// backtracking

// class Solution {
// public:
//     vector<vector<int>> permute(vector<int>& nums) {
//         vector<vector<int>> result;
//         vector<int> cur;
//         permute(nums, result, cur, -1);
//         return result;
//     }
// private:
//     void permute(vector<int> nums, vector<vector<int>>& result, vector<int>& cur, int pre_index) {
//         if(pre_index != -1)
//             nums.erase(nums.begin()+pre_index);
//         if(nums.empty()){
//             result.push_back(cur);
//             return;
//         }
//         for(int i = 0; i < nums.size(); i++){
//             cur.push_back(nums[i]);
//             permute(nums, result, cur, i);
//             cur.pop_back();
//         }
//     }
// };


class Solution {
    int n;
    void func(vector<vector<int>> &ret, vector<int>& ve, int cur){
        if(cur >= n){
            ret.push_back(ve);
            return;
        }
        for(int i = cur; i < n; i++){
            swap(ve[cur], ve[i]);
            // cout << cur << ' ' << i << '\n';
            func(ret, ve, cur + 1);
            swap(ve[cur], ve[i]);
        }
    }
public:
    vector<vector<int>> permute(vector<int>& ve) {
        n = ve.size();
        vector<vector<int> > ret; 
        func(ret, ve, 0);
        return ret;
    }
};

