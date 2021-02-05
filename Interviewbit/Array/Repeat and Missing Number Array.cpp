vector<int> Solution::repeatedNumber(const vector<int> &ve) {
    int n = ve.size();
    vector<int> dp(n + 1, 0);
    for(int i = 0; i < n; i++){
        dp[ve[i]]++;
    }
    vector<int> ret(2);
    for(int i = 1; i <= n; i++){
        if(dp[i] == 0)
            ret[1] = i;
        else if(dp[i] > 1)
            ret[0] = i;
    }
    return ret;
}

// space order 1

// Sum(Actual) = Sum(1...N) + A - B

//     Sum(Actual) - Sum(1...N) = A - B. 

//     Sum(Actual Squares) = Sum(1^2 ... N^2) + A^2 - B^2

//     Sum(Actual Squares) - Sum(1^2 ... N^2) = (A - B)(A + B) 

//     = (Sum(Actual) - Sum(1...N)) ( A + B). 

class Solution {
public:
    vector<int> repeatedNumber(const vector<int> &V) {
       long long sum = 0;
       long long squareSum = 0;
       long long temp;
       for (int i = 0; i < V.size(); i++) {
           temp = V[i];
           sum += temp;
           sum -= (i + 1);
           squareSum += (temp * temp);
           squareSum -= ((long long)(i + 1) * (long long)(i + 1));
       }
       // sum = A - B
       // squareSum = A^2 - B^2 = (A - B)(A + B)
       // squareSum / sum = A + B
       squareSum /= sum;

       // Now we have A + B and A - B. Lets figure out A and B now. 
       int A = (int) ((sum + squareSum) / 2);
       int B = squareSum - A;

       vector<int> ret;
       ret.push_back(A);
       ret.push_back(B);
       return ret;
    }
};
