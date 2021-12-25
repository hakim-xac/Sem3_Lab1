#include "MyApp.h"
#include <string>
#include <random>
#include <algorithm>
#include <ctime>



void LAB1::MyApp::showMenu()
{
	std::string hr{ delimiter() };

	MyApp::out << delimiter(' ');
	MyApp::out << hr;
	MyApp::out << delimiter(' ');
	MyApp::out << generatingStrings("Нажмите на клавишу и нажмите ВВОД");;
	MyApp::out << delimiter('_');
	MyApp::out << generatingStrings("( 1 )", "Генерация случайного массива", '.');
	MyApp::out << generatingStrings("( 2 )", "Просмотр массива", '.');
	MyApp::out << generatingStrings("( 3 )", "Очистить массив", '.');
	MyApp::out << generatingStrings("( 4 )", "Изменить размер массива", '.');
	MyApp::out << generatingStrings("( z )", "Сортировать массив методом прямого выбора по Возрастанию", '.');
	MyApp::out << generatingStrings("( x )", "Сортировать массив методом прямого выбора по Убыванию", '.');
	MyApp::out << generatingStrings("( c )", "Сортировать массив методом Шелла по Возрастанию", '.');
	MyApp::out << generatingStrings("( v )", "Сортировать массив методом Шелла по Убыванию", '.');
	MyApp::out << generatingStrings("( b )", "Сортировать массив методом Хоара по Возрастанию", '.');
	MyApp::out << generatingStrings("( n )", "Сортировать массив методом Хоара по Убыванию", '.');
	MyApp::out << generatingStrings("( 8 )", "Перемешать массив", '.');
	MyApp::out << generatingStrings("( 0 )", "Выход", '.');
	MyApp::out << hr;
}


void LAB1::MyApp::showTitle()
{
	std::string header	{generatingStrings("Лабораторная работа № 1", "Методы сортировки массивов")};
	std::string header2	{generatingStrings("Группа ПБ-11", "Хакимов А.C.")};

	std::string hr		{ delimiter() };

	out << hr;
	out << header;
	out << delimiter('-');
	out << header2;
	out << hr;
}

void LAB1::MyApp::showStatusBar()
{
	if (!bufferForStatusBar.empty())
	{
		std::string hr{ delimiter() };
		std::string hr2{ delimiter(' ') };

		out << hr;
		out << hr2;
		
		while(!bufferForStatusBar.empty()) {
			out << bufferForStatusBar.front();
			bufferForStatusBar.pop();
		}
		
		out << hr2;
		out << hr;
		
	}
}


void LAB1::MyApp::showStatusArray()
{
	out << generatingStrings("Статус массива:", flagClearArray? "ПУСТОЙ": "ЗАПОЛНЕН");
	out << delimiter('-');
	out << generatingStrings("Размер массива:", std::to_string(MyApp::getSizeArray()));
	out << delimiter();
}


const std::string LAB1::MyApp::delimiter(char del)
{
	std::string result(maxTableLength, del);
	result.at(0) = '#';	result[result.size() - 2] = '#'; result.back() = '\n';
	return result;
}


const std::string LAB1::MyApp::generatingStrings(const std::string&& str, char del)
{
	try {
		if (str.empty()) throw std::exception("Dont empty string! -> LAB1::MyApp::generatingStrings(const std::string& str)");
		int parity{ str.length() % 2 == 0 };
		size_t middleSize{ getMaxTableLength() > (str.length() + 2) ? (getMaxTableLength() - str.length() - 2) / 2 : 0 };

		std::string middle(middleSize - parity, del);
		std::string result{ "#" + middle + str + (parity ? " " : "") + middle + "#\n" };
		return result;
	}
	catch (const std::exception& ex) {
		std::cout << ex.what();
	}

}


