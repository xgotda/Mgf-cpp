#include "pch.h"
#include "Ion.h"


Ion::Ion()
{
	Peptide peptide();
	title = "";
	charge = "";
	rt = 0;
	scans = 0;
	//fragments = vector<Peptide>;
}

Ion::Ion(Peptide& aPeptide, string aTitle, string aCharge, int retentionTime, int numberOfScans) {
	
	peptide = aPeptide;
	title = aTitle;
	charge = aCharge;
	rt = retentionTime;
	scans = numberOfScans;
}

Ion::Ion(Peptide& aPeptide, string aTitle, string aCharge, int retentionTime, int numberOfScans, vector<Peptide>& fragmentList) {

	peptide = aPeptide;
	title = aTitle;
	charge = aCharge;
	rt = retentionTime;
	scans = numberOfScans;
	fragments = fragmentList;
}

const void Ion::printDetails() {
	cout << "Title: " << title << endl;
	cout << "Charge: " << charge << endl;
	cout << "RT: " << rt << endl;
	cout << "Scans: " << scans << endl;
	cout << "Precursor peptide values (m\/z, intensity): " << peptide.peptideDetails() << endl;

}

const string Ion::ionDetails() {
	string details;
	details = "Title \t Charge \t\t RT \t Scans \t Pep \n ";
	details = details + title + "\t " + charge + "\t" + to_string(rt) + "\t" + to_string(scans) + "\t" + peptide.peptideDetails() ;
	return details;
}

const string Ion::fragmentDetails() {
	string details;
	int number = fragments.size();

	for (int i = 0; i < number; i++)
	{
		details = details + fragments[i].peptideDetails() + "\t";
	}
	return details;
}

const void Ion::printFragments() {
	int noOfFragments = fragments.size();

	for (int i = 0; i < noOfFragments; i++)
	{
		cout << "Frag " << i + 1 << ": " << fragments[i].peptideDetails() << endl;
	}
}

Ion::~Ion()
{
	//std::cout << "Say \"Bye bye Ion " << title << " \"!";
}
