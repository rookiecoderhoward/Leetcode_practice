#include <bits/stdc++.h>
using namespace std;
vector<int> v;
int arr[3] = {1, 2, 3};
int len = 3;
// �???? - https://www.youtube.com/watch?v=REOH22Xwdkk&t=11s (Neetcode)
void dfs(int depth, vector<int> &ans)
{
    if (depth == len){
        if (ans.empty()){
            cout << "[]" << endl;
            return;
        }
        cout << '[' << ans[0];
        for (int i = 1; i < ans.size(); i++) cout << "," << ans[i];
        cout << ']' << endl;
        return;
    }
    ans.push_back(arr[depth]);
    dfs(depth+1, ans);
    ans.pop_back();
    dfs(depth+1, ans);
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    dfs(0, v);
    return 0;
}
