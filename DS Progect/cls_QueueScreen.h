#pragma once
#include <iostream>
#include "clsString.h"
#include "clsMyQueue.h"
#include "clsInputValidate.h"
using namespace std;

static clsMyQueue<string> _MyQueue;


class cls_QueueScreen
{
public:

	static enum enQueueOperations { ADD_END = 1, DELETE_Begining, Search_ByIndex, Print_Elements };





	static void AddInTheEnd_Options() {

		system("cls");

		cout << "\n";

		cout << clsString::Tabs(2) << "Please Enter A Value Of The Element ? | ";

		string S1 = clsInputValidate::ReadString();

		_MyQueue.push(S1);

		cout << "\n\n";
		cout << clsString::Tabs(2) << "Added Successfully :-) \n\n\t\t";

		system("pause");

		ShowQueueScreen();
	}
	static void DELETEInTheBegining_Options() {

		system("cls");

		cout << "\n";





		_MyQueue.pop();

		cout << "\n\n";
		cout << clsString::Tabs(2) << "Deleted Successfully :-) \n\n\t\t";

		system("pause");

		ShowQueueScreen();
	}

	static void SearchByIndex_Options() {

		system("cls");

		cout << "\n";

		short index = clsInputValidate::ReadNumber_InRange<short>("\n\t\tPlease Enter The Node Index To Search ? | ", 0, _MyQueue.Size() - 1);

		string Value = _MyQueue.GetItem(index);

		cout << "\n\t\t Index [ " << index << " ]" << " =  { " << Value << " }\n\n\t\t";

		system("pause");

		ShowQueueScreen();
	}

	static void PrintElements_Options() {

		system("cls");

		cout << "\n\n\t\t Your Elements is : | ";
		_MyQueue.Print();

		cout << "\n\n\t\t";
		system("pause");
		ShowQueueScreen();
	}


	static void _PerformSLLOptions(enQueueOperations UserOptions) {

		switch (UserOptions)
		{

		case ADD_END:
			AddInTheEnd_Options();
			break;

		case DELETE_Begining:
			DELETEInTheBegining_Options();
			break;


		case Search_ByIndex:
			SearchByIndex_Options();
			break;

		case Print_Elements:
			PrintElements_Options();
			break;
		default:
			break;
		}
	}

public:

	static void ShowQueueScreen() {

		system("cls");

		cout << "\n\n\n";
		cout << clsString::Tabs(4) << "+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-\n\n";
		cout << clsString::Tabs(4) << "                 --- ~~ {  Queue   } ~~ ---\n\n";
		cout << clsString::Tabs(4) << "+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-\n\n";

		cout << clsString::Tabs(4) << "| + [1]  Add Element ( PUSH )\n\n";

		cout << clsString::Tabs(4) << "\n\n";

		cout << clsString::Tabs(4) << "| + [2]  Delete Element ( POP )\n\n";

		cout << clsString::Tabs(4) << "\n\n";

		cout << clsString::Tabs(4) << "| + [3]  Search For Element (Is Exist!) - By Index\n\n";
		cout << clsString::Tabs(4) << "| + [4]  Print Elements\n\n\n";
		cout << clsString::Tabs(4) << "| + [5]  Back\n\n";

		cout << clsString::Tabs(4) << "+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-\n";


		_PerformSLLOptions((enQueueOperations)clsInputValidate::ReadNumber_InRange<short>("\n\t\t\t\tEnter Your Operation Number ? | ", 1, 5));
	}
};

