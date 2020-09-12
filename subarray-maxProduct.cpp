#include <bits/stdc++.h>
using namespace std;

/*
	Time complexity : O(N^3)
*/

void approach1(int arr[], int n) {

	int maxi = INT_MIN;
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			int product = 1;
			for (int k = i; k < j; ++k)
			{
				product *= arr[k];
			}
			maxi = max(maxi, product);
		}
	}

	cout << "answer1 : " << maxi << endl;
}

/*
	Time complexity : O(N^2)
*/
void approach2(int arr[], int n) {
	int maxi = INT_MIN;
	for (int i = 0; i < n; ++i)
	{

		int product = 1 ;

		for (int j = 0; j < n; ++j)
		{
			product *= arr[j];
			maxi = max(maxi, product);
		}
	}

	cout << "answer2 : " << maxi << endl;

}
/*
	Time complexity : O(N)
*/
void approach3(int arr[], int n) {

	if (n == 0 ) {
		return;
	}

	int max_so_far =  arr[0];
	int min_so_far = arr[0];
	int result = arr[0];

	for (int i = 1; i < n; ++i)
	{
		int current = arr[i];
		int tmp_max = max( max(current, min_so_far * current), current * max_so_far);
		min_so_far = min( min(current, min_so_far * current), current * max_so_far);


		max_so_far = tmp_max;
		result = max(max_so_far, result);

	}


	cout << "answer3 : " << result << endl;

}

int main() {

	int arr[] = { 2, -5, 3, 1, -4, 0, -10, 2, 8};
	int n = 9;
	approach1(arr, n);
	approach2(arr, n);
	approach3(arr, n);
	return 0;
}