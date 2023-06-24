#include<iostream>
#include<string>
#include<vector>
#include<conio.h>
#include"solutions/S3_Solutions.h"
#include"solutions/S3_EfficiencyTest.h"
#include"../Tools/Settings.hpp"

namespace Menu
{
    void Search()
    {
        char key;
        bool validInput;
        while (true) {
            system("cls");
            std::cout << "��-ʵ���� �����㷨��֤�����\n" << std::endl;

            std::cout << "[1] ���������������С��ͬԪ��\n";
            std::cout << "[2] �����������������λ��\n";
            std::cout << "[3] ����������\n";
            std::cout << "[4] �ڶ���Ч�ʶԱ�\n";
            std::cout << "[5] ������һ���˵�" << std::endl;

            while ((key = _getch()) < '1' && key > '5');

            switch (key) {
            case '1':
            {
                system("cls");
                std::cout << "���������������С��ͬԪ��\n" << std::endl;

                ShowCursor();
                std::cout << "��������������Ĵ�С: ";
                int aSize, bSize, cSize;
                while (true) {
                    std::cin >> aSize >> bSize >> cSize;
                    validInput = aSize > 0 && bSize > 0 && cSize > 0;
                    ClearBuffer();
                    if (validInput) { break; }
                    std::cout << "��������������������������Ĵ�С: ";
                }

                std::vector<int> a(aSize), b(bSize), c(cSize);
                std::cout << "�������һ�������Ԫ�أ�" << std::endl;
                while (true) {
                    for (auto& e : a) {
                        std::cin >> e;
                        validInput = !std::cin.fail();
                        if (!validInput) { break; }
                    }
                    ClearBuffer();
                    if (validInput) { break; }
                    std::cout << "�������������������һ�������Ԫ�أ�" << std::endl;
                }

                std::cout << "������ڶ��������Ԫ�أ�" << std::endl;
                while (true) {
                    for (auto& e : b) {
                        std::cin >> e;
                        validInput = !std::cin.fail();
                        if (!validInput) { break; }
                    }
                    ClearBuffer();
                    if (validInput) { break; }
                    std::cout << "������������������ڶ��������Ԫ�أ�" << std::endl;
                }

                std::cout << "����������������Ԫ�أ�" << std::endl;
                while (true) {
                    for (auto& e : c) {
                        std::cin >> e;
                        validInput = !std::cin.fail();
                        if (!validInput) { break; }
                    }
                    ClearBuffer();
                    if (validInput) { break; }
                    std::cout << "����������������������������Ԫ�أ�" << std::endl;
                }
                HideCursor();
                std::cout << std::endl;

                S3::FindMinCommonElement(a, b, c);

                std::cout << std::endl;
                system("pause");
                break;
            }
            case '2':
            {
                system("cls");
                std::cout << "�����������������λ��\n" << std::endl;

                ShowCursor();
                std::cout << "��ֱ�������������ĳ��ȣ�2��������";
                int m = -1, n = -1;
                while (true) {
                    std::cin >> m >> n;
                    validInput = !std::cin.fail() && m > 0 && n > 0;
                    ClearBuffer();
                    if (validInput) { break; }
                    std::cout << "��������������������������ĳ��ȣ�2������: ";
                }

                std::vector<int> vec1(m), vec2(n);
                std::cout << "�������һ�������Ԫ��:" << std::endl;
                while (true) {
                    for (int i = 0; i < m; i++) {
                        std::cin >> vec1[i];
                        validInput = !std::cin.fail() && (i == 0 || vec1[i - 1] <= vec1[i]);
                        if (!validInput) { break; }
                    }
                    ClearBuffer();
                    if (validInput) { break; }
                    std::cout << "�������������������һ�������Ԫ��:" << std::endl;
                }
                std::cout << "������ڶ��������Ԫ��: " << std::endl;
                while (true) {
                    for (int i = 0; i < n; i++) {
                        std::cin >> vec2[i];
                        validInput = !std::cin.fail() && (i == 0 || vec2[i - 1] <= vec2[i]);
                        if (!validInput) { break; }
                    }
                    ClearBuffer();
                    if (validInput) { break; }
                    std::cout << "������������������ڶ��������Ԫ��:" << std::endl;
                }
                HideCursor();

                std::cout << "\n���Բ��ң�" << std::endl;
                S3::FindMedian_Linear(vec1, vec2);
                std::cout << "\n���ֲ��ң�" << std::endl;
                S3::FindMedian_Binary(vec1, vec2);

                std::cout << std::endl;
                system("pause");
                break;
            }
            case '3':
            {
                system("cls");
                ShowCursor();
                HideCursor();

                system("pause");
                break;
            }
            case '4':
            {
                system("cls");
                std::cout << "�ڶ���Ч�ʶԱ�\n" << std::endl;

                ShowCursor();
                std::cout << "��ֱ�������������ĳ��ȣ�2��������";
                size_t m = 0, n = 0;
                while (true) {
                    std::cin >> m >> n;
                    validInput = !std::cin.fail() && m > 0 && n > 0;
                    ClearBuffer();
                    if (validInput) { break; }
                    std::cout << "��������������������������ĳ��ȣ�2������: ";
                }
                HideCursor();

                S3::Q2_EfficiencyTest<int>(m, n);

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