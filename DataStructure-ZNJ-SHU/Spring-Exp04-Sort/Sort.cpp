#include<iostream>
#include<conio.h>
#include<vector>
#include<algorithm>
#include<ranges>
#include"solutions/S4_QuickSort.h"
#include"solutions/S4_DNASort.h"
#include"../Tools/Random.hpp"
#include"../Tools/Settings.hpp"

namespace Menu
{
    void Sort()
    {
        char key;
        bool validInput;
        while (true) {
            system("cls");
            std::cout << "��-ʵ���� �����㷨��֤�����\n" << std::endl;

            std::cout << "[1] ��������Ľ�\n";
            std::cout << "[2] DNA����\n";
            std::cout << "[3] ������һ���˵�" << std::endl;

            while ((key = _getch()) < '1' && key > '3');

            switch (key) {
            case '1':
            {
                system("cls");
                std::cout << "��������Ľ�\n" << std::endl;

                ShowCursor();
                std::cout << "����������Ĵ�С��";
                int size;
                while (true) {
                    std::cin >> size;
                    validInput = !std::cin.fail() && size > 0;
                    ClearBuffer();
                    if (validInput) { break; }
                    std::cout << "����������������������Ĵ�С��";
                }
                HideCursor();
                std::vector<int> vec(size);

                std::cout << "[1] ��������\n";
                std::cout << "[2] Ч�ʶԱ�\n" << std::endl;
                while ((key = _getch()) < '1' && key > '2');

                if (key == '1') {
                    ShowCursor();
                    std::cout << "����������Ԫ�أ�" << std::endl;
                    while (true) {
                        for (int i = 0; i < size; i++) {
                            std::cin >> vec[i];
                            validInput = !std::cin.fail();
                            if (!validInput) { break; }
                        }
                        ClearBuffer();
                        if (validInput) { break; }
                        std::cout << "����������������������Ԫ�أ�" << std::endl;
                    }
                    HideCursor();
                } else {
                    std::cout << "������������Ԫ�ء���" << std::endl;
                    vec = Rand_Uniform<int>().generateVec(size, -20000, 20000);
                }

                std::cout << "\nstd::sort" << std::endl;
                std::vector<int> vec1(vec);
                clock_t start = clock();
                std::ranges::sort(vec1);
                clock_t end = clock();
                if (key == '1') {
                    for (const auto& e : vec1) {
                        std::cout << e << " ";
                    }
                    std::cout << std::endl;
                } else {
                    std::cout << "��ʱ: " << end - start << "ms" << std::endl;
                }

                std::cout << "\nQuickSort\n";
                std::vector<int> vec2(vec);
                start = clock();
                S4::QuickSort(vec2, 0, vec2.size() - 1);
                end = clock();
                if (key == '1') {
                    for (const auto& e : vec2) {
                        std::cout << e << " ";
                    }
                    std::cout << std::endl;
                } else {
                    std::cout << "��ʱ: " << end - start << "ms" << std::endl;
                }
                if (vec1 == vec2) {
                    std::cout << "������ȷ" << std::endl;
                } else {
                    std::cout << "�������" << std::endl;
                }

                std::cout << "\nQuickSort_MedianOfThree\n";
                std::vector<int> vec3(vec);
                start = clock();
                S4::QuickSort(vec3, 0, vec3.size() - 1);
                end = clock();
                if (key == '1') {
                    for (const auto& e : vec3) {
                        std::cout << e << " ";
                    }
                    std::cout << std::endl;
                } else {
                    std::cout << "��ʱ: " << end - start << "ms" << std::endl;
                }
                if (vec1 == vec3) {
                    std::cout << "������ȷ" << std::endl;
                } else {
                    std::cout << "�������" << std::endl;
                }

                system("pause");
                break;
            }
            case '2':
            {
                system("cls");
                std::cout << "DNA����\n" << std::endl;

                ShowCursor();
                std::cout << "������DNA�ַ�������Ŀn�볤��m��";
                int n, m;
                while (true) {
                    std::cin >> n >> m;
                    validInput = !std::cin.fail() && n > 0 && m > 0;
                    ClearBuffer();
                    if (validInput) { break; }
                    std::cout << "������������������DNA�ַ�������Ŀn�볤��m��";
                }

                std::cout << "������DNA�ַ���" << std::endl;
                std::vector<std::string> dnaVec(n);
                for (int i = 0; i < n; i++) {
                    while (true) {
                        std::cout << "(" << i + 1 << ") ";
                        std::cin >> dnaVec[i];
                        if (dnaVec[i].size() == m) {
                            validInput = true;
                            for (char c : dnaVec[i]) {
                                if (c != 'A' && c != 'C' && c != 'G' && c != 'T') {
                                    validInput = false;
                                    break;
                                }
                            }
                            if (validInput) { break; }
                        }
                        ClearBuffer();
                        std::cout << "�����������������룡" << std::endl;
                    }
                }
                HideCursor();
                std::cout << std::endl;

                S4::DNASort(dnaVec);

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