#include<iostream>
#include<string>
#include<vector>
#include<unordered_set>
#include<conio.h>
#include"solutions/S3_Solutions.h"
#include"../../tools/Random.hpp"
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
            std::cout << "[4] ������һ���˵�" << std::endl;

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
                HideCursor();
                std::vector<int> vec1, vec2;

                std::cout << "[1] ��������" << "\n";
                std::cout << "[2] Ч�ʶԱ�" << "\n" << std::endl;
                while ((key = _getch()) < '1' && key > '2');

                if (key == '1') {
                    ShowCursor();
                    int temp;
                    std::cout << "�������һ�������Ԫ��:" << std::endl;
                    while (true) {
                        for (int i = 0; i < m; i++) {
                            std::cin >> temp;
                            validInput = !std::cin.fail() && (i == 0 || vec1[i - 1] <= temp);
                            if (!validInput) { break; }
                            vec1.push_back(temp);
                        }
                        ClearBuffer();
                        if (validInput) { break; }
                        std::cout << "�������������������һ�������Ԫ��:" << std::endl;
                    }
                    std::cout << "������ڶ��������Ԫ��: " << std::endl;
                    while (true) {
                        for (int i = 0; i < n; i++) {
                            std::cin >> temp;
                            validInput = !std::cin.fail() && (i == 0 || vec2[i - 1] <= temp);
                            if (!validInput) { break; }
                            vec2.push_back(temp);
                        }
                        ClearBuffer();
                        if (validInput) { break; }
                        std::cout << "������������������ڶ��������Ԫ��:" << std::endl;
                    }
                    HideCursor();
                } else {
                    std::cout << "�������ɵ�һ�����顭��\n";
                    vec1 = Rand_Uniform<int>().generateVec(m, -1000000, 10000000);
                    std::ranges::sort(vec1);
                    std::cout << "�������ɵڶ������顭��" << std::endl;
                    vec2 = Rand_Normal<int>().generateVec(n, 0, 500000);
                    std::ranges::sort(vec2);
                }

                std::cout << "\n���Բ����㷨" << std::endl;
                clock_t start = clock();
                S3::FindMedian_Linear(vec1, vec2);
                clock_t end = clock();
                if (key == '2') {
                    std::cout << "��ʱ" << end - start << "ms" << std::endl;
                }

                std::cout << "\n���ֲ����㷨" << std::endl;
                start = clock();
                S3::FindMedian_Binary(vec1, vec2);
                end = clock();
                if (key == '2') {
                    std::cout << "��ʱ" << end - start << "ms" << std::endl;
                }

                std::cout << std::endl;
                system("pause");
                break;
            }
            case '3':
            {
                std::cout << "\n����������\n";
                std::cout << "[1] ��������\n";
                std::cout << "[2] Ч�ʶԱ�\n" << std::endl;

                while ((key = _getch()) < '1' && key > '2');

                system("cls");
                if (key == '1') {
                    S3::BST_Test();
                } else {
                    S3::BST_EfficiencyTest();
                    system("pause");
                }
                break;
            }
            case '4':
            {
                return;
            }
            }
        }
    }
}