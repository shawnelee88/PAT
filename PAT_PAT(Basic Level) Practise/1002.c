#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 101

int main()
{
	char numberSeq[MAX_SIZE];
	char array[10][5] = {"ling", "yi", "er", "san", "si", "wu", "liu", "qi", "ba", "jiu"};
	char result[10];  //max sum of 100 digit is less than 900
	int i = 0;
	int j = 0;
	int sum = 0;
	int size = 0;
	int tmp = 0;
	
	//read in data as string,
	size = read(fileno(stdin), numberSeq, MAX_SIZE) - 1;	
	for(i = 0; i < size; i++)
	{
		sum += (numberSeq[i] - '0');
	}
	
	//transform sum(int) to a reversed string
	//456-->"654"
	tmp = sum;
	while(tmp/10 != 0){
		result[j] = tmp % 10 + '0';
		j++;
		tmp /= 10;
	}
	result[j] = tmp%10 + '0';
	
	//print the string reversely
	//"654"-->4(si)-->5"wu"->6"liu"
	printf("%s", array[result[j]-'0']);
	for(i = j-1; i >= 0; i--)
	{
		printf(" %s", array[result[i]-'0']);
	}

	return 0;
}
