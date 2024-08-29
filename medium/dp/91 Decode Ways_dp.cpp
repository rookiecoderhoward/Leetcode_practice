#include <bits/stdc++.h>
using namespace std;
string s;
// https://www.youtube.com/watch?v=OjEHST4SXfE&list=PLLuMmzMTgVK7vEbeHBDD42pqqG36jhuOr&index=121 (花花)
// 滾動降維數組 dp，空間:O(n) -> O(1)
class Solution {
    public:
        int numDecoding(string str){
            if (str.empty() || str[0] == '0') return 0;
            if (str.length() == 1) return 1;
            int w2 = 1; // dp[i-2]，初始代表為 dp[-1]
            int w1 = 1; // dp[i-1]，初始代表為 dp[0]
            for (int i = 1; i < str.length(); i++){
                int w = 0; // 紀錄 dp[i]
                // 這三行 if很重要，多複習 !!!
                if (!isValid(str[i]) && !isValid(str[i-1], str[i])) return 0;
                if (isValid(str[i])) w = w1;
                if (isValid(s[i-1], s[i])) w += w2;
                w2 = w1;
                w1 = w;
            }
            return w1; // 最後是 w1 = w, so return w1;
        }
    private:
        bool isValid(const char ch){ return ch != '0';}
        bool isValid(const char c1, const char c2){
            const int num = 10*(c1-'0') + (c2-'0');
            return (num >= 10 && num <= 26);
        }
};

int main(void)
{
    ios::sync_with_stdio(0), cin.tie(0);
    Solution solution;
    cout << "Input a string: " << endl;
    cin >> s;
    cout << "Decodes ways: " << solution.numDecoding(s) << endl;
}
