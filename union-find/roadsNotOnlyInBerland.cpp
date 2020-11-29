#include <bits/stdc++.h>
using namespace std;

#define int long long


int parent[100005];
int size[100005];

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
vector<pair<int, int>> freeRoads;

void init(int n) {
	for (int i = 1; i < n; ++i)
	{
		int u , v;
		cin >> u >> v;

		if (findParent(u) != findParent(v))
		{
			union1(u, v);
		} else {
			freeRoads.push_back({u, v});
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

		https://codeforces.com/problemset/problem/25/D

		input :

		7
		1 2
		2 3
		3 1
		4 5
		5 6
		6 7


		out

		3 1 is an extra road thac can use to contruct a road between 2 7

		3 1 --> 2 7


	*/



	int n;
	cin >> n;

	for (int i = 1; i <= n; ++i)
	{
		parent[i] = i;
		size[i] = 1;
	}

	init(n);

	set<int> ultimateParent;
	for (int i = 1; i < n; ++i)
	{
		ultimateParent.insert(findParent(i));
	}

	int componentNumber = ultimateParent.size();


	if (freeRoads.size() >= componentNumber - 1) {


		std::vector<int> v(ultimateParent.begin(), ultimateParent.end());

		for (int i = 0; i < v.size() - 1; ++i)
		{
			pair<int, int> p = freeRoads.back();
			freeRoads.pop_back();
			cout << p.first << " " << p.second << " --> " << v[i] << " " << v[i + 1] << endl;
		}
	} else {
		cout << "impossible to link all the roads" << endl;
	}

	return 0;
}
