#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <cstdlib>
#include <string>
using namespace std;

class Solution {
public:
    int romanToInt(string s) {
        int x = 0;
        int slen = s.size();
        for(int i = 0; i < slen; i++){
            if(s[i] == 'M')
                x += 1000;
            else if(s[i] == 'D')
                x += 500;
            else if(s[i] == 'C'){
                if(i + 1 < slen){
                    if(s[i + 1] == 'D'){
                        x += 400;
                        i++;
                    }
                    else if(s[i + 1] == 'M'){
                        x += 900;
                        i++;
                    }else
                        x += 100;
                }
                else
                    x += 100;
            }
            else if(s[i] == 'L')
                x += 50;
            else if(s[i] == 'X'){
                if(i + 1 < slen){
                    if(s[i + 1] == 'L'){
                        x += 40;
                        i++;
                    }
                    else if(s[i + 1] == 'C'){
                        x += 90;
                        i++;
                    }else
                        x += 10;
                }
                else
                    x += 10;
            }
            else if(s[i] == 'V')
                x += 5;
            else if(s[i] == 'I'){
                if(i + 1 < slen){
                    if(s[i + 1] == 'V'){
                        x += 4;
                        i++;
                    }
                    else if(s[i + 1] == 'X'){
                        x += 9;
                        i++;
                    }else
                        x += 1;
                }
                else
                    x += 1;
            }
        }
        return x;
    }
};

int main() {
	Solution sol;
	string s;
    cin >> s;
	cout << sol.romanToInt(s);	
	return 0;
}