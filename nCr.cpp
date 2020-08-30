#include <bits/stdc++.h>
#define int long long

using namespace std;
extern const int N = 1e5;
extern const int mod = 1e9 + 7;

int fact[N];

int  power(int  b, int  p, int mod) {

    int res = 1;

    while (p != 0) {
        if (p % 2 == 0) {
            b = (b * b) % mod;
            p = p / 2;
        } else {
            res = (b * res) % mod;
            p = p - 1;
        }
    }
    return res;
}


void preCompute() {
    fact[0] = 1;
    for (int i = 1; i < N; i++) {
        fact[i] = ((i % mod) * (fact[i - 1] % mod)) % mod;
    }
}

int moduloInverse(int n)
{
    return power(n, mod - 2, mod);
}

int  nCr(int  n, int r) {
    int  a = fact[n];
    int  b = fact[r];
    int  c =  fact[n - r];

    long long answer = ( a * (moduloInverse(b) % mod * moduloInverse(c) % mod ) % mod) % mod;
    return answer;

}

signed main() {
    preCompute();
    cout  << "answer : " << nCr(10, 4) << endl;
    return 0;
}






