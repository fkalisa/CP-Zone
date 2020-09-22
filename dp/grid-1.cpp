#include <bits/stdc++.h>
using namespace std;


extern const int N = 10001;
extern const int M = 10001;

char matrix [N][M];
int dp[N][M];


int compute(char matrix[N][M], int i, int j, int n, int m) {
	if (i == n - 1 && j == m - 1)
	{
		return 1;
	}

	if (dp[i][j] != -1) {
		return dp[i][j];
	}
	int left = 0;
	int right = 0;

	if (i + 1 < n && matrix[i + 1][j] == '.') {
		left = compute( matrix,  i + 1 ,  j,  n,  m);
	}
	if (j + 1 < m && matrix[i][j + 1] == '.') {
		right = compute( matrix,  i ,  j + 1,  n,  m);
	}


	return dp[i][j] = left + right;
}

int main() {

#ifndef ONLINE_JUDGE

//for getting input from input.txt
	freopen("../../../env/input.txt", "r", stdin);

//for writting output to output.txt
	freopen("../../../env/output.txt", "w", stdout);
#endif

	/*
		https://atcoder.jp/contests/dp/tasks/dp_h

		input :

		3 4
		...#
		.#..
		....

		output :


	*/


	int n, m;
	cin >> n >> m;
	string s;

	for (int i = 0; i < n; ++i)
	{
		cin >> s;

		for (int j = 0; j < m; ++j)
		{
			matrix[i][j] = s.at(j);
		}

	}
	memset(dp, -1, sizeof dp);
	cout << compute(matrix, 0, 0, n, m);
	return 0;
}