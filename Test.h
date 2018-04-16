/**
*	@file Test.h
*	@author
*	@date
*	@brief A header file for Test class
*/

#ifndef TEST_H
#define TEST_H

#include <iostream>
#include <vector>
#include "List.h"
#include "Node.h"
#include "LinkedListOfInts.h"

class Test
{
	public:
	Test();

  void runTests(LinkedListOfInts& testList);

  void checkIsEmpty(LinkedListOfInts& testList);

  void checkSize(LinkedListOfInts& testList);

  void checkSearch(LinkedListOfInts& testList);

  bool checkAddBack(LinkedListOfInts& testList);

  bool checkAddFront(LinkedListOfInts& testList);

  void checkRemoveBack(LinkedListOfInts& testList);

  void checkRemoveFront(LinkedListOfInts& testList);
};
#endif
