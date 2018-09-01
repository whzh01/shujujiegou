#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int b[] = {2,5,8,9,7,1,4,3,6,7,14,2};
int a[] = {2,14,7,6,3,4,1,7,9,8,5,2};
void quick_sort(int left,int size)
{
	int tmp,i,j,t;
	tmp = a[left];
	i = left;
	j = size;
	if(left>size)
		return;
	while(i != j)
	{
		//查找左侧侧大于基准数的元素
		while(i<j && a[j]>=tmp)
			j--;
		//查找右侧不小于基准数的元素
		while(i<j && a[i]<tmp)
			i++;
		if(i<j)
		{//交换元素的位置
			t = a[i];
			a[i] = a[j];
			a[j] = t;
		}
	}
	a[left] = a[i];
	a[i] = tmp;
	quick_sort(left,i-1);
	quick_sort(i+1,size);
}
void GetMemory(char **str)
{
	*str = malloc(100);
	strcpy(*str,"Hello World!");
}
//重写字符串比较函数
int strcmp1(char  *source, char *dest)
{
	
	if((*source) == NULL && (*dest) == NULL )
	{
		return 0;
	}else if(*source == NULL || *dest == NULL)
	{
		return -1;
	}
	while(*source != '\0' && *dest != '\0')
	{
		if(*source == *dest)
		{
			source++;
			dest++;
		}else
		{
			return -1;
		}
	}
	if(*source == '\0' && *dest == '\0')
	{
		return 0;
	}
	return -1;
}
//判断是否为回文
int funca(char* s)
{
	//是 1 ，不是 0，错误 -1
	if(s == NULL || *s == NULL)
	{
		return -1;
	}
	char *t = s;
	int num = strlen(s);
	while(*t != '\0')
	{
		t++;
	}
	t--;
	for(int k=0;k<num/2;k++)
	{
		if(*s != *t)
		{
			return 0;
		}
		s++;
		t--;
	}
	return 1;
}
char* FindStr(char* str,char* val)
{
	//查找字符串
	char *cstr,*cval;
	int num = 0;
	cstr = str;
	cval = val;
	if(str == NULL || val == NULL)
	{
		return NULL;
	}
	if(*val == NULL)
	{
		return str;
	}
	while(*cval != '\0' && *cstr != '\0')
	{
		
		if(*cval == *cstr)
		{
			cval++;
			cstr++;
		}else
		{
			num++;//记录第几个元素不匹配
			cval = val;
			cstr = str+num;
		}
	}
	if(*cval == '\0')
	{
		return str+num;
	}else
	{
		return NULL;
	}
}
int main()
{
	unsigned long *p2=(unsigned long *)0x810000;
	int i;
	quick_sort(0,12);
	for( i=0;i<12;i++)
	{
		printf("%d ",a[i]);
	}
	getchar();
	char *s = NULL;
	char *sour = (char*)malloc(100);
	char *dest = (char*)malloc(100);
	strcpy(sour," ");
	strcpy(dest," ");
	p2 = p2+5;
	GetMemory(&s);
	printf("%s",s);
	printf("short %d\n",sizeof(short));
	printf("long %d\n",sizeof(long));
	printf("int %d\n",sizeof(int));
	printf("double is %d\n",sizeof(double));
	int arr[]={6,7,8,9,10};      
	int*ptr=arr;    
	*(ptr++)+=123;  
	printf("%d,%d\n",*ptr,*(++ptr));
	printf("compare result:%d\n",strcmp1(sour,dest));
	//printf("%x",)
	
	char *ss = NULL;
	printf("huiwen result:%d\n",funca(ss));
	char *s1 = "Hello WOrld.";
	char *strVal = "ld";
	printf("find str result:%d",FindStr(s1,strVal));
	getchar();
}