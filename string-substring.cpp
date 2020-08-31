#include <bits/stdc++.h>
using namespace std;




void printSubstring(string arr[], int n) {


	for (int i = 0; i < n; ++i)
	{
		for (int j = i; j < n; ++j)
		{
			for (int k = i; k <= j; k++) {
				cout << arr[k] ;
			}
			cout << endl;
		}
	}
}




signed main() {

	cout << "Nemo " << endl;
	string arr[] = {"A", "B", "C"};
	int n = 3;
	printSubstring(arr, n);


	return 0;

}