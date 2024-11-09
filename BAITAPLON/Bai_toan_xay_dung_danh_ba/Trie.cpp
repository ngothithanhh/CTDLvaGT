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

        


};