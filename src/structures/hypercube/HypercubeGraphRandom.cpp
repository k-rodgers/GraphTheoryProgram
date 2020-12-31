// HypercubeGraphRandom.cc

#include <list>
#include <string>
#include <iostream>
#include <algorithm>
#include <iterator>
#include <fstream>
//#include <boolean>

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include <math.h>

#include "components/Token.h"
#include "components/Node.h"
#include "structures/hypercube/HypercubeGraphRandom.h"
#include "tools/RandomEngine.h"

/*
 This is the .cpp file for the HypercubeGraphRandom object.
 */

//Desc: Constructor for the HypercubeGraphRandom object. Constructs a HypercubeGraphRandom of Nodes,
//		and creates edges between them.
//Input: int i for the number of Nodes
HypercubeGraphRandom::HypercubeGraphRandom(int i, int j, bool b, int k, int size)
{
	gameNumber = i;
	edgeWeight = j;
	totalGames = k;
    numberOfNodes = (int)pow(2, size);
	watch = b;
	nodeNameCount = 0;
	for (int l = 1; l <= numberOfNodes; l++)
	{
		createInitialNodes(l);
		nodeNameCount++;
	}
	createInitialEdges();
	std::ofstream master_data;
	game();
}
//analysis(numGames);


//Desc: Destructor for the HypercubeGraphRandom object. Deletes the nodeList
//		and frees up memory.
HypercubeGraphRandom::~HypercubeGraphRandom()
{
	while(!nodeList.empty()) {
		delete nodeList.front();
		nodeList.pop_front();
	}
	nodeList.clear();
	//player1.clear();
	//player2.clear();
}

//Desc: Creates the initial edges
void HypercubeGraphRandom::createInitialEdges()
{
    int creationMatrix [numberOfNodes][numberOfNodes];
    for (int i = 0; i < numberOfNodes; i++)
    {
        for (int j = 0; j < numberOfNodes; j++)
        {
            if (i%2 == 0)
            {
                if (j%2 == 0)
                    creationMatrix[i][j] = 0;
                else
                    creationMatrix[i][j] = 1;
            }
            else
            {
                if (j%2 == 0)
                    creationMatrix[i][j] = 1;
                else
                    creationMatrix[i][j] = 0;
            }
        }
    }
//    for (int i = 0; i < numberOfNodes; i++)
//    {
//        for (int j = 0; j < numberOfNodes; j++)
//            std::cout << creationMatrix[i][j] << " ";
//        std::cout << std::endl;
//    }
	std::list<Node*>::iterator iter1 = nodeList.begin();
	std::list<Node*>::iterator iter2 = nodeList.begin();
    for (int i = 0; i < numberOfNodes; i++)
        for (int j = 0; j < numberOfNodes; j++)
        {
            if (creationMatrix[i][j] == 1)
            {
                std::advance(iter1, i);
                std::advance(iter2, j);
                (*iter1)->setEdge(*iter2, edgeWeight);
                (*iter2)->setEdge(*iter1, edgeWeight);
                iter1 = nodeList.begin();
                iter2 = nodeList.begin();
            }
        }
}

//Desc: Creates the initial Nodes
//Input: int i, which is the name of the Node
void HypercubeGraphRandom::createInitialNodes(int i)
{
	Node *n = new Node(i);
	nodeList.push_back(n);
}

void HypercubeGraphRandom::removeEdge()
{
	int n1 = 0;
	int n2 = 0;
	std::cout << "Please enter the nodes you would like to remove the edge between (x y): ";
	std::cin >> n1;
	std::cin >> n2;
	std::list<Node*>::iterator iter1;
	std::list<Node*>::iterator iter2;
	for (iter1 = nodeList.begin(); iter1 != nodeList.end(); iter1++)
	{
		if ((*iter1)->getName() == n1)
		{
			for (iter2 = nodeList.begin(); iter2 != nodeList.end(); iter2++)
			{
				if ((*iter2)->getName() == n2)
				{
					(*iter1)->destroyEdge(*iter2);
					(*iter2)->destroyEdge(*iter1);
				}
			}
		}
	}
}

