#include <bits/stdc++.h>

using namespace std;

/*

	1/ we do not need 3 colors, we can use visited flag and previous

*/

extern const int V = 6;
extern const int E = 6;

bool isVisited[V];
vector<int> adjs[V];

void init(int n) {
	for (int i = 0; i < n ; ++i)
	{
		int u, v;
		cin >> u >> v;
		adjs[u].push_back(v);
		adjs[v].push_back(u);

	}
}

bool answer = false;

void dfs(int node, int previous) {

	isVisited[node] = 1;

	cout << node << endl;

	for (int i = 0; i < adjs[node].size(); ++i)
	{
		if (isVisited[ adjs[node][i]] &&  adjs[node][i] != previous)
		{
			answer = true;
			return;
		}
		if (!isVisited[ adjs[node][i]])
		{
			dfs(adjs[node][i], node);
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

	input :

	5 2
	5 0
	4 0
	4 1
	2 3
	3 1

	Output : 1

	Explantion : we came to a visited node which is different from the previous

	*/

	init(E);
	memset(isVisited, false, sizeof (isVisited));

	dfs(5, -1);

	cout << "answer : " << answer << endl;

	return 0;

}