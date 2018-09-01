/****
*
*冒泡排序算法
* arr-->待排序数组 
* maxLength -->数组的长度
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