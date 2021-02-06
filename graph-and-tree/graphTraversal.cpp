#include <bits/stdc++.h>
#include <vector>

using namespace std;

/*
	this is for undirected,
	for a given u, we push v
	for a given v, we push u
*/

vector<int> adjs[100005];
bool visited[100005];

void init(int m) {
	for (int i = 0; i < m; ++i)
	{
		int u, v;
		cin >> u >> v;
		adjs[u].push_back(v);
		adjs[v].push_back(u);

	}
}


void dfs(int node) {


	visited[node] = true;

	cout << "node : " << node << endl;
	for (int i = 0; i < adjs[node].size(); ++i)
	{
		if (visited[adjs[node][i]] == false)
		{
			dfs(adjs[node][i]);
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

	in graph traversal we have a visited array to avoid infinite traversal
	in graph we have N node and m edges

	input :


	5 6
	5 2
	5 0
	4 0
	4 1
	2 3
	3 1
	*/

	int n, m;
	cin >> n >> m;

	init(m);

	int connectedComponent = 0;
	for (int i = 0; i <= n; ++i)
	{

		if (!visited[i])
		{
			connectedComponent ++;
			dfs(i);
		}

	}

	cout << "Connected component : " << connectedComponent << endl;

}
