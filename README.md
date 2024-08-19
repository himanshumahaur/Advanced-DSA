# Advanced Data Structures and Algorithms

Welcome to the Advanced Data Structures and Algorithms repository! This repository contains implementations of various advanced data structures and algorithms. Each data structure and algorithm is organized into its own folder with detailed documentation and example usage.

## Available Data Structures

| Data Structure   | Description                                                                 | Link                                        |
|------------------|-----------------------------------------------------------------------------|---------------------------------------------|
| **Binary Search Tree (BST)** | A binary tree where each node has at most two children. Useful for efficient searching, insertion, and deletion. | [BST Docs](BST/README.md)         |
<!-- | **AVL Tree**           | A self-balancing binary search tree that maintains its balance using rotations. Ensures O(log n) height. | [AVL Tree Implementation](AVL/README.md)    |
| **Red-Black Tree**     | A balanced binary search tree with extra properties to ensure O(log n) operations. | [Red-Black Tree Implementation](RedBlackTree/README.md) |
| **B-Trees**            | A self-balancing tree data structure that maintains sorted data and allows searches, sequential access, insertions, and deletions in logarithmic time. | [B-Trees Implementation](BTrees/README.md)  |
| **Fibonacci Heap**     | A data structure for priority queue operations that allows for faster amortized time complexity for decrease-key and merge operations. | [Fibonacci Heap Implementation](FibonacciHeap/README.md) |
| **Binomial Heap**      | A heap data structure that supports mergeable heaps and efficient priority queue operations. | [Binomial Heap Implementation](BinomialHeap/README.md) |
| **Splay Tree**         | A self-adjusting binary search tree with the additional property that recently accessed elements are quick to access again. | [Splay Tree Implementation](SplayTree/README.md) |
| **Interval Tree**      | A data structure to manage intervals and query overlapping intervals efficiently. | [Interval Tree Implementation](IntervalTree/README.md) |

## General Overview

### Binary Search Tree (BST)

- **Description**: A binary tree where each node has at most two children. The left child's value is less than the parent's value, and the right child's value is greater.
- **Key Operations**: Insert, Delete, Search, Pre-order, In-order, Post-order Traversals.
- **Example Usage**: [BST Example](BST/ExampleUsage.md)

### AVL Tree

- **Description**: A self-balancing binary search tree where the difference between the heights of left and right subtrees cannot be more than one.
- **Key Operations**: Insert, Delete, Rotate (left and right), Balance Check.
- **Example Usage**: [AVL Tree Example](AVL/ExampleUsage.md)

### Red-Black Tree

- **Description**: A balanced binary search tree with an additional property of color-coding nodes to ensure balanced height.
- **Key Operations**: Insert, Delete, Balance Fix.
- **Example Usage**: [Red-Black Tree Example](RedBlackTree/ExampleUsage.md)

### B-Trees

- **Description**: A generalization of binary search trees that can have more than two children per node and is optimized for systems that read and write large blocks of data.
- **Key Operations**: Insert, Delete, Search, Split, Merge.
- **Example Usage**: [B-Trees Example](BTrees/ExampleUsage.md)

### Fibonacci Heap

- **Description**: A data structure for priority queue operations that supports better amortized time complexities for operations like merge and decrease-key.
- **Key Operations**: Insert, Extract-Min, Decrease-Key, Merge.
- **Example Usage**: [Fibonacci Heap Example](FibonacciHeap/ExampleUsage.md)

### Binomial Heap

- **Description**: A collection of binomial trees that provides efficient merging of heaps.
- **Key Operations**: Insert, Extract-Min, Union.
- **Example Usage**: [Binomial Heap Example](BinomialHeap/ExampleUsage.md)

### Splay Tree

- **Description**: A self-adjusting binary search tree that performs rotations to move recently accessed elements closer to the root.
- **Key Operations**: Insert, Delete, Access.
- **Example Usage**: [Splay Tree Example](SplayTree/ExampleUsage.md)

### Interval Tree

- **Description**: A data structure to efficiently query overlapping intervals.
- **Key Operations**: Insert, Query Overlaps.
- **Example Usage**: [Interval Tree Example](IntervalTree/ExampleUsage.md) -->

## Getting Started

To get started with any data structure, navigate to its respective folder and refer to the `README.md` file within that folder for detailed instructions and examples.

## Contribution

Contributions are welcome! Please refer to the `CONTRIBUTING.md` file for guidelines on how to contribute to this repository.

## License

This project is licensed under the MIT License. See the [LICENSE](LICENSE) file for details.

---

Feel free to explore the repository and learn more about advanced data structures and algorithms!
