vector<int> Solution::findPerm(const string s, int n) {
    vector<int> ve(n), ret(n);
    for(int i = 0; i < n; i++){
        ve[i] =  i + 1;    
    }
    int ss = s.size();
    int l = 0, r = n - 1, k = 0;
    for(int i = 0; i < ss;){
        if(s[i] == 'I'){
            if(k == 0){
                ret[k] = ve[l];
                l++;
                k++;
                i++;
                while(i < ss && s[i] == 'I'){
                    ret[k] = ve[l];
                    l++;
                    k++;
                    i++;
                }
                ret[k] = ve[r];
                r--;
                k++;
            }
            int c = 0;
            while(i < ss && s[i] == 'I'){
                i++;
                c++;
            }
            for(int j = r - c + 1; j <= r; j++){
                ret[k] = ve[j];
                k++;
            }
            r -= c;
        }
        else{
            if(k == 0){
                ret[k] = ve[r];
                r--;
                k++;
                i++;
                while(i < ss && s[i] == 'D'){
                    ret[k] = ve[r];
                    r--;
                    k++;
                    i++;
                }
                ret[k] = ve[l];
                l++;
                k++;
            }
            int c = 0;
            while(i < ss && s[i] == 'D'){
                c++:
                i++;
            }
            for(int j = l + c - 1; j >= l; j++){
                ret[k] = ret[j];
                k++;
            }
            l += c;
        }
    }
    return ret;
}

vector<int> Solution::findPerm(const string A, int B) {
  assert(A.length() == (B - 1));
  for(int i = 0; i < B - 1; i++) assert((A[i] == 'I') || (A[i] == 'D'));

  vector<int> ans(B); int start = 1, upto = B;
  for(int i = 0; i < B && (start < upto); i++) {
      if(A[i] == 'D') ans[i] = upto--;
      else ans[i] = start++;
  }
  assert(start == upto);
  ans[B - 1] = start;
  return ans;
}