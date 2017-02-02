#include "vertex.h"
#include<cstring>

using namespace std;

Vertex::Vertex() {
	index = "";
	color = NONE;
	edges = set<Vertex>();
}

Vertex::Vertex(string name){
	index = name;
	color = NONE;
	edges = set<Vertex>();
}

Vertex::Vertex(string name, Color col) {
	index = name;
	color = col;
	edges = set<Vertex>();
}

void Vertex::setColor(Color col) {
	color = col;
}

void Vertex::insertEdge(Vertex &ver2) {
	edges.insert(ver2); //Inserting vertex2 to the list of edges for this vertex
	ver2.edges.insert(*this); //Insert this vertex to the list of edges for vertex2
}

bool operator <(const Vertex &lhs, const Vertex & rhs){
	if (lhs.index != rhs.index) return lhs.index < rhs.index;
}

//Get index for the specific element as an int (e.g A=0, B=1, C=2 etc.)
int Vertex::getindex()const {
	const char *cstr = index.c_str();
	return *cstr - int('A');
}

string Vertex::getVertexName()const {
	return index;
}

set<Vertex> Vertex::getEdges()const {
	return edges;
}