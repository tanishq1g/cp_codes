#include <stdio.h>
int binarysearch(int * a,int first,int last,int key){
	int mid;
	while(first<=last){
		mid=(first+last)/2;
		if (a[mid]==key)
			return mid;
		else if(a[mid]<key)
			first=mid+1;
		else
			last=mid-1;
	
	}
	return -1;

}
int Solution::sqrt(int n) {
    int mi = 1, ma = n, mid, sq;
    if(n == 1)
        return 1;
    while(mi < ma){
        cout << mi << ' ' << ma << '\n';
        
        mid = (ma + mi) / 2;
        sq = mid * mid;
        if(sq > n){
            ma = mid;
        }
        else if(sq < n){
            mi = mid + 1;
        }
        else 
            return mid;
    }
    return mi - 1;
}


int main(){
	int a[10];
	for ( int i = 0 ;i<10;i++){
		fflush(stdin);
		scanf("%d",&a[i]);
	}
	printf("%d",binarysearch(a,0,9,8));
	
	return 0;
}
int Solution::sqrt(int n) {
    if(n == 1)
        return 1;
    int mi = 1, ma = n, mid, sq;
    while(mi < ma){ ///////////////////////////////////////////////
        // cout << mi << ' ' << ma << '\n';
        if(ma > INT_MAX - mi){
            mid = floor(floor(mi / 2.0) + floor(ma / 2.0));
            // cout << floor(mi / 2.0) + floor(ma / 2.0) << ' ' << mid << '\n';
        }
        else
            mid = (ma + mi) / 2;
        if(mid > INT_MAX / mid){
            ma = mid;
            continue;
        }
        else
            sq = mid * mid;
        if(sq > n){
            ma = mid; //////////////////////////////////////////////////
        }
        else if(sq < n){
            mi = mid + 1;
        }
        else 
            return mid;
    }
    return mi - 1;
}


int Solution::sqrt(int n) {
    if(n == 1)
        return 1;
    int mi = 1, ma = n, mid, sq;
    while(mi <= ma){ /////////////////////////////////////////////////////////
        // cout << mi << ' ' << ma << '\n';
        if(ma > INT_MAX - mi){
            mid = floor(floor(mi / 2.0) + floor(ma / 2.0));
            // cout << floor(mi / 2.0) + floor(ma / 2.0) << ' ' << mid << '\n';
        }
        else
            mid = (ma + mi) / 2;
        if(mid > INT_MAX / mid){
            ma = mid - 1;
            continue;
        }
        else
            sq = mid * mid;
        if(sq > n){
            ma = mid - 1;/////////////////////////////////////////////
        }
        else if(sq < n){
            mi = mid + 1;
        }
        else 
            return mid;
    }
    return mi - 1;
}
