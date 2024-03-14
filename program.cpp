#include "program.h"

void Program::add(string name, int age){
	if(ageNode==0){
		ageNode=new Node(age, name);
		nameNode=ageNode;
	}

	else{
		Node *pointer=new Node(age, name);
		
		if(age>(ageNode->age)){
			Node *temp=ageNode;

			while(temp->ageNext!=0){
				if(age<(temp->ageNext->age)){
					pointer->ageNext=temp->ageNext;
					temp->ageNext=pointer;
					break;
				}

				temp=temp->ageNext;
			}

			if(temp->ageNext==0){
				temp->ageNext=pointer;
			}
		}

		else{
			pointer->ageNext=ageNode;
			ageNode=pointer;
		}

		if(name[0]>(nameNode->name)[0]){
			Node *temp=nameNode;
			
			while(temp->nameNext!=0){
				if(name[0]<(temp->nameNext->name)[0]){
					pointer->nameNext=temp->nameNext;
					temp->nameNext=pointer;
					break;
				}

				temp=temp->nameNext;
			}

			if(temp->nameNext==0){
				temp->nameNext=pointer;
			}
		}

		else{
			pointer->nameNext=nameNode;
			nameNode=pointer;
		}
	}
}

bool Program::remove(string name){
	if(ageNode==0){
		cout << "Cannot remove " << name << " because the list is empty." << endl;
		return false;
	}

	if(name==ageNode->name){
		ageNode=ageNode->ageNext;
		cout << name << " has been removed from the list." << endl;
	}

	else if(ageNode->ageNext!=0){
		Node *temp=ageNode;

		while(temp->ageNext!=0){
			if(name==temp->ageNext->name){
				temp->ageNext=temp->ageNext->ageNext;
				cout << name << " has been removed from the list." << endl;
				break;
			}

			temp=temp->ageNext;
		}

		if(temp->ageNext==0){
				cout << "Cannot remove " << name << " because it is not in the list." << endl;
				return false;
		}
	}

	else{
		cout << "Cannot remove " << name << " because it is not in the list." << endl;
		return false;
	}

	if(name==nameNode->name){
		nameNode=nameNode->nameNext;
		return true;
	}

	else if(nameNode->nameNext!=0){
		Node *temp=nameNode;

		while(temp->nameNext!=0){
			if(name==temp->nameNext->name){
				temp->nameNext=temp->nameNext->nameNext;
				return true;
			}

			temp=temp->nameNext;
		}
	}

	return false;
}

void Program::update(string name, int age){
	if(ageNode==0)
		cout << "Cannot update " << name << " because the list is empty." << endl;

	if(name==ageNode->name){
		ageNode=ageNode->ageNext;
		add(name, age);
		cout << name << "'s age has been updated to " << age << "." << endl;
	}

	else if(ageNode->ageNext==0)
		cout << "Cannot update " << name << " because it is not in the list." << endl;

	else{
		Node *temp=ageNode;

		while(temp->ageNext!=0){
			if(name==temp->ageNext->name){
				temp->ageNext=temp->ageNext->ageNext;
				add(name, age);
				cout << name << "'s age has been updated to " << age << "." << endl;
				break;
			}

			temp=temp->ageNext;
		}

		if(temp->ageNext==0){
				cout << "Cannot update " << name << " because it is not in the list." << endl;
		}
	}
	
	if(name==nameNode->name && nameNode->age!=age){
		nameNode=nameNode->nameNext;
	}

	Node *temp=nameNode;

	while(temp->nameNext!=0){
		if(name==temp->nameNext->name && temp->nameNext->age!=age){
			temp->nameNext=temp->nameNext->nameNext;
			break;
		}

		temp=temp->nameNext;
	}
}

void Program::printByAge(){
	cout << "Persons sorted by age:" << endl;
	Node *temp=ageNode;

	while(temp!=0){
		cout << temp->name << " " << temp->age << endl;
		temp=temp->ageNext;
	}

	cout << endl;
}

void Program::printByName(){
	cout << "Persons sorted by name:" << endl;
	Node *temp=nameNode;

	while(temp!=0){
		cout << temp->name << " " << temp->age << endl;
		temp=temp->nameNext;
	}

	cout << endl;
}

void Program::loadFile(string filename){
	cout << "Loading file..." << endl << endl;

	ifstream file;
	file.open(filename.c_str());
	int age;
	string name;

	while(file >> name){
		file >> age;
		add(name, age);
		cout << "Adding this person to the list: " << name << " " << age << endl;
	}

	file.close();

	cout << endl;
	cout << "Successfully loaded file!" << endl << endl;
}

void Program::saveToFileByAge(string filename){
	ofstream file;
	file.open(filename.c_str());
	Node* temp=ageNode;

	while(temp!=0){
		file << temp->name << " " << temp->age << endl;
		temp=temp->ageNext;
	}

	file.close();

	cout << "Successfully saved persons to a file sorted by age!" << endl;
}

void Program::saveToFileByName(string filename){
	ofstream file;
	file.open(filename.c_str());
	Node *temp=nameNode;

	while(temp!=0){
		file << temp->name << " " << temp->age << endl;
		temp=temp->nameNext;
		}

	file.close();

	cout << "Successfully saved persons to a file sorted by name!" << endl;
}