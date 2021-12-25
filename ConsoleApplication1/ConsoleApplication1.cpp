#include <iostream>
#include "MyApp.h"
#include "enums.h"


const size_t LAB1::MyApp::maxTableLength{ 80 };
const size_t LAB1::MyApp::maxTableColumns{ 5 };
size_t LAB1::MyApp::sizeArray{ 100 };
size_t LAB1::MyApp::numberOfComparisons{};
size_t LAB1::MyApp::numberOfShipments{};

bool LAB1::MyApp::flagClearArray{ true };

std::vector<int> LAB1::MyApp::Array(sizeArray);
std::queue<std::string> LAB1::MyApp::bufferForStatusBar{};
std::ostream& LAB1::MyApp::out{ std::cout };


int main()
{
    using namespace LAB1;
    
    setlocale(LC_ALL, "Russian");
    Keys key{ Keys::Exit };
    do {        
        system("cls");
        MyApp::showTitle();
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
        case Keys::GeneratingRandomArray:
            MyApp::showGeneratedRandom();
            break;
        case Keys::PrintArray:
            MyApp::showPrintArray();
            break;
        case Keys::ClearArray:
            MyApp::clearArray();
            break;
        case Keys::ResizeArray:
            MyApp::resizeArrayStep();
            break;
        case Keys::SortByDirectSelection:
            MyApp::sortByDirectSelection();
            break;
        case Keys::ShellSort:
            MyApp::sortByShell();
            break;
        case Keys::HoareSort:
            MyApp::sortByHoare();
            break;
        case Keys::ShuffleArray:
            MyApp::showShuffleArray();
            break;
        default:
            MyApp::addInStatusBar("Введена не верная команда! " + std::to_string(static_cast<int>(key)));
            break;
        }
    } while (key != Keys::Exit);

}

