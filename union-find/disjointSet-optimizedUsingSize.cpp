#include <bits/stdc++.h>
using namespace std;

#define int long long


int parent[100005];
int size[100005];

// the ultemate parent
int findParent(int u) {

	if (u == parent[u])
	{
		return u;
	}

	return parent[u] = findParent(parent[u]);
}

// O(4alpha) -->
void union1(int u, int v) {

	int parU = findParent(u);
	int parV = findParent(v);

	if (parU == parV)
	{
		return;
	}

	if (size[u] > size[v])
	{
		parent[parV] = parU;
		size[parU] += size[parV];
	} else {
		parent[parU] = parV;
		size[parV] += size[parU];
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

	input :


	output :


	*/

	int n = 8;

	for (int i = 1; i <= n; ++i)
	{
		parent[i] = i;
		size[i] = 1;
	}



	return 0;
}
