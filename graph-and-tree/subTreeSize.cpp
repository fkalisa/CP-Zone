#include <bits/stdc++.h>
#include <vector>

using namespace std;


extern const int N = 1000005;
vector<int> adjs[N + 1];
int lev[N + 1];
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

void dfs(int node, int parent, int level) {


	lev[node] = level;
	//subtree init
	subtree[node] = 1;
	for (int i = 0; i < adjs[node].size(); ++i)
	{
		if (adjs[node][i] != parent)
		{
			dfs(adjs[node][i], node, level + 1);
			//subtree sum
			subtree[node] = subtree[node] + subtree[adjs[node][i]];

		}
	}
}

int main() {
#ifndef ONLINE_JUDGE

//for getting input from input.txt
	freopen("input.txt", "r", stdin);

//for writting output to output.txt
	freopen("output.txt", "w", stdout);
#endif

	/*

	7 4
	1 2
	1 3
	1 4
	3 5
	3 6
	4 7
	*/



	int n;
	cin >> n;
	int k;
	cin >> k;

	memset(adjs, 0, sizeof adjs);
	memset(lev, 0, sizeof lev);
	memset(subtree, 0, sizeof subtree);

	init(n);


	dfs(1, 0, 0);



	for (int i = 0; i < n; ++i)
	{
		cout << "Subtree size " << subtree[i] << endl;

	}

	return 0;

}
