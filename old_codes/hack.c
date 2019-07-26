#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

void merge(unsigned long long int *a,unsigned long long int *b, int start, int mid , int end,unsigned long long int *swaps){
    int i,j,k;
    int r=0;
    for(i=start,j=mid+1,k=start;i<=mid && j<=end;k++){
        if(a[i]>a[j]){
            b[k]=a[j++];
            r++;
        }
        else{
            b[k]=a[i++];
            (*swaps)+=r;
        }
    }
    while(i<=mid){
        b[k++]=a[i++];
        (*swaps)+=r;
    }
    while(j<=end)
        b[k++]=a[j++];
    for(i=start;i<=end;i++)
        a[i]=b[i];
    
}
void mergesort(unsigned long long int *a,unsigned long long int *b,int start, int end,unsigned long long int *swaps){
    if(start>=end);
    else{
        int mid;
        mid=start+(end-start)/2;
        mergesort(a,b,start,mid,swaps);
        mergesort(a,b,mid+1,end,swaps);
        merge(a,b,start,mid,end,swaps);

    }

}
int main() {
    int t;
    scanf("%d",&t);
    unsigned long long int swaps[t];
    for(int i=0;i<t;i++)
        swaps[i]=0;
    for(int i=0;i<t;i++){
        int n;
        unsigned long long int *a,*b;
        scanf("%d",&n);
        a=(unsigned long long int *)malloc(sizeof(unsigned long long int)*n);
        b=(unsigned long long int *)malloc(sizeof(unsigned long long int)*n);
        for(int j=0;j<n;j++){
            scanf("%llu",&a[j]);
        }
        mergesort(a,b,0,n-1,&swaps[i]);

    }
    for(int i=0;i<t;i++){
        printf("%llu\n",swaps[i]);
        
    }

    return 0;
}
