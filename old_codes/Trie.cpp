#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>
#include <ctime>
#include <cstdlib>
#include <queue>
#include <iomanip>
#include <climits>
using namespace std;
class Trie{
    class TrieNode{
    public:
        TrieNode * parent;
        TrieNode * children[26];
        int childcount;
        bool isleaf;
        TrieNode(){
            parent = NULL;
            for(int i=0; i<26; i++){
                children[i] = NULL;
            }
            childcount = 0;
            isleaf = false;
        }
    };
    TrieNode * root;

public:
    Trie(){
        root = new TrieNode();
    }
    void insert(string word){
        TrieNode * current = root;
        for(int i=0; i<word.length(); i++){
            if(current -> children[word[i] - 97] == NULL){
                current -> children[word[i] - 97] = new TrieNode();
                current -> childcount ++;
                current -> children[word[i] - 97] -> parent = current;
            }
            current = current -> children[word[i] - 97];
        }
        current -> isleaf = true;
    }
    bool searchbool(string word){
        TrieNode * current = root;
        int f=0;
        for(int i=0; i<word.length(); i++){
            if(current -> children[word[i] - 97] != NULL){
                current = current -> children[word[i] - 97] ;
            }
            else{
                f = 1;
                break;
            }
        }
        if(f == 1)
            return false;
        else{
            if(current -> isleaf == true)
                return true;
            else
                return false;
        }
    }
    TrieNode * searchtrienode(string word){
        TrieNode * current = root;
        int f=0;
        for(int i=0; i<word.length(); i++){
            if(current -> children[word[i] - 97] != NULL){
                current = current -> children[word[i] - 97] ;
            }
            else{
                f = 1;
                break;
            }
        }
        if(f == 1)
            return NULL;
        else{
            if(current -> isleaf == true)
                return current;
            else
                return NULL;
        }
    }
    void removeword(string word){
        TrieNode * temp = searchtrienode(word);
        if(temp == NULL)
            return;
        temp -> isleaf = false;
        for(int i=word.length()-1; i>=0; i--){
            if(temp -> childcount == 0 && temp -> isleaf == false){
                temp -> parent -> children[word[i] - 97] = NULL;
                temp -> parent -> childcount -- ;
                TrieNode * del = temp;
                free(del);
                temp = temp -> parent;
            }
            else
                break;
        }
    }
    void levelorderprint(){
        TrieNode * temp = root;
        queue <TrieNode *> q;
        levelorderprint1(temp,q);
    }
    void levelorderprint1(TrieNode * root,queue <TrieNode *> &q){
        if(root -> childcount != 0)
            for(int i=0; i<26; i++){
                if(root -> children[i] != NULL){
                    cout << char(i + 97) << ' ';
                    q.push(root -> children[i]);
                }
            }
        if(!q.empty()){
            TrieNode * temp = q.front();
            q.pop();
            levelorderprint1(temp,q);
        }
        else
            return;
    }
};


int main(){
    Trie t;
    t.insert("their");
    t.insert("t");
    t.insert("the");
    t.insert("all");
    cout<<t.searchbool("their")<<'\n';
    t.removeword("the");
    t.removeword("their");
    cout<<t.searchbool("their")<<'\n';
    t.levelorderprint();
    return 0;
}