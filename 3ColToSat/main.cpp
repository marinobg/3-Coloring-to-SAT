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
	while (true) {
		string v1, v2;
		cout << "Enter connecting edges, space between the edges. Enter '0' number to finish: ";
		cin >> v1 >> v2;
		if (v1 == "0") break;
		edges[v1].insert(v2); //Add edge from e1 to e2
		edges[v2].insert(v1); //Add edge from e2 to e1
	}

	for (auto it = vertices.begin(); it != vertices.end(); it++) {
		string ver = *it; //vertice
		cout << "(" << ver << "_r v " << ver << "_g v " << ver << "_b)" << " ^ "; //Available colors for the node
		cout << "(" << char(170) << ver << "_r v " << char(170) << ver << "_g)" << " ^ "; //If color blue, cannot be red or green
		cout << "(" << char(170) << ver << "_r v " << char(170) << ver << "_b)" << " ^ "; //If color green, cannot be red or blue
		cout << "(" << char(170) << ver << "_g v " << char(170) << ver << "_b)" << " ^ " << endl; //If color red, cannot be green or blue
	}
	system("PAUSE");
}