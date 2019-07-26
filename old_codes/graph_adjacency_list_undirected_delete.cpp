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
int deg[100001];
struct pairs{
		int node;
		int deg;
	};
	bool funcstruct(const pairs &a,const pairs &b){
		return a.deg>b.deg;
	}
class G_adj_list_node{

public:
	int vertex;
	G_adj_list_node * next;
	G_adj_list_node * oth;
	bool ignore;
	G_adj_list_node(int vertex = 0){
		this -> vertex = vertex;
		next = NULL;
		oth=NULL;
		ignore = false;
	}
};


class Adj_list{
public:
	list <G_adj_list_node *> head;
};


class G_adj_list{

private:
	
	int no_vertex;
	int no_edges;
	Adj_list * arr;
	int time;
public:
	G_adj_list(int no_vertex, int no_edges){
		this -> no_vertex = no_vertex;
		this -> no_edges = no_edges;
		arr = new Adj_list[no_vertex];
		memset(deg,0, no_vertex);
		time = 0;
	}

	void add_edge(int src, int dest){
		G_adj_list_node * temp = new G_adj_list_node( dest);
		arr[src].head.push_front(temp);
		G_adj_list_node * temp2 = temp;
		temp = new G_adj_list_node( src);
		arr[dest].head.push_front(temp);
		deg[src]++;
		deg[dest]++;
		temp2 -> oth = temp;
		temp -> oth = temp2;
	}

	void delete_edges(int ind){
		// cout<<"DELETE "<<ind <<'\n';
		deg[ind] = 0;
		list<G_adj_list_node *>::const_iterator temp;
		temp = arr[ind].head.begin();
		while (arr[ind].head.size()){
			if((*temp)-> ignore == false)
				(*temp) -> oth -> ignore = true;
			temp = arr[ind].head.erase(temp);
		}
		// print();
	}
	void bfs1(int v,int *visited,pairs *comp,int ptr){
		queue <int> qu;
		visited[v] = 1;
		qu.push(v);
		G_adj_list_node * temp;
		int max = 0;
		while(!qu.empty()){
			v = qu.front();
			qu.pop();
			list<G_adj_list_node *>::const_iterator temp;
			temp = arr[v].head.begin();
			int k=0;
			while ( temp != arr[v].head.end()){
				if((*temp) -> ignore == true){
					temp++;
					continue;
				}
				k++;
				if(visited[(*temp) -> vertex] == 0){
					qu.push((*temp) -> vertex);
					visited[(*temp) -> vertex] = 1;
				}
				++temp;
			}
			deg[v] = k;
			if(deg[v] >= max){
				max = deg[v];
				comp[ptr].node = v;
				comp[ptr].deg = deg[v];
			}
		}
	}
	int bfs(int ind){
		// cout<<"BFS\n";
		int visited[no_vertex];
		pairs comp[no_vertex];
		int ptr = 0;
		memset(visited,0,sizeof visited);
		for(int i=1; i<no_vertex; i++){
			if(visited[i] == 0){
				bfs1(i,visited,comp,ptr);
				ptr++;
			}
		}
		// for(int i=0; i<ptr; i++)cout<<comp[i]<<' ';cout<<'\n';
		if(ptr == 1){
			return 0;
		}
		else{
			sort(comp,comp+ptr,funcstruct);
			for(int i=0; i<ptr-1; i++){
				add_edge(comp[i].node,comp[i+1].node);
			}
			// cout<<"adding edge\n";
			// print();
			return ptr-1;
		}
	}
	void func(){
		for(int i=0; i<no_vertex-1; i++){
			int flag = 0;
			for(int j=1; j<no_vertex; j++){
				if(deg[j] <= i){
					flag=1;
					delete_edges(j);
				}
			}
			// cout<<"ans ";
			if(flag == 0)
				cout<<"0 ";
			else{
				cout<<bfs(i)<<' ';
			}
		}
		cout<<'\n';
	}

	void print(){
		list<G_adj_list_node *>::const_iterator temp;
		for(int i=1; i<no_vertex ; i++){
			temp = arr[i].head.begin();
			cout<<"src : "<<i<<"--"; 
			while ( temp != arr[i].head.end()){
				cout<<(*temp)-> vertex<<"/"<<(*temp)->ignore<<" ";
				temp++;
			}
			cout<<'\n';
		}
		for(int i=1; i<no_vertex; i++){
			cout<<deg[i]<<' ';
		}
		cout<<'\n';
	}
};


int main(){
	int t;
	cin >> t;
	for(int w=0; w<t; w++){
		int n,m;
		cin >> n >> m;
		n++;
		G_adj_list g(n,m);
		int u,v;
		while(m){
			cin >> u >> v;
			g.add_edge(u,v);
			m--;
		}
		g.func();
	}
}


