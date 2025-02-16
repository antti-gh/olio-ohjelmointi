#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Student {
private:
    string name;
    int age;

public:
    Student(string n, int a) : name(n), age(a) {}

    void setAge(int a) { age = a; }
    void setName(string n) { name = n; }

    string getName() const { return name; }
    int getAge() const { return age; }

    void printStudentInfo() const {
        cout << "Name: " << name << ", Age: " << age << endl;
    }
};

int main() {
    int selection = 0;
    vector<Student> studentList;

    studentList.push_back(Student("Antti", 30));
    studentList.push_back(Student("Jaakko", 26));
    studentList.push_back(Student("Noora", 28));
    studentList.push_back(Student("Maiju", 27));

    do {
        cout << endl;
        cout << "Select" << endl;
        cout << "Add students = 0" << endl;
        cout << "Print all students = 1" << endl;
        cout << "Sort and print students according to Name = 2" << endl;
        cout << "Sort and print students according to Age = 3" << endl;
        cout << "Find and print student = 4" << endl;
        cout << "Exit = 5" << endl;
        cin >> selection;

        switch (selection) {
        case 0: {
            string name;
            int age;
            cout << "Anna nimi: ";
            cin >> name;
            cout << "Anna ika: ";
            cin >> age;
            studentList.push_back(Student(name, age));
            break;
        }

        case 1:
            cout << "Opiskelijat:" << endl;
            for (const auto& student : studentList) {
                student.printStudentInfo();
            }
            break;

        case 2:
            sort(studentList.begin(), studentList.end(),
                 [](const Student& a, const Student& b) { return a.getName() < b.getName(); });

            cout << "Lajiteltu nimen perusteella: " << endl;
            for (const auto& student : studentList) {
                student.printStudentInfo();
            }
            break;

        case 3:
            sort(studentList.begin(), studentList.end(),
                 [](const Student& a, const Student& b) { return a.getAge() < b.getAge(); });

            cout << "Lajiteltu ian perusteella: " << endl;
            for (const auto& student : studentList) {
                student.printStudentInfo();
            }
            break;

        case 4: {
            string searchName;
            cout << "Anna etsittava nimi: ";
            cin >> searchName;

            auto it = find_if(studentList.begin(), studentList.end(),
                              [&searchName](const Student& s) { return s.getName() == searchName; });

            if (it != studentList.end()) {
                cout << "Loydetty opiskelija: " << endl;
                it->printStudentInfo();
            } else {
                cout << "Opiskelijaa ei loytynyt." << endl;
            }
            break;
        }

        case 5:
            cout << "Lopetetaan ohjelma..." << endl;
            return 0;

        default:
            cout << "Vaara valinta, yrita uudelleen." << endl;
            break;
        }
    } while (selection < 5);

    return 0;
}

