#include <bits/stdc++.h>

using namespace std;

int main() {
#ifndef ONLINE_JUDGE

//for getting input from input.txt
	freopen("../../../env/input.txt", "r", stdin);

//for writting output to output.txt
	freopen("../../../env/output.txt", "w", stdout);
#endif


	/*


	input :
		5 6
		1 2 1 1 2 2
		1 2 4 2 2 3
		1 1 1 2 1 1
		1 2 1 2 1 2
		1 3 1 1 2 1
		3
		3 3 4 4
		0 0 2 2
		1 2 4 4

	output

		6
		14
		20

	*/
	int n, m;
	cin >> n >> m;

	int matrix[n][m];
	int prefix[n][m];

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			cin >> matrix[i][j];
		}
	}

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			if (i == 0 && j == 0)
			{
				prefix[i][j] = matrix[i][j];
			} else if (i == 0) {
				prefix[i][j] = prefix[i][j - 1] + matrix[i][j];

			} else if (j == 0) {
				prefix[i][j]  = prefix[i - 1][j] + matrix[i][j];
			} else {
				prefix[i][j] =	prefix[i - 1][j] + prefix[i][j - 1] - prefix[i - 1][j - 1] + matrix[i][j];
			}
		}
	}

	int q;
	cin >> q;

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			if (j > 0)
			{
				cout << " ";
			}
			cout << prefix[i][j];

		}
		cout << endl;
	}

	while (q--) {

		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;


		int sum = prefix[x2][y2];

		if (x1 - 1 >= 0)
		{
			sum = sum - prefix[x1 - 1][y2];
		}
		if (y1 - 1 >= 0)
		{
			sum = sum  - prefix[x2][y1 - 1];
		}
		if (x1 - 1 >= 0 && y1 - 1 >= 0)
		{
			sum = sum + prefix[x1 - 1][y1 - 1];
		}
		cout << "sum between (x1,y1,x2,y2) " << x1 << "," << y1 << "," << x2 << "," << y2 << " : "  << sum << endl;
	}
	return 0;
}