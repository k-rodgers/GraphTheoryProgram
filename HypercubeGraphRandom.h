//HypercubeGraphRandom.h

#ifndef GUARD_HypercubeGraphRandom_h
#define GUARD_HypercubeGraphRandom_h

#include <list>
#include <vector>
#include <string>
//#include <boolean>

class Node;

class HypercubeGraphRandom {
public:
	HypercubeGraphRandom(int, int, bool, int, int);
	virtual ~HypercubeGraphRandom();
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