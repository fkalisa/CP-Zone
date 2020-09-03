#include <bits/stdc++.h>
using namespace std;


void prefix(int lsb [], string s, int n) {
	int i = 1;
	int len = 0;

	while (i < n) {

		if (s[i] == s[len]) {
			lsb[i] = len + 1;
			len++;
			i++;
		} else {

			if (len != 0) {
				len = lsb[len - 1];

			} else {
				lsb[i] = 0;
				i++;
			}
		}
	}

	for (int i = 0; i < n; ++i)
	{
		cout << s[i] << " ";
	}
	cout << endl;
	for (int i = 0; i < n; ++i)
	{
		cout << lsb[i] << " ";
	}
	cout << endl;
}

int main() {

	string s = "abcdabca";
	int n = s.size();

	int lsb [n];
	memset(lsb, 0, sizeof(lsb));
	prefix(lsb, s, n);


}
