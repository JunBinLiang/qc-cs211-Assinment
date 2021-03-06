// bitshop.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<iostream>
#include<cmath>
using namespace std;



bool ok(int arry[],int placeIndex, int n,int whichCol)  //n 4
{
	
	for (int i = 0; i < whichCol; i++) {
		if (placeIndex == arry[i])return false;
	}//cout <<"col  "<<whichCol<<"Index "<< placeIndex << endl;

	int row = placeIndex % n; 
	int col = placeIndex / n;
	//cout << row << " " << col << endl;  
	// col-1&&row-1   col-1&&row+10.
	for (int i=0;i<n;i++) 
	{
		if (((col - i) < 0) || ((row - i) < 0)) { break; }   //up
		int placeCol = col - i; int placeRow = row - i;

		for (int resultArrI = 0; resultArrI < whichCol; resultArrI++)      //loop through the result array
		{
			int previousCol = arry[resultArrI] / n;
			int previousRow= arry[resultArrI] %n;    //get the previous array's col and row Index
			if ((previousCol == placeCol) && (previousRow == placeRow))return false;
		}
	}

	for (int j = 0; j<n; j++)
	{   
		if (((col - j) < 0) || ((row + j) >= n)) { break; }  //down
		int placeCol = col - j; int placeRow = row+j;
		for (int resultArrI = 0; resultArrI < whichCol; resultArrI++)      //loop through the result array
		{
			int previousCol = arry[resultArrI] / n;
			int previousRow = arry[resultArrI] % n;    //get the previous array's col and row Index
			if ((previousCol == placeCol) && (previousRow == placeRow))return false;
		}
	}//print(arry, 2);  //k=2
	
	return true;
}
void move(int *result, int col, int blankNum, int k,unsigned int *&countP)  //16 as example    4x4
{
	int index;
	static int useless = 0;
	if (col == 0) {
		index = 0;
	}
	else {
		index = result[col - 1];
		index=index+1; //get to next pos
	}
	useless++;
	if (col == k) {//base case for recursion
		(*countP)++;
		return;
	}

	for (int Index=index; Index < blankNum; Index++)  //blankNum= n * n
	 {   
		result[col] = Index;
		//cout << "blanknun " << Index << endl;*/
		if (ok(result,Index,sqrt(blankNum),col))   //sqre(blankNum) get back the original n
		{
			move(result, col + 1, blankNum, k, countP);
		}
	}
}

int main()
{
	cout << "n           k                  number of bishops" << endl;
	for (int i = 1; i < 9; i++)
	{

		for (int j = 1; j <= i; j++)
		{
			int n, k;
			n = i; k = j;
			unsigned int count = 0;
			unsigned int *countP = &count;   //countP holding for how many result
									//n x n board,    k bitshop
									// 0  1  2   3 
									//0[0][4][8][12]
									//1[1][5][9][13]
									//2[2][6][10][14]
									//3[3][7][11][15]    in this mode

			int blankNum = n * n;  //4x4 ->15
			int *result = new int[k];
			for (int x = 0; x < k; x++)
			{
				result[x] = -1;  //initializing to all -1
			}

			move(result, 0, blankNum, k, countP);
			delete[]result;
			cout << n << "            " << k << "                " << *countP << endl;

		}cout << "____________________________________________" << endl;
	}//big for loop


	
    return 0;
}

