#include <bits/stdc++.h>

using namespace std;


void gcd1(int a, int b) {

	while (a != 0 && b != 0) {
		if (a > b)
		{
			a = a % b;
		} else {
			b = b % a;
		}
	}

	if (a == 0) {
		cout << b << endl;
	} else {
		cout << a << endl;
	}
}

// brute force
void gcd2(int a, int b) {

	int maxi = 1;

	for (int i = 1; i < min(a, b); ++i)
	{
		if (a % i == 0 && b % i == 0)
		{
			maxi = max(i, maxi);
		}
	}
	cout << maxi << endl;

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

	gcd1(a, b);

	int c = 27;
	int d = 15;
	gcd2(c, d);


	return 0;
}