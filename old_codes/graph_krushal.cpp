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

// for edge node used in krushal
class Edge{
public:
	int src,dest,weight;
};
bool sort_func(Edge e1, Edge e2){
	return e1.weight < e2.weight;
}

//union node
class Union_struct{
public:
	int parent;
	int rank;
	Union_struct(){
		rank=1;
	}
};

//union data structure used in krushal
class Union{
	int no_vertex;
	Union_struct * arr;
public:
	Union(int no_vertex){
		this -> no_vertex = no_vertex;
		arr = new Union_struct[no_vertex];
		for(int i=0; i<no_vertex; i++){
			arr[i].parent = i;
		}
	}

	int find_root(int v){
		if ( arr[v].parent != v)
			arr[v].parent = find_root(arr[v].parent);
		return arr[v].parent;
	}

	void union_2(int v1,int v2){
		int p1 = find_root(v1);
		int p2 = find_root(v2);
		cout<<p1<<' '<<p2<<'\n';
		if( arr[p1].rank > arr[p2].rank){
			arr[p2].parent = p1;
			arr[p1].rank += arr[p2].rank;
		}
		else{
			arr[p1].parent =p2;
			arr[p2].rank += arr[p1].rank;
		}
		for(int i=0; i<no_vertex; i++){
			cout<<i<<" -- "<<arr[i].parent<<' '<<arr[i].rank<<'\n';
		}
	}
};


class G_adj_list{

private:
	int no_vertex;
	int no_edge;
	Adj_list * arr;
	Edge * k_arr;
	int ctr;
	int time;
public:
	G_adj_list(int no_vertex, int no_edge){
		this -> no_vertex = no_vertex;
		arr = new Adj_list[no_vertex];
		this -> no_edge = no_edge;
		k_arr = new Edge[no_edge];
		time = 0;
		ctr=0;
	}

	void add_edge(int src, int dest, int weight){
		G_adj_list_node * temp = new G_adj_list_node( dest,weight);
		temp -> next = arr[src].head;
		arr[src].head = temp;

		temp = new G_adj_list_node( src, weight
			);
		temp -> next = arr[dest].head;
		arr[dest].head = temp;

		k_arr[ctr].src = src;
		k_arr[ctr].dest = dest;
		k_arr[ctr].weight = weight;
		ctr++;
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


	void kruskal(){
		sort(k_arr,k_arr+ctr,sort_func);
		for(int i=0; i<ctr; i++)
			cout<<k_arr[i].weight<<' ';
		cout<<'\n';
		Union u(no_vertex);
		Edge * result = new Edge[no_edge-1];
		Edge * newedge;
		int mst_e=0;
		for(int i=0; i<no_edge; i++){
			int x = u.find_root(k_arr[i].src);
			int y = u.find_root(k_arr[i].dest);
			if ( x != y){
				result[mst_e] = k_arr[i];
				mst_e++;
				u.union_2(k_arr[i].src,k_arr[i].dest);
			}
			if(mst_e == no_edge - 1)
				break;
			cout<<i<<'\n';
		}
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
    g.kruskal();
}