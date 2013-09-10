#include <stdio.h>
#include <stdlib.h>

#define MaxN 1001
#define MaxK 10


int main()
{

	int K1;
	int K2;
	float coeff[MaxN];  //coefficient
	int expo[MaxN];  //exponential
	float coefftmp;
	int expotmp;
	int i, j, k;
	int isfirst1;
	int isfirst2;
	int index;
	int size = 0;

	for(i = 0; i < MaxN; i++){
		coeff[i] = 0.0;
		expo[i] = 0;
	}

	scanf("%d", &K1);
	for(i = 0; i < K1; i++){
		scanf("%d%f", &expotmp, &coefftmp);
		if(coefftmp != 0.0){
			size++;
			expo[expotmp] = 1;
			coeff[expotmp] = coefftmp;
		}	
	}

	scanf("%d", &K2);
	for(j = 0; j < K2; j++){
		scanf("%d%f", &expotmp, &coefftmp);
		if(expo[expotmp] == 1){
			coeff[expotmp] += coefftmp;
			if(coeff[expotmp] == 0.0){  //rejudge if coeff of sum equals to 0?
				expo[expotmp] = 0;
				size--;
			}
		}else{
			if(coefftmp != 0){
				expo[expotmp] = 1;
				coeff[expotmp] = coefftmp;
				size++;
			}	
		}
	}

	printf("%d", size);
	i = 0;
	for(i = MaxN - 1; i >= 0; i--){
		if(expo[i] != 0){
			printf(" %d %.1f", i, coeff[i]);
		}
	}
	printf("\n");
	return 0;
}
