#include <bits/stdc++.h>

using namespace std;

extern const int N = 10000;
vector<int> adjs[N + 1];
int lev[N + 1];
vector <int> eulerVector;


void init(int n) {
	for (int i = 0; i < n - 1; ++i)
	{
		int u, v;
		cin >> u >> v;
		adjs[u].push_back(v);
		adjs[v].push_back(u);

	}
}

void dfs(int node, int par, int level) {


	lev[node] = level;
	eulerVector.push_back(node);
	for (auto it : adjs[node])
	{
		if (it != par)
		{
			dfs(it, node, level + 1);
			eulerVector.push_back(node);
		}
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



	Method using EulerTour : create a eulerTour vector and the minimum height value between i = 12 and j=11
	(values for which we want to find LCA) is the LCA

	    searching LCA of 12 and 11

	    solution : 3

	    inputs :

	    13
		1 2
		1 3
		1 4
		3 5
		3 6
		5 7
		5 8
		6 9
		6 10
		6 11
		8 12
		8 13

	Time complexity : O(N)

	*/

	int n;
	cin >> n;

	init(n);
	dfs(1, 0, 1);


	int i = 12;


	int j = 11;

	int mini = INT_MAX;

	int indexI = -1;
	int indexJ = -1;

	// calculating pointer for 11 and 12 in eulerTour vector

	for (int index = 0; index < eulerVector.size(); ++index)
	{
		if (eulerVector[index] == i && indexI == -1)
		{
			indexI = index;
		}
		if (eulerVector[index] == j && indexJ == -1)
		{
			indexJ = index;
		}
	}

	int minHeight = INT_MAX;

	for (int index = indexI; index <= indexJ; ++index)
	{
		int tmpHeight = lev[eulerVector[index]];
		if (minHeight > tmpHeight)
		{
			mini = eulerVector[index];
			minHeight = tmpHeight;
		}

	}


	cout << " answer : " << mini << endl;

	return 0;

}