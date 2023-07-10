#ifndef MYFUNCTIONS_H
#define MYFUNCTIONS_H

using namespace std;

struct BNode {
    int* lval = nullptr;
    int* rval = nullptr;
    BNode *left = nullptr;
    BNode *mid = nullptr;
    BNode *right = nullptr;

    ~BNode();

    bool isChild() {return left == nullptr;}
};

struct Tree23 {
    BNode* root = nullptr;

    BNode* splitNode(int x, BNode* cur);
    BNode* pushTop(BNode *prom, BNode *cur);
    BNode* insertNode(int x, BNode* &cur);
};

void traversalNode(BNode* root, ofstream &fout);


#endif
