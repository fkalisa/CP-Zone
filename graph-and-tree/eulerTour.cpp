#include <bits/stdc++.h>
#include <vector>

using namespace std;


extern const int N = 10000;
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

void eulertour(int node, int par = 0) {
	cout << node << " ";
	for (auto it : adj[node]) {
		if (it != par) {
			eulertour(it, node);
			cout << node << " ";
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

	inputs :

	7
	1 2
	1 3
	1 4
	3 5
	3 6
	4 7

	output :

	1 2 1 3 5 3 6 3 1 4 7 4 1


	*/

	int n;
	cin >> n;

	memset(adjs, 0, sizeof adjs);

	eulertour(1);

}