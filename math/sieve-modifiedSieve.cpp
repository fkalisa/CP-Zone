#include <bits/stdc++.h>
using namespace std;

extern const int N = 10000001;
int prime[N];


/*
	Modified Sieve  - find prime factors of a number
*/

void modifiedSieve() {

	prime[1] = 0;


	for (int i = 2; i < N; ++i)
	{
		prime[i] = i;
	}

	for (int i = 2; i * i < N; ++i)
	{
		if (prime[i] == i ) {
			for (int j = i * i; j < N; j = j + i)
			{

				if (prime[j] == j)
				{
					prime[j] = i;
				}

			}
		}
	}

}


int main() {

	modifiedSieve();

	for (int i = 0; i < 20; ++i)
	{
		cout << prime[i] << " ";
	}

	return 0;
}
