## 🌳 Binary Trees

### 1. What is a Binary Tree?

A **Binary Tree** is a hierarchical data structure made of **nodes**, where each node can have **at most 2 children**:

* **Left child**
* **Right child**

Unlike arrays, linked lists, stacks, and queues, which are **linear**, trees are **non-linear** and represent hierarchical relationships.

Example:

```text
        1        ← Root
       / \
      2   3      ← Children
     / \
    4   5        ← Leaf nodes
```

### Important Terms

| Term         | Meaning                                      |
| ------------ | -------------------------------------------- |
| **Node**     | Contains data and pointers to children       |
| **Root**     | Topmost node of the tree                     |
| **Parent**   | A node that has one or more children         |
| **Child**    | Node directly connected below a parent       |
| **Leaf**     | Node with no children                        |
| **Ancestor** | Any node on the path from a node to the root |

---

# 2. Types of Binary Trees

### 🔹 Full Binary Tree

Every node has **either 0 or 2 children**.

```text
        1
       / \
      2   3
     / \
    4   5
```

✅ No node has exactly **one child**.

**Remember:**

> Full = **0 or 2 children**

---

### 🔹 Complete Binary Tree

* Every level is completely filled **except possibly the last**.
* The last level is filled **from left to right**.

```text
        1
       / \
      2   3
     / \  /
    4  5 6
```

The last level doesn't have to be full, but there can be **no gaps from the left**.

**Common use:** Heaps.

**Remember:**

> Complete = **filled level-by-level, left to right**

---

### 🔹 Perfect Binary Tree

* Every level is completely filled.
* Every internal node has exactly **2 children**.
* All leaf nodes are at the **same level**.

```text
          1
        /   \
       2     3
      / \   / \
     4   5 6   7
```

**Remember:**

> Perfect = **everything is completely filled**

---

### 🔹 Balanced Binary Tree

The tree is structured so that its height remains relatively small.

A common definition is:

> For every node, the height difference between its left and right subtree is at most **1**.

```text
        1
       / \
      2   3
     / \
    4   5
```

A balanced tree has height approximately:

[
O(\log N)
]

where `N` = number of nodes.

**Remember:**

> Balanced = **left and right subtree heights are close**

---

### 🔹 Degenerate Binary Tree

Each node has only **one child**, so the tree becomes essentially a linked list.

```text
1
 \
  2
   \
    3
     \
      4
```

or

```text
    1
   /
  2
 /
3
/
4
```

Height:

[
O(N)
]

This gives poor performance for many tree operations.

**Remember:**

> Degenerate = **tree behaves like a linked list**

