#include<bits/stdc++.h>
#define int long long
using namespace std;

signed main(){
    int n, l;
    cin >> n >> l;
    vector<int> a(n);
    for(int &i : a){
        cin >> i;
    }
    int ans = 0;
    int Minpos = INT_MAX, Maxpos = -INT_MAX;
    for(int i=0; i<n; i++){
        Minpos = min(Minpos,a[i]);
        Maxpos = max(Maxpos,a[i]);
        int Min1 = INT_MAX, Min2 = INT_MAX;
        for(int j=0; j<n; j++){
            if (j==i) continue;
            if (a[j] < a[i]) Min1 = min(Min1,a[i]-a[j]);
            if (a[j] > a[i]) Min2 = min(Min2,a[j]-a[i]);
        }
        if (Min1 == INT_MAX && Min2 == INT_MAX) continue;
        else if (Min1 == INT_MAX && Min2 < INT_MAX) ans = max(ans,Min2);
        else if (Min2 == INT_MAX && Min1 < INT_MAX) ans = max(ans,Min1);
        else ans = max(ans,max(Min1,Min2));
    }
    cout << setprecision(2) << fixed << max((double)ans/2,1.0*max(Minpos,(l-Maxpos)));
}