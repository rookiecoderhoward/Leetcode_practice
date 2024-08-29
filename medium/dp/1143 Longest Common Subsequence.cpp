#include <bits/stdc++.h>
using namespace std;
#define N 1000
int dp[N][N];
string s1, s2, str;
// https://www.youtube.com/watch?v=Ua0GhsJSlWM (Neetcode, 講得很清楚) buttom_up dp
int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    cout << "Inuput two strings: " << endl;
    cin >> s1 >> s2;
    for (int i = s1.length()-1; i >= 0; i--){
        for (int j = s2.length()-1; j >= 0; j--){
            if (s1[i] == s2[j]){
                dp[i][j] = 1 + dp[i+1][j+1];
            }
            else dp[i][j] = max(dp[i+1][j], dp[i][j+1]);
        }
    }
    // 找出 Longest common subsequence 的 string
    int i = 0, j = 0;
    while (i < s1.length() && j < s2.length()){
        if (s1[i] == s2[j]){
            str += s1[i];
            i++, j++;
        }
        else if (dp[i+1][j] >= dp[i][j+1]) i++;
        else j++;
    }
    cout << "Longest common subsequence is: " << str << endl;
    cout << "The length of longest common subsequence is: " << dp[0][0] << endl;
    return 0;
}
