#include <bits/stdc++.h>
using namespace std;

#define int long long

vector<int> digit;

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

	digit = putIntoVector(r);
	int ans1 = countNumbersWithDigitOccuringKTimes(0, 0, 0, d, k);
	digit = putIntoVector(l - 1);
	int ans2 = countNumbersWithDigitOccuringKTimes(0, 0, 0, d, k);
	cout << ans1 - ans2;


}
