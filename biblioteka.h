#ifndef  BIBLIOTEKA_H
#define BIBLIOTEKA_H

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <numeric>
#include <cctype>
#include <limits>
#include <fstream>
#include <sstream>
using std::vector;
using std::cout;
using std::cin;
using std::endl;
using std::string;

class Student {
private:
	string Name, Surname;
	vector <int> HomeWork;     
	int Exam;
	float Rez;
public:
	Student();
	// Konstruktorius
	Student(string name, string surname, vector <int> homeWork, int exam);
	//Kopijavimo construktorius
	Student(const Student& A);
	//Priskirimo-kopijavimo operatorius
	Student& operator = (const Student& A);
	//Destruktorius
	~Student();
	// Vidurkio formule
	float Vidurkis();
	// Medianos formule
	float Mediana();
	void Result(char pas);
	//setters
	inline void SetName(string name) { Name = name; };
	inline void SetSurname(string surname) { Surname = surname; };
	inline void SetHomeWork(vector <int> Vec) { HomeWork = Vec; };
	inline void SetExam(int n) { Exam = n; };
	void print();
	float getResult() const {return Rez;}
	void readDataFromFile(vector<Student>& Group, const string& filename);
	void categorizeStudents(const vector<Student>& students, vector<Student>& vargsiukai, vector<Student>& kietiakai);

	// failu skaitymas
	friend std::ostream& operator <<(std::ostream& out, const Student& A);
	friend std::istream& operator >> (std::istream& in, Student& A);
	
};

#endif // ! BIBLIOTEKA.H
