#include "stdio.h"
/***
ȥ���㷨
array --->ԭ���飬��Ҫȥ�ص�����
maxlen --->����Ԫ�ظ���
newArray -->�����飬���ȥ�غ��Ԫ��
newLength -->������Ԫ�صĸ���


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
//ȥ�ص���ʾ��
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