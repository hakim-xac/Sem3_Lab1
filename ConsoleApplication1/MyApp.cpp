#include "MyApp.h"
#include <string>
#include <random>
#include <algorithm>
#include <ctime>


void LAB1::MyApp::showMenu()
{
	/// <summary>
	/// ����� ����
	/// </summary>

	std::string hr{ delimiter() };

	MyApp::out << delimiter(' ');
	MyApp::out << hr;
	MyApp::out << delimiter(' ');
	MyApp::out << generatingStrings("������� �� ������� � ������� ����");;
	MyApp::out << delimiter('_');
	MyApp::out << generatingStrings("( 1 )", "��������� ���������� �������", '.');
	MyApp::out << generatingStrings("( 2 )", "�������� �������", '.');
	MyApp::out << generatingStrings("( 3 )", "�������� ������", '.');
	MyApp::out << generatingStrings("( 4 )", "�������� ������ �������", '.');
	MyApp::out << generatingStrings("( z )", "����������� ������ ������� ������� ������ �� �����������", '.');
	MyApp::out << generatingStrings("( x )", "����������� ������ ������� ������� ������ �� ��������", '.');
	MyApp::out << generatingStrings("( c )", "����������� ������ ������� ����� �� �����������", '.');
	MyApp::out << generatingStrings("( v )", "����������� ������ ������� ����� �� ��������", '.');
	MyApp::out << generatingStrings("( b )", "����������� ������ ������� ����� �� �����������", '.');
	MyApp::out << generatingStrings("( n )", "����������� ������ ������� ����� �� ��������", '.');
	MyApp::out << generatingStrings("( 8 )", "���������� ������", '.');
	MyApp::out << generatingStrings("( 9 )", "�������� ������� ����� � ����������� �����", '.');
	MyApp::out << generatingStrings("( 0 )", "�����", '.');
	MyApp::out << hr;
}


void LAB1::MyApp::showHeader()
{
	/// <summary>
	/// ����� ���������
	/// </summary>
	std::string header	{generatingStrings("������������ ������ � 1", "������ ���������� ��������")};
	std::string header2	{generatingStrings("������ ��-11", "������� �.C.")};

	std::string hr		{ delimiter() };

	out << hr;
	out << header;
	out << delimiter('-');
	out << header2;
	out << hr;
}

void LAB1::MyApp::showStatusBar()
{
	/// <summary>
	/// ������ ���.
	/// </summary>
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
	/// <summary>
	/// ����� ���������� � �������
	/// </summary>
	out << generatingStrings("������ �������:", flagClearArray? "������": "��������");
	out << delimiter('-');
	out << generatingStrings("������ �������:", std::to_string(MyApp::getSizeArray()));
	out << delimiter();
}


const std::string LAB1::MyApp::delimiter(char del)
{
	/// <summary>
	/// �������� �����������
	/// </summary>
	/// <param name="del"> �������� ����������� </param>
	/// <returns>��������������� ������, ������ ������ ������ �������</returns>
	std::string result(maxTableWidth, del);
	result.at(0) = '#';	result[result.size() - 2] = '#'; result.back() = '\n';
	return result;
}


