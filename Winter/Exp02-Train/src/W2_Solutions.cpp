#include "W2_Solution.h"
#include "ArrayStack.h"
#include "Permutation.h"

#include <format>
#include <vector>
#include <iostream>
#include <fstream>

#include <ranges>
#include <algorithm>
#include <numeric>
#include <direct.h>
#include <io.h>
#include <conio.h>

namespace Winter02
{
    bool Task01(const std::vector<int>& outputOrder, int numOfCars, std::ostream* out)
    {
        std::string process;

        bool success = true;
        MyDS::ArrayStack<int> holdingTrack(numOfCars - 1);
        int checkingCar = 1;

        for (int i = 0; i < numOfCars; ++i)
        {
            if (!holdingTrack.IsEmpty() && holdingTrack.GetTop() == outputOrder[i])
            {
                process += std::format("| -> {}�ų���Ӹ������ʻ��������Ҳ�\n", outputOrder[i]);
                holdingTrack.Pop();
            }
            else
            {
                while (checkingCar < outputOrder[i])
                {
                    process += std::format("-> | {}�ų������������ʻ�븨�����\n", checkingCar);
                    holdingTrack.Push(checkingCar);
                    ++checkingCar;
                }
                if (checkingCar == outputOrder[i])
                {
                    process += std::format("->-> {}�ų������������ʻ��������Ҳ�\n", outputOrder[i]);
                    ++checkingCar;
                }
                else
                {
                    success = false;
                    break;
                }
            }
        }

        if (success)
            process += "������ɣ�";
        else
            process = "����ʧ�ܣ�";

        if (out)
            (*out) << process << std::endl;
        return success;
    }

    bool Task02(const std::vector<int>& inputOrder, int numOfCars, std::ostream* out)
    {
        std::string process;
        MyDS::ArrayStack<int> holdingTrack(numOfCars);
        bool success = true;
        int nextCarToOutput = 1;
        for (int i = 0; i < numOfCars; ++i)
        {
            if (inputOrder[i] == nextCarToOutput)
            {
                process += std::format("->-> {}�ų������������ʻ��������Ҳ�\n", inputOrder[i]);
                ++nextCarToOutput;
                while (!holdingTrack.IsEmpty() && holdingTrack.GetTop() == nextCarToOutput)
                {
                    process += std::format("| -> {}�ų���Ӹ������ʻ��������Ҳ�\n", holdingTrack.GetTop());
                    holdingTrack.Pop();
                    ++nextCarToOutput;
                }
            }
            else
            {
                if (!holdingTrack.IsEmpty() && holdingTrack.GetTop() < inputOrder[i])
                {
                    success = false;
                    break;
                }
                holdingTrack.Push(inputOrder[i]);
                process += std::format("-> | {}�ų������������ʻ�븨�����\n", inputOrder[i]);
            }
        }
        if (success)
            process += "������ɣ�";
        else
            process = "����ʧ�ܣ�";

        if (out)
            (*out) << process << std::endl;
        return success;
    }

