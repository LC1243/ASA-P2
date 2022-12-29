#include <iostream>
#include <vector>
#include <algorithm>

int V, E;
int M;
bool input = true;

std::vector<std::pair<int, std::pair<int, int>>> train_lines;

// <Parent, Cost>
std::vector<std::pair<int, int>> tree;

void getInput() {
    int u, v, w;
    if(scanf("%d\n", &V) != 1)
		return;
	if(scanf("%d\n", &E) != 1)
		return;
    for(int i = 0; i < E; i++) {
        if(scanf("%d %d %d", &u, &v, &w) != 3) 
			return;
		//make sets
		if(u < 1 || u > V || v < 1 || v > V)
			input = false;
		train_lines.push_back(std::make_pair(w, std::make_pair(u, v))); 

    }
}

// Cria a árvore
void makeSet(){
	for(int i = 0; i < V; i++){
		tree.push_back(std::make_pair(i, 0) );
	}
}

int findSet(int vertex){
	int parent = tree[vertex].first;

	if(vertex != parent)
		parent = findSet(parent);

	return parent;
}

void Link(int u, int v){
	if(tree[u].second > tree[v].second)
		tree[v].first = u;

	else{
		tree[u].first = v;

		if(tree[u].second == tree[v].second)
			tree[v].second++;
	}
}

// Encontra a união entre vértices
void Union(int v1, int v2){
	Link(findSet(v1), findSet(v2));
}

void displayTree(){
	for(int i = 0; i < V; i++){
		std::cout << tree[i].first << " " << tree[i].second << std::endl;
	}
}

// Função Principal
int maximizeExchanges() {
	int max_exchanges = 0;

	makeSet();

	// Sort em ordem inversa
	std::sort(train_lines.rbegin(), train_lines.rend());
	
	for(int i = 0; i < E; i++){

		// train_lines[i].second - Arco<u,v>
		if( findSet(train_lines[i].second.first - 1) != findSet(train_lines[i].second.second - 1) ){

			Union(train_lines[i].second.first - 1, train_lines[i].second.second - 1);

			max_exchanges += train_lines[i].first;
		}

	} 
   
	return max_exchanges;
}

int main() {
	int n = 0;
	getInput();

	if(V < 1 || E < 0 || input == false) {
		printf("%d\n", n);
		return 0;
	}
	
	printf("%d\n", maximizeExchanges());

	return 0;
}
