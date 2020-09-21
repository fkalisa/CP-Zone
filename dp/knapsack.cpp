#include <bits/stdc++.h>
using namespace std;
extern const int N = 1000000;
extern const int W = 1000000;

int dp[N + 1][15];

int getMaxValue(int values[], int weights[], int n, int maxWeight, int index) {

	if (index == n)
	{
		return 0;
	}

	if (dp[n][maxWeight] != -1)
	{
		return dp[n][maxWeight];
	}

	int maxi = INT_MIN;
	if (weights[index] <= maxWeight)
	{

		maxi =  values[index] + getMaxValue(values, weights, n, maxWeight - weights[index], index + 1);
	}
	return dp[n][maxWeight] = max (maxi, getMaxValue(values, weights, n, maxWeight, index + 1));
}

int main() {
#ifndef ONLINE_JUDGE

//for getting input from input.txt
	freopen("../../../env/input.txt", "r", stdin);

//for writting output to output.txt
	freopen("../../../env/output.txt", "w", stdout);
#endif
	/*

		https://atcoder.jp/contests/dp/tasks/dp_d

		input :

		3 8
		3 30
		4 50
		5 60

		output :

		90

	*/

	int n;
	cin >> n;

	int maxWeight;
	cin >> maxWeight;

	int values[n];
	int weights[n];

	for (int i = 0; i < n; ++i)
	{
		cin >> weights[i] >>  values[i];
	}
	memset(dp, -1, sizeof dp);

	cout << getMaxValue(values, weights, n, maxWeight, 0);

}