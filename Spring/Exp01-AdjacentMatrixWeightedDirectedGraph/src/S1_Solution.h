#pragma once
#include <iostream>
#include <format>
#include "AdjMatWDirGraph.h"

namespace Spring01
{
    template<class VertTy, class WeightTy, WeightTy infinity>
    void InsertVertex(MyDS::AdjMatWDirGraph<VertTy, WeightTy, infinity>& g, const VertTy& vert)
    {
        try
        {
            g.InsertVertex(vert);
            std::cout << "����ɹ���" << std::endl;
        }
        catch (VertexAlreadyExists)
        {
            std::cout << "�ö����Ѵ��ڣ��޷�����" << std::endl;
        }
    }

    template<class VertTy, class WeightTy, WeightTy infinity>
    void EraseVertex(MyDS::AdjMatWDirGraph<VertTy, WeightTy, infinity>& g, const VertTy& vert)
    {
        try
        {
            g.EraseVertex(vert);
            std::cout << "ɾ���ɹ���" << std::endl;
        }
        catch (VertexNotFound)
        {
            std::cout << "�ö��㲻����" << std::endl;
        }
    }

    template<class VertTy, class WeightTy, WeightTy infinity>
    void InsertEdge(MyDS::AdjMatWDirGraph<VertTy, WeightTy, infinity>& g, const VertTy& from, const VertTy& to, const WeightTy& weight)
    {
        try 
        {
            g.InsertEdge(from, to, weight);
            std::cout << "����ɹ���" << std::endl;
        }
        catch (IllegalParameterValue)
        {
            std::cout << "������յ���ͬ���޷�����" << std::endl;
        }
        catch (VertexNotFound)
        {
            std::cout << "���㲻���ڣ��޷�����" << std::endl;
        }
        catch (EdgeAlreadyExists)
        {
            std::cout << "�ñ��Ѵ��ڣ��޷�����" << std::endl;
        }
    }

    template<class VertTy, class WeightTy, WeightTy infinity>
    void EraseEdge(MyDS::AdjMatWDirGraph<VertTy, WeightTy, infinity>& g, const VertTy& from, const VertTy& to)
    {
        try
        {
            g.EraseEdge(from, to);
            std::cout << "ɾ���ɹ���" << std::endl;
        }
        catch (VertexNotFound)
        {
            std::cout << "���㲻���ڣ��޷�ɾ��" << std::endl;
        }
        catch (EdgeNotFound)
        {
            std::cout << "�ñ߲�����" << std::endl;
        }
    }

    template<class VertTy, class WeightTy, WeightTy infinity>
    void Degree(const MyDS::AdjMatWDirGraph<VertTy, WeightTy, infinity>& g, const VertTy& vert)
    {
        try
        {
            std::string result = std::format("�ܶ�����{0}\n��ȣ�{1} ���ȣ�{2}",
                    g.GetDegree(vert), g.GetInDegree(vert), g.GetOutDegree(vert));
            std::cout << result << std::endl;
        }
        catch (VertexNotFound)
        {
            std::cout << "�ö��㲻����" << std::endl;
        }
    }

    template<class VertTy, class WeightTy, WeightTy infinity>
    void ShortestPath(const MyDS::AdjMatWDirGraph<VertTy, WeightTy, infinity>& g, const VertTy& source, const VertTy& end) {
        std::cout << "------------\n";
        std::cout << "| Dijkstra |\n";
        std::cout << "------------" << std::endl;
        try
        {
            Algorithm::Dijkstra(g, source, end);
        }
        catch (VertexNotFound)
        {
            std::cout << "���㲻����\n";
        }
        catch (NegativeEdge)
        {
            std::cout << "����Ȩ�ߣ��޷�ʹ��Dijkstra�㷨\n";
        }
        std::cout << std::endl;

        std::cout << "----------------\n";
        std::cout << "| Bellman-Ford |\n";
        std::cout << "----------------" << std::endl;
        try
        {
            Algorithm::BellmanFord(g, source, end);
        }
        catch (VertexNotFound)
        {
            std::cout << "���㲻����\n";
        }
        catch (NegativeCycle)
        {
            std::cout << "����Ȩ��·���޷��������·��\n";
        }
        std::cout << std::endl;

        std::cout << "------------------\n";
        std::cout << "| Floyd-Warshall |\n";
        std::cout << "------------------" << std::endl;
        try
        {
            Algorithm::FloydWarshall(g, source, end);
        }
        catch (VertexNotFound)
        {
            std::cout << "���㲻����" << std::endl;
        }
        catch (NegativeCycle)
        {
            std::cout << "����Ȩ��·���޷��������·��" << std::endl;
        }
    }
}
