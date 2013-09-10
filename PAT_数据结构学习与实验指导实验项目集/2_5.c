#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAXN 10000

int main()
{
	int N;
	int i;
	float tmp;
	double result;
	int sum;
	double avg;
	int Numbers[MAXN];

	scanf("%d", &N);
	for(i = 0; i < N; i++){
		scanf("%d", &Numbers[i]);
	}
	
	result = 0.0;
	avg = 0.0;
	sum = 0;
	tmp = 0.0;
	for(i = 0; i < N; i++){
		sum += Numbers[i];
	}
	avg = sum*1.0/N;
	
	for(i = 0; i < N; i++){
		result += (Numbers[i] - avg)*(Numbers[i] - avg);
	}
	result = result / N;
	result = sqrt(result);
	printf("%.5f\n", result);
	return 0;
}