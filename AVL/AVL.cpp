#include <bits/stdc++.h>
using namespace std;

class AVL {
    struct node {
        node* left;
        node* right;
        int val;
        int height;
        node(int num) : left(NULL), right(NULL), val(num), height(0) {};
    };

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

    int balance(node* &root) {
        return (root->left ? root->left->height:0) - (root->right ? root->right->height:0);
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

        root->height = 1 + max((root->left ? root->left->height:0), (root->right ? root->right->height:0));

        if(abs(balance(root)) > 1) {
            if(balance(root) < 0) {
                if(balance(root->right) > 0) root->right = tright(root->right);
                root = tleft(root);
            }
            else {
                if(balance(root->left) < 0) root->left = tleft(root->left);
                root = tright(root);
            }
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
        if(root) {
            root->height = 1 + max((root->left ? root->left->height:0), (root->right ? root->right->height:0));

            if(abs(balance(root)) > 1) {
                if(balance(root) < 0) {
                    if(balance(root->right) > 0) root->right = tright(root->right);
                    root = tleft(root);
                }
                else {
                    if(balance(root->left) < 0) root->left = tleft(root->left);
                    root = tright(root);
                }
            }
        }
    }

    node* tleft(node* root) {
        node* nroot = root->right;
        root->right = nroot->left;
        nroot->left = root;

        root->height = 1 + max((root->left ? root->left->height:0), (root->right ? root->right->height:0));
        nroot->height = 1 + max((nroot->left ? nroot->left->height:0), (nroot->right ? nroot->right->height:0));
        
        return nroot;
    }

    node* tright(node* root) {
        node* nroot = root->left;
        root->left = nroot->right;
        nroot->right = root;

        root->height = 1 + max((root->left ? root->left->height:0), (root->right ? root->right->height:0));
        nroot->height = 1 + max((nroot->left ? nroot->left->height:0), (nroot->right ? nroot->right->height:0));

        return nroot;
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
};