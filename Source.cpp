#include <iostream>
using namespace std;

int MAXSIZE = 5;

struct Node {
	int data;
	Node *next;
};

Node **root = new Node*[MAXSIZE];

void MAKENULL() {
	for (int i = 0; i < MAXSIZE; i++) {
		root[i] = NULL;
	}
}

bool isEmpty(Node *row) {
	return row == NULL;
}

void Insert(int key) {
	int index = key%MAXSIZE;
	if (isEmpty(root[index])) {
		root[index] = new Node;
		root[index]->data = key;
		root[index]->next = NULL;
	} else {
		Node *temp = root[index];
		while (temp->next != NULL) {
			temp = temp->next;
		}
		temp->next = new Node;
		temp->next->next = NULL;
		temp->next->data = key;
	}
}

bool Search(int key) {
	
	int index = key%MAXSIZE;
	if (root[index] == NULL) return false;

	Node *temp = root[index];
	if (temp->data == key) return true;
	
	while (temp != NULL) {
		if (temp->data == key) 
			return true;
		temp = temp->next;
	}
	
	return false;
}

void Delete(int key) {
	int index = key%MAXSIZE;
	if (root[index] == NULL) return;

	Node *temp = root[index];
	Node *prev = NULL;

	if (temp->data == key) {
		root[index] = root[index]->next;
		delete temp;
	}
	else {
		while (temp != NULL) {
			if (temp->data == key) {
				prev->next = temp->next;
				return;
			}
			prev = temp;
			temp = temp->next;
		}
	}
}

void displayHash() { 
	for (int i = 0; i < MAXSIZE; i++) {
		cout << i << ":\t";
		if (isEmpty(root[i])) {
			cout << "----\n";
			continue;
		}
		Node *temp = root[i];
		while (temp != NULL) {
			cout << temp->data << " ";
			temp = temp->next;
		}
		cout << endl;
	}
}

void main() {
	MAKENULL();
	char CMD;
	cout << "-------------\nJUST A HASH TABLE\n";
	do {
		cout << "\n1-Insert\n2-Delete\n3-Print\n4-Search\n5-ANY KEY TO EXIT\n";
		cout << "Command:"; cin >> CMD;
		switch (CMD) {
		case '1':
			int inum;
			cout << "\nEnter Number to insert: ";
			cin >> inum;
			Insert(inum);
			break;
		case '2':
			int dnum;
			cout << "\nEnter Number to delete: ";
			cin >> dnum;
			Delete(dnum);
			break;
		case '3':
			displayHash();
			break;
		case '4':
			int snum;
			cout << "\nEnter Number to Search: ";
			cin >> snum;
			cout << Search(snum);
		}
	} while (CMD == '1' || CMD == '2' || CMD == '3' || CMD == '4');
}