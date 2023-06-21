#pragma once
#include"../data_structure/AdjListWUndirGraph.h"

namespace S2
{
    template<class VertTy, class WeightTy, WeightTy infinity>
    void InsertVertex(AdjListWUndirGraph<VertTy, WeightTy, infinity>& g, const VertTy& vert)
    {
        try {
            g.insertVertex(vert);
            std::cout << "����ɹ���" << std::endl;
        } catch (VertexAlreadyExists) {
            std::cout << "�ö����Ѵ��ڣ��޷�����" << std::endl;
        }
    }

    template<class VertTy, class WeightTy, WeightTy infinity>
    void EraseVertex(AdjListWUndirGraph<VertTy, WeightTy, infinity>& g, const VertTy& vert) {
        try {
            g.eraseVertex(vert);
            std::cout << "ɾ���ɹ���" << std::endl;
        } catch (VertexNotFound) {
            std::cout << "�ö��㲻����" << std::endl;
        }
    }

    template<class VertTy, class WeightTy, WeightTy infinity>
    void InsertEdge(AdjListWUndirGraph<VertTy, WeightTy, infinity>& g, const VertTy& from, const VertTy& to, const WeightTy& weight) {
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
    void EraseEdge(AdjListWUndirGraph<VertTy, WeightTy, infinity>& g, const VertTy& from, const VertTy& to) {
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
    void Degree(const AdjListWUndirGraph<VertTy, WeightTy, infinity>& g, const VertTy& vert) {
        std::ostringstream ss;
        try {
            ss << "\n������" << g.degree(vert) << "\n";
            std::cout << ss.str();
        } catch (VertexNotFound) {
            std::cout << "�ö��㲻����" << std::endl;
        }
    }

    template<class VertTy, class WeightTy, WeightTy infinity>
    void ConnectedComponent(const AdjListWUndirGraph<VertTy, WeightTy, infinity>& g) {
        if (g.connected()) {
            std::cout << "��ͼ����ͨͼ\n";
        } else {
            std::cout << "��ͼ������ͨͼ\n";
        }
        std::cout << "��ͨ��������" << g.numOfConnectedComponent() << std::endl;
    }

    template<class VertTy, class WeightTy, WeightTy infinity>
    void MinimumSpanningTree(const AdjListWUndirGraph<VertTy, WeightTy, infinity>& g) {
        if (g.hasUniqueMST()) {
            std::cout << "��ͼ��Ψһ��С������" << std::endl;
        } else {
            std::cout << "��ͼ�ж����С������" << std::endl;
        }
        std::cout << "-----------\n";
        std::cout << "| Kruskal |\n";
        std::cout << "-----------" << std::endl;

        std::cout << "--------\n";
        std::cout << "| Prim |\n";
        std::cout << "--------" << std::endl;

        std::cout << "------------------\n";
        std::cout << "| Reverse-Delete |\n";
        std::cout << "------------------" << std::endl;
    }
}
