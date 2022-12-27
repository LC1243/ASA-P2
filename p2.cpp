#include <iostream>
#include <vector>
#include <algorithm>

int V, E;
long long unsigned int M;

std::vector<std::pair<int, std::pair<int, int>>> train_lines;

// <Parent, Cost>
std::vector<std::pair<int, int>> tree;

void getInput() {
    int u, v, w;
    std::cin >> V;
    std::cin >> E;

    for(int i = 0; i < E; i++) {
        std::cin >> u >> v >> w;
		//make sets
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

// Funcção Principal
long long int maximizeExchanges() {
	long long int max_exchanges = 0;

	makeSet();

	// Sort em ordem inversa
	std::sort(train_lines.rbegin(), train_lines.rend());
	
	for(int i = 0; i < E; i++){

		// train_lines[i].second - Arco<u,v>
		if( findSet(train_lines[i].second.first) != findSet(train_lines[i].second.second) ){

			Union(train_lines[i].second.first, train_lines[i].second.second);

			max_exchanges += train_lines[i].first;
		}

	} 
   
	return max_exchanges;
}

int main() {
	getInput();

	if(V < 1 || E < 0)
		std::cout << 0 << std::endl;

	std::cout << maximizeExchanges() << std::endl;

	return 0;
}
