#include<stdio.h>
#include<string.h>

enum states {beforeP,findP,findT};


int main()
{
  int n;
  char str[101];
  states s;
  int res;
  int head;
  int middle;
  int tail;

  scanf("%d",&n);
  getchar();
  

  while(n--)
  {
      //initialize state and result
      s = beforeP;
      res = 1;
      head = 0;
      middle = 0;
      tail = 0;
      
      //get input
      gets(str);

      //analysis
      for( int i = 0 ; i < strlen(str) ; i++)
      {
          if(str[i] == 'P')
          {
              if(s == beforeP)
              {
                  s = findP;
              }
              else
              {
                  res = 0;  //multi P
                  break;
              }
                  
          }
          else if(str[i] == 'T')
          {
              if(s == findP)
              {
                  s = findT;
              }
              else
              {
                  res = 0;  //multi T
                  break;
              }
          }
          else if(str[i] == 'A')
          {
              if(s == beforeP)
              {
                  head++;
              }
              else if(s == findP)
              {
                  middle++;
              }
              else if(s == findT)
              {
                  tail++;
              }            
          }
          else   //invalid input
          {
              res = 0;
              break;
          }            
      }

      if(res == 1 && s == findT && middle > 0 && tail == middle*head)
          res = 1;
      else
          res = 0;
      
      if(res)
          printf("YES\n");
      else
          printf("NO\n");

  }
  return 0;
}

#if 0
//c++ version, ok on local machine and PAT
#include <string>
#include <iostream>

using namespace std;

int main()
{
	int n;
	cin >> n;

	while (n--)
	{
		string s;
		cin >> s;

		size_t p = s.find_first_not_of("A");
		if ((p == string::npos) || (s[p] != 'P'))
		{
			cout << "NO" << endl;
			continue;
		}

		size_t t = s.find_first_not_of("A", p + 1);
		if ((t == string::npos) || (t == p + 1) || (s[t] != 'T'))
		{
			cout << "NO" << endl;
			continue;
		}

		size_t n = s.find_first_not_of("A", t + 1);
		if (n != string::npos)
		{
			cout << "NO" << endl;
			continue;
		}

		if ((s.length() - t - 1) == p * (t - p - 1))
		{
			cout << "YES" << endl;
		}
		else
		{
			cout << "NO" << endl;
		}
	}

	return 0;
}

#endif

#if 0
//ok on local machine, not ok on PAT
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_SIZE 101

int checkRuleOne(char *str, int n);
int checkAllRule(char *str, int n);


int checkRuleOne(char *str, int n)
{
	int i = 0;
	int flag = 0;

	for(i = 0; i < n; i++){
		if((str[i] == 'P') || (str[i] == 'A') || (str[i] == 'T')){
			flag = 0;
			continue;
		}else{
			flag = 1;
			break;
		}
	}

	if(flag == 1){
		return 1;
	}else{
		return 0;
	}
}


int checkAllRule(char *str, int n)
{
	int i = 0;
	int j = 0;
	int posP = 0;
	int posT = 0;
	int pFound = 0;  //P found if 1
	int tFound = 0;  //T found if 1

	for(i = 0; i < n; i++){
		if(str[i] == 'P'){
			posP = i;
			pFound++;
		}
		if(str[i] == 'T'){
			posT = i;
			tFound++;
		}
	}

	if((pFound == 1) && (tFound == 1)){
		if(posT - posP <= 1){
			return 1;
		}else{
			if(posP*(posT-posP-1) == (n-posT-1)){
				return 0;
			}else{
				return 1;
			}
		}
	}else{
		return 1;
	}
}


int main()
{
	char buf[MAX_SIZE];
	int i = 0;
	int j = 0;
	int nStrings = 0;
	int size = 0;
	
	scanf("%d", &nStrings);
	fflush(stdin);
	for(i = 0; i < nStrings; i++){
		fgets(buf, MAX_SIZE, stdin);
		fflush(stdin);
		
		if(!checkRuleOne(buf, strlen(buf)-1)){
			if(checkAllRule(buf, strlen(buf)-1)){
				printf("NO\n");
			}else{
				printf("YES\n");
			}
		}	
		else{
			printf("NO\n");
		}
	}

	
	return 0;
}

#endif