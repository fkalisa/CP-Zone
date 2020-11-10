#include <bits/stdc++.h>
using namespace std;

#define int long long


double compute(double arr[], int n, int index, int count) {

	if (index == n)
	{
		if (count > n - count)
		{
			return 1;
		}
		return 0;
	}


	double left = arr[index] * compute( arr,  n,  index + 1, count + 1);
	double right = (1.0 - arr[index]) * compute( arr,  n,  index + 1, count);

	return left + right;
}

signed main() {

#ifndef ONLINE_JUDGE

//for getting input from input.txt
	freopen("../../../env/input.txt", "r", stdin);

//for writting output to output.txt
	freopen("../../../env/output.txt", "w", stdout);
#endif

	/*
	Print the probability of having more heads than tails

	input :
	3
	0.30 0.60 0.80


	*/

	int n;
	cin >> n;

	double arr[n];

	for (int i = 0; i < n; ++i)
	{
		cin >> arr[i];
	}
	cout << compute(arr, n, 0, 0);
}
