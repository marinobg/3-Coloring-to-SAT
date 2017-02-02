#pragma once
#include<string>
#include<vector>
#include<set>

enum Color {RED, GREEN, BLUE, NONE};

class Vertex {
	friend struct find_by_index;
private:
	std::string index; //Name of vertice
	Color color; //Color assigned to vertice
	std::set<Vertex> edges; //Edges connected to vertex

public:
	Vertex();
	Vertex(std::string name);
	Vertex(std::string name, Color col);
	void insertEdge(Vertex &ver2);
	void setColor(Color col);
	int getindex() const;
	std::string getVertexName() const;
	std::set<Vertex> getEdges()const;

	friend bool operator < (const Vertex &lhs, const Vertex & rhs);
};

struct find_by_index {
	find_by_index(std::string const &index) : index(index) {}
	bool operator()(Vertex const &vertex) {
		return vertex.index == index;
	}
private:
	std::string index;
};