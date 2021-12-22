﻿#include <iostream>
#include "MyApp.h"
#include "enums.h"


const size_t LAB1::MyApp::maxTableLength = 80;
unsigned int LAB1::MyApp::sizeArray = 100;
bool LAB1::MyApp::flagClearArray = true;

std::vector<int> LAB1::MyApp::Array(sizeArray);
std::stack<std::string> LAB1::MyApp::stack{};
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
            MyApp::generatesArrayFromRandom();
            break;
        case Keys::LoadArrayFromFile:   //TODO
            break;
        case Keys::PrintArray:
            MyApp::printArray();
            break;
        case Keys::ClearArray:
            MyApp::clearArray();
            break;
        case Keys::ResizeArray:
            MyApp::resizeArrayStep();
            break;
        case Keys::test:

            MyApp::addStack(std::to_string(MyApp::getSizeArray()));
            
            break;
        default:
            std::cout << (int)key << "\n";
            MyApp::addStack("Не верный код");
            break;
        }
    } while (key != Keys::Exit);

}

