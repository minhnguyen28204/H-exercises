#include "avltree.h"
#include <bits/stdc++.h>
using namespace std;

Node::~Node(){
    if (left) delete left;
    if (right) delete right;
}

Node* leftRotate(Node* pRoot){
    Node* RC = pRoot->right;
    Node* RLG = pRoot->right->left;


    //    pRoot
    //         \
    //         RC
    //        /  \
    //     RLG   ...


    //     RC
    //    /  \
    //pRoot  ...
    //    \
    //   RLG


    RC->left = pRoot;
    pRoot->right = RLG;

    pRoot->hei = max(getHeight(pRoot->left),getHeight(pRoot->right)) + 1;
    RC->hei = max(getHeight(RC->left),getHeight(RC->right));
    return RC;
}

Node* rightRotate(Node* pRoot){
    Node* LC = pRoot->left;
    Node* LRG = LC->right;

    LC->right = pRoot;
    pRoot->left = LRG;

    pRoot->hei = max(getHeight(pRoot->left),getHeight(pRoot->right)) + 1;
    LC->hei = max(getHeight(LC->left),getHeight(LC->right));
    return LC;
}

int getHeight(Node* pRoot){
    if (pRoot == nullptr) return 0;
    return pRoot->hei;
}

int getBalance(Node* pRoot){
    return getHeight(pRoot->left) - getHeight(pRoot->right);
}

Node* insertNode(Node* pRoot, int key){
    if (pRoot==nullptr){
        pRoot = new Node(key);
        return pRoot;
    }

    if (key < pRoot->val){
        pRoot->left = insertNode(pRoot->left,key);
    }
    else pRoot->right = insertNode(pRoot->right,key);

    pRoot->hei = max(getHeight(pRoot->left),getHeight(pRoot->right)) + 1;

    int balance = getBalance(pRoot);

    //Left-Left case
    //Balance > 1 <=> left sub tree is higher than right sub tree
    //Key < pRoot->left->val <=> the value key is insert to the left of the left sub tree node
    if (balance > 1 && key < pRoot->left->val){
        return rightRotate(pRoot);
    }

    //Right-Right case
    if (balance < -1 && key > pRoot->right->val){
        return leftRotate(pRoot);
    }

    //Left-Right case
    if (balance > 1 && key > pRoot->left->val){
        pRoot->left = leftRotate(pRoot->left);
        return rightRotate(pRoot);
    }

    //Right-Left case
    if (balance < -1 && key < pRoot->right->val){
        pRoot->right = rightRotate(pRoot->right);
        return leftRotate(pRoot);
    }

    return pRoot;
}

void inorderTraversal(Node* pRoot, ofstream &ofs){
    if (pRoot){
        inorderTraversal(pRoot->left,ofs);
        ofs << pRoot->val << ' ';
        inorderTraversal(pRoot->right,ofs);
    }
}
