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
 
int add_arr(int *Input,int cnt)
{
    int Total = 0;
	for(int i = 0; i < cnt; i++)
    {
        if(Input[i] < 1000)
        {
          Total += Input[i];
        }
    }
 
    return Total;
}
 
void strtonum(const char* String, int *num_arr,int *cnt)
{
    static int num = 0;
 
	if((String[*cnt] >= 48) && (String[*cnt] <= 57))
    {
       num = num * 10 + String[*cnt] - '0';
	  if((String[(*cnt)+1] >= 48) && (String[(*cnt)+1] <= 57))
       {
           (*cnt)++;
       }
       else
       {
          num_arr[*cnt] = num;
          num = 0;
          (*cnt)++;
       }
    }
    else
    {
        (*cnt)++;
        num = 0;
    }
}
 
int sum(const char *String)
{
    int cnt =0;
    int Total = 0;
    int Number[100] = {0};
    while(String[cnt] != '\0')
    {
       strtonum(String, Number, &cnt);
    }
 
    Total = add_arr(Number,cnt);
 
    return Total;
}
 
int CheckNegNumber(const char *String,int i)
{
      if((String[i] == '-') && (String[i+1] >= 48) && (String[i+1] <= 57))
      {
		  printf("Exception: negatives not allowed: %c%c\n", String[i], String[i+1]);
          return 0;
      }
    return 1;
}
 
int CheckStrNeg(const char *String)
{
    int Result = 0,i = 0;
    while(String[i] != '\0')
    {
      Result = CheckNegNumber(String,i);
      if(Result == 0)
      {
          break;
      }
      i++;
    }
    return Result;
}
 
int CheckStrEmpty(const char* String)
{
    return strlen(String) == 0 ? 1 : 0;
}
 
int CheckNegAndEmpty(const char *String)
{
	return (CheckStrEmpty(String) ? 1 : (CheckStrNeg(String) ? 1 : 0));
}
 
int add(const char *String)
{
    if((String != NULL) ? CheckNegAndEmpty(String) : 0)
    {
		int Result = sum(String);
        return Result > 0 ? Result : 0; 
    }
 
    return -1;
}
 
