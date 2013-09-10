#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAXNUM 10000

int main()
{
	int prev = 0, curr = 0;
	int n, i;
	int up = 0;
	int down = 0;
	int totaltime;

	scanf("%d", &n);
	i = n;
	while(i--){
		scanf("%d", &curr);
		if(curr > prev){
			up = curr - prev + up;
		}else if(curr < prev){
			down = prev - curr + down;
		}
		prev = curr;
	}

	totaltime = n*5 + up*6 + down*4;
	printf("%d\n", totaltime);
	return 0;
}
