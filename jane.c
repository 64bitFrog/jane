#include <stdio.h>
#include <memory.h>
#include <stdint.h>
#include <assert.h>
#include <malloc.h>
#include <string.h>
#include <unistd.h>
#include <inttypes.h>

#include "stack.h"

void isa_add(Stack *s){
	push(s, pop(s) + pop(s));
}

void isa_sub(Stack *s){
	push(s, pop(s) - pop(s));
}

void isa_div(Stack *s){
	/* integer division provides a remainder as well */
	int16_t operand = pop(s);
	int16_t divisor = pop(s);
	assert(divisor); // cannot divide by zero
	push(s, operand % divisor); // remainder
	push(s, operand / divisor);
}

void isa_mul(Stack *s){
	push(s, pop(s) * pop(s));
}

#define INPUTBUF 32
void vread(const char *prompt, char *s, int num_bytes){
	/* read from stdin and append a 0 to the string so
	the outpu stops driving me crazy when re-using the string 
	this relies on the contract that there is space
 	allocated for appending the null on the string after a read */
	printf("%s",prompt);
	fflush(stdout);
	int i = read(STDIN_FILENO,s,num_bytes);
	assert(i); // if we can't read from stin - we're screwed
	s[i+1] = 0; 
}

int main(){
	/* It doesn't get much simpler */
	Stack s;
	int16_t number;

	char input[INPUTBUF+1];
	init(&s);
    	
	while(1){
		print_stack(&s);
		vread(">",input,INPUTBUF);
		if(!strncmp(input,"exit", 4))
			break;
		if(!strncmp(input,"x", 1))
			break;
		if(sscanf(input,"%"SCNi16, &number)){
		  push(&s, number);
		  continue;
		}
		if(!strncmp(input,"add", 3)){
			isa_add(&s);
			continue;
		}
		if(!strncmp(input,"sub", 3)){
			isa_sub(&s);
			continue;
		}
		if(!strncmp(input,"div", 3)){
			isa_div(&s);
			continue;
		}
		if(!strncmp(input,"mul", 3)){
			isa_mul(&s);
			continue;
		}

		printf("Instruction not understood: %s",input);
	}
	puts("Thank you for your patronage");	
	return 0;
}
