/***
*��ȫ��������תָ��λ
*/
void Reverse(unsigned int* REGn,unsigned char bit)
{
	if(bit>31)
	{
		return ;
	}else
	{
		*REGn ^=1<<bit;
	}
}