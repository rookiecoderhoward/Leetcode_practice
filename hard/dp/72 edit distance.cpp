#include <bits/stdc++.h>
using namespace std;
#define N 1000
int dp[N][N];
string s1, s2;
// https://www.youtube.com/watch?v=XYi2-LPrwm4 (Neetcode)
// 似 LCS，但概念麻煩了不少，一樣為 buttom_up dp
int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    cout << "Input word1 and word2: " << endl;
    cin >> s1 >> s2;
    // 多看幾次 Neetcode的 explain，才會明白
    for (int j = s2.length(); j >= 0; j--) dp[s1.length()][j] = s2.length() - j;
    for (int i = s1.length(); i >= 0; i--) dp[i][s2.length()] = s1.length() - i;
    for (int i = s1.length(); i >= 0; i--){
        for (int j = s2.length(); j >= 0; j--){
            if (s1[i] == s2[j]) dp[i][j] = dp[i+1][j+1];
            else dp[i][j] = 1 + min({dp[i+1][j], dp[i][j+1], dp[i+1][j+1]}); // 別忘了要 +1
        }
    }
    cout << "Edit distance is: " << dp[0][0] << endl;
    return 0;
}
/*
想法: <影片會解說>
    if (w1[i] == w2[j]) 
        (i+1, j+1)
    else {
        insert: (i, j+1)
        delete: (i+1, j)
        replace: (i+1, j+1)
    }
*/