const std::string LAB1::MyApp::generatingStrings(const std::string&& str, char del)
{
	/// <summary>
	/// ���������� ������ �� ������� str �� ������
	/// </summary>
	/// <param name="str"> ��������� rValue ������ </param>
	/// <param name="del"> ��������������� ������ </param>
	/// <returns>��������������� ������, ������ ������ ������ �������</returns>
	try {
		if (str.empty()) throw std::exception("Dont empty string! -> LAB1::MyApp::generatingStrings(const std::string& str)");
		int parity{ str.length() % 2 == 0 };
		size_t middleSize{ getMaxTableWidth() > (str.length() + 2) ? (getMaxTableWidth() - str.length() - 2) / 2 : 0 };

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
	/// <summary>
	/// ���������� ������ �� ������� str �� ������
	/// </summary>
	/// <param name="str"> ��������� lValue ������ </param>
	/// <param name="del"> ��������������� ������ </param>
	/// <returns>��������������� ������, ������ ������ ������ �������</returns>
	try {
		if (str.empty()) throw std::exception("Dont empty string! -> LAB1::MyApp::generatingStrings(const std::string& str)");
		int parity{ str.length() % 2 == 0 };
		size_t middleSize{ getMaxTableWidth() > (str.length() + 2) ? (getMaxTableWidth() - str.length() - 2) / 2 : 0 };

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
	/// <summary>
	/// ���������� ������ �� ������� str ����� � str2 ������ �� ����
	/// </summary>
	/// <param name="str"> ��������� rValue ������ </param>
	/// <param name="str2"> ��������� rValue ������ </param>
	/// <param name="del"> ��������������� ������ </param>
	/// <returns>��������������� ������, ������ ������ ������ �������</returns>
	try{
		size_t len{ str.length() + str2.length()+11};
		size_t middleSize { getMaxTableWidth() > len ? getMaxTableWidth() - len : 11	};

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
	/// <summary>
	/// ������� �������
	/// </summary>
	if (flagClearArray) {
		addInStatusBar("������� ������, ������ ��� ������!");
		return;
	}
	Array.clear();
	setSizeArray();
	flagClearArray = true;
	addInStatusBar("������ ������� ������!");
	
}


void LAB1::MyApp::resizeArrayStep()
{
	/// <summary>
	/// �������� ������ �������
	/// </summary>
	size_t newSize{ getSizeArray() + 100 };
	if (newSize > 500 || newSize < 100) newSize = 100;
	if ( !flagClearArray ) clearArray();
	flagClearArray = true;
	setSizeArray(newSize);
	addInStatusBar("������ ������� �������!");
}


void LAB1::MyApp::addInStatusBar(const std::string& part)
{
	/// <summary>
	/// ������� ��������� ������ � �������, ��� ����������� ������
	/// ����������� ����� ��� ����� ���������
	/// </summary>
	/// <param name="part"> ������ ����� lValue</param>
	bufferForStatusBar.emplace(delimiter());
	bufferForStatusBar.emplace(delimiter(' '));
	bufferForStatusBar.emplace(generatingStrings(part));
	bufferForStatusBar.emplace(delimiter(' '));
	bufferForStatusBar.emplace(delimiter());
}


void LAB1::MyApp::addInStatusBar(const std::string&& part)
{	
	/// <summary>
	/// ������� ��������� ������ � �������, ��� ����������� ������
	/// ����������� ����� ��� ����� ���������
	/// </summary>
	/// <param name="part"> ������ ����� rValue</param>
	bufferForStatusBar.emplace(delimiter());
	bufferForStatusBar.emplace(delimiter(' '));
	bufferForStatusBar.emplace(generatingStrings(part));
	bufferForStatusBar.emplace(delimiter(' '));
	bufferForStatusBar.emplace(delimiter());
}


size_t LAB1::MyApp::getSizeArray()
{
	/// <summary>
	/// 
	/// </summary>
	/// <returns> ������� ������� �������</returns>
	return sizeArray;
}


size_t LAB1::MyApp::getNumberOfShipments()
{
	/// <summary>
	/// 
	/// </summary>
	/// <returns> ������� �������� �������� ����� � ������� </returns>
	return numberOfShipments;
}


size_t LAB1::MyApp::getNumberOfComparisons()
{
	/// <summary>
	/// 
	/// </summary>
	/// <returns> ������� �������� �������� ����������� ����� � ������� </returns>
	return numberOfComparisons;
}


size_t LAB1::MyApp::getMaxTableWidth()
{
	/// <summary>
	/// 
	/// </summary>
	/// <returns> ������� �������� ������ ������� </returns>
	return maxTableWidth;
}


void LAB1::MyApp::setSizeArray(size_t newSizeArray)
{
	/// <summary>
	/// ������ ����� ������ �������
	/// </summary>
	/// <param name="newSizeArray"></param>
	sizeArray = newSizeArray;
	Array.resize(sizeArray);
}


void LAB1::MyApp::showPrintArray()
{
	/// <summary>
	///  ����� �������
	/// </summary>
	if (!flagClearArray) {
		addInStatusBar("����� �������");

		size_t lengthColumn{ (maxTableWidth - 10) / maxTableColumns };
		printArray(std::string(lengthColumn, ' '));
		
	}
	else {
		addInStatusBar("������ ��� �� ��������!");
	}
}


void LAB1::MyApp::printArray(const std::string&& defaultString)
{
	/// <summary>
	/// ������� �������� ������� � ��������������� ���� 
	/// </summary>
	/// <param name="defaultString"></param>
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
	/// <summary>
	/// ��������������� ��������� ��������� �������
	/// </summary>
	generatesArrayFromRandom(Array.data(), Array.size());
	flagClearArray = false;
	addInStatusBar("������ ������� �������� ���������� �������!");
}


void LAB1::MyApp::generatesArrayFromRandom(int* data, size_t sizeArray, int begin, int end)
{
	/// <summary>
	/// ���������� �������, ������ ���������� ���������� 
	/// </summary>
	/// <param name="data"></param>
	/// <param name="sizeArray"></param>
	/// <param name="begin"></param>
	/// <param name="end"></param>
	srand(static_cast<unsigned int>(time(0)));
	for (size_t i{}; i < sizeArray; ++i) data[i] = rand() % (end - begin) + begin;
}


void LAB1::MyApp::showSeriesAndHashesCountung()
{
	/// <summary>
	/// ��������������� ����� �������� ����� � ����������� �����
	/// </summary>
	if (!flagClearArray) {
		bufferForStatusBar.emplace(generatingStrings("������� ���������� ����� � ����������� ����� � �������"));
		bufferForStatusBar.emplace(generatingStrings("����� - ����������� ������������������ ��������� � �������"));
		bufferForStatusBar.emplace(delimiter(' '));
		bufferForStatusBar.emplace(delimiter('-'));
		try {
			int countSeries;
			int countHash;
			std::tie(countSeries, countHash) = seriesAndHashesCountung(Array.data(), Array.size());

			bufferForStatusBar.emplace(generatingStrings("���������� �����:", std::to_string(countSeries)));
			bufferForStatusBar.emplace(delimiter('-'));
			bufferForStatusBar.emplace(generatingStrings("����������� �����:", std::to_string(countHash)));
		}
		catch (const std::exception& ex) {
			bufferForStatusBar.emplace(generatingStrings(ex.what()));
		}
		bufferForStatusBar.emplace(delimiter('-'));
	}
	else {
		bufferForStatusBar.emplace(generatingStrings("������ ����������!"));
		bufferForStatusBar.emplace(generatingStrings("������ ��� �� ��������!"));
	}
}


std::pair<int, int> LAB1::MyApp::seriesAndHashesCountung(int* data, size_t size)
{
	/// <summary>
	/// ���������� ���������� ����� � ����������� ����� � �������
	/// </summary>
	/// <param name="data">��������� �� ������ �������</param>
	/// <param name="size">������ �������</param>
	/// <returns>��������� ���������� �����</returns>
	if (data == nullptr) throw std::exception("In void LAB1::MyApp::directSelectionSort(int* data, size_t size)\
 data == nullptr");
	int countSeries{};
	int countHash{};
	for (size_t i{}; i < size; ++i) {
		countHash += data[i];
		if (!i) continue;
		if (data[i] > data[i + 1]) ++countSeries;
	}
	return { countSeries, countHash };
}


void LAB1::MyApp::sortByDirectSelection(bool direction)
{
	/// <summary>
	/// ����� ���������� ���������� ������ ������� ��������
	/// </summary>
	/// <param name="direction"> ����������� ���������� 
	/// "true" -  �� ����������� 
	/// "false" -  �� �������� 
	/// </param>
	if (!flagClearArray) {
		addInStatusBar(direction? "������ ������� ������������ �� ����������� ������� ������� ������"
								: "������ ������� ������������ �� �������� ������� ������� ������"
	);
		try {
			int hash, series;
			std::tie(series, hash) = seriesAndHashesCountung(Array.data(), Array.size());
			bufferForStatusBar.emplace(generatingStrings("���������� ����� �� ����������:", std::to_string(series)));
			bufferForStatusBar.emplace(generatingStrings("����������� ����� �� ����������:", std::to_string(hash)));

			directSelectionSort(Array.data(), Array.size(), direction);

			std::tie(series, hash) = seriesAndHashesCountung(Array.data(), Array.size());
			bufferForStatusBar.emplace(generatingStrings("���������� ����� ����� ����������:", std::to_string(series)));
			bufferForStatusBar.emplace(generatingStrings("����������� ����� ����� ����������:", std::to_string(hash)));
		}
		catch (const std::exception& ex) {
			addInStatusBar(ex.what());
		}
		showFieldsByTopic();
	}
	else {
		addInStatusBar("����������� ������! ������ ��� �� ��������!");
	}
}


void LAB1::MyApp::sortByShell(bool direction)
{
	/// <summary>
	/// ����� ���������� ���������� ������ �����
	/// </summary>
	/// <param name="direction"> ����������� ���������� 
	/// "true" -  �� ����������� 
	/// "false" -  �� �������� 
	/// </param>
	if (!flagClearArray) {
		addInStatusBar(direction ? "������ ������� ������������ �� ����������� ������� �����"
			: "������ ������� ������������ �� �������� ������� �����"
		);
		try {
			int hash, series;
			std::tie(series, hash) = seriesAndHashesCountung(Array.data(), Array.size());
			bufferForStatusBar.emplace(generatingStrings("���������� ����� �� ����������:", std::to_string(series)));
			bufferForStatusBar.emplace(generatingStrings("����������� ����� �� ����������:", std::to_string(hash)));

			shellSort(Array.data(), Array.size(), direction);

			std::tie(series, hash) = seriesAndHashesCountung(Array.data(), Array.size());
			bufferForStatusBar.emplace(generatingStrings("���������� ����� ����� ����������:", std::to_string(series)));
			bufferForStatusBar.emplace(generatingStrings("����������� ����� ����� ����������:", std::to_string(hash)));			
		}
		catch (const std::exception& ex) {
			addInStatusBar(ex.what());
		}
		showFieldsByTopic();
	}
	else {
		addInStatusBar("����������� ������! ������ ��� �� ��������!");
	}
}


void LAB1::MyApp::sortByHoare(bool direction)
{
	/// <summary>
	/// ����� ���������� ���������� ������ �����
	/// </summary>
	/// <param name="direction"> ����������� ���������� 
	/// "true" -  �� ����������� 
	/// "false" -  �� �������� 
	/// </param>
	if (!flagClearArray) {
		addInStatusBar(direction ? "������ ������� ������������ �� ����������� ������� �����"
			: "������ ������� ������������ �� �������� ������� �����"
		);

		numberOfComparisons = 0;
		numberOfShipments = 0;
		try {
			int hash, series;
			std::tie(series, hash) = seriesAndHashesCountung(Array.data(), Array.size());
			bufferForStatusBar.emplace(generatingStrings("���������� ����� �� ����������:", std::to_string(series)));
			bufferForStatusBar.emplace(generatingStrings("����������� ����� �� ����������:", std::to_string(hash)));

			hoareSort(Array.data(), 0, Array.size() - 1, direction);

			std::tie(series, hash) = seriesAndHashesCountung(Array.data(), Array.size());
			bufferForStatusBar.emplace(generatingStrings("���������� ����� ����� ����������:", std::to_string(series)));
			bufferForStatusBar.emplace(generatingStrings("����������� ����� ����� ����������:", std::to_string(hash)));
		}
		catch (const std::exception& ex) {
			addInStatusBar(ex.what());
		}
		showFieldsByTopic();
	}
	else {
		addInStatusBar("����������� ������! ������ ��� �� ��������!");
	}
}


void LAB1::MyApp::showShuffleArray()
{
	/// <summary>
	/// ����� ���������� �������������
	/// </summary>
	if (!flagClearArray) {
		shuffleArray();
		addInStatusBar("������ ������� ���������");
	}
	else {
		addInStatusBar("��� ����, ����� ����������, ���������� ��������� ������!");
	}
}


void LAB1::MyApp::shuffleArray()
{
	/// <summary>
	/// ������������� �������
	/// </summary>
	std::random_device rd;
	std::mt19937 g{ rd() };
	std::shuffle(Array.begin(), Array.end(), g);
}


void LAB1::MyApp::directSelectionSort(int* data, size_t size, bool direction)
{
	/// <summary>
	/// ���������� ������� ������� ������� ������
	/// </summary>
	/// <param name="data"> ��������� �� ������ ������� </param>
	/// <param name="size"> ������ ������� </param>
	/// <param name="direction"> ����������� ����������
	/// "true" -  �� ����������� 
	/// "false" -  �� �������� 
	///  </param>
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
	/// <summary>
	/// ���������� ������� ������� �����
	/// </summary>
	/// <param name="data"> ��������� �� ������ ������� </param>
	/// <param name="size"> ������ ������� </param>
	/// <param name="direction"> ����������� ����������
	/// "true" -  �� ����������� 
	/// "false" -  �� �������� 
	///  </param>
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
	/// <summary>
	/// ���������� ������� ������� �����
	/// </summary>
	/// <param name="data"> ��������� �� ������ ������� </param>
	/// <param name="size"> ������ ������� </param>
	/// <param name="direction"> ����������� ����������
	/// "true" -  �� ����������� 
	/// "false" -  �� �������� 
	///  </param>
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
	/// <summary>
	/// ����� ���������� ��������� � ����������� �����
	/// </summary>
	bufferForStatusBar.emplace(delimiter(' '));
	bufferForStatusBar.emplace(delimiter('-'));
	bufferForStatusBar.emplace(generatingStrings("�������������� ������� ��� ������������ ������"));
	bufferForStatusBar.emplace(delimiter('-'));
	bufferForStatusBar.emplace(generatingStrings("���������� ���������:", std::to_string(getNumberOfComparisons())));
	bufferForStatusBar.emplace(delimiter('-'));
	bufferForStatusBar.emplace(generatingStrings("���������� ���������:", std::to_string(getNumberOfShipments())));
	bufferForStatusBar.emplace(delimiter('-'));
	bufferForStatusBar.emplace(delimiter(' '));
}

