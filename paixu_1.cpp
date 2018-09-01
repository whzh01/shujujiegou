#include <stdio.h>

int numbers[10001] = {0,888,151,333,333,333,88,88}; //initialize 10000 number with range 1 - 1000

int count[1001] ={0};

#define ORDER 3041

int main()
{
    //your code.
    int i,j;
    int sum = 0;
    int find_number = 0;

    for(i = 1 ; i < 10001 ; i++)
    {
        count[numbers[i]] ++;
    }

    for(i = 1 ; i < 1001; i++)
    {
        if((sum += count[i]) >= ORDER)
        {
            find_number = i;
            break;
        }
    }

    printf("the %d number is %d\n",ORDER,find_number);
}