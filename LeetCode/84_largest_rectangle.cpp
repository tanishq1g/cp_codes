class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int ans = 0;
        int len = heights.size();
        if(len == 0){
            return 0;
        }
        stack<int> st;
        for(int i = 0; i <= len;){
            int h = (i == len ? 0 : heights[i]);
            if(st.empty() || heights[st.top()] <= h){
                st.push(i++);
            }else{
                int tmp = st.top();
                st.pop();
                int l = (st.empty() ? i : i - st.top() - 1);
                ans = max(ans, l * heights[tmp]);
            }
        }
        return ans;
    }
};