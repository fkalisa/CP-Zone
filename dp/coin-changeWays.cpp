#include <bits/stdc++.h>
using namespace std;

extern const int N = 10001;
extern const int M = 10001;

int compute(int arr[], int n, int i) {

	if (i == n - 1) {
		return 0;
	}


	int left = abs(arr[i] - arr[i + 1]) + compute(arr, n, i + 1);

	int right = 0;
	if (i + 2 < n)
	{
		right = abs(arr[i] - arr[i + 2]) + compute(arr, n, i + 2);
	}

	return min(left, right);

}


int main() {

#ifndef ONLINE_JUDGE

//for getting input from input.txt
	freopen("../../../env/input.txt", "r", stdin);

//for writting output to output.txt
	freopen("../../../env/output.txt", "w", stdout);
#endif

	int n;
	cin >> n;

	int arr[n];
	for (int i = 0; i < n; ++i)
	{
		cin >> arr[i];
	}

	cout << compute(arr, n, 0);


}