/**
*�����򣬹鲢����
*arrA--> ��������A,
*size_a -->����A�Ĵ�С
*arrB -->��������B
*size_b -->����B�Ĵ�С
*arrRes -->������������飬��ռ�>size_a+size_b
*/

void Guibing(int* arrA,int size_a,int* arrB,int size_b,int* arrRes)
{
	int i,j,k;
	i=0;
	j=0;
	k=0;
	while(i<size_a && j<size_b)
	{
		if(arrA[i]<arrB[j])
		{
			arrRes[k++] = arrA[i];
			i++;
		}else
		{
			arrRes[k++] = arrB[j];
			j++;
		}
	}
	while(i<size_a)
	{
		arrRes[k++] = arrA[i++];
	}
	while(j<size_b)
	{
		arrRes[k++] = arrB[j++];
	}

}