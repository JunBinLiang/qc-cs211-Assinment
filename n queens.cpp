// n queens.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;

int main()
{
	cout << "please enter a number n for the queens you want to test!!!" << endl;
	int myCol;
	cin >> myCol; //8
	int *board = new int[myCol];
	for (int i = 0; i < myCol; i++)
	{   //0 1 2  3 4 5 6 7
		board[i] = -1;
	}
	int lessone;
	lessone = myCol - 1;

	int col = 0;
	int count = 0;

NextR:
	board[col]++;
	//print(board);
	if (board[col] > lessone) { board[col] = -1;  goto BackTrack; }
	goto Check;

Check:
	for (int c = 0; c < col; c++)  //horizontal test
	{
		if (board[c] == board[col])goto NextR;
	}
	//cout << "good" << endl;
	// no vertical check
	for (int i = 1; i <= lessone; i++)
	{
		if ((col - i) < 0 || board[col - i]<0)break;

		if ((board[col] - i) == (board[col - i]))
			goto NextR;
	}
	//cout << "good1" << endl;

	for (int i = 1; i <= 7; i++)
	{
		if ((col - i) < 0 || board[col - i]>lessone)break;

		if ((board[col] + i) == (board[col - i]))
			goto NextR;
	}
	//cout << "good2" << endl;
	// safe
	goto NextC;

NextC:
	col++;

	if (col == myCol)
	{

		//printing
		for (int i = 0; i <= lessone; i++)
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
	delete[] board;
	return 0;
}

