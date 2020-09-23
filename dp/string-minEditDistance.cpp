#include <bits/stdc++.h>
using namespace std;

extern const int R = 1001;
extern const int C = 1001;

int dp[R][C];

int editDistance(string s1, string s2, int i, int j) {


	if (i == s1.size())
	{
		return s2.size() - j;
	}
	if (j == s2.size())
	{
		return s1.size() - i;
	}

	if (dp[i][j] != -1)
	{
		return dp[i][j];
	}
	if (s1[i] == s2[j] )
	{
		return editDistance(s1, s2, i + 1, j + 1);
	}
	int ins = 0;
	if (j + 1 < s2.size()) {
		ins = 1 + editDistance(s1, s2, i , j + 1);
	}


	int rep = 0;
	if (i + 1 < s1.size() && j + 1 < s2.size()) {
		rep = 1 + editDistance(s1, s2, i + 1, j + 1);
	}

	int del = 0;
	if (i + 1 < s2.size()) {
		del = 1 + editDistance(s1, s2, i + 1 , j );

	}

	return dp[i][j] = min(ins, min(rep, del));


}

int main() {

#ifndef ONLINE_JUDGE

//for getting input from input.txt
	freopen("../../../env/input.txt", "r", stdin);

//for writting output to output.txt
	freopen("../../../env/output.txt", "w", stdout);
#endif


	string s1, s2;
	cin >> s1 >> s2;

	memset(dp, -1, sizeof dp);
	cout << editDistance(s1, s2, 0, 0);

	return 0;
}