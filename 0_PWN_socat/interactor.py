#!/usr/bin/env python2.7
from pwn import *

conn = remote('localhost',4000)
print conn.recvuntil('nope?')
print ">>>>Sending 'yes'<<<<"
conn.send("yes\n")
print conn.recvuntil("name:")
print ">>>>Sending 'Bob'<<<<"
conn.send("Bob\n")
print conn.recvuntil("today?")
conn.interactive()
