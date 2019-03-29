

#include "stdafx.h"
#include <iostream>
#include<vector>
using namespace std;
int main() {
	vector<int> t[3];
	int n, candidate, to, from, move = 0;
	cout << "Please enter an ODD number of rings to move: ";
	cin >> n;
	cout << endl;
	int cap = n + 1;
	for (int i = n + 1; i >= 1; i--)
		t[0].push_back(i);
	t[1].push_back(n + 1);
	t[2].push_back(n + 1);

	from = 0;
	if ((n % 2) == 1)
	{
		to = 1;

	}
	else {
		to = 2;
	}
	candidate = 1;

	while (t[1].size()<cap) {
		cout << "move number " << ++move << ": Transfer ring " << candidate <<
			" from tower " << char(from + 65) << " to tower " << char(to + 65) << endl;
		t[to].push_back(t[from].back());
		t[from].pop_back();

		if (t[(to + 1) % 3].back()<t[(to + 2) % 3].back())
		{
			from = (to + 1) % 3;
		}
		else
		{
			from = (to + 2) % 3;
		}


		if (((t[(from + 2) % 3].back() - t[from].back()) >= 1) && ((t[(from + 1) % 3].back() - t[from].back()) >= 1))  // when it has 2 options
		{
			if (n % 2 == 0)
			{
				to = (from + 2) % 3;
			}

		    else
		    {
			to = (from + 1) % 3;
		    }
		}
		if (!(((t[(from + 2) % 3].back() - t[from].back()) >= 1) && ((t[(from + 1) % 3].back() - t[from].back()) >= 1)))  // when it has only 1 option
		{
			if (t[(from + 1)% 3].back()>t[from].back())
			{
				to = (from + 1) % 3;
			}

			if(t[(from + 2) % 3].back()>t[from].back())
			{
				to = (from + 2) % 3;
			}
		}
		
		candidate = t[from].back();
	}
	return 0;
}


