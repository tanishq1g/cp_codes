int na, nb, nc;
bool func(string &a, string &b, string &c, int x, int y, int z){
    
    if(z == nc)
        return true;
    bool aa = false;
    bool bb = false;
    if(x < na && a[x] == c[z]){
        aa = func(a, b, c, x + 1, y, z + 1);
    }
    if(y < nb && b[y] == c[z]){
        bb = func(a, b, c, x, y + 1, z + 1);
    }
    return aa || bb;
}
int Solution::isInterleave(string a, string b, string c) {
    na = a.size();
    nb = b.size();
    nc = c.size();
    return func(a, b, c, 0, 0, 0);
}