//Desc: Prints out the current version of the program the user is running
void HypercubeGraphRandom::printVersion()
{
	std::cout << std::endl;
	std::cout << "Version: 0.2 Beta" << std::endl;
	std::cout << "Author: Kyle Rodgers" << std::endl;
	std::cout << "Date of Last Revision: 5/4/14 23:30" << std::endl;
}

void HypercubeGraphRandom::print()
{
	std::cout << "This surface contains the following nodes and edges: " << std::endl;
	std::list<Node*>::iterator iter;
	for (iter = nodeList.begin(); iter != nodeList.end(); iter++)
	{
		(*iter)->printEdges();
	}
}

int HypercubeGraphRandom::getRandomNumber(int size)
{

	RandomEngine *rand = RandomEngine::instance();
	double r = rand->getRandom();
	int randNum = (int)(r * size);
	return randNum;
}

int HypercubeGraphRandom::getnumberOfNodes()
{
    return numberOfNodes;
}

//This is the method that plays the game
//The master data is sent to the file /output_data/mater_data.txt

void HypercubeGraphRandom::rotateBar()
{
	barCount++;
	char barspin[4] = {'\\', '|', '/', '-'};
	int whichOne;
	whichOne = barCount % 4;
	if (whichOne == 3)
	{
		std::cout << '\r' << barspin[whichOne] << "  Please wait while the games are played. Game: " << gameNumber << " " << (int)(((double)gameNumber/totalGames)*100.0) << "% complete";

	}
	else
	{
		std::cout << '\r' << barspin[whichOne] << "  Please wait while the games are played. Game: " << gameNumber << " " << (int)(((double)gameNumber/totalGames)*100.0) << "% complete";
	}
	std::cout.flush();
	return;
}

int HypercubeGraphRandom::getRandomEdge(int size)
{

	RandomEngine *rand = RandomEngine::instance();
	double r = rand->getRandom();
	int randNum = (int)((r * size)+1);
	return randNum;
}

