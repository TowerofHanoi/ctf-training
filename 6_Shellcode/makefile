justrecompile:
	gcc -mpreferred-stack-boundary=4 -O0 -fno-stack-protector -g source_redirectme.c -m32 -z execstack -o redirectme
	gcc shellcode_test.c -z execstack -o test_shellcode -m32
