/*
	Orion Davis (3003072) ord4@zips.uakron.edu
	The University of Akron
	Computer Science II, Prof. Will
	ASSGN5: Char Linked List
*/
#include <iostream>
#include "charList.hpp"

// Default constructor makes sure head pointer isn't pointing to garbage
CharList::CharList(){
	head = nullptr;
}
/*********************************************************************
* appendNode will add a node to the end of the linked list           *
* PRE:  Char value                                                   *
* POST: Linked list now has passed char value appended into the liste*
*********************************************************************/
void CharList::appendNode(char myChar){
	ListNode *newNode;
	ListNode *nodePtr;

	newNode = new ListNode;
	newNode->value = myChar;
	newNode->next = nullptr;

	if(!head){
		head = newNode;
	}
	else{
		nodePtr = head;
		while(nodePtr->next){
			nodePtr = nodePtr->next;
		}
		nodePtr->next = newNode;
	}
}

/******************************************************************************
* insertNode will insert a node into the linked list so that it remains in    *
*  descending order                                                           *
* PRE:  Char value                                                            *
* POST: New node inserted into the linked list where the proper order is kept *
******************************************************************************/
void CharList::insertNode(char myChar){
	ListNode *newNode;
	ListNode *nodePtr;
	ListNode *previousNode = nullptr;

	newNode = new ListNode;
	newNode->value = myChar;

	if(!head){
		head = newNode;
		newNode->next = nullptr;
	}
	else{
		nodePtr = head;
		previousNode = nullptr;
		while(nodePtr != nullptr && nodePtr->value > myChar){
			previousNode = nodePtr;
			nodePtr = nodePtr->next;
		}
		if(previousNode == nullptr){
			head = newNode;
			newNode->next = nodePtr;
		}
		else{
			previousNode->next = newNode;
			newNode->next = nodePtr;
		}
	}
}

/*****************************************************************************
* deleteNode will take in a char value and delete one (if multiple) instance *
*  of that char in the linked list                                           *
* PRE:  Char value                                                           *
* POST: One specific instance of the char value will be deleted from list    *
*****************************************************************************/
void CharList::deleteNode(char myChar){
	ListNode *nodePtr;
	ListNode *previousNode;

	if(!head){
		return;
	}

	if(head->value == myChar){
		nodePtr = head->next;
		delete head;
		head = nodePtr;
	}
	else{
		nodePtr = head;
		while(nodePtr != nullptr && nodePtr->value != myChar){
			previousNode = nodePtr;
			nodePtr = nodePtr->next;
		}
		if(nodePtr){
			previousNode->next = nodePtr->next;
		}
	}
}

//**************************************************
// displayList shows the value                     *
// stored in each node of the linked list          *
// pointed to by head.                             *
// pre: an empty parameter list                    *
// post: standard output of the linked list        *
//**************************************************
void CharList::displayList() const
{
   ListNode *nodePtr;  // To move through the list

   // Position nodePtr at the head of the list.
   nodePtr = head;
   short count = 0;

   // While nodePtr points to a node, traverse
   // the list.
   while (nodePtr)
   {
      // Display the value in this node.
      std::cout << "[" << nodePtr->value << "] -> ";
      ++count;
      // Move to the next node.
      nodePtr = nodePtr->next;
      if (count % 10 == 0) {
        std::cout << std::endl;
        count = 0;
      }
   }
   std::cout << std::endl;
}

//**************************************************
// Destructor                                      *
// This function deletes every node in the list.   *
// pre: n/a                                        *
// post: destroyed object                          *
//**************************************************
CharList::~CharList()
{
   ListNode *nodePtr;   // To traverse the list
   ListNode *nextNode;  // To point to the next node

   // Position nodePtr at the head of the list.
   nodePtr = head;

   // While nodePtr is not at the end of the list...
   while (nodePtr != nullptr)
   {
      // Save a pointer to the next node.
      nextNode = nodePtr->next;

      // Delete the current node.
      delete nodePtr;

      // Position nodePtr at the next node.
      nodePtr = nextNode;
   }
}
