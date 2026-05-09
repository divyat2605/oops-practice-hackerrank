# Vector Erase - HackerRank

## Problem Link
[HackerRank - Vector Erase](https://www.hackerrank.com/challenges/vector-erase/problem)

---

## Problem
Given a vector of integers, perform two erase operations:
1. Remove a single element at a given position
2. Remove a range of elements from the updated vector

Finally, print the size and elements of the modified vector.

---

## Concepts Used
- C++ STL Vector
- `push_back()`
- `erase()`
- Iterators
- 0-based indexing
- Range erase in vectors

---

## Approach

### Step 1
Read all integers and store them in a vector.

### Step 2
Erase a single element using:
```cpp
v.erase(v.begin() + (y - 1));
```

We use `(y - 1)` because:
- Input positions are 1-based
- Vector indices are 0-based

---

### Step 3
Erase a range using:
```cpp
v.erase(v.begin() + (a - 1), v.begin() + (b - 1));
```

The erase range works as:
```txt
[start, end)
```

which means:
- start is included
- end is excluded

---

## Time Complexity

### Single erase
```txt
O(n)
```

### Range erase
```txt
O(n)
```

### Overall Complexity
```txt
O(n)
```

---

## Space Complexity
```txt
O(n)
```

for storing vector elements.

---

## Key Learning
- `vector.erase(pos)` removes one element
- `vector.erase(start, end)` removes a range
- STL vectors internally shift elements after erase operations
- Always convert 1-based input positions to 0-based vector indices

---

## Code

```cpp
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
```