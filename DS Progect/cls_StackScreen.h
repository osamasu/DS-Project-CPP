#pragma once
#include <iostream>
#include "clsString.h"
#include "clsMyStack.h"
#include "clsInputValidate.h"
using namespace std;

static clsMyStack<string> _MyStack;


class cls_StackScreen
{
public:

	static enum enSSLOperations { ADD_Begining = 1, DELETE_Begining, Search_ByIndex, Print_Elements };



	static void AddInTheBegining_Options() {

		system("cls");

		cout << "\n";

		cout << clsString::Tabs(2) << "Please Enter A Value Of The Element ? | ";

		string S1 = clsInputValidate::ReadString();

		_MyStack.push(S1);

		cout << "\n\n";
		cout << clsString::Tabs(2) << "Added Successfully :-) \n\n\t\t";

		system("pause");

		ShowStackScreen();
	}


	static void DELETEInTheBegining_Options() {

		system("cls");

		cout << "\n";





		_MyStack.pop();

		cout << "\n\n";
		cout << clsString::Tabs(2) << "Deleted Successfully :-) \n\n\t\t";

		system("pause");

		ShowStackScreen();
	}

	static void SearchByIndex_Options() {

		system("cls");

		cout << "\n";

		short index = clsInputValidate::ReadNumber_InRange<short>("\n\t\tPlease Enter The Node Index To Search ? | ", 0, _MyStack.Size() - 1);

		string Value = _MyStack.GetItem(index);

		cout << "\n\t\t Index [ " << index << " ]" << " =  { " << Value << " }\n\n\t\t";

		system("pause");

		ShowStackScreen();
	}


	static void PrintElements_Options() {

		system("cls");

		cout << "\n\n\t\t Your Elements is : | ";
		_MyStack.Print();

		cout << "\n\n\t\t";
		system("pause");
		ShowStackScreen();
	}




	static void _PerformSLLOptions(enSSLOperations UserOptions) {

		switch (UserOptions)
		{
		case ADD_Begining:
			AddInTheBegining_Options();
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

	static void ShowStackScreen() {

		system("cls");

		cout << "\n\n\n";
		cout << clsString::Tabs(4) << "+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-\n\n";
		cout << clsString::Tabs(4) << "|                --- ~~ {  Stack   } ~~ ---\n\n";
		cout << clsString::Tabs(4) << "+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-\n\n";

		cout << clsString::Tabs(4) << "| + [1]  Add Element (At The Begining)  ~ PUSH \n\n";

		cout << clsString::Tabs(4) << "\n\n";

		cout << clsString::Tabs(4) << "| + [2]  Delete Element (In The Begining)  ~POP\n\n";

		cout << clsString::Tabs(4) << "\n\n";

		cout << clsString::Tabs(4) << "| + [3]  Search For Element (Is Exist!) - By Index\n\n";
		cout << clsString::Tabs(4) << "| + [4]  Print Elements\n\n\n";
		cout << clsString::Tabs(4) << "| + [5]  Back\n\n";

		cout << clsString::Tabs(4) << "+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-\n";


		_PerformSLLOptions((enSSLOperations)clsInputValidate::ReadNumber_InRange<short>("\n\t\t\t\tEnter Your Operation Number ? | ", 1, 5));
	}
};

