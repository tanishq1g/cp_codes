#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
unsigned long long fans=0;

vector<unsigned long long> k;
vector< vector<int> > info;

int n;

void create(int x,vector<int> &comp,vector<int> &size){
	comp[x]=x;
	size[x]=0;
}

int fcomp(int x,vector<int> &comp,vector<int> &size){
	if(x!=comp[x])
		comp[x]=fcomp(comp[x],comp,size);
	return comp[x];
}

void merge(int a,int b,vector<int> &comp,vector<int> &size)
{
		a=fcomp(a,comp,size);
	b=fcomp(b,comp,size);
	if(size[a]>size[b])
		comp[b]=a;
	else if(size[a]<size[b])
		comp[a]=b;
	else{
		comp[a]=b;
		size[b]++;
	} 
}
int include(int i,vector<int> &comp,vector<int> &size)
{
int ans=0;
	if(info[i].size()==0)
		return 0;
	for(int w=0;w<info[i].size()-1;++w){	
		int p=info[i][w];
		int q=info[i][w+1];
		if(fcomp(p,comp,size)!=fcomp(q,comp,size)){
			ans++;
			merge(p,q,comp,size);
		}
	
	}
	return ans;
}

void make(int i){
	for(int p=0;p<64;++p)
		if(k[i]>>p&1){
			info[i].push_back(p);
		}
}

void makecomp(int x,vector<int> c,vector<int> s,int ans){
	if(x>=n){
		fans+=ans;
		return;
	}
	makecomp(x+1,c,s,ans);
	ans-=include(x,c,s);
	makecomp(x+1,c,s,ans);
}


int main(){
	int n;
	cin>>n;
	vector<unsigned long long> k(n);
	vector<int> comp(64);
	vector<int> size(64);
	for(int i=0;i<n;++i)
		cin>>k[i];
	for(int i=0;i<64;++i)
		create(i,comp,size);
	::k=k;
	::n=n;
	info.resize(n);
	for(int i=0;i<n;++i)
		make(i);
	makecomp(0,comp,size,64);
	cout<<fans;
	return 0;
}