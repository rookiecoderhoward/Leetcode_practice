#include <bits/stdc++.h>
using namespace std;
int l, r = 0; // 用來記錄 max subarray的起點和終點
// https://www.youtube.com/watch?v=7J5rs56JBs8 (花花醬)
// 這邊使用降維dp
class Solution {
    public:
        int maxSubarray(vector<int>& nums) {
            int ans = nums[0];
            int current_sum = nums[0];
            
            for (int i = 1; i < nums.size(); i++) {
                // current_sum = max(current_sum + nums[i], nums[i]);
                if (current_sum + nums[i] < nums[i]) {
                    current_sum = nums[i];
                    l = r = i;
                }
                else if (current_sum + nums[i] > nums[i])
                    current_sum = current_sum + nums[i];

                if (current_sum > ans) {
                    ans = current_sum;
                    r = i;
                }
            }
            return ans;
        }
};

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    vector<int> v = {-2, 1, -3, 4, -1, 2, 1, -5, 4, 2};
    Solution s;
    cout << "Maximum subarray sum is: " << s.maxSubarray(v) << endl;
    cout << "The maximum subarray is: ";
    for (int i = l; i <= r; i++) {
        cout << v[i] << " ";
    }
    return 0;
}

/*
// Author: Huahua
// Runtime: 6 ms (better than 98.66%)
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        vector<int> f(nums.size());
        f[0] = nums[0];
        
        for (int i = 1; i < nums.size(); ++i)
            f[i] = max(f[i - 1] + nums[i], nums[i]);
        
        return *std::max_element(f.begin(), f.end());
    }
};
*/