const std::string LAB1::MyApp::generatingStrings(const std::string& str, char del)
{
	try {
		if (str.empty()) throw std::exception("Dont empty string! -> LAB1::MyApp::generatingStrings(const std::string& str)");
		int parity{ str.length() % 2 == 0 };
		size_t middleSize{ getMaxTableLength() > (str.length() + 2) ? (getMaxTableLength() - str.length() - 2) / 2 : 0 };

		std::string middle(middleSize - parity, del);
		std::string result{ "#" + middle + str + (parity ? " " : "") + middle + "#\n" };

		return result;
	}
	catch (const std::exception& ex) {
		std::cout << ex.what();
	}
}


const std::string LAB1::MyApp::generatingStrings(const std::string&& str, const std::string&& str2, char del)
{	
	try{
		size_t len{ str.length() + str2.length()+11};
		size_t middleSize { getMaxTableLength() > len ? getMaxTableLength() - len : 11	};

		std::string middle(middleSize, del);
		std::string result{ "#    " + str + middle + str2 + "    #\n"};

		return result;
	}
	catch (const std::exception& ex) {
		std::cout << ex.what();
	}
}


void LAB1::MyApp::clearArray()
{
	if (flagClearArray) {
		addInStatusBar("Очищать нечего, массив ещё пустой!");
		return;
	}
	Array.clear();
	setSizeArray();
	flagClearArray = true;
	addInStatusBar("Массив успешно очищен!");
	
}


void LAB1::MyApp::resizeArrayStep()
{
	size_t newSize{ getSizeArray() + 100 };
	if (newSize > 500 || newSize < 100) newSize = 100;
	if ( !flagClearArray ) clearArray();
	flagClearArray = true;
	setSizeArray(newSize);
	addInStatusBar("Размер массива изменен!");
}


void LAB1::MyApp::addInStatusBar(const std::string& part)
{
	bufferForStatusBar.emplace(delimiter());
	bufferForStatusBar.emplace(delimiter(' '));
	bufferForStatusBar.emplace(generatingStrings(part));
	bufferForStatusBar.emplace(delimiter(' '));
	bufferForStatusBar.emplace(delimiter());
}


void LAB1::MyApp::addInStatusBar(const std::string&& part)
{
	bufferForStatusBar.emplace(delimiter());
	bufferForStatusBar.emplace(delimiter(' '));
	bufferForStatusBar.emplace(generatingStrings(part));
	bufferForStatusBar.emplace(delimiter(' '));
	bufferForStatusBar.emplace(delimiter());
}


size_t LAB1::MyApp::getSizeArray()
{
	return sizeArray;
}


size_t LAB1::MyApp::getNumberOfShipments()
{
	return numberOfShipments;
}


size_t LAB1::MyApp::getNumberOfComparisons()
{
	return numberOfComparisons;
}


size_t LAB1::MyApp::getMaxTableLength()
{
	return maxTableLength;
}


void LAB1::MyApp::setSizeArray(size_t newSizeArray)
{
	sizeArray = newSizeArray;
	Array.resize(sizeArray);
}


void LAB1::MyApp::showPrintArray()
{

	if (!flagClearArray) {
		addInStatusBar("Вывод массива");

		static_assert(sizeof(__int64) <= sizeof(size_t), "Unable to safely store an __int64 value in a size_t variable");

		size_t lengthColumn((maxTableLength - 10) / maxTableColumns);
		std::string defaultString(lengthColumn, ' ');
		printArray(defaultString);
		
	}
	else {
		addInStatusBar("Массив ещё не заполнен!");
	}
}


void LAB1::MyApp::printArray(const std::string& defaultString)
{
	std::string result{};
	for (auto it{ Array.begin() }, ite{ Array.end() }; it != ite; ++it) {

		std::string tmp{ defaultString };
		std::string num{ std::to_string(*it) };

		size_t len{ static_cast<size_t>(std::distance(Array.begin(), it)) };
		if ((len+1) % maxTableColumns != 0) {
			tmp.replace(tmp.size()-1, 1, "|");
		}
		tmp.replace((tmp.length() - num.length()) / 2, num.length(), num);
		result += tmp;

		if ((len + 1) % maxTableColumns == 0) {
			bufferForStatusBar.emplace(generatingStrings(result));
			bufferForStatusBar.emplace(delimiter('-'));
			result.clear();
		}
	}
	if (!result.empty()) bufferForStatusBar.emplace(generatingStrings(result));	
}


