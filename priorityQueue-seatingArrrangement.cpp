#include <bits/stdc++.h>
using namespace std;


int main() {


	/*

	https://www.hackerearth.com/practice/data-structures/trees/heapspriority-queues/practice-problems/algorithm/seating-arrangement-6b8562ad/
	Example :
	5 3
	RLR
	5
	1
	2
	3
	4
	5

	*/

	int n = 5;
	int people = 3;
	int chair[n];
	memset(chair, -1, sizeof(chair));

	string s = "RLR" ;
	priority_queue<pair<int, int>> q;
	q.push({n, -1});

	for (int i = 1; i <= people; i++) {
		auto it = q.top();
		q.pop();

		int len = it.first;
		int start = -1 * it.second;
		int end = start + len - 1;
		//odd
		if (len % 2) {
			int middle = end - start;
			chair[middle] = i;

			if (middle > start) {
				q.push({middle - start, -1 * start});
			} else if (middle < end) {
				q.push({end - middle, -1 * (middle + 1)});
			}
		} else {
			int leftmid = (start + end) / 2;
			int rightmid = leftmid + 1;

			if (s[i - 1] == 'L') {
				chair[leftmid] = i;
				if (leftmid > start) {
					q.push({leftmid - start, -1 * start});
				}
				if (leftmid < end) {
					q.push({end - leftmid, -1 * (leftmid + 1)});
				}
			}
			else {
				chair[rightmid] = i;
				if (rightmid > start) {
					q.push({rightmid - start, -1 * start});
				}
				if (rightmid < end) {
					q.push({end - rightmid, -1 * (rightmid + 1)});
				}
			}

		}


	}

	for (int i = 0; i < n + 1; ++i)
	{
		cout << chair[i] << endl;
	}
	return 0;


}