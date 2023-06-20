#include<iostream>
#include<conio.h>
#include"solutions/W1_Solutions.h"
#include"../../Tools/Settings.hpp"

namespace Menu
{
    void InterviewArrangement() {
        char key;
        bool validInput;
        while (true) {
            system("cls");
            std::cout << "��-ʵ��һ ���԰���\n" << std::endl;

            std::cout << "[1] ��һ��\n";
            std::cout << "[2] �ڶ���\n";
            std::cout << "[3] ������һ���˵�" << std::endl;

            while ((key = _getch()) < '1' && key > '3');

            switch (key) {
            case '1':
            {
                system("cls");
                std::cout << "��һ��\n" << std::endl;

                ShowCursor();
                std::cout << "������N��K��M��ֵ��";
                int N, K, M;
                while (true) {
                    std::cin >> N >> K >> M;
                    validInput = !std::cin.fail() && N >= 0 && K > 0 && M > 0;
                    ClearBuffer();
                    if (validInput) { break; }
                    std::cout << "������������������N��K��M��ֵ��";
                }
                HideCursor();

                W1::Question1(N, K, M);

                std::cout << std::endl;
                system("pause");
                break;
            }
            case '2':
            {
                system("cls");
                std::cout << "�ڶ���\n" << std::endl;

                ShowCursor();
                std::cout << "������N��K��M��ֵ��";
                int N, K, M;
                while (true) {
                    std::cin >> N >> K >> M;
                    validInput = !std::cin.fail() && N >= 0 && K > 0 && M > 0;
                    ClearBuffer();
                    if (validInput) { break; }
                    std::cout << "������������������N��K��M��ֵ��";
                }
                HideCursor();

                W1::Question2(N, K, M);

                std::cout << std::endl;
                system("pause");
                break;
            }
            case '3':
            {
                return;
            }
            }
        }
    }
}