#include <bits/stdc++.h>

using namespace std;


extern const int N = 100000;
vector<int> adjs[N + 1];

map<pair<int, int>, int> mpp;

int dist[N + 1];

void init(int n, int m) {

	for (int i = 0; i < m; ++i)
	{
		int u, v, w;
		// u,v(vertices) and w (the weight associated)

		cin >> u >> v >> w;
		adjs[u].push_back(v);
		adjs[v].push_back(u);
		mpp[ {u, v}] = w;
		mpp[ {v, u}] = w;
	}
}

void dijsktra(int source, int n) {
	//min heap
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

	pq.push({0, source});


	for (int i = 0; i < n; ++i)
	{
		dist[i] = INT_MAX;

	}

	dist[source] = 0;


	while (!pq.empty()) {
		auto it = pq.top();
		pq.pop();

		int distt = it.first;
		int node = it.second;


		for (int i = 0; i < adjs[node].size(); ++i)
		{
			int dis = distt + mpp[ {node, adjs[node][i]}];
			if (dis < dist[adjs[node][i]]) {
				dist[adjs[node][i]] = dis;
				pq.push({dis, adjs[node][i]});
			}
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
	int n, m;
	cin >> n >> m;

	// n (total number of nodes), m(edges)
	memset(adjs, 0, sizeof adjs);
	memset(dist, 0, sizeof dist);
	init(n, m);
	int source = 0;
	dijsktra(source, n);

	for (int i = 0; i < n; ++i)
	{
		cout << "distance from " << source  << " to " << i << " : " << dist[i] << endl;
	}

}



