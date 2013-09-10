#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>


#define min(a, b) ((a) < (b))?(a):(b)
#define MaxNum 2000
typedef struct _Student{
	char id[7];
	int clang;  //c programming language
	int math;  //math
	int eng;  //english
	int sum;  //sum of 3 courses, can represent average 
	//int rank;  //best rank
}Student;


int minRank(int clang, int math, int eng, int sum, char *index)
{
	int minR1 = 0;
	int minR2 = 0;
	int minR3 = 0;

	minR1 = min(clang, math);
	minR2 = min(eng, sum);
	minR3 = min(minR1, minR2);

	if(minR3 == sum){
		*index = 'A';
	}else if(minR3 == clang){
		*index = 'C';
	}else if(minR3 == math){
		*index = 'M';
	}else if(minR3 == eng){
		*index = 'E';
	}

	return minR3;
}

//*a > *b, return 1
//*a < *b, return -1
//*a == *b, return 0
int compareClang(const void *a, const void *b)
{
	Student *x = (Student *)a;
	Student *y = (Student *)b;
	if(x->clang > y->clang){
		return -1;
	}else if(x->clang < y->clang){
		return 1;
	}else{
		return 0;
	}
}

int compareMath(const void *a, const void *b)
{
	Student *x = (Student *)a;
	Student *y = (Student *)b;
	if(x->math > y->math){
		return -1;
	}else if(x->math < y->math){
		return 1;
	}else{
		return 0;
	}
}

int compareEng(const void *a, const void *b)
{
	Student *x = (Student *)a;
	Student *y = (Student *)b;
	if(x->eng > y->eng){
		return -1;
	}else if(x->eng < y->eng){
		return 1;
	}else{
		return 0;
	}
}

int compareSum(const void *a, const void *b)
{
	Student *x = (Student *)a;
	Student *y = (Student *)b;
	if(x->sum > y->sum){
		return -1;
	}else if(x->sum < y->sum){
		return 1;
	}else{
		return 0;
	}
}

int rankProcess(Student stu[], int n, char index)
{
	int tmpRank = 0;
	int tmpScore = 0;
	int oldScore = 0;
	int i;
	int *tmpStu;


	for(i = 0; i < n; i++){
		switch (index){
			case 's': tmpStu = &stu[i].sum; break;
			case 'c': tmpStu = &stu[i].clang; break;
			case 'm': tmpStu = &stu[i].math;  break;
			case 'e': tmpStu = &stu[i].eng;   break;
			default: break;
		}

		tmpScore = *tmpStu;
		if(oldScore == tmpScore){
			*tmpStu = tmpRank;
		}else{
			tmpRank = i + 1;
			*tmpStu = tmpRank;
		}
		oldScore = tmpScore;
	}
}

int main()
{
	int n, m;
	Student stu[MaxNum];
	int i, j;
	int maxFinalRank[MaxNum];
	int maxFinalRankTmp;
	char index[MaxNum];
	char indexTmp;
	int tmpScore, oldScore;
	int tmpRank, highRank;
	int result, flag;
	char tmpStudent[7];
	
	scanf("%d%d", &n, &m);
	for(i = 0; i < n; i++){
		scanf("%s%d%d%d", (stu[i].id), &(stu[i].clang), &(stu[i].math), &(stu[i].eng));
		stu[i].sum = stu[i].clang + stu[i].math + stu[i].eng;
	}

	qsort(stu, n, sizeof(Student), compareClang);
	rankProcess(stu, n, 'c');  //replace code below
	//tmpRank = 0;
	//tmpScore = 0;
	//oldScore = 0;
	//for(i = 0; i < n; i++){
	//	tmpScore = stu[i].clang;
	//	if(oldScore == stu[i].clang){
	//		stu[i].clang = tmpRank;
	//	}else{
	//		tmpRank = i + 1;
	//		stu[i].clang = tmpRank;
	//	}
	//	oldScore = tmpScore;
	//}
	
	qsort(stu, n, sizeof(Student), compareMath);
	rankProcess(stu, n, 'm');

	qsort(stu, n, sizeof(Student), compareEng);
	rankProcess(stu, n, 'e');

	qsort(stu, n, sizeof(Student), compareSum);
	rankProcess(stu, n, 's');

	result = 0;
	for(i = 0; i < m; i++){
		flag = 0;
		scanf("%s", tmpStudent);
		for(j = 0; j < n; j++){
			result = strncmp(tmpStudent, stu[j].id, 7);
			if(result == 0){  //found
				flag = 1;
				maxFinalRankTmp = minRank(stu[j].clang, stu[j].math, stu[j].eng, stu[j].sum, &indexTmp);
				break;
			}else{ 
				continue;
			}
		}

		if(flag == 0){
			maxFinalRank[i] = 0; 
		}else{
			maxFinalRank[i] = maxFinalRankTmp; 
			index[i] = indexTmp;
		}
	}

	for(i = 0; i < m; i++){
		if(maxFinalRank[i] != 0){
			printf("%d %c\n", maxFinalRank[i], index[i]); 
		}else{
			printf("N/A\n");
		}
	}

	return 0;
}
