#pragma once

#include <string>

class Engine {
public:
	Engine();
	int p1size;
	int p2size;
	int longestGame;

private:
	void printIntro();
	void printStartMenu();
	void startMenuChoices(int);
	void createPetersenGraph(int, int, bool, bool);
	void rotateBarParse();
	void rotateBarParsePlayer1();
	void rotateBarParsePlayer2();
	void rotateBarAnalyzeP1();
	void rotateBarAnalyzeP2();
	int barCount;
	int barCount1;
	int barCount2;
	void createCompleteGraph(int, int, int, bool, bool);
	void createHypercubeGraph(int, int, int, bool, bool);
	void parseMasterData();
//	void parsePlayerLogicalData();
	void dataAnalysis(int);
		void PrintIntro();
		void PrintStartMenu();
		void StartMenuChoices(int);
		void CreatePetersenGraph(int, int, bool, bool);
		void RotateBar(const std::string_view &message);
		void RotateBarParse();
		void RotateBarParsePlayer1();
		void RotateBarParsePlayer2();
		void RotateBarAnalyzeP1();
		void RotateBarAnalyzeP2();
		int barCount;
		int barCount1;
		int barCount2;
		int choice;
		void CreateCompleteGraph(int, int, int, bool, bool);
		void CreateHypercubeGraph(int, int, int, bool, bool);
		void ParseMasterData();
		void DataAnalysis(int);
};