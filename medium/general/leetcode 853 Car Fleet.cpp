#include <bits/stdc++.h>
using namespace std;
vector<double> fleet;
int target, n;
// https://www.youtube.com/watch?v=Pr6T-3yB9RM&t=2s (NeetCode) ps:這題著重理解觀念，多重複看解釋
int main()
{
    cout << "Target: ";
    cin >> target;
    cout << "Number of cars: ";
    cin >> n;
    vector<pair<int, int>> v(n); // position, speed
    cout << "Position: ";
    for (int i = 0, x; i < v.size(); i++){
        cin >> x;
        v[i].first = x;
    }
    cout << "Speed: ";
    for (int i = 0, x; i < v.size(); i++){
        cin >> x;
        v[i].second = x;
    }
    sort(v.rbegin(), v.rend());
    for (auto &k:v){
        fleet.push_back(double(target-k.first) / double(k.second));
        if (fleet.size() > 1 && fleet[fleet.size()-1] <= fleet[fleet.size()-2]) fleet.pop_back();
    }
    cout << "The total number of car fleets is : " << fleet.size() << endl;
}
