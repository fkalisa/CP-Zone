#include <bits/stdc++.h>

using namespace std;

#define int long long

std::vector<int> adjs[100005];

bool visited[100005];
bool dfsVisited[100005];


void init(int m) {

    for (int i = 0; i < m; ++i)
    {
        int u, v;
        cin >> u >> v;
        adjs[u].push_back(v);
    }
}

bool dfs(int n) {

    visited[n] = true;
    dfsVisited[n] = true;

    for (auto it : adjs[n])
    {

        if (visited[it] == false)
        {
            if (dfs(it)) {
                return true;
            }

        } else if (dfsVisited[it]) {
            return true;
        }

    }
    dfsVisited[n] = false;

    return false;
}
signed main() {


#ifndef ONLINE_JUDGE

//for getting input from input.txt
    freopen("../../../env/input.txt", "r", stdin);

//for writting output to output.txt
    freopen("../../../env/output.txt", "w", stdout);
#endif


    /*

    we use 2 visted array :
        visited : global array
        dfsVisisted : inside a dfs call

    7 7 N M
    1 2
    2 3
    3 4
    5 2
    5 7
    7 6
    6 5


            7 - > 6
            ^
              \  /

               5
               ^
               |
        1  ->  2 -> 3  -> 4



    */

    int n, m;
    cin >> n >> m;

    init(m);

    int flag = false;

    for (int i = 0; i <= n; ++i)
    {
        if (!visited[i])
        {
            if (dfs(i)) {
                flag = true;
                break;
            }
        }
    }

    cout << " cycle detected : " << flag << endl;

    return 0;
}
