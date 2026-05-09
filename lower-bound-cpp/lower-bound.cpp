# Solution - C++ Lower Bound STL


#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    
    int n;
    cin >> n;
    
    vector<int> v;
    
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        v.push_back(x);
    }
    
    int q;
    cin >> q;
    
    while (q--) {
        int x;
        cin >> x;
        
        auto it = lower_bound(v.begin(), v.end(), x);
        int pos = it - v.begin();
        
        if (*it == x) {
            cout << "Yes " << pos + 1 << endl;
        } else {
            cout << "No " << pos + 1 << endl;
        }
    }
    
    return 0;
}