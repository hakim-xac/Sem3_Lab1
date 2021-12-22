#include "MyApp.h"
#include <string>
#include <random>
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
	MyApp::out << generatingStrings("( 6 )", "test", '.');
	MyApp::out << generatingStrings("( 0 )", "Выход", '.');
	MyApp::out << hr;
}

constexpr const std::string LAB1::MyApp::delimiter(char del)
{
	std::string result(maxTableLength, del);
	result[0] = '#';	result[result.size() - 2] = '#'; result[result.size() - 1] = '\n';
	return result;
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
	if (!stack.empty()) {
		std::string hr{ delimiter() };
		std::string hr2{ delimiter(' ') };

		out << hr;
		out << hr2;
		while(!stack.empty()) {
			out << generatingStrings(stack.top());
			stack.pop();
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

void LAB1::MyApp::generatesArrayFromRandom(int begin, int end)
{
	srand(static_cast<unsigned int>(time(0)));

	for (auto&& it : Array) it = rand() % (end - begin) + begin;
	flagClearArray = false;
	addStack("Массив успешно заполнен случайными числами!");

}


std::string LAB1::MyApp::generatingStrings(const std::string& str)
{	
	if (str.empty()) throw std::exception("Dont empty string! -> LAB1::MyApp::generatingStrings(const std::string& str)");
	int parity{ str.length() % 2 == 0};
	size_t middleSize{ MyApp::getMaxTableLength() > (str.length()+2) ? (MyApp::getMaxTableLength() - str.length() - 2) / 2  : 0 };
	
	std::string middle(middleSize-parity, ' ');
	std::string result{ "#" + middle + str + (parity? " ": "") + middle + "#\n"};

	return result;
}

std::string LAB1::MyApp::generatingStrings(const std::string& str, const std::string& str2, char del)
{	
	size_t len{ str.length() + str2.length()+11};
	size_t middleSize { MyApp::getMaxTableLength() > len ? MyApp::getMaxTableLength() - len : 11	};

	std::string middle(middleSize, del);
	std::string result{ "#    " + str + middle + str2 + "    #\n"};

	return result;
}

void LAB1::MyApp::printArray()
{
	for (auto&& it : Array) stack.push({ "n: " + std::to_string(it) });	
}

void LAB1::MyApp::clearArray()
{
	Array.clear();
	setSizeArray();
	flagClearArray = true;
	addStack("Массив успешно очищен!");
}

void LAB1::MyApp::resizeArrayStep()
{
	unsigned int newSize{ getSizeArray() + 100 };
	if (newSize > 500 || newSize < 100) newSize = 100;
	clearArray();
	flagClearArray = true;
	setSizeArray(newSize);
	addStack("Размер массива изменен! ");
}

void LAB1::MyApp::addStack(const std::string& part)
{
	stack.push(part);
}

unsigned int LAB1::MyApp::getSizeArray()
{
	return sizeArray;
}

size_t LAB1::MyApp::getMaxTableLength()
{
	return maxTableLength;
}

void LAB1::MyApp::setSizeArray(unsigned int newSizeArray)
{
	sizeArray = newSizeArray;
	Array.resize(sizeArray);
}



