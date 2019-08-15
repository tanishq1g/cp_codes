class Solution {
public:
    int mySqrt(int x) {
        // method 1
        // for (int i = x / 2; i > 0; i--){
        //     if(i * i <= x)
        //         return i;
        // }

        // method 2
        if(x == 1)
            return 1;
        if(x == 0)
            return 0;
        int le = 1;
        int ri = x / 2;
        int m;
        while(le <= ri){
            m = (le + ri) / 2;
            // cout << le << ' ' << m << ' ' << ri << '\n';
            if(m > x / m){
                ri = m - 1;
            }
            else if(m + 1 <= (x / (m + 1))){
                le = m + 1;
            }
            else
                break;
        }
        m = (le + ri) / 2;
        return m;
    }

    // recursion with bit shifts
    class Solution:
    def mySqrt(self, x):
        if x < 2:
            return x
        
        left = self.mySqrt(x >> 2) << 1
        right = left + 1
        return left if right * right > x else right

    
};
