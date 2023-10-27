#pragma once
#include <iostream>
#include "clsString.h"
#include "clsDynamicArray.h"
#include "clsInputValidate.h"
using namespace std;

clsDynamicArray<int> _MyArrayListt;


class cls_ArrayScreen
{
public:

	static enum enSSLOperations { ADD_Begining = 1, ADD_ByIndex, ADD_END, DELETE_Begining, DELETE_ByIndex, DELETE_END, Search_ByIndex, LinearSearch_ByValue, BinarySearch_ByValue, Reverse, Sort, Clear, Print_Elements };



	static void AddInTheBegining_Options() {

		system("cls");

		cout << "\n";



		int S1 = clsInputValidate::ReadNumber<int>("\t\tPlease Enter A Value Of The Element ? | ");

		_MyArrayListt.InsertAtBeginning(S1);

		cout << "\n\n";
		cout << clsString::Tabs(2) << "Added Successfully :-) \n\n\t\t";

		system("pause");

		ShowArrraysOpScreen();
	}

	static void AddInByIndex_Options() {

		system("cls");

		cout << "\n";



		int S1_Value = clsInputValidate::ReadNumber<int>("\t\tPlease Enter A Value Of The Element ? | ");

		cout << clsString::Tabs(2) << "Please Enter Index Of The Element Place ? | ";

		short S1_Index = clsInputValidate::ReadNumber_InRange<short>("", 0, _MyArrayListt.Size());

		_MyArrayListt.InsertAfter(S1_Index - 1, S1_Value);

		cout << "\n\n";
		cout << clsString::Tabs(2) << "Added Successfully :-) , Press Any Key to return";

		system("pause");

		ShowArrraysOpScreen();
	}

	static void AddInTheEnd_Options() {

		system("cls");

		cout << "\n";



		int S1 = clsInputValidate::ReadNumber<int>("\t\tPlease Enter A Value Of The Element ? | ");

		_MyArrayListt.InsertAtEnd(S1);

		cout << "\n\n";
		cout << clsString::Tabs(2) << "Added Successfully :-) \n\n\t\t";

		system("pause");

		ShowArrraysOpScreen();
	}




	static void DELETEInTheBegining_Options() {

		system("cls");

		cout << "\n";





		_MyArrayListt.DeleteFirstItem();

		cout << "\n\n";
		cout << clsString::Tabs(2) << "Deleted Successfully :-) \n\n\t\t";

		system("pause");

		ShowArrraysOpScreen();
	}

	static void DELETEInByIndex_Options() {

		system("cls");

		cout << "\n";

		cout << clsString::Tabs(2) << "Please Enter The Index Of The Element , To Delete ? | ";

		short S1 = clsInputValidate::ReadNumber_InRange<short>("", 0, _MyArrayListt.Size() - 1);

		_MyArrayListt.DeleteItemAt(S1);

		cout << "\n\n";
		cout << clsString::Tabs(2) << "Deleted Successfully :-) \n\n\t\t";

		system("pause");

		ShowArrraysOpScreen();
	}

	static void DELETEInTheEnd_Options() {

		system("cls");

		cout << "\n";





		_MyArrayListt.DeleteLastItem();

		cout << "\n\n";
		cout << clsString::Tabs(2) << "Deleted Successfully :-) \n\n\t\t";

		system("pause");

		ShowArrraysOpScreen();
	}



	static void SearchByIndex_Options() {

		system("cls");

		cout << "\n";

		short index = clsInputValidate::ReadNumber_InRange<short>("\n\t\tPlease Enter The Node Index To Search ? | ", 0, _MyArrayListt.Size() - 1);

		int Value = _MyArrayListt.GetItem(index);

		cout << "\n\t\t Index [ " << index << " ]" << " =  { " << Value << " }\n\n\t\t";

		system("pause");

		ShowArrraysOpScreen();
	}

	static void LinearSearch_Options() {

		system("cls");

		cout << "\n";

		int Value = clsInputValidate::ReadNumber<int>("\n\t\tPlease Enter The Value To Search ? | ");

		int index = _MyArrayListt.Find(Value);

		if (index != -1)
			cout << "\n\t\t Index [ " << index << " ]" << " =  { " << Value << " }\n\n\t\t";
		else
			cout << "\n\t\t Not Found ! }\n\n\t\t";


		system("pause");

		ShowArrraysOpScreen();
	}

