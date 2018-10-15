#include <stdio.h>
#include <iostream>
using namespace std;

struct StudentRecord
{
	int studentid;
	double quizscore1, quizscore2;
	double midexamscore, finalexamscore;
	double totalscore;
	char studentgrade;
}studentrecord;

void computeGrade(StudentRecord& student);
//Precondition: 구조체의 학생의 퀴즈성적, 중간성적, 기말성적을 받아 비율에 맞게 계산한다.
//Postcondition: 계산된 성적을 student.score에 성적을 바탕으로 만들어진 등급을 student.grade에 저장한다.
void input(StudentRecord &student);
//Precondition: 구조체에서 변수 값을 받아온다.
//Postcondition: student.id, student.quizscore1,2, student.midexamscore,student.finalexamscore에 값을 저장한다.
void output(const StudentRecord student);
//Precondition: 구조체에서 변수 값을 받아온다.
//Postcondition: 값을 출력해서 보여준다.
int main()
{
	char ans;
	do
	{
		StudentRecord studentrecord;
		input(studentrecord);
		computeGrade(studentrecord);
		output(studentrecord);
		cout << "Try Agian? Y/y continues, other quits.";
		cin >> ans;
	} while (ans == 'Y' || ans == 'y');
	cout << "Bye" << endl;
	
}

void computeGrade(StudentRecord & student)
{
	
	student.totalscore = (student.quizscore1 + student.quizscore2)*5 *0.25;
	
	student.totalscore += (student.midexamscore * 0.25);
	
	student.totalscore += (student.finalexamscore*0.5);
	
	if (student.totalscore >= 90)
	{
		student.studentgrade = 'A';
	}
	else if (student.totalscore >= 80)
	{
		student.studentgrade = 'B';
	}
	else if (student.totalscore >= 70)
	{
		student.studentgrade = 'C';
	}
	else if (student.totalscore >= 60)
	{
		student.studentgrade = 'D';
	}
	else if (student.totalscore >= 0)
	{
		student.studentgrade = 'F';
	}
	

}

void input(StudentRecord & student)
{
	cout << "Enter the student number : ";
	cin >> student.studentid;
	cout << "Enter two 10 point quizes"<< endl;
	cin >> student.quizscore1;
	cin >> student.quizscore2;
	cout << "Enter the midterm and final exam grades, These are 100 point tests." << endl;
	cin >> student.midexamscore;
	cin >> student.finalexamscore;
}

void output(const StudentRecord student)
{
	cout << "The record for student number: " << student.studentid << endl;
	cout << "The quiz grades are : " << student.quizscore1 << " " << student.quizscore2 << endl;
	cout << "The midterm and exam grades are: " << student.midexamscore <<" " << student.finalexamscore<< endl;
	cout << "The numeric average is: " << student.totalscore << endl;
	cout << "and the letter grade assigned is " << student.studentgrade << endl;

}
