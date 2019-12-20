#include <iostream>
#include "Students.h"
using namespace std;

int main() {
	Students first("IvanPetrenko", 10, 177, 200, 61);
	first.education = "middle";
	first.certificats = 5;
	first.get_inf();
	cout << "The country of supply is " << first.education << endl;
	cout << "number of index is " << first.certificats << endl;

	Students second("VasylShevchenko", 5, 169, 195, 66);
	second.education = "middle";
	second.certificats = 10;
	second.get_inf();
	cout << " The education is " << second.education << endl;
	cout << " Number of certificats is  " << second.certificats << endl;

	Students third("RomanLevytskiy", 12, 183, 189, 71);
	third.education = "middle";
	third.certificats = 17;
	third.get_inf();
	cout << "The education is " << third.education << endl;
	cout << "Number of certificats is  " << third.certificats << endl;

}