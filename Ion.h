#pragma once
#include <string>
#include <vector>
#include <iostream>
#include "Peptide.h"
using namespace std;

#ifndef ION_H
#define ION_H



class Ion
{
public:

	Peptide peptide;	// original/precursor peptide
	string title;
	string charge;
	int rt;				//retention time in seconds
	int scans;
	vector<Peptide> fragments;

	// Overload Constructors
	Ion();
	Ion(Peptide&, string, string, int, int);
	Ion(Peptide&, string, string, int, int, vector<Peptide>&);

	//void addFragments(vector<Peptide>);
		// addFragments - add

	const void printDetails();
		// printDetails - prints the "header" details of Ion via cout
	const string ionDetails();
		// ionDetails - puts the "header" details of Ion into a string
	const void printFragments();
		// printFragments - prints each value in the 'fragments' 
		//		vector of Ion via cout. Newline separated.
	const string fragmentDetails();
		// fragmentDetails - puts each value in the 'fragments'
		//		vector of Ion into a string. Tab separated.

	//Destructor
	virtual ~Ion();

};

#endif // !ION_H