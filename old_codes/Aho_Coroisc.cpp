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

int no;
class Aho_Coroisc{
public:
	class Trie{
	    class TrieNode{
	    public:
	        // TrieNode * parent;
	        TrieNode * children[26];
	        TrieNode * fail;
	        int childcount;
	        bool isleaf;
	        string *str;
	        int ptr;
	        TrieNode(){
	            // parent = NULL;
	            for(int i=0; i<26; i++){
	                children[i] = NULL;
	            }
	            fail = NULL;
	            childcount = 0;
	            isleaf = false;
	            ptr = 0;
	            str = new string[no];
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
	                // current -> children[word[i] - 97] -> parent = current;
	            }
	            current = current -> children[word[i] - 97];
	        }
	        current -> isleaf = true;
	        // current -> str[current -> ptr] = new string;
	        current -> str[current -> ptr] = word;
	        cout<<current -> str[current -> ptr] << '\n';
	        current -> ptr++;
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
	    // void removeword(string word){
	    //     TrieNode * temp = searchtrienode(word);
	    //     if(temp == NULL)
	    //         return;
	    //     temp -> isleaf = false;
	    //     for(int i=word.length()-1; i>=0; i--){
	    //         if(temp -> childcount == 0 && temp -> isleaf == false){
	    //             temp -> parent -> children[word[i] - 97] = NULL;
	    //             temp -> parent -> childcount -- ;
	    //             TrieNode * del = temp;
	    //             free(del);
	    //             temp = temp -> parent;
	    //         }
	    //         else
	    //             break;
	    //     }
	    // }
	    void levelorderprint(){
	    	TrieNode * temp = root;
	    	queue <TrieNode *> q;
	    	levelorderprint1(temp,q);
	    }
	    void levelorderprint1(TrieNode * root,queue <TrieNode *> &q){
	    	if(root -> childcount != 0)
		    	for(int i=0; i<26; i++){
		    		if(root -> children[i] != NULL){
		    			cout << char(i + 97) << ' ' << root -> children[i] -> fail<<' ';
		    			int k=root -> children[i] -> ptr;
		    			cout << k <<' ';
		    			if(k != 0){
		    				k -- ;
		    				while(k >= 0){
		    					cout << root -> children[i] -> str[k] <<' ';
						        k -- ;
		    				}
		    			}
		    			q.push(root -> children[i]);
		    			cout<<'\n';
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

	    void createfail(){
	    	queue <TrieNode *> q;
	    	root -> fail = root;
	    	// cout <<this ->  root << ' '<<"fail "<<root -> fail <<endl;
	    	if(root -> childcount != 0){
	    		for(int i=0; i<26; i++){
		    		if(root -> children[i] != NULL){
		    			q.push(root -> children[i]);
		    			// cout<< " sdd "<<char(i+97)<<' '<<root -> children[i]<<' ';
		    			root -> children[i] -> fail = root;
		    			// cout<<" fail "<<root -> children[i] -> fail<<endl;
		    		}
		    	}
		    	if(!q.empty()){
		    		TrieNode * temp = q.front();
		    		q.pop();
		    		createfail1(temp,q);
		  		}
	    	}
	    	// cout <<"OVER\n";
	    }
	    void createfail1(TrieNode * root,queue <TrieNode *> &q){
	    	if(root -> childcount != 0)
		    	for(int i=0; i<26; i++){
		    		if(root -> children[i] != NULL){
		    			q.push(root -> children[i]);
		    			TrieNode * temp = root;
		    			while(1){
		    				if(temp-> fail -> children[i] != NULL || temp -> fail == temp){
		    					// cout<< " sdd "<<char(i+97)<<' '<<root -> children[i]<<' ';
		    					break;
		    				}
		    				// cout <<"            temp "<<temp <<endl;
		    				temp = temp -> fail;
		    			}
		    			if(temp -> fail != temp)
		    				root -> children[i] -> fail = temp -> fail -> children[i];
		    			else
		    				root -> children[i] -> fail = temp; 
		    			// cout<<" fail "<<root -> children[i] -> fail<<endl;
		    			if(root -> children[i] -> fail == this -> root)
		    				continue;
		    			int k=root -> children[i] -> fail -> ptr;
		    			// cout << k <<endl;
		    			if(k != 0){
		    				k -- ;
		    				while(k >= 0){
		    					// root -> children[i] -> str[root -> children[i] -> ptr] = new string;
						        root -> children[i] -> str[root -> children[i] -> ptr] = root -> children[i] -> fail -> str[k];
						        // cout << root -> children[i] -> str[root -> children[i] -> ptr] <<endl;
						        root -> children[i] -> ptr++;
						        k -- ;
		    				}
		    			}
		    		}
		    	}
		    // cout << "  queue s "<<q.size()<<endl;
		   	if(!q.empty()){
	    		TrieNode * temp = q.front();
	    		q.pop();
	    		createfail1(temp,q);
	  		}
	    }

	    void ahoi(string &text, int n){
	    	TrieNode * temp = root , * cur;
			for(int i=0; i<n; ){
				// cout<<"\nfinding "<<text[i]<<'\n';
				cur = temp -> children[text[i] - 97];
				if(cur != NULL){
					int k = cur -> ptr;
					// cout << "    k  " << k <<endl;
					string s;
					k--;
					while(k >= 0){
						s = cur -> str[k];
						cout << s <<" found at "<< i - s.length() + 1 << endl;
						k--;
					}
					temp = cur;
					i++;
				}
				else if(temp -> fail == temp)
					i++;
				else{
					temp = temp -> fail;
				}
			}
	    }
	};
	Trie t;
public:
	void insert(string str){
		t.insert(str);
	}
	void search(string text){
		t.createfail();
		// t.levelorderprint();
		int n = text.length();
		t.ahoi(text,n);
	}
};

int main(){

	string s = "aabaabaabababaac";
	no = 12;
    Aho_Coroisc aho;
    aho.insert("a");
    aho.insert("ab");
    aho.insert("bc");
    aho.insert("aab");
    aho.insert("aac");
    aho.insert("bd");
    aho.search(s);
    return 0;
}