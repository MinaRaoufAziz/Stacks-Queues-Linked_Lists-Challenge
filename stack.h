/*
 * stack.h
 *
 *  Created on: Oct 17, 2019
 *      Author: Mina
 */

#ifndef STACK_H_
#define STACK_H_

#include "stdtypes.h"
#include <stdlib.h>

/* Normal values for no errors to be assigned to flags */

#define STACK_INITIAL_FLAG_VALUE	0
#define STACK_CREATED				1
/* Error to handle the case if the stack is not created. used in push and pop function */
#define STACK_NOT_EMPTY			1
#define	STACK_NOT_OVERFLOW		1
#define STACK_NOT_UNDERFLOW		1
/* Error codes to be assigned to the flags */

/*  */
#define STACK_NOT_CREATED			-1
/* Error to handle if the stack is empty. used in pop function */
#define STACK_EMPTY					-2
#define STACK_OVER_FLOW				-3
#define STACK_UNDER_FLOW			-4

#define MAX_CHAR_NUM		10


#define DATA_EMPTY		0
#define TOP_START		-1

typedef struct
{
	uint32 * top;
	uint32 size;
	uint32 * current_pointer;
}ST_stackInfo;

void createStack(ST_stackInfo *info, uint32 size);
void push(ST_stackInfo *info, uint32 data);
void pop(ST_stackInfo *info, uint32* data);

#endif /* STACK_H_ */
