#pragma once
#include <string>
#include <iostream>
using namespace std;

#ifndef PEPTIDE_H
#define PEPTIDE_H


class Peptide
{
	double m_z;		// m/z
	double intensity;

public:

	Peptide();
	Peptide(double, double);
	
	double gmz() const;		//gmz= get m_z
	double gity() const;	//gity = get intensity
	const void printPeptide();
	const string peptideDetails();

	virtual ~Peptide();		//destructor

};

#endif