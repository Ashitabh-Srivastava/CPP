#include <bits/stdc++.h>
using namespace std;


int main() {
    int n;
    cin >> n;
    
    vector <int> nums;
    for(int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        nums.push_back(a);
    }
    
    sort(nums.begin(), nums.end());
    
    for(int j : nums)
    {
        cout << j << " ";
    }
    return 0;
}