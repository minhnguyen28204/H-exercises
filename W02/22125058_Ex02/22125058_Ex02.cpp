//linear probing
class MyHashSet {
private:
    struct Node{
        int val;
        Node* pNext;
    };
    Node* arr[10005];
    const int MOD = 1e4;
public:
    MyHashSet() {
        for(int i=0; i<=10001; i++) arr[i] = nullptr;
    }
    
    void add(int key) {
        int id = key % MOD;
        if (contains(key)) return;
        Node* NewNode = new Node;
        NewNode->val = key;
        NewNode->pNext = arr[id];
        arr[id] = NewNode;
    }
    
    void remove(int key) {
        int id = key % MOD;
        if (!contains(key)) return;
        Node* Cur = arr[id];
        if (arr[id]->val==key){
            Node* Temp = arr[id];
            arr[id] = arr[id]->pNext;
            delete Temp;
            return;
        }
        Node* PrevCur = Cur;
        while (Cur->val != key) PrevCur = Cur, Cur = Cur->pNext;
        Node* Temp = Cur;
        Cur = Cur->pNext;
        PrevCur->pNext = Cur;
        delete Temp;
    }
    
    bool contains(int key) {
        int id = key % MOD;
        Node* Cur = arr[id];
        while (Cur){
            if (Cur->val == key) return true;
            Cur = Cur->pNext;
        }
        return false;
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */