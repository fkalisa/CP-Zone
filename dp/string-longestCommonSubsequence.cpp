#include <bits/stdc++.h>
using namespace std;

extern const int r = 10001;
extern const int c = 10001;

int dp[r][c];


int compute(string s1, string s2, int i, int j, int dp[r][c]) {

	if (i == s1.size() || j == s2.size())
	{
		return 0;
	}

	if (dp[i][j] != -1)
	{
		return dp[i][j];
	}

	if (s1[i] == s2[j]) {
		return dp[i][j] = 1 + compute(s1, s2, i + 1, j + 1, dp);
	}



	int left =  compute(s1, s2, i + 1, j, dp);
	int  right = compute(s1, s2, i , j + 1, dp);

	return dp[i][j] = max(left, right);

}

int main() {

#ifndef ONLINE_JUDGE

//for getting input from input.txt
	freopen("../../../env/input.txt", "r", stdin);

//for writting output to output.txt
	freopen("../../../env/output.txt", "w", stdout);
#endif
	/*

		LCS : Longest Common Subsequence

		example :

		input :

		ABCDGH
		AEDFHR

		output :

		ADH

		How : 2 pointers

	*/



	string s1, s2;
	cin >> s1 >> s2;

	memset(dp, -1, sizeof dp);

	cout << compute(s1, s2, 0, 0, dp);

	return 0;


}