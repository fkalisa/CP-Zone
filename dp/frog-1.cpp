#include <bits/stdc++.h>
using namespace std;
extern const int N = 100000;

int dp[N + 1];
int compute(int arr[], int n, int index) {

	if (index == n - 1) {
		return 0;
	}

	if (dp[index] != -1)
	{
		return dp[index];
	}

	int left = abs(arr[index] - arr[index + 1]) + compute(arr, n, index + 1);
	int right = INT_MAX;
	if ( index + 2 < n)
	{
		right =  abs(arr[index] - arr[index + 2 ]) + compute(arr, n, index + 2);
	}

	return dp[index] = min(left, right);

}

int main() {
#ifndef ONLINE_JUDGE

//for getting input from input.txt
	freopen("../../../env/input.txt", "r", stdin);

//for writting output to output.txt
	freopen("../../../env/output.txt", "w", stdout);
#endif

	/*

	https://atcoder.jp/contests/dp/tasks/dp_a

	input :
	6
	30
	10
	60
	10
	60
	50

	output :

	40
	*/


	int n;
	cin >> n;
	memset(dp, -1, sizeof dp);

	int arr[n];

	for (int i = 0; i < n; ++i)
	{
		cin >> arr[i];
	}

	cout << "answer : " << compute(arr, n, 0);

	return 0;
}
