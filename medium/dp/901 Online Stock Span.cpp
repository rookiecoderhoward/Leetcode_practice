#include <bits/stdc++.h>
using namespace std;
// https://www.youtube.com/watch?v=RGRC46zHB98&list=PLLuMmzMTgVK6-w5poVP89Kl38S9UryDHx&index=91 (花花)
// https://zxi.mytechroad.com/blog/stack/leetcode-901-online-stock-span/ (程式碼)
class StockSpanner {

    public:
        int next(int price) {
            int span = 1; // 這個必須寫在function內部啊 ! 不然數字會跑掉
            while (!s_.empty() && price >= s_.top().first) { //是 && and price >= s_.top().first要寫在後面
                span += s_.top().second;
                s_.pop();
            }
            s_.push(make_pair(price, span));
            return span;
        }
    private:
        stack<pair<int, int>> s_; // {price, span}, ordered by price DESC.
};

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    StockSpanner sp;
    int n;
    cin >> n;
    vector<int> v; // 存所有的stock
    for (int i = 0, x; i < n; i++) cin >> x, v.push_back(x);
    for (int i = 0; i < n; i++) {
        cout << sp.next(v[i]) << " ";
    }
    cout << endl;
    return 0;
}
