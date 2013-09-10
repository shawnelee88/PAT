#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAXNUM 10000

int main()
{
	int a[MAXNUM];
	int i, j;
	int maxfront = 0;
	int maxrear = 0;
	int front = 0;
	int rear = 0;
	int sum = -1;
	int maxsum = -1;
	int n;

	scanf("%d", &n);
	for(i = 0; i < n; i++){
		scanf("%d", &a[i]);
	}

	for(i = 0; i < n; i++){
		if(sum < 0){
			sum = a[i];
			front = i;
			rear = i;
		}else{
			sum += a[i];
			rear = i;
		}

		if(sum > maxsum){
			maxsum = sum;
			maxfront = front;
			maxrear = rear;
		}
	}

	if(maxsum < 0){
		printf("0 %d %d\n", a[0], a[n-1]);
	}else{
		printf("%d %d %d\n", maxsum, a[maxfront], a[maxrear]);
	}
	return 0;
}
