#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MaxNumber 1000

int main()
{
	int arr[MaxNumber];
	int i = 0;
	int j = 0;
	int k = 0;
	int isfirst;
	char ch;
	int data;
	int coeff;
	int expo;

	while(scanf("%d%c", &data, &ch)){
		arr[i++] = data;
		if(ch == '\n'){
			break;
		}
	}

	for(j = 0; j < i;){
		coeff = arr[j++];
		expo = arr[j++];
		if(expo != 0){
			arr[j - 2] = coeff * expo;
			arr[j - 1] = expo - 1;
		}else{
			arr[j - 2] = 0;
			arr[j - 1] = 0;
		}
	}

	isfirst = 1;
	for(k = 0; k < j; k += 2){
		if(arr[k] == 0){
			continue;
		}else{
			if(isfirst == 1){
				printf("%d %d", arr[k], arr[k + 1]);
				isfirst = 0;
			}else{
				printf(" %d %d", arr[k], arr[k + 1]);
			}
		}	
	}

	if(isfirst){
		printf("0 0");
	}

	printf("\n");


	return 0;
}
