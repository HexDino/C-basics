#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    int n, m;
    scanf("%d%d", &n, &m);
    while (n--){
        char x[256];
        scanf("%s", x);
        long long sum = 0;
        int j = 0;
        for (int i = strlen(x) - 1; i >= 0; i--){
            sum = (sum * 256 + x[j]) % m;
            j++;
        }
        printf("%lld\n", sum);
    }   
}