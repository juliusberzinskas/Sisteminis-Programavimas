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

int main()
{
	vector<Student> Group;
	string filename = "studentai10000.txt";
	readDataFromFile(Group, filename); // Skaitome failą TIK KARTĄ

	for (int i = 0; i < 3; i++) {
		for (auto& duom : Group) {
			cout << duom; // Atspausdiname studentų duomenis 3 kartus
		}
	}

	system("pause");
}