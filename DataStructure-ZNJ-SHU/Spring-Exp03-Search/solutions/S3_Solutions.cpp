#include<iostream>
#include<algorithm>
#include<unordered_set>
#include<conio.h>
#include"../data_structure/BinarySearchTree.h"
#include"../../Tools/Random.hpp"
#include"../../Tools/Settings.hpp"

namespace S3
{
    void BST_Test() {
        static BinarySearchTree<int, int> tree;
        while (true) {
            system("cls");
            std::cout << "��������\n" << std::endl;
            tree.outputKeyTree();

            std::cout << "[1] ����Ԫ��\n";
            std::cout << "[2] ɾ��Ԫ�أ������������Ԫ���滻��ɾ��Ԫ�أ�\n";
            std::cout << "[3] ɾ��Ԫ�أ�����������СԪ���滻��ɾ��Ԫ�أ�\n";
            std::cout << "[4] ɾ��Ԫ�أ����������ƶ�����������СԪ�ص���������\n";
            std::cout << "[5] ɾ��Ԫ�أ����������ƶ������������Ԫ�ص���������\n";
            std::cout << "[6] ���\n";
            std::cout << "[7] ������һ���˵�\n" << std::endl;

            char choice;
            bool validInput;
            while ((choice = _getch()) < '1' && choice > '7');

            auto GetKey = [&]()->int {
                int key;
                while (true) {
                    std::cin >> key;
                    validInput = !std::cin.fail();
                    ClearBuffer();
                    if (validInput) { break; }
                    std::cout << "�����������������룺";
                }
                return key;
            };

            switch (choice) {
            case '1':
            {
                ShowCursor();
                std::cout << "����Ԫ��\n";
                std::cout << "�����������Ԫ�صļ�����������";
                int key = GetKey();
                HideCursor();
                tree.insert(key, key);
                break;
            }
            case '2':
            {
                ShowCursor();
                std::cout << "ɾ��Ԫ�أ������������Ԫ���滻��ɾ��Ԫ�أ�\n";
                std::cout << "�������ɾ��Ԫ�صļ���";
                int key = GetKey();
                HideCursor();
                tree.erase_ver1(key);
                break;
            }
            case '3':
            {
                ShowCursor();
                std::cout << "ɾ��Ԫ�أ�����������СԪ���滻��ɾ��Ԫ�أ�\n";
                std::cout << "�������ɾ��Ԫ�صļ���";
                int key = GetKey();
                HideCursor();
                tree.erase_ver2(key);
                break;
            }
            case '4':
            {
                ShowCursor();
                std::cout << "ɾ��Ԫ�أ����������ƶ�����������СԪ�ص���������\n";
                std::cout << "�������ɾ��Ԫ�صļ���";
                int key = GetKey();
                HideCursor();
                tree.erase_ver3(key);
                break;
            }
            case '5':
            {
                ShowCursor();
                std::cout << "ɾ��Ԫ�أ����������ƶ������������Ԫ�ص���������\n";
                std::cout << "�������ɾ��Ԫ�صļ���";
                int key = GetKey();
                HideCursor();
                tree.erase_ver4(key);
                break;
            }
            case '6':
            {
                tree.clear();
                break;
            }
            case '7':
            {
                return;
            }
            }
        }
    }

    void BST_EfficiencyTest() {
        std::cout << "Ч�ʶԱ�\n" << std::endl;
        std::cout << "������Ԫ�ظ�����";
        ShowCursor();
        int numOfElements;
        bool validInput;
        while (true) {
            std::cin >> numOfElements;
            validInput = !std::cin.fail() && numOfElements;
            ClearBuffer();
            if (validInput) { break; }
            std::cout << "������������������Ԫ�ظ���: ";
        }
        HideCursor();

        std::cout << "���ڹ����������������\n" << std::endl;
        std::unordered_set<int> set;
        std::vector<std::pair<int, int>> elements;
        for (size_t i = 0; i < numOfElements;) {
            int temp = Rand_Uniform<int>()(-2 * numOfElements, 2 * numOfElements);
            if (set.find(temp) == set.end()) {
                set.insert(temp);
                elements.push_back(std::pair<int, int>{ temp, temp });
                i++;
            }
        }
        BinarySearchTree<int, int> tree(elements);
        std::vector<void(BinarySearchTree<int, int>::*)(const int&)> methods = {
            &BinarySearchTree<int, int>::erase_ver1, &BinarySearchTree<int, int>::erase_ver2,
            &BinarySearchTree<int, int>::erase_ver3, &BinarySearchTree<int, int>::erase_ver4
        };
        auto EraseTest = [&](int idx) {
            BinarySearchTree<int, int> copy(tree);
            clock_t start = clock();
            for (const auto& element : elements) {
                (copy.*methods[idx - 1])(element.first);  // Call erase function.
            }
            clock_t end = clock();
            std::cout << "��ʱ" << end - start << "ms" << std::endl;
        };
        std::cout << "����һ�������������Ԫ���滻��ɾ��Ԫ��" << std::endl;
        EraseTest(1);
        std::cout << "������������������СԪ���滻��ɾ��Ԫ��" << std::endl;
        EraseTest(2);
        std::cout << "�����������������ƶ�����������СԪ�ص�������" << std::endl;
        EraseTest(3);
        std::cout << "�����ģ����������ƶ������������Ԫ�ص�������" << std::endl;
        EraseTest(4);

        system("pause");
    }
}