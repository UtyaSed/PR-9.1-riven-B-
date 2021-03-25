// Lab_9_1.cpp
// ������ ³����
// ����������� ������ � 9.1 г���� B
//���������� ����� � ����� ��������
// ������ 7

#include <iostream>
#include <iomanip>
#include <string>
#include <Windows.h>

using namespace std;

enum Specialty { KN, IT, MathAndEconomic, PhysicsandAndIT, TrudoveNavchany };;
string SpecialtyStr[] = { "��������� �����", "�����������", "���������� �� ��������","Գ���� �� �����������","������� ��������" };

struct Student
{
	string prizv;
	int kurs;
	Specialty specialty;
	int Phisic;
	int Math;
	int Prog;
	int Num_Methods;
	int Pedagogy;
	float sb;

};

void Create(Student* p, const int N);
void Print(Student* p, const int N);
int Percentage_Who_Have_5_or_4_In_Physics(Student* p, const int N);
void Print_Students_Prizv_Seredni_Bal_Prog(Student* p, const int N);




int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	int N;
	cout << "������ ������� �������� N: "; cin >> N;

	Student* p = new Student[N];

	Create(p, N);
	Print(p, N);
	cout << endl;
	cout << endl;
	cout << "������� ��������, �� �������� � ������ ������ �5� ��� �4�. = " << Percentage_Who_Have_5_or_4_In_Physics(p, N) << "%" << endl;
	Print_Students_Prizv_Seredni_Bal_Prog(p, N);


	return 0;
}

void Create(Student* p, const int N)
{
	int specialty;
	for (int i = 0; i < N; i++)
	{
		cout << "������� � " << i + 1 << ":" << endl;
		cin.get(); // ������� ����� ��������� � �� ����������� �������
		cin.sync(); // "����� �����", �� �� ����� ������ ��������� ������� �����

		cout << " �������: "; getline(cin, p[i].prizv);
		cout << " ����: "; cin >> p[i].kurs;
		cout << " ������������ (0 - ��������� �����, 1 - �����������, 2 - ���������� �� ��������, 3 - Գ���� �� �����������, 4 - ������� ��������): ";
		cin >> specialty;
		p[i].specialty = (Specialty)specialty;
		cout << " ������ � Գ����: "; cin >> p[i].Phisic;
		cout << " ������ � ����������: "; cin >> p[i].Math;
		switch (p[i].specialty)
		{
		case KN:
			cout << " ������ � �������������: "; cin >> p[i].Prog;
			break;
		case IT:
			cout << " ������ � ��������� ������: "; cin >> p[i].Num_Methods;
			break;
		case MathAndEconomic:
		case PhysicsandAndIT:
		case TrudoveNavchany:
			cout << " ������ � ���������: "; cin >> p[i].Pedagogy;
			break;
		}
		cout << endl;
	}
}
void Print(Student* p, const int N)
{
	cout << "============================================================================================================================================================================"
		<< endl;
	cout << "                                                                     ������ ��������" << endl;

	cout << "============================================================================================================================================================================"
		<< endl;
	cout << "|  � |   �������   | ���� |      ������������      | ������ � Գ���� | ������ � ���������� | ������ � ������������� | ������ � ��������� ������  | ������ � ��������� | "
		<< endl;
	cout << "----------------------------------------------------------------------------------------------------------------------------------------------------------------------------"
		<< endl;
	for (int i = 0; i < N; i++)
	{
		cout << "| " << setw(2) << right << i + 1 << " ";
		cout << "| " << setw(13) << left << p[i].prizv
			<< "| " << setw(4) << right << p[i].kurs << " "
			<< "| " << setw(23) << left << SpecialtyStr[p[i].specialty] << " "
			<< "| " << setw(15) << right << p[i].Phisic << " "
			<< "| " << setw(19) << right << p[i].Math << " ";
		switch (p[i].specialty)
		{
		case KN:
			cout << "| " << setw(22) << right << p[i].Prog << " |" << setw(30) << "|" << setw(22) << "  |" << endl;
			break;
		case IT:
			cout << "| " << setw(24) << " |" << setw(29) << right << p[i].Num_Methods << "|" << setw(22) << " |" << endl;
			break;
		case MathAndEconomic:
		case PhysicsandAndIT:
		case TrudoveNavchany:
			cout << "| " << setw(24) << " |" << setw(30) << "|" << setw(21) << right << p[i].Pedagogy << "|" << endl;
			break;
		}

	}
	cout << "============================================================================================================================================================================="
		<< endl;
	cout << endl;
}
int Percentage_Who_Have_5_or_4_In_Physics(Student* p, const int N)
{
	double F_of_F = 0;

	for (int i = 0; i < N; i++)
	{
		if (p[i].Phisic == 4 || p[i].Phisic == 5)
			F_of_F += 1;

	}

	F_of_F = (F_of_F / N) * 100;

	return F_of_F;
}

void Print_Students_Prizv_Seredni_Bal_Prog(Student* p, const int N)
{
	int � = 0;
	cout << "������� ��������, ������� ���: " << endl;

	for (int i = 0; i < N; i++)
	{
		{
			if (p[i].sb = ((p[i].Phisic + p[i].Math + p[i].specialty) / 3.0));

		}
			cout << ++� << "." << p[i].prizv << " , " << " ������� ��� = " << p[i].sb << endl;
	}
}