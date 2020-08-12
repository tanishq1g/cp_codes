// trick string
class Solution {
public:
    string nextClosestTime(string time) {
        int h = 10 * (time[0] - '0') + (time[1] - '0');
        int m = 10 * (time[3] - '0') + (time[4] - '0');
        vector<int> ve{time[0] - '0', time[1] - '0', time[3] - '0', time[4] - '0'};
        sort(ve.begin(), ve.end());
        while(1){
            if(m < 60){
                m++;
            }
            else{
                m = 0;
                if(h < 24){
                    h++;
                }
                else{
                    h = 0;
                }
            }
            if(find(ve.begin(), ve.end(), h % 10) != ve.end() && 
                find(ve.begin(), ve.end(), h / 10) != ve.end() &&
                find(ve.begin(), ve.end(), m % 10) != ve.end() && 
                find(ve.begin(), ve.end(), m / 10) != ve.end()){
                    time[0] = ((h / 10) + '0');
                    time[1] = ((h % 10) + '0');
                    time[3] = ((m / 10) + '0');
                    time[4] = ((m % 10) + '0');
                    return time;
                }
        }
    }
};