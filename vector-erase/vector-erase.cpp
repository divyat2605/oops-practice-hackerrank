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

    for(int i = 0; i < n; i++) {
        int x;
        cin >> x;
        v.push_back(x);
    }

    int y;
    cin >> y;

    // erase single element
    v.erase(v.begin() + (y - 1));

    int a, b;
    cin >> a >> b;

    // erase range
    v.erase(v.begin() + (a - 1), v.begin() + (b - 1));

    cout << v.size() << endl;

    for(int x : v) {
        cout << x << " ";
    }

    return 0;
}