#include <bits/stdc++.h>

using namespace std;


bool isVisited[10005];
vector<int> adjs[10005];
int color [10005];

void init(int m) {
	for (int i = 0; i < m ; ++i)
	{
		int u, v;
		cin >> u >> v;
		adjs[u].push_back(v);
		adjs[v].push_back(u);

	}
}


bool dfs(int node, int parent, int col = 0) {

	isVisited[node] = 1;
	color[node] = col;

	//cout << node << endl;

	for (auto it : adjs[node] )
	{
		if (isVisited[ it] &&  it != parent)
		{
			return true;
		}
		if (!isVisited[ it])
		{
			if (dfs(it, node, !col)) {
				return true;
			};
		}
	}
	return false;

}


int main() {
#ifndef ONLINE_JUDGE

//for getting input from input.txt
	freopen("../../../env/input.txt", "r", stdin);

//for writting output to output.txt
	freopen("../../../env/output.txt", "w", stdout);
#endif


	/*
	input :
	5 6
	5 2
	5 0
	4 0
	4 1
	2 3
	3 1
	Output : 1
	Explantion : we came to a visited node which is different from the previous(parent)
	*/

	int n, m;
	cin >> n >> m;

	init(m);
	memset(isVisited, false, sizeof (isVisited));
	memset(color, 0, sizeof (color));

	for (int i = 0; i <= n ; ++i)
	{
		if (!isVisited[i]) {
			cout << " cycle : " << dfs(5, -1) << endl;

		}
	}

	return 0;

}