void LAB1::MyApp::showGeneratedRandom()
{
	generatesArrayFromRandom(Array.data(), Array.size());
	flagClearArray = false;
	addInStatusBar("Массив успешно заполнен случайными числами!");
}


void LAB1::MyApp::generatesArrayFromRandom(int* data, size_t sizeArray, int begin, int end)
{
	srand(static_cast<unsigned int>(time(0)));
	for (size_t i{}; i < sizeArray; ++i) data[i] = rand() % (end - begin) + begin;
}


void LAB1::MyApp::showSeriesAndHashesCountung()
{
	if (!flagClearArray) {
		bufferForStatusBar.emplace(generatingStrings("Подсчет количества серий и контрольной суммы в массиве"));
		bufferForStatusBar.emplace(generatingStrings("Серия - неубывающая последовательность элементов в массиве"));
		bufferForStatusBar.emplace(delimiter(' '));
		bufferForStatusBar.emplace(delimiter('-'));
		try {
			int countSeries{ seriesCountung(Array.data(), Array.size()) };
			int countHash{ hashCountung(Array.data(), Array.size()) };
			bufferForStatusBar.emplace(generatingStrings("Количество серий:", std::to_string(countSeries)));
			bufferForStatusBar.emplace(delimiter('-'));
			bufferForStatusBar.emplace(generatingStrings("Хеш:", std::to_string(countHash)));
		}
		catch (const std::exception& ex) {
			bufferForStatusBar.emplace(generatingStrings(ex.what()));
		}
		bufferForStatusBar.emplace(delimiter('-'));
	}
	else {
		bufferForStatusBar.emplace(generatingStrings("Нечего подсчитать!"));
		bufferForStatusBar.emplace(generatingStrings("Массив ещё не заполнен!"));
	}
}


int LAB1::MyApp::seriesCountung(int* data, size_t size)
{
	if (data == nullptr) throw std::exception("In void LAB1::MyApp::directSelectionSort(int* data, size_t size)\
 data == nullptr");
	int countSeries{};
	for (size_t i{}; i < size - 1; ++i) {
		if (data[i] > data[i + 1]) ++countSeries;
	}
	return countSeries;
}


int LAB1::MyApp::hashCountung(int* data, size_t size)
{
	if (data == nullptr) throw std::exception("In void LAB1::MyApp::directSelectionSort(int* data, size_t size)\
 data == nullptr");
	int countHash{};
	size_t sizeArray{ size };
	while (sizeArray)
	{
		countHash += sizeArray & 1;
		sizeArray >>= 1;
	}	
	return countHash;
}


void LAB1::MyApp::sortByDirectSelection(bool direction)
{
	if (!flagClearArray) {

		addInStatusBar("Сортировка методом прямого выбора По " + (direction)? "возрастанию": "убыванию");
		try {
			directSelectionSort(Array.data(), Array.size(), direction);
		}
		catch (const std::exception& ex) {
			addInStatusBar(ex.what());
		}
		showFieldsByTopic();
	}
	else {
		addInStatusBar("Сортировать нечего! Массив ещё не заполнен!");
	}
}


void LAB1::MyApp::sortByShell(bool direction)
{
	if (!flagClearArray) {
		addInStatusBar("Сортировка методом Шелла");
		try {
			shellSort(Array.data(), Array.size(), direction);
		}
		catch (const std::exception& ex) {
			addInStatusBar(ex.what());
		}
		showFieldsByTopic();
	}
	else {
		addInStatusBar("Сортировать нечего! Массив ещё не заполнен!");
	}
}


