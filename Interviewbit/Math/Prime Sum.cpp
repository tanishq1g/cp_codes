vector<int> Solution::primesum(int n) {
    // if(n == 4){
    //     return vector<int> {2, 2};
    // }
    vector<bool> sieve(n + 1, true);
    for(int i = 2; i < n; i++){
        if(sieve[i] == false)
            continue;
        for(int j = i + i; j < n; j += i){
            sieve[j] = false;
        }
    }

    int l = 2, r = n - 1;
    while(l <= r){
        while(sieve[l] != true){
            l++;
        }
        while(sieve[r] != true){
            r--;
        }
        if(l + r < n){
            l++;
        }
        else if(l + r > n){
            r--;
        }
        else{
            return vector<int> {l, r};
        }
    }
    return vector<int> {-1, -1};
}


// another approach

generate prime numbers then put them into Hash-Table 
iterate whole prime numbers list using i:
	if  i is prime and N - i is prime check using Hash-Table:
	    update global solution
End Loop

Return global solution 
