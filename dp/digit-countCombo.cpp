#include <bits/stdc++.h>
using namespace std;

int dp[18][2][18];


int countCombo(string value,  int k, int d, int index, int flag, int count ) {

	if (index == value.size())
	{
		if (count == k)
		{
			return 1;
		}
		return 0;
	}

	int ans = 0;
	if (flag == 0)
	{
		int dig = value[index] - '0';
		for (int i = 0; i <= dig; ++i)
		{
			if (i < dig)
			{
				if (d == i)
				{
					ans  = ans + countCombo( value,   k,  d,  index + 1, 1,  count + 1);
				} else {
					ans  = ans + countCombo( value,   k,  d,  index + 1, 1,  count);

				}

			} else {
				if (d == i)
				{
					ans  = ans + countCombo( value,   k,  d,  index + 1, 0,  count + 1);

				} else {
					ans  = ans + countCombo( value,   k,  d,  index + 1, 0,  count);
				}
			}
		}
		return ans;

	} else {

		for (int i = 0; i <= 9; ++i)
		{
			if (i == d)
			{
				ans = ans + countCombo(value, k, d, index + 1,  1, count + 1);
			} else {
				ans = ans + countCombo(value, k, d, index + 1, 1, count);

			}


		}

	}
	return dp[index][flag][count] = ans;

}


int main() {

#ifndef ONLINE_JUDGE

//for getting input from input.txt
	freopen("../../../env/input.txt", "r", stdin);

//for writting output to output.txt
	freopen("../../../env/output.txt", "w", stdout);
#endif

	/*

		Time complexity : O(18*2*18)

		input :
		7 22 2 1

		output :
		3

	*/

	int l, r, d, k;

	cin >> l >> r >> d >> k;

	string s1 = to_string(l - 1);
	string s2 = to_string(r);

	int count1 = countCombo(  s1,   k,  d,  0,  0, 0 );
	int count2 = countCombo(  s2,   k,  d,  0,  0, 0 );

	for (int i = 0; i < 18; ++i)
	{
		for (int j = 0; j < 2; ++j)
		{
			for (int k = 0; k < 18; ++k)
			{
				dp[i][j][k] = -1;
			}
		}
	}

	cout << "answer : " << count2 - count1;

}