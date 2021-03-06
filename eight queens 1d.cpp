// 1D eight.cpp : Defines the entry point for the console application.
//

//#include "stdafx.h"
#include <iostream>
using namespace std;

void print(int board[8]){

	for (int i = 0; i <= 7; i++)
	{
		cout << board[i] << " ";
	}cout << endl;
}


int main()
{ 

	int board[8] = { -1,-1,-1,-1,-1,-1,-1,-1 };  
	int col = 0;
	int count = 0;

NextR:
	board[col]++;
	//print(board);
	if (board[col] > 7) { board[col] = -1;  goto BackTrack; }
	goto Check;

Check:
	for (int c = 0; c < col; c++)  //horizontal test
	{
		if (board[c] == board[col])goto NextR;
	}
	//cout << "good" << endl;
// no vertical check
	for (int i = 1; i <= 7; i++) 
	{
		if ((col - i) < 0 || board[col - i]<0)break;

		if ((board[col] - i) == (board[col - i]))
			goto NextR;
	}
	//cout << "good1" << endl;

	for (int i = 1; i <= 7; i++)
	{
		if ((col - i) < 0 || board[col-i]>7)break;

		if ((board[col] + i) == (board[col - i]))
			goto NextR;
	}
	//cout << "good2" << endl;
	// safe
	goto NextC;

NextC:
	col++;
	
	if (col == 8)
	{
		
		for (int i = 0; i <= 7; i++)
		{
			cout << board[i] << " ";
		}cout << endl;
		count++;
		goto BackTrack;
	}
	goto NextR;
	


BackTrack:
	col--;
	if (col < 0)goto Done;
	goto NextR;


	
Done:
	cout << count << "times" << endl;
	cout << "program end~~" << endl;
    return 0;
}

