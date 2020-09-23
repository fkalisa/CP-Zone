#include <bits/stdc++.h>
using namespace std;

int compute(int arr[], int n, int i) {


	if (i == n - 1) {
		return 1;
	}

	int left = 0;

	if (arr[i] < arr[i + 1])
	{
		left =  1 + compute( arr,  n,  i + 1);
	}

	int right = compute( arr,  n,  i + 1);

	return max(left, right);
}

int main() {

#ifndef ONLINE_JUDGE

//for getting input from input.txt
	freopen("../../../env/input.txt", "r", stdin);

//for writting output to output.txt
	freopen("../../../env/output.txt", "w", stdout);
#endif

	/*
	input :
	9
	19 22 9 33 21 50 41 60 80

	output :

	6
	*/

	int n;
	cin >> n;
	int arr[n];
	for (int i = 0; i < n; ++i)
	{
		cin >> arr[i];
	}

	cout << compute(arr, n, 0);


	return 0;
}