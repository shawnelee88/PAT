#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double max3(double a[], int n, char *index)
{
	double maxNum;

	maxNum = (a[0] > a[1])?a[0]:a[1];
	maxNum = (maxNum > a[2])?maxNum:a[2];
	if(maxNum == a[0]){
		*index = 'W';
	}else if(maxNum == a[1]){
		*index = 'T';
	}else if(maxNum == a[2]){
		*index = 'L';
	}

	return maxNum;
}

int main()
{
	double input[3];
	double maxOdd[3];
	char index[3];
	double tmpMax;
	double result;
	int i, j;

	for(i = 0; i < 3; i++){
		scanf("%lf%lf%lf", &input[0], &input[1], &input[2]);
		maxOdd[i] = max3(input, 3, &index[i]);
	}

	result = (maxOdd[0]*maxOdd[1]*maxOdd[2]*0.65 - 1)*2;

	printf("%c %c %c %.2lf\n", index[0], index[1], index[2], result);
	
	return 0;
}
