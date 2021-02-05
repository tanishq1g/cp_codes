class Solution {
public:
    string reorganizeString(string s) {
        int n = s.size();
        struct cmp{
            bool operator()(const pair<int, char> &a, const pair<int, char> &b){
                if(a.first == b.first)
                    return a.second < b.second;
                return a.first < b.first;
            }
        };
        priority_queue<pair<int, char>, vector<pair<int, char>>, cmp> pq;
        vector<int> freq(26, 0);
        for(int i = 0; i < n; i++){
            freq[s[i] - 'a']++;
        }
        int limit = (n + 1) / 2;
        for(int i = 0; i < 26; i++){
            if(freq[i] > 0){
                pq.push(make_pair(freq[i], i + 'a'));
            }
            if(freq[i] > limit)
                return "";
        }
        string ret = "";
        pair<int, char> pa, pa2;
        bool flag = false;
        pa = pq.top();
        pq.pop();
        ret += pa.second;
        pa.first--;
        if(pa.first == 0){
            pa = pq.top();
            pq.pop();
            flag = true;                   
        }
        while(!pq.empty()){
            if(flag){
                pq.push(pa);
                pa = pq.top();
                pq.pop();
                ret += pa.second;
                pa.first--;
                flag = false;
                if(pa.first == 0){
                    pa = pq.top();
                    pq.pop();
                    flag = true;                   
                }
            }
            else{
                pa2 = pq.top();
                pq.pop();
                ret += pa2.second;
                pa2.first--;
                if(pa2.first > 0){
                    pq.push(pa2);
                }
                flag = true;
            }
        }
        if(pa.first > 0){
            ret += pa.second;
        }
        return ret;
    }
};