#include <stdio.h>
#include <stdlib.h>

int main()
{
	int n = 0;
	int tmp = 0;
	int count = 0;
	
	scanf("%d", &n);
	if(n>1000){
		
		exit(1);
	}

	tmp = n;
	while(tmp != 1){
		if(tmp%2 == 0)	{
			tmp = tmp/2;
		}else{
			tmp = (tmp*3+1)/2;
		}
		count++;
	}
	printf("%d\n", count);

	return 0;
}