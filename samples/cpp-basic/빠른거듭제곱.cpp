#include <stdio.h>

typedef long long ll;

ll pow(ll value, ll n) {
    if(n == 0) return 0;
    if(n == 1) return value;
    ll result = pow(value, n / 2);
    result *= result;
    if(n % 2) result *= value;
    return result;
}

int main() {
    printf("%lld", pow(2,50));
    return 0;
}