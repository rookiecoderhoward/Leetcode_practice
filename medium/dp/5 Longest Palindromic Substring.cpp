# include <bits/stdc++.h>
using namespace std;
// https://www.youtube.com/watch?v=g3R-pjUNa3k&t=62s (花花)
class Solution {
    public:
        string longestPalindrome(string s) {
            const int n = s.length();
            int len = 0; // 目前最優解的 length
            int start = 0; // 最長回文字串的起始點

            for (int i = 0; i < n; i++) {
                int cur = max(getlengthExpandFromCenter(s, i, i), getlengthExpandFromCenter(s, i, i+1));
                if (cur > len) {
                    len = cur;
                    start = i - (len-1) / 2; // 這行多想想
                }
            }
            return s.substr(start, len); // 從最長回文字串的起始點 數len個char，就是longset palindrome substring
        }
    private:
        int getlengthExpandFromCenter(const string& s, int l, int r) {
            while (l >= 0 && r < s.length() && s[l] == s[r]) {
                l--;
                r++;
            }
            return r-l-1; // 這行多想想 回傳目前這個substring的長度
        }
};

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    Solution solution;
    string s;
    cin >> s;
    cout << solution.longestPalindrome(s) << endl;
    return 0;
}
