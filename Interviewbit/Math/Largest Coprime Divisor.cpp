int gcd(int a, int b) { 
    if (a == 0) 
        return b; 
    return gcd(b % a, a); 
} 
int Solution::cpFact(int a, int b) {
    if(gcd(a, b) == 1)
        return a;
    int x = gcd(a, b);
    while(x != 1){
        a = a / x;
        x = gcd(a, b);
    }
    return a;
}
