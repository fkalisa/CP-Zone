#include <bits/stdc++.h>
using namespace std;

long long dp[11000001][2];



long long compute2(long long arr[], int n) {

    // here i = 0
    // max I can get including the current number
    long long incl = arr[0];
    // max I can get excluding the current number
    long long excl = 0;

    for (int i = 1; i < n; ++i)
    {
        int tmp = incl;
        incl = max (incl, excl + arr[i]);
        excl = tmp;

    }

    return max(excl, incl);
}


long long compute1(long long arr[], int n, int index, int flag) {
    if (index >= n) {
        return 0;
    }
    if (dp[index][flag] != -1) {
        return dp[index][flag] ;
    }
    if (flag == 0) {
        //pick
        long long c1 = arr[index] + compute1(arr, n, index + 1, 1);
        // no pick
        long long c2 =  compute1(arr, n, index + 1, 0);
        return dp[index][flag] = max(c1, c2);
    } else {
        // no pick
        long long c2 =  compute1(arr, n, index + 1, 0);
        return dp[index][flag] = c2;
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
    max sum for no consecutive element :

    input :

    3
    3
    1 2 3
    3
    1 20 3
    5
    3 6 1 1 100

    output :

    4
    20


    */


    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        long long arr[n];

        for (int i = 0; i < n; ++i)
        {
            cin >> arr[i];
        }

        memset(dp, -1, sizeof dp);
        cout << " compute1 : " << compute1(arr, n, 0, 0) << endl;
        cout << " compute2 : " << compute2(arr, n) << endl;
    }

    return 0;

}