
#include <iostream>
#include <iomanip>
#include <queue>

using namespace std;

// �ض���߽ڵ㣬���ڲ���
typedef struct ArcNode *Position;

/* �߽ڵ�
 * ����Ԫ��:
 * AdjName:������ߵ�β���
 * Weight:������ߵ�Ȩ��
 * Next:������ߵ�ͷ�������������
 */
struct ArcNode {
	int AdjName;
	int Weight;
	Position Next;

};

/* �߽ڵ�:������KrusKal�㷨��
 * ����Ԫ��:
 * Vex1:������ߵĽڵ�
 * Vex2:������ߵ���һ���ڵ�
 * Weight:������ߵ�Ȩ��
 */
struct Edge {
	int Vex1;
	int Vex2;
	int Weight;

	// ���ء�<�����ţ�����KrusKal�㷨
	friend bool operator < (const Edge &a, const Edge &b) {
		return a.Weight > b.Weight;
	}
};

/* ����ڵ�
 * ����Ԫ��:
 * Name:�ö��������
 * FirstArc:�Ըö���Ϊͷ���ĵ�һ�������
 */
struct VexNode {
	int Name;
	Position FirstArc;
};

/* ��ڵ�
 * ����Ԫ��:
 * Known:�ýڵ��״̬
 * Dist:�ýڵ��ָ���ڵ�ľ���
 * Path:ָ��ýڵ�Ľڵ�
 */
struct TableNode {
	bool Known;
	int Dist;
	int Path;
};

/* ALGraph��
 * �ӿ�:
 * Display:չʾ���ܣ�չʾ������е���Ϣ
 * MakeEmpty:���ù��ܣ����ø�ͼ�е����б�
 * Creat:�������ܣ���ͼ�й�����
 * KrusKal:KrusKal�㷨����ͼ��Ѱ����С������
 * Prim:Prim�㷨����ͼ��Ѱ����С������
 */

class ALGraph
{
public:
	// ���캯��
	ALGraph(int = 10);
	// ��������
	~ALGraph();

//--------- �ӿں���------------

	// ��������
	void Display();
	void MakeEmpty();
	void Creat();

	// ��С����������
	void KrusKal();
	void Prim();

//-------------------------------

private:
	// ��������
	void InitTable();

	// ���ݳ�Ա
	int VexNum; // ���涥����
	int ArcNum; // �������
	VexNode *AdjList; // �����ڽӱ�
	TableNode *Table; // ��������
	priority_queue <Edge> H; // �������ȶ��У�����KrusKal�㷨��
};


/* ���캯��:��ʼ������
 * ����ֵ:��
 * ����:vnum:ͼ�еĶ�����
 */
ALGraph::ALGraph(int vnum)
: VexNum(vnum), ArcNum(0){
	// �����ڽӱ���ռ�
	AdjList = new VexNode[VexNum + 1];
	// ����������ռ�
	Table = new TableNode[VexNum + 1];

	// �ж��Ƿ�����ɹ�
	if (AdjList == NULL || Table == NULL) {
		cout << "�ڽӱ�����ʧ��!" << endl;
		return;
	}

	// ��ʼ���ڽӱ��Լ������
	for (int i = 0; i < VexNum + 1; i++) {
		AdjList[i].FirstArc = NULL;
		AdjList[i].Name = i;
		Table[i].Dist = INT_MAX;
		Table[i].Known = false;
		Table[i].Path = 0;
	}
}

/* ��������:��������ʱ���մ���ռ�
 * ����ֵ:��
 * ����:��
 */
ALGraph::~ALGraph()
{
	// �������еı�
	MakeEmpty();

	// ɾ���ڽӱ�
	delete AdjList;
	AdjList = NULL;

	// ɾ�������
	delete Table;
	Table = NULL;
}

/* ���ú���:�������еı�
 * ����ֵ:��
 * ����:��
 */
