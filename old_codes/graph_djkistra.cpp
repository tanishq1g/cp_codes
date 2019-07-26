#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>
#include <ctime>
#include <cstdlib>
#include <queue>
using namespace std;

//for list node
class G_adj_list_node{

public:
	int vertex;
	int weight;
	G_adj_list_node * next;
	G_adj_list_node(int vertex = 0, int weight = 0){
		this -> vertex = vertex;
		this -> weight = weight;
		next = NULL;
	}
};

//for array node
class Adj_list{
public:
	G_adj_list_node * head;
	Adj_list(){
		head = NULL;
	}
};


class Edge{
public:
	int src,dest,weight;
};


class Min_heap{
	Edge * arr;
	int no_edge;
	int len;
	int * pos;
public:
	Min_heap(int no_edge,int no_vertex){
		this -> no_edge = no_edge;
		this -> no_vertex = no_vertex;
		arr = new Edge[no_edge];
		pos = new int[no_vertex];
		len = 0;
	}

	void bottom_up_heapify(int in){
		int p=(in-1)/2;
		Edge temp;
		while(in > 0){
			if(arr[p].weight > arr[in].weight){
				temp = arr[p];
				arr[p] = arr[in];
				arr[in] = temp;
			}
			else
				break;
			in = p;
			p = (in-1)/2;
		}
	}

	void top_bottom_heapify(int in){
		int l = 2*in +1;
		int r = 2*in +2,j;
		Edge temp;
		if(l == len-1 && arr[in].weight > arr[l].weight){
			temp = arr[l];
			arr[l] = arr[in];
			arr[in] = temp;
			return;
		}
		while( r < len){
			if(arr[l].weight < arr[r].weight)
				j=l;
			else
				j=r;
			if(arr[in].weight < arr[j].weight)
				break;
			else{
				temp = arr[j];
				arr[j] = arr[in];
				arr[in] = temp;
			}
			in=j;
			l=2*in+1;
			r=2*in+2;
			if(l == len-1 && arr[in].weight > arr[l].weight){
				temp = arr[l];
				arr[l] = arr[in];
				arr[in] = temp;
				return;
			}
		}
	}

	void insert(int src, int dest, int weight){
		arr[len].src = src;
		arr[len].dest = dest;
		arr[len].weight = weight;
		len++;
		bottom_up_heapify(len-1);
	}

	Edge delete_min(){
		Edge temp = arr[len-1];
		arr[len-1] = arr[0];
		arr[0] = temp;
		len--;
		top_bottom_heapify(0);
		return arr[len];
	}

	bool empty(){
		if(len == 0)
			return true;
		else 
			return false;
	}

	void print(){
		for(int i=0; i<len; i++){
			cout<<"src "<<arr[i].src<<" dest "<<arr[i].dest<<" weight "<<arr[i].weight<<'\n';
		}
	}
};
