#include <stdio.h>

#define MOD 1000000007

long long factorial(int n) {
    long long fact = 1;
    for(int i = 2; i <= n; i++) {
        fact = (fact * i) % MOD;
    }
    return fact;
}

long long power(long long x, int y) {
    long long res = 1;
    x = x % MOD;
    while (y > 0) {
        if (y & 1)
            res = (res*x) % MOD;
        y = y >> 1;
        x = (x*x) % MOD;
    }
    return res;
}

long long modInverse(long long n) {
    return power(n, MOD-2);
}

long long nCrModPFermat(int n, int r) {
    if (r==0)
        return 1;
    long long fac[n+1];
    fac[0] = 1;
    for (int i=1 ; i<=n; i++)
        fac[i] = fac[i-1]*i%MOD;
    return (fac[n]* modInverse(fac[r]) % MOD *
            modInverse(fac[n-r]) % MOD) % MOD;
}

int main() {
    int k, n;
    scanf("%d %d", &k, &n);
    printf("%lld\n", nCrModPFermat(n, k));
    return 0;
}
