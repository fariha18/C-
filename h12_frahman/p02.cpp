// p2.cpp - F. Rahman
using namespace std;
#include <iostream>
#include <string>
#include <iomanip>

class Student{

public:
void setStudentName(string name);
string getStudentName() const;

void setexam_1(double grade);
int getexam_1() const;

void setexam_2(double grade);
int getexam_2() const;

char getGrade() const;

private:
double calcGPA();
string StudentName;
int exam_1grade;
int exam_2grade;

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

double Student::calcGPA() {}
char Student::getGrade() {

  double Student = calcGPA() const {
    return ((exam_1grade + exam_2grade)/2.0)
 }

 char Student :: getGrade() const {

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


void addStudent(){
int size , CAPACITY;

if ( size < CAPACITY){
Student s{};
s.setStudentName(StudentName);
s.setexam_1grade(exam_1grade);
s.setexam_2grade(exam_2grade);
  }
}

void output(){
cout << s.getStudentName();
cout << s.getexam_1grade();
cout << s.getexam_2grade();

}


//void addStudent(Student students[], int size, string name, double exam_1, double exam_2);
//void output(Student students[], int size);

int main(){
const int CAPACITY = 10;
Student students[CAPACITY];
int size = 0;

addStudent(students, size, CAPACITY, "Amy", 90, 85);
addStudent(students, size, CAPACITY, "Bob", 74, 63);
addStudent(students, size, CAPACITY, "Charlie", 86, 80);
addStudent(students, size, CAPACITY, "Daisy", 75, 99);
addStudent(students, size, CAPACITY, "Edward", 24, 66);
output(students, size);

return 0;
}
