#include "W3_Solution.h"

#include <iostream>
#include <fstream>
#include <conio.h>
#include <format>
#include <vector>
#include <set>
#include <direct.h>
#include <io.h>

namespace Winter03
{
    struct Location
    {
        int row = 1;
        int col = 1;
    };

    // Build next array for KMP (Multiple matching).
    std::vector<int> BuildNext(const std::string& pattern)
    {
        std::vector<int> next{ -1 };
        int t = -1;
        for (int j = 0; j < pattern.size();)
        {
            while (t >= 0 && pattern[j] != pattern[t])
                t = next[t];

            ++t, ++j;

            if (pattern[j] == pattern[t])
                next.push_back(next[t]);  // Optimize by using the previous next value.
            else
                next.push_back(t);
        }
        return next;
    }

    void ReadPatterns(std::ifstream& fpPat, std::vector<std::string>& patterns, std::vector<std::vector<int>>& nexts)
    {
        std::set<std::string> checkDuplicate;
        std::string word;

        while (fpPat >> word)
        {
            // Ignore the word if it is already read.
            if (checkDuplicate.find(word) != checkDuplicate.end())
                continue;

            // Check if the word is valid.
            bool valid = true;
            for (char c : word)
            {
                if (c >= 'A' && c <= 'Z')
                {
                    // Convert uppercase to lowercase.
                    c = c - 'A' + 'a';
                }
                else if (!(c >= 'a' && c <= 'z') && c != '-')  
                {
                    // Ignore non-alphabetic characters.
                    valid = false;
                    break;
                }
            }
            if (!valid)
                continue;

            checkDuplicate.emplace(word);
            patterns.push_back(word);
            nexts.push_back(BuildNext(word));
        }
    }

    void Task(const std::string& patternPath, const std::string& textPath, const std::string& outputDir)
    {
        // Read the patterns.
        std::cout << "���ڴ�" << patternPath << "��ȡ��ͳ�Ƶĵ��ʡ���" << std::endl;
        std::ifstream fpPattern(patternPath);
        if (!fpPattern.good())
        {
            std::cout << "��ȡʧ�ܣ�������ֹ��" << std::endl;
            return;
        }

        std::vector<std::string> patterns;
        std::vector<std::vector<int>> next;
        ReadPatterns(fpPattern, patterns, next);
        fpPattern.close();
        if (patterns.empty())
        {
            std::cout << "��ͳ�Ƶĵ���������Ϊ0��������ֹ��" << std::endl;
            return;
        }
        std::cout << "��ȡ��ϣ�\n" << std::endl;

        // Count the patterns in the text.
        std::cout << "���ڶ�" << textPath << "�����ݽ���ͳ�ơ���" << std::endl;
        std::ifstream fpText(textPath);
        if (!fpText.good())
        {
            std::cout << "�ļ���ȡʧ�ܣ�������ֹ��" << std::endl;
            return;
        }

        char c;
        Location pos{ 1, 1 };  // Position of current character.
        std::vector<int> p(next.size(), 0);  // Pattern pointers.
        std::vector<std::vector<Location>> count(next.size());
        while ((c = fpText.get()) != std::char_traits<char>::eof())
        {
            // If it reaches the end of a line, move {pos} to the next row and reset the pattern pointers.
            if (c == '\n' || c == '\r')
            {
                ++pos.row, pos.col = 1;
                std::fill(p.begin(), p.end(), 0);
                continue;
            }

            // Convert uppercase to lowercase.
            if (c >= 'A' && c <= 'Z')
                c = c - 'A' + 'a';

            // Apply the KMP algorithm for each pattern.
            for (int i = 0; i < patterns.size(); ++i)
            {
                while (p[i] >= 0 && c != patterns[i][p[i]])
                    p[i] = next[i][p[i]];

                ++p[i];

                if (p[i] == patterns[i].size())  // Pattern matched.
                {
                    count[i].emplace_back(pos.row, pos.col - p[i] + 1);
                    p[i] = next[i][p[i]];
                }
            }
            ++pos.col;
        }
        fpText.close();
        std::cout << "ͳ����ϣ�\n" << std::endl;

        // Print the result.
        std::string ans;
        for (int i = 0; i < patterns.size(); ++i)
        {
            ans += std::format("{0}: {1}�����ִ�����{2}\n", i + 1, patterns[i], count[i].size());
            if (!count[i].empty())
            {
                for (const Location& loc : count[i])
                    ans += std::format("    ��{0}�У���{1}��\n", loc.row, loc.col);
            }
            ans += '\n';
        }
        std::cout << ans;
        std::cout << "��������ϣ�\n";

        // Save the result.
        std::cout << "�Ƿ�Ҫ��ͳ�ƽ�����浽" << outputDir << "result.txt? [Y/N]" << std::endl;
        char choice;
        while ((choice = _getch()) != 'y' && choice != 'Y' && choice != 'n' && choice != 'N');
        if (choice == 'y' || choice == 'Y')
        {
            if (_access(outputDir.c_str(), 0) == -1)
                _mkdir(outputDir.c_str());

            std::ofstream fout(outputDir + "result.txt");
            fout << ans;
            fout.close();
            std::cout << "�ѱ��棡" << std::endl;
        }
    }
}