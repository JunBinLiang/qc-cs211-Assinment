// 8 cross.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;
void print(int board[8]) {

	for (int i = 0; i <= 7; i++)
	{
		cout << board[i] << " ";
	}cout << endl;
}



int main()
{
	int board[8]= { 0 };  //1 to 8
	int col =0;
	int row = 0;
	int count = 0;
	int val = 1;
	int static helper[8][5] = { //column size varies!     10 means dont care
		{ -1,-1,-1,-1,-1 }, //box 0
	{ 0, -1 ,-1,-1,-1 }, //box 1
	{ 0, 1, -1,-1,-1 }, //box 2
	{ 0, 2, -1,-1,-1 }, //box 3
	{ 1, 2, -1,-1,-1 }, //box 4
	{ 1, 2, 3, 4, -1 }, //box 5
	{ 2, 3, 5, -1,-1 }, //box 6
	{ 4, 5, 6, -1,-1 } //box 7
	};
	goto nextR;
nextR:
	board[col]++;
	if (board[col] > 8) { board[col] = 0;  goto BackTrack; }
	goto check;
nextC:
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
	goto nextR;
	
check:
	for (int c = 0; c < col; c++)  //horizontal test
	{
		if (board[c] == board[col])goto nextR;
	}

	for (int i = 0; i < 5; i++) {
		int index = helper[col][i];

		if (index == -1)continue;
		//consecutive
		if ((board[col] - 1) == board[index])goto nextR;
		if ((board[col] + 1) == board[index])goto nextR;
	}
	goto nextC;
BackTrack:
	col--;
	if (col < 0)goto Done;
	goto nextR;

Done:
	cout << count << "times" << endl;
	cout << "program end~~" << endl;
    return 0;
}

