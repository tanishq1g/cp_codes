class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        vector<bool> visited(nums.size()+1, false);
        for(int num : nums){
            if(num > 0 && num < visited.size()){
                visited[num-1] = true;
            }
        }
        for(int i=0; i<visited.size(); i++){
            if(!visited[i]){return i+1;}
        }
        return -1;
    }
};