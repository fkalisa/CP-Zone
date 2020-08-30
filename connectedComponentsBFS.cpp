#include <bits/stdc++.h>
using namespace std;


int n =  5 ;

int matrix [][5] = {
    {1, 1, 0, 1, 1},
    {1, 1, 0, 0, 0},
    {0, 0, 0, 1, 1},
    {1, 1, 0, 1, 1},
    {0, 0, 0, 0, 0}
};


int mx[] = {0, 0, 1, -1};
int my[] = {1, -1, 0, 0};

int vis[5][5];


bool isValid(int x, int y ) {
    return x >= 0 && y >= 0 && x < n && y < n && !vis[x][y] &&  matrix[x][y] == 1;
}

void dfs(int i, int j) {

    queue<pair<int, int>> q;
    q.push({i, j});
    vis[i][j] = 1;

    while (!q.empty()) {
        pair<int, int> p = q.front();
        q.pop();
        int xi = p.first;
        int yi = p.second;

        for (int k = 0; k < 4; ++k)
        {
            int tx = xi + mx[k];
            int ty = yi + my[k];

            if (isValid(tx, ty))
            {
                q.push({tx, ty});
                vis[tx][ty] = 1;
            }
        }

    }

}

int main() {
    int counter = 0;

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            if (matrix[i][j] == 1 && !vis[i][j])
            {
                counter++;
                dfs(i, j);
            }
        }
    }

    cout  << "answer : " << counter << endl;
    return 0;
}
