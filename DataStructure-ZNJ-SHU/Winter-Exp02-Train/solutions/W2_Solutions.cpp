#include<sstream>
#include<vector>
#include"../data_structure/ArrayStack.h"

namespace W2
{
    bool Question1(const std::vector<int>& outputOrder, int numOfCars, std::ostream* out) {
        std::ostringstream process;
        ArrayStack<int> holdingTrack(numOfCars - 1);
        bool success = true;
        int checkingCar = 1;
        for (int i = 0; i < numOfCars; ++i) {
            if (!holdingTrack.empty() && holdingTrack.top() == outputOrder[i]) {
                process << "| -> " << outputOrder[i] << "�ų���Ӹ������ʻ��������Ҳ�\n";
                holdingTrack.pop();
            } else {
                while (checkingCar < outputOrder[i]) {
                    process << "-> | " << checkingCar << "�ų������������ʻ�븨�����\n";
                    holdingTrack.push(checkingCar);
                    ++checkingCar;
                }
                if (checkingCar == outputOrder[i]) {
                    process << "->-> " << outputOrder[i] << "�ų������������ʻ��������Ҳ�\n";
                    ++checkingCar;
                } else {
                    success = false;
                    break;
                }
            }
        }
        if (success) {
            process << "������ɣ�";
        } else {
            process.str("����ʧ�ܣ�");
        }

        if (out) {
            (*out) << process.str() << std::endl;
        }
        return success;
    }

    bool Question2(const std::vector<int>& inputOrder, int numOfCars, std::ostream* out) {
        std::ostringstream process;
        ArrayStack<int> holdingTrack(numOfCars);
        bool success = true;
        int nextCarToOutput = 1;
        for (int i = 0; i < numOfCars; ++i) {
            if (inputOrder[i] == nextCarToOutput) {
                process << "->-> " << inputOrder[i] << "�ų������������ʻ��������Ҳ�\n";
                ++nextCarToOutput;
                while (!holdingTrack.empty() && holdingTrack.top() == nextCarToOutput) {
                    process << "| -> " << holdingTrack.top() << "�ų���Ӹ������ʻ��������Ҳ�\n";
                    holdingTrack.pop();
                    ++nextCarToOutput;
                }
            } else {
                if (!holdingTrack.empty() && holdingTrack.top() < inputOrder[i]) {
                    success = false;
                    break;
                }
                holdingTrack.push(inputOrder[i]);
                process << "-> | " << inputOrder[i] << "�ų������������ʻ�븨�����\n";
            }
        }
        if (success) {
            process << "������ɣ�";
        } else {
            process.str("����ʧ�ܣ�");
        }

        if (out) {
            (*out) << process.str() << std::endl;
        }
        return success;
    }
}