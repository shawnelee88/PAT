#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 1000
int main()
{
	int N ;
	int box_size[MAXSIZE];	
	int object[MAXSIZE];
	int boxNumOfObject[MAXSIZE];
	int i, j;
	int maxBoxNum = 0;

	scanf("%d", &N);
	for(i = 0; i < N; i++){
		scanf("%d", &object[i]);
	}

	for(j = 0; j < N; j++){
		box_size[j] = 0;
		boxNumOfObject[j] = 0;
	}

	for(i = 0; i < N; i++){
		for(j = 0; j < N; j++){
			if(box_size[j] + object[i] > 100){
				continue;
			}else{
				box_size[j] += object[i];
				boxNumOfObject[i] = j+1;
				break;
			}
		}
	}

	for(i = 0; i < N; i++){
		if(maxBoxNum < boxNumOfObject[i]){
			maxBoxNum = boxNumOfObject[i];
		}
		printf("%d %d\n", object[i], boxNumOfObject[i]);
	}
	printf("%d\n", maxBoxNum);
	return 0;
	
}
