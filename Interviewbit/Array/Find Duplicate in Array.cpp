// O(n) space

int Solution::repeatedNumber(const vector<int> &ve) {
    int n = ve.size();
    vector<int> dp(n + 1, 0);
    for(int i = 0; i < n; i++){
        dp[ve[i]]++;
        if(dp[ve[i]] > 1){
            return ve[i];
        }    
    }
    return -1;
}


// O(sqrt(n)) space
int Solution::repeatedNumber(const vector<int> &A) {
    int s = A.size();
    int sq = sqrt(s);
    int l = s/sq + 1; // Number of blocks sqrt(n)
    vector<int> blocks(l, 0); //Extra O(sqrt(n)) for sqrt(n) blocks
    //Traversed 1st time
    for(auto i:A)
    {
        blocks[(i-1)/sq]++; //Each value goes into corresponding blocks. 
    }
    int sb = l-1;
    for(int i=0; i<l; i++)
    {
        if(blocks[i] > sq)
        {
            sb = i; // find block number that contains more than sqrt(n) elements
            break;
        }
    }

    unordered_set<int> us; //Extra O(sqrt(n)) for checking particular block
    //Traversed 2st time
    for(int i=0; i<s; i++)
    {
        if((A[i]-1)/sq != sb) // if current block is same as block having more than sq elemnts
            continue;
        if(us.find(A[i]) == us.end())
        {
            //insert A[i] as it is not present
            us.insert(A[i]);
        }
        else
        {
            //if(A[i] is already present)
            return A[i];
        }
    }
    return -1;
}