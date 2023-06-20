#include<iostream>
#include<conio.h>
#include<vector>
#include<set>
#include"solutions/W2_Solutions.h"
#include"solutions/W2_Validation.h"
#include"../../Tools/Settings.hpp"

namespace Menu
{
    void Train() {
        char key;
        bool validInput;
        while (true) {
            system("cls");
            std::cout << "��-ʵ��� �������\n" << std::endl;
            std::cout << "[1] ��һ��\n";
            std::cout << "[2] �ڶ���\n";
            std::cout << "[3] ��һ����㷨��֤\n";
            std::cout << "[4] �ڶ�����㷨��֤\n";
            std::cout << "[5] ������һ���˵�" << std::endl;

            while ((key = _getch()) < '1' && key > '5');

            switch (key) {
            case '1':
            {
                system("cls");
                std::cout << "��һ��\n" << std::endl;

                ShowCursor();
                std::cout << "�����복��������";
                int numOfCars;
                while (true) {
                    std::cin >> numOfCars;
                    validInput = !std::cin.fail() && numOfCars >= 1;
                    ClearBuffer();
                    if (validInput) { break; }
                    std::cout << "�����������������복��������";
                }

                std::cout << "\n������������Ҳ�ĳ���˳��" << std::endl;
                std::vector<int> outputOrder(numOfCars);
                while (true) {
                    std::set<int> checkOrder;
                    for (int i = 0; i < numOfCars; ++i) {
                        std::cin >> outputOrder[i];
                        validInput = !std::cin.fail()
                            && outputOrder[i] >= 1 && outputOrder[i] <= numOfCars
                            && checkOrder.find(outputOrder[i]) == checkOrder.end();
                        if (!validInput) { break; }
                        checkOrder.emplace(outputOrder[i]);
                    }
                    ClearBuffer();
                    if (validInput) { break; }
                    std::cout << "������������������������Ҳ�ĳ���˳��" << std::endl;
                }
                HideCursor();
                std::cout << "\n";

                W2::Question1(outputOrder, numOfCars);

                std::cout << std::endl;
                system("pause");
                break;
            }
            case '2':
            {
                system("cls");
                std::cout << "�ڶ���\n" << std::endl;

                ShowCursor();
                std::cout << "�����복��������";
                int numOfCars;
                while (true) {
                    std::cin >> numOfCars;
                    validInput = !std::cin.fail() && numOfCars >= 1;
                    ClearBuffer();
                    if (validInput) { break; }
                    std::cout << "�����������������복��������";
                }

                std::cout << "\n��������������ĳ���˳��" << std::endl;
                std::vector<int> inputOrder(numOfCars);
                while (true) {
                    std::set<int> checkOrder;
                    for (int i = 0; i < numOfCars; ++i) {
                        std::cin >> inputOrder[i];
                        validInput = !std::cin.fail()
                            && inputOrder[i] >= 1 && inputOrder[i] <= numOfCars
                            && checkOrder.find(inputOrder[i]) == checkOrder.end();
                        if (!validInput) { break; }
                        checkOrder.emplace(inputOrder[i]);
                    }
                    ClearBuffer();
                    if (validInput) { break; }
                    std::cout << "��������������������������ĳ���˳��" << std::endl;
                }
                HideCursor();
                std::cout << "\n";

                W2::Question2(inputOrder, numOfCars);

                std::cout << std::endl;
                system("pause");
                break;
            }
            case '3':
            {
                system("cls");
                std::cout << "��һ����㷨��֤\n" << std::endl;

                ShowCursor();
                std::cout << "�����복��������";
                int numOfCars;
                while (true) {
                    std::cin >> numOfCars;
                    validInput = !std::cin.fail() && numOfCars >= 1;
                    ClearBuffer();
                    if (validInput) { break; }
                    std::cout << "�����������������복��������";
                }
                HideCursor();
                std::cout << "\n";

                W2::Q1_Validation(numOfCars);

                std::cout << std::endl;
                system("pause");
                break;
            }
            case '4':
            {
                system("cls");
                std::cout << "�ڶ�����㷨��֤\n" << std::endl;

                ShowCursor();
                std::cout << "�����복��������";
                int numOfCars;
                while (true) {
                    std::cin >> numOfCars;
                    validInput = !std::cin.fail() && numOfCars >= 1;
                    ClearBuffer();
                    if (validInput) { break; }
                    std::cout << "�����������������복��������";
                }
                HideCursor();
                std::cout << "\n";

                W2::Q2_Validation(numOfCars);

                std::cout << std::endl;
                system("pause");
                break;
            }
            case '5':
            {
                return;
            }
            }
        }
    }
}