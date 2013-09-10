#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	int *result;
	int tmp;
	int N;
	int A;
	int i;
	int flag = 0;
	int zero = 0;
	

	scanf("%d %d", &A, &N);
	if((A == 0) || (N == 0)){
		printf("%d\n", zero);
		return 0;
	}

	result = (int *)malloc((N+1)*sizeof(int));
	memset(result, 0, (N+1)*sizeof(int));

	for(i = 0; i < N+1; i++){
		tmp = (N - i)*A + result[i];
		result[i] = tmp % 10;
		result[i+1] = tmp / 10;
	}


	for(i = N; i>= 0; i--){
		if(result[i] == 0){
			if(flag == 0){
				continue;
			}else{
				printf("%d", result[i]);
			}
		}else{
			flag = 1;
			printf("%d", result[i]);
		}
	}
	printf("\n");
	return 0;
	
}
