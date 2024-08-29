#include <bits/stdc++.h>
using namespace std;
set<string> Myset;
string str;
int n, limit;
// https://www.youtube.com/watch?v=GdJQeTe2LNw&t=152s 花花醬 (use dp + recursion)
// 不用 backtracking，因為遇到 string長度大一點就會馬上 TLE
class Solution {
    public:
        bool dp(string st){
            limit = min(int(st.length()), 20);
            if (Myset.find(st) != Myset.end()) return true;
            for (int i = 0; i < limit; i++){
                if (Myset.find(st.substr(0, i)) != Myset.end() && dp(st.substr(i))) return true;
            }
            return false;
        }
};

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    vector<string> v(n);
    Solution s;
    cout << "Input the string:" << endl;
    cin >> str;
    cout << "Input the Dictionary size:" << endl;
    cin >> n;
    cout << "Input the Dictionary elements:" << endl;
    for (int i = 0; i < n; i++) cin >> str, v.push_back(str);
    for (int i = 0; i < n; i++) Myset.emplace(v[i]);
    if (s.dp(str)) cout << "True" << endl;
    else cout << "False" << endl;
    return 0;
}
