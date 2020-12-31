#pragma once

#include <string_view>

class Engine
{
	public:

		Engine();
		int p1size;
		int p2size;
		int longestGame;

	private:
		static constexpr std::string_view MASTER_DATA_PATH = "output_data/master_data.txt";
		static constexpr std::string_view PLAYER1_DATA_PATH = "output_data/player1_moves.txt";
		static constexpr std::string_view PLAYER2_DATA_PATH = "output_data/player2_moves.txt";
		static constexpr std::string_view RESULTS_DATA_PATH = "output_data/results.txt";
		static constexpr std::string_view PLAYER1_UNIQUE_MOVES_DATA_PATH = "output_data/player1_unique_moves.txt";
		static constexpr std::string_view PLAYER2_UNIQUE_MOVES_DATA_PATH = "output_data/player2_unique_moves.txt";

		static constexpr char BarChars[] = {'\\', '|', '/', '-'};

		void PrintIntro();
		void PrintStartMenu();
		void StartMenuChoices(int);
		void CreatePetersenGraph(int, int, bool, bool);
		void RotateBar(const std::string_view &message);
		void RotateBarParse();
		inline void RotateBarParsePlayer1()
		{
			this->RotateBar("  Please wait while Player 1's logical moves are extracted...");
		}

		inline void RotateBarParsePlayer2()
		{
			this->RotateBar("  Please wait while Player 2's logical moves are extracted...");
		}

		inline void RotateBarAnalyzeP1()
		{
			this->RotateBar("  Please wait while Player 1's data is analyzed...");
		}

		inline void RotateBarAnalyzeP2()
		{
			this->RotateBar("  Please wait while Player 2's data is analyzed...");
		}

		int barCount;
		int barCount1;
		int barCount2;
		int choice;
		void CreateCompleteGraph(int, int, int, bool, bool);
		void CreateHypercubeGraph(int, int, int, bool, bool);
		void ParseMasterData();
		void DataAnalysis(int);
};