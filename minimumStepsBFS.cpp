#include <bits/stdc++.h>
using namespace std;

int arr[] = { 3, 4, 65 };
int mod = 100000;
int visited[100000];
int size = 3;

int getMinimumStep(int start, int end) {


    queue<pair<int, int>> q;

    q.push({start, 0});
    visited[start] = 1;

    while (!q.empty()) {
        pair<int, int> p = q.front();
        q.pop();

        if (p.first == end) {
            return p.second;
        }
        for (int i = 0; i < size; ++i)
        {
            int tmp = (arr[i] * p.first ) % mod;
            if (!visited[tmp])
            {
                q.push({tmp, p.second + 1});
                visited[tmp] = 1;
            }
        }

    }

    return -1;

}
int main() {
    int start = 7;
    int end = 66175;

    cout << getMinimumStep(start, end);

}