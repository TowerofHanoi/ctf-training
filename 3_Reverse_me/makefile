normal:
	gcc -O0 -fno-stack-protector reverseme.c -o reverseme -m32
	strip reverseme

easy:
	gcc -O0 -fno-stack-protector reverseme.c -o reverseme -m32

moderate:
	gcc -O2 -fno-stack-protector reverseme.c --static -o reverseme -m32

hardcore:
	gcc -O3 -fno-stack-protector reverseme.c --static -o reverseme
	strip reverseme
