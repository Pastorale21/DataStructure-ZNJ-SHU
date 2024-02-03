#include "W1_Solution.h"

#include "Console.h"
#include <iostream>
#include <conio.h>

namespace Winter01
{
    void InterviewArrangement()
    {
        while (true)
        {
            Console::Clear();
            std::cout << "��-ʵ��һ ���԰���\n\n";

            std::cout << "[1] ��һ��\n";
            std::cout << "[2] �ڶ���\n";
            std::cout << "[3] �˳�" << std::endl;

            char choice;
            while ((choice = _getch()) < '1' && choice > '3');

            if (choice == '3')
                return;

            Console::Clear();
            if (choice == '1')
                std::cout << "��һ�⣺\n";
            else
                std::cout << "�ڶ��⣺\n";

            std::cout << "������N��K��M��ֵ��";
            int N, K, M;
            while (true)
            {
                std::cin >> N >> K >> M;
                bool isValid = !std::cin.fail() && N > 0 && K > 0 && M > 0;
                Console::ClearBuffer();
                if (isValid)
                    break;
                std::cout << "������������������N��K��M��ֵ��";
            }

            if (choice == '1')
                Task01(N, K, M);
            else
                Task02(N, K, M);

            std::cout << std::endl;
            Console::WaitForKey();
        }
    }
}

int main()
{
    Winter01::InterviewArrangement();
}