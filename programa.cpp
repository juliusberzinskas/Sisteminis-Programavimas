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

	std::ofstream vargsiukaiFile("Vargsiukai.txt");
	std::ofstream kietiakaiFile("Kietiakai.txt");

	if (!vargsiukaiFile.is_open() || !kietiakaiFile.is_open()) {
		cout << "Nepavyko atidaryti failų išsaugojimui!" << endl;
		return 1;
	}

	for (const auto& student : Vargsiukai) {
		vargsiukaiFile << student;
	}

	for (const auto& student : Kietiakai) {
		kietiakaiFile << student;
	}

	// uzdaro failus
	vargsiukaiFile.close();
	kietiakaiFile.close();

	cout << "Duomenys išsaugoti atitinkamuose failuose." << endl;

	return 0;
}
