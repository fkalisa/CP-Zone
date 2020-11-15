#include <bits/stdc++.h>

using namespace std;

extern const int N = 10000;
vector<int> adjs[N + 1];
int lev[N + 1];
int parent[N + 1];


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
	parent[node] = par;

	for (int i = 0; i < adjs[node].size(); ++i)
	{
		if (adjs[node][i] != par)
		{
			dfs(adjs[node][i], node, level + 1);
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

	1/ Method using the parent array :
			- store the ancestor of 12 --> 12 8 5 3 1
			- store the ancestor of 11 --> 11 6 3 1

	check the element in commin : 3

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

	2/ using Euler Tour
	*/

	int n;
	cin >> n;

	init(n);
	dfs(1, 0, 0);


	int i = 12;

	std::vector<int> v1;

	while (i != 1) {
		i = parent[i];
		v1.push_back(i);
	}


	std::vector<int> v2;
	int j = 11;
	while (j != 1) {
		j = parent[j];
		v2.push_back(j);
	}

	sort( v1.begin(), v1.end());

	sort(v2.begin(), v2.end());

	int result = -1;
	for (int i = 0; i < n; ++i)
	{
		if (v2[i] == v1[i])
		{
			result = v1[i];
		} else {
			break;
		}
	}

	cout << "answer : " << result << endl;


	return 0;

}