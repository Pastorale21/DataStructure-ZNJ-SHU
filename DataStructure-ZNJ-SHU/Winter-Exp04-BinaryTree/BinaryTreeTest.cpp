#include<iostream>
#include<conio.h>
#include<vector>
#include"solutions/W4_Solutions.h"
#include"../../Tools/Settings.hpp"

namespace Menu
{
    void BinaryTreeTest() {
        char key;
        bool validInput;
        while (true) {
            system("cls");
            std::cout << "��-ʵ���� ��������չ����Ƕ�����\n" << std::endl;
            std::cout << "[1] ������������" << std::endl;
            std::cout << "[2] ��Ƕ�����" << std::endl;
            std::cout << "[3] ������һ���˵�" << std::endl;

            while ((key = _getch()) < '1' && key > '3');

            switch (key) {
            case '1':
            {
                system("cls");
                std::cout << "������������\n" << std::endl;

                W4::Question1();

                system("pause");
                break;
            }
            case '2':
            {
                system("cls");
                std::cout << "��Ƕ�����\n" << std::endl;

                ShowCursor();
                std::cout << "���������������";
                int numOfCases;
                while (true) {
                    std::cin >> numOfCases;
                    validInput = !std::cin.fail() && numOfCases > 0;
                    ClearBuffer();
                    if (validInput) { break; }
                    std::cout << "���������������������������";
                }

                int a, b;
                std::cout << "������������ݣ�" << std::endl;
                for (int i = 0; i < numOfCases; i++) {
                    while (true) {
                        std::cout << "(" << i + 1 << ") ";
                        std::cin >> a >> b;
                        validInput = !std::cin.fail() && a > 0 && b > 0;
                        ClearBuffer();
                        if (validInput) { break; }
                        std::cout << "�����������������룡" << std::endl;
                    }
                    W4::Question2(a, b);
                }
                HideCursor();

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