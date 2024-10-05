#include <iostream>

bool hypotesisChecker(int value) {
	setlocale(LC_ALL, "Russian");
	int number = value;
	while (number > 1) {
		if (number % 2 == 0) {
			std::cout << number << " - ������ �����. ����� �� 2" << std::endl;
			number = number / 2;
		}
		else {
			std::cout << number << " - �������� �����. �������� �� 3, ���������� ������� � ����� �� 2" << std::endl;
			number = (number * 3 + 1) / 2;
		}
	}

	std::cout << "�������� �����: " << number << std::endl;

	if (number == 1) {
		std::cout << "�������� �������� �������� ��� ����� " << value;
	}
	else {
		std::cout << "�������� �������� �� �������� ��� ����� " << value;
	}

	return number == 1;
}

void clear_screen() {
#if defined _WIN32
	system("cls");
#elif defined (__LINUX__) || defined(__gnu_linux__) || defined(__linux__)
	system("clear");
#elif defined (__APPLE__)
	system("clear");
#endif
}

int main() {
	setlocale(LC_ALL, "Russian");

	bool isWorking = true;


	while (isWorking) {
		std::cout << "��������� �������� �������� ��������" << std::endl;
		std::cout << "������� ����� ����������� �����, ������� ������ ��������� �� ������������ ��������: ";

		int chosenNumber;
		std::cin >> chosenNumber;

		if (std::cin.fail()) {
			std::cout << "������, ������� �������� �������� ��� ������������ �����" << std::endl;
			std::cout << "������� enter, ����� ����������";
			std::cin.clear();
			std::cin.ignore(2, '\n');
			std::cin.get();
			clear_screen();
			continue;
		}

		if (chosenNumber < 1) {
			std::cout << "������, ����� �� �����������. ���������� �����." << std::endl;
			std::cin.ignore(100, '\n');
			std::cout << "������� enter, ����� ����������";
			std::cin.get();
			clear_screen();
		}
		else {
			hypotesisChecker(chosenNumber);
			isWorking = false;
			std::cin.get();
		}
	}

}
