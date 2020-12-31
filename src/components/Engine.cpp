#include <iostream>
#include "structures/petersen/PetersenGraphRandom.h"
#include "structures/complete/CompleteGraphRandom.h"
#include "structures/hypercube/Hypercube2Random.h"
#include "structures/hypercube/Hypercube3Random.h"
#include "structures/hypercube/Hypercube4Random.h"
#include "components/Engine.h"

#include "structures/petersen/PetersenGraphLogical.h"
#include "structures/complete/CompleteGraphLogical.h"
#include "structures/hypercube/Hypercube2Logical.h"
#include "structures/hypercube/Hypercube3Logical.h"
#include "structures/hypercube/Hypercube4Logical.h"

#include "constants.h"

#include <cstdio>
#include <ctime>
#include <fstream>

#include <vector>
#include <map>

Engine::Engine(): choice(0), barCount(0)
{
	this->PrintIntro();
	this->PrintStartMenu();
	std::cin >> choice;
	this->StartMenuChoices(choice);
}

void Engine::PrintIntro()
{
	std::cout << std::endl;
	std::cout << "Welcome to the Text-Based Graph Theory Logging Program" << std::endl;
	std::cout << std::endl;
}

void Engine::PrintStartMenu()
{
	std::cout << "What type of graph would you like to use?" << std::endl;
	std::cout << "1. Petersen Graph" << std::endl;
	std::cout << "2. Complete Graph" << std::endl;
	std::cout << "3. Hypercube Graph" << std::endl;
	std::cout << "9. Quit program" << std::endl;
	std::cout << "Please enter your choice: ";
}

