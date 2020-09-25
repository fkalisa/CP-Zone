#include <bits/stdc++.h>
using namespace std;


//using recursion
void compute2(string s, int index, string current) {

	if (index == s.size())
	{
		cout << current << endl;
		return;
	}

	compute2( s,  index + 1,  current + s[index]) ;
	compute2( s,  index + 1,  current ) ;

}

// using bit masks
void compute1(string s) {
	int n = s.size();

	for (int i = 0; i < (1 << n); ++i)
	{
		int tmp = i;
		int counter = 0;
		while (tmp) {

			if (tmp & 1) {
				cout << s[counter];
			}
			counter++;
			tmp = tmp >> 1;

		}
		cout << endl;
	}
}


int main() {
#ifndef ONLINE_JUDGE

//for getting input from input.txt
	freopen("../../env/input.txt", "r", stdin);

//for writting output to output.txt
	freopen("../../env/output.txt", "w", stdout);
#endif



	string s = "ABC";


	compute2(s, 0, "");

	return 0;




}