void LAB1::MyApp::sortByHoare(bool direction)
{
	if (!flagClearArray) {
		addInStatusBar("Сортировка методом Хоара");

		numberOfComparisons = 0;
		numberOfShipments = 0;
		try {
			hoareSort(Array.data(), 0, Array.size() - 1, direction);
		}
		catch (const std::exception& ex) {
			addInStatusBar(ex.what());
		}
		showFieldsByTopic();
	}
	else {
		addInStatusBar("Сортировать нечего! Массив ещё не заполнен!");
	}
}


void LAB1::MyApp::showShuffleArray()
{
	if (!flagClearArray) {
		shuffleArray();
		addInStatusBar("Массив успешно перемешан");
	}
	else {
		addInStatusBar("Для того, чтобы перемешать, необходимо заполнить массив!");
	}
}


void LAB1::MyApp::shuffleArray()
{
	std::random_device rd;
	std::mt19937 g{ rd() };
	std::shuffle(Array.begin(), Array.end(), g);
}


void LAB1::MyApp::directSelectionSort(int* data, size_t size, bool direction)
{
	if (data == nullptr) throw std::exception("In void LAB1::MyApp::directSelectionSort(int* data, size_t size)\
 data == nullptr");
	numberOfComparisons = 0;
	numberOfShipments = 0;
	size_t min;
	for (size_t i{}; i < size - 1; ++i) {
		min = i;
		for (size_t j{ i + 1 }; j < size; ++j) {
			++numberOfComparisons;
			if (direction) {
				if (data[j] < data[min]) min = j;
			}
			else {
				if (data[j] > data[min]) min = j;
			}
		}
		std::swap(data[i], data[min]);
		++numberOfShipments;
	}
}


void LAB1::MyApp::shellSort(int* data, size_t size, bool direction)
{
	if (data == nullptr) throw std::exception("In void LAB1::MyApp::shellSort(int* data, size_t size)\
 data == nullptr");
	numberOfComparisons = 0;
	numberOfShipments = 0;
	for (size_t step{ size >> 1 }; step; step >>= 1) {
		for (size_t i{ step }, j{}; i < size; ++i) {
			int tmp{ data[i] };
			for (j = i; j >= step; j -= step) {
				if (direction) {
					if (tmp < data[j - step]) data[j] = data[j - step];
					else break;
				}
				else {
					if (tmp > data[j - step]) data[j] = data[j - step];
					else break;
				}
				++numberOfComparisons;
			}
			data[j] = tmp;
			++numberOfShipments;
		}
	}

}


void LAB1::MyApp::hoareSort(int* data, int begin, int end, bool direction)
{
	if (data == nullptr) throw std::exception("In void LAB1::MyApp::hoareSort(int* data, int begin, int end)\
 data == nullptr");
	int i{ begin }, j{ end };
	int x{ data[(begin + end) / 2] };

	while (i <= j)
	{
		if (direction) {
			while (data[i] < x) ++i;
			while (data[j] > x) --j;
		}
		else {
			while (data[i] > x) ++i;
			while (data[j] < x) --j;
		}
		++numberOfComparisons;
		if (i <= j) {
			if (i < j) {
				std::swap(data[i], data[j]);
				++numberOfShipments;
			}
			++i;
			--j;
		}
	}
	if (i < end) hoareSort(data, i, end, direction);
	if (begin < j) hoareSort(data, begin, j, direction);
}

void LAB1::MyApp::showFieldsByTopic()
{
	bufferForStatusBar.emplace(delimiter(' '));
	bufferForStatusBar.emplace(delimiter('-'));
	bufferForStatusBar.emplace(generatingStrings("Дополнительное задание для лабороторной работы"));
	bufferForStatusBar.emplace(delimiter('-'));
	bufferForStatusBar.emplace(generatingStrings("Количество сравнений:", std::to_string(getNumberOfComparisons())));
	bufferForStatusBar.emplace(delimiter('-'));
	bufferForStatusBar.emplace(generatingStrings("Количество пересылок:", std::to_string(getNumberOfShipments())));
	bufferForStatusBar.emplace(delimiter('-'));
	bufferForStatusBar.emplace(delimiter(' '));
}

