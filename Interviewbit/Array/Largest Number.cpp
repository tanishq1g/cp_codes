string Solution::largestNumber(const vector<int> &arr) {
    vector<string> ve(arr.size()); 
    int n = arr.size();
    if(n == 0)
        return "";
    for(int i = 0; i < n; i++){
        ve[i] = to_string(arr[i]);
    }
    string str = "";
    // sort(ve.begin(), ve.end(), [](string &a, string &b){
    //     int s1 = a.size();
    //     int s2 = b.size();
    //     if(s1 == s2)
    //         return a > b;
    //     int s3 = min(s1, s2);
    //     for(int i = 0; i < s3; i++){
    //         if(a[i] < b[i])
    //             return false;
    //         else if(a[i] > b[i])
    //             return true;
    //     }
    //     if(s1 > s2){
    //         for(int j = 0; j < s2; j++){
    //             for(int i = s3; i < s1; i++){
    //                 if(a[i] < b[j])
    //                     return false;
    //                 else if(a[i] > b[j])
    //                     return true;
    //             }
    //         }
    //         return true;
    //     }
    //     else{
    //         for(int j = 0; j < s1; j++){
    //             for(int i = s3; i < s2; i++){
    //                 if(b[i] < a[j])
    //                     return true;
    //                 else if(b[i] > a[j])
    //                     return false;
    //             }
    //         }
    //         return false;
    //     }
    //     return false;
    // });
    
    sort(ve.begin(), ve.end(), [](string &a, string &b){
        return a + b > b + a;
    });

    if(ve[0] == "0")
        return "0";
    for(int i = 0; i < n; i++){
        // cout << ve[i] << '\n';
        str += ve[i];    
    }
    return str;
}
