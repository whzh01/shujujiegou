#include "stdio.h"
/***
去重算法
array --->原数组，需要去重的数组
maxlen --->数组元素个数
newArray -->新数组，存放去重后的元素
newLength -->新数组元素的个数


  **/
void quchong(char* array,int maxlen,char* newArray,int* newLength)
{
	int i,j,k,ln;
	char* a = array;
    for(ln=maxlen,k=i=1;i<ln;i++){
        for(j=0;j<k;j++)
            if(a[j]==a[i]) break;
        if(j>=k) a[k++]=a[i];
    }
	 for(i=0;i<k;i++)
	 {
		newArray[i] = a[i];	
	 }
	 *newLength = i-1;
}
/****
//去重调用示例
void main(void){
   
	char a[] = {12,33,32,23,33,33,32,33,3,3,3,3,3,34,2,90,2};
	int maxlen = sizeof(a)/sizeof(a[1]); 
	int i;
	int newLen;
	quchong(a,maxlen,a,&newLen);
	for( i=0;i<=newLen;i++)
	{
		printf("%d ",a[i]);
	}
    printf("\n");
}
***/