void Engine::StartMenuChoices(int choice)
{
	int subMenuChoice = 0;
    int numGamesToPlay = 0;
	int numNodes = 0;
	int edgeWeight = 0;
    bool random;
    bool watch;
	std::string watchChoice;
	if (choice == 1)
	{
		std::cout << "\nPetersen Graph" << std::endl;
        std::cout << "What type of game would you like to play?" << std::endl;
        std::cout << "1. Random Game" << std::endl;
        std::cout << "2. Logical Game" << std::endl;
        std::cout << "Please enter your choice: ";
        std::cin >> subMenuChoice;
        if (subMenuChoice == 1)
        {
            std::cout << "\nRandom Petersen Graph" << std::endl;
            random = true;
        }
        else if (subMenuChoice == 2)
        {
            std::cout << "\nLogical Petersen Graph" << std::endl;
            random = false;
        }
        std::cout << "What weight would you like to assign the edges?: ";
		std::cout << "\n\tNote: Type 0 for a random weight for each edge, between 1 and 10." << std::endl;
        std::cout << "What weight? ";
        std::cin >> edgeWeight;
        std::cout << "How many games would you like to play?: ";
        std::cin >> numGamesToPlay;
        std::cout << "Would you like to view the games as they are being played?" << std::endl;
        std::cout << "\tNote: If running more than 10 million games, or \n\tif you want a cleaner terminal, 'n' recommended." << std::endl;
        std::cout << "Watch games? (y/n): ";
        std::cin >> watchChoice;
        std::cout << std::endl;
        if (watchChoice == "y" || watchChoice == "Y")
            watch = true;
        else if (watchChoice == "n" || watchChoice == "N")
            watch = false;
        this->CreatePetersenGraph(numGamesToPlay, edgeWeight, watch, random);
	}
	else if (choice == 2)
	{
        std::cout << "\nComplete Graph" << std::endl;
        std::cout << "What type of game would you like to play?" << std::endl;
        std::cout << "1. Random Game" << std::endl;
        std::cout << "2. Logical Game" << std::endl;
        std::cout << "Please enter your choice: ";
        std::cin >> subMenuChoice;
        if (subMenuChoice == 1)
        {
            std::cout << "\nRandom Complete Graph" << std::endl;
            random = true;
        }
        else if (subMenuChoice == 2)
        {
            std::cout << "\nLogical Complete Graph" << std::endl;
            random = false;
        }
		std::cout << "How many nodes would you like in this graph?: ";
		std::cin >> numNodes;
		std::cout << "What weight would you like to assign the edges?: ";
		std::cout << "\n\tNote: Type 0 for a random weight for each edge, between 1 and 10." << std::endl;
		std::cout << "What weight? ";
		std::cin >> edgeWeight;
		std::cout << "How many games would you like to play?: ";
		std::cin >> numGamesToPlay;
		std::cout << "Would you like to view the games being played?" << std::endl;
		std::cout << "\tNote: If running over 150-200 nodes, and/or over 10 million games, or \n\tif you want a cleaner terminal, 'n' recommended." << std::endl;
		std::cout << "Watch games? (y/n): ";
		std::cin >> watchChoice;
		std::cout << std::endl;
        if (watchChoice == "y" || watchChoice == "Y")
            watch = true;
        else if (watchChoice == "n" || watchChoice == "N")
            watch = false;
		this->CreateCompleteGraph(numGamesToPlay, numNodes, edgeWeight, watch, random);
	}
	else if (choice == 3)
	{
        std::cout << "\nHypercube Graph" << std::endl;
        std::cout << "What type of game would you like to play?" << std::endl;
        std::cout << "1. Random Game" << std::endl;
        std::cout << "2. Logical Game" << std::endl;
        std::cout << "Please enter your choice: ";
        std::cin >> subMenuChoice;
        if (subMenuChoice == 1)
        {
            std::cout << "\nRandom Hypercube Graph" << std::endl;
            random = true;
        }
        else if (subMenuChoice == 2)
        {
            std::cout << "\nLogical Hypercube Graph" << std::endl;
            random = false;
        }
		int dimension = 0;
		std::cout << "What dimension would you like this graph to be? (2-4): ";
		std::cin >> dimension;
		std::cout << "What weight would you like to assign the edges?: ";
		std::cout << "\n\tNote: Type 0 for a random weight for each edge, between 1 and 10." << std::endl;
		std::cout << "What weight? ";
		std::cin >> edgeWeight;
		std::cout << "How many games would you like to play?: ";
		std::cin >> numGamesToPlay;
		std::cout << "Would you like to view the games being played?" << std::endl;
		std::cout << "\tNote: If running over 150-200 nodes, and/or over 10 million games, or \n\tif you want a cleaner terminal, 'n' recommended." << std::endl;
		std::cout << "Watch games? (y/n): ";
		std::cin >> watchChoice;
		std::cout << std::endl;
        if (watchChoice == "y" || watchChoice == "Y")
            watch = true;
        else if (watchChoice == "n" || watchChoice == "N")
            watch = false;
		this->CreateHypercubeGraph(numGamesToPlay, edgeWeight, dimension, watch, random);
	}
    else if (choice == 9)
    {
        std::cout << "Thank you for using this program!" << std::endl;
        exit(0);
    }
}

void Engine::ParseMasterData()
{
	longestGame = 0;
	p1size = 0;
	p2size = 0;
	std::ifstream master;
	std::ofstream p1;
	std::ofstream p2;
	master.open(std::data(MASTER_DATA_PATH));
	p1.open(std::data(PLAYER1_DATA_PATH), std::ios_base::app);
	p2.open(std::data(PLAYER2_DATA_PATH), std::ios_base::app);
	std::string parseLine;
	while (std::getline(master, parseLine))
	{
		this->RotateBarParse();
		std::string::iterator iter = (parseLine.end()-1);
		if ((*iter) == '1')
		{
			p1size++;
            std::string p1ParseLine;
			p1ParseLine = parseLine.substr(0, parseLine.size() - 2);
			p1 << p1ParseLine << std::endl;
			if (p1ParseLine.size() > longestGame)
				longestGame = (int)p1ParseLine.size();
		}
		else if((*iter) == '2')
		{
			p2size++;
            std::string p2ParseLine;
			p2ParseLine = parseLine.substr(0, parseLine.size() - 2);
			p2 << p2ParseLine << std::endl;
			if (p2ParseLine.size() > longestGame)
				longestGame = (int)p2ParseLine.size();
		}
		master.clear();
	}
	std::cout << "\nData sorted by player successfully!" << std::endl;
	p1.close();
	p2.close();
	master.close();
}

