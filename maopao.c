/****
*
*ð�������㷨
* arr-->���������� 
* maxLength -->����ĳ���
*/

void Maopao(int* arr,int maxLength)
{
	int i,k,temp;
	for(i=0;i<maxLength;i++)
	{
		for(k=0;k<maxLength;k++)
		{
			if(arr[i]>arr[k])
			{
				temp = arr[k];
				arr[k] = arr[i];
				arr[i] = temp;
			}
		}
	}
}