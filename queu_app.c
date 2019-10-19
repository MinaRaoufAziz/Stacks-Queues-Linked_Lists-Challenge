/*
 * main.c
 *
 *  Created on: Oct 18, 2019
 *      Author: Mina
 */

#include "stack.h"
#include <stdio.h>

#define MODULUS				37
#define MULTIPLICARTION		42
#define ADDITION			43
#define SUBTRACTION			45
#define DIVISION			47
#define ZERO				48
#define ONE					49
#define TWO					50
#define THREE				51
#define FOUR				52
#define FIVE				53
#define SIX					54
#define SEVEN				55
#define EIGHT				56
#define NINE				57


extern uint8 is_stack_created;
extern uint8 is_stack_pushed;
extern uint8 is_stack_pulled;
extern uint8 stack_status_flag;


int main()
{
	uint32 data = 400;
	uint32 * data_ptr = &data;
	uint8 counter, counter_two;
	uint32 result = 0;
	ST_stackInfo Stack;
	ST_stackInfo * stack_ptr = &Stack;
	createStack(&Stack, MAX_CHAR_NUM);
	ST_queueInfo Queue;
	ST_queueInfo * queue_ptr = &Queue;
	createQueue(queue_ptr, MAX_CHAR_NUM);
	char char_arr [MAX_CHAR_NUM]= "5*6+3/3%2";
	while (char_arr[counter != '\0')
	{
		if ((MODULUS == (char_arr[counter])) || (MULTIPLICARTION == (char_arr[counter])) || (ADDITION == (char_arr[counter])) || (SUBTRACTION == (char_arr[counter])) || (DIVISION == (char_arr[counter])))
		{
			enqueue(queue_ptr, char_arr[counter]);
		}
		else if ((ONE == (char_arr[counter])) || (TWO == (char_arr[counter])) || (THREE == (char_arr[counter])) || (FOUR == (char_arr[counter])) ||(FIVE == (char_arr[counter])) ||(SIX == (char_arr[counter])) ||(SEVEN == (char_arr[counter])) ||(EIGHT == (char_arr[counter])) ||(NINE == (char_arr[counter])) ||(ZERO == (char_arr[counter])))
		{
			push(stack_ptr,  char_arr[counter]);
		}
		else
		{

		}
		counter++;
	}
	for (counter = 0; counter < MAX_CHAR_NUM; counter+=2)
	{
		for (counter_two = 0; counter < MAX_CHAR_NUM; counter_two++)
		{
			uint32 result
		}
	}
	uint32 result


}
