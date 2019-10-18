/*
 * main.c
 *
 *  Created on: Oct 18, 2019
 *      Author: Mina
 */

#include "stack.h"
#include <stdio.h>


extern uint8 is_stack_created;
extern uint8 is_stack_pushed;
extern uint8 is_stack_pulled;
extern uint8 stack_status_flag;


int main()
{
	uint32 data = 400;
	uint32 * data_ptr = &data;
	uint8 counter;
	ST_stackInfo Stack;
	ST_stackInfo * stack_ptr = &Stack;
	createStack(&Stack, MAX_CHAR_NUM);
	printf("%d\n", is_stack_created);
	printf("%p\n", (stack_ptr -> current_pointer));
	printf("%p\n", (stack_ptr -> top));
	printf("%d\n", (stack_ptr -> size));
	push(stack_ptr, 2);
	printf("%p\n", (stack_ptr -> current_pointer));
	printf("%d\n", (*(stack_ptr -> current_pointer)));
	push(stack_ptr, 5);
	printf("%p\n", (stack_ptr -> current_pointer));
	printf("%d\n", (*(stack_ptr -> current_pointer)));
	push(stack_ptr, (*data_ptr));
	printf("%p\n", (stack_ptr -> current_pointer));
	printf("%d\n", (*(stack_ptr -> current_pointer)));
	pop( stack_ptr, data_ptr);
	printf("%d\n", (*(stack_ptr -> current_pointer)));
	printf("%p\n", (stack_ptr -> current_pointer));
}
