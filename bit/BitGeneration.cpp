#include <bits/stdc++.h>
using namespace std;


int main() {

#ifndef ONLINE_JUDGE

//for getting input from input.txt
	freopen("../../../env/input.txt", "r", stdin);

//for writting output to output.txt
	freopen("../../../env/output.txt", "w", stdout);
#endif


	int n = 3;
	int size = 1 << n;


	std::vector<int> v(n);

	for (int i = 0; i < size; ++i)
	{
		int tmp = i;
		int counter = 0;
		while (tmp) {

			v[counter] = (tmp & 1) ;

			tmp = tmp >> 1;
			counter++;

		}

		for (auto it : v)
		{
			cout << it;
		}
		cout << endl;
	}
}