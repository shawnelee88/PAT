#include <stdio.h>
#include <stdlib.h>


int main()
{
	int m;
	int i;
	char Locker[16];
	char Unlocker[16];
	char student[16];
	char startTime[9];
	char endTime[9];
	char earlistTime[9] = "23:59:59";
	char latestTime[9] = "00:00:00";
	int result = 0;

	scanf("%d", &m);
	for(i = 0; i < m; i++){
		scanf("%s%s%s", student, startTime, endTime);
		result = strncmp(startTime, earlistTime, 8);
		if(result <= 0){  //startTime < earlistTime
			strncpy(earlistTime, startTime, sizeof(startTime));
			strncpy(Unlocker, student, sizeof(student));
		}

		result = strncmp(endTime, latestTime, 8);
		if(result >= 0){
			strncpy(latestTime, endTime, sizeof(endTime));
			strncpy(Locker, student, sizeof(student));
		}
	}
	
	printf("%s %s\n", Unlocker, Locker);

	return 0;
}
