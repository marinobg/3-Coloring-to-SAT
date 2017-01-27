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

	for (int i = 0; i < nVer; i++) vertices.insert(string(1, (char(i + 'A')))); //Inserting vertices into the set, vertcies labeled alphabetically from A


}