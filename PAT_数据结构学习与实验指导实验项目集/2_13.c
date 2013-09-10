#include <stdio.h>
#include <stdlib.h>
#include <string.h>



void PrintMid(int *buffer1, int *buffer2, int n){
	
	int count1 = 0;
	int count2 = 0;
	int tmp;

	

	while(count1 < n && count2 < n){
		if(buffer1[count1] <= buffer2[count2]){
			tmp = buffer1[count1];
			count1++;
			if(count1 + count2 == n){
				printf("%d", tmp);
				break;
			}
		}else if(buffer1[count1] > buffer2[count2]){
			tmp = buffer2[count2];
			count2++;
			if(count1 + count2 == n){
				printf("%d", tmp);
				break;
			}
		}			
	}
}

int main()
{

	int flag1 = 0, flag2 = 0;

	int tmp1, tmp2;
	int n;
	int cnt1 = 0;
	int cnt2 = 0;
	int buffer1[100000];
	int buffer2[100000];


	scanf("%d", &n);

	while(1){
		if(cnt1 != n){
			scanf("%d", &tmp1);
			buffer1[cnt1++] = tmp1;
			//Insert(L1, tmp1, P1);
		}else{
			break;
		}
	}
	

	while(1){
		if(cnt2 != n){
			scanf("%d", &tmp2);
			buffer2[cnt2++] = tmp2;
			//Insert(L2, tmp2, P2);		
		}else{
			break;
		}
	}


	PrintMid(buffer1, buffer2, n);
	printf("\n");

	return 0;

}
