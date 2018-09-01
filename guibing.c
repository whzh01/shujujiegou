/**
*外排序，归并排序
*arrA--> 有序数组A,
*size_a -->数组A的大小
*arrB -->有序数组B
*size_b -->数组B的大小
*arrRes -->存放排序后的数组，其空间>size_a+size_b
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