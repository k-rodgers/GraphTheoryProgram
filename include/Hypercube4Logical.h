#pragma once

#include <list>
#include <vector>
#include <string>
//#include <boolean>

class Node;

class Hypercube4Logical {
public:
	Hypercube4Logical(int, int, bool, int);
	virtual ~Hypercube4Logical();
	void createInitialEdges();
	void createInitialNodes(int);
	void removeEdge();
	void printVersion();
	void print();
	void game();
	//std::vector<std::string> player1;
	//std::vector<std::string> player2;
	//void analysis(int);
    int getRandomNumber(int);
    int getRandomEdge(int);
    void setLowestEdge();
    int gameNumber;

private:
	int nodeNameCount; //Keeps track of what the name of the next Node will be
	int edgeWeight;
	int totalGames;
    int lowestEdge;
	bool watch;
	void rotateBar();
	int barCount;
	std::list<Node*> nodeList;

};