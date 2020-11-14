#include <bits/stdc++.h>
using namespace std;

#define int long long

int countBruteForce(int d, int k, int l, int r) {

	int ans = 0;
	for (int i = l; i <= r; ++i)
	{


		int tmp = i;
		int counter = 0;

		while (tmp) {
			int value = tmp % 10;
			if (value == d)
			{
				counter++;
			}
			tmp = tmp / 10;
		}

		if (counter == k)
		{
			ans++;
		}

	}
	return ans;
}

vector<int> digit;

int dp[18][2][18];

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

int countNumbersWithDigitOccuringKTimes( int index, bool flag, int counter, int d, int k) {

	if (digit.size() == index)
	{
		if (counter == k)
		{
			return 1;
		}
		return 0;
	}
	if (dp[index][flag][counter] != -1)
	{
		return dp[index][flag][counter] ;
	}
	int limit;
	limit = digit[index];
	if (flag == 1)
	{
		limit = 9;
	}

	int ans = 0;
	for (int i = 0; i <= limit; ++i)
	{
		if (i < digit[index])
		{
			if (i == d)
			{
				ans += countNumbersWithDigitOccuringKTimes(index + 1, 1, counter + 1, d, k);
			} else {
				ans += countNumbersWithDigitOccuringKTimes(index + 1, 1, counter, d, k);

			}


		} else {
			if (i == d)
			{
				ans += countNumbersWithDigitOccuringKTimes(index + 1, flag, counter + 1, d, k);
			} else {
				ans += countNumbersWithDigitOccuringKTimes(index + 1, flag, counter, d, k);

			}
		}
	}
	dp[index][flag][counter] = ans;
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

	Time complexity : 18*2*18
	Space complexity : 18*2*18

	d = 2
	k = 1

	Count number between l and r whose d is contained kth times

	input:

	3
	25
	1
	2

	output:

	12 20 21 23 24 26 -> 6

	*/

	int l, r, k, d;
	cin >> l >> r >> k >> d;
	//
	digit = putIntoVector(r);
	memset(dp, -1, sizeof(dp));
	int ans1 = countNumbersWithDigitOccuringKTimes(0, 0, 0, d, k);
	//
	digit = putIntoVector(l - 1);
	memset(dp, -1, sizeof(dp));
	int ans2 = countNumbersWithDigitOccuringKTimes(0, 0, 0, d, k);

	//
	cout << ans1 - ans2 << endl;
	//
	cout << countBruteForce( d,  k,  l,  r) << endl;


}
