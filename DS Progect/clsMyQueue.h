#pragma once
#include "clsDbLinkedList.h"

template <class DataType>
class clsMyQueue

{
protected:

	clsDbLinkedList <DataType> _MyList;

public :

	void push(DataType Value) {

		_MyList.InsertAtEnd(Value);
	}

	void pop() {

		_MyList.DeleteFirstNode();
	}

	DataType front() {

		return _MyList.GetItem(0);
	}

	DataType back() {

		return _MyList.GetItem(Size() - 1);
	}

	short Size() {

		return _MyList.Size();
	}

	bool IsEmpty() {

		return _MyList.IsEmpty();
	}

	DataType GetItem(short Index) {

		return _MyList.GetItem(Index);
	}

	void Reverse() {

		_MyList.Reverse();
	}

	bool UpdateItem(short Index, DataType ItemValue) {

		return _MyList.UpdateItem(Index, ItemValue);
	}

	bool InsertAfter(short Index , DataType ItemValue) {

		return _MyList.InsertAfter(Index, ItemValue);
	}

	void InsertAtFront(DataType ItemValue) {

		_MyList.InsertAtBegining(ItemValue);
	}

	void InsertAtBack(DataType ItemValue) {

		_MyList.InsertAtEnd(ItemValue);
	}

	void Clear() {

		_MyList.Clear();
	}

	void Print() {

		_MyList.PrintList();
	}
};

