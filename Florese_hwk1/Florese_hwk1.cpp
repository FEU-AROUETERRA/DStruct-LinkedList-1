// Florese_hwk1.cpp : ignore pch.h, it is a precompiled header i.e an unused default

#include "pch.h"
#include <iostream>
#include <stdlib.h>
using namespace std;

struct Node {
	int data;
	Node *next;
};

//GLOBAL
Node *node = NULL;
Node *head = NULL;
Node *tail = NULL;
int List_Size=0;

void addNode() {
	node = new Node;
	node->next = NULL;
	cin >> node->data;
	if (head == NULL) {
		head = tail = node;
	}
	else {
		tail->next = node;
		tail = node;
	}
	++List_Size;
}

void displayLinkedList() { 
	node = head;
	cout << "{ ";
	while (node != NULL) { 
		if (node == tail) {
			cout << node->data;
			node = node->next;
		}
		else {
			cout << node->data << ", ";
			node = node->next;
		}
	} cout << " } ";
	system("pause"); 
}

#pragma region  Homework: Search Function


void search() {
	int value, pos = 0;
	node = head;
	cout << "Search: ";
	cin >> value;

	for (int i = 0; i <= List_Size; i++) {
		pos = pos++;
		if (node != NULL) {
			if (node->data == value) {
				
				cout << "Output: " << " Value has been found! ";
				cout << "( @position[" << pos << "] ) " << endl;
				break;
			}
			
			else {
				node = node->next;
			}
		}
		else {
			cout << "Output: " << " Value does not exist! " << endl;
		}
	}

	system("pause");
}

#pragma endregion

void menu() {
	int choice;system("cls");cout << "1. Add Node" 	<< endl;
	cout << "2. Show List" << endl;
	cout << "3. Search" << endl;
	cout << "3. Exit" << endl;
	cout << "Choice: ";
	cin >> choice;
	switch (choice) {
	case 1:addNode();break;
	case 2:displayLinkedList();break;
	case 3:search();break; // NEW
	case 4:exit(1);break;
	}
}

int main()
{
	while (true) {
		menu();
	}
	return 0;
}

