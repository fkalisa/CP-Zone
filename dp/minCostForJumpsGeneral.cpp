#include <bits/stdc++.h>
using namespace std;
extern const int N = 100000;

int dp[N + 1];
int compute(int arr[], int n, int index, int k) {

	if (index == n - 1) {
		return 0;
	}

	if (dp[index] != -1)
	{
		return dp[index];
	}
	int mini = INT_MAX;
	for (int i = 1; i <= k; ++i)
	{
		if (index + i <= n - 1) {
			mini = min(mini, abs(arr[index] - arr[index + i]) + compute(arr, n, index + i, k));
		}
		else {
			break;
		}
	}



	return dp[index] = mini;

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
	4
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
	int k;
	cin >> k;
	memset(dp, -1, sizeof dp);

	int arr[n];

	for (int i = 0; i < n; ++i)
	{
		cin >> arr[i];
	}

	cout << "answer : " << compute(arr, n, 0, k);

	return 0;
}
