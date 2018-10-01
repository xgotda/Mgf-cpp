#include "pch.h"
#include "Peptide.h"


Peptide::Peptide()
{
	m_z = 0.0;
	intensity = 0.0;
}

Peptide::Peptide(double m_zValue, double intensityValue) {
	m_z = m_zValue;
	intensity = intensityValue;
}

double Peptide::gmz() const {
	return m_z;
}

double Peptide::gity() const {
	return intensity;
}

const void Peptide::printPeptide() {
	std:: cout << "[" << to_string(m_z) << ", " << to_string(intensity) << "]" << std::endl;
}

const string Peptide::peptideDetails() {
	string details;
	details = "[" + to_string(m_z) + ", " + to_string(intensity) + "]";
	return details;
}

Peptide::~Peptide()
{
	//std::cout << "\n bye bye "<< peptideDetails() << std::endl;
}
