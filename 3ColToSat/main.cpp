#include "vertex.h"
#include<iostream>
#include<vector>
#include<string>
#include<map>
#include<algorithm>

using namespace std;

int main() {
	unsigned int nVer;
	cout << "Enter number of vertices in the graph: ";
	cin >> nVer;

	vector<Vertex> vertices;

	for (int i = 0; i < nVer; i++) vertices.push_back(Vertex(string(1, (char(i + 'A'))))); //Inserting vertices into the set, vertcies labeled alphabetically from A
	//Adding edges to the map edges. (v1 and v2 are vertcies connected by an edge)
	int nEdges = 0; //Number of edges
	while (true) {
		string v1, v2;
		cout << "Enter connecting edges, space between the edges. Enter '0' number to finish: ";
		cin >> v1 >> v2;
		if (v1 == "0") break;
		vector<Vertex>::iterator result = find_if(vertices.begin(), vertices.end(), find_by_index(v1));
		vector<Vertex>::iterator result2 = find_if(vertices.begin(), vertices.end(), find_by_index(v2));

		vertices.at(result->getindex()).insertEdge(*result2); //Insert edge for the two vertices (add the other vertex to each vertex' list)
		nEdges++;
	}

	for (auto it = vertices.begin(); it != vertices.end(); it++) {
		Vertex ver = *it; //vertice
		cout << "(" << ver.getVertexName() << "_r v " << ver.getVertexName() << "_g v " << ver.getVertexName() << "_b)" << " ^ "; //Available colors for the node
		cout << "(" << char(170) << ver.getVertexName() << "_r v " << char(170) << ver.getVertexName() << "_g)" << " ^ "; //If color blue, cannot be red or green
		cout << "(" << char(170) << ver.getVertexName() << "_r v " << char(170) << ver.getVertexName() << "_b)" << " ^ "; //If color green, cannot be red or blue
		cout << "(" << char(170) << ver.getVertexName() << "_g v " << char(170) << ver.getVertexName() << "_b)" << " ^ " << endl; //If color red, cannot be green or blue
	}

	int printedEdges = 0;
	set<string> marked; //List of vertices that's described with an edge
	for (auto it = vertices.begin(); it != vertices.end(); it++) {
		set<Vertex> edges =  it->getEdges(); //Get list of edges for the vertices

		for (auto itr = edges.begin(); itr != edges.end(); itr++) { //Loop through the vertices connected to *it by an edge
			string edge = itr->getVertexName(); //get name of vertex connected to vertex *it by an edge (vertex in *it's edge list)

			if (marked.find(edge) == marked.end()) { //If all edges for a vertex is printed, go to next vertex in the edge list
				printedEdges++;
				cout << "\t(" << char(170) << it->getVertexName() << "_r v " << char(170) << edge << "_r) ^ "; //Print restriction for edges (Two connecting vertices cannot have same color)
				cout << "(" << char(170) << it->getVertexName() << "_g v " << char(170) << edge << "_g) ^ ";
				cout << "(" << char(170) << it->getVertexName() << "_b v " << char(170) << edge << "_b)";
				if (printedEdges != nEdges) cout << " ^ " << endl; //Add an 'AND' if not the last clause
				else cout << endl;
			}
		}
		marked.insert(it->getVertexName()); //Mark vertex as finished when iterated through all its edges
	}
	system("PAUSE");
}