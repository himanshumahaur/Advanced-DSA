# Adelson-Velsky and Landis (AVL) Tree

This repository provides a C++ implementation of an AVL Tree, a self-balancing binary search tree. It supports basic operations such as insertion, deletion, and various tree traversals.

## Features

| Function       | Description                                      |
|----------------|--------------------------------------------------|
| `insert(num)`  | Adds a value to the AVL tree.                    |
| `erase(num)`   | Removes a value from the AVL tree.               |
| `preorder()`   | Prints the AVL tree nodes in pre-order traversal.|
| `inorder()`    | Prints the AVL tree nodes in in-order traversal. |
| `postorder()`  | Prints the AVL tree nodes in post-order traversal.|

## Traversal Results

The following tree traversal methods are implemented:

- **Pre-order Traversal**: Visits nodes in the order of root, left subtree, right subtree.
- **In-order Traversal**: Visits nodes in the order of left subtree, root, right subtree.
- **Post-order Traversal**: Visits nodes in the order of left subtree, right subtree, root.

## Traversal Results

| Traversal   | Result          |
|-------------|-----------------|
| **Pre-order** | 2 1 5 4 6       |
| **In-order**  | 1 2 4 5 6       |
| **Post-order**| 1 4 6 5 2       |

## Example Usage

```cpp
int main() {
    AVL T;

    // Insert values
    T.insert(4);
    T.insert(2);
    T.insert(1);
    T.insert(6);
    T.insert(5);

    // Display traversals
    cout << "Initial tree:" << endl;
    T.preorder();  // Output: 2 1 5 4 6
    T.inorder();   // Output: 1 2 4 5 6
    T.postorder(); // Output: 1 4 6 5 2

    // Erase a value and display traversals
    T.erase(2);
    cout << "After erasing 2:" << endl;
    T.preorder();  // Output: 4 1 6 5
    T.inorder();   // Output: 1 4 5 6
    T.postorder(); // Output: 1 6 5 4

    return 0;
}
```