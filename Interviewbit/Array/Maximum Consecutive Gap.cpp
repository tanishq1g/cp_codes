int Solution::maximumGap(const vector<int> &A) {
    if(A.size() < 2) return 0;
    
    int min_x= *min_element(A.begin(), A.end());
    int max_x= *max_element(A.begin(), A.end());
    
    int max_gap = max_x - min_x;
    
    int n = A.size();
    
    double delta = (max_gap) * 1.0 / (n - 1);
    
    vector<int> min_bucket(n - 1, INT_MAX), max_bucket(n - 1, INT_MIN);
    
    for(int i = 0; i < A.size(); i++)
    {
        int x = A[i];
        if(x == min_x || x == max_x) continue;
        
        int pos = floor((x - min_x) / delta);
        
        min_bucket[pos] = min(min_bucket[pos], x);
        max_bucket[pos] = max(max_bucket[pos], x);
    }
    
    int max_diff = INT_MIN;
    int prev_max = min_x;
    for(int i = 0; i < (n - 1); i++)
    {
        if(min_bucket[i] == INT_MAX) continue; //empty bucket
        
        int curr = min_bucket[i] - prev_max;
        max_diff = max(curr, max_diff);
        
        prev_max = max_bucket[i];
    }
    max_diff = max(max_diff, max_x - prev_max);
    
    return max_diff;
}
