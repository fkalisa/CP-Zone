#include <bits/stdc++.h>

using namespace std;



void printCombo(int num, int sum, vector<int> &v) {

	if (sum == 0)
	{
		for (int i = 0; i < v.size(); ++i)
		{
			cout << v[i] << " ";
		}
		cout << endl;
	}

	for (int i = num; i <= sum; ++i)
	{
		v.push_back(i);
		printCombo(i, sum - i, v );
		v.pop_back();
	}
}

void printAllCombo(int num, int sum, vector<int> &v) {

	if (sum == 0)
	{
		for (int i = 0; i < v.size(); ++i)
		{
			cout << v[i] << " ";
		}
		cout << endl;
	}

	for (int i = 1; i <= sum; ++i)
	{
		v.push_back(i);
		printAllCombo(i, sum - i, v );
		v.pop_back();
	}
}

void printStrictlyIncreasingCombo(int num, int sum, vector<int> &v) {

	if (sum == 0)
	{
		for (int i = 0; i < v.size(); ++i)
		{
			cout << v[i] << " ";
		}
		cout << endl;
	}

	for (int i = num; i <= sum; ++i)
	{
		v.push_back(i);
		printStrictlyIncreasingCombo(i + 1, sum - i, v);
		v.pop_back();
	}
}


int main() {
#ifndef ONLINE_JUDGE

//for getting input from input.txt
	freopen("../../../env/input.txt", "r", stdin);

//for writting output to output.txt
	freopen("../../../env/output.txt", "w", stdout);
#endif

	/*
		input 5

		output :
		-----1------
		1 1 1 1 1
		1 1 1 2
		1 1 3
		1 2 2
		1 4
		2 3
		5
		-------2------

		1 4
		2 3
		5

		------3-------
		1 1 1
		1 2
		2 1
		3
	*/

	vector<int> v;
	printCombo(1, 5, v);
	cout << endl;
	printStrictlyIncreasingCombo(1, 5, v);
	cout << endl;
	printAllCombo(1, 3, v);



}

