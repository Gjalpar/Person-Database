#include "program.h"

int main(){
	Program TermProject;

	TermProject.loadFile("input.txt");

	TermProject.printByAge();
	TermProject.printByName();

	TermProject.remove("elif");
	TermProject.remove("deniz");
	TermProject.remove("eren");
	cout << endl;

	TermProject.printByAge();
	TermProject.printByName();

	TermProject.update("sude", 18);
	TermProject.update("eren", 19);
	TermProject.update("bugra", 25);
	cout << endl;

	TermProject.printByAge();
	TermProject.printByName();

	TermProject.add("sude", 18);
	cout << "Adding this person to the list: sude 18" << endl;
	TermProject.add("eren", 19);
	cout << "Adding this person to the list: eren 19" << endl << endl;

	TermProject.printByAge();
	TermProject.printByName();

	TermProject.saveToFileByAge("age.txt");
	TermProject.saveToFileByName("name.txt");

	return 0;
}