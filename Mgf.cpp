// Mgf.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include "Ion.h"
using namespace std;
#include <fstream>

void fillVect(vector<Peptide>&);

int main()
{
/*	Peptide p(123.88001, 43521.896);
	cout << "Peptide details: " << p.peptideDetails() << endl;
	
	
	vector<Peptide> fragments;
	int a = 4;
	while (a > 0)
	{
		Peptide pp(a-0.762, a + 0.003);
		fragments.push_back(pp);
		//p.printPeptide();
		a--;
	}


	Ion anotherIon(p, "Fred", "2+", 1289, 32987, fragments);
	anotherIon.printDetails();
	cout << "Ion details: \n" << anotherIon.ionDetails() << endl;
	anotherIon.printFragments();
	cout << "List of fragments: " << anotherIon.fragmentDetails() << endl;
	cout << "end of list of fragments.";
	
	
	cout << "what is p now?  " << endl;
	p.printPeptide();
	*/
	

	// ifstream  is what is in the file i.e. read
	// ofstream is what we put into the file i.e. write
	ifstream inFile;
	inFile.open("Text.txt");
	if (inFile.fail())
	{
		cerr << "Fail at open" << endl;
		exit(1);
	}
	cout << "Char count in Text " << inFile.get() << endl;
	ofstream secondF;
	secondF.open("sec.txt");

	char line[50];
	while (!inFile.eof())
	{
		inFile.getline(line, 50);	
		if (line == "BEGIN IONS")
		{
			secondF << line << endl;
		}
		cout << "printing   " << line << endl;
	}
	
	inFile.read(line, 10);
	cout << line << endl;
	cout << "Char count in Text " << inFile.get() << endl;
	cout << "what does get lock do? " << inFile.getloc().c_str() << endl;
	secondF << endl << "bob bobby bob bob" << endl << "suaveness is here";


	
	
	inFile.close();
	secondF.close();


	return 0;
}




void fillVect(vector<Peptide>& thisVector) {
	char keepgoing = 'y';
	double mz, intens;
	while (keepgoing != 'n') {
		cout << "Enter vals mz & intensity: " << endl;
		cin >> mz;
		cin >> intens;

		Peptide pep(mz, intens);
		cout << "Entered " << pep.peptideDetails() << endl;

		thisVector.push_back(pep);
		cout << "Type \'n\' to exit or another letter to continue.";
		cin >> keepgoing;
	}
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
