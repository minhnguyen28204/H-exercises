#include <bits/stdc++.h>
#define int long long

using namespace std;

int sum[200005];

signed main()
{
    if (fopen("test.inp","r")){
        freopen("test.inp","r",stdin);
    }
    for(int i=1; i<=2e5; i++) sum[i] = sum[i-1] + i;
    int t;
    cin >> t;
    while (t--){
        int n;
        cin >> n;
        vector<int> a(n);
        for(int i=0; i<n; i++){
            int x; cin >> x;
            a[i] = x-(i+1);
        }
        int ans = 0;
        sort(a.begin(),a.end());
        int l = 0;
        for(int r = 0; r < n; r++){
            if (a[r]!=a[l]){
                //cout << l << ' ' << r-1 << '\n';
                ans += sum[(r-1)-l];
                l = r;
            }
        }
        if (n-1-l > 0) ans += sum[n-1-l];
        cout << ans << '\n';
    }
    return 0;
}
