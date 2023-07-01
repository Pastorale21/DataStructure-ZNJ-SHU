#include<iostream>
#include<conio.h>
#include"Tools/Settings.hpp"

namespace Menu
{
    void InterviewArrangement();
    void Train();
    void LiteratureAssistant();
    void BinaryTreeTest();
    void AdjMatWDirGraphTest();
    void AdjListWUndirGraphTest();
    void Search();
    ////void Sort();
}

int main() {
    char key;
    bool flag = true;
    HideCursor();

    while (flag) {
        system("cls");
        std::cout << "SJ�ṹʵ��\n" << std::endl;

        std::cout << "[1] ��-ʵ��һ ���԰���\n";
        std::cout << "[2] ��-ʵ��� �������\n";
        std::cout << "[3] ��-ʵ���� ��ѧ�о�����\n";
        std::cout << "[4] ��-ʵ���� ��������չ����Ƕ�����\n";
        std::cout << "[5] ��-ʵ��һ ���������ڽӾ�����֤����չ\n";
        std::cout << "[6] ��-ʵ��� ���������ڽӱ���֤����չ\n";
        std::cout << "[7] ��-ʵ���� �����㷨��֤�����\n";
        std::cout << "[8] ��-ʵ���� �����㷨��֤�����\n";
        std::cout << "[9] �˳�" << std::endl;

        while ((key = _getch()) < '1' || key > '9');

        switch (key) {
        case '1': { Menu::InterviewArrangement();    break; }
        case '2': { Menu::Train();                   break; }
        case '3': { Menu::LiteratureAssistant();     break; }
        case '4': { Menu::BinaryTreeTest();          break; }
        case '5': { Menu::AdjMatWDirGraphTest();     break; }
        case '6': { Menu::AdjListWUndirGraphTest();  break; }
        case '7': { Menu::Search();                  break; }
        case '8': { break; }  // Unfinished
        case '9': { flag = false; break; }
        }
    }
}