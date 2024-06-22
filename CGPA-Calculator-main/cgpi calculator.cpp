#include <bits/stdc++.h>
using namespace std;

class InputGrades  // base class
{
protected:
    string subjects[100];
    int gradePoints[100];  // Changed from string grade to int gradePoints
    string letterGrades[100];  // To store the corresponding letter grades
    int NumofSubjects;
    int cred[100];
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
        cout << "Enter Grade Points obtained (0-10)" << endl;
        cin >> gradePoints[i];
        cout << "Enter Credits for the subjects" << endl;
        cin >> cred[i];

        // Assign corresponding letter grade based on grade points
        if (gradePoints[i] == 10) { letterGrades[i] = "AA"; }
        else if (gradePoints[i] == 9) { letterGrades[i] = "AB"; }
        else if (gradePoints[i] == 8) { letterGrades[i] = "BB"; }
        else if (gradePoints[i] == 7) { letterGrades[i] = "BC"; }
        else if (gradePoints[i] == 6) { letterGrades[i] = "CC"; }
        else if (gradePoints[i] == 5) { letterGrades[i] = "CD"; }
        else { letterGrades[i] = "F"; }  // Assuming any grade point less than 5 is a fail (F)
    }
}

void InputGrades::display()      // Function to display the inputted parameters
{
    cout << setw(12) << left << "Subjects" << setw(22) << left << "||" << setw(15) << left << "Grade Points" << "||" << setw(10) << left << "Credits" << endl;
    cout << "----------------------------------------------------------" << endl;
    for (int i = 0; i < NumofSubjects; i++)
    {
        cout << setw(12) << left << subjects[i] << setw(22) << left << "||" << setw(15) << left << gradePoints[i] << "||" << setw(10) << left << cred[i] << endl;
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

void Cgpi::displaygrades()  // Function to display grades and convert to grade points
{
    cout << setw(12) << left << "Subjects" << setw(22) << left << "||" << setw(18) << left << "Letter Grades" << "||" << setw(15) << left << "Grade Points" << "||" << setw(10) << left << "Credits" << endl;
    cout << "--------------------------------------------------------------------------------" << endl;
    for (int i = 0; i < NumofSubjects; i++)
    {
        cout << setw(12) << left << subjects[i] << setw(22) << left << "||" << setw(18) << left << letterGrades[i] << "||" << setw(15) << left << gradePoints[i] << "||" << setw(10) << left << cred[i] << endl;
    }
    cout << endl;
}

int Cgpi::compute()    // Function to compute total grade points
{
    int totalGradePoints = 0;
    for (int i = 0; i < NumofSubjects; i++)
    {
        totalGradePoints += (gradePoints[i] * cred[i]);
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
