#include <bits/stdc++.h>
using namespace std;


int main() {

#ifndef ONLINE_JUDGE

//for getting input from input.txt
	freopen("../../../env/input.txt", "r", stdin);

//for writting output to output.txt
	freopen("../../../env/output.txt", "w", stdout);
#endif

	/*
		Time complexity : O(N*2^N)
	*/

	int n = 3;
	int size = 1 << n;

	for (int i = 0; i < size; ++i) //N
	{

		for (int j = 0; j < n; ++j) // 2^N
		{
			if (i & (1 < j))
			{
				cout << 1;
			} else {
				cout << 0;
			}
		}
		cout << endl;
	}
}