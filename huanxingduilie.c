/**
*环形队列缓冲区
*
*/
#define BUFFSIZE 5
#define true 1
#define false 0
typedef struct
{
	char top;
	char last;
	char empty;
	char data[BUFFSIZE];
}Buff;
//char buff[100];
Buff buff={0,0,0,{0}};
char IsEmpty()
{
  if((buff.top == buff.last) && (buff.empty == 0))
  {
	  //Is empty
	  return true;
  }else
  {
	  return false;
  }
}
char IsFull()
{
	if((buff.last%BUFFSIZE == buff.top) && (buff.empty != 0))
	{
		//Is full
		return true;
	}else
	{
		return false;
	}

}
void PullBuff(char data)
{
	if(!IsFull())
	{
		buff.data[buff.last%BUFFSIZE] = data;
		printf("Pull:%d\n",data);
		buff.last++;
		buff.empty++;
		
	}
}
char PopBuff()
{
	char s;
	if(!IsEmpty())
	{
		s = buff.data[buff.top%BUFFSIZE];
		buff.top++;
		buff.empty--;
		return s;
	}
	
}
