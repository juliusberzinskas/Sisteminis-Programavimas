#include "biblioteka.h"

Student::Student() : Exam(0), Rez(0) {}

// Konstruktorius,
Student::Student(string name, string surname, vector <int> homeWork, int exam) {
	Name = name;
	Surname = surname;
	HomeWork = homeWork;
	Exam = exam;
	Result('v');
}
//Kopijavimo construktorius
Student::Student(const Student& A) {
	Name = A.Name;
	Surname = A.Surname;
	HomeWork = A.HomeWork;
	Exam = A.Exam;
	Rez = A.Rez;
}
//Priskirimo-kopijavimo operatorius
Student& Student::operator = (const Student& A) {
	if (this == &A) return *this;
	Name = A.Name;
	Surname = A.Surname;
	HomeWork = A.HomeWork;
	Exam = A.Exam;
	Rez = A.Rez;
	return *this;
}
//Destruktorius
Student::~Student() {
	Name.clear();
	Surname.clear();
	HomeWork.clear();
	Exam = 0;
	Rez = 0;
}

// Vidurkio formule
float Student::Vidurkis() {
	return std::accumulate(HomeWork.begin(), HomeWork.end(), 0.0) / HomeWork.size();
}
// Medianos formule
float Student::Mediana() {
	std::sort(HomeWork.begin(), HomeWork.end());
	return
		(HomeWork.size() % 2 == 1) ? HomeWork[HomeWork.size() / static_cast<float>(2)] / 1.0 :
		(HomeWork[HomeWork.size() / static_cast<float>(2) - 1] + HomeWork[HomeWork.size() / static_cast<float>(2)]) / 2.0;
}
void Student::Result(char pas) {
	if (pas == 'v') { Rez = 0.4 * Vidurkis() + 0.6 * Exam; }
	else { Rez = 0.4 * Mediana() + 0.6 * Exam; }
}

	// failu skaitymas
std::ostream& operator << (std::ostream& out, const Student& A) {
	out << A.Name << " ; " << A.Surname << " | ";
	for (auto& i : A.HomeWork) cout << i << " | ";
	out << A.Exam << " | ";
	out << " Rezultatas = " << A.Rez << endl;
	return out;
}

std::istream& operator >> (std::istream& in, Student& a) {
	in >> a.Name;
	in >> a.Surname;

	string grade;
	while (in >> grade && isdigit(grade[0])) {  // skaito ND iki egzo
		a.HomeWork.push_back(stoi(grade));
	}

	if (a.HomeWork.size()) {
		a.Exam = stoi(grade);  // nuskaitytas egzamino pažymys
	}

	a.Result('v');
	return in;
}
