#pragma once
#include<iostream>
#include<sstream>
#include"../data_structure/AdjMatWDirGraph.h"

namespace S1
{
    template<class VertTy, class WeightTy, WeightTy infinity>
    void InsertVertex(AdjMatWDirGraph<VertTy, WeightTy, infinity>& g, const VertTy& vert) {
        try {
            g.insertVertex(vert);
            std::cout << "����ɹ���" << std::endl;
        } catch (VertexAlreadyExists) {
            std::cout << "�ö����Ѵ��ڣ��޷�����" << std::endl;
        }
    }

    template<class VertTy, class WeightTy, WeightTy infinity>
    void EraseVertex(AdjMatWDirGraph<VertTy, WeightTy, infinity>& g, const VertTy& vert) {
        try {
            g.eraseVertex(vert);
            std::cout << "ɾ���ɹ���" << std::endl;
        } catch (VertexNotFound) {
            std::cout << "�ö��㲻����" << std::endl;
        }
    }

    template<class VertTy, class WeightTy, WeightTy infinity>
    void InsertEdge(AdjMatWDirGraph<VertTy, WeightTy, infinity>& g, const VertTy& from, const VertTy& to, const WeightTy& weight) {
        try {
            g.insertEdge(from, to, weight);
            std::cout << "����ɹ���" << std::endl;
        } catch (IllegalParameterValue) {
            std::cout << "������յ���ͬ���޷�����" << std::endl;
        } catch (VertexNotFound) {
            std::cout << "���㲻���ڣ��޷�����" << std::endl;
        } catch (EdgeAlreadyExists) {
            std::cout << "�ñ��Ѵ��ڣ��޷�����" << std::endl;
        }
    }

    template<class VertTy, class WeightTy, WeightTy infinity>
    void EraseEdge(AdjMatWDirGraph<VertTy, WeightTy, infinity>& g, const VertTy& from, const VertTy& to) {
        try {
            g.eraseEdge(from, to);
            std::cout << "ɾ���ɹ���" << std::endl;
        } catch (VertexNotFound) {
            std::cout << "���㲻���ڣ��޷�ɾ��" << std::endl;
        } catch (EdgeNotFound) {
            std::cout << "�ñ߲�����" << std::endl;
        }
    }

    template<class VertTy, class WeightTy, WeightTy infinity>
    void Degree(const AdjMatWDirGraph<VertTy, WeightTy, infinity>& g, const VertTy& vert) {
        std::ostringstream ss;
        try {
            ss << "\n�ܶ�����" << g.degree(vert) << "\n"
                << "��ȣ�" << g.inDegree(vert) << " ���ȣ�" << g.outDegree(vert) << std::endl;
            std::cout << ss.str();
        } catch (VertexNotFound) {
            std::cout << "�ö��㲻����" << std::endl;
        }
    }
    template<class VertTy, class WeightTy, WeightTy infinity>
    void ShortestPath(const AdjMatWDirGraph<VertTy, WeightTy, infinity>& g, const VertTy& vert) {
        std::cout << "------------\n";
        std::cout << "| Dijkstra |\n";
        std::cout << "------------" << std::endl;
        try {
            ShortestPath::Dijkstra(g, vert);
        } catch (VertexNotFound) {
            std::cout << "�ö��㲻����" << std::endl;
        } catch (NegativeEdge) {
            std::cout << "����Ȩ�ߣ��޷�ʹ��Dijkstra�㷨" << std::endl;
        }
        std::cout << std::endl;

        std::cout << "----------------\n";
        std::cout << "| Bellman-Ford |\n";
        std::cout << "----------------" << std::endl;
        try {
            ShortestPath::BellmanFord(g, vert);
        } catch (VertexNotFound) {
            std::cout << "�ö��㲻����" << std::endl;
        } catch (NegativeCycle) {
            std::cout << "����Ȩ��·" << std::endl;
        }
        std::cout << std::endl;

        std::cout << "------------------\n";
        std::cout << "| Floyd-Warshall |\n";
        std::cout << "------------------" << std::endl;
        try {
            ShortestPath::FloydWarshall(g);
        } catch (NegativeCycle) {
            std::cout << "����Ȩ��·" << std::endl;
        }
    }
}
