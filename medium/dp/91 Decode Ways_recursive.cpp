#include <bits/stdc++.h>
using namespace std;
unordered_map<string, int> mp_ways;
string s;
// https://www.youtube.com/watch?v=OjEHST4SXfE&list=PLLuMmzMTgVK7vEbeHBDD42pqqG36jhuOr&index=121 (花花)
// 計畫遞歸
int ways(string str){
    if (mp_ways.count(str)) return mp_ways[str];
    if (str[0] == '0') return 0;
    if (str.length() == 1) return 1; // 這行不能少啊 !!!
    
    int w = ways(str.substr(1));
    const int prefix = (str.substr(0, 2)[0]-'0')*10 + (str.substr(0, 2)[1]-'0');
    if (prefix >= 10 && prefix <= 26) {
        w += ways(str.substr(2));
    }
    mp_ways[str] = w;
    return w;
}

int main(void)
{
    ios::sync_with_stdio(0), cin.tie(0);
    cout << "Input a string: " << endl;
    cin >> s;
    if (s.length() == 0 || s.empty()){
        cout << 0;
        return 0;
    }
    mp_ways[""] = 1; // 這行不能少啊 !!!
    cout << "Decodes ways: " << ways(s) << endl;
}
