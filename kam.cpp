#include <iostream>
#include <string>
#include <random>
#include <sstream>
std::random_device rd;
std::ranlux48 rnd { rd() };
std::uniform_int_distribution<> dist1 {15, 25};
std::uniform_int_distribution<> dist2 {1, 3};

int r() {
	int result;
	std::cout <<"������� ������ ��������? ����� ����� �� 1 �� 3!" << std::endl;
	std::string input;
	std::getline(std::cin, input);
	std::stringstream input_ss { input };
	input_ss >> result;
	bool f = input_ss.fail();
	while ( f || result < 1 || result > 3) {//��� ������������ �����
		std::cerr << "����� ������� ����� �� 1 �� 3! �������� ��� ���." <<std::endl;
		std::getline(std::cin, input);
		std::stringstream input_ss { input };
		input_ss >> result;
		f = input_ss.fail();
 }
	return result;
}

int lv1(bool f) {
	int d1 = dist1(rnd);
	std::cout << "� ����  " << d1 << " ������." << std::endl;
	int d2, a;
	bool f1;
	for (unsigned i=0; d1>0; ++i) {
		if( i%2 == 0 ) {
			a = r();
			while (a > d1) {
				std::cerr << "� ���� �������� " << d1 << " ������. ����� ���� ���!" <<std::endl;
				a = r();
 }
			std::cout << "�������� " <<(d1 - a) <<" ������" << std::endl;
			d1 -= a;
			f1 = true;
 }
		else {
			d2 = dist2 (rnd);
			while (d2 > d1) {
				d2 = dist2 (rnd);
			}
			std::cout << "���� ���� - " << d2 << " ������. � ���� ��������: " << (d1-d2) << std::endl;
			d1 -= d2;
			f1 = false;
		}
		if (d1 < 13 and f) return d1;
}
	if(f1) std::cout << "���� ��������, �� ��������." << std::endl;
	else std::cout << "���� ��������, �� �������. ����������!" << std::endl;
	return 1;
}

void lv3(bool f, int ans) {
	int d1 = ans;
	std::cout << "� ���� " << d1 << " ������." << std::endl;
	int d2, a;
	bool f1;
	for (unsigned i=0; d1>0; ++i) {
		if(i%2 == 0)
		{
			a = r(); //����� �����
			while (a > d1)
			{
				std::cerr << "� ���� �������� " << d1 << " ������. ����� ���� ���!";
				a = r();
			}
			std::cout << "�������� " <<(d1 - a) <<" ������ " << std::endl;
			d1 -= a;
			f1 = true;
		}
		else
		{
			if( (d1 - 9) % 4 == 1 or d1 - 9 == -3 or d1 == 2 )
			{
				d1 -= 1;
				std::cout << "���� ���� - 1 ������" << ". ��������: "<< d1 << std::endl;
			}
			else if( (d1 - 9) % 4 == 2 or d1 - 9 == -2 or d1 == 3 )
			{
				d1 -= 2;
				std::cout << "���� ���� - 2 �����" << ". ��������: "<< d1 << std::endl;
			}
			else if( (d1 - 9) % 4 == 3 or d1 - 9 == -1 or d1 == 4 )
			{
				d1 -= 3;
				std::cout << "���� ���� - 3 �����" << ". ��������: "<< d1 << std::endl;
			}
			else
			{
				d2 = dist2 (rnd);
				while (d2 > d1) {
					d2 = dist2 (rnd);
				}
				d1 -= d2;
				std::cout << "�������� ����� - " << d2 << ". ������ ��������: " << d1 <<std::endl;
			}
			f1 = false;
		}
	}
	if(f1) std::cout << "���� ��������, �� ��������. �� �� �������������, �������� ��� ���." << std::endl;
	else std::cout << "���� ��������, �� �������. ����������!" << std::endl;
}

void lv2() {
	bool f = true;
	int ans = lv1(f);
	lv3(f, ans);
}

void pravila() {
	std::cout << "� ���� n-�� ���������� ������. ���������� ��� ������ ������ ���: ����� �� ����� �� 1 �� 3 ������. "
			"���, ��� ������� ��������� - ��������. �� ������� ������ ����. �������� ��� ��������!" << std::endl;
}

int main() {
	int choise;
	bool f = false;
	do
	{
		std::cout << "������ ��������� ������� ����, ����� 4. �� ���� ��� �� ������, �� ������� ������� ���������: " << std::endl
				<< "1. ������" << std::endl
				<< "2. ���������" << std::endl
				<< "3. �������" << std::endl
				<< "4. ������� ����" << std::endl
				<< "5. �� ���� ������. �����." << std::endl;
		std::cin >> choise;
		while (std::cin.fail() or choise < 1 or choise > 5) {
			std::cerr << "�������� ��� ���." << std::endl;
			if (std::cin.fail()) {
				std::cin.clear();
				std::cin.ignore(32767,'\n');
				} // ������: ���� ���������� ����� ���������. ��������� �������� ����������� �����
			std::cin >> choise;
			}
		std::cin.ignore(32767,'\n');
		switch(choise){
		case 1: {lv1(f); break;}
		case 2: {lv2(); break;}
		case 3: {lv3(f, dist1(rnd)); break;}
		case 4: {pravila(); break;}
		}
	}
	while (choise != 5);
	return 0;
}
