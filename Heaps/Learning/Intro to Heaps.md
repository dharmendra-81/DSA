# **Priority Queue & Binary Heap **

---

## 1. Priority Queue

A **Priority Queue** is a special queue where elements are processed based on **priority**, not insertion order.

* Higher priority element is removed first.
* If priorities are equal, insertion order is followed.

### Applications

* CPU Task Scheduling
* Dijkstra's Algorithm
* Prim's Algorithm
* Event Simulation
* Operating Systems
* Real-time Systems

---

## 2. Binary Heap

A **Binary Heap** is a **Complete Binary Tree** that satisfies the **Heap Property**.

It is the most common implementation of a Priority Queue.

---

## 3. Properties of Binary Heap

### (A) Complete Binary Tree

* Every level is completely filled except possibly the last.
* Last level is filled from **left to right**.

### (B) Heap Property

### Min Heap

* Parent ≤ Children
* Root contains the **smallest** element.

### Max Heap

* Parent ≥ Children
* Root contains the **largest** element.

---

## 4. Array Representation

Instead of pointers, heaps are stored in an array.

If current node is at index **i**

| Relation    | Formula |
| ----------- | ------- |
| Parent      | (i−1)/2 |
| Left Child  | 2i+1    |
| Right Child | 2i+2    |

Root is always at index **0**.

---

## 5. Operations on Min Heap

---

## 1. Insert(x)

### Steps

1. Insert element at the last position.
2. Complete Binary Tree property remains valid.
3. Compare with parent.
4. If parent > child, swap.
5. Continue until heap property is restored.

This upward movement is called **Heapify Up (Bubble Up)**.

### Time Complexity

**O(log N)**

---

## 2. Heapify (Heapify Down)

Used when a node violates the heap property.

### Steps

1. Compare node with left and right child.
2. Find the smallest.
3. Swap with smallest child.
4. Repeat recursively.

Used after deleting the root or building a heap.

### Time Complexity

**O(log N)**

---

## 3. getMin()

Simply return the root.

```cpp
arr[0]
```

### Time Complexity

**O(1)**

---

## 4. ExtractMin()

Removes the smallest element (root).

### Steps

1. Store root.
2. Copy last element to root.
3. Reduce heap size.
4. Heapify from root.

This restores heap property.

### Time Complexity

**O(log N)**

---

## 5. DecreaseKey(index, newValue)

Decrease the value of a node.

### Steps

1. Update value.
2. Compare with parent.
3. If parent is larger, swap.
4. Repeat until heap property is restored.

### Time Complexity

**O(log N)**

---

## 6. Delete(index)

Delete any node in the heap.

### Steps

1. Change value to **INT_MIN**.
2. Call **DecreaseKey()** so it reaches the root.
3. Call **ExtractMin()** to remove it.

### Time Complexity

**O(log N)**

---

# 6. Time Complexity Table

| Operation   | Complexity   |
| ----------- | ------------ |
| Insert      | **O(log N)** |
| Heapify     | **O(log N)** |
| getMin      | **O(1)**     |
| ExtractMin  | **O(log N)** |
| DecreaseKey | **O(log N)** |
| Delete      | **O(log N)** |

---

# 7. Important Interview Points

* Priority Queue is usually implemented using a **Binary Heap**.
* Binary Heap is always a **Complete Binary Tree**.
* **Min Heap:** Root is the minimum element.
* **Max Heap:** Root is the maximum element.
* **Insert** and **DecreaseKey** use **Heapify Up**.
* **ExtractMin** and **Delete** use **Heapify Down**.
* Heap is stored efficiently in an array, so no pointers are required.




