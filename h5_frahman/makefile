// p1.cpp - F. Rahman


CXXFLAGS := -std=c++11

prog.exe : driver.o RationalNumber.o
	g++ -std=c++11 -o prog driver.o RationalNumber.o


driver.o : driver.cpp
	g++ -std=c++11 -c driver.cpp
RationalNumber.o : RationalNumber.cpp
	g++ -std=c++11 -c RationalNumber.cpp

clean:
	del driver.o RationalNumber.o
	del prog.exe
