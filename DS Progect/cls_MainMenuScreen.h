#pragma once

#include <iostream>
#include "clsString.h"
#include "clsInputValidate.h"
#include "cls_SLLScreen.h"
#include "cls_DLLScreen.h"
#include "cls_StackScreen.h"
#include "cls_QueueScreen.h"
#include "cls_ArrayScreen.h"
using namespace std;



class cls_MainMenuScreen {

private:
	static void Single_LinkedListOption() {

		cls_SLLScreen::ShowSSLScreen();

	}

	static void Double_LinkedListOption() {

		cls_DLLScreen::ShowSSLScreen();
	}

	static void StackOption() {

		cls_StackScreen::ShowStackScreen();
	}

	static void QueueOption() {
		cls_QueueScreen::ShowQueueScreen();
	}

	static void TreesOption() {

	}

	static void ArraysOption() {
		cls_ArrayScreen::ShowArrraysOpScreen();
	}

public:
	static enum enMainMenuOptions { Single_LinkedList = 1, Double_LinkedList, Stack, Queue, Trees, Arrays };

	static void PerformMainMenuOptions(enMainMenuOptions UserOption) {

		switch (UserOption)
		{
		case cls_MainMenuScreen::Single_LinkedList:
			Single_LinkedListOption();
			break;

		case cls_MainMenuScreen::Double_LinkedList:
			Double_LinkedListOption();
			break;
		case cls_MainMenuScreen::Stack:
			StackOption();
			break;
		case cls_MainMenuScreen::Queue:
			QueueOption();
			break;
		case cls_MainMenuScreen::Trees:
			TreesOption();
			break;
		case cls_MainMenuScreen::Arrays:
			ArraysOption();
			break;
		default:
			break;
		}
	}


	static void ShowMainMenuScreen() {

		system("cls");

		cout << "\n\n\n";
		cout << clsString::Tabs(4) << "+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-\n\n";

		cout << clsString::Tabs(4) << "                   ---   Main Menu   ---\n\n";

		cout << clsString::Tabs(4) << "+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-\n\n";

		cout << clsString::Tabs(4) << "| +  [ 1 ] -  Single Linked List\n\n";
		cout << clsString::Tabs(4) << "| +  [ 2 ] -  Double  Linked List\n\n";
		cout << clsString::Tabs(4) << "| +  [ 3 ] -  Stack\n\n";
		cout << clsString::Tabs(4) << "| +  [ 4 ] -  Queue\n\n";
		cout << clsString::Tabs(4) << "| +  [ 5 ] -  Trees\n\n";
		cout << clsString::Tabs(4) << "| +  [ 6 ] -  Arrays\n\n";

		cout << clsString::Tabs(4) << "+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-\n";

		PerformMainMenuOptions((enMainMenuOptions)clsInputValidate::ReadNumber_InRange<short>("\n\t\t\t\tPlease Enter Operation Number ? | ", 1, 6));
	}
};