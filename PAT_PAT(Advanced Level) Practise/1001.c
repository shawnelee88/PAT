#include <stdio.h>
#include <stdlib.h>

int main()
{
	int a = 0;
	int b = 0;
	int c = 0;
	int tmp = 0;
	int len = 0;
	int i = 0;
	int j = 0;
	char result[10];

	while(scanf("%d %d", &a, &b) != EOF){
		c = a + b;
		if(c < 0){
			tmp = -c;
		}else{
			tmp = c;
		}

		while(tmp/10 != 0){
			result[j++] = tmp % 10 + '0';
			len++;
			if(len%3 == 0){
				result[j++] = ',';
			}
			tmp = tmp /10;
		}
		result[j++] = tmp % 10 + '0';
		if(c < 0 ){
			result[j++] = '-';
		}

		for(i = j-1; i >=0; i--){
			printf("%c", result[i]);
		}
		printf("\n");

	}
	return 0;
}