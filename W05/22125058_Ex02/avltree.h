#ifndef AVLTREE_H
#define AVLTREE_H
#include <bits/stdc++.h>
using namespace std;

struct Node{
    int val, hei;
    Node *left, *right;
    Node(int _val){
        val = _val;
        hei = 1;
        left = nullptr;
        right = nullptr;
    }
    ~Node();
};

Node* leftRotate(Node* pRoot);
Node* rightRotate(Node* pRoot);
Node* insertNode(Node* pRoot, int key);
int getHeight(Node* pRoot);
int getBalance(Node* pRoot);

void inorderTraversal(Node* pRoot, ofstream &ofs);

#endif // ALVTREE_H
