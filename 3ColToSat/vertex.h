#pragma once
#include<string>
#include<set>

enum Color {RED, GREEN, BLUE, NONE};

class Vertex {
private:
	std::string index; //Name of vertice
	Color color; //Color assigned to vertice
	std::set<Vertex> edges; //Edges connected to vertex

public:
	Vertex();
	Vertex(std::string name);
	Vertex(std::string name, Color col);
	void insertEdge(Vertex ver2);
	void setColor(Color col);

	friend bool operator < (const Vertex &lhs, const Vertex & rhs);
};