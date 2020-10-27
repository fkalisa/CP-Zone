#include <bits/stdc++.h>

using namespace std;

/*

0/ we need 3 colors to detect a cycle

1/ using topological sort algorithm for DAG
-> check the vector containing the topo is equal to number of vertices, if not there is a cycle

2/ use color white, gray, and black for directed graph
	init all the nodes are white
	when visited mark it gray
	when visited and all adjacents visited mark it black

	if the adjecent is already gray, this means there is a back edge therefore a cycle.
*/

extern const int V = 6;
extern const int E = 7;

bool isVisited[V];
vector<int> adjs[V];

int white = 1;
int gray = 2;
int black = 3;
//
int color[V];



void init(int n) {
	for (int i = 0; i < n ; ++i)
	{
		int u, v;
		cin >> u >> v;
		adjs[u].push_back(v);
	}
}

bool answer = false;

void dfs(int node) {

	isVisited[node] = 1;


	color[node] = gray;

	cout << node << endl;

	for (int i = 0; i < adjs[node].size(); ++i)
	{
		if (color[adjs[node][i]] == gray) {
			answer = true;
			return;
		}

		if (!isVisited[ adjs[node][i]])
		{
			dfs(adjs[node][i]);
		}
	}

	color[node] = black;
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
	3 5

	Ouput : 1
	Explanation : cycle introduced by 3-5 edge in directed graph

	*/

	init(E);
	memset(color, white, sizeof(color));
	memset(isVisited, false, sizeof (isVisited));

	dfs(5);

	cout << "answer : " << answer << endl;

	return 0;

}