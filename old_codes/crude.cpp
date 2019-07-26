__builtin_popcount = int
__builtin_popcountl = long int
__builtin_popcountll = long long or unsigned long long


transform(f.begin(),f.end(),f.begin(),::toupper);
		transform(l.begin(),l.end(),l.begin(),::toupper);
		
struct dragon{
	int strength;
	int bonus;
};
bool funcstruct(const dragon &a,const dragon &b){
	if(a.strength == b.strength)
		return b.bonus < a.bonus;
	return a.strength < b.strength;
}

// void swap(int *a,int i,int j){
// 	int temp=a[i];
// 	a[i]=a[j];
// 	a[j]=temp;
// }	

// bool func(int a,int b){return a>b;}
// struct order{
// 	int t;
// 	int d;
// };
bool funcstruct(pairs &a,pairs &b){
	return a.deg>b.deg;
}
long int binarysearch(long int * a,int first,int last,int key){
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
	return first;
}

string addintto_string(string s,int t){
	int l = s.length();
	int no;
	for(int i=l-1; i>=0; i--){
		no = s[i] - 48 + t;
		if(no > 9){
			s[i] = no%10 + 48;
			t = no/10;
			if(i == 0)
				s = to_string(t) + s ;
		}
		else{
			s[i] = no + 48;
			break;
		}
	}
	return s;
}


 #define MOD 1000000007
unsigned long long power(int n,int k){
    if(k == 0)
        return 0;
    if( n== 1)
        return 1;
    if(n == 0)
        return 1;
    unsigned long long result,pow;
    result=n%MOD;
    pow=1;
    while(pow*2<=k)
    {
        pow=pow*2;
        result=(result*result);
        result=result%MOD;
    }

    if(k-pow!=0)
        result=result*power(n, k-pow);
    result=result%MOD;
    return result;
}




// decimal to hexadecimal

long aa;
	cin >> aa;
	string s,temp;
			int t = (aa % 16) ;
			if(t >= 0 && t <= 9)
				s = t + '0';
			else
				s = t -10 + 'A';
			aa /= 16;
			while(aa){
				t = (aa % 16) ;
				if(t >= 0 && t <= 9){
					temp = t + '0';
					s = temp + s;
				}
				else{
					temp = t - 10 + 'A';
					s = temp + s;
				}
				aa /= 16;
			}
			cout << s << ' ';


//array of lower bits

lowbit[0] = 0;
	int p = 1;
	for(int i = 1; i < 100001; i+=2){
		lowbit[i] = 1;
	}
	for(int i = 2; i < 100001; i+=2){
		lowbit[i] = 2;
	}
	while( (1<<p) < 100001){
		for(int i = (1<<p); i < 100001; i+=(1<<p)){
			lowbit[i] = 1<<p;
		}
		p++;
	}

long long solving_quadratic(long long a,long long b,long long c){
	long long d = sqrt(b*b - 4*a*c);
	return min((-b + d)/a ,(-b - d)/a);
}
#include <iostream>     // std::cout
#include <algorithm>    // std::unique_copy, std::sort, std::distance
#include <vector>       // std::vector

bool myfunction (int i, int j) {
  return (i==j);
}

int main () {
  int myints[] = {10,20,20,20,30,30,20,20,10};
  std::vector<int> myvector (9);                            // 0  0  0  0  0  0  0  0  0

  // using default comparison:
  std::vector<int>::iterator it;
  it=std::unique_copy (myints,myints+9,myvector.begin());   // 10 20 30 20 10 0  0  0  0
                                                            //                ^

  std::sort (myvector.begin(),it);                          // 10 10 20 20 30 0  0  0  0
                                                            //                ^

  // using predicate comparison:
  it=std::unique_copy (myvector.begin(), it, myvector.begin(), myfunction);
                                                            // 10 20 30 20 30 0  0  0  0
                                                            //          ^

  myvector.resize( std::distance(myvector.begin(),it) );    // 10 20 30

  // print out content:
  std::cout << "myvector contains:";
  for (it=myvector.begin(); it!=myvector.end(); ++it)
    std::cout << ' ' << *it;
  std::cout << '\n';

  return 0;
}

int powersof2[15]={1,2,4,8,16,32,64,128,256,512,1024,2048,4096,8192,16384};
