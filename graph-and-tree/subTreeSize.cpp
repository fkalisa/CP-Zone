#include <bits/stdc++.h>
#include <vector>

#define int long long

using namespace std;


extern const int N = 1000005;
vector<int> adjs[N + 1];
int subtree[N + 1];

void init(int n) {
	for (int i = 0; i < n - 1; ++i)
	{
		int u, v;
		cin >> u >> v;
		adjs[u].push_back(v);
		adjs[v].push_back(u);

	}
}

void dfs(int node, int parent) {

	int sum = 0;
	for (auto it : adjs[node])
	{
		if (it != parent)
		{
			dfs(it, node);
			sum += subtree[it];
		}
	}

	subtree[node] = 1 + sum;
}

signed main() {
#ifndef ONLINE_JUDGE

//for getting input from input.txt
	freopen("../../../env/input.txt", "r", stdin);

//for writting output to output.txt
	freopen("../../../env/output.txt", "w", stdout);
#endif

	/*
	input :
	7
	1 2
	1 3
	1 4
	4 5
	4 6
	4 7

	output :
	array containing the size of the subtree for each node

	Node 0 -> subtree size 0
	Node 1 -> subtree size 7
	Node 2 -> subtree size 1
	Node 3 -> subtree size 1
	Node 4 -> subtree size 4
	Node 5 -> subtree size 1
	Node 6 -> subtree size 1
	Node 7 -> subtree size 1

	*/



	int n;
	cin >> n;

	memset(subtree, 0, sizeof subtree);

	init(n);

	dfs(1, 0);



	for (int i = 0; i <= n; ++i)
	{
		cout << "Node " << i << " -> subtree size " << subtree[i] << endl;

	}

	return 0;

}