void Engine::DataAnalysis(int choice)
{
	std::ifstream p1;
	std::ifstream p2;
	std::ofstream results;
	p1.open(std::data(PLAYER1_DATA_PATH));
	p2.open(std::data(PLAYER2_DATA_PATH));
	results.open(std::data(RESULTS_DATA_PATH));
	std::string testLine;
	std::map<std::string, int> player1moves;
	std::map<std::string, int> player2moves;
	std::map<std::string, int> player1logicalmoves;
	std::map<std::string, int> player2logicalmoves;
	while (std::getline(p1, testLine))
	{
		this->RotateBarAnalyzeP1();
		std::map<std::string, int>::iterator it = player1moves.find(testLine);
        if (it == player1moves.end())
            player1moves[testLine] = 1;
        else
            (it->second)++;
        testLine.clear();
	}
	std::cout << "\nPlayer 1 data analyzed successfully!" << std::endl;
	while (std::getline(p2, testLine))
	{
		this->RotateBarAnalyzeP2();
        std::map<std::string, int>::iterator it = player2moves.find(testLine);
        if (it == player2moves.end())
            player2moves[testLine] = 1;
        else
            (it->second)++;
		testLine.clear();
	}
	std::cout << "\nPlayer 2 data analyzed successfully!" << std::endl;
	std::cout << std::endl;
	results << std::endl;
	p1.close();
	p2.close();
	int numberOfGamesPlayed = choice;
	std::cout << "-----------------------------------------------" << std::endl;
	results << "-----------------------------------------------" << std::endl;
	std::cout << "\nGame Analysis" << std::endl;
	results << "\nGame Analysis" << std::endl;
	std::cout << std::endl;
	results << std::endl;
	std::cout << "Of the " << numberOfGamesPlayed << " games played:" << std::endl;
	results << "Of the " << numberOfGamesPlayed << " games played:" << std::endl;
	std::cout << std::endl;
	results << std::endl;
	std::cout << "Player 1 won " << p1size << "." << std::endl;
	results << "Player 1 won " << p1size << "." << std::endl;
	std::cout << "Player 2 won " << p2size << "." << std::endl;
	results << "Player 2 won " << p2size << "." << std::endl;
	std::cout << std::endl;
	results << std::endl;
	std::cout << "There are " << player1moves.size() << " unique moves for Player 1." << std::endl;
	results << "There are " << player1moves.size() << " unique moves for Player 1." << std::endl;
	std::cout << "There are " << player2moves.size() << " unique moves for Player 2." << std::endl;
	results << "There are " << player2moves.size() << " unique moves for Player 2." << std::endl;
	std::cout << std::endl;
	results << std::endl;
	std::cout << "Do you want to view the unique moves?" << std::endl;
	std::cout << "\tNote: the moves will be saved to file regardless of choice." << std::endl;
	std::cout << "View moves? (y/n): ";
	std::string s;
	std::cin >> s;
	if (s == "y" || s == "y")
	{
		std::cout << "The following moves led to Player 1's victory:" << std::endl;
		results << "The following moves led to Player 1's victory:" << std::endl;
		for (std::map<std::string, int>::iterator i = player1moves.begin(); i != player1moves.end(); i++)
		{
			std::cout << i->first << " " << i->second << std::endl;
			results << i->first << " " << i->second << std::endl;
		}
		std::cout << std::endl;
		results << std::endl;
		std::cout << "The following moves led to Player 2's victory:" << std::endl;
		results << "The following moves led to Player 2's victory:" << std::endl;
		for (std::map<std::string, int>::iterator i = player2moves.begin(); i != player2moves.end(); i++)
		{
			std::cout << i->first << " " << i->second << std::endl;
			results << i->first << " " << i->second << std::endl;
		}
		std::cout << std::endl;
		results << std::endl;
	}
	else
	{
		results << "The following moves led to Player 1's victory:" << std::endl;
		for (std::map<std::string, int>::iterator i = player1moves.begin(); i != player1moves.end(); i++)
		{
            results << i->first << " " << i->second << std::endl;
		}
		results << std::endl;
		results << "The following moves led to Player 2's victory:" << std::endl;
		for (std::map<std::string, int>::iterator i = player2moves.begin(); i != player2moves.end(); i++)
		{
			results << i->first << " " << i->second << std::endl;
		}
		results << std::endl;
	}
	std::cout << "\nThe longest game was " << (longestGame / 4) << " moves.\n" << std::endl;
	results << "The longest game was " << (longestGame / 4) << " moves.\n" << std::endl;
	results.close();
}