	static void BinarySearch_Options() {

		system("cls");

		cout << "\n";

		int Value = clsInputValidate::ReadNumber<int>("\n\t\tPlease Enter The Value To Search ? | ");

		int index = _MyArrayListt.BFind(Value);

		if (index != -1)
			cout << "\n\t\t Index [ " << index << " ]" << " =  { " << Value << " }\n\n\t\t";
		else
			cout << "\n\t\t Not Found ! }\n\n\t\t";


		system("pause");

		ShowArrraysOpScreen();
	}

	static void Reverso() {

		system("cls");

		_MyArrayListt.Reverse();

		cout << "\n\t\t Reversed Successfully ! }\n\n\t\t";

		system("pause");

		ShowArrraysOpScreen();
	}

	static void Soorto() {

		system("cls");

		_MyArrayListt.Sort();

		cout << "\n\t\t Sorted Successfully ! }\n\n\t\t";

		system("pause");

		ShowArrraysOpScreen();
	}

	static void Clearr() {

		system("cls");

		_MyArrayListt.Clear();

		cout << "\n\t\t Cleared Successfully ! }\n\n\t\t";

		system("pause");

		ShowArrraysOpScreen();
	}

	static void PrintElements_Options() {

		system("cls");

		cout << "\n\n\t\t Your Elements is : | \n\n";
		_MyArrayListt.PrintList();

		cout << "\n\n\t\t";
		system("pause");
		ShowArrraysOpScreen();
	}




	static void _PerformSLLOptions(enSSLOperations UserOptions) {

		switch (UserOptions)
		{
		case ADD_Begining:
			AddInTheBegining_Options();
			break;

		case ADD_ByIndex:
			AddInByIndex_Options();
			break;
		case ADD_END:
			AddInTheEnd_Options();
			break;

		case DELETE_Begining:
			DELETEInTheBegining_Options();
			break;

		case DELETE_ByIndex:
			DELETEInByIndex_Options();
			break;

		case DELETE_END:
			DELETEInTheEnd_Options();
			break;

		case Search_ByIndex:
			SearchByIndex_Options();
			break;

		case LinearSearch_ByValue:
			LinearSearch_Options();
			break;

		case BinarySearch_ByValue:
			BinarySearch_Options();
			break;

		case Reverse:
			Reverso();
			break;

		case Sort:
			Soorto();
			break;

		case Clear:
			Clearr();
			break;

		case Print_Elements:
			PrintElements_Options();
			break;
		default:
			break;
		}
	}

public:

	static void ShowArrraysOpScreen() {

		system("cls");

		cout << "\n\n\n";
		cout << clsString::Tabs(4) << "+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-\n\n";
		cout << clsString::Tabs(4) << "                   ---  {  Arrays   }  ---\n\n";
		cout << clsString::Tabs(4) << "+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-\n\n";

		cout << clsString::Tabs(4) << "| + [1] - Add Element (At The Begining)\n\n";
		cout << clsString::Tabs(4) << "| + [2] - Add Element (In The Middle)\n\n";
		cout << clsString::Tabs(4) << "| + [3] - Add Element (In The End)\n\n";

		cout << clsString::Tabs(4) << "\n\n";

		cout << clsString::Tabs(4) << "| + [4] - Delete Element (In The Begining)\n\n";
		cout << clsString::Tabs(4) << "| + [5] - Delete Element (By Index)\n\n";
		cout << clsString::Tabs(4) << "| + [6] - Delete Element (In The End)\n\n";

		cout << clsString::Tabs(4) << "\n\n";

		cout << clsString::Tabs(4) << "| + [7]  Search For Element (Is Exist!) - By Index\n\n";
		cout << clsString::Tabs(4) << "| + [8]  Search For Element (Is Exist!) - By Value (Linear Search)\n\n";
		cout << clsString::Tabs(4) << "| + [9]  Search For Element (Is Exist!) - By Value (Binary Search)\n\n";

		cout << clsString::Tabs(4) << "\n\n";

		cout << clsString::Tabs(4) << "| + [10]  Reverse\n\n";
		cout << clsString::Tabs(4) << "| + [11]  Sort\n\n";
		cout << clsString::Tabs(4) << "| + [12]  Clear\n\n";

		cout << clsString::Tabs(4) << "\n\n";

		cout << clsString::Tabs(4) << "| + [13]  Print Elements\n\n\n";
		cout << clsString::Tabs(4) << "| + [14]  Back\n\n";

		cout << clsString::Tabs(4) << "+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-\n";


		_PerformSLLOptions((enSSLOperations)clsInputValidate::ReadNumber_InRange<short>("\n\t\t\t\tEnter Your Operation Number ? | ", 1, 14));
	}
};

