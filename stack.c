#include <stdio.h>
#include <assert.h>
#include <inttypes.h>

#include "stack.h"

void init(Stack *s){
	s->sp = -1;
}

void print_stack(const Stack *s){
	int i;
	printf("\nStack: ");
    for(i = 0; i <= s->sp; i++)
		printf("%hi, ",s->data[i]);
	printf("\n");
}

int16_t pop(Stack *s)
{
	assert(s->sp != -1);	
	return s->data[s->sp--];
}

void push(Stack *s, int16_t i)
{
	assert(s->sp < STACK_SIZE - 1);
    s->data[++(s->sp)] = i;	
}
