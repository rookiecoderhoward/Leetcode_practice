#include <bits/stdc++.h>
using namespace std;
vector<int> v;
int n, k, sum, goal;
int used[10000] = {0};
// https://www.youtube.com/watch?v=mBk4I0X46oI (NeetCode)
// https://www.youtube.com/watch?v=FQ7du5dpgb8 (Huifeng Guan)
class Solution{
    public:
        bool backtrack(int i, int k, int subSum){
            if (k == 0) return true;
            if (subSum == goal) return backtrack(0, k-1, 0);
            for (int j = i; j < n; j++){
                if (used[j] || subSum + v[j] > goal) continue;
                used[j] = 1;
                if (backtrack(i+1, k, subSum + v[j])) return true;
                used[j] = 0;
            }
            return false;
        }
};

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> n >> k;
    for (int i = 0, x; i < n; i++){
        cin >> x;
        sum += x;
        v.emplace_back(x);
    }
    if (sum % k){
        cout << "false" << endl;
        return 0;
    }
    // necessary: 倒序 sort
    sort(v.rbegin(), v.rend());
    goal = sum / k;
    Solution s;
    if (s.backtrack(0, k, 0)) cout << "true" << endl;
    else cout << "false" << endl;
    return 0;
}
