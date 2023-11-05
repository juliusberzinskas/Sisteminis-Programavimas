#include "biblioteka.h"


void readDataFromFile(vector<Student>& Group, const string& filename) {
	std::ifstream file(filename);

	if (!file.is_open()) {
		cout << "Nepavyko atidaryti failo!" << endl;
		return;
	}

	string line, word;
	getline(file, line);  // praleidžiame pirmą eilutę (antraštę)

	while (getline(file, line)) {
		std::istringstream iss(line);
		Student student;
		iss >> student;  // naudojame jau sukurtą >> operatorių
		Group.push_back(student);
	}

	file.close();
}

void categorizeStudents(const vector<Student>& students, vector<Student>& vargsiukai, vector<Student>& kietiakiai) {
	for (const auto& student : students) {
		if (student.getResult() < 5.0) {
			vargsiukai.push_back(student);
		}
		else {
			kietiakiai.push_back(student);
		}
	}
}

int main()
{

	vector<Student> Group;
	vector<Student> Vargsiukai;
	vector<Student> Kietiakai;
	string filename = "studentai10000.txt";
	readDataFromFile(Group, filename);
	categorizeStudents(Group, Vargsiukai, Kietiakai);


	cout << "Vargsiukai:" << endl;
	cout << endl;
	for (const auto& student : Vargsiukai) {
		cout << student;
	}

	cout << "\nKietiakai:" << endl;
	for (const auto& student : Kietiakai) {
		cout << student;
	}
	// outputas atskiria studentus i vargsiukus ir kietiakus vargsiukai yra ispausdinami pirmi sarase o veliau eina kietiakai

	// irasome vargsiukus i faila
	std::ofstream vargsiukaiFile("vargsiukai.txt");
	if (!vargsiukaiFile.is_open()) {
		cout << "Nepavyko atidaryti vargsiukai.txt failo rašymui!" << endl;
		return 1;
	}

	for (const auto& student : Vargsiukai) {
		vargsiukaiFile << student;
	}
	vargsiukaiFile.close(); // Uzdarome faila

	// irasome kietekus i faila
	std::ofstream kietiakaiFile("kietiakai.txt");
	if (!kietiakaiFile.is_open()) {
		cout << "Nepavyko atidaryti kietiakai.txt failo rašymui!" << endl;
		return 1;
	}

	for (const auto& student : Kietiakai) {
		kietiakaiFile << student;
	}
	kietiakaiFile.close(); // Uzdarome faila

	cout << "Vargsiukai ir kietiakai išsaugoti atitinkamuose failuose." << endl;

	// programa sukuria failus direktorijoje vargsiukai.txt bei kietekai.txt


	return 0;

	system("pause");
}
