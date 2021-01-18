#include <bits/stdc++.h>

using namespace std;

#define int long long

int fen[10000007];
int arr[10000007];


/*
	time complexity for update : logN
*/

void update(int index, int value, int n) {


	while (index <= n) {
		fen[index] = fen[index]  + value;
		index =  index + (index & -index);

	}
}

/*
	time complexity for sum : logN
*/

int sum (int index) {

	int sum = 0;

	while (index >= 1) {
		sum = sum + fen[index];
		index = index - (index & -index);
	}

	return sum;
}

signed main() {
#ifndef ONLINE_JUDGE

//for getting input from input.txt
	freopen("../../../env/input.txt", "r", stdin);

//for writting output to output.txt
	freopen("../../../env/output.txt", "w", stdout);
#endif

	/*
	with fenwickTree application : max range with update
	fenwickTree compared to segment tree, it is better in term of space complexity
	with fenwickTree, index start with 1
	in CP, tree are represented by an array


	inputs:
	16
	1 0 2 1 1 3 0 4 2 5 2 2 3 1 0 2
	3
	1 4
	1 16
	3 7

	outputs :

	4
	29
	7
	*/

	int n;
	cin >> n;

	for (int i = 1; i <= n; ++i)
	{
		cin >> arr[i];
		update(i, arr[i], n);

	}

	int t;
	cin >> t;

	while (t--) {
		int l, r;
		cin >> l >> r;

		cout << sum(r) - sum(l - 1) << endl; //the prefix sum
	}
	return 0;
}