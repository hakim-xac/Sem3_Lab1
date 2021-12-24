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
	MyApp::out << generatingStrings("( 2 )", "Загрузка массива из файла", '.');
	MyApp::out << generatingStrings("( 3 )", "Просмотр массива", '.');
	MyApp::out << generatingStrings("( 4 )", "Очистить массив", '.');
	MyApp::out << generatingStrings("( 5 )", "Изменить размер массива", '.');
	MyApp::out << generatingStrings("( 6 )", "Сортировать массив методом прямого выбора", '.');
	MyApp::out << generatingStrings("( 7 )", "Сортировать массив методом Шелла", '.');
	MyApp::out << generatingStrings("( 8 )", "Сортировать массив методом Хоара", '.');
	MyApp::out << generatingStrings("( 9 )", "Перемешать массив", '.');
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
			out << (enablesFormatStatusBar? generatingStrings(std::move(bufferForStatusBar.front())): bufferForStatusBar.front());
			bufferForStatusBar.pop();
		}
		
		out << hr2;
		out << hr;
		
	}
	enablesFormatStatusBar = true;
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


void LAB1::MyApp::showGeneratedRandom()
{
	generatesArrayFromRandom(Array.data(), Array.size());
	flagClearArray = false;
	addInStatusBar("Массив успешно заполнен случайными числами!");
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
	addInStatusBar("Размер массива изменен! ");
}


void LAB1::MyApp::addInStatusBar(const std::string& part)
{
	bufferForStatusBar.emplace(part);
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
		size_t lengthColumn((maxTableLength - 10) / maxTableColumns);
		std::string defaultString(lengthColumn, ' ');
		std::string header{ defaultString };
		std::string header2(maxTableLength - 10 - lengthColumn, ' ');

		header.replace(header.length() / 2, 1, "№");
		header2.replace(header2.length() / 2, 7, "Колонки");
		header.back() = '|';
		bufferForStatusBar.emplace(generatingStrings("Вывод массива"));
		bufferForStatusBar.emplace(delimiter(' '));
		bufferForStatusBar.emplace(delimiter('-'));
		bufferForStatusBar.emplace(generatingStrings({ header + header2 }));
		bufferForStatusBar.emplace(delimiter('-'));

		static_assert(sizeof(__int64) <= sizeof(size_t), "Unable to safely store an __int64 value in a size_t variable");
		printArray(defaultString);
		
	}
	else {
		bufferForStatusBar.emplace(generatingStrings("Массив ещё не заполнен!"));
		enablesFormatStatusBar = false;
	}
	if (enablesFormatStatusBar) enablesFormatStatusBar = false;
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


void LAB1::MyApp::generatesArrayFromRandom(int* data, size_t sizeArray, int begin, int end)
{
	srand(static_cast<unsigned int>(time(0)));
	for (size_t i{}; i < sizeArray; ++i) data[i] = rand() % (end - begin) + begin;
}


void LAB1::MyApp::sortByDirectSelection()
{
	enablesFormatStatusBar = false;
	if (!flagClearArray) {
		bufferForStatusBar.emplace(generatingStrings("Сортировка методом прямого выбора"));
		bufferForStatusBar.emplace(delimiter(' '));
		bufferForStatusBar.emplace(delimiter('-'));

		directSelectionSort(Array.data(), Array.size());
		showFieldsByTopic();
		bufferForStatusBar.emplace(generatingStrings("Массив отсортирован методом прямого выбора"));
		//showPrintArray();
	}
	else {
		bufferForStatusBar.emplace(generatingStrings("Сортировать нечего!"));
		bufferForStatusBar.emplace(generatingStrings("Массив ещё не заполнен!"));
	}
}


void LAB1::MyApp::sortByShell()
{
	enablesFormatStatusBar = false;
	if (!flagClearArray) {
		bufferForStatusBar.emplace(generatingStrings("Сортировка методом Шелла"));
		bufferForStatusBar.emplace(delimiter(' '));
		bufferForStatusBar.emplace(delimiter('-'));

		directSelectionSort(Array.data(), Array.size());
		showFieldsByTopic();
		bufferForStatusBar.emplace(generatingStrings("Массив отсортирован методом Шелла"));
		//showPrintArray();
	}
	else {
		bufferForStatusBar.emplace(generatingStrings("Сортировать нечего!"));
		bufferForStatusBar.emplace(generatingStrings("Массив ещё не заполнен!"));
	}
}


void LAB1::MyApp::sortByHoare()
{
	enablesFormatStatusBar = false;
	if (!flagClearArray) {
		bufferForStatusBar.emplace(generatingStrings("Массив успешно перемешан"));
		bufferForStatusBar.emplace(delimiter(' '));
		bufferForStatusBar.emplace(delimiter('-'));

		numberOfComparisons = 0;
		numberOfShipments = 0;
		hoareSort(Array.data(), 0, Array.size() - 1);
		showFieldsByTopic();
		bufferForStatusBar.emplace(generatingStrings("Массив отсортирован методом Хоара"));
		//showPrintArray();
	}
	else {

		bufferForStatusBar.emplace(generatingStrings("Сортировать нечего!"));
		bufferForStatusBar.emplace(generatingStrings("Массив ещё не заполнен!"));
	}
}


void LAB1::MyApp::showShuffleArray()
{
	enablesFormatStatusBar = false;
	if (!flagClearArray) {
		bufferForStatusBar.emplace(generatingStrings("Массив успешно перемешан"));
		bufferForStatusBar.emplace(delimiter(' '));
		bufferForStatusBar.emplace(delimiter('-'));
		shuffleArray();
		//showPrintArray();
	}
	else {
		bufferForStatusBar.emplace(generatingStrings("Для того, чтобы перемешать, необходимо заполнить массив!"));
	}
}


void LAB1::MyApp::shuffleArray()
{
	std::random_device rd;
	std::mt19937 g{ rd() };
	std::shuffle(Array.begin(), Array.end(), g);
}


void LAB1::MyApp::directSelectionSort(int* data, size_t size)
{
	numberOfComparisons = 0;
	numberOfShipments = 0;
	size_t min;
	for (size_t i{}; i < size - 1; ++i) {
		min = i;
		for (size_t j{ i + 1 }; j < size; ++j) {
			++numberOfComparisons;
			if (data[j] < data[min]) min = j;			
		}
		std::swap(data[i], data[min]);
		++numberOfShipments;
	}
}


void LAB1::MyApp::shellSort(int* data, size_t size)
{
	numberOfComparisons = 0;
	numberOfShipments = 0;
	for (size_t step{ size / 2 }; step; step /= 2) {
		for (size_t i{ step }, j{}; i < size; ++i) {
			int tmp{ data[i] };
			for (j = i; j >= step; j -= step) {
				if (tmp < data[j - step]) data[j] = data[j - step];
				else break;
				++numberOfComparisons;
			}
			data[j] = tmp;
			++numberOfShipments;
		}
	}

}


void LAB1::MyApp::hoareSort(int* data, int begin, int end)
{
	int i{ begin }, j{ end };
	int x{ data[(begin + end) / 2] };

	do {
		while (data[i] < x) ++i;
		while (data[j] > x) --j;
		++numberOfComparisons;
		if (i <= j) {
			++numberOfShipments;
			if (i < j) std::swap(data[i], data[j]);
			++i;
			--j;
		}
	} while (i <= j);
	if (i < end) hoareSort(data, i, end);
	if (begin < j) hoareSort(data, begin, j);
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