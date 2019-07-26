
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
	//path compression
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