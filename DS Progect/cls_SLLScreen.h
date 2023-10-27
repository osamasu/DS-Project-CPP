#pragma once
#include <iostream>
#include "clsString.h"
#include "clsDbLinkedList.h"
using namespace std;

static clsDbLinkedList<string> _MyList;


class cls_SLLScreen
{
public:

	static enum enSSLOperations { ADD_Begining = 1, ADD_ByIndex, ADD_END, DELETE_Begining, DELETE_ByIndex, DELETE_END, Search_ByIndex, Print_Elements };



	static void AddInTheBegining_Options() {

		system("cls");

		cout << "\n";

		cout << clsString::Tabs(2) << "Please Enter A Value Of The Element ? | ";

		string S1 = clsInputValidate::ReadString();

		_MyList.InsertAtBegining(S1);

		cout << "\n\n";
		cout << clsString::Tabs(2) << "Added Successfully :-) \n\n\t\t";

		system("pause");

		ShowSSLScreen();
	}

	static void AddInByIndex_Options() {

		system("cls");

		cout << "\n";

		cout << clsString::Tabs(2) << "Please Enter A Value Of The Element ? | ";

		string S1_Value = clsInputValidate::ReadString();

		cout << clsString::Tabs(2) << "Please Enter Index Of The Element Place ? | ";

		short S1_Index = clsInputValidate::ReadNumber_InRange<short>("", 0, _MyList.Size());

		_MyList.InsertAfter(S1_Index - 1, S1_Value);

		cout << "\n\n";
		cout << clsString::Tabs(2) << "Added Successfully :-) , Press Any Key to return";

		system("pause");

		ShowSSLScreen();
	}

	static void AddInTheEnd_Options() {

		system("cls");

		cout << "\n";

		cout << clsString::Tabs(2) << "Please Enter A Value Of The Element ? | ";

		string S1 = clsInputValidate::ReadString();

		_MyList.InsertAtEnd(S1);

		cout << "\n\n";
		cout << clsString::Tabs(2) << "Added Successfully :-) \n\n\t\t";

		system("pause");

		ShowSSLScreen();
	}




	static void DELETEInTheBegining_Options() {

		system("cls");

		cout << "\n";





		_MyList.DeleteFirstNode();

		cout << "\n\n";
		cout << clsString::Tabs(2) << "Deleted Successfully :-) \n\n\t\t";

		system("pause");

		ShowSSLScreen();
	}

	static void DELETEInByIndex_Options() {

		system("cls");

		cout << "\n";

		cout << clsString::Tabs(2) << "Please Enter The Index Of The Element , To Delete ? | ";

		short S1 = clsInputValidate::ReadNumber_InRange<short>("", 0, _MyList.Size() - 1);

		_MyList.DeleteNode(S1);

		cout << "\n\n";
		cout << clsString::Tabs(2) << "Deleted Successfully :-) \n\n\t\t";

		system("pause");

		ShowSSLScreen();
	}

	static void DELETEInTheEnd_Options() {

		system("cls");

		cout << "\n";





		_MyList.DeleteLastNode();

		cout << "\n\n";
		cout << clsString::Tabs(2) << "Deleted Successfully :-) \n\n\t\t";

		system("pause");

		ShowSSLScreen();
	}

	static void SearchByIndex_Options() {

		system("cls");

		cout << "\n";

		short index = clsInputValidate::ReadNumber_InRange<short>("\n\t\tPlease Enter The Node Index To Search ? | ", 0, _MyList.Size() - 1);

		string Value = _MyList.GetItem(index);

		cout << "\n\t\t Index [ " << index << " ]" << " =  { " << Value << " }\n\n\t\t";

		system("pause");

		ShowSSLScreen();
	}


	static void PrintElements_Options() {

		system("cls");

		cout << "\n\n\t\t Your Elements is : | ";
		_MyList.PrintList();

		cout << "\n\n\t\t";
		system("pause");
		ShowSSLScreen();
	}




	static void _PerformSLLOptions(enSSLOperations UserOptions) {

		switch (UserOptions)
		{
		case cls_SLLScreen::ADD_Begining:
			AddInTheBegining_Options();
			break;

		case cls_SLLScreen::ADD_ByIndex:
			AddInByIndex_Options();
			break;
		case cls_SLLScreen::ADD_END:
			AddInTheEnd_Options();
			break;

		case cls_SLLScreen::DELETE_Begining:
			DELETEInTheBegining_Options();
			break;

		case cls_SLLScreen::DELETE_ByIndex:
			DELETEInByIndex_Options();
			break;

		case cls_SLLScreen::DELETE_END:
			DELETEInTheEnd_Options();
			break;

		case cls_SLLScreen::Search_ByIndex:
			SearchByIndex_Options();
			break;

		case cls_SLLScreen::Print_Elements:
			PrintElements_Options();
			break;
		default:
			break;
		}
	}

public:

	static void ShowSSLScreen() {

		system("cls");

		cout << "\n\n\n";
		cout << clsString::Tabs(4) << "+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-\n\n";
		cout << clsString::Tabs(4) << "|            --- ~~ {  Single Linked List   } ~~ ---\n\n";
		cout << clsString::Tabs(4) << "+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-\n\n";

		cout << clsString::Tabs(4) << "| + [1]  Add Element (At The Begining)\n\n";
		cout << clsString::Tabs(4) << "| + [2]  Add Element (In The Middle)\n\n";
		cout << clsString::Tabs(4) << "| + [3]  Add Element (In The End)\n\n";

		cout << clsString::Tabs(4) << "\n\n";

		cout << clsString::Tabs(4) << "| + [4]  Delete Element (In The Begining)\n\n";
		cout << clsString::Tabs(4) << "| + [5]  Delete Element (By Index)\n\n";
		cout << clsString::Tabs(4) << "| + [6]  Delete Element (In The End)\n\n";

		cout << clsString::Tabs(4) << "\n\n";

		cout << clsString::Tabs(4) << "| + [7]  Search For Element (Is Exist!) - By Index\n\n";
		cout << clsString::Tabs(4) << "| + [8]  Print Elements\n\n\n";
		cout << clsString::Tabs(4) << "| + [9]  Back\n\n";

		cout << clsString::Tabs(4) << "+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-\n";


		_PerformSLLOptions((enSSLOperations)clsInputValidate::ReadNumber_InRange<short>("\n\t\t\t\tEnter Your Operation Number ? | ", 1, 9));
	}
};

