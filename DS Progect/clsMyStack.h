#pragma once
#include "clsMyQueue.h"

template <class DataType>
class clsMyStack : public clsMyQueue <DataType>
{

public:

	void push(DataType ItemValue) {

		clsMyQueue <DataType>::_MyList.InsertAtBegining(ItemValue);
	}

	DataType Top() {

		return clsMyQueue <DataType>::front();
	}

	DataType Bottom() {

		return clsMyQueue <DataType>::back();
	}
	
};

