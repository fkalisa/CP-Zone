#include <bits/stdc++.h>

using namespace std;

extern const int N = 100005;
vector<int> adjs[N + 1];
int lev[N + 1];
int par[N + 1][21];

void dfs(int node, int parent, int level) {


	for (int i = 0; i < 21; ++i)
	{
		par[node][i] = par[par[node][i - 1]][ i - 1];
	}
	lev[node] = level + 1;

	for (int i = 0; i < adjs[node].size(); ++i)
	{
		if (adjs[node][i] != parent)
		{
			dfs(adjs[node][i], node, level);
		}

	}

}

void swap(int a, int b) {
	int tmp = a;
	a = b;
	b = tmp;
}

int lca(int u, int v) {
	if (lev[u] < lev[v]) {
		swap(u, v);
	}

	int dist = lev[u] - lev[v];
	int cnt = 0;

	while (dist) {
		if (dist & 1)
		{
			u = par[u][cnt];
		}
		cnt++;
		dist = dist >> 1;
	}

	if (u == v) return v;


	for (int i = 20; i >= 0; i--) {
		int p1 = par[u][i];
		int p2 = par[v][i];
		if (p1 != p2)
		{
			u = p1;
			v = p2;
		}
	}
	return par[u][0];
}



int main() {
#ifndef ONLINE_JUDGE

//for getting input from input.txt
	freopen("input.txt", "r", stdin);

//for writting output to output.txt
	freopen("output.txt", "w", stdout);
#endif

	/*

	calculating the parent
	for(int i= 0; i < 20; i ++ ){

		par[node][i] = [par[node][i-1]][n-1]

	}
	if tree, time complex is O(N*20)

	any number(distance) can be represented in power of 2, that is why we store parents in power of 2

	application : LCA

	why 20? 2^20 --> 10^6


	LCA implementation :

	given u and v, for which we want to find

	- who is at the bottom level between u (bottom level 12), and v (bottom level 10)
	- u is at the bottom with the difference of 2
	- 2 --> 2^1
	- par[u][1] = [par[u][0]][0]
	- from 20 to 0, with j
		- if par[u][j] != par[v][j], we move u and v
		- if same, continue

	- the immidiate parent is the LCA

	*/





	return 0;

}
