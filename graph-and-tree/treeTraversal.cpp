#include <bits/stdc++.h>
#include <vector>

using namespace std;

/*
	this is for undirected,
	for a given u, we push v
	for a given v, we push u
*/

extern const int N = 6;
vector<int> adjs[N + 1];


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

	cout << "node : " <<  node << " , level: " << level << endl;

	for (int i = 0; i < adjs[node].size(); ++i)
	{
		if (adjs[node][i] != parent)
		{
			dfs(adjs[node][i], node, level + 1);
		}
	}


}

void bfs() {
	queue<pair<pair<int, int>, int>> q;
	q.push({{1, 0}, 0});

	while (!q.empty()) {
		pair<pair<int, int>, int> current = q.front();

		int node = current.first.first;
		int level = current.first.second;
		int parent = current.second;


		cout << node << " ";
		q.pop();


		for (int i = 0; i < adjs[node].size(); i++)
		{

			if (adjs[node][i] != parent) {
				q.push({{adjs[node][i], level + 1}, node});
			}
		}
	}

}





int main() {


	/*
	input :

	6
	1 2
	1 3
	1 4
	2 5
	2 6
	*/

	int n;
	cin >> n;
	cout << "-----bfs traversal-----" << endl;
	bfs();
	cout << "-----dfs traversal-----" << endl;
	dfs(1, 0, 0);

}
