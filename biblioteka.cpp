#include "biblioteka.h"

Student::Student() {
	cout << "declared..." << endl;
}
// Konstruktorius
Student::Student(string name, string surname, vector <int> homeWork, int exam) {
	Name = name;
	Surname = surname;
	HomeWork = homeWork;
	Exam = exam;
	Result();
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
		(HomeWork.size() % 2 == 1) ? HomeWork[HomeWork.size() / 2] / 1.0 :
		(HomeWork[HomeWork.size() / 2 - 1] + HomeWork[HomeWork.size() / 2]) / 2.0;
}
void Student::Result() {
	char opt;
	while (true) {
		cout << endl;
		cout << "Kaip norite skaiciuoti?" << endl;
		cout << "mediana, parasykite m | vidurkis, parasykite v : ";
		cin >> opt;
		if (opt == 'v') {
			Rez = 0.4 * Vidurkis() + 0.6 * Exam;
			ResultType = 'v';
			break;
		}
		else if (opt == 'm') {
			Rez = 0.4 * Mediana() + 0.6 * Exam;
			ResultType = 'm';
			break;
		}

		else {
			cout << "Klaidingai ivestas pasirinkimas. Bandykite dar karta." << endl;
		}
	}
}
void Student::print() {
    cout << std::setw(12) << Surname << std::setw(12) << Name;

    if (ResultType == 'v') {
        cout << std::setw(20) << std::fixed << std::setprecision(2) << Rez;
        cout << std::setw(20) << "//";
    }
    else {
        cout << std::setw(20) << "//";
        cout << std::setw(20) << std::fixed << std::setprecision(2) << Rez;
    }
    cout << endl;
}


int minimum(int a, int b)
{
	return 0;
}
