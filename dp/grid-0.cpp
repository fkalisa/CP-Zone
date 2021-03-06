#include <bits/stdc++.h>
using namespace std;

extern const int N = 10001;
extern const int M = 10001;


int matrix[N][M];
int dp[N][M];

int compute(int matrix[N][M], int i, int j, int n, int m) {

	if (i == n - 1 && j == m - 1)
	{
		return 1;
	}
	if (dp[i][j] != -1) {
		return dp[i][j];
	}

	int left = 0;
	if (i + 1 < n) {
		left = compute( matrix,  i + 1 ,  j,  n,  m);
	}
	int right = 0;
	if (j + 1 < m) {
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

	int n = 2;
	int m = 3;

	memset(matrix, 0, sizeof matrix);
	memset(dp, -1, sizeof dp);
	cout << compute(matrix, 0, 0, n, m);
	return 0;
}
