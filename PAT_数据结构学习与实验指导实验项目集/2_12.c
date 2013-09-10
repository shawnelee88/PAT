#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _Node{
	int data;
	struct _Node *next;
}Node;
typedef Node *List;
typedef Node *Position;

List Initialize()
{
	List L;
	
	L = malloc(sizeof(Node));
	if(L == NULL){
		perror("malloc error.");
		exit(1);
	}

	L->next = NULL;
	return L;
}


int IsEmpty(List L)
{
	if(L->next == NULL){  //empty
		return 0;
	}else{
		return 1;
	}
}

//insert after the end of list
List Insert(List L, int key, Position Pos)
{
	Position P;
	Position TmpCell;
	Position Prev;

	TmpCell = malloc(sizeof(Node));
	if(TmpCell == NULL){
		perror("malloc error.");
		exit(1);
	}

	TmpCell->data = key;
	TmpCell->next = NULL;

	Pos->next = TmpCell;
	//P = Find(L, key);
	//if(P != NULL){  //key found, insert after the element
	//		TmpCell->next = P->next;
	//		P->next = TmpCell;		
	//}else{  //key not found, insert after the lesser one		
	//	if(IsEmpty(L) == 0){
	//		L->next = TmpCell;
	//	}else{
	//		for(P = L->next; P != NULL; P = P->next){
	//			if(key >= P->data){
	//				Prev = P;
	//			}else{
	//				if(P == L->next){  //insert after the head
	//					TmpCell->next = P;
	//					L->next = TmpCell;
	//				}else{
	//					TmpCell->next = P;
	//					Prev->next = TmpCell;
	//				}
	//				return L;				
	//			}
	//		}
	//		Prev->next = TmpCell;  //insert after the end
	//	}	
	//}
	return L;
}



void PrintList(List L)
{
	Position P;

	if(L->next == NULL){  //empty list
		printf("NULL");
	}else{
		P = L->next;
		printf("%d", P->data);
		P = P->next;
		while(P != NULL){
			printf(" %d", P->data);
			P = P->next;
		}
	}
	printf("\n");
}
//
//List Merge(List L1, List L2)
//{
//	Position P1;
//	Position P2;
//	Position P3;
//	List L3;
//
//	L3 = Initialize();
//	
//	P1 = L1->next;
//	P2 = L2->next;
//	P3 = L3;
//
//	while(P1 && P2){
//		if(P1->data < P2->data){
//			//Insert(L3, P1->data, P3);  //malloc another block of mem
//			P3->next = P1;  //modify on the original list
//			P3 = P3->next;
//			P1 = P1->next;
//		}else{
//			//Insert(L3, P2->data, P3);
//			P3->next = P2;
//			P3 = P3->next;
//			P2 = P2->next;
//		}
//	}
//	while(P1){
//		//Insert(L3, P1->data, P3);
//		P3->next = P1;
//		P3 = P3->next;
//		P1 = P1->next;
//	}
//	while(P2){
//		//Insert(L3, P2->data, P3);
//		P3->next = P2;
//		P3 = P3->next;
//		P2 = P2->next;
//	}
//
//	return L3;
//}


List Mix(List L1, List L2)
{
	List L3;
	Position P1, P2, P3;
	Position tmp1 = NULL;
	Position tmp2 = NULL;

	P1 = L1->next;
	P2 = L2->next;
	L3 = Initialize();
	P3 = L3;
	if(IsEmpty(L1) && IsEmpty(L2)){
		while(P1 && P2){
			if(P1->data < P2->data){
				tmp1 = P1;
				P1 = P1->next;
				free(tmp1);
			}else if(P1->data > P2->data){
				tmp2 = P2;
				P2 = P2->next;
				free(tmp2);
			}else{
				Insert(L3, P1->data, P3);
				P3 = P3->next;
				tmp1 = P1;
				tmp2 = P2;
				P1 = P1->next;
				P2 = P2->next;
				free(tmp1);
				free(tmp2);
			}
		}	
	}

	return L3;
}


int main()
{
	List L1, L2, L3;
	int flag1 = 0, flag2 = 0;
	Position P1;
	Position P2;
	int tmp1, tmp2;

	L1 = Initialize();
	L2 = Initialize();
	L3 = Initialize();
	P1 = L1;
	P2 = L2;
	//Insert(L1, 2);  //空插
	//Insert(L1, 5);	//尾部插入
	//Insert(L1, 7);  //尾部插入
	//Insert(L1, 3);  //普通插入
	//Insert(L1, 1);  //首部插入

	scanf("%d", &tmp1);
	if(tmp1 != -1){
		Insert(L1, tmp1, P1);
		P1 = P1->next;
		while(scanf("%d", &tmp1)){
			if(tmp1 != -1){
				Insert(L1, tmp1, P1);
				P1 = P1->next;
			}else{
				break;
			}
		}
	}

	scanf("%d", &tmp2);
	if(tmp2 != -1){
		Insert(L2, tmp2, P2);
		P2 = P2->next;
		while(scanf("%d", &tmp2)){
			if(tmp2 != -1){
				Insert(L2, tmp2, P2);
				P2 = P2->next;
			}else{
				break;
			}
		}
	}

	//L3 = Merge(L1, L2);
	L3 = Mix(L1, L2);
	PrintList(L3);

	return 0;

}
