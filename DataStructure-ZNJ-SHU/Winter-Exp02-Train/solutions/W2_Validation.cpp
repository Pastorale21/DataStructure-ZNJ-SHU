#include<fstream>
#include<sstream>
#include<conio.h>
#include<vector>
#include<ranges>
#include<algorithm>
#include<numeric>
#include<direct.h>
#include<io.h>
#include"../data_structure/ArrayStack.h"
#include"Permutation.h"
#include"W2_Solutions.h"

namespace W2
{
    void Q1_Validation(int numOfCars) {
        // inOrder = 1, 2, 3, ..., numOfCars
        std::vector<int> inOrder(numOfCars);
        std::iota(inOrder.begin(), inOrder.end(), 1);

        std::cout << "�������п��ܵĵ��Ƚ��..." << std::endl;
        std::vector<std::vector<int>> outOrders;
        ArrayStack<int> st;
        std::vector<int> outOrder;
        stack_out(inOrder, 0, st, outOrder, outOrders);

        std::cout << "ͳ�����п��ܵ��Ƚ���е��ȳɹ��ĸ���..." << std::endl;
        int success1 = 0;
        for (const auto& out : outOrders) {
            if (W2::Question1(out, numOfCars, nullptr)) {
                success1++;
            }
        }

        std::cout << "���ȳɹ��ĸ��������ɵĽ����";
        if (outOrders.size() == success1) {
            std::cout << "���" << std::endl;
        } else {
            std::cout << "����ȣ��㷨�����쳣" << std::endl;
            return;
        }

        std::cout << "\n�������п��ܵ��û�����..." << std::endl;
        std::vector<std::vector<int>> fullPerms;
        full_permutation(inOrder, 0, numOfCars - 1, fullPerms);

        std::cout << "ͳ�����п��ܵ��û������е��ȳɹ��ĸ���..." << std::endl;
        int success2 = 0;
        std::ostringstream result;
        for (const auto& vec : fullPerms) {
            if (W2::Question1(vec, numOfCars, nullptr)) {
                success2++;
                result << "[" << success2 << "] ";
                for (auto e : vec) {
                    result << e << " ";
                }
                result << std::endl;
            }
        }

        std::cout << "���ȳɹ��ĸ��������п��ܵĵ��Ƚ����";
        if (success1 == success2) {
            std::cout << "���" << std::endl;
            std::cout << "�㷨��ȷ�����ȳɹ���Ϊ" << success1 << "/" << fullPerms.size() << std::endl;

            std::cout << "\n�Ƿ�������е��ȳɹ��Ĳ����������ļ�Winter-Exp02-Train/output/test1.txt��[Y/N]" << std::endl;
            char key;
            while ((key = _getch()) != 'y' && key != 'Y' && key != 'n' && key != 'N');
            if (key == 'y' || key == 'Y') {
                std::string folderPath = "Winter-Exp02-Train/output/";
                if (_access(folderPath.c_str(), 0) == -1) {
                    _mkdir(folderPath.c_str());
                }
                std::ofstream fout(folderPath + "test1.txt");
                fout << result.str();
                fout.close();
                std::cout << "�ѱ��棡" << std::endl;
            }
        } else {
            std::cout << "����ȣ��㷨�����쳣" << std::endl;
        }
    }

    void Q2_Validation(int numOfCars) {
        // outOrder = 1, 2, 3, ..., numOfCars
        std::vector<int> outOrder(numOfCars);
        std::iota(outOrder.begin(), outOrder.end(), 1);

        std::cout << "�������п��ܵĴ���������..." << std::endl;
        std::vector<std::vector<int>> inOrders;
        ArrayStack<int> st;
        std::vector<int> inOrder;
        std::vector<int> outOrder_rev(outOrder);
        std::ranges::reverse(outOrder_rev);
        stack_out(outOrder_rev, 0, st, inOrder, inOrders);
        for (auto& in : inOrders) {
            std::ranges::reverse(in);
        }

        std::cout << "ͳ�����п��ܵĴ����������е��ȳɹ��ĸ���..." << std::endl;
        int success1 = 0;
        for (const auto& in : inOrders) {
            if (W2::Question2(in, numOfCars, nullptr)) {
                success1++;
            }
        }

        std::cout << "���ȳɹ��ĸ�������������еĸ���";
        if (inOrders.size() == success1) {
            std::cout << "���" << std::endl;
        } else {
            std::cout << "����ȣ��㷨�����쳣" << std::endl;
            return;
        }

        std::cout << "\n�������п��ܵ��û�����..." << std::endl;
        std::vector<std::vector<int>> fullPerms;
        full_permutation(outOrder, 0, numOfCars - 1, fullPerms);

        std::cout << "ͳ�����п��ܵ��û������е��ȳɹ��ĸ���..." << std::endl;
        int success2 = 0;
        std::ostringstream result;
        for (const auto& vec : fullPerms) {
            if (W2::Question2(vec, numOfCars, nullptr)) {
                success2++;
                result << "[" << success2 << "] ";
                for (auto e : vec) {
                    result << e << " ";
                }
                result << std::endl;
            }
        }

        std::cout << "���ȳɹ��ĸ��������п��ܵĴ��������и���";
        if (success1 == success2) {
            std::cout << "���" << std::endl;
            std::cout << "�㷨��ȷ�����ȳɹ���Ϊ" << success1 << "/" << fullPerms.size() << std::endl;

            std::cout << "\n�Ƿ�������е��ȳɹ��Ĳ����������ļ�Winter-Exp02-Train/output/test2.txt��[Y/N]" << std::endl;
            char key;
            while ((key = _getch()) != 'y' && key != 'Y' && key != 'n' && key != 'N');
            if (key == 'y' || key == 'Y') {
                std::string folderPath = "Winter-Exp02-Train/output/";
                if (_access(folderPath.c_str(), 0) == -1) {
                    _mkdir(folderPath.c_str());
                }
                std::ofstream fout(folderPath + "test2.txt");
                fout << result.str();
                fout.close();
                std::cout << "�ѱ��棡" << std::endl;
            }
        } else {
            std::cout << "����ȣ��㷨�����쳣" << std::endl;
        }
    }
}