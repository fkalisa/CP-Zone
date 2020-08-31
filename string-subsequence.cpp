#include <bits/stdc++.h>
using namespace std;



void printSubsequences(string arr[], int n)
{

	/* 000 to 111 */
	for (int counter = 1; counter < (1 << n); counter++)
	{
		for (int j = 0; j < n; j++)
		{
			if (counter & (1 << j))
				cout << arr[j] << " ";
		}
		cout << endl;
	}
}

signed main() {

	/*
		Subsequence : number of operations 2^N
	*/

	string arr[] = {"A", "B", "C"};
	int n = 3;
	printSubsequences(arr, n);

	return 0;

}