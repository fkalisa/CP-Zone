#include <bits/stdc++.h>

using namespace std;

#define int long long


vector<int> adjs[100005];
int visited[100005];
int low[100005];
int entryTime[100005];
int timer = 0;
void init(int m) {

	for (int i = 0; i < m; ++i)
	{
		char u, v;
		cin >> u >> v;
		adjs[u - 'a'].push_back(v - 'a');
		adjs[v - 'a'].push_back(u - 'a');
	}
}

void dfs(int node, int par = 0) {

	visited[node] = 1;
	low[node] = entryTime[node] = timer++;

	for (auto it : adjs[node])
	{

		if (it == par) {
			continue;
		}
		if (visited[it]) {
			low[node] = min(low[node], entryTime[it]);
		} else {
			dfs(it, node);
			low[node] = min(low[node], low[it]);
			if (low[it] >  entryTime[node]) {
				cout << (char)(it + 'a') << " " << (char)(node + 'a') << endl;
			}

		}
	}

}
signed main() {
#ifndef ONLINE_JUDGE

//for getting input from input.txt
	freopen("../../../env/input.txt", "r", stdin);

//for writting output to output.txt
	freopen("../../../env/output.txt", "w", stdout);
#endif


	/*

	inputs :
	14 19
	a b
	a c
	b c
	b e
	c d
	d e
	d f
	b f
	c h
	i h
	h j
	j l
	i j
	i k
	k l
	k m
	m n
	n o
	o m


	output
	m k
	h c
	*/

	int n, m ;
	cin >> n >> m;

	init(m);

	for (int i = 1; i <= n; ++i)
	{
		if (!visited[i]) {
			dfs(i);
		}
	}

	return 0;

}