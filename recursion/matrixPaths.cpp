
#include <bits/stdc++.h>
using namespace std;

int matrix[3][3] = {

    {1, 1, 1},
    {0, 1, 1},
    {0, 1, 1}
};

void printPaths(int x, int y, int rows, int cols, std::vector<pair<int, int>> v) {

    if (x == rows - 1 && y == cols - 1 )
    {
        for (auto it : v)
        {
            cout << it.first << "," << it.second << " | ";
        }
        cout << rows - 1 << "," << cols - 1;
        cout << endl;
        return;
    }

    if (y + 1 < cols && matrix[x][y + 1] == 1)
    {
        v.push_back({x, y + 1});
        printPaths(x, y + 1, rows, cols, v);
        v.pop_back();
    }

    if (x + 1 < rows && matrix[x + 1][y] == 1) {
        v.push_back({x + 1, y});
        printPaths(x + 1, y, rows, cols, v);
        v.pop_back();
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
        Prints all path combo in matrix
    */

    std::vector<pair<int, int>> v;
    v.push_back({0, 0});

    printPaths(0, 0, 3, 3, v);
    return 0;
}