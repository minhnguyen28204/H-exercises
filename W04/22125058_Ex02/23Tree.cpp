#include <iostream>
#include <fstream>
#include "23Tree.h"

using namespace std;

BNode::~BNode(){
    if (left) delete left;
    if (mid) delete mid;
    if (right) delete right;
    if (lval) delete lval;
    if (rval) delete rval;
}

BNode* Tree23::splitNode(int x, BNode* cur) {

    if (cur->rval == nullptr) {
        cur->rval = new int(x);
        if (*(cur->lval) > *(cur->rval)) swap(cur->lval, cur->rval);
        return nullptr;
    }

    int leftVal = min(x, min(*cur->lval, *cur->rval));
    int midVal = max(*cur->lval, min(*cur->rval, x));
    int rightVal = max(x, max(*cur->lval, *cur->rval));

    *cur->lval = midVal;
    delete cur->rval;
    cur->rval = nullptr;
    cur->left = new BNode;
    cur->left->lval = new int(leftVal);
    cur->mid = new BNode;
    cur->mid->lval = new int(rightVal);
    return cur;
}

BNode* Tree23::pushTop(BNode *prom, BNode *cur) {

    if (cur->rval == nullptr) {
        cur->rval = new int(*prom->lval);
        if (*cur->lval > *prom->lval) {
            swap(cur->lval, cur->rval);
            cur->right = cur->mid;
            cur->mid = prom->mid;
            cur->left = prom->left;
        }
        else {
            cur->right = prom->mid;
            cur->mid = prom->left;
        }

        prom->left = prom->mid = prom->right = nullptr;
        delete prom;
        return prom = nullptr;
    }

    if (*prom->lval < *cur->lval) {
        BNode* res = new BNode;
        res->lval = new int(*cur->lval);
        res->left = prom;
        res->mid = cur;
        *cur->lval = *cur->rval;
        delete cur->rval;
        cur->rval = nullptr;
        cur->left = cur->mid;
        cur->mid = cur->right;
        cur->right = nullptr;
        return res;
    }
    else if (*prom->lval > *cur->lval && *prom->lval < *cur->rval) {
        BNode* res = new BNode;
        res->lval = new int(*prom->lval);
        res->left = cur;
        res->mid = prom;
        *prom->lval = *cur->rval;
        delete cur->rval;
        cur->rval = nullptr;
        cur->mid = prom->left;
        prom->left = prom->mid;
        prom->mid = cur->right;
        cur->right = nullptr;
        return res;
    }
    else {
        BNode* res = new BNode;
        res->lval = new int(*cur->rval);
        res->left = cur;
        res->mid = prom;
        delete cur->rval;
        cur->rval = nullptr;
        cur->right = nullptr;
        return res;
    }

    return nullptr;
}

BNode* Tree23::insertNode(int x, BNode* &cur) {

    if (cur == nullptr) {
        cur = new BNode;
        cur->lval = new int(x);
        cur->left = cur->mid = cur->right = nullptr;
        return nullptr;
    }

    if (cur->isChild()) {
        return splitNode(x, cur);
    }

    BNode* prom = nullptr;
    if (*cur->lval > x)
        prom = insertNode(x, cur->left);
    else if ((*cur->lval < x && cur->rval == nullptr) || x < *cur->rval)
        prom = insertNode(x, cur->mid);
    else
        prom = insertNode(x, cur->right);

    if (prom == nullptr)
        return nullptr;
    BNode* temp = pushTop(prom, cur);
    if (cur == root) {
        if (temp)
            root = temp;
        return temp = nullptr;
    }
    return temp;
}

void traversalNode(BNode* root, ofstream &fout) {
    if (root == nullptr)
        return;
    traversalNode(root->left, fout);
    fout << *root->lval << " ";
    traversalNode(root->mid, fout);
    if (root->rval)
        fout << *root->rval << " ";
    traversalNode(root->right, fout);
}
