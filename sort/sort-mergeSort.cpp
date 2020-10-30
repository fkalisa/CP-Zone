#include <bits/stdc++.h>
using namespace std;


void merge(int arr [], int low, int high) {

	std::vector<int> v;
	int middle = low + (high - low) / 2;

	int i = low;
	int j = middle + 1;


	while (i <= middle && j <= high) {

		if (arr[i] <= arr[j]) {
			v.push_back(arr[i]);
			i++;
		} else {
			v.push_back(arr[j]);
			j++;
		}
	}


	while (i <= middle ) {
		v.push_back(arr[i]);
		i++;
	}

	while (j <= high) {
		v.push_back(arr[j]);
		j++;
	}



	for (int i = low; i <= high; ++i)
	{
		arr[i] = v[i - low];

	}

}

void mergeSort(int arr [], int low, int high ) {
	int middle = low + (high - low) / 2;

	if (low >= high) {
		return;
	}

	mergeSort(arr, low, middle );
	mergeSort(arr, middle + 1, high);
	merge(arr, low, high);
}


int main() {

	/*
		Time complexity O(Nlog(N))
		mergeSort : logN
		merge : N
		application :
			- sort
			- Inversion Count - https://www.spoj.com/problems/INVCNT/
			- Revrese pairs - https://leetcode.com/problems/reverse-pairs/solution/
		
	*/
	int arr [] = {7, 6, 4, 0, 9, 2, 1, 3, 8};
	int n = 8;
	mergeSort(arr, 0, n);

	for (auto it : arr)
	{
		cout << it << endl;
	}

	return 0;
}
