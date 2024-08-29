#include <bits/stdc++.h>
using namespace std;
int n, reach;
vector<int> v;
// https://www.youtube.com/watch?v=Yan0cv2cLy8 (NeetCode)
int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    while (cin >> n){
        v.push_back(n); 
    }
    reach = v.size()-1;
    for (int i = v.size()-1; i >= 0; i--){
        if (i + v[i] >= reach) reach = i;
    }
    cout << (reach == 0 ? "true" : "false") << endl;
}
