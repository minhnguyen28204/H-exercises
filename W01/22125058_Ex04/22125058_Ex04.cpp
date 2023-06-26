#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;
    int* arr;
    arr = new int[n+1];
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }
    int len1 = 0, len2 = 0;
    int pre = -1;
    int ans = 0;
    for(int i=0; i<n; i++){
        if (arr[i]!=pre){
            ans = max(ans,min(len1,len2)*2);
            len1 = len2;
            len2 = 1;
            pre = arr[i];
        }
        else{
            len2++;
        }
    }
    ans = max(ans,min(len1,len2)*2);
    cout << ans;
    delete[] arr;
    return 0;
}
