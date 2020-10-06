#include <bits/stdc++.h>

using namespace std;

long long power(int b, int p, long long mod) {

	if (p == 0) {
		return 1;
	}

	if (p % 2 == 2) {
		return power((b * b) % mod, p / 2, mod);
	} else {
		return (b * power(b, p - 1, mod)) % mod;
	}
}


int main() {
#ifndef ONLINE_JUDGE

//for getting input from input.txt
	freopen("../../../env/input.txt", "r", stdin);

//for writting output to output.txt
	freopen("../../../env/output.txt", "w", stdout);
#endif

	int b = 5;
	int p = 15;

	cout <<  power(b, p, 1e9 + 7);
}