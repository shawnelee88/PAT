#include<stdio.h>
#include<string.h>

int main()
{
	char inputs[81][81];
	char str[81];
	char ch;
	int count = 0;
	int i;

	while(scanf("%s%c",str,&ch))
	{
		strncpy(inputs[count],str, strlen(str));
		inputs[count++][strlen(str)] = '\0';
		if(ch=='\n')
			break;
	}

	for(i = count-1; i >= 0; i--)
	{
		printf("%s", inputs[i]);
		if(i != 0)
			printf(" ");

	}

	printf("\n");
	return 0;
}