void HypercubeGraphRandom::game()
{
    /*    std::cout << edgeWeight << std::endl;
     for (std::list<Node*>::iterator iter = nodeList.begin(); iter != nodeList.end(); iter++)
     std::cout << (*iter)->getDegree() << std::endl;
     */    std::ofstream master_data;
	//master_data.open("logs/log.txt");


	//std::string moves;
    //	std::string gameName = std::to_string(i) + ".txt";
	std::string master_data_path = "output_data/master_data.txt";

    //	master_data.open(path+gameName);
	master_data.open(master_data_path.c_str(), std::ios_base::app);
	std::list<Node*>::iterator iter1 = nodeList.begin();
	Node* nextMoveNode;
	Token* t = new Token(*iter1);
	int nextRandomWeight = 0;
	int edgeSize = 0;
	int nextMove = 0;
	if (watch == true)
	{
		std::cout << "Game " << gameNumber << std::endl;
		std::cout << std::endl;
		master_data << (t->getTokenLocation())->getName() << "-";
		while (true)
		{
            if (t->getCurrentPlayerTurn() == 2)
            {
                nextMove = getRandomNumber(t->getTokenLocation()->getEdgeListSize());
                nextMoveNode = t->getTokenLocation()->getNodeAtElement(nextMove);
            }
            else
                nextMoveNode = t->getTokenLocation()->getMinimalDegreeNode();     // sets node at based in this number
	        edgeSize = t->getTokenLocation()->getWeight(nextMoveNode);
            nextRandomWeight = getRandomEdge(edgeSize);
            nextRandomWeight = 1;
            if (nextRandomWeight == 0)
		    {
		    	t->getTokenLocation()->destroyEdge(nextMoveNode);
	    		nextMoveNode->destroyEdge(t->getTokenLocation());
		    }
            else if (nextRandomWeight > 0)
        	{
        		master_data << nextRandomWeight << "-";
        		(t->getTokenLocation())->setEdge(nextMoveNode, nextMoveNode->getWeight(t->getTokenLocation()) - nextRandomWeight);
		        (nextMoveNode)->setEdge(t->getTokenLocation(), t->getTokenLocation()->getWeight(nextMoveNode) - nextRandomWeight);
    		    std::cout << "Player " << t->getCurrentPlayerTurn() << " removed edge " << (t->getTokenLocation())->getName() << " - " << nextRandomWeight << " - " << (nextMoveNode)->getName() << std::endl;
	    	    //master_data << "Player " << t->getCurrentPlayerTurn() << " removed edge " << (t->getTokenLocation())->getName() << " - " << (nextMoveNode)->getName() << std::endl;
    	    	t->setPlayerTurn();
		        t->setTokenLocation(nextMoveNode);
		        master_data << (t->getTokenLocation())->getName() << "-";
		    }
    	    if (t->getTokenLocation()->getEdgeListSize() == 0)
			{
				//moves += std::to_string((t->getTokenLocation())->getName());
				t->setPlayerTurn();
				std::cout << std::endl;
				//master_data << "Player " << t->getCurrentPlayerTurn() << " wins!\n";
				master_data << t->getCurrentPlayerTurn() << std::endl;
				std::cout << "Player " << t->getCurrentPlayerTurn() << " wins!" << std::endl;
				std::cout << std::endl;
                delete t;
				break;
			}
		}
	}
	else
	{
		master_data << (t->getTokenLocation())->getName() << "-";
		while (true)
		{
			rotateBar();
            for (std::list<Node*>::iterator iter = nodeList.begin(); iter != nodeList.end(); iter++)
                (*iter)->setDegree();
            //            for (std::list<Node*>::iterator iter = nodeList.begin(); iter != nodeList.end(); iter++)
            //                std::cout << "Node: " << (*iter)->getName() << " Degree: " << (*iter)->getDegree() << std::endl;
            if (t->getCurrentPlayerTurn() == 2)
            {
                nextMove = getRandomNumber(t->getTokenLocation()->getEdgeListSize());
                nextMoveNode = t->getTokenLocation()->getNodeAtElement(nextMove);
            }
            else
                nextMoveNode = t->getTokenLocation()->getMinimalDegreeNode();
    	    edgeSize = t->getTokenLocation()->getWeight(nextMoveNode);
        	nextRandomWeight = getRandomEdge(edgeSize);
            if (nextRandomWeight > 0)
    	    {
    	    	master_data << nextRandomWeight << "-";
        		(t->getTokenLocation())->removeEdgeWeight(nextMoveNode, nextRandomWeight);
	        	(nextMoveNode)->removeEdgeWeight(t->getTokenLocation(), nextRandomWeight);
    		    t->setPlayerTurn();
	        	t->setTokenLocation(nextMoveNode);
       			master_data << (t->getTokenLocation())->getName() << "-";
	    	}
            /*            else if (nextRandomWeight == 0)
             {
             t->getTokenLocation()->destroyEdge(nextMoveNode);
             nextMoveNode->destroyEdge(t->getTokenLocation());
             }
             */    	    if (t->getTokenLocation()->getEdgeListSize() == 0)
             {
                 //moves += std::to_string((t->getTokenLocation())->getName());
                 t->setPlayerTurn();
                 //				std::cout << std::endl;
                 //master_data << "Player " << t->getCurrentPlayerTurn() << " wins!\n";
                 master_data << t->getCurrentPlayerTurn() << std::endl;
                 //				std::cout << "Player " << t->getCurrentPlayerTurn() << " wins!" << std::endl;
                 //				std::cout << std::endl;
                 delete t;
                 break;
             }
        }
        master_data.close();
    }
}