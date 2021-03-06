// Stable marriage.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<iostream>;

using namespace std;
	


    

bool check(int woman[3],int col)   //   
{
	int preference = -1;
	int newerWomen = -1;
	int newWomenPartner = -1;
	int manP[3][3] = {//table, use for refernce and check
		{ 0,2,1 },
	    { 0,2,1 },
	    { 1,2,0 },
	                 };
	int womanP[3][3] = {// table, use for reference and check
		{ 2,1,0 },
	    { 0,1,2 },
	    { 2,0,1 },
	                   };
	preference = manP[col][woman[col]];

	for (int i = 0; i < col; i++)  //horizontal test, check if woman have already been assign
	{
		if (woman[col] == woman[i]) { return false; }
	}
	

	for (int j = 0; j < 3; j++) 
	{
		if (manP[col][j] < preference) // man 1  /  woman 0   2
		{
			newerWomen = j; // 
			// do woman check
			for (int manI = 0; manI < 3; manI++) 
			{
				if (woman[manI] == newerWomen) 
				{
					newWomenPartner = manI;

					if (womanP[newerWomen][newWomenPartner]>womanP[newerWomen][col])
					{
						return false;
					}
				}

			
			}
		
		}
		
	}
	// after all possible check
	return true;

}

void print(int woman[3])
{    
	int man[3] = { 0,1,2 };
	cout << "men          women" << endl;
	for (int i = 0; i < 3; i++) {
		cout << man[i] << "          ";
		cout << woman[i] << endl;
	}

}

int main()
{
	int man[3] = { 0,1,2 };
	int woman[3] = { -1 ,-1,-1};


	int count = 0;
	int tem = 100;
	int col = 0;
	woman[0] = 2;


	while (col>=0) {
	
		

		for (int row = 2; row >= 0; row--)
		{       
			// 2  1  0    
			// a very large tem for initialization
			if (tem == 0) {
				
				woman[col] = -1;
				col--;
				tem = woman[col];
				//cout << "break tem" << tem<<" col "<<col << endl;
				break;
			}

			if (row >= tem)  //   doing in backtrack
			{
				//cout << "continue" << endl;
				//cout << "row  " << row << "  tem" << tem << endl;
				continue; // next row
			}
			    tem = 100;
			    woman[col] = row;						
				//print(woman);

			if (check(woman, col))  //if success
			{
				//cout << "success ";// << col << endl;
				//tem = 100;
				//print(woman);
				col++; //cout << "after col++" << col << endl;
				
				if (col == 3) 
				{   //backtrack
					count++;
					print(woman);
					col--;
					tem = woman[col];
					break;
				}

			    break;    // break big for loop
			}
		
			if (row == 0)   // backtrack
			{
				//cout << "fail" << endl;
				woman[col] = -1;
				col--;
				tem = woman[col];
				//cout << "tem" << tem<<endl;
				break;
			}

		} //for


		
	          } // while



	cout << "program end" << endl;
	cout << count << " times" << endl;




	


    return 0;
}

