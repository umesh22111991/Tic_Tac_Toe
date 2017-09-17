#include <stdio.h>
#include <string.h>
#define RLIMIT 3
#define CLIMIT 3
#define USER1VALUE 'X';
#define USER2VALUE 'O';

int userCount = 0; 

void ShowWindow(char arr[RLIMIT][CLIMIT])
{
	int i,j;
	printf("\n");
	for(i=0 ; i < RLIMIT ; i++)
	{
		for(j=0 ; j < CLIMIT ; j++)
		{
			printf("\t%c", arr[i][j]);

		}
		printf("\n");
	}
	printf("\n");
}

void getUPos(int *xPos , int *yPos)
{
	printf("\n\tEnter Row Position >>> ");
	scanf("%d" , xPos);
	printf("\n\tEnter Col Position >>> ");
	scanf("%d" , yPos);
}

void getPos(int *xPos , int *yPos)
{
	userCount++;
	if(userCount%2 == 0)
	{
		printf("\n USER 2 >>>>>  ");
		getUPos(xPos , yPos);
		
	}
	else
	{
		printf("\n USER 1 >>>>>  ");
		getUPos(xPos,yPos);	
		
	}
}

void storeVlaue(char arr[RLIMIT][CLIMIT] , int xPos , int yPos)
{
	if(arr[xPos][yPos] != '-')
	{
		printf("\n***Invalid Position***");
		userCount--;
		return;
	}
	else
	{
		if(userCount%2 == 0)
		{
			arr[xPos][yPos] = USER2VALUE;
		}
		else
		{
			arr[xPos][yPos] = USER1VALUE;
		}	
	}
}

int checkRow(char arr[RLIMIT][CLIMIT], int xPos , int yPos)
{
	int flag = 0;
	int i;	
	for(i=0 ; i<CLIMIT ; i++)
	{
		if(CLIMIT == i)
		{
			continue;
		}
		else 
		{
			if(arr[xPos][yPos] == arr[xPos][i])
			{
				continue;
			}
			else
			{
				flag = 1;
			}
		}
		if(flag == 1)
			break;
	}
	return flag;
}

int checkcol(char arr[RLIMIT][CLIMIT], int xPos ,int yPos)
{
	int flag = 0;
	int i;	
	for(i=0 ; i<RLIMIT ; i++)
	{
		if(RLIMIT == i)
		{
			continue;
		}
		else 
		{
			if(arr[xPos][yPos] == arr[i][yPos])
			{
				continue;
			}
			else
			{
				flag = 1;
			}
		}
		if(flag == 1)
			break;
	}
	return flag;
}

void printWinnerMark(char arr[RLIMIT][CLIMIT], int xPos , int yPos , int stat)
{
	int i,j, k = 1;
	printf("\nWinner Status >>>  \n");
	for(i=0 ; i<RLIMIT ; i++)
	{
		for (j = 0; j < CLIMIT; j++)
		{
			if(stat == 0)
			{
				if(xPos == i)
				{
					printf("\t%c",arr[i][j]);
				}
				else
				{
					printf("\t%c",'-');	
				}
			}
			else if(stat == 1)
			{
				if(yPos == j)
				{
					printf("\t%c",arr[i][j]);
				}
				else
				{
					printf("\t%c",'-');	
				}		
			}
			else if(stat == 2)
			{
				if(j == (CLIMIT - k))
				{
					printf("\t%c",arr[i][j]);
					k++;
				}
				else
				{
					printf("\t%c",'-');	
				}
			}
			else if(stat == 3)
			{
				if(i == j)
				{
					printf("\t%c",arr[i][j]);
				}
				else
				{
					printf("\t%c",'-');	
				}
			}
		}
		printf("\n");	
	}
}


int chekFcross(char arr[RLIMIT][CLIMIT], int xPos , int yPos)
{
	int flag = 0;
	int i,j;
	for(i = 0 , j = CLIMIT-1 ; ((i<CLIMIT) && (j>=0)) ; i++ , j--)
	{
		
		if(arr[i][j] == arr[xPos][yPos])
		{
			continue;
		}
		else
		{
			flag = 1; 
		}
		if(flag == 1)
		{
			break;
		}
	}			
	if((i == CLIMIT) && (j == -1) && (flag == 0))
		return flag;
	else
		return 1;
}

int chekBcross(char arr[RLIMIT][CLIMIT], int xPos , int yPos)
{
	int flag = 0;
	int i;
	for (i = 0; i < RLIMIT; i++)
	{
		if(arr[i][i] == arr[xPos][yPos])
		{
			continue;
		}
		else
		{
			flag = 1;
		}
		if(flag == 1)
		{
			break;
		}
	}
	return flag;
}

int checkWinnerPosition(char arr[RLIMIT][CLIMIT], int xPos , int yPos)
{
	int winner_status = 1;
	winner_status = checkRow(arr, xPos , yPos);
	if(winner_status == 0)
	{
		//Print Winner row
		printWinnerMark(arr, xPos , yPos , 0);
		return 1;
	}
	winner_status = checkcol(arr, xPos , yPos);
	if(winner_status == 0)
	{
		//Print Winner col
		printWinnerMark(arr, xPos , yPos , 1);
		return 1;
	}
	winner_status = chekFcross(arr, xPos , yPos);
	if(winner_status == 0)
	{
		//Print Winner Forward cross
		printWinnerMark(arr, xPos , yPos , 2);
		return 1;
	}
	winner_status = chekBcross(arr, xPos , yPos);
	if(winner_status == 0)
	{
		//Print Winner Forward cross
		printWinnerMark(arr, xPos , yPos , 3);
		return 1;
	}
	return 0;	
}


int main()
{
	int winner_stat;
	int xPos ;
	int yPos ;
	char arr[RLIMIT][CLIMIT];
	memset(arr , '-' , sizeof(char) * RLIMIT * CLIMIT);
	int cnt = 0;
	while(1)
	{
			if (cnt++ == 0)
			ShowWindow(arr);
			getPos(&xPos , &yPos);
			storeVlaue(arr , xPos , yPos);
			ShowWindow(arr);


			if((userCount >= 5) && (checkWinnerPosition(arr, xPos , yPos)))
			{
				printf("\n***WIN ");
				if(userCount%2 == 0)
				{
					printf("USER 2\n");
					break;
				}
				else
				{
					printf("USER 1\n");
					break;	
				}
			}
			
	}
	return 0;
}