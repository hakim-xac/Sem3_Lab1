#pragma once
#include <iostream>
#include <vector>
#include <limits>
#include <string>
#include <stack>

namespace LAB1 {
	struct MyApp
	{
	public:
		static void showTitle();
		static void showMenu();

		static void showStatusArray();//TODO

		static void generatesArrayFromRandom(int begin = 0, int end = std::numeric_limits<int>::max());

		constexpr const static std::string delimiter(char del = '=');
		static std::string generatingStrings(const std::string& str);
		static std::string generatingStrings(const std::string& str, const std::string& str2, char del = ' ');
		static void printArray();
		static void clearArray();
		static void showStatusBar(); 
		static size_t getMaxTableLength();
		static unsigned int getSizeArray();
		static void setSizeArray(unsigned int newSizeArray= sizeArray);
		static void resizeArrayStep();
		static void addStack(const std::string& part);
	private:

		static bool flagClearArray;
		static std::stack <std::string> stack;
		static std::vector <int> Array;
		static const size_t maxTableLength;
		static unsigned int sizeArray;
		static std::ostream& out;
	};
}
