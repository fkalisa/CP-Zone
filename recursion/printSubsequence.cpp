
#include <bits/stdc++.h>
using namespace std;

void printSubsequence(int arr[], int n, int k,  int index, int sum, vector<int> &v) {


    if (index == n)
    {
        if (sum % k == 0)
        {
            for (auto it : v)
            {
                cout << it << " ";
            }
            cout << endl;

        }
        return;
    }

    //pick
    v.push_back(arr[index]);
    printSubsequence(arr, n, k, index + 1, sum + arr[index] , v);
    v.pop_back();

    // non-pick
    printSubsequence(arr, n,  k, index + 1, sum , v);

}

int main() {
#ifndef ONLINE_JUDGE

//for getting input from input.txt
    freopen("../../../env/input.txt", "r", stdin);

//for writting output to output.txt
    freopen("../../../env/output.txt", "w", stdout);
#endif

    /*


    */

    int arr[] = {2, 3, 4 , 5, 4, 7};
    int k = 3;
    int n = 6;
    vector<int> v;

    printSubsequence(arr, n, k, 0, 0, v);

    return 0;
}