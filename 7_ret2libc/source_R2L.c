#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>                                                             
#include <inttypes.h>   
char control_string[40];

void vulnerable_function(){
	int control=0;
	char very_long_buffer[80]; 

	printf("Input:\n> ");
	fflush(stdout);
	gets(very_long_buffer);
	printf(very_long_buffer);
	printf("\n");
	fflush(stdout);

	//Get printf address
    char* printf_address=(char*)printf;                                         
    printf_address += 2;                                                        
    uint32_t** printf_real_address_ptr = (uint32_t**)printf_address;            
    printf("0x%x\n",**printf_real_address_ptr);
	fflush(stdout);
	//

	return;
}
int main(){
	int loop=2;
	printf("Welcome!\nInsert name ");
	fflush(stdout);
	fgets(control_string ,39,stdin);
	while(loop--){
		vulnerable_function();
	}
	return 0;
}
