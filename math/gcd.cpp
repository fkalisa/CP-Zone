#include <bits/stdc++.h>

using namespace std;


int gcd1(int a, int b) {

	while (a != 0 && b != 0) {
		if (a > b)
		{
			a = a % b;
		} else {
			b = b % a;
		}
	}

	return (a == 0) ? b : a;
}

// brute force
int gcd2(int a, int b) {

	int maxi = 1;

	for (int i = 1; i < min(a, b); ++i)
	{
		if (a % i == 0 && b % i == 0)
		{
			maxi = max(i, maxi);
		}
	}

	return maxi;
}


int gcd3(int a, int b)
{
	if (a == 0)
		return b;

	return gcd3(b % a, a);
}

int main() {
#ifndef ONLINE_JUDGE

//for getting input from input.txt
	freopen("../../../env/input.txt", "r", stdin);

//for writting output to output.txt
	freopen("../../../env/output.txt", "w", stdout);
#endif


	int a = 27;
	int b = 15;

	cout << gcd1(a, b) << endl;

	int c = 27;
	int d = 15;
	cout << gcd2(c, d) << endl;

	cout << gcd3(27, 15) << endl;

	return 0;
}