#include <bits/stdc++.h>
using namespace std;
#define N 1000
int dp[N];
int n;
// https://www.youtube.com/watch?v=H75Qp7ExCwo&list=PLLuMmzMTgVK7vEbeHBDD42pqqG36jhuOr&index=116 (花花醬)
// dp way, recursive way在影片也有說明 自己去看
int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    cout << "Input # of houses: " << endl;
    cin >> n;
    vector<int> v(n, 0);
    cout << "Input the money of each house has: " << endl;
    for (int i = 0; i < n; i++) cin >> v[i];
    for (int i = 0; i < n; i++){
        dp[i] = max((i > 1 ? dp[i-2] : 0) + v[i], (i > 0 ? dp[i-1] : 0));
    }
    cout << "The maximum money can be robbed is: " << dp[n-1] << endl;
}
