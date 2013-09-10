#include <stdio.h>
#include <stdlib.h>

typedef struct _StudentInfo{
	char name[11];
	char id[11];
	int grade;
}StudentInfo;


int main()
{
	int N = 0;
	int i;
	StudentInfo max;
	StudentInfo min;
	StudentInfo tmp;
	char tmpName[11];
	char tmpId[11];
	int tmpGrade = 0;
	
	max.grade = 0;
	min.grade = 100;


	scanf("%d", &N);
	for(i = 0; i < N; i++){
		scanf("%s %s %d", tmpName, tmpId, &tmpGrade);
		if(tmpGrade <= min.grade){
			min.grade = tmpGrade;
			strncpy(min.id, tmpId, sizeof(tmpId));
			strncpy(min.name, tmpName, sizeof(tmpName));
		}
		if(tmpGrade >= max.grade){
			max.grade = tmpGrade;
			strncpy(max.id, tmpId, sizeof(tmpId));
			strncpy(max.name, tmpName, sizeof(tmpName));
		}
	}

	printf("%s %s\n", max.name, max.id);
	printf("%s %s\n", min.name, min.id);
	return 0;
}
