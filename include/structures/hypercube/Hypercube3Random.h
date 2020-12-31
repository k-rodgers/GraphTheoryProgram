#pragma once

#include <list>
#include <vector>
#include <string>
//#include <boolean>

class Node;

class Hypercube3Random {
public:
	Hypercube3Random(int, int, bool, int);
	virtual ~Hypercube3Random();
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
    int gameNumber;

private:
	int nodeNameCount; //Keeps track of what the name of the next Node will be
	int edgeWeight;
	int totalGames;
	bool watch;
	void rotateBar();
	int barCount;
	std::list<Node*> nodeList;

};