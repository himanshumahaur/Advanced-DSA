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

            // add fix here
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

    T.insert(10);
    T.insert(5);
    T.insert(15);
    T.insert(1);
    T.insert(8);
    T.insert(12);
    T.insert(17);

    print2D(T.root);

    Node *tmp = T.find(10);
    if (tmp)
        cout << tmp->p->v << endl;

    return 0;
}