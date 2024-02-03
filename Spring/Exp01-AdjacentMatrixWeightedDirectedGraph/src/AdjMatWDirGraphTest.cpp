#include "S1_Solution.h"
#include "AdjMatWDirGraph.h"
#include "Console.h"

#include <iostream>
#include <conio.h>

namespace Spring01
{
    void AdjMatWDirGraphTest()
    {
        MyDS::AdjMatWDirGraph<int, int> g;
        while (true)
        {
            Console::Clear();
            std::cout << "��-ʵ��һ ���������ڽӾ�����֤����չ\n" << std::endl;

            std::cout << "�ߣ�\n";
            g.PrintEdges();
            std::cout << "\n�ڽӾ���\n";
            g.PrintAdjacentMatrix();

            std::cout << "\n[1] ���붥��  [2] ɾ������  [3] �����  [4] ɾ����\n";
            std::cout << "[5] ����      [6] ���·��  [7] ���    [8] �˳�\n" << std::endl;

            char choice;
            while ((choice = _getch()) < '1' && choice > '8');

            switch (choice)
            {
                case '1':
                {
                    std::cout << "���붥��\n";
                    std::cout << "�����붥�㣨��������";
                    int v;
                    while (true)
                    {
                        std::cin >> v;
                        bool validInput = !std::cin.fail();
                        Console::ClearBuffer();
                        if (validInput)
                            break;
                        std::cout << "�����������������붥�㣨��������";
                    }

                    InsertVertex(g, v);

                    Console::WaitForKey();
                    break;
                }
                case '2':
                {
                    std::cout << "ɾ������\n";
                    std::cout << "�����붥�㣺";
                    int v;
                    while (true)
                    {
                        std::cin >> v;
                        bool validInput = !std::cin.fail();
                        Console::ClearBuffer();
                        if (validInput)
                            break;
                        std::cout << "�����������������붥�㣺";
                    }

                    EraseVertex(g, v);

                    Console::WaitForKey();
                    break;
                }
                case '3':
                {
                    std::cout << "�����\n";
                    std::cout << "����������ߵ���㡢�յ��Ȩֵ����������";
                    int from, to, weight;
                    while (true)
                    {
                        std::cin >> from >> to >> weight;
                        bool validInput = !std::cin.fail();
                        Console::ClearBuffer();
                        if (validInput)
                            break;
                        std::cout << "������������������ߵ���㡢�յ��Ȩֵ����������";
                    }

                    InsertEdge(g, from, to, weight);

                    Console::WaitForKey();
                    break;
                }
                case '4':
                {
                    std::cout << "ɾ����\n";
                    std::cout << "����������ߵ������յ㣺";
                    int from, to;
                    while (true)
                    {
                        std::cin >> from >> to;
                        bool validInput = !std::cin.fail();
                        Console::ClearBuffer();
                        if (validInput)
                            break;
                        std::cout << "������������������ߵ������յ㣺";
                    }

                    EraseEdge(g, from, to);

                    Console::WaitForKey();
                    break;
                }
                case '5':
                {
                    std::cout << "����\n";
                    std::cout << "�����붥�㣺";
                    int v;
                    while (true)
                    {
                        std::cin >> v;
                        bool validInput = !std::cin.fail();
                        Console::ClearBuffer();
                        if (validInput)
                            break;
                        std::cout << "�����������������붥�㣺";
                    }

                    Degree(g, v);

                    Console::WaitForKey();
                    break;
                }
                case '6':
                {
                    std::cout << "���·��\n";
                    std::cout << "������Դ����յ㣺";
                    int source, end;
                    while (true)
                    {
                        std::cin >> source >> end;
                        bool validInput = !std::cin.fail();
                        Console::ClearBuffer();
                        if (validInput)
                            break;
                        std::cout << "������������������Դ����յ㣺";
                    }

                    ShortestPath(g, source, end);

                    Console::WaitForKey();
                    break;
                }
                case '7':
                {
                    g.Clear();
                    break;
                }
                case '8':
                {
                    return;
                }
            }
        }
    }
}

int main()
{
    Spring01::AdjMatWDirGraphTest();
}