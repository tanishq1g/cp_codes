int Solution::isPalindrome(int A) {
    string str = to_string(A);
    int n = str.size();
    for(int i = 0, j = n - 1; i < j; i++, j--){
        if(str[i] != str[j])
            return 0;
    }
    return 1;
}
