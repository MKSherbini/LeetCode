#include "KClosestPointsToOrigin.h"
#include "stdc++.h"


using namespace std;

// A recursive function that find articulation
// points using DFS traversal
// adj[] --> Adjacency List representation of the graph
// u --> The vertex to be visited next
// visited[] --> keeps track of visited vertices
// disc[] --> Stores discovery times of visited vertices
// low[] -- >> earliest visited vertex (the vertex with minimum
// discovery time) that can be reached from subtree
// rooted with current vertex
// parent --> Stores the parent vertex in DFS tree
// isAP[] --> Stores articulation points
void APUtil(vector<vector<int>>& adj, int node, bool visited[],
	int disc[], int low[], int& time, int parent,
	bool isAP[])
{
	// Count of children in DFS Tree
	int children = 0;


	// Mark the current node as visited
	visited[node] = true;

	// Initialize discovery time and low value
	disc[node] = low[node] = ++time;

	// Go through all vertices adjacent to this
	for (auto child : adj[node]) {
		// If v is not visited yet, then make it a child of u
		// in DFS tree and recur for it
		if (!visited[child]) {
			children++;
			APUtil(adj, child, visited, disc, low, time, node, isAP);

			// Check if the subtree rooted with child has
			// a connection to one of the ancestors of node
			low[node] = min(low[node], low[child]);
			// If node is not root and low value of one of
			// its child is more than discovery value of node.
			if (parent != -1 && low[child] >= disc[node])
				isAP[node] = true;
		}

		// Update low value of u for parent function calls.
		else if (child != parent)
			low[node] = min(low[node], disc[child]);
	}

	// If u is root of DFS tree and has two or more children.
	if (parent == -1 && children > 1)
		isAP[node] = true;
}

void AP(vector<vector<int>>& adj, int V)
{
	int* disc = new int[V] { 0 };
	int* low = new int[V] { 0 };
	bool* visited = new bool[V] { 0 };
	bool* isAP = new bool[V] { 0 };
	int time = 0, par = -1;

	// Adding this loop so that the
	// code works even if we are given
	// disconnected graph
	for (int u = 0; u < V; u++)
		if (!visited[u])
			APUtil(adj, u, visited, disc, low,
				time, par, isAP);
	for (int u = 0; u < V; u++)
		cout << low[u] << " ";
	cout << endl;
	for (int u = 0; u < V; u++)
		cout << disc[u] << " ";
	cout << endl;
	// Printing the APs
	for (int u = 0; u < V; u++)
		if (isAP[u] == true)
			cout << u << " ";
}

// Utility function to add an edge
void addEdge(vector<vector<int>>& adj, int u, int v)
{
	adj[u].push_back(v);
	adj[v].push_back(u);
}

int main()
{
	freopen("output.txt", "w", stdout);
	freopen("input.txt", "r", stdin);
	// Create graphs given in above diagrams
	int V = 5;
	cout << "Articulation points in first graph \n";
	vector<vector<int>> adj1(V);
	addEdge(adj1, 1, 0);
	addEdge(adj1, 0, 2);
	addEdge(adj1, 2, 1);
	addEdge(adj1, 0, 3);
	addEdge(adj1, 3, 4);
	AP(adj1, V);

	cout << "\nArticulation points in second graph \n";
	V = 4;
	vector<vector<int>> adj2(V);
	addEdge(adj2, 0, 1);
	addEdge(adj2, 1, 2);
	addEdge(adj2, 2, 3);
	AP(adj2, V);

	cout << "\nArticulation points in third graph \n";
	V = 7;
	vector<vector<int>> adj3(V);
	addEdge(adj3, 0, 1);
	addEdge(adj3, 1, 2);
	addEdge(adj3, 2, 0);
	addEdge(adj3, 1, 3);
	addEdge(adj3, 1, 4);
	addEdge(adj3, 1, 6);
	addEdge(adj3, 3, 5);
	addEdge(adj3, 4, 5);
	AP(adj3, V);

	return 0;
}
