#include <iostream>

using namespace std;

void solve(){
    int a, b, c;
    cin >> a >> b >> c;
    if ((a+b+c)%9){
        cout << "NO \n";
        return;
    }
    int enhanced_shot = (a+b+c)/9;
    if (a < enhanced_shot || b < enhanced_shot || c < enhanced_shot || enhanced_shot==0){
        cout << "NO \n";
    }
    else{
        cout << "YES \n";
    }
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
