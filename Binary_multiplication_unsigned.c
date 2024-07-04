#include<stdio.h>

int binaryaddition(int a, int b)
{
 int carry=0,result=0,bit=1;
 while(a!=0||b!=0)
 {
 	int bit_a=a%10;
 	int bit_b=b%10;
 	int sum=bit_a+bit_b+carry;
 	result+=(sum%2)*+bit;
 	carry=sum/2;
 	a/=10;
 	b/=10;
 	bit*=10;
 }
  result+=carry*bit;
  return result;
}
int logicalshiftleft(int num)
{
	return num*10;
}
int logicalshiftright(int num)
{
		return num/10;
} 
int bothmultiply(int multiplicand,int multiplier)
{
	int accumulator =0;
	int bitmask=1;
while(multiplier !=0){

	if(multiplier % 10==1)
	{
		accumulator=binaryaddition(accumulator,multiplicand);
		
	}
	multiplicand =logicalshiftleft(multiplicand);
	multiplier=logicalshiftright(multiplier);
	bitmask*=10;
}
return accumulator;
}
int decimaltobinary(int decimal)
{
	int binarynum=0,rem=0,i=1;
	while(decimal>0)
	{
		rem=decimal%2;
		decimal=decimal/2;
		binarynum=binarynum+rem*i;
		i=i*10;
	}
	return binarynum;
}
int binarytodecimal(int binary)
{
	int decimal=0,base=1;
	while(binary!=0)
	{
		int lastdigit=binary%10;
		decimal+=lastdigit*base;
		binary/=10;
		base*=2;
	}
	return decimal;
}
int main()
{
	int multiplicand,multiplier;
	printf("enter the multiplicand(decimal):");
	scanf("%d",&multiplicand);
	printf("enter the multiplier(decimal):");
	scanf("%d",&multiplier);
	multiplicand=decimaltobinary(multiplicand);
	multiplier=decimaltobinary(multiplier);
	int product= bothmultiply(multiplicand,multiplier);
	printf("product of the two number is:%d(binary)\n",product);
	printf("product in decimal:%d\n",binarytodecimal(product));
	return 0;
}