void Engine::RotateBar(const std::string_view &message)
{
	barCount %= 4;

	std::cout << '\r' << BarChars[barCount] << std::data(message);
	std::cout.flush();

	++barCount;
}

void Engine::RotateBarParse()
{
	this->RotateBar("  Please wait while the data is sorted...");
}

void Engine::CreatePetersenGraph(int choice, int edgeWeight, bool watch, bool random)
{
	std::clock_t startTime = clock();
	std::cout << "Number of games to play: " << choice << std::endl;
    if (random == true)
        for (int i = 1; i <= choice; i++)
        {
            PetersenGraphRandom *a = new PetersenGraphRandom(i, edgeWeight, watch, choice);
            delete a;
        }
    else if (random == false)
        for (int i = 1; i <= choice; i++)
        {
            PetersenGraphLogical *a = new PetersenGraphLogical(i, edgeWeight, watch, choice);
            delete a;
        }
	std::cout << "\n\n-----------------------------------------------\n" << std::endl;
	this->ParseMasterData();
	this->DataAnalysis(choice);
	std::clock_t endTime = clock();
	std::clock_t timeDelta = endTime - startTime;
	double timeInSeconds = timeDelta / (double)CLOCKS_PER_SEC;
	int timeInDays = timeInSeconds / (Seconds::Day);
	int timeInHours = (timeInSeconds / (Seconds::Hour)) - (timeInDays * Hours::Day);
	int timeInMinutes = (timeInSeconds / Seconds::Minute) - (timeInHours * Seconds::Minute);
	int secondsRemaining = (int)(timeInSeconds - (timeInMinutes * Seconds::Minute));
	std::cout << "Benchmark:" << std::endl;
	if (secondsRemaining == 0 && timeInMinutes == 0)
	{
		std::cout << "This calculation was quite quick!" << std::endl;
		std::cout << std::endl;
	}
	else if (secondsRemaining >= 10)
	{
		std::cout << "Time to completion: " << timeInMinutes << ":" << secondsRemaining << std::endl;
		std::cout << std::endl;
	}
	else
	{
		std::cout << "Time to completion: " << timeInMinutes << ":0" << secondsRemaining << std::endl;
		std::cout << std::endl;
	}
	std::cout << "This calculation took exactly " << timeInSeconds << " seconds." << std::endl;
	std::cout << std::endl;
}

