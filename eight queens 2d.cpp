// 2d Eight.cpp : Defines the entry point for the console application.
//

#include <iostream>
using namespace std;

void print(int board[8][8])
{

	for (int r = 0; r < 8; r++)
	{
		for (int c = 0; c < 8; c++)
		{
			cout << board[r][c] << " ";
		}cout << endl;
	}cout << endl << endl;
}

int main()
{   
	int board[8][8] = {0};
	int col = 0;
	int count = 0;
	int row = -1;	
	goto NextR;


NextR:
	row++;
	if (row == 8) { goto BackTrack; }
	goto check;

check:
	
	for (int r = 0; r <= row; r++)
	{
		if (board[r][col] == 1)    //unsafe   row checking
			goto NextR;
	}
	for (int c = 0; c<= col; c++)
	{
		if (board[row][c] == 1)   //unsafe  column checking
			goto NextR;
	}

	for (int i = 1; i <=row ; i++)  //diagonal checking
	{
		if ((row-i)<0 || (col-i)<0)break;
		if (board[row - i][col - i] == 1)
			goto NextR;
	}
	for (int j = 1; j <=(7-row); j++)
	{
		if ((row+j)>7 || (col - j)<0)break;
		if (board[row + j][col - j] == 1)
			goto NextR;
	}



	  board[row][col] = 1; // after checking, safe
	  goto NextC;

 NextC:
	  col++;

	  if (col == 8) 
	  {   
		  count++;
		  for (int r = 0; r < 8; r++)
		  {
			  for (int c = 0; c < 8; c++)
			  {
				  cout<< board[r][c] << " ";
			  }cout << endl;
		  }cout << endl << endl;
		  goto BackTrack; 	  
	  }
	  row = -1;
	  goto NextR;

 
 BackTrack:
	  col--;
	  if (col == -1)goto Done;
	  row = -1;
	  for (int i = 0; i <= 7; i++)
	  {
		  if (board[i][col] == 1)
		  { 
			  board[i][col] = 0;  //assign to 0
			  row = i;
			  break;
		  }
	  }
	  goto NextR;


  Done:
	  cout << count << "times" << endl;
	  cout << "End of the program"<<endl;

    return 0;
}

