#pragma once
#include "clsMyQueueArr.h"

template <class DataType>
class clsMyStackArr : public  clsMyQueueArr <DataType>
{
public:

	void push(DataType Value) {

		clsMyQueueArr <DataType>::_MyList.InsertAtBeginning(Value);
	}

	DataType Top() {

		return clsMyQueueArr <DataType>::front();
	}

	DataType Bottom() {

		return clsMyQueueArr <DataType>::back();
	}
};

