#include <bits/stdc++.h>
using namespace std;


int getMaxValue(int values[], int weights[], int n, int maxWeight, int index) {

	if (index == n)
	{
		return 0;
	}

	int maxi = INT_MIN;
	if (weights[index] <= maxWeight)
	{

		maxi =  max(maxi, values[index] + getMaxValue(values, weights, n, maxWeight - weights[index], index + 1));
	}
	return max (maxi, getMaxValue(values, weights, n, maxWeight, index + 1));
}

int main() {
#ifndef ONLINE_JUDGE

//for getting input from input.txt
	freopen("../../../env/input.txt", "r", stdin);

//for writting output to output.txt
	freopen("../../../env/output.txt", "w", stdout);
#endif


	int n;
	cin >> n;

	int maxWeight;
	cin >> maxWeight;

	int values[n];
	int weights[n];

	for (int i = 0; i < n; ++i)
	{
		cin >> weights[i] >>  values[i];
	}

	cout << getMaxValue(values, weights, n, maxWeight, 0);

}