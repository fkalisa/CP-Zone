#include <bits/stdc++.h>

using namespace std;

extern const int N = 10000;
int arr[N + 1];
int seg[  4 * N + 5];

/*
Time complexity O(4*n)
*/
void build(int ind, int low, int high) {

	if (low == high)
	{
		seg[ind] = arr[low];
		return;

	}
	int middle = (low + high) / 2;
	build( ind * 2 + 1,  low,  middle);
	build( ind * 2 + 2,   middle + 1, high);

	seg[ind] = max(seg[ind * 2 + 1], seg[ind * 2 + 2]);

}

/*
	Time complexity : log(N)
*/
int query(int ind, int low, int high, int l, int r) {

	// inside - l low high r

	if (low >= l && high <= r) {
		return seg[ind];

	}


	// outside - 2 use cases
	// low high l r , l r low high

	if (high < l || low > r) {
		return INT_MIN;
	}

	int middle = (low + high) / 2;
	// overlapping

	int left = query(2 * ind + 1, low, middle, l, r);
	int right = query(2 * ind + 2, middle + 1, high , l, r);
	return max(left, right);
}

/*
	Time complexity : log(N)
*/

void update(int ind, int value, int i, int low, int high)
{
	if (high == low)
	{
		seg[ind] = value;
		arr[i] = value;
		return;
	}
	int middle = (high + low) / 2;
	if (i <= middle) {
		update( ind * 2 + 1,  value, i, low,  middle);
	} else {
		update( ind * 2 + 2,  value, i, middle + 1,  high);
	}

	seg[ind] = max(seg[ind * 2 + 1], seg[ind * 2 + 2] );
}

/*
	completely lies (included)(return nodes)
	does not lie (no overlapping) : INT_MIN
	partially lies(overlapping) : left, max

*/
int main() {
#ifndef ONLINE_JUDGE

//for getting input from input.txt
	freopen("../../../env/input.txt", "r", stdin);

//for writting output to output.txt
	freopen("../../../env/output.txt", "w", stdout);
#endif

	/*
		input

		8
		2 5 6 1 0 2 1 7
		1 6

		output

		6
	*/

	int n;
	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		cin >> arr[i];
	}

	int l, r;
	cin >> l >> r;

	build(0, 0, n - 1);

	cout << query(0, 0, n - 1, l - 1, r - 1) << endl;

	update(0, 11, 4, 0, n - 1);

	cout << query(0, 0, n - 1, l - 1, r - 1) << endl;

	return 0;
}