#include <bits/stdc++.h>

using namespace std;

const int Mod = 30000;
const int Base = 37;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);
    struct Node{
        string val;
        Node* pNext;
        Node():val(""), pNext(nullptr){}
        Node(string val):val(val), pNext(nullptr){}
    };
    Node* arr[30005];
    void add(int id, string key) {
        Node* NewNode = new Node(key);
        NewNode->pNext = arr[id];
        arr[id] = NewNode;
    }
    
    void remove(int id, string key) {
        Node* Cur = arr[id];
        if (arr[id]->val == key){
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
    
    bool contains(int id, string key) {
        Node* Cur = arr[id];
        while (Cur){
            if (Cur->val == key) return true;
            Cur = Cur->pNext;
        }
        return false;
    }

/*
 * Complete the 'checkMagazine' function below.
 *
 * The function accepts following parameters:
 *  1. STRING_ARRAY magazine
 *  2. STRING_ARRAY note
 */

void checkMagazine(vector<string> magazine, vector<string> note) {
    for(int i=0; i<=30000; i++) arr[i] = nullptr;
    for(int i=0; i<magazine.size(); i++){
        int tmp = 0;
        for(int j=0; j<magazine[i].size(); j++) tmp += magazine[i][j];
        add(tmp,magazine[i]);
    }
    for(int i=0; i<note.size(); i++){
        int tmp = 0;
        for(int j=0; j<note[i].size(); j++) tmp += note[i][j];
        if (contains(tmp,note[i])){
            remove(tmp,note[i]);
        }
        else{
            cout << "No";
            return;
        }
    }
    cout << "Yes";
}   

int main()
{
    string first_multiple_input_temp;
    getline(cin, first_multiple_input_temp);

    vector<string> first_multiple_input = split(rtrim(first_multiple_input_temp));

    int m = stoi(first_multiple_input[0]);

    int n = stoi(first_multiple_input[1]);

    string magazine_temp_temp;
    getline(cin, magazine_temp_temp);

    vector<string> magazine_temp = split(rtrim(magazine_temp_temp));

    vector<string> magazine(m);

    for (int i = 0; i < m; i++) {
        string magazine_item = magazine_temp[i];

        magazine[i] = magazine_item;
    }

    string note_temp_temp;
    getline(cin, note_temp_temp);

    vector<string> note_temp = split(rtrim(note_temp_temp));

    vector<string> note(n);

    for (int i = 0; i < n; i++) {
        string note_item = note_temp[i];

        note[i] = note_item;
    }

    checkMagazine(magazine, note);

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}

vector<string> split(const string &str) {
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos) {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}
