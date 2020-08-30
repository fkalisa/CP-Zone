#include <bits/stdc++.h>
using namespace std;


int power(int b, int power) {
	int result = 1;

	while (power != 0) {
		if (power % 2 == 0) {
			b =  b * b;
			power = power / 2;
		} else {

			result = result * b;
			power = power - 1;
		}
	}

	return result;
}

int main() {

	int b = 10;
	int p = 4;

	cout << "answer : " << power(b, p);
	return 0;
}