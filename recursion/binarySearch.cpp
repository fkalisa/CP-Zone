#include <bits/stdc++.h>

using namespace std;

int binarySearch(int arr[], int n, int value, int i, int j) {


	if (i > j) {
		return -1;
	}
	int middle = (i + j) / 2;

	if (arr[middle] == value)
	{
		return middle;
	}

	if (value < arr[middle]) {
		return binarySearch(arr, n, value, i, middle - 1);
	} else {
		return binarySearch(arr, n, value, middle + 1, j);
	}

}


int main() {
#ifndef ONLINE_JUDGE

//for getting input from input.txt
	freopen("../../../env/input.txt", "r", stdin);

//for writting output to output.txt
	freopen("../../../env/output.txt", "w", stdout);
#endif


	int arr[] = {1, 3, 5, 6, 7, 8, 10, 11};
	int n = 8;
	cout << binarySearch(arr, n, 10, 0, n - 1);

}