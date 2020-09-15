#include <bits/stdc++.h>
using namespace std;

long double square_root(long double x, long double e) {

    long double start = 0;

    long double end = x + 1;

    while (start <= end) {

        long double mid  = ( long double)(end + start) /    (long double)(2);

        if (abs(mid * mid - x) < e * 10)
        {
            return mid;
        } else if (x > mid * mid) {
            start = mid + e;
        } else {
            end = mid - e;
        }

    }

    return -1;
}


int main() {
    long double e = 0.001;

    cout << " answer : " << fixed << setprecision(2) << square_root(2, e);
    cout << " answer : " << fixed << setprecision(2) << square_root(81, e);

}