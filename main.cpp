#include <bits/stdc++.h>
using namespace std;

struct node {
    node* left;
    node* right;
    int val;

    node(int num) : left(NULL), right(NULL), val(num) {}
};

class BST {
    node* root = NULL;

    int small(node* root) {
        while (root->left) {
            root = root->left;
        }

        return root->val;
    }

    int big(node* root) {
        while (root->right) {
            root = root->right;
        }

        return root->val;        
    }

    void preorder(node* root) {
        if(root) {
            cout << root->val << " ";
            preorder(root->left);
            preorder(root->right);
        }
    }

    void inorder(node* root) {
        if(root) {
            inorder(root->left);
            cout << root->val << " ";
            inorder(root->right);
        }
    }

    void postorder(node* root) {
        if(root) {
            postorder(root->left);
            postorder(root->right);
            cout << root->val << " ";
        }
    }

    void insert(node* &root, int num) {
        if(root) {
            if(root->val==num) return;
            else if(root->val>num) insert(root->left, num);
            else if(root->val<num) insert(root->right, num);
        }
        else {
            root = new node(num);
        }
    }

    void erase(node* &root, int num) {
        if(root) {
            if(root->val==num) {
                if(root->left && root->right) {
                    root->val = small(root->right);
                    erase(root->right, root->val);
                }
                else if(root->left) root = root->left;
                else if(root->right) root = root->right;
                else root = NULL;
            }
            else if(root->val>num) erase(root->left, num);
            else if(root->val<num) erase(root->right, num);
        }
        else {
            return;
        }
    }

public:
    void preorder() {
        cout << "Pre-order: ";
        preorder(root);
        cout << endl;
    }

    void inorder() {
        cout << "In-order: ";
        inorder(root);
        cout << endl;
    }

    void postorder() {
        cout << "Post-order: ";
        postorder(root);
        cout << endl;
    }

    void insert(int num) {
        insert(root, num);
    }

    void erase(int num) {
        erase(root, num);
    }

    int big() {
        if(root) return big(root);
        throw runtime_error("Notree");
    }

    int small() {
        if(root) return small(root);
        throw runtime_error("Notree");
    }
};