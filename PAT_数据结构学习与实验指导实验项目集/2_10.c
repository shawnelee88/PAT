#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 100
#define MINSIZE 3

int ReverseFindOne(int a[], int n)
{
	int i;
	int index = 0;

	for(i = n - 1; i >= 0; i--){
		if(a[i] == 1){
			return i;
		}
	}
}

int main()
{

	int array[MAXSIZE];
	int D, P;  //D-Diamonds; P-person
	int len, i, j;
	int lastZero = 0;
	int tmp = 0;
	int sum = 0;
	int minIndex = 0;  //index of min elemet except 0

	scanf("%d%d", &D, &P);
	array[0] = 0;
	array[1] = 1;
	array[2] = D - 1;
	len = 3;

	for(j = 0; j < P-3; j++){
		sum = 0;
		minIndex = ReverseFindOne(array, len);
		for(i = 0; i < len; i++){
			if(array[i] == 0){
				array[i]++; 
				sum += array[i];

			}else{
				if(i == minIndex){
					array[minIndex]++;
				}else{
					array[i] = 0;
				}	
			}
		}

		array[len] = D - sum - array[minIndex];
		len++;	
	}
	printf("%d\n", array[len - 1]);
	return 0;
}


