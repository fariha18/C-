// p1.cpp - F. Rahman
#include <iostream>
#include <iomanip>
using namespace std;


class Student{

public:
  Student() : Student("  ", "  ", 0.0) { }
  Student(string n, string m, double gpa) : name(n), major(m), grade(gpa) { }

  void setName(string name) { }
  string getName( ) const  {return name;}

  void setMajor(string major) { }
  string getMajor( ) const {return major;}

  void setGrade(double gpa) {grade.setGPAlet(gpa);}
  double  getGrade() const {return grade.getGPAlet();}

  void display( ) const{
            cout<<"Name : " << name << endl;
            cout<<"Major : " << major << endl;
            cout<<"GPA : " << grade.getGPAlet() << endl;
            cout<<"Grade : " << grade.getLetterGrade() << endl;
  }
private:
    class GPA {
    public:
      GPA( ) : gpa(0.0) { }
      GPA(double g) : gpa(g) { }

      void setGPAlet(double g)  { g = gpa;}
      double getGPAlet( ) const { return gpa; }
      char getLetterGrade( ) const
          {
              if(gpa >= 3.5)
              return 'A';
              else if(gpa >= 2.5)
              return 'B';
              else if(gpa >= 1.5)
              return 'C';
              else if(gpa >= 1)
              return 'D';
              else
              return 'F';
            }

private:
    double gpa;
};
    string name;
    string major;
    GPA grade;
};

int main( ) {

  Student student{};

  Student student1{"John Williams", "Music", 4.00};
  student1.display( );
  cout << endl;

  Student student2{"Isaac Asimov", "English", 3.33};
  student2.display( );


        return 0;
}
