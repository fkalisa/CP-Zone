#include <bits/stdc++.h>
using namespace std;

#define int long long

int parent[100005];
int size[100005];

vector<pair<int, pair<int, int>>> vec;

void init(int n, int m) {

	for (int i = 0; i < m; ++i)
	{
		int u, v, w;
		cin >> u >> v >> w;
		vec.push_back({w, {u, v}});
	}
}

int findParent(int u) {

	if (u == parent[u])
	{
		return u;
	}

	return parent[u] = findParent(parent[u]);
}


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

int sum = 0;

void minSpannigTree(std::vector<pair<int, pair<int, int>>> v) {

	for (auto it : v)
	{
		int w = it.first;
		int u = it.second.first;
		int v = it.second.second;

		cout << u << "* " << v << " " << w <<  " perU --> " << findParent(u) << "  perV --> " << findParent(v) << endl;


		if (findParent(u) != findParent(v))
		{

			cout << u << "**" << v << " " << w <<  " perU --> " << findParent(u) << "  perV --> " << findParent(v) << endl;


			sum = sum + w;

			union1(u, v);
		}
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

	Also known as Kruskal Algorithm

	input :

	8 9
	1 2 2
	1 4 1
	5 4 9
	5 1 4
	2 4 3
	4 3 5
	3 2 3
	2 6 7
	3 6 8

	output :
	17

	*/
	int n, m;
	cin >> n >> m;

	init(n, m);

	for (int i = 1; i <= n; ++i)
	{
		parent[i] = i;
		size[i] = 1;
	}

	sort(vec.begin(), vec.end());

	minSpannigTree(vec);

	cout << sum;
	return 0;
}
