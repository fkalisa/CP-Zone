#include <bits/stdc++.h>
using namespace std;


void swap(int arr[], int i, int j ) {
	int tmp = arr[i];
	arr[i] =  arr[j];
	arr[j] = tmp;
}

void sort(int arr[], int n) {

	int j = 0;
	while (j < n) {
		int i = j;
		while (i > 0) {
			if (arr[i - 1] > arr[i]) {
				swap(arr, i, i - 1);
			}
			i--;
		}
		j++;
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