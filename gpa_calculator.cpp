#include <iostream>
using namespace std;
#define SIZE 3
#define CH 2

struct grades
{
	float modules[SIZE];
	int weights[SIZE];
	float GPA;
};

void get(grades students[])
{
	cout << "Please enter " << SIZE << " students data of " << SIZE << " modules:\n";
	for (int i = 0; i < SIZE; i++)
	{
		cout << "Student #" << i + 1 << endl;
		for (int j = 0; j < SIZE; j++)
		{
			cout << "Module #" << j + 1 << ": ";
			cin >> students[i].modules[j];
		}
	}
}

void calcWeight(grades students[])
{
	for (int i = 0; i < SIZE; i++)
	{
		for (int j = 0; j < SIZE; j++)
		{
			if (students[i].modules[j] > 79)
				students[i].weights[j] = 4;
			else
				if (students[i].modules[j] > 69)
					students[i].weights[j] = 3;
				else
					if (students[i].modules[j] > 59)
						students[i].weights[j] = 2;
					else
						if (students[i].modules[j] > 39)
							students[i].weights[j] = 1;
						else
							students[i].weights[j] = 0;
		}
	}
}

void calcGPA(grades students[])
{
	for (int i = 0; i < SIZE; i++)
	{
		float gpa = 0;
		for (int j = 0; j < SIZE; j++)
		{
			gpa += students[i].weights[j]*CH;
		}
		students[i].GPA = gpa / (CH * SIZE);
	}
}

void display(grades students[])
{
	cout << "Students' GPAs:\n";
	for (int i = 0; i < SIZE; i++)
		cout << "GPA of student #" << i + 1 << ": " << students[i].GPA<< endl;
}

void main()
{
	grades students[SIZE];
	get(students);
	calcWeight(students);
	calcGPA(students);
	display(students);
}
