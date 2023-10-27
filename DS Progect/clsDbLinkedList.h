#pragma once
#include <iostream>
using namespace std;

template <class DataType>
class clsDbLinkedList
{

protected:

	short _NumberOfNodes = 0;

public:

	class Node;

	Node* Head = NULL;
	Node* Tail = NULL;

	void PrintNodeDetails(Node* Node)
	{

		if (Node->Prev != NULL)
			cout << Node->Prev->Data;
		else
			cout << "NULL";

		cout << " <--> " << Node->Data << " <--> ";

		if (Node->Next != NULL)
			cout << Node->Next->Data << "\n";
		else
			cout << "NULL";

	}

	class Node {

	public:

		DataType Data;

		Node* Prev;
		Node* Next;
	};

	short Size() {

		return  _NumberOfNodes;
	}

	bool IsEmpty() {

		return (_NumberOfNodes == 0);
	}

	void Clear() {

		while (_NumberOfNodes > 0)
		{
			DeleteFirstNode();
		}
	}

	void Reverse() {

		Node* Current = Head;
		Node* TempPtr = nullptr;

		while (Current != NULL)
		{
			TempPtr = Current->Prev;
			Current->Prev = Current->Next;;
			Current->Next = TempPtr;

			Current = Current->Prev;
		}

		if (TempPtr != nullptr)
			Head = TempPtr->Prev;
	}

	Node* GetNode(short IndexOfNode) {

		if (IndexOfNode < 0 || IndexOfNode > _NumberOfNodes - 1) return NULL;

		Node* Current = Head; short Counter = 0;

		while (Current != NULL && (Current->Next != NULL))
		{
			if (Counter == IndexOfNode)
				break;

			Current = Current->Next;
			Counter++;
		}

		return Current;
	}

	DataType GetItem(short NodeIndex) {

		Node* TempNode = GetNode(NodeIndex);

		if (TempNode == NULL)
			return NULL;

		return TempNode->Data;
	}

	bool UpdateItem(short IndexOfNode, DataType ValueToUpdate) {

		Node* TempNode = GetNode(IndexOfNode);

		if (TempNode == NULL) return false;

		TempNode->Data = ValueToUpdate;
		return true;
	}

	void InsertAtBegining(DataType Value) {

		Node* NewNode = new Node; _NumberOfNodes++;

		NewNode->Data = Value;
		NewNode->Next = Head;
		NewNode->Prev = NULL;

		if (Head != NULL) {

			Head->Prev = NewNode;
		}

		Head = NewNode;
	}

	bool InsertAfter(Node* Current, DataType Value) {

		if (Current == NULL) return false;

		Node* NewNode = new Node; _NumberOfNodes++;

		NewNode->Data = Value;
		NewNode->Next = Current->Next;
		NewNode->Prev = Current;

		if (Current->Next != NULL) {

			Current->Next->Prev = NewNode;
		}
		Current->Next = NewNode;
		return true;
	}

	bool InsertAfter(short IndexOfNode, DataType Value) {

		Node* Node = GetNode(IndexOfNode);

		return InsertAfter(Node, Value);
	}

	void InsertAtEnd(DataType Value) {

		Node* newNode = new Node(); _NumberOfNodes++;
		newNode->Data = Value;
		newNode->Next = NULL;

		if (Head == NULL) {
			newNode->Prev = NULL;
			Head = newNode;
		}

		else {

			Node* current = Head;
			while (current->Next != NULL) {

				current = current->Next;
			}

			current->Next = newNode;
			newNode->Prev = current;
		}
	}

	Node* Find(DataType Value) {

		Node* TempNode = Head;

		while (TempNode != NULL)
		{
			if (TempNode->Data == Value) return TempNode;
			TempNode = TempNode->Next;
		}

		return NULL;
	}

	void DeleteNode(Node*& NodeToDelete) {

		if (Head == NULL || NodeToDelete == NULL) return;

		if (Head == NodeToDelete) {

			Head = NodeToDelete->Next;
		}

		if (NodeToDelete->Next != NULL) {

			NodeToDelete->Next->Prev = NodeToDelete->Prev;
		}

		if (NodeToDelete->Prev != NULL) {

			NodeToDelete->Prev->Next = NodeToDelete->Next;
		}

		delete NodeToDelete; _NumberOfNodes--;
	}

	void DeleteNode(short IndexOfNode) {

		Node* o = GetNode(IndexOfNode);
		DeleteNode(o);
	}

	void DeleteFirstNode() {


		if (Head == NULL) return;

		Node* NodeToDelete = Head;

		Head = Head->Next;

		if (Head != NULL) {

			Head->Prev = NULL;
		}

		delete NodeToDelete; _NumberOfNodes--;
	}

	void DeleteLastNode() {


		if (Head == NULL) return;

		Node* LastNodeToDelete = Head;


		if (LastNodeToDelete->Next == NULL) {

			Head = LastNodeToDelete->Next;
		}

		else {

			while (LastNodeToDelete->Next != NULL)
			{
				LastNodeToDelete = LastNodeToDelete->Next;
			}

			LastNodeToDelete->Prev->Next = NULL;
		}

		delete LastNodeToDelete; _NumberOfNodes--;
	}

	void PrintList() {

		Node* TempNode = Head;

		while (TempNode != NULL)
		{
			cout << TempNode->Data << "  ";
			TempNode = TempNode->Next;
		}
	}

	void PrintListDetails() {

		Node* TempNode = Head;

		while (TempNode != NULL)
		{
			PrintNodeDetails(TempNode);
			TempNode = TempNode->Next;
		}
	}

};

