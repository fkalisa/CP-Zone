#include <bits/stdc++.h>
using namespace std;


void compute(int arr[], int n) {

	if (n == 0) {
		return;
	}

	int max_current = arr[0];
	int max_global = arr[0];

	for (int i = 1; i < n; ++i)
	{
		max_current = max(arr[i], max_current + arr[i]);

		if (max_current > max_global)
		{
			max_global = max_current;
		}
	}
	cout << "answer : " << max_global;
}


int main() {

	int arr[] = { -2, 3, 2, -1};
	int n = 4;
	compute(arr, n);

	return 0;
}