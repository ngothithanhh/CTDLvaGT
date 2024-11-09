#include<iostream>
#include<string>

using namespace std;

class Node{
    public:
        Node* child[26]; //Moi phan tu la 1 not con cho cac ki tu tu 'a' den 'z'
        int count;

        Node(){
            count = 0;
            for(int i = 0; i < 26; i++){
                child[i] = nullptr;
            }
        }

};

class Trie{
    private:
        Node *root;
    public:
        Trie(){
            root = new Node();
        }

        void add(const string& str) {
            Node* node = root;
            for (char c : str) {
                int index = c - 'a'; // Tinh chi so cua ky tu tu 0 den 25
                if (node->child[index] == nullptr) {
                    node->child[index] = new Node();
                }
                node = node->child[index];
                node->count++;
            }
    }

        int find(const string& fin) {
            Node* node = root;
            for (char c : fin) {
                int index = c - 'a';
                if (node->child[index] == nullptr) {
                    return 0; // Khong tim thay tien to
                }
                node = node->child [index];
            }
            return node->count; // Tra ve so tu co tien to can tim
        }
};

main() {
    int n;
    cin >> n; //Nhap so cau lenh

    Trie trie;
    for (int i = 0; i < n; ++i) {
        string command, str;
        cin >> command >> str; // cu pha: lenh chuoikitu
        if (command == "add") {
            trie.add(str);
        } else if (command == "find") {
            cout << trie.find(str) << endl;
        }
    }
}