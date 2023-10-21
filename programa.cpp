#include "biblioteka.h"

bool isString(const string& s) {
	for (char c : s) {
		if (isdigit(c)) {  // Checks if a character is a digit
			return false;
		}
	}
	return true;
}

int main()
{
	vector<Student> Group;
	for (int i = 0; i < 3; i++) {
		Student point;
		string poinT;
		vector <int> Vec;

		cout << "Iveskite Varda: ";
		while (true) {
			cin >> poinT;
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			if (isString(poinT)) {
				point.SetName(poinT);
				break;
			}
			else {
				cout << "Neteisingas vardas. Iveskite Varda: ";
			}
		}

		cout << "Iveskite Pavarde: ";
		while (true) {
			cin >> poinT;
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			if (isString(poinT)) {
				point.SetSurname(poinT);
				break;
			}
			else {
				cout << "Neteisinga pavarde. Iveskite pavarde: ";
			}
		}

		cout << "Pazimiu skaicius semestre: ";
		int hw; cin >> hw;
		for (int i = 0; i < hw; i++)
		{
			int pazim;
			cout << "Iveskite " << i + 1 << " pazymi: ";
			cin >> pazim; Vec.push_back(pazim);
		}

		point.SetHomeWork(Vec); Vec.clear();
		cout << "Iveskite egzamino pazymi: ";
		cin >> hw;
		point.SetExam(hw);
		point.Result();
	/*	cin >> point;*/
		Group.push_back(point);

		cout << std::setw(12) << "Pavard?" << std::setw(12) << "Vardas";
    cout << std::setw(20) << "Galutinis (Vid.)" << std::setw(20) << "Galutinis (Med.)" << endl;
    cout << "-----------------------------------------------------------" << endl;
	}
	for (auto& duom : Group) duom.print(); 

	system("pause");
}
