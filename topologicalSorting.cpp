#include <iostream>
#include <list>
#include <stack>

using namespace std;

class Graph {
	int V;
	list<list> *adj;//use adjacency list to store graph

	void topologicalSortUtil(int v, bool visited[], stack<int> &stack);

public:
	Graph(int V);//constructor

	void addEdge(int u, int v);//add an edge to the graph

	void topologicalSort();//print out the topological sort of the graph

};

Graph::Graph(int V) {
	this->V = V;
	adj = new list<int> [V];
}

void Graph::addEdge(int u, int v) {
	adj[u].push_back(v);//since it is a directed graph, we only need to update one adjacency list 
}

//usd DFS to do topological sort
void Graph::topologicalSortUtil(int v, bool visited[],stack<int> &stack) {
	visited[v] = true;//mark the current as visited

	//recursivly visit its adjacent node
	list<int>::iterator i;
	for(int i = adj[v].begin(); i != adj[v].end(); i++) {
		if(!visited[*i]) {
			topologicalSortUtil(*i, visited, stack);
		}
	}

	stack.push(v);//push current node to stack, which stores the result
}


void Graph::topologicalSort() {
	stack<int> stack;

	//mark all the nodes as unvisited
	bool *visited = new bool[v];
	for(int i = 0; i < V; i++) {
		visited[i] = false;
	}

	//call the helper function to topological sort the graph
	for(int i = 0; i < V; i++) {
		if(!viisted[i]) {
			topologicalSortUtil(i, visited, stack);
		}
	}

	//print out the result
	while(!stack.empty()) {
		cout << stack.top() << " ";
		stack.pop();
	}
}

int main() {
	Graph graph(6);
	graph.addEdge(5,2);
	graph.addEdge(5,0);
	graph.addEdge(4,0);
	graph.addEdge(4,1);
	graph.addEdge(2,3);
	graph.addEdge(3,1);

	cout << "Topological sort of the graph is:\n";
	graph.topologicalSort();
	return 0;
}
