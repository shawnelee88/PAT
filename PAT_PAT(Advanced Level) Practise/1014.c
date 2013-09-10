#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MaxCustomers 1000
#define TimeLimit 60*9

int time[MaxCustomers + 1];  //processing time of customer use
int result[MaxCustomers + 1];
typedef struct _Person{
	int id;
	int timeLeft;
}Person;

typedef struct _Queue{
	int capacity;
	int size;
	Person p[11];  //use a[1]~a[10] as the queue
}Queue;


Queue *initQueue(int n)
{
	Queue *q;

	q = malloc(sizeof(Queue));
	if(q == NULL){
		perror("Out of space!");
		exit(1);
	}
	memset(q, 0, sizeof(Queue));	
	q->capacity = n;
	return q;
}

//return 0 if queue is not full and enqueue 
//return 1 if queue is full
int enQueue(Person *p, Queue *q)
{
	if(q->size != q->capacity){  //not full
		q->size++;
		q->p[q->size].id = p->id;
		q->p[q->size].timeLeft = p->timeLeft;
		return 0;
	}else{  
		return -1;
	}
}

//return the element when queue is not empty
//return -1 when queue is empty
void deQueue(Queue *q)
{
	int i;
	int tmp;

	if(q->size == 0){  //empty
		return;
	}else{
		for(i = 1; i <= q->size; i++){
			q->p[i - 1].id = q->p[i].id;
			q->p[i - 1].timeLeft = q->p[i].timeLeft;
		}
		q->p[0].id = 0;
		q->p[0].timeLeft = 0;
		q->p[q->size].id = 0;
		q->p[q->size].timeLeft = 0;
		q->size--;
		return;
	}
}


int main()
{
	int n, m, k, q;
	int i, j;
	int customerLeft;
	Queue *windows[21];  //use windows[1]~windows[20]
	Queue *tmpQueue;
	Person *tmpPerson;
	int minTime;
	int timer = 0;
	int query = 0;

	tmpPerson = malloc(sizeof(Person));
	if(tmpPerson == NULL){
		perror("Out of space!.");
		exit(1);
	}

	scanf("%d%d%d%d", &n, &m, &k, &q);
	for(i = 1; i <= n; i++){ //init n queues
		windows[i] = initQueue(m);
	}

	for(i = 1; i <= k; i++){  //input processing time of k customers
		scanf("%d", &time[i]);
	}

	customerLeft = k;

	while(1){
		/************************************************************************/
		/* 17:00之前进入的人,就算结束时间晚于17:00可以得到服务                  */
		/* 而晚于17:00之后的就算想进入即不再加入queue中                         */
		/* 故一开始就要判断时间是否超出界限                                     */
		/************************************************************************/
		if(timer < TimeLimit){  
			//若没有剩下的客户需要得到服务，就直接继续，否则按规则插入到队列中
			//两种情况：开始全部为空时的插入，以及满的时候选择最短的插入
			//规则：找最短队列，若有多条队伍一样长，找下标最小的那条
			//if(customerLeft > 0){
			for(i = 0; i < m; i++){
				for(j = 1; j <= n; j++){
					if(windows[j]->size == i && customerLeft > 0){ //队伍都满的时候选择插入需要判断的次数较多
						tmpPerson->id = k - (customerLeft--) + 1;  //ID:1~n
						tmpPerson->timeLeft = time[tmpPerson->id];
						enQueue(tmpPerson, windows[j]);  //插入队列中
					}
				}
			}
			//}
		}

		//找到所有队伍最开头那个人需要服务的时间的最小值
		minTime = 0;
		for(i = 1; i <= n; i++){
			if(windows[i]->size != 0){
				if(minTime == 0 || minTime > windows[i]->p[1].timeLeft){
					minTime = windows[i]->p[1].timeLeft;
				}
			}
		}

		timer += minTime;

		//如果没有下一个离开窗口的时间，则表明所有人都服务完毕
		if(minTime == 0){
			break;
		}

		for(i = 1; i <= n; i++){
			if(windows[i]->size != 0){
				//队首每个人都消耗相同的最小时间，故每个人所剩时间都需减去minTime
				windows[i]->p[1].timeLeft -= minTime;
				//与之前找到minTime的相同所有队列首元素就是要同时离开的人
				if(windows[i]->p[1].timeLeft == 0){
					result[windows[i]->p[1].id] = timer;  //保存对应人所离开的时间
					deQueue(windows[i]);

					//17:00之前加入的，就算结束时间17:00之后也可以得到服务，故
					//先出队，再将队列中剩余元素全部清空，可看case分析，第6次循环的分析
					if(timer >= TimeLimit){ 
						while(windows[i]->size != 0){
							deQueue(windows[i]);
						}
					}
				}
			}
		}	
	}

	for(i = 0; i < q; i++){
		scanf("%d", &query);
		if(result[query] == 0){
			printf("Sorry\n");
		}else{
			printf("%02d:%02d\n", 8 + result[query]/60, result[query]%60);
		}
	}

	return 0;
}
