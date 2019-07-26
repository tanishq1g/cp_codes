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
#include <iomanip>
#include <climits>
#include <list>

using namespace std;
#define MOD 1000000007
int n,m;
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
	int ans;
public:
	G_adj_list(int no_vertex){
		this -> no_vertex = no_vertex;
		arr = new Adj_list[no_vertex];
		time = 0;
		ans = 0;
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

	int dfs1(int v ,int * visited,int * arri, int * dep,int * nodes_in_subtree){
		visited[v] = 1;
		arri[v] = ++time;
		cout<<v<<' ';
		G_adj_list_node * temp;
		temp = arr[v].head;
		while(temp!=NULL){
			if(visited[temp->vertex] == 0){
				nodes_in_subtree[v] += dfs1(temp->vertex,visited,arri,dep,nodes_in_subtree);
				if(nodes_in_subtree[temp -> vertex] % 2 == 0){
					ans ++;
					cout<<"ans "<<temp->vertex<<" ans"<<' ';
				}
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
		for(int i=1; i<no_vertex; i++){
			visited[i] = 0;
			nodes_in_subtree[i] = 1;
		}
		nodes_in_subtree[v] = dfs1(v,visited,arri,dep,nodes_in_subtree);
		
		cout<<'\n';
		
		for(int i=1; i<no_vertex; i++){
			cout<<i<<"--"<<arri[i]<<"/"<<dep[i]<<' '<<nodes_in_subtree[i]<<'\n';
		}
		cout<<ans;
	}


	void print(){
		G_adj_list_node * temp;
		for(int i=1; i<no_vertex; i++){
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
	cin >> n >> m;
	n++;
	G_adj_list g(n);
	for(int i = 0; i < m; i++){
		int u,v;
		cin >> u>>v;
		g.add_edge(u,v);
	}
	//g.print();
	g.dfs(1);
	return 0;
}