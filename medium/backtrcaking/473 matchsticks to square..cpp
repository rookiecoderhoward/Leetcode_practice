#include <bits/stdc++.h>
using namespace std;
vector<int> sticks;
int sides[4] = {0}; // 上下左右 4個邊
int len, n, sum = 0;
// https://www.youtube.com/watch?v=hUe0cUKV-YY (Neetcode)，跟 leetcode 698 超像 (多想 !)
bool backtrack(int i) {
    if (i == sticks.size()) 
        return true;
    for (int j = 0; j < 4; j++) {
        if (sides[j] + sticks[i] <= len) {
            sides[j] += sticks[i];
            if (backtrack(i+1)) 
                return true;
            sides[j] -= sticks[i];
        }
    }
    return false;
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> n;
    for (int i = 0, x; i < n; i++) {
        cin >> x;
        sticks.emplace_back(x);
        sum += x;
    }
    if (sum % 4 != 0) {
        cout << "false" << endl;
        return 0;
    }
    // 必須要倒序 sort !!!
    sort(sticks.rbegin(), sticks.rend());
    len = sum / 4; // 正方形邊長
    cout << (backtrack(0) ? "true" : "false") << endl;
    return 0;
}
