#include <bits/stdc++.h>
using namespace std;

#define int long long


vector<int> digit;

int dp[18][2];

vector<int> putIntoVector(int num) {

	vector<int> v;
	while (num) {

		int value = num % 10;
		v.push_back(value);
		num = num / 10;

	}
	reverse(v.begin(), v.end());

	return v;
}

int getSumOfNumbersUntilR( int index, bool flag, int sum) {

	if (digit.size() == index)
	{
		return sum;
	}
	if (dp[index][flag] != -1)
	{
		return dp[index][flag] ;
	}
	int limit;
	limit = digit[index];

	if (flag == 1)
	{	limit = 9;
	}

	int ans = 0;
	for (int i = 0; i <= limit; ++i)
	{

		if (i < digit[index])
		{
			ans += getSumOfNumbersUntilR(index + 1, 1,  sum + i);
		} else {
			ans +=  getSumOfNumbersUntilR(index + 1, flag,  sum + i);

		}

	}
	dp[index][flag] = ans;
	return ans;
}

signed main() {

#ifndef ONLINE_JUDGE

//for getting input from input.txt
	freopen("../../../env/input.txt", "r", stdin);

//for writting output to output.txt
	freopen("../../../env/output.txt", "w", stdout);
#endif

	/*

	Time complexity : 18*2
	Space complexity : 18*2


	9
	12

	output:

	9 + 1+0 + 1 + 1 + 1 +2 = 15

	*/

	int l, r;
	cin >> l >> r;
	//
	digit = putIntoVector(r);
	memset(dp, -1, sizeof(dp));
	int ans1 = getSumOfNumbersUntilR(0, 0, 0);
	//
	digit = putIntoVector(l - 1);
	memset(dp, -1, sizeof(dp));
	int ans2 = getSumOfNumbersUntilR(0, 0, 0);
	//
	cout << ans1 - ans2 << endl;
	//


}
