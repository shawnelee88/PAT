#include <stdio.h>
#include <stdlib.h>
#include <string.h>


//if N is prime, return N
//if not, return next prime
int NextPrime( int N )
{
	int i;
	int flag = 0;

	if( N % 2 == 0 )
		N++;
	for( ; ; N += 2 ){
		for( i = 3; i * i <= N; i += 2 ){
			if( N % i == 0 ){
				flag = 1;
				break;
			}else{
				flag = 0;
				continue;
			}			
		}

		if(flag == 0){
			return N;
		}else{
			continue;
		}
	}
}



int main()
{
	long int data;
	int p, k, i;

	int CurrentP;
	int NextP;
	p = 0;
	k = 0;


	scanf("%ld", &data);

	
	if(NextPrime(data) == data){  //data is a prime, or data = 1
		printf("%d=%d\n", data, data);
		return 0;
	}else{
		printf("%d=", data);
		while(data % 2 == 0){
			if(data == 0){
				break;
			}else{
				k++;
				data /= 2;
			}	
		}
		if(k != 0){
			if(k == 1){
				printf("2");
			}else{
				printf("2^%d", k);

			}	

			if(data == 1){
				printf("\n");
				return 0;
			}else{
				printf("*");
			}
		}
		
		CurrentP = 2;
		for(i = 0; ; i++){
			k = 0;
			NextP = NextPrime(CurrentP);
			while(data % NextP == 0){
				if(data == 0){
					break;
				}else{
					k++;
					data /= NextP;
				}
			}
			if(k != 0){
				if(k == 1){
					printf("%d", NextP);
				}else{
					printf("%d^%d", NextP, k);
				}

				if(data == 1){
					printf("\n");
					return 0;
				}else{
					printf("*");
				}
			}
			
			CurrentP = NextP + 1;
		}
	}
}


