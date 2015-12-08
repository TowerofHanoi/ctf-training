#use make -B all to force rebuild

all: default broken canaries partialrelro fullrelro pie 

default:
	gcc securcheck.c -o default

#this is almost never the case, and it is one of the two cases in which a shellcode can work
broken:
	gcc securcheck.c -z execstack -o broken

#Stack protector
canaries:
	gcc securcheck.c -fstack-protector -o canaries

#Partial RELRO
#	the ELF sections are reordered so that the ELF internal data sections (.got, .dtors, etc.) precede the program's data sections (.data and .bss)
#	non-PLT GOT is read-only
#	GOT is still writeable

partialrelro:
	gcc securcheck.c -z relro -o partialrelro

#Full RELRO
#	supports all the features of partial RELRO
# 	and the entire GOT is also (re)mapped as read-only
fullrelro:
	gcc securcheck.c -z relro -z now -o fullrelro

#ASLR also for main executable
pie:
	gcc securcheck.c -pie -fPIC -o pie

checksec:
	checksec --file default > checksec.log
	checksec --file broken >> checksec.log
	checksec --file canaries >> checksec.log
	checksec --file partialrelro >> checksec.log
	checksec --file fullrelro >> checksec.log
	checksec --file pie >> checksec.log

sections:
	r2 -wqc'S' fullrelro

