#include <iostream>

void clear_screen() {
#if defined _WIN32
    system("cls");
#elif defined (__LINUX__) || defined(__gnu_linux__) || defined(__linux__)
    system("clear");
#elif defined (__APPLE__)
    system("clear");
#endif
}

char* to_base_n(int chosenNumber, int base) {

    int tempNumber = chosenNumber;
    int length = 0;
    while (tempNumber > 0) {
        tempNumber /= base;
        length++;
    }

    char* finalNumber = new char[length + 1];
    finalNumber[length] = '\0';

    tempNumber = chosenNumber;
    for (int i = length - 1; i >= 0; i--) {
        const int digit = tempNumber % base;
        tempNumber /= base;
        if (digit < 10)
            finalNumber[i] = '0' + digit;
        else
            finalNumber[i] = 'A' + digit - 10;
    }

    return finalNumber;
}


void menu() {
    setlocale(LC_ALL, "Russian");

    bool isWorking = true;
    while (isWorking) {
        int chosenOption;
        clear_screen();
        std::cout << "����� ���������� � ���� ��������������� 2015\n� ����� ������� ��������� �� ������ ��������� �����?\
           \n1 - ����������������� �������\n2 - ������������ �������\n3 - �� � �����! ����� ����� �� ���������!\n\n��� �������: ";
        std::cin >> chosenOption;
        clear_screen();

        if (std::cin.fail()) {
            std::cout << "��������, � ���� �� ��� �������, � �������� � ���� ������ ����, � �� ���� �����. ����� ��������� ������ �� ����, ������ �� ��������" << std::endl;
            std::cin.clear();
            std::cin.ignore(2, '\n');
            std::cin.get();
            chosenOption = -1;
            continue;
        }


        int x;
        switch (chosenOption) {
        case 1:
            std::cout << "������� �����, ������� ���� �������������: ";
            std::cin >> x;
            std::cout << "���� ����� � ����������������� �������: " << to_base_n(x, 16) << std::endl;
            std::cin.ignore(1, '\n'); std::cin.get();
            break;
        case 2:
            std::cout << "������� �����, ������� ���� �������������: ";
            std::cin >> x;
            std::cout << "���� ����� � ������������ �������: " << to_base_n(x, 8) << std::endl;
            std::cin.ignore(1, '\n'); std::cin.get();
            break;
        case 3:
            std::cout << "�� �����, ����";
            std::cin.ignore(1, '\n'); std::cin.get();
            isWorking = false;
            break;
        default:
            std::cout << "������� �������� ��������, ���������� ��� ���" << std::endl;
            std::cin.ignore(1, '\n'); std::cin.get();

            break;
        }
    }

    return;
}

int main()
{
    

    menu();
}