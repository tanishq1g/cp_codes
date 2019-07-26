#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>
#include <ctime>
#include <cstdlib>
#include <climits>
using namespace std;

int rangesumquery(int *t,int start, int end, int qlow, int qhigh, int pos){
    if(qlow <= start && qhigh >= end)
        return t[pos];
    if( qlow > end || qhigh <start)
        return 0;
    int mid = (start + end)/2;
    return rangesumquery(t,start,mid,qlow,qhigh,2*pos+1) + rangesumquery(t,mid+1,end,qlow,qhigh,2*pos+2);
}





void seg_sum_build(long int *t,int s,long int *a , int n, int start, int end, int pos){
    if( start == end){
        t[pos] = a[start];
    }
    else{
        int mid = ( start + end )/2;
        seg_sum_build(t,s,a,n,start,mid,2*pos+1);
        seg_sum_build(t,s,a,n,mid+1,end,2*pos+2);
       t[pos] = t[2*pos+1] + t[2*pos+2];
    }
}

void seg_updaterangelazy(long int *t,long int *lazy,int start,int end, int qlow, int qhigh, int val, int pos){
    if(start > end)
        return;
    if(lazy[pos] != 0){
        t[pos] += lazy[pos];
        if ( start != end ){
            lazy[2*pos + 1] += lazy[pos];
            lazy[2*pos + 2] += lazy[pos];
        }
        lazy[pos]=0;
    }
    if(start > qhigh || end < qlow)
        return;
    if(qlow <= start&& qhigh >= end ){
        t[pos] += (end - start + 1) * val;
        if ( start != end){
            lazy[2*pos + 1] += val;
            lazy[2*pos + 2] += val;
        }
        return;
    }
    int mid = (start + end)/2;
    seg_updaterangelazy(t,lazy,start,mid,qlow,qhigh,val,2*pos+1);
    seg_updaterangelazy(t,lazy,mid+1,end,qlow,qhigh,val,2*pos+2);
    t[pos] = t[2*pos + 1] + t[2*pos + 2];
}

long int query_range(long int * t,long int *lazy,int start,int end, int qlow, int qhigh,int pos){
    if(start > end)
        return 0;
    if(lazy[pos] != 0){
        t[pos] += (end - start + 1) * lazy[pos];
        if ( start != end ){
            lazy[2*pos + 1] += lazy[pos];
            lazy[2*pos + 2] += lazy[pos];
        }
        lazy[pos]=0;
    }
    if(qlow <= start && qhigh >= end)
        return t[pos];
    if( qlow > end || qhigh <start)
        return 0;
    int mid = (start + end)/2;
    return query_range(t,lazy,start,mid,qlow,qhigh,2*pos+1) + query_range(t,lazy,mid+1,end,qlow,qhigh,2*pos+2);
}


int main(){
    int n;
    cin>>n;
    long int a[n];
    for ( int i =0; i < n; i++)
        cin>>a[i];
    int seg_s=2*pow(2,ceil(log2(n)))-1;
    long int seg_a[seg_s];
    long int seg_lazy[seg_s];
    for(int i=0; i<seg_s; i++){
        seg_lazy[i]=0;
    }
    seg_sum_build(seg_a,seg_s,a,n,0,n-1,0);

    for(int i=0; i<seg_s; i++)
        cout<<seg_a[i]<<' ';
    cout<<'\n';
    cout<<query_range(seg_a,seg_lazy,0,n-1,1,4,0)<<'\n';
    seg_updaterangelazy(seg_a,seg_lazy,0,n-1,0,3,2,0);
    for(int i=0; i<seg_s; i++)
        cout<<seg_lazy[i]<<' ';
    cout<<'\n';
    cout<<query_range(seg_a,seg_lazy,0,n-1,1,4,0)<<'\n';
    for(int i=0; i<seg_s; i++){cout<<seg_a[i]<<' ';}cout<<"\n";
    for(int i=0; i<seg_s; i++)
        cout<<seg_lazy[i]<<' ';
    cout<<'\n';
}



