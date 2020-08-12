class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& ve, int k) {
        int n = ve.size();
        int pp = 1;
        long long int  count = 0;
        int le = 0, i;
        vector<pair<long long int , long long int > > p;
        for(i = 0; i < n; i++){
            pp *= ve[i];
            if(pp >= k){
                cout << le << ' ' << i << ' ' << pp / ve[i] << '\n';
                p.push_back(make_pair(le, i));
                pp /= ve[le];
                le++;
                while(le < n && pp >= k){
                    pp /= ve[le];
                    le++;
                }
                if(le == n)
                    break;
                pp = max(1, pp);
            }
        }
        cout << le << ' ' << i << ' ' << pp << '\n';
        if(pp < k){
            p.push_back(make_pair(le, i));
        }

        int np = p.size();
        if(np == 0)
            return 0;
        i = 0;
        count += (p[i].second - p[i].first) * (p[i].second - p[i].first + 1) / 2;
        i++;
        for( ; i < np; i++){
            if(p[i].first < p[i - 1].second){
                count -= (p[i - 1].second - p[i].first) * (p[i - 1].second - p[i].first + 1) / 2;
            }
            count += (p[i].second - p[i].first) * (p[i].second - p[i].first + 1) /  2;
        }
        return count;
    }
};