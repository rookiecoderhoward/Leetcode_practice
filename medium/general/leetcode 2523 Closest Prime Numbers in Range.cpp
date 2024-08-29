#include <bits/stdc++.h>
using namespace std;
vector<int> ans;
int Left, Right;
int cmp = INT_MAX, last = INT_MIN;
// https://www.youtube.com/watch?v=UX5RR825b-o&t=1s
int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    cout << "Please input left and right bounds:" << endl;
    cin >> Left >> Right;
    vector<int> prime(Right + 1, 1);
    prime[0] = prime[1] = 0;
    for (int i = 2; i <= sqrt(Right); i++){
        if (!prime[i]) continue;
        for (int j = i*i; j <= Right; j += i) prime[j] = 0;
    }
    for (int i = Left; i <= Right; i++){
        if (!prime[i]) continue;
        if (last > 0 && i - last < cmp){
            cmp = i - last;
            ans = {last, i};
        }
        last = i;
    }
    if (!ans.size()) cout << "[-1, -1]" << endl;
    else cout << '[' << ans[0] << ", " << ans[1] << ']' << endl;
    return 0;
}
