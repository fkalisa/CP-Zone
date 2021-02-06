#include <bits/stdc++.h>

using namespace std;

stack<int> topo;
int vis[1000005];


extern const int V = 6;
extern const int E = 6;

vector<int> adjs[V];

void init(int n) {
	for (int i = 0; i < n ; ++i)
	{
		int u, v;
		cin >> u >> v;
		adjs[u].push_back(v);
	}
}

void dfs(int node) {

	vis[node] = 1;
	for (auto it : adjs[node])
	{
		if (!vis[it]) {
			dfs(it);
		}
	}

	topo.push(node);

}
int main() {

#ifndef ONLINE_JUDGE

//for getting input from input.txt
	freopen("../../../env/input.txt", "r", stdin);

//for writting output to output.txt
	freopen("../../../env/output.txt", "w", stdout);
#endif

	/*

	Topo using a stack

	5 2
	5 0
	4 0
	4 1
	2 3
	3 1

	*/
	init(E);

	for (int i = 0; i < V; ++i)
	{
		if (!vis[i])
		{
			dfs(i);
		}
	}

	while (!topo.empty())
	{

		cout << topo.top() << " ";
		topo.pop();
	}
}
