#include <bits/stdc++.h>
using namespace std;
vector<int> v;
int arr[4] = {1, 2, 2, 3};
int len = 4;
// method 1 - https://www.youtube.com/watch?v=Vn2v6ajA7U0 (Neetcode)
// method 2 - https://www.youtube.com/watch?v=RIn3gOkbhQE&t=1619s
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
    while (depth+1 < len && arr[depth] == arr[depth+1]) depth += 1;
    dfs(depth+1, ans);
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    dfs(0, v);
}

/* method 2：
#include <bits/stdc++.h>
using namespace std;
vector<int> v;
vector<vector<int>> ans;
int arr[4] = {1, 2, 2, 3};
int len = 4;

void dfs(int now, vector<int> &temp)
{
    ans.push_back(temp);
    for (int i = now; i < len; i++){
        if (i != now && arr[i] == arr[i-1]) continue;
        temp.push_back(arr[i]);
        dfs(i+1, temp);
        temp.pop_back();
    }
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    dfs(0, v);
    for (auto &k:ans){
        if (k.empty()) cout << "[]" << endl;
        else {
            cout << '[' << k[0];
            for (int i = 1; i < k.size(); i++) cout << ',' << k[i];
            cout << ']' << endl;
        } 
    }
}
*/
