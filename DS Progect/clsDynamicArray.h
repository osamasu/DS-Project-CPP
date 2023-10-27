#pragma once
#include <iostream>
using namespace std;

template <class DataType>
class clsDynamicArray
{
private:

	void Swap(DataType& FirstElement, DataType& SecondElement) {

		DataType* Temp = new DataType;

		*Temp = FirstElement;
		FirstElement = SecondElement;
		SecondElement = *Temp;

		delete Temp;
	}

protected:

	DataType* _OriginalArray;
	DataType* _TempArray;

	short _ArraySize;

public:

	clsDynamicArray(short ArraySize = 0) {

		if (ArraySize < 0)
			ArraySize = 0;

		_OriginalArray = new DataType[ArraySize];
		_ArraySize = ArraySize;
	}

	~clsDynamicArray() {

		delete[] _OriginalArray;
	}


	void Resize(short ArraySizeTo_ReSize) {

		if (ArraySizeTo_ReSize < 0) {

			ArraySizeTo_ReSize = 0;
		}

		_TempArray = new DataType[ArraySizeTo_ReSize];

		if (ArraySizeTo_ReSize < _ArraySize)
			_ArraySize = ArraySizeTo_ReSize;

		for (short i = 0; i < _ArraySize; i++) {

			_TempArray[i] = _OriginalArray[i];
		}

		_ArraySize = ArraySizeTo_ReSize;

		delete[] _OriginalArray;
		_OriginalArray = _TempArray;
	}


	bool SetItem(short Index, DataType Value) {

		if (Index < 0 || Index >= _ArraySize) return false;

		_OriginalArray[Index] = Value;
		return true;
	}

	DataType GetItem(short Index) {

		return _OriginalArray[Index];
	}

	bool DeleteItemAt(short IndexOfItem_ToDelete) {

		if (IndexOfItem_ToDelete < 0 || IndexOfItem_ToDelete > _ArraySize - 1) return false;

		_ArraySize--;

		_TempArray = new DataType[_ArraySize];

		for (short i = 0; i < IndexOfItem_ToDelete; i++) {

			_TempArray[i] = _OriginalArray[i];
		}

		for (short i = IndexOfItem_ToDelete + 1; i < _ArraySize + 1; i++) {

			_TempArray[i - 1] = _OriginalArray[i];
		}

		delete[]_OriginalArray;
		_OriginalArray = _TempArray;
		return true;
	}

	bool InsertAt(short Index, DataType Value) {

		if (Index < 0 || Index > _ArraySize) return false;

		_ArraySize++;

		_TempArray = new DataType[_ArraySize];

		for (short i = 0; i < Index; i++) {

			_TempArray[i] = _OriginalArray[i];
		}

		_TempArray[Index] = Value;

		for (short i = Index; i < _ArraySize - 1; i++) {

			_TempArray[i + 1] = _OriginalArray[i];
		}

		delete[] _OriginalArray;
		_OriginalArray = _TempArray;
		return true;
	}

	bool InsertAtBeginning(DataType Value) {

		return InsertAt(0, Value);
	}

	bool InsertBefore(short Index, DataType Value) {

		if (Index < 1)
			return InsertAtBeginning(Value);

		return InsertAt(Index, Value);
	}

	bool InsertAfter(short Index, DataType Value) {

		if (Index >= _ArraySize)
			return InsertAtEnd(Value);

		return InsertAt(Index + 1, Value);
	}

	bool InsertAtEnd(DataType Value) {

		return InsertAt(_ArraySize, Value);
	}

	bool DeleteFirstItem() {

		return DeleteItemAt(0);
	}

	bool DeleteLastItem() {

		return DeleteItemAt(_ArraySize - 1);
	}

	void Reverse() {

		if (_ArraySize < 2) return;

		short ReverseCounter = floor(_ArraySize / 2);

		for (short i = 0; i < ReverseCounter; i++) {

			Swap(_OriginalArray[i], _OriginalArray[_ArraySize - 1 - i]);
		}
	}

	void PrintList() {

		for (short i = 0; i < _ArraySize; i++) {

			cout << GetItem(i) << "   ";
		}

	}

	short Size() {

		return _ArraySize;
	}

	bool IsEmpty() {

		return (_ArraySize == 0);
	}

	void Clear() {

		delete[] _TempArray;
		_ArraySize = 0;
		_TempArray = new DataType[0];
		_OriginalArray = _TempArray;
	}

	short Find(DataType Value) {

		for (short i = 0; i < _ArraySize; i++) {

			if (_OriginalArray[i] == Value)
				return i;
		}

		return -1;
	}

	short BFind(DataType Value) {

		int left = 0;
		int right = _ArraySize - 1;
		while (left <= right) {
			int mid = left + (right - left) / 2;
			if (_OriginalArray[mid] == Value) {
				return mid;
			}
			else if (_OriginalArray[mid] < Value) {
				left = mid + 1;
			}
			else {
				right = mid - 1;
			}
		}

		return -1;
	}

	void Sort() {

		for (int i = 0; i < _ArraySize - 1; i++) {

			for (int j = i + 1; j < _ArraySize; j++) {


				if (_OriginalArray[i] > _OriginalArray[j]) {

					Swap(_OriginalArray[i], _OriginalArray[j]);
				}
			}
		}
	}

	bool DeleteItem(DataType Value) {

		return DeleteItemAt(Find(Value));
	}


};

