#include <iostream>
#include <string>
#include <iomanip>
#include <vector>
#include <algorithm> // Для std::sort

using namespace std;

struct Student {
    string name;
    string group;
    string recordBookNumber;
    vector<int> grades; // Используем vector вместо raw указателя

    double averageGrade() const {
        double sum = 0;
        for (int grade : grades) {
            sum += grade;
        }
        return grades.size() > 0 ? sum / grades.size() : 0; // Избегаем деления на 0
    }
};

bool compareStudents(const Student& a, const Student& b) {
    return a.averageGrade() > b.averageGrade(); // Сравниваем по убыванию
}

class StudentList {
private:
    vector<Student> students; // Храним студентов в векторе

public:
    void addStudent(const Student& student) {
        students.push_back(student);
    }

    void sort() {
        std::sort(students.begin(), students.end(), compareStudents);
    }

    void display() const {
        for (const auto& s : students) {
            cout << "ФИО: " << s.name << ", Группа: " << s.group
                << ", Номер зачетной книжки: " << s.recordBookNumber
                << ", Средний балл: " << fixed << setprecision(2)
                << s.averageGrade() << endl;
        }
    }
};

int main() {
    setlocale(LC_ALL, "Russian");

    StudentList studentsList;

    // Добавляем студентов
    Student s1;
    s1.name = "Иванов И.И.";
    s1.group = "Группа 1";
    s1.recordBookNumber = "123456";
    s1.grades = { 4, 5, 3, 4 };

    Student s2;
    s2.name = "Петрова П.П.";
    s2.group = "Группа 2";
    s2.recordBookNumber = "654321";
    s2.grades = { 5, 5, 5, 4 };

    Student s3;
    s3.name = "Сидоров С.С.";
    s3.group = "Группа 3";
    s3.recordBookNumber = "111222";
    s3.grades = { 3, 3, 4, 5 };

    Student s4;
    s4.name = "Кузьменко Ф.С.";
    s4.group = "Группа ИУ8-13";
    s4.recordBookNumber = "111223";
    s4.grades = { 5, 5, 5, 5 };

    studentsList.addStudent(s1);
    studentsList.addStudent(s2);
    studentsList.addStudent(s3);
    studentsList.addStudent(s4);

    cout << "Список студентов до сортировки:" << endl;
    studentsList.display();

    studentsList.sort();

    cout << "\nСписок студентов после сортировки:" << endl;
    studentsList.display();

    return 0;
}
