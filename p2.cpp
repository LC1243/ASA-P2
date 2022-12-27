#include <iostream>
#include <vector>
#include <algorithm>

int V, E;
long long unsigned int M;
std::vector<std::pair<int, std::pair<int, int>>> train_lines;

void getInput() {
    int u, v, w;
    std::cin >> V;
    std::cin >> E;
    for(int i = 0; i < E; i++) {
        scanf("%d %d %d", &u, &v, &w);
		//make sets
		train_lines.push_back(std::make_pair(w, std::make_pair(u, v)));
    }
}

long long int maximizeExchanges() {
	std::sort(train_lines.rbegin(), train_lines.rend());
	return 0;
}

int main() {
	getInput();
	maximizeExchanges();
	std::cout << maximizeExchanges() << std::endl;
	return 0;
}
