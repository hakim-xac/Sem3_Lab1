#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <limits>
#include <string>
#include <queue>

namespace LAB1 {
	struct MyApp
	{
	public:

		static void showTitle();
		static void showMenu();

		static void showGeneratedRandom();

		static void sortByDirectSelection();
		static void sortByShell();
		static void sortByHoare();

		static void showShuffleArray();
		static void shuffleArray();

		static void showStatusArray();

		static void generatesArrayFromRandom(int* data, size_t sizeArray, int begin=0, int end=std::numeric_limits<int>::max());

		static const std::string delimiter(char del = '=');

		static const std::string generatingStrings(const std::string& str, char del = ' ');
		static const std::string generatingStrings(const std::string&& str, char del = ' ');
		static const std::string generatingStrings(const std::string&& str, const std::string&& str2, char del = ' ');

		static void showPrintArray();
		static void printArray(const std::string& defaultString);
		static void clearArray();
		static void showStatusBar(); 
		static void setSizeArray(size_t newSizeArray= sizeArray);
		static void resizeArrayStep();
		static void addInStatusBar(const std::string& part);

		static size_t getMaxTableLength();
		static size_t getSizeArray();
		static size_t getNumberOfShipments();
		static size_t getNumberOfComparisons();

	private:

		static void showFieldsByTopic();

		static void directSelectionSort(int* data, size_t size);
		static void shellSort(int* data, size_t size);
		static void hoareSort(int* data, int begin, int end);

		static bool flagClearArray;
		static bool enablesFormatStatusBar;
		static std::queue <std::string> bufferForStatusBar;
		static std::vector <int> Array;

		static const size_t maxTableLength;
		static const size_t maxTableColumns;
		static size_t sizeArray;

		static size_t numberOfShipments;
		static size_t numberOfComparisons;

		static std::ostream& out;
	};
}
