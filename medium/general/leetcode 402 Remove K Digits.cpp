#include <bits/stdc++.h>
using namespace std;
vector<char> v;
string s, str;
int k, flag = 1; 
// https://www.youtube.com/watch?v=cFabMOnJaq0&list=PLot-Xpze53lfxD6l5pAGvCD4nPvWKU8Qo&index=19
int main()
{
    cout << "The number is: ";
    cin >> s;
    cout << "k is: ";
    cin >> k;
    for (int i = 0; i < s.length(); i++){
        while (k > 0 && !v.empty() && v[v.size()-1] > s[i]){
            v.pop_back();
            k -= 1;
        }
        v.emplace_back(s[i]); 
    }
    // 這行重要
    for (int i = k; i > 0; i--) v.pop_back();
    if (!v.size()) cout << "The answer is: " << '0' << endl;
    else {
        bool check = false;
        if (v[0] == '0'){
            for (int i = 0; i < v.size(); i++){
                if (v[i] == '0' && !check) continue;
                else {
                    check = true;
                    str += v[i];
                }
            }
        }
        else for (int i = 0; i < v.size(); i++) str += v[i];
        // 檢查是否 v裡面全是'0'
        for (auto &k:v){
            if (k != '0'){
                flag = 0; // 表示有不為'0'的數字
                break;
            }
        }
        if (flag) cout << "The answer is: " << '0' << endl;
        else cout << "The answer is: " << str << endl;
    }
    return 0;
}
