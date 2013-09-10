#include<stdio.h>
#include<string.h>
#include<memory.h>


int main()
{
	int n;
	int tmp;
	int num[101];
	int i;
	int isfirst;

	memset(num, -1, sizeof(num));
	scanf("%d",&n);
	while(n--)
	{
		scanf("%d",&tmp);
		num[tmp] = 0;  //wait to check
	}

	for(i = 0 ; i < 101 ; i++)
	{
		if(num[i] == 0)
		{
			tmp = i;
			while(tmp!=1)            
			{
				if( tmp % 2 == 0)                         
				{    
					tmp = tmp / 2;
				}                                    
				else                                 
				{    
					tmp = (3*tmp+1) / 2;
				}
				if(tmp < 101 && num[tmp] != -1)
					num[tmp] = 1;  //occupy  
			}
		}
	}

	isfirst = 1;
	for(i = 100; i >= 0 ; i--)
	{

		if(num[i] == 0)  //not be occupied
		{
			if(!isfirst)
				printf(" ");
			printf("%d",i);
			isfirst = 0;
		}
	}    
	
	printf("\n");
	return 0;
}