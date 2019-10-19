/*
 * main.c
 *
 *  Created on: Oct 18, 2019
 *      Author: Mina
 */


#include "que.h"


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
#define MAX_CHAR_NUM 10


int calculate(int num1,int num2,char oper);

int calculate(int num1,int num2,char oper)
{

	if(oper == '+')
	{
		return num1+num2;
	}else if(oper == '-')
	{
		return num1-num2;
	}else if(oper == '/')
	{
		return num1/num2;
	}else if(oper == '*')
	{
		return num1*num2;
	}
}
int evaluate(char* expression)
{
	int size_numbers = 0,size_signs = 0;
	int counter = 0;
	int counter_signs=0;
	int result = 0;
	ST_queueInfo Queue_numbers;
	ST_queueInfo Queue_signs;
	createQueue(&Queue_numbers, MAX_CHAR_NUM);
	createQueue(&Queue_signs, MAX_CHAR_NUM);
	while (expression[counter] != '\0')
	{
		if ((MODULUS == (expression[counter])) || (MULTIPLICARTION == (expression[counter])) || (ADDITION == (expression[counter])) || (SUBTRACTION == (expression[counter])) || (DIVISION == (expression[counter])))
		{
			enqueue(&Queue_signs, expression[counter]);
		}
		else if ((ONE == (expression[counter])) || (TWO == (expression[counter])) || (THREE == (expression[counter])) || (FOUR == (expression[counter])) ||(FIVE == (expression[counter])) ||(SIX == (expression[counter])) ||(SEVEN == (expression[counter])) ||(EIGHT == (expression[counter])) ||(NINE == (expression[counter])) ||(ZERO == (expression[counter])))
		{
			enqueue(&Queue_numbers, (expression[counter]-48));
		}
		else
		{
			// error input string
		}
		counter++;
	}

	size_signs =  getSize(&Queue_signs);
	size_numbers =  getSize(&Queue_numbers);
	for(counter_signs = 0;counter_signs<size_signs;counter_signs++)
	{
		result +=  calculate(dequeue(&Queue_numbers),dequeue(&Queue_numbers),dequeue(&Queue_signs));
	}
	result++;
	printf("%d\n",size_signs);
	printf("%d\n",size_numbers);

	return result;
}
int main(void)
{
	int res = evaluate("1+2+5");
	printf("%d",res);
}
