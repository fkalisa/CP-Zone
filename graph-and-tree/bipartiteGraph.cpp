#include <bits/stdc++.h>

using namespace std;

#define int long long


bool visited[100005];
int color[100005];
vector<int> adjs[100005];

void init(int m) {
	for (int i = 0; i < m ; ++i)
	{
		int u, v;
		cin >> u >> v;
		adjs[u].push_back(v);
		adjs[v].push_back(u);

	}
}


bool dfs(int node, int col) {

	visited[node] = 1;
	color[node] = col;

	for (auto it : adjs[node])
	{

		if (!visited[ it])
		{
			if (!dfs(it, !col)) {
				return false;
			}
		} else if (color[it] == col)
		{
			return false;
		}
	}

	return true;

}


signed main() {
#ifndef ONLINE_JUDGE

//for getting input from input.txt
	freopen("../../../env/input.txt", "r", stdin);

//for writting output to output.txt
	freopen("../../../env/output.txt", "w", stdout);
#endif


	/*Bipartite , we detetect a cycle and check the color
	2 arrays :
		- visited array
		- color array
		- no need to carry the parent array
	
	Application : test an odd length cycle, it is not a bipartite

	input1 :

	4 4
	1 2
	2 3
	3 4
	4 1

	Output1 : 1

	input2 :

	5 5
	1 2
	2 3
	3 4
	4 5
	5 1

	Output2 : 0


	*/

	int n, m;

	cin >> n  >> m;

	init(m);

	cout << "Graph is Bipartite : " << dfs(5, 0) << endl;

	return 0;

}
