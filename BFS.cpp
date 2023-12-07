#include<iostream>
#include<list>
using namespace std;

class BFS {
	int vertex_count; // vertex count in graph
	list<int> *adjacent_vertexes; // arr of lists
	int* colour; // 0 - not found, 1 - in process, 2 - founded 
	int* distance; // distance to vertex[i] from vertex_start
	int* p; // vertex[i]'s parentz

public:
	// constructor (creating dynamic arrays)
	BFS(int vertex_count) : vertex_count(vertex_count) {
		adjacent_vertexes = new list<int>[vertex_count];
		colour = new int[vertex_count];
		distance = new int[vertex_count];
		p = new int[vertex_count];
	}

	void addEdge(int v1, int v2) {
		adjacent_vertexes[v1].push_back(v2);
	}

	void algoStart(int vertex_start) {
		// default initialize
		for (int i = 0; i < vertex_count; i++) {
			colour[i] = 0;
			distance[i] = -1;
			p[i] = -1;
		}

		// start vertex initialize
		colour[vertex_start] = 1;
		distance[vertex_start] = 0;

		// queue create and pushing start vertex
		list<int> queue;
		queue.push_back(vertex_start);

		/*
		* Algorithm:
		* Get front vertex from the queue while it is not empty.
		* Add all its adjacent to queue if they are not there (check by colour).
		* Thats all ;)
		*/

		while (!queue.empty()) {
			// getting front vertex from queue
			// changing its colour to 1(in process)
			// deleting this vertex from queue
			int curr_vertex = queue.front();
			colour[curr_vertex] = 1;
			cout << " -> " << curr_vertex << " ";
			queue.pop_front();

			// checking all the adjacents of this vertex
			for (auto i = adjacent_vertexes[curr_vertex].begin();
				i != adjacent_vertexes[curr_vertex].end(); i++) {
				// if vertex is not found, then
				// pointing its parent, distance, changing colour
				// and pushing in queue
				if (colour[*i] == 0) {
					distance[*i] = distance[curr_vertex] + 1;
					p[*i] = curr_vertex;
					colour[*i] = 1;
					queue.push_back(*i);
				}
			}
		}
	}
};

int main() {
	BFS bfs(4); // 4 edges, indexing from 0
	bfs.addEdge(0, 1);
	bfs.addEdge(0, 2);
	bfs.addEdge(2, 0);
	bfs.addEdge(2, 3);
	bfs.addEdge(3, 3);

	bfs.algoStart(2); // algorithm start from vertex 2
}