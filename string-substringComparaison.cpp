#include <bits/stdc++.h>
using namespace std;

#define int long long

extern const int mod = 1e9 + 7;

int  power(int  b, int  p, int mod) {

	int res = 1;

	while (p != 0) {
		if (p % 2 == 0) {
			b = (b * b) % mod;
			p = p / 2;
		} else {
			res = (b * res) % mod;
			p = p - 1;
		}
	}
	return res;
}

int moduloInverse(int n)
{
	return power(n, mod - 2, mod);
}

signed main() {

	string s = "addressdre";

	int n = s.size();


	int prime[n];
	int preHash[n];
	int modInv[n];

	int hash = 0;
	int p = 1;

	for (int i = 0; i < n; ++i)
	{
		hash = (hash + ((s[i] - 'a' + 1) * p) % mod) % mod;
		prime[i] = p;
		preHash[i] = hash;
		modInv[i] = moduloInverse(prime[i]);
		p = ( p * 31) % mod;
	}

	int i = 2;
	int j = 4;

	int hash1 =  preHash[j];
	if (i > 0) {
		hash1  = (hash1  - preHash[i - 1] + mod) % mod;
		hash1 =  (hash1 *  modInv[i]) % mod;
	}


	int k = 7;
	int t = 9;
	int hash2 = preHash[t];
	if (k > 0) {
		hash2 = (hash2 - preHash[k - 1] + mod) % mod;
		hash2 = (hash2 * modInv[k]) % mod;
	}

	cout << "answer : " << hash1 << " , " << hash2 <<   "  : " <<  (hash1  == hash2) << endl;

	return 0;

}