#include <bits/stdc++.h>
#include "avltree.h"

using namespace std;

int main(){
    Node* pRoot = nullptr;
    ifstream ifs("input.txt");
    int x;
    while (ifs >> x){
        pRoot = insertNode(pRoot,x);
    }
    ifs.close();

    ofstream ofs("output.txt");
    inorderTraversal(pRoot,ofs);
    ofs.close();
    return 0;
}
