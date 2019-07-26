#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <ctime>
#include <cstdlib>
#include <limits>
using namespace std;

void swap(int *a,int i,int j){
	int temp=a[i];
	a[i]=a[j];
	a[j]=temp;
}	