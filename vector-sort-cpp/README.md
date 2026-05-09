# Vector Sort - HackerRank

## Problem
Given `n` integers, store them in a vector, sort them, and print them in sorted order.

---

## Concept Used
- C++ STL Vector
- `push_back()`
- `sort()` function
- Loops

---

## Approach
1. Read the number of integers `n`
2. Store all integers in a vector using `push_back()`
3. Sort the vector using:
   ```cpp
   sort(v.begin(), v.end());
   ```
4. Traverse the vector and print all elements

---

## Time Complexity
- `O(n log n)` → due to sorting

## Space Complexity
- `O(n)` → vector storage

---

## Code

```cpp
#include <iostream>
#include <vector>
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

    sort(v.begin(), v.end());

    for(int x : v) {
        cout << x << " ";
    }

    return 0;
}
```

Problem : [https://www.hackerrank.com/challenges/vector-sort/problem]