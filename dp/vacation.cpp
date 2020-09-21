
#include <bits/stdc++.h>
using namespace std;
extern const int N = 100000;

int dp[N + 1][4];

int getMaxHapiness(int a[], int b[], int c[], int n, int i, int task) {

	if (i == n)
	{
		return 0;
	}

	if (dp[i][task] != -1)
	{
		return dp[i][task];
	}

	if (task == 0)
	{

		int a1 = a[i] + getMaxHapiness(a, b, c,  n, i + 1,  1);
		int b1 = b[i] + getMaxHapiness(a, b, c,  n, i + 1,  2);
		int c1 = c[i] + getMaxHapiness(a, b, c,  n, i + 1,  3);

		return dp[i][task] = max(c1, max(a1, b1));
	} else if (task == 1) {

		int b1 = b[i] + getMaxHapiness(a, b, c,  n, i + 1,  2);
		int c1 = c[i] + getMaxHapiness(a, b, c,  n, i + 1,  3);

		return dp[i][task] = max(b1, c1);

	} else if (task == 2) {

		int a1 = a[i] + getMaxHapiness(a, b, c,  n, i + 1,  1);
		int c1 = c[i] + getMaxHapiness(a, b, c,  n, i + 1,  3);
		return dp[i][task] = max(a1, c1);

	} else {
		int a1 = a[i] + getMaxHapiness(a, b, c,  n, i + 1,  1);
		int b1 = b[i] + getMaxHapiness(a, b, c,  n, i + 1,  2);

		return dp[i][task] = max(a1, b1);

	}
}


int main() {
#ifndef ONLINE_JUDGE

//for getting input from input.txt
	freopen("../../../env/input.txt", "r", stdin);

//for writting output to output.txt
	freopen("../../../env/output.txt", "w", stdout);
#endif

	/*

	input :

		https://atcoder.jp/contests/dp/tasks/dp_c

		3
		10 40 70
		20 50 80
		30 60 90

	output :

		210
	*/

	int n;
	cin >> n;

	int a[n];
	int b[n];
	int c[n];


	for (int i = 0; i < n; i++)
		cin >> a[i] >> b[i] >> c[i];

	memset(dp, -1, sizeof dp);

	cout << getMaxHapiness(a, b, c, n, 0, 0);


	return 0;
}