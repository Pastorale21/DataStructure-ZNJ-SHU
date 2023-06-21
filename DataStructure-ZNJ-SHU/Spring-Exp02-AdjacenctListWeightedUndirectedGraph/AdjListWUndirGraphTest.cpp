#include<iostream>
#include<conio.h>
#include"data_structure/AdjListWUndirGraph.h"
#include"solutions/S2_Solutions.h"
#include"../Tools/Settings.hpp"

namespace Menu
{
    void AdjListWUndirGraphTest() {
        static AdjListWUndirGraph<int, int> g;
        char key;
        bool validInput;
        while (true) {
            system("cls");
            HideCursor();
            std::cout << "��-ʵ��� ���������ڽӱ���֤����չ\n" << std::endl;

            std::cout << "�ߣ�\n";
            g.printEdges();
            std::cout << "\n�ڽӱ�\n";
            g.printAdjList();

            std::cout << "\n[1] ���붥��  [2] ɾ������  [3] �����  [4] ɾ����\n";
            std::cout << "[5] ����  [6] ��ͨ������  [7] ��С������  [8] ���  [9] ������һ���˵�\n" << std::endl;

            while ((key = _getch()) < '1' && key > '9');

            switch (key) {
            case '1':
            {
                ShowCursor();
                std::cout << "���붥��\n";
                std::cout << "�����붥�㣨��������";
                int v;
                while (true) {
                    std::cin >> v;
                    validInput = !std::cin.fail();
                    ClearBuffer();
                    if (validInput) { break; }
                    std::cout << "�����������������붥�㣨��������";
                }
                HideCursor();

                S2::InsertVertex(g, v);

                system("pause");
                break;
            }
            case '2':
            {
                ShowCursor();
                std::cout << "ɾ������\n";
                std::cout << "�����붥�㣺";
                int v;
                while (true) {
                    std::cin >> v;
                    validInput = !std::cin.fail();
                    ClearBuffer();
                    if (validInput) { break; }
                    std::cout << "�����������������붥�㣺";
                }
                HideCursor();

                S2::EraseVertex(g, v);

                system("pause");
                break;
            }
            case '3':
            {
                ShowCursor();
                std::cout << "�����\n";
                std::cout << "����������ߵ���㡢�յ��Ȩֵ����������";
                int from, to, weight;
                while (true) {
                    std::cin >> from >> to >> weight;
                    validInput = !std::cin.fail();
                    ClearBuffer();
                    if (validInput) { break; }
                    std::cout << "������������������ߵ���㡢�յ��Ȩֵ����������";
                }
                HideCursor();

                S2::InsertEdge(g, from, to, weight);

                system("pause");
                break;
            }
            case '4':
            {
                ShowCursor();
                std::cout << "ɾ����\n";
                std::cout << "����������ߵ������յ㣺";
                int from, to;
                while (true) {
                    std::cin >> from >> to;
                    validInput = !std::cin.fail();
                    ClearBuffer();
                    if (validInput) { break; }
                    std::cout << "������������������ߵ������յ㣺";
                }
                HideCursor();

                S2::EraseEdge(g, from, to);

                system("pause");
                break;
            }
            case '5':
            {
                ShowCursor();
                std::cout << "����\n";
                std::cout << "�����붥�㣺";
                int v;
                while (true) {
                    std::cin >> v;
                    validInput = !std::cin.fail();
                    ClearBuffer();
                    if (validInput) { break; }
                    std::cout << "�����������������붥�㣺";
                }
                HideCursor();

                S2::Degree(g, v);

                system("pause");
                break;
            }
            case '6':
            {
                std::cout << "��ͨ������\n";
                S2::ConnectedComponent(g);
                system("pause");
                break;
            }

            case '7':
            {
                ShowCursor();
                std::cout << "��С������\n";
                int source, end;
                while (true) {
                    std::cin >> source >> end;
                    validInput = !std::cin.fail();
                    ClearBuffer();
                    if (validInput) { break; }
                    std::cout << "������������������Դ����յ㣺";
                }
                HideCursor();

                S2::MinimumSpanningTree(g);

                system("pause");
                break;
            }
            case '8':
            {
                g.clear();
                break;
            }
            case '9':
            {
                return;
            }
            }
        }
    }
}