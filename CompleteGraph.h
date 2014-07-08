#ifndef GUARD_CompleteGraph_h
#define GUARD_CompleteGraph_h

#include <list>
#include <vector>
#include <string>

class Node;

class CompleteGraph {
public:
	CompleteGraph(int, int, int, bool, int, bool);
	virtual ~CompleteGraph();
	void createInitialEdges();
	void createInitialNodes(int);
	void removeEdge();
	void printVersion();
	void print();
	void logicalGame();
    void randomGame();
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
    bool random;
	std::list<Node*> nodeList;
	
};

#endif