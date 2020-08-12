// array hashing

class Solution {
public:
    int fourSumCount(vector<int>& a, vector<int>& b, vector<int>& c, vector<int>& d) {
        int n = a.size();
        unordered_map<int, int> umap;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                umap[a[i] + b[j]]++;
            }
        }
        int count = 0;
        unordered_map<int, int>::iterator itr;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                itr = umap.find(-(c[i] + d[j]));
                if(itr != umap.end()){
                    count += itr->second;
                }
            }    
        }
        return count;
    }
};