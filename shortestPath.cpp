// shortestPath.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"


#include<iostream>
using namespace std;
const int rows = 5;
const int cols = 6;
int trace[rows][cols] =
{ //pass to the array and update it     EX. row0 means the path of col:5, row:0
{ -1,-1,-1,-1,-1,-1 },
{ -1,-1,-1,-1,-1,-1},
{ -1,-1,-1,-1,-1,-1},
{ -1,-1,-1,-1,-1,-1 },
{ -1,-1,-1,-1,-1,-1 }
};

int cost(int i, int j) { // i is the row, j is the column
	int minIndex;
	static int weight[rows][cols] = {  //012334
		{ 3,4,1,2,8,6 },
	    { 6,1,8,2,7,4 },
	    { 5,9,3,9,9,5 },
	    { 8,4,1,3,2,6 },
	    { 3,7,2,8,6,4 } 
	                                 };

	//base case
	if (j == 0)
	{
		return weight[i][0];
	}
	
	int upIndex = (i - 1) % 5;

	if (upIndex < 0) {  //negative is possible
		upIndex += 5;
	}

	int left =cost(i,j-1) ;                 //same row
	int up =cost(upIndex,j-1) ;             // one row up
	int down =cost(((i + 1) % 5),j-1) ;     // one row down


	//find the min by comparing these 3
	int min = left;
	minIndex = i;

	if (up < min) {
		min = up;
		minIndex = upIndex;
	              }

	if (down < min) {
		min = down; 
		minIndex = (i + 1) % 5;
	                 }

	 trace[i][j] = minIndex;

	min =min+weight[i][j];

		return min;
}

int main() {
	int pathArray[5];
	int minIndex = 0;
	int traceIndex;
	int traceArray[6];
	for (int i = 0; i < rows; i++)
	{
		pathArray[i] = cost(i, cols - 1);
	}
	int min = pathArray[0];  
	
	for (int i = 1; i < rows; i++) {
		if (pathArray[i] < min) {
			min = pathArray[i];
			minIndex = i;
		}
	}
	
	
	cout << "the shortest path is of length " << min << endl << endl;
	cout << "the path is  ";
	traceIndex = minIndex;
	for (int c=5;c>0;c--)
	{
		traceArray[c - 1] = trace[traceIndex][c];
		traceIndex= trace[traceIndex][c];
	}
	for (int j = 0; j < 5; j++) {
		cout << traceArray[j] << " ";
	}cout << minIndex;
	cout << endl;
	return 0;

}