#include <bits/stdc++.h>
using namespace std;

class InputGrades  // base class
{
protected:
    string subjects[100];
    string grade[100];
    int NumofSubjects;
    int cred[100];
    int marks[100];
public:
    void input();
    void display();
};

void InputGrades::input()        // Function to input number of subjects, grades, and credits
{
    cout << "Enter Number of Subjects" << endl;
    cin >> NumofSubjects;
    cout << endl;
    for (int i = 0; i < NumofSubjects; i++)
    {
        cout << "Enter subject Name" << endl;
        cin >> subjects[i];
        cout << "Enter Grades obtained" << endl;
        cin >> grade[i];
        cout << "Enter Credits for the subjects" << endl;
        cin >> cred[i];
    }
}

void InputGrades::display()      // Function to display the inputted parameters
{
    cout << setw(8) << "Subjects" << setw(10) << "||" << setw(8) << "Grades" << "    " << setw(7) << "||" << setw(9) << "Credits" << endl;
    cout << "------------------------------------------------------------------------------";
    cout << endl;
    for (int i = 0; i < NumofSubjects; i++)
    {
        cout << setw(8) << subjects[i] << "        " << "||" << " " << setw(8) << grade[i] << "        " << setw(3) << "|| " << setw(8) << cred[i];
        cout << endl;
    }
    cout << endl;
}

class Cgpi : public InputGrades   // derived class
{
public:
    void displaygrades();
    int compute();
    void pointerPercentage();
};

void Cgpi::displaygrades()  // Function to convert inputted grades to marks
{
    cout << setw(8) << "Subjects" << setw(10) << "||" << setw(8) << "Grades" << setw(11) << "||" << setw(8) << "Marks" << setw(7) << "||" << setw(8) << "Credits" << endl;
    cout << "-----------------------------------------------------------------------------------";
    cout << endl;
    for (int i = 0; i < NumofSubjects; i++)
    {
        if (grade[i] == "AA") { marks[i] = 10; }
        else if (grade[i] == "AB") { marks[i] = 9; }
        else if (grade[i] == "BB") { marks[i] = 8; }
        else if (grade[i] == "BC") { marks[i] = 7; }
        else if (grade[i] == "CC") { marks[i] = 6; }
        else if (grade[i] == "CD") { marks[i] = 5; }
        else
        {
            // Check if the grade is numeric
            try {
                int num_grade = stoi(grade[i]);
                if (num_grade >= 0 && num_grade <= 10) {
                    marks[i] = num_grade;
                }
                else {
                    marks[i] = 0;
                }
            }
            catch (invalid_argument&) {
                marks[i] = 0;
            }
        }

        cout << setw(8) << subjects[i] << "        " << "||" << " " << setw(8) << grade[i] << "        " << "||" << setw(8) << marks[i] << "     " << "|| " << setw(8) << cred[i] << endl;
    }
}

int Cgpi::compute()    // Function to compute total grade points
{
    int totalGradePoints = 0;
    for (int i = 0; i < NumofSubjects; i++)
    {
        totalGradePoints += (marks[i] * cred[i]);
    }
    return totalGradePoints;
}

void Cgpi::pointerPercentage()  // Function to convert sum to pointer and percentage
{
    int tot = 0;
    for (int i = 0; i < NumofSubjects; i++)
    {
        tot += cred[i];
    }
    double cgpi = (double)compute() / tot;
    cout << setprecision(3);
    cout << endl;
    cout << "The pointer computed is: " << cgpi << endl;
    cout << "The computed percentage is: " << (10.00 * cgpi) - 7.50 << endl;
}

int main()   // main function
{
    Cgpi c;   // object creation of derived class
    c.input();
    c.display();
    c.displaygrades();
    c.pointerPercentage();
    return 0;
}
