#include <bits/stdc++.h>
using namespace std;

#define int long long

extern const int N = 1000000;

int getMinCoinChange(int arr[], int n, int amount) {
	if (amount == 0)
	{
		return 0;
	}


	int mini = INT_MAX;

	for (int i = 0; i < n; ++i)
	{
		if ( arr[i] <= amount)
		{
			mini = min(mini, 1 + getMinCoinChange(arr, n, amount - arr[i]));
		}

	}
	return mini;

}

int getMinCoinChange2(int arr[], int n, int i, int amount) {
	if (i == n)
	{
		if (amount == 0)
		{
			return 0;
		}
		return INT_MAX;
	}

	int left = INT_MAX;

	if (amount >= arr[i])
	{
		left = 1 + getMinCoinChange2(arr, n, i,  amount - arr[i]);
	}
	int right = getMinCoinChange2(arr, n, i + 1,  amount);

	return min(left, right);

}




signed main() {

#ifndef ONLINE_JUDGE

//for getting input from input.txt
	freopen("../../../env/input.txt", "r", stdin);

//for writting output to output.txt
	freopen("../../../env/output.txt", "w", stdout);
#endif

	/*

		example 1:

		10
		3
		1 3 4

		output :

		example 2

		10
		4
		7 5 4 1

	*/


	int amount;
	cin >> amount;
	int n;
	cin >> n;

	int arr[n];
	for (int i = 0; i < n; ++i)
	{
		cin >> arr[i];
	}

	int dp[amount + 1][n + 1];
	memset(dp, -1, sizeof dp);

	cout << getMinCoinChange(arr, n, amount) << endl;
	cout << getMinCoinChange2(arr, n, 0, amount) << endl;
}
