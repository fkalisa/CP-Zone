#include <bits/stdc++.h>
using namespace std;


int kThGreaterElement(int arr[], int n, int k) {
	/*
		By default priority queue is maximum priority queue --> priority_queue<int, std::vector<int>>
		Known as minimum priority queue --> q : 1, 2, 3, 4
		The counter part (maximum pririty queue) is with less <int> --> : q : 4, 3, 2, 1
	*/
	priority_queue<int, std::vector<int>, greater<int>> q;

	for (int i = 0; i < n; ++i)
	{
		if (q.size() >= k) {
			q.pop();
		}
		q.push(arr[i]);
	}


	return q.top();
}


int main() {
	int arr[] = {2, 1, 5, 3, 6, 4, 8, 9, 7, 10};
	int n = 10;

	cout << "answer : " << kThGreaterElement(arr, n, 4);
}
