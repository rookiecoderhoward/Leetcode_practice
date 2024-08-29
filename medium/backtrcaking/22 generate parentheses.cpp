#include <bits/stdc++.h>
using namespace std;
vector<string> ans;
string str;
int n, ct;
// https://www.youtube.com/watch?v=s9fokUqJ76A (NeetCode)
void dfs(int openN, int closedN, string temp){
    if (openN == n && closedN == n){
        if (!ct) cout << "\"" << temp << "\"" << endl;
        else cout << ", \"" << temp << "\"" << endl;
        return;
    }
    if (openN < n){
        dfs(openN + 1, closedN, temp + '(');
    }
    if (closedN < openN){
        dfs(openN, closedN + 1, temp + ')');
    }
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> n;
    dfs(0, 0, str);
    return 0;
}
