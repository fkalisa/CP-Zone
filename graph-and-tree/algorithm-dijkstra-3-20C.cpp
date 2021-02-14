#include <bits/stdc++.h>

using namespace std;

extern const int N = 100000;

vector<int> adjs[N + 1];
map<pair<int, int>, int> mpp;

int dist[N + 1];
int parent[N + 1];

void init(int m) {

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


    for (int i = 1; i <= n + 1; ++i)
    {
        dist[i] = INT_MAX;

    }

    dist[source] = 0;
    parent[source] = source;


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
                parent[adjs[node][i]] = node;
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

    /*
        inputs :

        5 6
        1 2 2
        2 5 5
        2 3 4
        1 4 1
        4 3 3
        3 5 1

        Output :

        1 4 3 5

    */
    int n, m;
    cin >> n >> m;

    memset(parent, -1, sizeof parent);

    init(m);
    int source = 1;
    dijsktra(source, n);

    for (int i = 1; i <= n; ++i)
    {
        cout << "distance from " << source  << " to " << i << " : " << dist[i] << endl;
    }

    cout << "------" << endl;

    for (int i = n; i >=  1; --i)
    {
        cout << i << " : " <<  parent[i] << endl;
    }

    cout << "------" << endl;

    int i = n;
    cout << n << endl;
    while (i != 1 ) {
        cout << parent[i] << endl;
        i = parent[i];

    }


}



