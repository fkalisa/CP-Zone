#include <bits/stdc++.h>

using namespace std;

#define int long long

int fen[10000007];
int freq[10000007];
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
	https://www.spoj.com/problems/INVCNT/
	 fenwickTree with hashTable


	 input :

	2
	3 3 1 2
	5 2 3 8 6 1

	output :

	2
	4

	*/

	int t;
	cin >> t;



	while (t--) {
		int n;
		cin >> n;

		memset(fen, 0, sizeof fen);
		memset(freq, 0, sizeof freq );
		memset(arr, 0, sizeof arr);

		/*
			complexity : NlogN
		*/
		for (int i = 1; i <= n; ++i)
		{
			cin >> arr[i];
			freq[arr[i]]++;
			update( arr[i], 1, n );
		}

		int total = 0;
		/*
			complexity : NlogN
		*/
		for (int i = 1; i <= n; ++i)
		{
			freq[arr[i]]--;
			update( arr[i], -1, n ); // do not forget
			total = total + sum(arr[i] - 1);
		}

		cout << total << endl;

	}
	return 0;
}