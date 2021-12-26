#include <iostream>
#include "MyApp.h"                                                  // Подключаем заголовок, где находится реализация методов класса, работы программы
#include "enums.h"                                                  // Подключаем заголовок, содержащий все перечисления

/*
* Инициализируем статические переменные 
*/
const size_t LAB1::MyApp::maxTableWidth                 { 80 };     // Ширина Таблицы, минимум 76, иначе оформление "поплывет"
const size_t LAB1::MyApp::maxTableColumns               { 5 };      // Количество колонок, при выводе массива 
size_t LAB1::MyApp::sizeArray                           { 100 };    // Первичный размер массива


/* Инициализация побочных статических переменных */
/* Пользователю менять их нельзя, иначе UB */
size_t LAB1::MyApp::numberOfComparisons                 {};                      
size_t LAB1::MyApp::numberOfShipments                   {};
bool LAB1::MyApp::flagClearArray                        { true };
std::vector<int> LAB1::MyApp::Array                     (sizeArray);
std::queue<std::string> LAB1::MyApp::bufferForStatusBar {};
std::ostream& LAB1::MyApp::out                          { std::cout };


int main()
{
    using namespace LAB1;                           // Подключаем пространство имен нашей программы
    
    setlocale(LC_ALL, "Russian");                   // Задаем локаль
    Keys key{ Keys::Exit };

    /* Запускаем бесконечный цикл ожидая ввод команды от пользователя  */
    do {        
        system("cls");
        MyApp::showHeader();
        MyApp::showStatusArray();
        MyApp::showStatusBar();
        MyApp::showMenu();
        key = static_cast<Keys>(std::cin.get());
        std::cin.ignore();

        switch (key)
        {
        case Keys::Exit:
            exit(0);
            break;
        case Keys::GeneratingRandomArray:           // key 1
            MyApp::showGeneratedRandom();           // Вызываем функцию генерации массива случайными числами.
            break;
        case Keys::PrintArray:                      // key 2
            MyApp::showPrintArray();                // Вызываем функцию вывода массива в источник вывода
            break;
        case Keys::ClearArray:                      // key 3
            MyApp::clearArray();                    // Вызываем функцию очистки массива
            break;
        case Keys::ResizeArray:                     // key 4
            MyApp::resizeArrayStep();               // Вызываем функцию изменения массива (выполняется очистка)
            break;
        case Keys::SortByDirectSelectionAsk:        // key z
            MyApp::sortByDirectSelection();         // Вызываем функцию сортировки массива методом прямого выбора по возрастанию
            break;
        case Keys::SortByDirectSelectionDesk:       // key x
            MyApp::sortByDirectSelection(false);    // Вызываем функцию сортировки массива методом прямого выбора
            break;
        case Keys::ShellSortAsk:                    // key c
            MyApp::sortByShell();                   // Вызываем функцию сортировки массива методом Шелла по возрастанию
            break;
        case Keys::ShellSortDesc:                   // key v
            MyApp::sortByShell(false);              // Вызываем функцию сортировки массива методом Шелла по убыванию
            break;
        case Keys::HoareSortAsk:                    // key b
            MyApp::sortByHoare();                   // Вызываем функцию сортировки массива методом Хоара по возрастанию
            break;
        case Keys::HoareSortDesc:                   // key n
            MyApp::sortByHoare(false);              // Вызываем функцию сортировки массива методом Хоара по убыванию
            break;
        case Keys::ShuffleArray:                    // key 8
            MyApp::showShuffleArray();              // Вызываем функцию перемешивания массива
            break;
        case Keys::ShowSeries:                      // key 9
            MyApp::showSeriesAndHashesCountung();   // Вызываем функцию подсчета количества серий и контрольной суммы
            break;
        default:
            MyApp::addInStatusBar("Введена не верная команда! ");   // любая клавиша отсутствующая в перечислении Keys
            break;
        }
    } while (key != Keys::Exit);                    // 0

}

