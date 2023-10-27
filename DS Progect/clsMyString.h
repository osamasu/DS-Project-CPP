#pragma once

#include <iostream>
#include "clsMyStack.h"
using namespace std;

class clsMyString
{

private:

	string _Value;

	clsMyStack <string> _UndoHistory;
	
	clsMyStack <string> _RedoHistory;


public:

	clsMyString() {

		_Value = "";
		_UndoHistory.push(_Value);
	}

	void SetValue(string Value) {

		_UndoHistory.push(_Value);

		_Value = Value;
	}

	string GetValue() {

		return _Value;
	}
	__declspec(property(put = SetValue, get = GetValue)) string Value;


	void Undo() {

		if (!_UndoHistory.IsEmpty()) {

			_RedoHistory.push(_Value);

			_Value = _UndoHistory.Top();
			_UndoHistory.pop();
		}
	}

	void Redo() {

		if (!_RedoHistory.IsEmpty()) {

			_UndoHistory.push(_Value);
			_Value = _RedoHistory.Top();
			_RedoHistory.pop();
		}
	}
};

