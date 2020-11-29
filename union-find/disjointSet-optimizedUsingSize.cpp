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
	 										9
											|
	 1 - 2 								6 - 7 - 8
	 |
	 3 - 4 - 5


	9 7
	1 2
	1 3
	3 4
	4 5
	6 7
	7 9
	7 8
	3
	7
	4
	6

	output : how many element in the componet

		7 -> 4
		4 -> 5
		6 -> 4
	*/

	int n, m;
	cin >> n >> m;

	for (int i = 1; i <= n; ++i)
	{
		parent[i] = i;
		size[i] = 1;
	}

	for (int i = 0; i < m; ++i)
	{
		int u, v;
		cin >> u >> v;

		cout << u << " " << v << endl;
		union1(u, v);
	}

	int q;
	cin >> q;

	for (int i = 0; i < q; ++i)
	{
		int k;
		cin >> k;
		cout << size[findParent(k)] << endl;
	}



	return 0;
}
