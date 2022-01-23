#include <bits/stdc++.h>

using namespace std;


int main() {
#ifndef ONLINE_JUDGE

//for getting input from input.txt
	freopen("../../../env/input.txt", "r", stdin);

//for writting output to output.txt
	freopen("../../../env/output.txt", "w", stdout);
#endif

	int n = 16;
	int k = 4;


	for (int i = 1; i <= 16; ++i) {
		int result = -1 ;

		if (i % k == 0) {
			result = n;
		} else if ((i % k) == k - 1) {
			result = 0;
		} else if (i % k == 1) {
			result = 1;
		} else if (i % k == 2) {
			result = n + 1;
		}

		cout << i << " ^ " << k << " = " << result << endl;;
	}

	return 0;
}