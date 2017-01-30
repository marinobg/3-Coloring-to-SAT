#include<iostream>
#include<set>
#include<string>
#include<map>

using namespace std;

int main() {
	unsigned int nVer;
	cout << "Enter number of vertices in the graph: ";
	cin >> nVer;

	set<string> vertices;
	map<string, set<string>> edges;

	for (int i = 0; i < nVer; i++) vertices.insert(string(1, (char(i + 'A')))); //Inserting vertices into the set, vertcies labeled alphabetically from A

	//Adding edges to the map edges. (v1 and v2 are vertcies connected by an edge)
	int nEdges = 0; //Number of edges
	while (true) {
		string v1, v2;
		cout << "Enter connecting edges, space between the edges. Enter '0' number to finish: ";
		cin >> v1 >> v2;
		if (v1 == "0") break;
		edges[v1].insert(v2); //Add edge from e1 to e2
		edges[v2].insert(v1); //Add edge from e2 to e1
		nEdges++;
	}

	for (auto it = vertices.begin(); it != vertices.end(); it++) {
		string ver = *it; //vertice
		cout << "(" << ver << "_r v " << ver << "_g v " << ver << "_b)" << " ^ "; //Available colors for the node
		cout << "(" << char(170) << ver << "_r v " << char(170) << ver << "_g)" << " ^ "; //If color blue, cannot be red or green
		cout << "(" << char(170) << ver << "_r v " << char(170) << ver << "_b)" << " ^ "; //If color green, cannot be red or blue
		cout << "(" << char(170) << ver << "_g v " << char(170) << ver << "_b)" << " ^ " << endl; //If color red, cannot be green or blue
	}

	int printedEdges = 0;
	set<string> marked; //List of vertices that's described with an edge
	for (auto it = vertices.begin(); it != vertices.end(); it++) {
		set<string> ver_edges = edges[*it]; //Get list of edges for the vertices
		for (auto itr = ver_edges.begin(); itr != ver_edges.end(); itr++) { //Loop through the vertices connected to *it by an edge
			if (marked.find(*itr) == marked.end()) {
				printedEdges++;
				cout << "\t(" << char(170) << *it << "_r v " << char(170) << *itr << "_r) ^ "; //Print restriction for edges (Two connecting vertices cannot have same color)
				cout << "(" << char(170) << *it << "_g v " << char(170) << *itr << "_g) ^ ";
				cout << "(" << char(170) << *it << "_b v " << char(170) << *itr << "_b)";
				if (printedEdges != nEdges) cout << " ^ " << endl; //Add an 'AND' if not the last clause
				else cout << endl;
			}
		}
		marked.insert(*it); //Mark edge as finished when iterated through all its edges
	}
	system("PAUSE");
}