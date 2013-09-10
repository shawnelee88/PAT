#include <stdio.h>
#include <stdlib.h>

#define MaxN 1000
#define MaxK 10


int main()
{

	int K1;
	int K2;
	double coeff1[MaxN + 1];  //coefficient
	int expo1[MaxN + 1];  //exponential
	double coeff2[MaxN + 1];
	int expo2[MaxN + 1];
	double coeffFinal[2*MaxN + 2];
	int expoFinal[2*MaxN + 2];
	double coefftmp;
	int expotmp;
	int i, j, k;
	int size = 0;

	for(i = 0; i < MaxN+1; i++){
		coeff1[i] = 0.0;
		expo1[i] = 0;
		coeff2[i] = 0.0;
		expo2[i] = 0;
		coeffFinal[i] = 0.0;
		coeffFinal[i+MaxN+1] = 0.0;
		expoFinal[i] = 0;
		expoFinal[i+MaxN+1] = 0;
	}


	scanf("%d", &K1);
	for(i = 0; i < K1; i++){
		scanf("%d%lf", &expotmp, &coefftmp);
		if(coefftmp != 0.0){
			//size++;
			expo1[expotmp] = 1;
			coeff1[expotmp] = coefftmp;
		}	
	}

	scanf("%d", &K2);
	for(j = 0; j < K2; j++){
		scanf("%d%lf", &expotmp, &coefftmp);
		if(coefftmp != 0.0){
			expo2[expotmp] = 1;
			coeff2[expotmp] = coefftmp;
		}
	}

	for(i = 0; i < MaxN + 1; i++){
		if(expo1[i] == 1){
			for(j = 0; j < MaxN + 1; j++){
				if(expo2[j] == 1){
					if(expoFinal[i + j] == 0){
						size++;
						expoFinal[i + j] = 1;
					}

					coeffFinal[i + j] += (coeff1[i] * coeff2[j]);
					if(coeffFinal[i + j] == 0.0000){
						size--;
						expoFinal[i + j] = 0;
					}
				}
				
			}
		}
		
	}

	printf("%d", size);
	i = 0;
	for(i = 2*MaxN; i >= 0; i--){
		if(expoFinal[i] != 0){
			printf(" %d %.1f", i, coeffFinal[i]);
		}
	}
	printf("\n");
	return 0;
}