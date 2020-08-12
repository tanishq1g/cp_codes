// array

class Solution {
    vector<string> ret;
    int ss;
    map<char, int> ma;
    string o;
    void func(string &str){
        map<char, int>::iterator itr;
        for(itr = ma.begin(); itr != ma.end(); itr++){
            if(itr->second != 0)
                break;
        }
        if(itr == ma.end()){
            cout << str << '\n';
            string c = str;
            reverse(c.begin(), c.end());
            ret.push_back(str + o + c);
        }

        for(itr = ma.begin(); itr != ma.end(); itr++){
            if(itr->second != 0){
                str.push_back(itr->first);
                itr->second--;
                func(str);
                itr->second++;
                str.pop_back();
            }
        }
    }
public:
    vector<string> generatePalindromes(string s) {
        ss = s.size();
        for(int i = 0; i < ss; i++){
            ma[s[i]]++;
        }
        o = "";
        for(auto itr = ma.begin(); itr != ma.end(); itr++){
            if(itr->second % 2 == 1){
                if(o != "")
                    return ret;
                o = itr->first;
                itr->second--;
            }
            itr->second = itr->second / 2;
        }
        string str = "";
        func(str);
        return ret;
    }
};