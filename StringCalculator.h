#include <string.h>
#include <stdlib.h>
/******************************************************************************
 
                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.
 
*******************************************************************************/
 
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
 
bool isNegative(const char* str){
	int i = 0;
	while(str[i]){
		if(str[i] == '-'){
			printf("Negatives not allowed\n");
			return true;
		}
		i++;
	}
	return false;
}

int sumOfDigits(int s){
	int sum = 0;
	if (s<=1000){
		while(s){
			sum = sum + (s%10);
			s/=10;
		}
	}
	return sum;
}

int fetchNumberFromString(const char* str, int i, int* number){	
	while(str[i]&&isdigit(str[i++])){		
		*number = ((*number)*10) + str[i-1]-'0';	
	}							
	return i;
}

int add(const char *str){
	int i=0, s = 0, sum = 0;
	bool neg = isNegative(str);
	if (neg == false)
	{
		while(str[i]){
			i = fetchNumberFromString(str, i, &s);
			sum = sum + sumOfDigits(s);
			s=0;
		}
	}
	return sum;
}
 
