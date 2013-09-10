#include<stdio.h>
#include<string.h>
#include<memory.h>


int main()
{
	int N;
	int a[3];
	int i = 0;
	int j = 0;
	int k = 0;
	int tmp;

	memset(a, 0, 3*4);

	scanf("%d", &N);
	while(N / 10 != 0){
		a[i++] = N % 10;
		N /= 10;
	}
	a[i] = N;

	for(j = i; j >= 0; j--){
		tmp = a[j];
		if(tmp != 0){
			switch(j){
				case 2:
					for(k = 0; k < tmp; k++){
						printf("%c", 'B');
					}
					break;
				case 1:
					for(k = 0; k < tmp; k++){
						printf("%c", 'S');
					}
					break;
				case 0:
					for(k = 0; k < tmp; k++){
						printf("%c", '0' + k + 1);
					}
					break;
				default:
					break;
			}
		}	
	}

	return 0;
}