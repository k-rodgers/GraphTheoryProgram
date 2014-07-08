//Hypercube2.h

#ifndef GUARD_Hypercube2_h
#define GUARD_Hypercube2_h

#include <list>
#include <vector>
#include <string>
//#include <boolean>

class Node;

class Hypercube2 {
public:
	Hypercube2(int, int, bool, int, bool);
	virtual ~Hypercube2();
	void createInitialEdges();
	void createInitialNodes(int);
	void removeEdge();
	void printVersion();
	void print();
    void randomGame();
	void logicalGame();
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
    bool random;
	std::list<Node*> nodeList;
	
};

#endif