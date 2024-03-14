#ifndef PROGRAM
#define PROGRAM

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class Node{
	public:
		int age;
		string name;
		Node *ageNext;
		Node *nameNext;

		Node(){
			ageNext=0;
			nameNext=0;
		}

		Node(int age_, string name_, Node *ageNext_=0, Node *nameNext_=0){
			age=age_;
			name=name_;
			ageNext=ageNext_;
			nameNext=nameNext_;
		}
};

class Program{
	private:
		Node *ageNode;
		Node *nameNode;

	public:
		Program(){
			ageNode=0;
			nameNode=0;
		}

		void add(string, int);
		bool remove(string);
		void update(string, int);
		void printByAge();
		void printByName();
		void loadFile(string);
		void saveToFileByAge(string);
		void saveToFileByName(string);
};

#endif