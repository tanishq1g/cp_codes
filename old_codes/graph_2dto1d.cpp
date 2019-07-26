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
#include <stack>
using namespace std;
#define mod 1000000007
using namespace std;
char maze[505][505];
int st[505*505];
int ctr,n,m;
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
	bool dormant;
	Adj_list(){
		head = NULL;
		dormant = true;
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
		arr[src].dormant = false;
		arr[dest].dormant = false;
		G_adj_list_node * temp = new G_adj_list_node( dest);
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
	void dfs1(int v ,int * visited,int * arri, int * dep){
		visited[v] = 1;
		arri[v] = ++time;
		// cout<<v<<' ';
		st[ctr++] = v;
		G_adj_list_node * temp;
		temp = arr[v].head;
		while(temp!=NULL){
			if(visited[temp->vertex] == 0 && arr[temp->vertex].dormant == false)
				dfs1(temp->vertex,visited,arri,dep);
			temp = temp -> next;
		}
		dep[v] = ++time;
	}
	void dfs(int k){
		int visited[no_vertex];
		int arri[no_vertex];
		int dep[no_vertex];
		int time = 0;
		for(int i=0; i<no_vertex; i++){
			visited[i] = 0;
		}
		for(int i = 1; i < no_vertex; i++){
			if(arr[i].dormant == false){
				if(visited[i] == 0){
					ctr = 0;
					dfs1(i,visited,arri,dep);
					// cout<<'\n';
					// cout<<ctr<<'\n';
					if(ctr >= k){
						int t = 0;
						while(t != ctr - k){
							// cout<<st[t]<<' '<<(st[t]%m == 0 ? st[t]/m : st[t]/m + 1)<<' '<<(st[t]%m == 0 ? m : st[t]%m)<<'\n';
							maze[(st[t]%m == 0 ? st[t]/m : st[t]/m + 1)][(st[t]%m == 0 ? m : st[t]%m)] = 'X';
							t++;
						}
						break;
					}
				}
			}
		}
		G_adj_list_node * temp;
		// for(int i=0; i<no_vertex; i++){
		// 	if(arr[i].dormant == false)
		// 		cout<<i<<"--"<<arri[i]<<"/"<<dep[i]<<'\n';
		// }
	}


	void print(){
		G_adj_list_node * temp;
		for(int i=0; i<no_vertex; i++){
			temp = arr[i].head;
			cout<<"src : "<<i<<"/"<<arr[i].dormant<<" --"; 
			while ( temp != NULL){
				cout<<temp->vertex<<" ";
				temp = temp -> next;
			}
			cout<<'\n';
		}
	}
};

int main(){
	int k;
	cin >> n >> m >> k;
	G_adj_list g(n*m+1);
	for(int i = 1; i <=n; i++){
		for(int j = 1; j <=m; j++){
			cin >> maze[i][j];
		}
	}
	
	for(int i = 1; i < n ; i++){
		for(int j = 1; j < m ; j++){
			if(maze[i][j] == '.'){
				if(maze[i][j+1] == '.')
					g.add_edge(i*m-m+j,i*m-m+j+1);
				if(maze[i+1][j] == '.')
					g.add_edge((i+1)*m-m+j,i*m-m+j);
			}
		}
	}
	for(int i = 1; i < n; i++){
		if(maze[i][m] == '.'){
			if(maze[i+1][m] == '.')
				g.add_edge((i+1)*m,i*m);
		}
	}

	for(int j = 0; j < m; j++){
		if(maze[n][j] == '.'){
			if(maze[n][j+1] == '.')
				g.add_edge((n)*m-m+j,(n)*m-m+j+1);
		}
	}

	// g.print();
	if(k == 0)
		for(int i = 1; i <= n; i++){
			for(int j = 1; j <= m; j++){
				cout << maze[i][j];
			}
			cout<<'\n';
		}
	else{
		g.dfs(k);
		for(int i = 1; i <= n; i++){
			for(int j = 1; j <= m; j++){
				if(maze[i][j] == '.')
					cout<<'X';
				else if(maze[i][j] == 'X')
					cout<<'.';
				else
					cout << maze[i][j];
			}
			cout<<'\n';
		}
	}
}