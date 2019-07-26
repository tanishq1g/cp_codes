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
int deg[102];
int dd[102][102];
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
	int count;
public:
	G_adj_list(int no_vertex, int no_edges){
		this -> no_vertex = no_vertex;
		this -> no_edges = no_edges;
		arr = new Adj_list[no_vertex];
		memset(deg,0, no_vertex);
		count = 0;
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

	void delete_edges(){
		queue <int> q;
		for(int i=1; i<no_vertex; i++){
			if(dd[1][i] == 1){
				int ind = i;
				q.push(ind);
				list<G_adj_list_node *>::const_iterator temp;
				temp = arr[ind].head.begin();
				while (arr[ind].head.size()){
					if((*temp)-> ignore == false){
						(*temp) -> oth -> ignore = true;
						q.push((*temp) -> vertex);
					}
					temp = arr[ind].head.erase(temp);
				}
			}
		}
		while(!q.empty()){
			int x = q.front();
			q.pop();
			dd[deg[x]][x] = 0;
			dd[deg[x]][0]--;
			deg[x] -- ;
			dd[deg[x]][x] = 1;
			dd[deg[x]][0]++;
		}
		//print();
	}
	
	void func(){
		for(int i=0; i<no_vertex; i++){
			dd[i][0] = 0;
		}
		for(int i=1; i<no_vertex; i++){
			dd[deg[i]][i] = 1;
			dd[deg[i]][0]++;
		}
		//print();
		while(dd[1][0] != 0){
			count++;
			delete_edges();
		}
		cout << count;
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
		for(int i=0; i<no_vertex; i++){
			cout<<"deg "<<i<<" - ";
			for(int j=0; j<no_vertex; j++){
				cout<<dd[i][j]<<' ';
			}	
			cout<<'\n';
		}
	}
};
int main(){
	int n,m;
	cin >> n >> m;
	n++;
	G_adj_list g(n,m);
	for(int i=0; i<m; i++){
		int u,v;
		cin >> u>>v;
		g.add_edge(u,v);
	}
	g.func();
}


