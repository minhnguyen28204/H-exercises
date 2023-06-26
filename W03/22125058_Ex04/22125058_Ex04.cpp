#include<bits/stdc++.h>

using namespace std;

class Node {
    public:
        int data;
        Node *left;
        Node *right;
        Node(int d) {
            data = d;
            left = NULL;
            right = NULL;
        }
};

class Solution {
    public:
  		Node* insert(Node* root, int data) {
            if(root == NULL) {
                return new Node(data);
            } else {
                Node* cur;
                if(data <= root->data) {
                    cur = insert(root->left, data);
                    root->left = cur;
                } else {
                    cur = insert(root->right, data);
                    root->right = cur;
               }

               return root;
           }
        }

/*
class Node {
    public:
        int data;
        Node *left;
        Node *right;
        Node(int d) {
            data = d;
            left = NULL;
            right = NULL;
        }
};

*/
int appear_distance[1005];
    void topView(Node * root) {
        for(int i=0; i<=1000; i++) appear_distance[i] = -1;
        queue<pair<Node*,int>> qu;
        qu.push(make_pair(root,0));
        while (qu.size()){
            Node* u = qu.front().first;
            int distance = qu.front().second;
            qu.pop();
            if (appear_distance[distance+500]==-1) appear_distance[distance+500] = u->data;
            if (u->left) qu.push(make_pair(u->left, distance-1));
            if (u->right) qu.push(make_pair(u->right, distance+1));
        }
        for(int i=0; i<=1000; i++) if (appear_distance[i]!=-1) cout << appear_distance[i] << ' ';
    }

}; //End of Solution

int main() {
  
    Solution myTree;
    Node* root = NULL;
    
    int t;
    int data;

    std::cin >> t;

    while(t-- > 0) {
        std::cin >> data;
        root = myTree.insert(root, data);
    }
  
	myTree.topView(root);
    return 0;
}
