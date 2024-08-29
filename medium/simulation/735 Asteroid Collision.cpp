#include <bits/stdc++.h>
using namespace std;
vector<int> stone; // 存input隕石的vector
// https://www.youtube.com/watch?v=8oOhXcdXbZk (花花)
// stcak, simulation
class Solution {
    public:
        vector<int> asteroidCollision(vector<int>& asteroid) {
            vector<int> s; // 用來模擬的stack
            for (int i = 0; i < asteroid.size(); i++) {
                const int size = asteroid[i];
                if (size > 0) { // To right(向右的隕石), OK
                    s.push_back(size);
                }
                else {
                    // To left(向左的隕石)
                    if (s.empty() || s.back() < 0) // // OK when all are negtives(向左)
                        s.push_back(size);
                    else if (abs(s.back()) <= abs(size)) {
                        // Top of the stack is going right.
                        // Its size is less than the current one.
                    
                        // The current one still alive! 所以必須 i--，繼續使用 current的隕石下去模擬
                        if (abs(s.back()) < abs(size)) i--; 
                        else if (abs(s.back()) == abs(size)) ; // 大小相同 兩者會同時消失

                        s.pop_back(); // Destory the top one moving right
                    }
                }
            }
            return s;
        }
};

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    int n; // n個隕石
    cin >> n;
    for (int i = 0, x; i < n; i++) cin >> x, stone.emplace_back(x);
    Solution solution;
    vector<int> ans = solution.asteroidCollision(stone);
    for (auto &k:ans) {
        cout << k << " ";
    }
    cout << endl;
    return 0;
}
