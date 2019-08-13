class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> cur;
        permute(nums, result, cur, -1);
        return result;
    }
private:
    void permute(vector<int> nums, vector<vector<int>>& result, vector<int>& cur, int pre_index) {
        if(pre_index != -1)
            nums.erase(nums.begin()+pre_index);
        if(nums.empty()){
            result.push_back(cur);
            return;
        }
        for(int i = 0; i < nums.size(); i++){
            cur.push_back(nums[i]);
            permute(nums, result, cur, i);
            cur.pop_back();
        }
    }
};
