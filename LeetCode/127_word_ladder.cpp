#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <unordered_map>
#include <string>
#include <queue>
using namespace std;

class Solution {
    struct Node{
        string str;
        int depth;
        Node(string s, int d): str(s), depth(d) {}
    };

    bool transformable(string &a, string &b){
        int s = a.size(), sim = 0;
        for (int i = 0; i < s; i++){
            if(a[i] == b[i])
                sim++;
        }
        return sim == (s - 1);
    }

public:
// one directional BFS
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        int swordList = wordList.size();
        if(beginWord == "" || endWord == "" || swordList == 0 || find(wordList.begin(), wordList.end(), endWord) == wordList.end())
            return 0;

        int sb = beginWord.size();

        vector<bool> visited(swordList, false);
        queue<Node> q;
        Node temp = Node("", -1);
        q.push(Node(beginWord, 1));
        while(!q.empty()){
            temp = q.front();
            q.pop();
            for (int i = 0; i < swordList; i++){
                if(!visited[i]){
                    if(transformable(temp.str, wordList[i])){
                        if(wordList[i] == endWord)
                            return temp.depth + 1;
                        q.push(Node(wordList[i], temp.depth + 1));
                        visited[i] = true;
                    }
                }
            }
        }
        return 0;
    }
// 2 bidirectional bfs
    int ladderLength2(string beginWord, string endWord, vector<string>& wordList) {
        int swordList = wordList.size();
        if(beginWord == "" || endWord == "" || swordList == 0 || find(wordList.begin(), wordList.end(), endWord) == wordList.end())
            return 0;

        int sb = beginWord.size();

        vector<int> visited0(swordList, -1), visited1(swordList, -1);
        queue<Node> q0, q1;
        Node temp = Node("", -1);
        q0.push(Node(beginWord, 1));
        q1.push(Node(endWord, 1));
        while(!q0.empty() || !q1.empty()){
            if(!q0.empty()){
                cout<<"in0\n";
                temp = q0.front();
                q0.pop();
                for (int i = 0; i < swordList; i++){
                    if(visited0[i] == -1){
                        if(transformable(temp.str, wordList[i])){
                            if(wordList[i] == endWord)
                                return temp.depth + 1;
                            q0.push(Node(wordList[i], temp.depth + 1));
                            visited0[i] = temp.depth + 1;
                        }
                    }
                    else{
                        if(visited1[i] != -1){
                        cout<<temp.str<<'\n';
                            return visited0[i] + visited1[i] - 1;
                        }
                    }
                }
            }
            if(!q1.empty()){
                cout<<"in1\n";
                temp = q1.front();
                q1.pop();
                for (int i = 0; i < swordList; i++){
                    if(visited1[i] == -1){
                        if(transformable(temp.str, wordList[i])){
                            if(wordList[i] == beginWord)
                                return temp.depth + 1;
                            q1.push(Node(wordList[i], temp.depth + 1));
                            visited1[i] = temp.depth + 1;
                        }
                    }
                    else{
                        if(visited0[i] != -1){
                        cout<<temp.str<<'\n';
                            return visited1[i] + visited0[i] - 1;
                        }
                    }
                }
            }
            cout<<q0.size()<<' '<<q1.size()<<'\n';
        }
        return 0;
    }
};

int main(){
    Solution sol;
    string beginWord = "hit";
    string endWord = "cog";
    vector<string> wordList{"hot","dot","dog","lot","log","cog"};
    cout<<sol.ladderLength2(beginWord, endWord, wordList);
    return 0;
}