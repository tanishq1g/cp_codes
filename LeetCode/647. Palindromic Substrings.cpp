class Solution {
public:
    bool check_palindrome(string &s, int l, int r){
        for(int i = l, j = r; i < j; ){
            if(s[i] == s[j]){
                i++;
                j--;
            }
            else{
                return false;
            }
        }
        return true;
    }
    int countSubstrings(string s) {
        int n = s.size();
        int count = 0;
        for(int i = 0; i < n; i++){
            for(int j = i; j < n; j++){
                if(check_palindrome(s, i, j)){
                    count++;
                }
            }   
        }        
        return count;
    }
};