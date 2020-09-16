#include <bits/stdc++.h>
using namespace std;

/*

Lower case or upper case → p = 31
Lower case AND upper case → p = 53

*/

int computeHash(string s) {

	int mod = (int)1e9 + 7;
	int hash = 0;
	int p = 1;


	for (int i = 0; i < s.size(); ++i)
	{
		hash = (hash + ((s[i] - 'a' + 1) * p) % mod) % mod;
		p = ( p * 31) % mod;
	}

	return hash;
}


int main() {


	cout << "answer : " << computeHash("hello");
}