#include <iostream>
#include <vector>
#include <algorithm>

long long unsigned int V, E;
long long unsigned int M;
bool input = true;

std::vector<std::pair<long long unsigned int, std::pair<long long unsigned int, long long unsigned int>>> train_lines;

// <Parent, Cost>
std::vector<std::pair<long long unsigned int, long long unsigned int>> tree;

void getInput() {
    long long unsigned int u, v, w;
    if(scanf("%llu\n", &V) != 1)
		return;
	if(scanf("%llu\n", &E) != 1)
		return;
    for(long long unsigned int i = 0; i < E; i++) {
        if(scanf("%llu %llu %llu", &u, &v, &w) != 3) 
			return;
		//make sets
		if(u < 1 || u > V || v < 1 || u > V)
			input = false;
		train_lines.push_back(std::make_pair(w, std::make_pair(u, v))); 

    }
}

// Cria a árvore
void makeSet(){
	for(long long unsigned int i = 0; i < V; i++){
		tree.push_back(std::make_pair(i, 0) );
	}
}

long long unsigned int findSet(long long unsigned int vertex){
	long long unsigned int parent = tree[vertex].first;

	if(vertex != parent)
		parent = findSet(parent);

	return parent;
}

void Link(long long unsigned int u, long long unsigned int v){
	if(tree[u].second > tree[v].second)
		tree[v].first = u;

	else{
		tree[u].first = v;

		if(tree[u].second == tree[v].second)
			tree[v].second++;
	}
}

// Encontra a união entre vértices
void Union(long long unsigned int v1, long long unsigned int v2){
	Link(findSet(v1), findSet(v2));
}

void displayTree(){
	for(long long unsigned int i = 0; i < V; i++){
		std::cout << tree[i].first << " " << tree[i].second << std::endl;
	}
}

// Função Principal
long long unsigned int maximizeExchanges() {
	long long unsigned int max_exchanges = 0;

	makeSet();

	// Sort em ordem inversa
	std::sort(train_lines.rbegin(), train_lines.rend());
	
	for(long long unsigned int i = 0; i < E; i++){

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
	}
	
	printf("%lld\n", maximizeExchanges());

	return 0;
}
