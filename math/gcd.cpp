#include <bits/stdc++.h>

using namespace std;

int main() {
#ifndef ONLINE_JUDGE

//for getting input from input.txt
	freopen("../../../env/input.txt", "r", stdin);

//for writting output to output.txt
	freopen("../../../env/output.txt", "w", stdout);
#endif


	int a = 27;
	int b = 15;


	while (a != 0 && b != 0) {
		if (a > b)
		{
			a = a - b;
		} else {
			b = b - a;
		}
	}

	if (a == 0) {
		cout << b << endl;
	} else {
		cout << a << endl;
	}


	return 0;
}