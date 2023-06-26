#include <iostream>

using namespace std;

int n, k;
int sum[15];

int main()
{
    cin >> n >> k;
    int Time = 4*60;
    for(int i=1; i<=n; i++) sum[i] = sum[i-1] + i*5;
    int l = 0, r = n;
    while (r>l){
        int mid = (l+r+1)/2;
        if (sum[mid]+k<=Time) l = mid;
        else r = mid-1;
    }
    cout << l;
    return 0;
}
