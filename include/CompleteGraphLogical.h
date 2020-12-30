#ifndef GUARD_CompleteGraphLogical_h
#define GUARD_CompleteGraphLogical_h

#include <list>
#include <vector>
#include <string>

class Node;

class CompleteGraphLogical {
public:
	CompleteGraphLogical(int, int, int, bool, int);
	virtual ~CompleteGraphLogical();
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
//    typedef pair<int, int> edgeweightNodeDegree;

private:
	int nodeNameCount; //Keeps track of what the name of the next Node will be
	int edgeWeight;
	int totalGames;
	void rotateBar();
	bool watch;
	int barCount;
	std::list<Node*> nodeList;

};

#endif