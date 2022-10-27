// p2.cpp - F. Rahman
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


  void addStudent(){
  if ( size < CAPACITY){
  Student student{};
  student.setStudentName(StudentName);
  student.setexam_1grade(exam_1grade);
  student.setexam_2grade(exam_2grade);
    }
  }

  void output(){
    int size , CAPACITY;

    if ( size < CAPACITY) {
    cout << student.getStudentName();
    cout << student.getexam_1grade();
    cout << student.getexam_2grade();
      }
    }


int main() {
  const int CAPACITY = 10;
  Student student[CAPACITY];
  int size = 0;

  addStudent(student, size, CAPACITY, "Amy", 90, 85);
  addStudent(student, size, CAPACITY, "Bob", 74, 63);
  addStudent(student, size, CAPACITY, "Charlie", 86, 80);
  addStudent(student, size, CAPACITY, "Daisy", 75, 99);
  addStudent(student, size, CAPACITY, "Edward", 24, 66);
  output(student, size);

  return 0;

}
