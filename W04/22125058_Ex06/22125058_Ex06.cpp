#include <bits/stdc++.h>

using namespace std;

bool isPrime[1000005];

void sieve(){
    memset(isPrime, true, sizeof isPrime);
    isPrime[0] = isPrime[1] = false;
    for(int i=2; i*i<=1e6; i++){
        if (isPrime[i]){
            for(int j=i*i; j<=1e6; j+=i) isPrime[j] = false;
        }
    }
}

int main()
{
    sieve();
    int n;
    cin >> n;
    //T-prime = prime^2
    for(int i=1; i<=n; i++){
        long long x;
        cin >> x;
        long long dx = sqrt(x);
        if (dx * dx == x){
            if (isPrime[dx]){
                cout << "YES\n";
                continue;
            }
        }
        cout << "NO\n";
    }
    return 0;
}
