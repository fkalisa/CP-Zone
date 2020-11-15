#include <bits/stdc++.h>
using namespace std;

#define int long long



extern const int N = 1000005;
vector<int> adjs[N + 1];
//
int subtree[N + 1];
int height[N + 1];

int contribution[N + 1];

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

	height[node] = level;
	int sum = 0;

	for (auto it : adjs[node])
	{
		if (it != parent)
		{
			dfs(it, node, level + 1);
			sum += subtree[it];
		}
	}

	subtree[node] = 1 + sum;
}

bool descendingSort(int i, int j) { return i > j; }


signed main() {

#ifndef ONLINE_JUDGE

//for getting input from input.txt
	freopen("../../../env/input.txt", "r", stdin);

//for writting output to output.txt
	freopen("../../../env/output.txt", "w", stdout);
#endif

	/*


	https://codeforces.com/problemset/problem/1336/A
	input :

	7 4
	1 2
	1 3
	1 4
	3 5
	3 6
	4 7

	the formula is (level[node] -1) - (substree[node]-1)

	select k node, and calculate the max contribution

	output :

	7

	*/

	int n, k;
	cin >> n >> k;
	memset(subtree, -1, sizeof (subtree));
	memset(height, -1, sizeof (height));
	init(n);
	dfs(1, 0, 1);

	for (int i = 1; i <= n; ++i)
	{
		contribution[i] = (height[i] - 1 ) - (subtree[i] - 1);
	}

	sort(contribution, contribution + N, descendingSort);

	int sum = 0;
	for (int i = 0; i < k; ++i)
	{
		sum += contribution[i];
	}

	cout << "answer " << sum;


}

