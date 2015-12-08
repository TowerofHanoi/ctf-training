#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <inttypes.h>

int main(int argc, char *argv[],char*envp[]){
	int i;
	char*args[]={"/tmp/flag"};
	char command[20];
	printf("argc: %d\n",argc);
	for(i=0;i<argc;i++){
		printf("\targv[%d] = %s\n",i,argv[i]);
	}
	char* printf_address=(char*)printf;
	printf_address += 2;
	uint32_t** printf_real_address_ptr = (uint32_t**)printf_address;
	printf("0x%x\n",**printf_real_address_ptr);
	
	scanf("");
	char* scanf_address=(char*)scanf;
	scanf_address += 2;
	uint32_t** scanf_real_address_ptr = (uint32_t**)scanf_address;
	printf("0x%x\n",**scanf_real_address_ptr);
	
	printf("Now executing cat");
	execve("/usr/bin/cat",args,envp);
}

