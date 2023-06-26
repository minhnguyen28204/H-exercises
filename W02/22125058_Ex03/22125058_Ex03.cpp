//linear probing
class MyHashSet {
private:
    const int MOD = 1e4+1;
    int HashTable[10005];
public:
    MyHashSet() {
        for(int i=0; i<=10000; i++) HashTable[i] = -1;
    }
    
    void add(int key) {
        if (contains(key)) return;
        int id = key % MOD;
        while (HashTable[id]!=-1) id = (id+1)%MOD;
        HashTable[id] = key;
    }
    
    void remove(int key) {
        if (!contains(key)) return;
        int id = key % MOD;
        while (HashTable[id]!=key) id = (id+1)%MOD;
        HashTable[id] = 0;
    }
    
    bool contains(int key) {
        int id = key % MOD;
        while (HashTable[id]!=key && HashTable[id]!=-1) id = (id+1)%MOD;
        if (HashTable[id]==key) return true;
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