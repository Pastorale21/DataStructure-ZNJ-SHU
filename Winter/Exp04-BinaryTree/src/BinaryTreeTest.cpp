#include "W4_Solution.h"
#include "Console.h"
#include <iostream>
#include <conio.h>
#include <vector>

namespace Winter04
{
    void BinaryTreeTest()
    {
        bool validInput;
        while (true)
        {
            Console::Clear();
            std::cout << "��-ʵ���� ��������չ����Ƕ�����\n\n";

            std::cout << "[1] ������������\n";
            std::cout << "[2] ��Ƕ�����\n";
            std::cout << "[3] �˳�" << std::endl;

            char choice;
            while ((choice = _getch()) < '1' && choice > '3');

            switch (choice)
            {
                case '1':
                {
                    Console::Clear();
                    std::cout << "������������\n\n";

                    Task01();

                    Console::WaitForKey();
                    break;
                }
                case '2':
                {
                    Console::Clear();
                    std::cout << "��Ƕ�����\n\n";

                    std::cout << "���������������";
                    int numOfCases;
                    while (true)
                    {
                        std::cin >> numOfCases;
                        validInput = !std::cin.fail() && numOfCases > 0;
                        Console::ClearBuffer();
                        if (validInput)
                            break;
                        std::cout << "���������������������������";
                    }

                    std::cout << "������������ݣ�" << std::endl;
                    for (int i = 0; i < numOfCases; i++)
                    {
                        int a, b;
                        while (true)
                        {
                            std::cout << "(" << i + 1 << ") ";
                            std::cin >> a >> b;
                            validInput = !std::cin.fail() && a > 0 && b > 0;
                            Console::ClearBuffer();
                            if (validInput)
                                break;
                            std::cout << "�����������������룡" << std::endl;
                        }
                        Task02(a, b);
                    }
                    std::cout << std::endl;
                    Console::WaitForKey();
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

int main()
{
    Winter04::BinaryTreeTest();
}