int *visted = new int[MAX_VERTIX_NUM];
std::queue<int> my_queue;

int FirstNeihber(Graph &G,int i);
int NextNeighbor(Graph &G,int i,int j);

void BFS(Graph &G,int v){
	visted[v] = true;
	my_queue.push(v);

	while(!my_queue.empty()){
		v = my_queue.front();
		my_queue.pop();
		for(int w=FirstNeihber(G,v);w>=0;w=NextNeighbor(G,v,w)){
			if(!visted[w]){
				visted[w] = true;
				my_queue.push(w);
			}
		}
	}
}

void BFSTraverse(Graph &G){
	for(int i=0;i<MAX_VERTIX_NUM;i++)
		visted[i] = false;


	for(int i=0;i<G.vexnum;i++)
		if(!visted[i])
			BFS(G,i);
}
