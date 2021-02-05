#define Mod 1000003

// Factorial Function
long long fact (int n) {
    
    if (n == 0 || n == 1)
        return 1;
    
    long long ans = 1;
    
    while (n > 1) {
    
        ans = (ans * n) % Mod;
        n--;
    }
    
    return ans;
}

// Calculating Power Under Modulus
long long modPow (long long a, long long n) {
    
    long long ans = 1;
    
    while (n > 0) {
        
        if (n & 1)
            ans = (ans * a) % Mod;
        
        a = (a * a) % Mod;
        n >>= 1;
    }
    
    return ans;
}

int Solution::findRank(string A) {
    
    int size = A.size();
    long long ans = 1, repeat, less_num, count;
    
    for (int i = 0; i < size; i++) { // Comparing each position to calculate
                                     // how many numbers greater can be formed
        
        less_num = 0;           // No of elements less than value at A[i] to
                                // calculate nos less than given number
        for (int j = i + 1; j < size; j++)
            if (A[j] < A[i])
                less_num++;
        
        vector<int> freq(256, 0);       // Frequency calculation of characters. 
                                        // 256 considers all characters
        for (int j = i; j < size; j++)
            freq[A[j]]++;
        
        repeat = 1;
        
        for (int j = 0; j < 256; j++)                   // removing Permutations of
            repeat = (repeat * fact(freq[j])) % Mod;    // repetitive characters
            
        repeat = modPow(repeat, Mod - 2); // Taking Modular Inverse using Fermat's little 
                                          // Theorem.
                                          // If Mod is not prime then use
                                          // Extended Euclidean Theorem
                                          // to calculate Modular Inverse
        
        count = (fact(size - i - 1) * less_num) % Mod; // Total numbers smaller than 
        count = (count * repeat) % Mod;                // given number whose i'th digit is
                                                       // less than A[i]
        ans = (ans + count) % Mod;          // Adding in final answer
    }
    
    return ans;
}