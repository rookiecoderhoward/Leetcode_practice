#include <bits/stdc++.h>
using namespace std;
using ll =  long long;
ll dp[1000][2];
ll N, Mod = 1e9+7;
// https://www.youtube.com/watch?v=S-fUTfqrdq8 花花醬 (dynammic programming)超級無敵難
int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> N;
    dp[0][0] = dp[1][0] = 1;
    for (int i = 2; i <= N; i++){
        dp[i][0] = (dp[i-1][0] + dp[i-2][0] + 2 * dp[i-1][1]) % Mod;
        dp[i][1] = (dp[i-2][0] + dp[i-1][1]) % Mod;
    }
    cout << "The number of ways to tile a 2*N board is: " << dp[N][0] << endl;
    return 0;
}
