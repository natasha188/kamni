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
	std::cout <<"Сколько камней возьмешь? Можно брать от 1 до 3!" << std::endl;
	std::string input;
	std::getline(std::cin, input);
	std::stringstream input_ss { input };
	input_ss >> result;
	bool f = input_ss.fail();
	while ( f || result < 1 || result > 3) {//для некоректного ввода
		std::cerr << "Нужно вводить число от 1 до 3! Попробуй ещё раз." <<std::endl;
		std::getline(std::cin, input);
		std::stringstream input_ss { input };
		input_ss >> result;
		f = input_ss.fail();
 }
	return result;
}

int lv1(bool f) {
	int d1 = dist1(rnd);
	std::cout << "В куче  " << d1 << " камней." << std::endl;
	int d2, a;
	bool f1;
	for (unsigned i=0; d1>0; ++i) {
		if( i%2 == 0 ) {
			a = r();
			while (a > d1) {
				std::cerr << "В куче осталось " << d1 << " камней. Делай свой ход!" <<std::endl;
				a = r();
 }
			std::cout << "Осталось " <<(d1 - a) <<" камней" << std::endl;
			d1 -= a;
			f1 = true;
 }
		else {
			d2 = dist2 (rnd);
			while (d2 > d1) {
				d2 = dist2 (rnd);
			}
			std::cout << "Вася взял - " << d2 << " камней. В куче осталось: " << (d1-d2) << std::endl;
			d1 -= d2;
			f1 = false;
		}
		if (d1 < 13 and f) return d1;
}
	if(f1) std::cout << "Игра окончена, ты проиграл." << std::endl;
	else std::cout << "Игра окончена, ты победил. Поздравляю!" << std::endl;
	return 1;
}

void lv3(bool f, int ans) {
	int d1 = ans;
	std::cout << "В куче " << d1 << " камней." << std::endl;
	int d2, a;
	bool f1;
	for (unsigned i=0; d1>0; ++i) {
		if(i%2 == 0)
		{
			a = r(); //берет игрок
			while (a > d1)
			{
				std::cerr << "В куче осталось " << d1 << " камней. Делай свой ход!";
				a = r();
			}
			std::cout << "Осталось " <<(d1 - a) <<" камней " << std::endl;
			d1 -= a;
			f1 = true;
		}
		else
		{
			if( (d1 - 9) % 4 == 1 or d1 - 9 == -3 or d1 == 2 )
			{
				d1 -= 1;
				std::cout << "Вася взял - 1 камень" << ". Осталось: "<< d1 << std::endl;
			}
			else if( (d1 - 9) % 4 == 2 or d1 - 9 == -2 or d1 == 3 )
			{
				d1 -= 2;
				std::cout << "Вася взял - 2 камня" << ". Осталось: "<< d1 << std::endl;
			}
			else if( (d1 - 9) % 4 == 3 or d1 - 9 == -1 or d1 == 4 )
			{
				d1 -= 3;
				std::cout << "Вася взял - 3 камня" << ". Осталось: "<< d1 << std::endl;
			}
			else
			{
				d2 = dist2 (rnd);
				while (d2 > d1) {
					d2 = dist2 (rnd);
				}
				d1 -= d2;
				std::cout << "Рандомно взяли - " << d2 << ". Камней осталось: " << d1 <<std::endl;
			}
			f1 = false;
		}
	}
	if(f1) std::cout << "Игра окончена, ты проиграл. Но не расстаривайся, попробуй ещё раз." << std::endl;
	else std::cout << "Игра окончена, ты победил. Поздравляю!" << std::endl;
}

void lv2() {
	bool f = true;
	int ans = lv1(f);
	lv3(f, ans);
}

void pravila() {
	std::cout << "В куче n-ое количество камней. Поочередно два игрока делают ход: берут из кучки от 1 до 3 камней. "
			"Тот, кто возьмет последний - проиграл. Ты играешь против Васи. Попробуй его выиграть!" << std::endl;
}

int main() {
	int choise;
	bool f = false;
	do
	{
		std::cout << "Можешь прочитать правила игры, нажав 4. Но если уже их знаешь, то выбирай уровень сложности: " << std::endl
				<< "1. Легкий" << std::endl
				<< "2. Среднячок" << std::endl
				<< "3. Сложный" << std::endl
				<< "4. Правила игры" << std::endl
				<< "5. Не хочу играть. Выйти." << std::endl;
		std::cin >> choise;
		while (std::cin.fail() or choise < 1 or choise > 5) {
			std::cerr << "Попробуй ещё раз." << std::endl;
			if (std::cin.fail()) {
				std::cin.clear();
				std::cin.ignore(32767,'\n');
				} // защита: если извлечение будет неудачным. удаляется значение предыдущего вводы
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
