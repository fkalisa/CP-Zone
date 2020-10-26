#include <bits/stdc++.h>

using namespace std;

stack<int> topo;
int vis[1000005];


void dfs(int node) {

	vis[node] = 1;
	for (auto it : adj[node])
	{
		if (!vis[it]) {
			dfs(it);
		}
	}

	topo.push(node);

}
int main() {


	int n ;
	cin >> n;


	for (int i = 0; i < n; ++i)
	{
		if (!vis[i])
		{
			dfs(i);
		}
	}

}