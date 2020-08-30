#include <bits/stdc++.h>
using namespace std;

extern const int N = 1e5;
int prime[N];

/*
Sieve of Ératosthène - find if a number is a prime number or not
*/

void sieve() {
	prime[1] = 0;
	for (int i = 2; i < N; ++i)
	{
		prime[i] = 1;
	}

	for (int i = 2; i * i < N; ++i)
	{
		if (prime[i] == 1) {
			for (int j = i * i; j < N; j = j + i)
			{
				prime[j] = 0;
			}
		}
	}
}


int main() {

	sieve();

	cout << "27 is prime : " << prime[27] << endl;
	cout << "13 is prime : " << prime[13] << endl;

	return 0;
}