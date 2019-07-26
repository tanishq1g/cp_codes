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
public:
	Min_heap(int no_edge){
		this -> no_edge = no_edge;
		arr = new Edge[no_edge];
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

class G_adj_list{

private:
	int no_vertex;
	int no_edge;
	Adj_list * arr;
	int time;
public:
	G_adj_list(int no_vertex, int no_edge){
		this -> no_vertex = no_vertex;
		arr = new Adj_list[no_vertex];
		this -> no_edge = no_edge;
		time = 0;
	}

	void add_edge(int src, int dest, int weight){
		G_adj_list_node * temp = new G_adj_list_node( dest,weight);
		temp -> next = arr[src].head;
		arr[src].head = temp;

		temp = new G_adj_list_node( src, weight
			);
		temp -> next = arr[dest].head;
		arr[dest].head = temp;
	}

	void dfs1(int v ,int * visited,int * arri, int * dep){
		visited[v] = 1;
		arri[v] = ++time;
		cout<<v<<' ';
		G_adj_list_node * temp;
		temp = arr[v].head;
		while(temp!=NULL){
			if(visited[temp->vertex] == 0)
				dfs1(temp->vertex,visited,arri,dep);
			temp = temp -> next;
		}
		dep[v] = ++time;
	}
	void dfs(int v){
		int visited[no_vertex];
		int arri[no_vertex];
		int dep[no_vertex];
		int time = 0;
		for(int i=0; i<no_vertex; i++){
			visited[i] = 0;
		}
		dfs1(v,visited,arri,dep);
		cout<<'\n';
		G_adj_list_node * temp;
		for(int i=0; i<no_vertex; i++){
			cout<<i<<"--"<<arri[i]<<"/"<<dep[i]<<'\n';
		}
	}

	void prim(int v){
		int visited[no_vertex];
		for(int i=0; i<no_vertex; i++){
			visited[i] = 0;
		}
		Edge * result = new Edge[no_edge-1];
		int mst_e=0;
		Min_heap heap(no_edge);
		G_adj_list_node * temp;
		temp = arr[v].head;
		while(temp != NULL){
			cout<<temp -> vertex<<'\n';
			heap.insert(v, temp -> vertex, temp -> weight);
			temp = temp -> next;
		}
		heap.print();
		visited[v] = 1;
		Edge e;
		while(!heap.empty()){
			e = heap.delete_min();
			if(visited[e.dest] == 1)
				continue;
			result[mst_e].src = e.src;
			result[mst_e].dest = e.dest;
			result[mst_e].weight = e.weight;
			mst_e++;
			visited[e.dest] = 1;
			temp = arr[e.dest].head;
			while(temp != NULL){
				if(visited[temp -> vertex]==0){
					heap.insert(e.dest, temp -> vertex, temp -> weight);
				}
				temp = temp -> next;
			}
			heap.print();
		}
		cout<<"ans\n";
		for(int i=0; i<mst_e; i++)
			cout<<"src "<<result[i].src<<" dest "<<result[i].dest<<" weight "<<result[i].weight<<'\n';
	}
	void print(){
		G_adj_list_node * temp;
		for(int i=0; i<no_vertex; i++){
			temp = arr[i].head;
			cout<<"src : "<<i<<"--"; 
			while ( temp != NULL){
				cout<<temp->vertex<<"/"<<temp->weight<<" ";
				temp = temp -> next;
			}
			cout<<'\n';
		}
	}
};

int main(){
	G_adj_list g(4,5);
    g.add_edge(0, 1, 10);
    g.add_edge(0, 2, 6);
    g.add_edge(0, 3, 5);
    g.add_edge(1, 3, 15);
    g.add_edge(2, 3, 4);
    g.print();
    g.prim(0);
}