void Engine::CreateCompleteGraph(int numGames, int numNodes, int edgeWeight, bool watch, bool random)
{
	std::clock_t startTime = clock();
	std::cout << "Number of games to play: " << numGames << std::endl;
    if (random == true)
        for (int i = 1; i <= numGames; i++)
        {
            CompleteGraphRandom *a = new CompleteGraphRandom(i, numNodes, edgeWeight, watch, numGames);
            delete a;
        }
    if (random == false)
        for (int i = 1; i <= numGames; i++)
        {
            CompleteGraphLogical *a = new CompleteGraphLogical(i, numNodes, edgeWeight, watch, numGames);
            delete a;
        }
    std::cout << "\n\n-----------------------------------------------\n" << std::endl;
	this->ParseMasterData();
	this->DataAnalysis(numGames);
	std::clock_t endTime = clock();
	std::clock_t timeDelta = endTime - startTime;
	double timeInSeconds = timeDelta / (double)CLOCKS_PER_SEC;
	int timeInDays = timeInSeconds / (Seconds::Day);
	int timeInHours = (timeInSeconds / (Seconds::Hour)) - (timeInDays * Hours::Day);
	int timeInMinutes = (timeInSeconds / Seconds::Minute) - (timeInHours * Seconds::Minute);
	int secondsRemaining = (int)(timeInSeconds - (timeInMinutes * Seconds::Minute));
	std::cout << "Benchmark:" << std::endl;
	if (secondsRemaining == 0 && timeInMinutes == 0)
	{
		std::cout << "This calculation was quite quick!" << std::endl;
		std::cout << std::endl;
	}
	else if (secondsRemaining >= 10)
	{
		std::cout << "Time to completion: " << timeInMinutes << ":" << secondsRemaining << std::endl;
		std::cout << std::endl;
	}
	else
	{
		std::cout << "Time to completion: " << timeInMinutes << ":0" << secondsRemaining << std::endl;
		std::cout << std::endl;
	}
	std::cout << "This calculation took exactly " << timeInSeconds << " seconds." << std::endl;
	std::cout << std::endl;
}

void Engine::CreateHypercubeGraph(int numGames, int edgeWeight, int dimensions, bool watch, bool random)
{
	std::clock_t startTime = clock();
	std::cout << "Number of games to play: " << numGames << std::endl;
	if (dimensions == 2)
    {
        if (random == true)
            for (int i = 1; i <= numGames; i++)
            {
                Hypercube2Random *a = new Hypercube2Random(i, edgeWeight, watch, numGames);
                delete a;
            }
        else if (random == false)
            for (int i = 1; i <= numGames; i++)
            {
                Hypercube2Logical *a = new Hypercube2Logical(i, edgeWeight, watch, numGames);
                delete a;
            }
    }
    else if (dimensions == 3)
    {
        if (random == true)
            for (int i = 1; i <= numGames; i++)
            {
                Hypercube3Random *a = new Hypercube3Random(i, edgeWeight, watch, numGames);
                delete a;
            }
        else if (random == false)
            for (int i = 1; i <= numGames; i++)
            {
                Hypercube3Logical *a = new Hypercube3Logical(i, edgeWeight, watch, numGames);
                delete a;
            }
    }
    else if (dimensions == 4)
    {
        if (random == true)
            for (int i = 1; i <= numGames; i++)
            {
                Hypercube4Random *a = new Hypercube4Random(i, edgeWeight, watch, numGames);
                delete a;
            }
        else if (random == false)
            for (int i = 1; i <= numGames; i++)
            {
                Hypercube4Logical *a = new Hypercube4Logical(i, edgeWeight, watch, numGames);
                delete a;
            }
    }
	std::cout << "\n\n-----------------------------------------------\n" << std::endl;
	this->ParseMasterData();
	this->DataAnalysis(numGames);
	std::clock_t endTime = clock();
	std::clock_t timeDelta = endTime - startTime;
	double timeInSeconds = timeDelta / (double)CLOCKS_PER_SEC;
	int timeInDays = timeInSeconds / (Seconds::Day);
	int timeInHours = (timeInSeconds / (Seconds::Hour)) - (timeInDays * Hours::Day);
	int timeInMinutes = (timeInSeconds / Seconds::Minute) - (timeInHours * Seconds::Minute);
	int secondsRemaining = (int)(timeInSeconds - (timeInMinutes * Seconds::Minute));
	std::cout << "Benchmark:" << std::endl;
	if (secondsRemaining == 0 && timeInMinutes == 0)
	{
		std::cout << "This calculation was quite quick!" << std::endl;
		std::cout << std::endl;
	}
	else if (secondsRemaining >= 10)
	{
		std::cout << "Time to completion: " << timeInMinutes << ":" << secondsRemaining << std::endl;
		std::cout << std::endl;
	}
	else
	{
		std::cout << "Time to completion: " << timeInMinutes << ":0" << secondsRemaining << std::endl;
		std::cout << std::endl;
	}
	std::cout << "This calculation took exactly " << timeInSeconds << " seconds." << std::endl;
	std::cout << std::endl;
}