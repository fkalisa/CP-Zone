#include <bits/stdc++.h>

using namespace std;

#define int long long


vector<pair<int, int>> adjs[100005];
int dist[100005];

void dijkstra(int  source ) {

    dist[source] = 0;
    priority_queue<pair<int, int>, std::vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, source});


    for (int i = 0; i < 100005; ++i)
    {
        dist[i] = INT_MAX;

    }


    while (!pq.empty()) {
        auto it = pq.top();
        pq.pop();

        int distance = it.first;
        int node = it.second;

        for (auto elt : adjs[node])
        {

            int v = elt.first;
            int w = elt.second;

            if (distance + w < dist[v]) {
                dist[v] = distance + w;
                pq.push({distance + w, v});
            }
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

    input :

    9 14
    0 1 4
    0 7 8
    1 7 11
    7 6 1
    7 8 7
    1 2 8
    2 8 2
    8 6 6
    6 5 2
    2 5 4
    2 3 7
    3 5 14
    3 4 9
    5 4 10

    output :

    distance from 0 to 0 : 8
    distance from 0 to 1 : 4
    distance from 0 to 2 : 12
    distance from 0 to 3 : 19
    distance from 0 to 4 : 21
    distance from 0 to 5 : 11
    distance from 0 to 6 : 9
    distance from 0 to 7 : 8
    distance from 0 to 8 : 14

    */

    int n, m;
    cin >> n >> m;

    for (int i = 0; i < m; ++i)
    {
        int u, v, w;
        cin >> u >> v >> w;
        adjs[u].push_back({v, w});
        adjs[v].push_back({u, w});
    }

    int source = 0;

    //memset(dist, INT_MAX, sizeof(dist));
    dijkstra(source);

    for (int i = 0; i < n; ++i)
    {
        cout << "distance from " << source << " to " << i << " : " << dist[i] << endl;
    }

    return 0;
}
