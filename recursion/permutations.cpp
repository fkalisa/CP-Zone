#include <bits/stdc++.h>

using namespace std;
void printPermutation (string s, string current, int freq []) {

    if (s.size() == current.size() )
    {
        cout << current << endl;
        return;
    }

    for (int i = 0; i < s.size(); ++i)
    {
        if (freq[i] == 0)
        {
            freq[i] = 1;
            printPermutation(s, current + s[i], freq);
            freq[i] = 0;
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

        P(n,r)=n! (n−r)! = 4!(4-4)! = 24

    */

    string s = "abab";
    int freq [s.size()];
    memset(freq, 0, sizeof(freq));
    printPermutation(s, "", freq);

    return 0;
}