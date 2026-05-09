# `std::lower_bound()` in C++ — Complete Guide

> A beginner-friendly to advanced explanation of iterators, binary search in STL, `lower_bound()`, `upper_bound()`, time & space complexity, and competitive programming usage.

---

## Table of Contents

1. [What is lower_bound()?](#1-what-is-lower_bound)
2. [Syntax](#2-syntax)
3. [What is an Iterator?](#3-what-is-an-iterator)
4. [begin() and end()](#4-begin-and-end)
5. [How lower_bound Works](#5-how-lower_bound-works)
6. [Internal Logic (Binary Search)](#6-internal-logic-binary-search)
7. [Examples](#7-examples)
8. [lower_bound vs upper_bound](#8-lower_bound-vs-upper_bound)
9. [Time Complexity](#9-time-complexity)
10. [Space Complexity](#10-space-complexity)
11. [Common Use Cases](#11-common-use-cases)
12. [Full Working Example](#12-full-working-example)
13. [Key Takeaways](#13-key-takeaways)

---

## 1. What is `lower_bound()`?

`std::lower_bound()` is a C++ STL algorithm that performs **binary search** on a **sorted range**.

It returns an **iterator** pointing to:

> **The first element that is NOT LESS THAN (`>=`) the given value.**

In other words — it finds the leftmost position where `value` could be inserted without breaking sorted order.

---

## 2. Syntax

```cpp
lower_bound(first, last, value);
```

**Parameters:**

| Parameter | Description |
|-----------|-------------|
| `first`   | Iterator to the beginning of the range |
| `last`    | Iterator to one past the end of the range |
| `value`   | The value to search for |

**Example:**

```cpp
vector<int> v = {10, 20, 30, 40};
auto it = lower_bound(v.begin(), v.end(), 25);
// Result → points to 30
```

---

## 3. What is an Iterator?

An **iterator** is like a smart pointer used to traverse containers like `vector`, `set`, `map`, etc.

Think of it as a **position** (or cursor) inside a container.

```cpp
// Classic syntax
vector<int>::iterator it = v.begin();

// Modern (preferred)
auto it = v.begin();

// Access the value at that position
*it;      // dereference → gives the value

// Move the iterator forward
it++;     // advance to next element
```

Iterators allow STL algorithms like `lower_bound` to work uniformly across **all container types** — not just arrays.

---

## 4. `begin()` and `end()`

### `begin()`

Points to the **first element** of the container:

```
[10, 20, 30]
  ^
begin()
```

### `end()`

Points to **one past the last element** (a sentinel — it does NOT point to valid data):

```
[10, 20, 30]
             ^
            end()
```

> ⚠️ Never dereference `end()` — it's out of bounds.

---

## 5. How `lower_bound` Works

It finds the **first element `>= target`** in a **sorted** range.

```cpp
vector<int> v = {1, 2, 4, 4, 4, 5, 7};
auto it = lower_bound(v.begin(), v.end(), 4);
```

Result:

```
1  2  4  4  4  5  7
      ^
      first element >= 4
```

> ⚠️ **Important:** `lower_bound` only works correctly on **sorted data**. On unsorted data, results are undefined.

---

## 6. Internal Logic (Binary Search)

Internally, `lower_bound` runs a **binary search** — not a linear scan:

```
Start: lo = begin, hi = end

At each step:
  mid = (lo + hi) / 2

  if v[mid] < value  →  lo = mid + 1   (go right)
  else               →  hi = mid        (go left, mid might be the answer)

Repeat until lo == hi → that's your answer.
```

This is why it only works on **sorted** arrays, and why it achieves **O(log n)** time.

---

## 7. Examples

### Example 1 — Exact match exists

```cpp
vector<int> v = {10, 20, 30, 40};
auto it = lower_bound(v.begin(), v.end(), 20);
// *it == 20  (points directly to 20)
```

### Example 2 — Value not present (gap)

```cpp
auto it = lower_bound(v.begin(), v.end(), 25);
```

```
10  20  30  40
        ^
Returns iterator to 30 (first element >= 25)
```

### Example 3 — Value larger than all elements

```cpp
auto it = lower_bound(v.begin(), v.end(), 100);
// Returns v.end()
```

> Always check `it != v.end()` before dereferencing!

---

## 8. `lower_bound` vs `upper_bound`

| Function | Returns |
|----------|---------|
| `lower_bound(first, last, x)` | Iterator to **first element `>= x`** |
| `upper_bound(first, last, x)` | Iterator to **first element `> x`** |

**Visual example** with `{1, 2, 4, 4, 4, 5}`:

```
lower_bound(v, 4):          upper_bound(v, 4):

1  2  4  4  4  5            1  2  4  4  4  5
      ^                                   ^
first >= 4                  first > 4
```

Together they define the **range of all occurrences** of a value:

```cpp
auto lo = lower_bound(v.begin(), v.end(), 4);
auto hi = upper_bound(v.begin(), v.end(), 4);
// [lo, hi) spans all 4s in the vector
```

---

## 9. Time Complexity

`lower_bound` uses binary search internally:

| Case | Complexity |
|------|------------|
| Always | **O(log n)** |

Very fast — even for `n = 10^9`, it takes at most ~30 comparisons.

> ⚠️ Exception: If used on `std::list` or other non-random-access iterators, it degrades to **O(n)** because pointer arithmetic (`mid = lo + n/2`) isn't O(1) for those.

---

## 10. Space Complexity

| | Complexity |
|-|------------|
| Extra memory used | **O(1)** |

`lower_bound` operates entirely in-place — no auxiliary arrays or recursion stack.

---

## 11. Common Use Cases

### 1. Check if a value exists

```cpp
auto it = lower_bound(v.begin(), v.end(), x);
if (it != v.end() && *it == x)
    cout << "Found at index " << (it - v.begin());
```

### 2. Count frequency of a value

```cpp
int count = upper_bound(v.begin(), v.end(), x)
          - lower_bound(v.begin(), v.end(), x);
```

### 3. Insert while keeping sorted order

```cpp
v.insert(lower_bound(v.begin(), v.end(), x), x);
```

### 4. Get the index (not iterator)

```cpp
int index = lower_bound(v.begin(), v.end(), x) - v.begin();
```

### 5. Find smallest element >= x (competitive programming)

```cpp
// "What's the cheapest item that costs at least x?"
auto it = lower_bound(prices.begin(), prices.end(), x);
if (it != prices.end())
    cout << "Cheapest valid price: " << *it;
```

---

## 12. Full Working Example

```cpp
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    vector<int> v = {10, 20, 20, 20, 30, 40};

    // lower_bound: first element >= 20
    auto lo = lower_bound(v.begin(), v.end(), 20);

    // upper_bound: first element > 20
    auto hi = upper_bound(v.begin(), v.end(), 20);

    cout << "lower_bound value : " << *lo << endl;
    cout << "lower_bound index : " << (lo - v.begin()) << endl;

    cout << "upper_bound value : " << *hi << endl;
    cout << "upper_bound index : " << (hi - v.begin()) << endl;

    cout << "Count of 20s      : " << (hi - lo) << endl;

    return 0;
}
```

**Output:**

```
lower_bound value : 20
lower_bound index : 1
upper_bound value : 30
upper_bound index : 4
Count of 20s      : 3
```

---

## 13. Key Takeaways

| Concept | Detail |
|---------|--------|
| `lower_bound` returns | First element **`>= target`** |
| Prerequisite | Array/range must be **sorted** |
| Return type | **Iterator** (not index) |
| Get value | `*it` |
| Get index | `it - v.begin()` |
| Not found | Returns `v.end()` |
| Time complexity | **O(log n)** |
| Space complexity | **O(1)** |

---

### Final Thought

Once you understand **iterators**, **binary search**, and **`lower_bound` / `upper_bound`** — a huge portion of STL-based competitive programming problems become straightforward. These three primitives unlock: existence checks, frequency counts, sorted insertions, range queries, and much more.

---

*Header: `#include <algorithm>` — Required for `lower_bound` and `upper_bound`.*