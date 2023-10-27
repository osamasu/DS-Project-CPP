#pragma once
#include "clsDynamicArray.h"

template <class DataType>
class clsMyQueueArr
{
protected:

	clsDynamicArray <DataType> _MyList;

public:

	void push(DataType Value) {

		_MyList.InsertAtEnd(Value);
	}

	void pop() {

		_MyList.DeleteFirstItem();
	}

	short Size() {

		return _MyList.Size();
	}

	DataType front() {

		return _MyList.GetItem(0);
	}

	DataType back() {

		return _MyList.GetItem(Size() - 1);
	}

	DataType GetItem(short Index) {

		return _MyList.GetItem(Index);
	}

	void Reverse() {

		_MyList.Reverse();
	}

	void UpdateItem(short IndexToUpdate, DataType Value) {

		_MyList.SetItem(IndexToUpdate, Value);
	}

	bool InsertAfter(short IndexToInsertAfter, DataType Value) {

		return _MyList.InsertAfter(IndexToInsertAfter, Value);
	}

	bool InsertAtFront(DataType Value) {

		return _MyList.InsertAtBeginning(Value);
	}

	bool InsertAtBack(DataType Value) {

		return _MyList.InsertAtEnd(Value);
	}

	void Clear() {

		_MyList.Clear();
	}

	void Print() {

		_MyList.PrintList();
	}



};

