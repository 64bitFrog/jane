/* 2018.09.02 */

#include <inttypes.h>

#ifndef _STACK_H
#define _STACK_H

#define STACK_SIZE 10

typedef struct ___s{
	int sp;						
	uint16_t data[STACK_SIZE];
} Stack;

void init(Stack *);
void print_stack(const Stack *);
int16_t pop(Stack *);
void push(Stack *, int16_t);

#endif
