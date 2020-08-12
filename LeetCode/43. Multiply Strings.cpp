// string

class Solution {
public:
    string multiply(string num1, string num2) {
        int s1 = num1.size();        
        int s2 = num2.size();    
        string re = "";

        int ca = 0, mu, su, ca2;
        for(int i = s1 - 1; i >= 0; i--){
            ca = 0;
            ca2 = 0;
            for(int j = s2 - 1, k = s1 - i - 1; j >= 0; j--, k++){
                mu = (num2[j] - '0') * (num1[i] - '0') + ca;
                ca = mu / 10;
                mu %= 10;
                if(re.size() < k + 1){
                    su = mu + ca2;
                    // cout << su << '\n';
                    ca2 = su / 10;
                    su %= 10;
                    re.push_back(su + '0');
                }
                else{
                    su = (re[k] - '0') + mu + ca2;
                    // cout << "s " << su << '\n';
                    ca2 = su / 10;
                    su %= 10;
                    re[k] = (su + '0');
                }
            }
            if(ca + ca2 != 0){
                re.push_back(ca + ca2 + '0');
            }
            // cout << re << '\n';
        }
        int i, ss = re.size();
        for(i = 0; i < ss; i++){
            if(re[i] != '0'){
                break;
            }
        }
        if(i == ss || ss == 0){
            return "0";
        }
        reverse(re.begin(), re.end());
        return re;
    }
};