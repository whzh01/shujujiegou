/*****
*利用不排序的方式显示顺序的几个数
*类似于桶排序原理
*/

#include <stdio.h>

int numbers[10001] = {0,888,151,333,333,333,88,88,4,6}; //initialize 10000 number with range 1 - 1000

int count[1001] ={0};

#define ORDER 5


void Paixu(int* numbers,int* count,int* find_number, int* find_position)
{
    //your code.
    int i,j;
    int sum = 0;
   // int find_number = 0;

    for(i = 1 ; i < 10001 ; i++)
    {
        count[numbers[i]] ++;
    }

    for(i = 1 ; i < 1001; i++)
    {
		sum += count[i];
        if(sum >= *find_position)
        {
            *find_number = i;
            break;
        }
    }

   // printf("the %d number is %d\n",ORDER,find_number);
}
/**
int main()
{
	int num;
	int pos = 5;
	Paixu(numbers,count,&num,&pos);
	printf("%d",num);
}
*/