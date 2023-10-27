//@iLjoker1
#pragma once
#include <iostream>
#include <windows.h>


using namespace std;

class clsColor
{

public:

    static void Blue1()
    {
        HANDLE  _hConsole;
        _hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
        SetConsoleTextAttribute(_hConsole, 3);
    }
    static void Blue2()
    {
        HANDLE  _hConsole;
        _hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
        SetConsoleTextAttribute(_hConsole, 9);
    }
    static void Blue3()
    {
        HANDLE  _hConsole;
        _hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
        SetConsoleTextAttribute(_hConsole, 1);
    }
    static void Green1()
    {
        HANDLE  _hConsole;
        _hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
        SetConsoleTextAttribute(_hConsole, 2);
    }
    static void Green2()
    {
        HANDLE  _hConsole;
        _hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
        SetConsoleTextAttribute(_hConsole, 10);
    }
    static void Aqua()
    {
        HANDLE  _hConsole;
        _hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
        SetConsoleTextAttribute(_hConsole, 11);
    }
    static void Red1()
    {
        HANDLE  _hConsole;
        _hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
        SetConsoleTextAttribute(_hConsole, 12);
    }
    static void Read2()
    {
        HANDLE  _hConsole;
        _hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
        SetConsoleTextAttribute(_hConsole, 4);
    }
    static void Yellow1()
    {
        HANDLE  _hConsole;
        _hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
        SetConsoleTextAttribute(_hConsole, 14);
    }
    static void Yellow2()
    {
        HANDLE  _hConsole;
        _hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
        SetConsoleTextAttribute(_hConsole, 6);
    }
    static void White1()
    {
        HANDLE  _hConsole;
        _hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
        SetConsoleTextAttribute(_hConsole, 8);
    }
    static void White2()
    {
        HANDLE  _hConsole;
        _hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
        SetConsoleTextAttribute(_hConsole, 7);
    }
    static void White3()
    {
        HANDLE  _hConsole;
        _hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
        SetConsoleTextAttribute(_hConsole, 15);
    }
    static void Purple1()
    {
        HANDLE  _hConsole;
        _hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
        SetConsoleTextAttribute(_hConsole, 5);
    }
    static void Purple2()
    {
        HANDLE  _hConsole;
        _hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
        SetConsoleTextAttribute(_hConsole, 13);
    }


};