/*
 * stack.c
 *
 *  Created on: Oct 17, 2019
 *      Author: Mina
 */

#include "stack.h"

/* IMPORTANT NOTE: To check for errors and in order to maintain functions prototypes
 *					The way it is. I implemented the error checking using flags */

uint8 is_stack_created = STACK_INITIAL_FLAG_VALUE;
uint8 is_stack_pushed = STACK_INITIAL_FLAG_VALUE;
uint8 is_stack_pulled = STACK_INITIAL_FLAG_VALUE;
uint8 stack_status_flag = STACK_INITIAL_FLAG_VALUE;
//uint32 * top_ptr = NULL;


void createStack(ST_stackInfo *info, uint32 size)
{
	/* in this function we need first to check on the passed pointer to structure not equal null
	 * then we will access the structure elements and assign the top pointer the casted pointer
	 * from the dynamic memory allocation. then we will assign the size parameter passed to the
	 * function to the structure size member. */
	if (info  != NULL)
	{
		info ->top= (uint32 * ) calloc (size, sizeof(uint32));
		info ->size = size;
		info -> current_pointer = info -> top;
		is_stack_created = STACK_CREATED;
		*(info->current_pointer) = TOP_START;
		stack_status_flag = STACK_EMPTY;
	}
}

void push(ST_stackInfo *info, uint32 data)
{
	/* in this function we need first to check that the stack is created in the first place.
	 * Then we will check that the top not pointing to the bottom element, if so
	 * then we will dereference the pointer and store the data in it and will increment to
	 * point to the next element in the stack. The data will be stored in the pointer by
	 * creating a global pointer to the ST_stackInfo type and contains th	*/
	if ((STACK_CREATED == is_stack_created) && (STACK_OVER_FLOW != stack_status_flag))
		/* As the stack must be created at first */
	{
		if ((info -> current_pointer) != ((info -> top)+((info->size)-1)))
			/* Here we check if the top is not pointing to the last element*/
			{
			(info->current_pointer)++;
			*(info->current_pointer) = data;
			is_stack_pushed++;
			stack_status_flag = STACK_NOT_EMPTY;
			}
		else
		{
			/* Here we must raise error for overflow. This can be accomplished using
			 * typedef enum {
			 * OVERFLOW_ERROR = -90 , UNDERFLOW_ERROR = -80, CREATE_ERROR = -70}ERROR_MODE;
			 * and then we need to create another enum to contain error indicator for
			 * each function
			 * typedef enum {STACK_PUSH = -5 , STACK_PULL = -4 }FUNC_ERR;
			 *  and we change the function prototype to return uint32, which represents
			 *  the corresponding error for function and module*/

			stack_status_flag = STACK_OVER_FLOW;
		}
	}

}

void pop(ST_stackInfo *info, uint32* data)
{
	/* In this function we need also to check if the push function was called previously.
	 * In order to avoid pop function execution if the stack has no data. I implemented this
	 * idea using flags in order to maintain function prototypes as it is.*/

	/* First we need to make sure that the pointer not equal to NULL */
	if (info != NULL)
	{
	/* Then we need to check that the stack is created and not underflow and is containing data */
		if ((STACK_CREATED == is_stack_created) )
		{
			if ((info -> current_pointer) != (info ->top))
			{
				/* Here we make sure that the top pointer is not pointing the first element
				 * in the stack to avoid underflow.
				 * If so, then we clear the data and decrement the pointer by one step */
				*data = (*(info->current_pointer));
				(info->current_pointer)--;
				is_stack_pulled++;
				stack_status_flag = STACK_NOT_EMPTY;
			}
		}
		else
		{
			/* in this case, we violated the above condition, then we reached the underflow.
			 * So we report the underflow occurance in the pop function and we may print
			 * this flag in the application to inform the user*/
			stack_status_flag = STACK_UNDER_FLOW;
		}
	}
}




