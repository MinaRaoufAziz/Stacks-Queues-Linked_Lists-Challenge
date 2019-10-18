/*
 * app.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: COMPUTER SHOW
 */


#include"stack.h"
#include<stdio.h>

#define BALANCED (unsigned char)1
#define NOT_BALANCED (unsigned char)0

ST_stackInfo Stack;
ST_stackInfo * stackPtr = &Stack;
//uint32 *data_ptr = NULL;

unsigned char checkForBalancedParantheses(char* expression)
{
	unsigned char Balance_Flag = NOT_BALANCED;
	int str_ctr = 0;
	uint32 data_1;
	uint32 data_2;
	uint32 data_3;
	createStack(&Stack, NUM_OF_CHARS);
	while(expression[str_ctr] != '\0')
	{
		if( ((expression[str_ctr])!= '(')
				|| ((expression[str_ctr])!= '{')
				|| ((expression[str_ctr])!= '[')
				|| ((expression[str_ctr])!= ')')
				|| ((expression[str_ctr])!= '}')
				||((expression[str_ctr])!= ']') )
		{
			Balance_Flag =  NOT_BALANCED;
		}
		str_ctr++;
	}
	str_ctr = 0 ;
	while(expression[str_ctr] != '\0')
	{
		if( (expression[str_ctr] == '(') )
		{
			data_1 = 40;
			push(&Stack, data_1);
		}
		if( (expression[str_ctr] == '[') )
		{
			data_2 = 91;
			push(&Stack, data_2);
		}
		if( (expression[str_ctr] == '{') )
		{
			data_3 = 123;
			push(&Stack, data_3);
		}
		if( (expression[str_ctr] == ')') )
		{
			//*data_ptr = 41;
			pop(&Stack, &data_1);
		}
		if((expression[str_ctr] == ']') )
		{
			//*data_ptr = 93;
			pop(&Stack, &data_2);
		}
		if(expression[str_ctr] == '}')
		{
			//*data_ptr = 125;
			pop(&Stack, &data_3);
		}
		str_ctr++;
	}
	if (is_stack_pushed == is_stack_pulled)
	{
		Balance_Flag = BALANCED;
	}
	else
	{
		Balance_Flag = NOT_BALANCED;
	}
	return Balance_Flag;
}

int main(void)
{

	uint8 return_check = checkForBalancedParantheses("({()})");
	if(return_check == NOT_BALANCED){
		printf(" not balanced string\n ");
	}else{
		printf("  balanced string\n ");
	}
}
