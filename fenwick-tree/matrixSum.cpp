#include <bits/stdc++.h>

using namespace std;

#define int long long

int fen[1025][1025];
int arr[1025][1025];



void update(int num, int index, int value, int n) {


	while (index <= n) {
		fen[num][index] = fen[num][index]  + value;
		index =  index + (index & -index);

	}
}

/*
	time complexity for sum : logN
*/

int sum (int num, int index) {

	int sum = 0;

	while (index >= 1) {
		sum = sum + fen[num][index];
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
		https://www.spoj.com/problems/MATSUM/

	input:
		1
		4
		SET 0 0 1
		SUM 0 0 3 3
		SET 2 2 12
		SUM 2 2 2 2
		SUM 2 2 3 3
		SUM 0 0 2 2
		END

	output :

	total : 1
	total : 12
	total : 12
	total : 13

	*/

	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;

		memset(fen, 0 , sizeof fen);
		memset(arr, 0, sizeof arr);

		while (true) {
			string s;

			cin >> s;
			if (s == "END")
			{
				break;
			} else {
				if (s == "SUM")
				{
					int x1, y1, x2, y2;
					cin >> x1 >> y1 >> x2 >> y2;
					x1++;
					x2++;
					y1++;
					y2++;
					int total = 0;

					for (int i = x1; i <= x2; ++i)
					{
						total = total + sum(i, x2 ) - sum(i, x1 - 1);
					}
					cout << "total : " << total << endl;

				} else {
					int x1, y1, value;
					cin >> x1 >> y1 >> value;
					x1++;
					y1++;
					arr[x1 ][y1 ] = value;
					update(x1 , y1 , value, n);
				}
			}
		}


	}


	return 0;
}