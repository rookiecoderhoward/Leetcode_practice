#include <bits/stdc++.h>
using namespace std;
vector<int> stock;
// https://www.youtube.com/watch?v=8pVhUpF1INw&t=1s (花花)
// 另一種做法是用 maximum subarray(相對更高效節省空間)
class Solution {
    public:
        int maxProfit(vector<int>& prices) {
            const int n = prices.size();
            if (n < 1) return 0;
            vector<int> max_profit(n);
            vector<int> min_price(n);
            min_price[0] = prices[0]; // min_price[0]不是0喔 別搞錯
            max_profit[0] = 0;
            for (int i = 1; i < n; i++) {
                min_price[i] = min(min_price[i-1], prices[i]);
                max_profit[i] = max(max_profit[i-1], prices[i] - min_price[i-1]);
            }
            return max_profit[n-1];
        }
};

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    int n;
    cin >> n;
    for (int i = 0, x; i < n; i++) cin >> x, stock.push_back(x);
    Solution solution;
    cout << solution.maxProfit(stock) << endl;
    return 0;
}