void ALGraph::MakeEmpty() {
	// ��ʱ�����м�ڵ�
	Position P;

	// �����ڽӱ�
	for (int i = 1; i < VexNum + 1; i++) {
		P = AdjList[i].FirstArc;

		// �����������ӵı�
		while (P != NULL) {
			AdjList[i].FirstArc = P->Next;
			delete P;
			P = AdjList[i].FirstArc;
		}
	}

	// ������ʼ��
	ArcNum = 0;
}

/* ��������:��ͼ�й��������
 * ����ֵ:��
 * ����:��
 */
void ALGraph::Creat() {
	int tmp; // �������
	cout << "������Ҫ�������������: ";
	cin >> tmp;
	ArcNum += tmp;

	// �������е������
	for (int i = 0; i < tmp; i++) {
		// v:�ߵĶ���
		// w:�ߵ���һ������
		// weight:�ߵ�Ȩ��
		int v, w, weight;
		cout << "������Ҫ����������ߣ�v, w��: ";
		cin >> v >> w;
		cout << "�����������ߵ�Ȩ��: ";
		cin >> weight;

		// ����һ�������
		Position P1 = new ArcNode();
		P1->AdjName = w;
		P1->Weight = weight;
		P1->Next = AdjList[v].FirstArc;
		AdjList[v].FirstArc = P1;

		// ������һ�������
		Position P2 = new ArcNode();
		P2->AdjName = v;
		P2->Weight = weight;
		P2->Next = AdjList[w].FirstArc;
		AdjList[w].FirstArc = P2;

		// ����һ������ߣ�����KrusKal�㷨��
		Edge E;
		E.Vex1 = v;
		E.Vex2 = w;
		E.Weight = weight;

		// ���������ѹ�����ȶ���
		H.push(E);
	}
}

/* ��ʼ������:��ʼ�������
 * ����ֵ:��
 * ����:��
 */
void ALGraph::InitTable() {
	// �������еľ����
	for (int i = 0; i < VexNum + 1; i++) {
		// ��ʼ������
		Table[i].Dist = INT_MAX;
		Table[i].Known = false;
		Table[i].Path = 0;
	}
}

/* չʾ����:չʾ������е���Ϣ
 * ����ֵ:��
 * ����:��
 */
void ALGraph::Display() {
	// �������еľ����
	cout << "�ڵ�----->�ڵ�------����"<<endl;// << i << " ,   ����: " << Table[i].Dist << " ,   ·��: " << Table[i].Path << endl;
	for (int i = 1; i <VexNum; i++) {
		cout<<i<<"----->"<<Table[i].Path<<"-----"<<Table[i].Dist<<endl;
	}
}


/* Prim�㷨:Ѱ����С������
 * ����ֵ:��
 * ����:��
 */
void ALGraph::Prim() {
	// v:һ������ߵĶ���
	// w:һ������ߵ���һ������
	// counter:��������ͳ�Ʊ���
	// P:����߽ڵ�
	int v, w, counter;
	Position P;

	// ��ʼ���������ѡȡ��ʼ�ڵ�
	InitTable();
	v = 1;
	counter = 1;
	Table[v].Dist = 0;
	Table[v].Known = true;

	// һֱѰ�ң�ֱ������Ϊ:VexNum - 1
	while (counter != VexNum) {
		// ��ȡ�߽ڵ�
		P = AdjList[v].FirstArc;

		// ������ýڵ����������
		while (P != NULL) {
			w = P->AdjName;
			// �ж��Ƿ���Ҫ���¾������Ϣ
			if (Table[w].Known == false && Table[w].Dist > P->Weight) {
				Table[w].Dist = P->Weight;
				Table[w].Path = v;
			}
			// ָ����һ�������
			P = P->Next;
		}

		// Ѱ�Ҳ�����Ȧ��Ȩ����С�������
		int Min = INT_MAX;
		for (int i = 1; i < VexNum + 1; i++) {
			if (Table[i].Known == false && Min > Table[i].Dist) {
				v = i;
				Min = Table[i].Dist;
			}
		}

		// ���Ӹ�����ߣ�����������
		Table[v].Known = true;
		counter++;
	}
}


int main()
{
	ALGraph A(7);
	A.Creat();


	A.Prim();
	A.Display();

    return 0;
}
