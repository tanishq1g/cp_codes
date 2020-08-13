class Solution {
public:
    void sortColors(vector<int>& ve) {
        int n = ve.size();
        int low = 0, mid = 0, high = n - 1;

        for(int i = 0; i <= high;){
            cout << low << ' ' << high << ' ' << i << '\n';
            if(ve[i] == 0){
                swap(ve[i], ve[low++]);
                i++;
            }    
            else if(ve[i] == 1){
                i++;
            }
            else{
                swap(ve[i], ve[high--]);
            }
            for(int j = 0; j < n; j++){
                cout << ve[j] << ' ';
            } cout << endl;
        }
    }
};