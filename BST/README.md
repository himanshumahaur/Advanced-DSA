# Binary Search Tree (BST)

This repository provides a C++ implementation of a Binary Search Tree (BST) with basic operations and functionalities.

## Features

| Function       | Description                                      |
|----------------|--------------------------------------------------|
| `insert(num)`  | Adds a value to the BST.                         |
| `erase(num)`   | Removes a value from the BST.                    |
| `preorder()`   | Prints the BST nodes in pre-order traversal.     |
| `inorder()`    | Prints the BST nodes in in-order traversal.      |
| `postorder()`  | Prints the BST nodes in post-order traversal.    |
| `small()`      | Returns the smallest value in the BST. Throws exception if empty. |
| `big()`        | Returns the largest value in the BST. Throws exception if empty. |

## Visuals

### Example Tree Structure

```plaintext
       4
      / \
     2   6
    /   /
   1   5
```

## Traversal Results

| Traversal   | Result          |
|-------------|-----------------|
| **Pre-order** | 4 2 1 6 5       |
| **In-order**  | 1 2 4 5 6       |
| **Post-order**| 1 2 5 6 4       |

## Example Usage

```cpp
int main() {
    BST T;

    // Insert values
    T.insert(4);
    T.insert(2);
    T.insert(1);
    T.insert(6);
    T.insert(5);

    // Display traversals
    cout << "Initial tree:" << endl;
    T.preorder();  // Output: 4 2 1 6 5
    T.inorder();   // Output: 1 2 4 5 6
    T.postorder(); // Output: 1 2 5 6 4

    // Find and display smallest and largest values
    try {
        cout << "Smallest value: " << T.small() << endl; // Output: 1
        cout << "Largest value: " << T.big() << endl;    // Output: 6
    } catch (const runtime_error& e) {
        cout << "Exception: " << e.what() << endl;
    }

    // Erase a value and display traversals
    T.erase(2);
    cout << "After erasing 2:" << endl;
    T.preorder();  // Output: 4 1 6 5
    T.inorder();   // Output: 1 4 5 6
    T.postorder(); // Output: 1 5 6 4

    // Display smallest and largest values after deletion
    try {
        cout << "Smallest value: " << T.small() << endl; // Output: 1
        cout << "Largest value: " << T.big() << endl;    // Output: 6
    } catch (const runtime_error& e) {
        cout << "Exception: " << e.what() << endl;
    }

    return 0;
}