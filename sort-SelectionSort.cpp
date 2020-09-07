#include <bits/stdc++.h>
using namespace std;

void swap(int arr[], int i, int j ) {
	int tmp = arr[i];
	arr[i] =  arr[j];
	arr[j] = tmp;
}

void sort(int arr[], int n) {

	for (int i = 0; i < n; ++i)
	{
		int index = i;
		for (int j = i + 1; j < n; ++j)
		{
			if (arr[j] < arr[index]) {
				index = j;
			}
		}
		swap(arr, i, index);
	}

	for (int i = 0; i < n; ++i)
	{
		cout << arr[i] << " ";
	}
}





int main() {

	/*
		Time complexity O(N*N)
	*/

	int arr[] = {1, 9, 0, 3, 4, 7, 8, 6};
	int n = 8;

	sort( arr, n);
	return 0;
}