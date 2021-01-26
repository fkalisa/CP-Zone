#include <bits/stdc++.h>

#define int long long

using namespace std;


signed main() {


#ifndef ONLINE_JUDGE

//for getting input from input.txt
    freopen("../../../env/input.txt", "r", stdin);

//for writting output to output.txt
    freopen("../../../env/output.txt", "w", stdout);
#endif

    /*

    https://atcoder.jp/contests/abc189/tasks/abc189_c

    input :

    6
    200 4 4 9 4 9

    6
    2 4 4 9 4 9

    output :

    200
    20 = 4 * 5
    */


    int n;
    cin >> n;

    int arr[n];

    for (int i = 0; i < n; ++i)
    {
        cin >> arr[i];
    }

    int resultat = arr[0];

    for (int i = 0; i < n; ++i)
    {

        int mini = INT_MAX;
        for (int j = i; j < n; ++j)
        {
            mini = min(mini, arr[j]);

            int tmp = mini * (j - i + 1);
            if (resultat < tmp)
            {
                resultat = tmp;
            }
        }


    }


    cout << resultat << endl;


    return 0;
}