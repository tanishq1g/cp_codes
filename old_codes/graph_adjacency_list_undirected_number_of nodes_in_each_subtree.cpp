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
	G_adj_list_node * next;
	G_adj_list_node(int vertex = 0){
		this -> vertex = vertex;
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

	void add_edge(int src, int dest){
		G_adj_list_node * temp = new G_adj_list_node( dest);
		\
		temp -> next = arr[src].head;
		arr[src].head = temp;
		temp = new G_adj_list_node( src);
		temp -> next = arr[dest].head;
		arr[dest].head = temp;
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

	int dfs1(int v ,int * visited,int * arri, int * dep,int * nodes_in_subtree){
		visited[v] = 1;
		arri[v] = ++time;
		cout<<v<<' ';
		G_adj_list_node * temp;
		temp = arr[v].head;
		while(temp!=NULL){
			if(visited[temp->vertex] == 0){
				nodes_in_subtree[v] += dfs1(temp->vertex,visited,arri,dep,nodes_in_subtree);
			}
			temp = temp -> next;
		}
		dep[v] = ++time;
		return nodes_in_subtree[v];
	}
	void dfs(int v){
		int visited[no_vertex];
		int arri[no_vertex];
		int dep[no_vertex];
		int nodes_in_subtree[no_vertex];
		int time = 0;
		for(int i=0; i<no_vertex; i++){
			visited[i] = 0;
			nodes_in_subtree[i] = 1;
		}
		nodes_in_subtree[v] = dfs1(v,visited,arri,dep,nodes_in_subtree);
		
		cout<<'\n';
		
		for(int i=0; i<no_vertex; i++){
			cout<<i<<"--"<<arri[i]<<"/"<<dep[i]<<' '<<nodes_in_subtree[i]<<'\n';
		}
		
	}


	void print(){
		G_adj_list_node * temp;
		for(int i=0; i<no_vertex; i++){
			temp = arr[i].head;
			cout<<"src : "<<i<<"--"; 
			while ( temp != NULL){
				cout<<temp->vertex<<" ";
				temp = temp -> next;
			}
			cout<<'\n';
		}
	}
};


int main(){
	G_adj_list g(5);
    g.add_edge(0, 1);
    g.add_edge(0, 4);
    g.add_edge(1, 2);
    g.add_edge(1, 3);
    g.add_edge(1, 4);
    g.add_edge(2, 3);
    g.add_edge(3, 4);
    g.print();
    g.dfs(0);
    g.bfs_lev_pi(0);
}













