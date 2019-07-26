#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>
#include <ctime>
#include <cstdlib>
using namespace std;


class G_adj_matrix{
	int no_vertex;
	int adj_matrix[20];

public:
	G_adj_matrix(int no_vertex){
		this -> no_vertex = no_vertex;
		for(int i=0; i<no_vertex; i++){
			for(int j=0; j<no_vertex; j++){
				adj_matrix[i][j] = 0;
			}
		}
	}

	void insert_edge(int src, int dest){
		adj_matrix[src][dest] = 1;
		adj_matrix[dest][src] = 1;
	}

	void delete_edge(int src, int dest){
		adj_matrix[src][dest] = 0;
		adj_matrix[dest][src] = 0;
	}
}

1