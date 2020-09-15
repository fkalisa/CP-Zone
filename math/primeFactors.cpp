#include <bits/stdc++.h>
using namespace std;

void primeFactors(int n) {

	for (int i = 2; i * i <= n; ++i)
	{
		while (n % i == 0) {
			cout << i << " ";
			n = n / i;
		}

	}
	cout << n << endl;
}


int main() {
	primeFactors(125);
	return 0;
}
