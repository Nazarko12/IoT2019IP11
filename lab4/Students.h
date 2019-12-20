
#include "Students.h"
#include <iostream>
using namespace std;




Students::Students(string Studentsname, int Studentsrating, int Studentsgrowth, int Studentsexamscore, int Studentsweight) {
	name = Studentsname;
	rating = Studentsrating;
	growth = Studentsgrowth;
	examscore = Studentsexamscore;
	weight = Studentsweight;
}
string Students::getName() {
	return name;
}
int Students::getRating() {
	return rating;
}
int Students::getGrowth() {
	return growth;
}
int Students::getExamscore() {
	return examscore;
}
int Students::getWeight() {
	return  weight;
}
void Students::get_inf() {
	cout << "\nStudent name  is " << "\"" << getName() << "\"" << ",Student rating is " << getRating() << ", Student growth is "
		<< getGrowth() << ", Student examscore is " << getExamscore() << ",size is " << getWeight() << "\n";
}
Students::~Students() {

}