    void Task01_Validation(int numOfCars)
    {
        // inOrder = 1, 2, 3, ..., numOfCars
        std::vector<int> inOrder(numOfCars);
        std::iota(inOrder.begin(), inOrder.end(), 1);

        std::cout << "�������п��ܵĵ��Ƚ��..." << std::endl;
        std::vector<std::vector<int>> outOrders;
        MyDS::ArrayStack<int> st;
        std::vector<int> outOrder;
        StackOut(inOrder, 0, st, outOrder, outOrders);

        std::cout << "ͳ�����п��ܵ��Ƚ���е��ȳɹ��ĸ���..." << std::endl;
        int success1 = 0;
        for (const std::vector<int>& out : outOrders)
        {
            if (Winter02::Task01(out, numOfCars, nullptr))
                success1++;
        }

        std::cout << "���ȳɹ��ĸ��������ɵĽ����";
        if (outOrders.size() == success1)
        {
            std::cout << "���" << std::endl;
        }
        else
        {
            std::cout << "����ȣ��㷨�����쳣" << std::endl;
            return;
        }

        std::cout << "\n�������п��ܵ��û�����..." << std::endl;
        std::vector<std::vector<int>> fullPerms;
        FullPermutation(inOrder, 0, numOfCars - 1, fullPerms);

        std::cout << "ͳ�����п��ܵ��û������е��ȳɹ��ĸ���..." << std::endl;
        int success2 = 0;
        std::string result;
        for (const std::vector<int>& vec : fullPerms)
        {
            if (Winter02::Task01(vec, numOfCars, nullptr))
            {
                success2++;
                result += std::format("[{}] ", success2);
                for (int e : vec)
                    result += std::format("{} ", e);
                result += "\n";
            }
        }

        std::cout << "���ȳɹ��ĸ��������п��ܵĵ��Ƚ����";
        if (success1 == success2)
        {
            std::cout << "���\n";
            std::cout << "�㷨��ȷ�����ȳɹ���Ϊ" << success1 << "/" << fullPerms.size() << std::endl;

            std::cout << "\n�Ƿ�������е��ȳɹ��Ĳ���������output/result1.txt��[Y/N]" << std::endl;

            char key;
            while ((key = _getch()) != 'y' && key != 'Y' && key != 'n' && key != 'N');
            if (key == 'y' || key == 'Y')
            {
                std::string folderPath = "output/";
                // If the folder does not exist, create it.
                if (_access(folderPath.c_str(), 0) == -1)
                    _mkdir(folderPath.c_str());

                std::ofstream fout(folderPath + "result1.txt");
                fout << result;
                fout.close();
                std::cout << "�ѱ��棡" << std::endl;
            }
        }
        else
        {
            std::cout << "����ȣ��㷨�����쳣" << std::endl;
        }
    }

    void Task02_Validation(int numOfCars)
    {
        // outOrder = 1, 2, 3, ..., numOfCars
        std::vector<int> outOrder(numOfCars);
        std::iota(outOrder.begin(), outOrder.end(), 1);

        std::cout << "�������п��ܵĴ���������..." << std::endl;
        std::vector<std::vector<int>> inOrders;
        MyDS::ArrayStack<int> st;
        std::vector<int> inOrder;
        std::vector<int> outOrder_rev(outOrder);
        std::ranges::reverse(outOrder_rev);
        StackOut(outOrder_rev, 0, st, inOrder, inOrders);
        for (std::vector<int>& in : inOrders)
            std::ranges::reverse(in);

        std::cout << "ͳ�����п��ܵĴ����������е��ȳɹ��ĸ���..." << std::endl;
        int success1 = 0;
        for (const std::vector<int>& in : inOrders)
        {
            if (Winter02::Task02(in, numOfCars, nullptr))
                success1++;
        }

        std::cout << "���ȳɹ��ĸ�������������еĸ���";
        if (inOrders.size() == success1)
        {
            std::cout << "���" << std::endl;
        }
        else
        {
            std::cout << "����ȣ��㷨�����쳣" << std::endl;
            return;
        }

        std::cout << "\n�������п��ܵ��û�����..." << std::endl;
        std::vector<std::vector<int>> fullPerms;
        FullPermutation(outOrder, 0, numOfCars - 1, fullPerms);

        std::cout << "ͳ�����п��ܵ��û������е��ȳɹ��ĸ���..." << std::endl;
        int success2 = 0;
        std::string result;
        for (const std::vector<int>& vec : fullPerms)
        {
            if (Winter02::Task02(vec, numOfCars, nullptr))
            {
                success2++;
                result += std::format("[{}] ", success2);
                for (int e : vec)
                    result += std::format("{} ", e);
                result += "\n";
            }
        }

        std::cout << "���ȳɹ��ĸ��������п��ܵĴ��������и���";
        if (success1 == success2)
        {
            std::cout << "���" << std::endl;
            std::cout << "�㷨��ȷ�����ȳɹ���Ϊ" << success1 << "/" << fullPerms.size() << std::endl;

            std::cout << "\n�Ƿ�������е��ȳɹ��Ĳ����������ļ�output/result2.txt��[Y/N]" << std::endl;
            char key;
            while ((key = _getch()) != 'y' && key != 'Y' && key != 'n' && key != 'N');
            if (key == 'y' || key == 'Y')
            {
                std::string folderPath = "output/";
                // If the folder does not exist, create it.
                if (_access(folderPath.c_str(), 0) == -1)
                    _mkdir(folderPath.c_str());

                std::ofstream fout(folderPath + "result2.txt");
                fout << result;
                fout.close();
                std::cout << "�ѱ��棡" << std::endl;
            }
        }
        else
        {
            std::cout << "����ȣ��㷨�����쳣" << std::endl;
        }
    }

}