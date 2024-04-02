#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    long long n;
    cin >> n;

    long long* a = new long long[n];
    long long* dp = new long long[n];

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    dp[0] = max(0LL, a[0]);
    for (int i = 1; i < n; i++) {
        dp[i] = max(dp[i-1] + a[i], a[i]);
    }

    cout << *max_element(dp, dp+n);

    delete[] a;
    delete[] dp;

    return 0;
}
