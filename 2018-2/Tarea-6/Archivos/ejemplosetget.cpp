// Class automatically generated by Dev-C++ New Class wizard
#include <cstdlib>
#include <iostream>
#include <string>
#include "termpaper.h" 

using namespace std;


TermPaper::TermPaper()
{
fName = "";
lName = "";
subject = "";
letterGrade = 'F';            
	
}
void TermPaper::setFname(string fN)
{
   fName = fN;
}
void TermPaper::setLName(string lN)
{
  lName = lN;
}
void TermPaper::setSubject(string sub)
{
  subject = sub;
}
void TermPaper::setLetterGrade(char grade)
{
  letterGrade = grade;
}
string  TermPaper::getFname( )
{
  return fName;
}
string TermPaper::getLname( )
{
  return lName;
}
string TermPaper::getSubject( )
{
  return subject;
}
char TermPaper::getLetterGrade( )
{
  return letterGrade;
}