#include <bits/stdc++.h>
using namespace std;
map<char, int> mp;
priority_queue<int> heap; // priority_queue 會由大到小排好
queue<pair<int, int>> q;
char ch;
int n, N, T;
// https://www.youtube.com/watch?v=s8p8ukTyA2I (這題有夠難想)
int main()
{
    cout << "Input the task number:" << endl;
    cin >> N;
    cout << "Input the N tasks:" << endl;
    for (int i = 0; i < N; i++){
        cin >> ch;
        mp[ch]++;
    }
    cout << "Input the cooldown time:" << endl;
    cin >> n; 
    for (auto i:mp){
        heap.push(i.second);
    }
    int ct;
    while (heap.size() || q.size()){
        T++;
        if (heap.size()){
            ct = heap.top()-1;
            if (ct) q.push(make_pair(ct, T + n));
            heap.pop();
        }
        if (q.size() && q.front().second == T){
            heap.push(q.front().first);
            q.pop();
        }
    }
    cout << "The least number of units of times is: " << T << endl;
    return 0;
}
