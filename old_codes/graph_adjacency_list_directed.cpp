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


class Adj_list{
public:
	G_adj_list_node * head;
	Adj_list(){
		head = NULL;
	}
};


class G_adj_list{

private:
	int no_vertex;
	Adj_list * arr;
	int time;
public:
	G_adj_list(int no_vertex){
		this -> no_vertex = no_vertex;
		arr = new Adj_list[no_vertex];
		time = 0;
	}

	void add_edge(int src, int dest, int weight){
		G_adj_list_node * temp = new G_adj_list_node( dest,weight);
		temp -> next = arr[src].head;
		arr[src].head = temp;
	}

	void bfs(int v){
		int visited[no_vertex];
		for(int i=0; i<no_vertex; i++){
			visited[i] = 0;
		}
		queue <int> qu;
		visited[v] = 1;
		qu.push(v);
		G_adj_list_node * temp;
		while(!qu.empty()){
			v = qu.front();
			qu.pop();
			cout<<v<<' ';
			temp = arr[v].head;
			while(temp != NULL){
				if(visited[temp -> vertex] == 0){
					qu.push(temp -> vertex);
					visited[temp -> vertex] = 1;
				}
				temp = temp -> next;
			}
		}
		cout<<'\n';
	}

	void bfs_lev_pi(int v){
		int visited[no_vertex];
		int level[no_vertex];
		int pi[no_vertex];
		for(int i=0; i<no_vertex; i++){
			visited[i] = 0;
		}
		queue <int> qu;
		visited[v] = 1;
		level[v] = 0;
		pi[v] = v;
		qu.push(v);
		G_adj_list_node * temp;
		int cur;
		while(!qu.empty()){
			v = qu.front();
			qu.pop();
			cout<<v<<' ';
			temp = arr[v].head;
			while(temp != NULL){
				cur = temp -> vertex;
				if(visited[cur] == 0){
					qu.push(cur);
					visited[cur] = 1;
					pi[cur] = v;
					level[cur] = level[pi[cur]] + 1;
				}
				temp = temp -> next;
			}
		}
		cout<<'\n';
		for(int i=0; i<no_vertex; i++){
			cout<<"node - "<<i<<" level - "<<level[i]<<" pi - "<<pi[i]<<'\n';
		}
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
	G_adj_list g(6);
    g.add_edge(0, 3, 0);
    g.add_edge(0, 2, 1);
    g.add_edge(1, 0, 2);
    g.add_edge(1, 2, 3);
    g.add_edge(2, 3, 4);
    g.add_edge(2, 4, 5);
    g.add_edge(3, 5, 6);
    g.add_edge(5, 4, 6);   
    g.add_edge(4, 0, 6);   
    g.print();
    g.dfs(0);
    g.bfs_lev_pi(0);
}













