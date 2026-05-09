# C++ Lower Bound - STL (HackerRank)

## 🔗 Problem Link
https://www.hackerrank.com/challenges/cpp-lower-bound/problem?isFullScreen=true

---

## 📌 Problem Statement

You are given a sorted array of integers and multiple queries.  
For each query:

- If the number exists in the array → print `"Yes"` and its **first 1-based index**
- If it does not exist → print `"No"` and the **index of the next greater element**

You must use **lower_bound (STL)** to solve this efficiently.

---

## 💡 Concept Used

### 🔹 `lower_bound`
- Returns an iterator pointing to:
  - First element ≥ target
- Works only on **sorted containers**

---

## ⚙️ Approach

For each query:
1. Use `lower_bound(v.begin(), v.end(), x)`
2. Convert iterator to index: `it - v.begin()`
3. Check:
   - If `*it == x` → element found
   - Else → element not found, but `it` gives next greater position
4. Print 1-based index (`+1`)

---

## ⏱ Complexity

- Each query: **O(log N)**
- Total: **O(Q log N)**

---

## 📚 Key Learning

- STL `lower_bound`
- Iterator usage
- Binary search on sorted vectors