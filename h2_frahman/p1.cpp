// p1.cpp - F. Rahman
using namespace std;
#include <iostream>
#include <string>

class Student{
private:
    string StudentName;
    int exam_1grade;
    int exam_2grade;

    double calcGPA(){
      return (exam_1grade + exam_2grade) / 2.0;
    }


public:

    Student(string name, int exam_1grade, int exam_2grade) {

    setStudentName(name);
    setexam_1grade(exam_1grade);
    setexam_2grade(exam_2grade);

  }

       char getGrade() {

       double gpa = calcGPA();

        if (gpa >= 90 && gpa <= 100)
        return 'A';
        else if (gpa >= 80)
        return 'B';
        else if (gpa >= 70)
        return 'C';
        else if (gpa >= 60)
        return 'D';
        else return 'F';
          }


    void setStudentName (string name);
    void setexam_1grade (int grade);
    void setexam_2grade (int grade);


    string getStudentName();
    int getexam_1grade();
    int getexam_2grade();

};

void Student::setStudentName(string name)
  { StudentName = name;}
void Student::setexam_1grade(int grade)
  { exam_1grade = grade; }
void Student::setexam_2grade(int grade)
  { exam_2grade = grade; }

string Student::getStudentName()
  { return StudentName; }
int Student::getexam_1grade()
  { return exam_1grade; }
int Student::getexam_2grade()
  { return exam_2grade; }



int main() {

  Student student1 = Student("Amy", 95, 90);
  cout << "Name: " << student1.getStudentName() << endl;
  cout << "Exam 1: " << student1.getexam_1grade() << endl;
  cout << "Exam 2: " << student1.getexam_2grade() << endl;
  cout << "GPA: " << student1.getGrade() << endl << endl;

  Student student2 = Student("Bob", 74, 63);
  cout << "Name: " << student2.getStudentName() << endl;
  cout << "Exam 1: " << student2.getexam_1grade() << endl;
  cout << "Exam 2: " << student2.getexam_2grade() << endl;
  cout << "GPA: " << student2.getGrade() << endl << endl;

  Student student3 = Student("Charlie", 86, 80);
  cout << "Name: " << student3.getStudentName() << endl;
  cout << "Exam 1: " << student3.getexam_1grade() << endl;
  cout << "Exam 2: " << student3.getexam_2grade() << endl;
  cout << "GPA: " << student3.getGrade() << endl << endl;

  Student student4 = Student("Daisy", 75, 99);
  cout << "Name: " << student4.getStudentName() << endl;
  cout << "Exam 1: " << student4.getexam_1grade() << endl;
  cout << "Exam 2: " << student4.getexam_2grade() << endl;
  cout << "GPA: " << student4.getGrade() << endl << endl;

  Student student5 = Student("Edward", 24, 66);

  cout << "Name: " << student5.getStudentName() << endl;
  cout << "Exam 1: " << student5.getexam_1grade() << endl;
  cout << "Exam 2: " << student5.getexam_2grade() << endl;
  cout << "GPA: " << student5.getGrade();

return 0;
}
