#include <bits/stdc++.h>
using namespace std;

enum Colour
{
    RED,
    BLACK
};

struct Node
{
    int v;

    Node *l;
    Node *r;
    Node *p;

    Colour c = RED;

    Node(int v, Node *&p) : v(v), l(NULL), r(NULL), p(p) {}
};

class RBT
{
public:
    Node *root = NULL;

    bool uisr(Node *&root) {
        if(root->p && root->p->p) {
            Node* p = root->p;
            Node* gp = root->p->p;
            if(gp->l==p && gp->r->c==RED) return true;
            if(gp->l!=p && gp->l->c==RED) return true;
        }
        return false;
    }

    bool uisb(Node *&root) {
        if(root->p && root->p->p) {
            Node* p = root->p;
            Node* gp = root->p->p;
            if(gp->l==p && gp->r->c==BLACK) return true;
            if(gp->l!=p && gp->l->c==BLACK) return true;
        }
        return false;
    }

    Node* tleft(Node* root) {
        Node* nroot = root->r;
        root->r = nroot->l;
        nroot->l = root;
        return nroot;
    }

    Node* tright(Node* root) {
        Node* nroot = root->l;
        root->l = nroot->r;
        nroot->r = root;
        return nroot;
    }

    void insert(Node *&root, Node *p, int v)
    {
        if (root)
        {
            if (root->v > v)
            {
                insert(root->l, root, v);
            }
            else if (root->v < v)
            {
                insert(root->r, root, v);
            }
            else
            {
                return;
            }
        }
        else
        {
            root = new Node(v, p);
            
            if(p==NULL) {
                root->c = BLACK;
                return;
            }
            else if(uisr(root)) {
                Node* gp = root->p->p;
                gp->c = RED;
                gp->l->c = BLACK;
                gp->r->c = BLACK;
                return;
            }
            else if(uisb(root)) {
                Node* p = root->p;
                Node* gp = root->p->p;

                if(gp->r!=p && p->r==root) {
                    root->p = tleft(root->p);
                }
                else if(gp->l!=p && p->l==root) {
                    root->p = tright(root->p);
                }
                else if(gp->r==p && p->r==root) {
                    p->c = BLACK;
                    gp->c = RED;
                    root->p->p = tleft(root->p->p);
                }
                else if(gp->l==p && p->l==root) {
                    p->c = BLACK;
                    gp->c = RED;
                    root->p->p = tright(root->p->p);
                }
                
                return;
            }
        }
    }

    void print(Node *root)
    {
        if (root)
        {
            cout << root->v << " ";
            print(root->l);
            print(root->r);
        }
    }

    Node *find(Node *root, int v)
    {
        if (root)
        {
            if (root->v == v)
            {
                return root;
            }
            else if (root->v < v)
            {
                return find(root->r, v);
            }
            else if (root->v > v)
            {
                return find(root->l, v);
            }
        }
    }

public:
    void insert(int v)
    {
        insert(root, NULL, v);
    }

    void print()
    {
        cout << "Values: ";
        print(root);
        cout << endl;
    }

    Node *find(int v)
    {
        return find(root, v);
    }
};

#define COUNT 10

void print2DUtil(Node *root, int space)
{
    if (root == NULL)
        return;

    space += COUNT;

    print2DUtil(root->r, space);

    cout << endl;
    for (int i = COUNT; i < space; i++)
        cout << " ";
    cout << root->v << "\n";

    print2DUtil(root->l, space);
}

void print2D(Node *root)
{
    print2DUtil(root, 0);
}

int main()
{
    RBT T;

    T.insert(15);
    T.insert(5);
    T.insert(1);

// B = 1
// R = 0
    // T.print();
    cout << T.root->c << endl;
    cout << T.root->l->c << endl;

    // T.insert(10);
    // T.insert(5);
    // T.insert(15);
    // T.insert(1);
    // T.insert(8);
    // T.insert(12);
    // T.insert(17);

    cout << endl << 0 << endl;

    return 0;
}