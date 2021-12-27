#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <limits>
#include <queue>							
#include <map>							
#include "enums.h"							

namespace LAB1 {
	struct MyApp
	{
	public:

		static void showHeader						();
		static void showMenu						();

		static void showGeneratedRandom				();
		static void showSeriesAndHashesCountung		();

		static void sortByDirectSelection			(bool direction = true);
		static void sortByShell						(bool direction = true);
		static void sortByHoare						(bool direction = true);

		static void showStatusArray					();
		static void showShuffleArray				();


		static void generatesArrayFromRandom		(int* data, size_t sizeArray, int begin=0, int end=std::numeric_limits<int>::max());

		static const std::string delimiter			(char del = '=');

		static const std::string generatingStrings	(const std::string& str, char del = ' ');
		static const std::string generatingStrings	(const std::string&& str, char del = ' ');
		static const std::string generatingStrings	(const std::string& str, const std::string& str2, char del = ' ');
		static const std::string generatingStrings	(const std::string&& str, const std::string&& str2, char del = ' ');

		static void showPrintArray					();
		static void printArray						(const std::string&& defaultString);
		static void clearArray						();
		static void showStatusBar					(); 
		static void setSizeArray					(size_t newSizeArray= sizeArray);
		static void resizeArrayStep					();
		static void addInStatusBar					(const std::string& part);
		static void addInStatusBar					(const std::string&& part);

		static size_t getMaxTableWidth				();
		static size_t getSizeArray					();
		static size_t getNumberOfShipments			();
		static size_t getNumberOfComparisons		();

	private:

		static void showFieldsByTopic				();

		static std::pair<int, int> seriesAndHashesCountung(int* data, size_t size);

		static void shuffleArray					();
		static void directSelectionSort				(int* data, size_t size, bool direction = true);
		static void shellSort						(int* data, size_t size, bool direction = true);
		static void hoareSort						(int* data, int begin, int end, bool direction = true);

		static bool flagClearArray;
		static std::queue <std::string> bufferForStatusBar;
		static std::vector <int> Array;


		static size_t numberOfShipments;
		static size_t numberOfComparisons;

		static std::ostream& out;

		static const size_t maxTableWidth;
		static const size_t maxTableColumns;
		static size_t sizeArray;
		static SortingStatus activeStatus;
		static const std::map <LAB1::SortingStatus, std::string> mapActiveStatus;

	};
}
