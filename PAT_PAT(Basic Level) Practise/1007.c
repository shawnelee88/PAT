#include<stdio.h>
#include<math.h>


//return 1 if n is a prime, return 0 if not
int IsPrime(int n)
{
	int res = 1;
	int i = 0;

	if(n == 1 || ((n > 2) && (n % 2 == 0))) //even or 1       
	{
		res = 0;
		return res;
	}
	
	if(n == 2){
		res = 1;
		return res;
	}

	for(i = 3; i <= sqrt(n) ; i+=2)
	{
		if( n % i == 0)  //not a prime
		{
			res = 0;
			break;
		}
	}//end of loop , is a prime
	return res;
}

int main()
{
	int n;
	int prevprime = 3;  //start from 3
	int count = 0;
	int i = 0;


	scanf("%d",&n);
	//if n == 1 or 2, count = 0
	for(i = 3 ; i <= n ; i += 2 )
	{
		if(IsPrime(i))
		{
			if(i - prevprime == 2){
				count++;
			}	
			prevprime = i;
		}
	}

	printf("%d\n",count);
	return 0;
}