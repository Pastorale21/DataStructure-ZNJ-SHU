#include<iostream>
#include<conio.h>
#include"data_structure/AdjMatWDirGraph.h"
#include"solutions/S1_Solutions.h"
#include"../../Tools/Settings.hpp"

namespace Menu
{
    void AdjMatWDirGraphTest() {
        static AdjMatWDirGraph<int, int> g;
        char key;
        bool validInput;
        while (true) {
            system("cls");
            HideCursor();
            std::cout << "��-ʵ��һ ���������ڽӾ�����֤����չ\n" << std::endl;

            std::cout << "���㣺\n";
            g.printVertices();
            std::cout << "\n�ߣ�\n";
            g.printEdges();
            std::cout << "\n�ڽӾ���\n";
            g.printAdjMatrix();

            std::cout << "\n[1] ���붥��  [2] ɾ������  [3] �����  [4] ɾ����\n";
            std::cout << "[5] ����      [6] ���·��  [7] ���    [8] ������һ���˵�\n" << std::endl;

            while ((key = _getch()) < '1' && key > '8');

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

                S1::InsertVertex(g, v);

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

                S1::EraseVertex(g, v);

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

                S1::InsertEdge(g, from, to, weight);

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

                S1::EraseEdge(g, from, to);

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

                S1::Degree(g, v);

                system("pause");
                break;
            }
            case '6':
            {
                ShowCursor();
                std::cout << "���·��\n";
                std::cout << "������Դ����յ㣺";
                int source, end;
                while (true) {
                    std::cin >> source >> end;
                    validInput = !std::cin.fail();
                    ClearBuffer();
                    if (validInput) { break; }
                    std::cout << "������������������Դ����յ㣺";
                }
                HideCursor();

                S1::ShortestPath(g, source, end);

                system("pause");
                break;
            }
            case '7':
            {
                g.clear();
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