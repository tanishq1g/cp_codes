// string trick

class Solution {
public:
    bool checkValidString(string s) {
        int ss = s.size();
        int c = 0, c2 = 0;
        for(int i = 0; i < ss; i++){
            if(s[i] == '('){
                c2++;;
            }
            else if(s[i] == '*'){
                c++;
            }
            else{
                if(c == 0 && c2 == 0){
                    return false;
                }
                if(c2 == 0)
                    c--;
                else
                    c2--;
            }
        }        
        cout << c2 << ' ' << c << '\n';
        if(c2 == 0)
            return true;
        else{
            // cout << "o\n";
            int c = 0, c2 = 0;
            for(int i = ss - 1; i >= 0; i--){
                if(s[i] == ')'){
                    c2++;;
                }
                else if(s[i] == '*'){
                    c++;
                }
                else{
                    if(c == 0 && c2 == 0){
                        return false;
                    }
                    if(c2 == 0)
                        c--;
                    else
                        c2--;
                }
            }    
            return true;
        }
        return false;
    }
};

