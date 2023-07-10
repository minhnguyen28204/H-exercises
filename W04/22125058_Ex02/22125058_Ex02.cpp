#include <iostream>
#include <fstream>
#include "23Tree.h"

using namespace std;

int main()
{
    Tree23 MyTree;
    ifstream ifs("input.txt");
    int x;
    while (ifs>>x){
        MyTree.insertNode(x,MyTree.root);
    }
    ifs.close();

    ofstream ofs("output.txt");
    traversalNode(MyTree.root,ofs);
    ofs.close();
    return 0;
}
