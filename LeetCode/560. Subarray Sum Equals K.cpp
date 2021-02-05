class Solution {
public:
    int subarraySum(vector<int>& ve, int k) {
        int n = ve.size();
        int count = 0;
        unordered_map<int, int> umap;
        int su = 0;
        umap[0] = 1;
        for(int i = 0; i < n; i++){
            su += ve[i];
            if(umap.find(su - k) != umap.end()){
                count += umap[su - k];
            }
            if(umap.find(su) != umap.end()){
                umap[su]++;
            }
            else{
                umap[su] = 1;
            }
        }
        return count;
    }
};