#include<stdio.h>
#include<math.h>

int Reverse(int a[], int N)
{
	int i;
	int tmp;

	for(i = 0; i < N/2; i++){
		tmp = a[i];
		a[i] = a[N - 1 - i];
		a[N - 1 -i] = tmp;	
	}
}

int main()
{
	int n = 0;
	int m = 0;
	int i = 0;
	int *a = NULL;
	int isfirst = 1;

	scanf("%d %d", &n, &m);
	a = malloc(n*sizeof(int));
	for(i = 0; i < n; i++){
		scanf("%d", &a[i]);
	}
	
	Reverse(a, n);
	Reverse(a, m%n);
	Reverse(a+m%n, n-m%n);
	for(i = 0; i < n; i++){
		if(isfirst){
			printf("%d", a[i]);
			isfirst = 0;
		}else{
			printf(" %d", a[i]);
		}
	}
	printf("\n");
	return 0;
}