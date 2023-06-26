#include <iostream>

using namespace std;

int calc(int a, int b, int shovel){
    if (a < shovel*2) return -1;
    if (b < shovel) return -1;
    int lefa = a - shovel*2;
    int lefb = b - shovel;
    return shovel + min(lefb/2,lefa);
}

int calc2(int a, int b, int sword){
    if (a < sword) return -1;
    if (b < sword*2) return -1;
    int lefa = a - sword;
    int lefb = b - sword*2;
    return sword + min(lefb,lefa/2);
}

void solve(){
    int a, b;
    cin >> a >> b;
    cout << min(a,min(b,(a+b)/3)) << '\n';
}

int main()
{
    int t;
    cin >> t;
    while (t--){
        solve();
    }
    return 0;
}
