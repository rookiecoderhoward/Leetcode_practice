#include <bits/stdc++.h>
using namespace std;
// https://www.youtube.com/watch?v=YzZd-bsMthk&list=PLLuMmzMTgVK7vEbeHBDD42pqqG36jhuOr&index=113 (花花)
// 方法與 house robber類似，用滾動數組
class Solution {
    public:
        int rob(const vector<int>& nums){
            int dp1 = 0;
            int dp2 = 0;
            for (int i = 1; i <= nums.size(); i++){
                int dp = max(dp2 + nums[i], dp1);
                dp2 = dp1;
                dp1 = dp;
            }
            return dp1;
        }
};

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    int n;
    cin >> n;
    vector<int> nums;
    for (int i = 0, x; i < n; i++) cin >> x, nums.push_back(x);
    int Max = *max_element(nums.begin(), nums.end());
    vector<int> points(Max+1, 0);
    for (auto num:nums){
        points[num] += num;
    }
    Solution s;
    cout << "Max earns is: " << s.rob(points) << endl;
    return 0;
}
