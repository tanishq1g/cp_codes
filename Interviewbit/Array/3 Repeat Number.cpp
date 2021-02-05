int Solution::repeatedNumber(const vector<int> &ve) {
    int n = ve.size();
    unordered_map<int, int> umap;
    int s = n / 3;
    for(int i = 0; i < n; i++){
        umap[ve[i]]++;
        if(umap[ve[i]] > s)
            return ve[i];
    }
    return -1;
}


int Solution::repeatedNumber(const vector<int> &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    int m1=0,m2=0, num1=A[0], num2=A[1];
    for(int i=0; i<A.size(); i++) {
        if(A[i] == num1) m1++;
        else if(A[i] == num2) m2++;
        else if(m1 == 0) {
            num1=A[i];
            m1=1;
        }
        else if(m2 == 0) {
            num2=A[i];
            m2=1;
        }
        else {
            m1--;
            m2--;
        }
    }
    int freq1=0,freq2=0;
    for(int i=0; i<A.size(); i++) {
        if(A[i] == num1) freq1++;
        if(A[i] == num2) freq2++;
    }
    if(freq1>(A.size()/3)) return num1;
    if(freq2>(A.size()/3)) return num2;
    return -1;
}
