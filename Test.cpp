#include "Test.h"
#include <iostream>
#include <vector>
Test::Test(){

}
void Test::runTests(LinkedListOfInts& testList){
	bool check1;
	bool check2;
  std::cout << "Test 1: Check isEmpty on empty list: ";
  checkIsEmpty(testList);
  std::cout << "Test 2: Check size on empty list: ";
  checkSize(testList);
  std::cout << "Test 3: Check search on empty list: ";
  checkSearch(testList);
  std::cout << "Test 4: Check addBack on an empty list: ";
  check1 = checkAddBack(testList);
  std::cout << "Test 5: Check addFront on empty list: ";
  check2 = checkAddFront(testList);
  std::cout << "Test 6: Check removeBack on empty list: ";
  checkRemoveBack(testList);
  std::cout << "Test 7: Check removeFront on empty list: ";
  checkRemoveFront(testList);
  if(check1) {
	  testList.addBack(1);
	  testList.addBack(2);
  }
  else if(check2) {
	  testList.addFront(2);
	  testList.addFront(1);
  }
  else {
	  std::cout << "The next test results are inconclusive since neither addFront nor addBack work.\n";
  }
  std::cout << "Test 8: Check isEmpty on populated list: ";
  checkIsEmpty(testList);
  std::cout << "Test 9: Check size on populated list: ";
  checkSize(testList);
  std::cout << "Test 10: Check search on populated list: ";
  checkSearch(testList);
  std::cout << "Test 11: Check addBack on populated list: ";
  check1 = checkAddBack(testList);
  std::cout << "Test 12: Check addFront on populated list: ";
  check2 = checkAddFront(testList);
  std::cout << "Test 13: Check removeBack on populated list: ";
  checkRemoveBack(testList);
  std::cout << "Test 14: Check removeFront on populated list: ";
  checkRemoveFront(testList);


}

void Test::checkIsEmpty(LinkedListOfInts& testList){
	bool check;
	check = testList.isEmpty();
	std::vector<int> vec = testList.toVector();
	//std::cout << vec.size();

  if ((vec.size() == 0) && (check == true)){
	  std::cout << "Passed!\n";
  }
  else if ((vec.size() != 0) && (check == false)){
	  std::cout << "Passed!\n";
  }
  else if ((vec.size() == 0) && (check == false)) {
	  std::cout << "Failed! Says it isn't empty, but it is.\n";
  }
  else {
	  std::cout << "Failed! Says it is empty, but it isn't.\n";
  }


}

void Test::checkSize(LinkedListOfInts& testList){
	int check;
	check = testList.size();
	std::vector<int> vec = testList.toVector();
	if (vec.size() == check) {
		std::cout << "Passed!\n";
	}
	else {
		std::cout << "Failed!\n";
	}
}

void Test::checkSearch(LinkedListOfInts& testList){
  std::vector<int> vec = testList.toVector();
	bool check;
	bool isThere;
	int val = 1;
	check = testList.search(val);
	std::vector<int>::iterator it;
	if (check) {
		for (it = vec.begin(); it != vec.end(); it++) {
			if (*it == val) {
				isThere = true;
				break;
			}
			else {
				isThere = false;
			}
		}
		if (isThere) {
			std::cout << "Passed!\n";
		}
		else {
			std::cout << "Failed! Says the value is there, but it isn't.\n";
		}
	}
	else {
		for (it = vec.begin(); it != vec.end(); it++) {
			if (*it == val) {
				isThere = true;
				break;
			}
			else {
				isThere = false;
			}
		}
		if (isThere) {
			std::cout << "Failed! Says the value isn't there, but it is.\n";
		}
		else {
			std::cout << "Passed!\n";
		}
	}
}

bool Test::checkAddBack(LinkedListOfInts& testList){
	int size1;
	int size2;
	std::vector<int> vec = testList.toVector();
	size1 = vec.size();
	testList.addBack(1);
	std::vector<int> vec2 = testList.toVector();
	size2 = vec2.size();
	if ((size2 - size1) == 1) {
		if (size1 == 0){
			std::cout << "Passed!\n";
			return true;
		}
		else if (vec[size1-1] != vec2[size2-1]) {
			std::cout << "Passed!\n";
			return true;
		}
		else {
			std::cout << "Failed! Added value, but not to back.\n";
			return false;
		}
	}
	else {
		std::cout << "Failed! Did not add value.\n";
		return false;
	}
}

bool Test::checkAddFront(LinkedListOfInts& testList){
	//int size1;
	//int size2;
	std::vector<int> vec = testList.toVector();
	//size1 = vec.size();
	//std::cout << vec.size();
	testList.addFront(1);
	std::vector<int> vec2 = testList.toVector();
	//size2 = vec2.size();
	if ((vec2.size() - vec.size()) == 1) {
		if (vec.size() == 0){
			std::cout << "Passed!\n";
			return true;
		}
		else if (vec[0] != vec2[0]) {
			std::cout << "Passed!\n";
			return true;
		}
		else {
			std::cout << "Failed! Added value, but not to front.\n";
			return false;
		}
	}
	else {
		std::cout << "Failed! Did not add value.\n";
		return false;
	}
}

void Test::checkRemoveBack(LinkedListOfInts& testList){
	int size1;
	int size2;
	bool check;
	std::vector<int> vec = testList.toVector();
	size1 = vec.size();
	check = testList.removeBack();
	if (check == true) {
		std::vector<int> vec2 = testList.toVector();
		size2 = vec2.size();
		if ((size1 - size2) == 1) {
			if (size2 == 0){
				std::cout << "Passed!\n";
			}
			else if (vec[size1-1] != vec2[size2-1]) {
				std::cout << "Passed!\n";
			}
			else {
				std::cout << "Failed! Removed value, but not from back.\n";
			}
		}
		else {
			std::cout << "Failed! Did not remove value.\n";
		}
	}
	else {
		if (size1 == 0) {
			std::cout << "Passed!\n";
		}
		else {
			std::cout << "Failed! Returned false when size > 0.\n";
		}
	}


}

void Test::checkRemoveFront(LinkedListOfInts& testList){
	int size1;
	int size2;
	bool check;
	std::vector<int> vec = testList.toVector();
	size1 = vec.size();
	check = testList.removeFront();
	if (check == true) {
		std::vector<int> vec2 = testList.toVector();
		size2 = vec2.size();
		if ((size1 - size2) == 1) {
			if (size2 == 0){
				std::cout << "Passed!\n";
			}
			else if (vec[0] != vec2[0]) {
				std::cout << "Passed!\n";
			}
			else {
				std::cout << "Failed! Removed value, but not from front.\n";
			}
		}
		else {
			std::cout << "Failed! Did not remove value.\n";
		}
	}
	else {
		if (size1 == 0) {
			std::cout << "Passed!\n";
		}
		else {
			std::cout << "Failed! Returned false when size > 0.\n";
		}
	}
}
