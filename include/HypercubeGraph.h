//HypercubeGraph.h

#ifndef GUARD_HypercubeGraph_h
#define GUARD_HypercubeGraph_h

#include <list>
#include <vector>
#include <string>
//#include <boolean>

class Node;

class HypercubeGraph {
public:
	HypercubeGraph(int, int, bool, int, int);
	virtual ~HypercubeGraph();
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
    int getnumberOfNodes();
    
private:
	int nodeNameCount; //Keeps track of what the name of the next Node will be
	int edgeWeight;
	int totalGames;
    int numberOfNodes;
	bool watch;
	void rotateBar();
	int barCount;
	std::list<Node*> nodeList;
	
};

#endif