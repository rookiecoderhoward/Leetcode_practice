#include <bits/stdc++.h>
using namespace std;
vector<int> v;
int n, j;
// https://www.youtube.com/watch?v=8g78yfzMlao (Neetcode)
// 此題難在將 space complexity壓縮至 O(1), time compelxity O(n)
class Solution{
    public: 
        void solve(){
            for (int i = 0; i < n; i++) if (v[i] < 0) v[i] = 0;
            for (int i = 0; i < n; i++){
                int val = abs(v[i]);
                if (1 <= val && val <= n){
                    if (v[val-1] > 0) v[val-1] *= -1;
                    else if (v[val-1] == 0) v[val-1] = -1 * (v.size()+1); // 排除例外情況
                }
            }
            for (j = 1; j <= n; j++){
                if (v[j-1] >= 0) break; // 注意 : >= 0 not > 0
            }
            cout << "The first missing number is: " << j << endl;
        }
};

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> n;
    Solution s;
    for (int i = 0, x; i < n; i++){
        cin >> x;
        v.emplace_back(x);
    }
    s.solve();
}
