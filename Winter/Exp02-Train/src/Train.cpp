#include "W2_Solution.h"
#include "Console.h"

#include <iostream>
#include <conio.h>
#include <vector>
#include <set>

namespace Winter02
{
    void Train()
    {
        while (true)
        {
            Console::Clear();
            std::cout << "��-ʵ��� �������\n\n";

            std::cout << "[1] ��һ��\n";
            std::cout << "[2] �ڶ���\n";
            std::cout << "[3] ��һ����㷨��֤\n";
            std::cout << "[4] �ڶ�����㷨��֤\n";
            std::cout << "[5] �˳�" << std::endl;

            char key;
            while ((key = _getch()) < '1' && key > '5');

            switch (key)
            {
                case '1':
                {
                    Console::Clear();
                    std::cout << "��һ��\n" << std::endl;

                    std::cout << "�����복��������";
                    int numOfCars;
                    bool validInput;
                    while (true)
                    {
                        std::cin >> numOfCars;
                        validInput = !std::cin.fail() && numOfCars >= 1;
                        Console::ClearBuffer();
                        if (validInput)
                            break;
                        std::cout << "�����������������복��������";
                    }

                    std::cout << "\n������������Ҳ�ĳ���˳��" << std::endl;
                    std::vector<int> outputOrder(numOfCars);
                    while (true)
                    {
                        std::set<int> checkOrder;
                        for (int i = 0; i < numOfCars; ++i)
                        {
                            std::cin >> outputOrder[i];
                            validInput = !std::cin.fail()
                                && outputOrder[i] >= 1 && outputOrder[i] <= numOfCars
                                && checkOrder.find(outputOrder[i]) == checkOrder.end();
                            if (!validInput)
                                break;
                            checkOrder.emplace(outputOrder[i]);
                        }
                        Console::ClearBuffer();
                        if (validInput)
                            break;
                        std::cout << "������������������������Ҳ�ĳ���˳��" << std::endl;
                    }
                    std::cout << "\n";

                    Task01(outputOrder, numOfCars);

                    std::cout << std::endl;
                    Console::WaitForKey();
                    break;
                }
                case '2':
                {
                    Console::Clear();
                    std::cout << "�ڶ���\n" << std::endl;

                    std::cout << "�����복��������";
                    int numOfCars;
                    bool validInput;
                    while (true)
                    {
                        std::cin >> numOfCars;
                        validInput = !std::cin.fail() && numOfCars >= 1;
                        Console::ClearBuffer();
                        if (validInput)
                            break;
                        std::cout << "�����������������복��������";
                    }

                    std::cout << "\n��������������ĳ���˳��" << std::endl;
                    std::vector<int> inputOrder(numOfCars);
                    while (true)
                    {
                        std::set<int> checkOrder;
                        for (int i = 0; i < numOfCars; ++i)
                        {
                            std::cin >> inputOrder[i];
                            validInput = !std::cin.fail()
                                && inputOrder[i] >= 1 && inputOrder[i] <= numOfCars
                                && checkOrder.find(inputOrder[i]) == checkOrder.end();
                            if (!validInput)
                                break;
                            checkOrder.emplace(inputOrder[i]);
                        }
                        Console::ClearBuffer();
                        if (validInput)
                            break;
                        std::cout << "��������������������������ĳ���˳��" << std::endl;
                    }
                    std::cout << "\n";

                    Task02(inputOrder, numOfCars);

                    std::cout << std::endl;
                    Console::WaitForKey();
                    break;
                }
                case '3':
                {
                    Console::Clear();
                    std::cout << "��һ����㷨��֤\n" << std::endl;

                    std::cout << "�����복��������";
                    int numOfCars;
                    bool validInput;
                    while (true)
                    {
                        std::cin >> numOfCars;
                        validInput = !std::cin.fail() && numOfCars >= 1;
                        Console::ClearBuffer();
                        if (validInput)
                            break;
                        std::cout << "�����������������복��������";
                    }
                    std::cout << "\n";

                    Task01_Validation(numOfCars);

                    std::cout << std::endl;
                    Console::WaitForKey();
                    break;
                }
                case '4':
                {
                    Console::Clear();
                    std::cout << "�ڶ�����㷨��֤\n" << std::endl;

                    std::cout << "�����복��������";
                    int numOfCars;
                    bool validInput;
                    while (true)
                    {
                        std::cin >> numOfCars;
                        validInput = !std::cin.fail() && numOfCars >= 1;
                        Console::ClearBuffer();
                        if (validInput)
                            break;
                        std::cout << "�����������������복��������";
                    }
                    std::cout << "\n";

                    Task02_Validation(numOfCars);

                    std::cout << std::endl;
                    Console::WaitForKey();
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

int main()
{
    Winter02::Train();
}