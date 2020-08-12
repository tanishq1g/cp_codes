// backtrack

class Solution {
    int n;
    map<int, int> ma;
    vector<vector<int>> ret;
    void func(vector<int>& ve, vector<int> &ad){
        map<int, int>::iterator itr;
        for(itr = ma.begin(); itr != ma.end(); itr++){
            if(itr->second != 0){
                break;
            }
        }
        if(itr == ma.end()){
            ret.push_back(ad);
            return;
        }
        for(itr = ma.begin(); itr != ma.end(); itr++){
            if(itr->second != 0){
                ad.push_back(itr->first);
                itr->second--;
                func(ve, ad);
                itr->second++;
                ad.pop_back();
            }
        }

    }
public:
    vector<vector<int>> permuteUnique(vector<int>& ve) {
        n = ve.size();
        for(int i = 0; i < n; i++){
            ma[ve[i]]++;   
        }
        vector<int> ad;
        func(ve, ad);
        return ret;
    }
};