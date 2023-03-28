#include <iostream>

using namespace std;

namespace _nmsp1
{
	//��������ģʽ(����ŵ��������Ƚ�)----------------------------------------
	//���︸��
	class Monster
	{
	public:
		//���캯��
		Monster(int life, int magic, int attack) :m_life(life), m_magic(magic), m_attack(attack) {}
		virtual ~Monster() {} //������ʱ��������Ӧ��Ϊ�麯��

	protected://���ܱ�������ʵĳ�Ա��������protected����
		//��������
		int m_life; //����ֵ
		int m_magic; //ħ��ֵ
		int m_attack; //������
	};
	//���������
	class M_Undead :public Monster
	{
	public:
		//���캯��
		M_Undead(int life, int magic, int attack) :Monster(life, magic, attack)
		{
			cout << "һ������������������������" << endl;
		}
		//����������......
	};
	//Ԫ�������
	class M_Element :public Monster
	{
	public:
		//���캯��
		M_Element(int life, int magic, int attack) :Monster(life, magic, attack)
		{
			cout << "һ��Ԫ��������������������" << endl;
		}
		//����������......
	};
	//��е�����
	class M_Mechanic :public Monster
	{
	public:
		//���캯��
		M_Mechanic(int life, int magic, int attack) :Monster(life, magic, attack)
		{
			cout << "һ����е������������������" << endl;
		}
		//����������......
	};
		
	//���й�����ĸ���
	class M_ParFactory
	{
	public:
		virtual Monster* createMonster() = 0; //�����ʵ���������н���
		virtual ~M_ParFactory() {} //������ʱ��������Ӧ��Ϊ�麯��
	};
	//M_Undead�������͵Ĺ���������M_Undead���͹���
	class M_UndeadFactory : public M_ParFactory
	{
	public:
		virtual Monster* createMonster()
		{
			//return  new M_Undead(300, 50, 80); //�������������
			Monster* ptmp = new M_Undead(300, 50, 80); //�������������
			//�����������һЩ����ҵ�����
			//......
			return ptmp;
		}
	};

	//M_Element�������͵Ĺ���������M_Element���͹���
	class M_ElementFactory : public M_ParFactory
	{
	public:
		virtual Monster* createMonster()
		{
			return  new M_Element(200, 80, 100); //����Ԫ�������
		}
	};

	//M_Mechanic�������͵Ĺ���������M_Mechanic���͹���
	class M_MechanicFactory : public M_ParFactory
	{
	public:
		virtual Monster* createMonster()
		{
			return  new M_Mechanic(400, 0, 110); //������е�����
		}
	};
}

namespace _nmsp2 {
	//���︸��
	class Monster
	{
	public:
		//���캯��
		Monster(int life, int magic, int attack) :m_life(life), m_magic(magic), m_attack(attack) {}
		virtual ~Monster() {} //������ʱ�鹹����Ӧ��Ϊ�麯��

	public:
		virtual Monster* clone() = 0; //�����ʵ���������н���

//	public:
//		void setlife(int tmplife)
//		{
//			m_life = tmplife;
//		}
	protected: //���ܱ�������ʵĳ�Ա��������protected����
//	public:
		//��������
		int m_life;  //����ֵ
		int m_magic; //ħ��ֵ
		int m_attack;  //������
	};
	
	//���������
	class M_Undead :public Monster
	{
	public:
		//���캯��
		M_Undead(int life, int magic, int attack) :Monster(life, magic, attack)
		{
			cout << "һֻ����������������������" << endl;
		}
		
		//�������캯��
		//..........��������Լ�д

		virtual Monster* clone()
		{
			//return new M_Undead(300, 50, 80); //�������������
			return new M_Undead(*this); //�����������캯���ĵ������������������
			
			
//			Monster * pmonster = new M_Undead(300, 50, 80); //�������������
//			//pmonster->m_life = m_life;
//			pmonster->setlife(m_life);
//			pmonster->m_magic = m_magic;
//			pmonster->m_attack = m_attack;
//			return pmonster;
		}
		//...����������
	};
	
	//Ԫ�������
	class M_Element :public Monster
	{
	public:
		//���캯��
		M_Element(int life, int magic, int attack) :Monster(life, magic, attack)
		{
			cout << "һֻԪ��������������������" << endl;
		}
		
		//�������캯��
		M_Element(const M_Element& tmpobj) :Monster(tmpobj) //��ʼ���б���ע��Ը����Ӷ���ĳ�ʼ��
		{
			cout << "������M_Element::M_Element(const M_Element& tmpobj)�������캯��������һֻԪ�������" << endl;
		}

		virtual Monster* clone()
		{
			//return new M_Element(200, 80, 100); //����Ԫ�������
			return new M_Element(*this);
		}
		//...����������
	};
	
	//��е�����
	class M_Mechanic :public Monster
	{
	public:
		//���캯��
		M_Mechanic(int life, int magic, int attack) :Monster(life, magic, attack)
		{
			cout << "һֻ��е������������������" << endl;
		}
		
		//�������캯��
		M_Mechanic(const M_Mechanic& tmpobj) :Monster(tmpobj) //��ʼ���б���ע��Ը����Ӷ���ĳ�ʼ��
		{
			cout << "������M_Mechanic::M_Mechanic(const M_Mechanic& tmpobj)�������캯��������һֻ��е�����" << endl;
		}

		virtual Monster* clone()
		{
			//return new M_Mechanic(400, 0, 110); //������е�����
			return new M_Mechanic(*this);
		}
		//...����������
	};
	
//	//ȫ�ֵ����ڴ����������ĺ���
//	void Gbl_CreateMonster2(Monster* pMonster)
//	{
//		Monster* ptmpobj = nullptr;
//		if (dynamic_cast<M_Undead*>(pMonster) != nullptr)
//		{
//			ptmpobj = new M_Undead(300, 50, 80); //�������������
//		}
//		else if (dynamic_cast<M_Element*>(pMonster) != nullptr)
//		{
//			ptmpobj = new M_Element(200,80, 100); //����Ԫ�������
//		}
//		else if (dynamic_cast<M_Mechanic*>(pMonster) != nullptr)
//		{
//			ptmpobj = new M_Mechanic(400, 0, 110); //������е�����
//		}
//		if (ptmpobj != nullptr)
//		{
//			//����Ϳ������ptmpobj����ʵ�ָ���ҵ���߼�
//			//......
//			//��Ҫ�����ͷ���Դ
//			delete ptmpobj;
//		}
//	}

	void Gbl_CreateMonster2(Monster* pMonster)
	{
		Monster* ptmpobj = pMonster->clone(); //�������ж���ֱ�Ӵ����¶��󣬲���Ҫ֪�����ж�������������
		//����Ϳ������ptmpobj����ʵ�ָ���ҵ���߼�
			//......
			//��Ҫ�����ͷ���Դ
		delete ptmpobj;
	}

}

int main() {
	
//	_nmsp2::M_Mechanic myPropMecMonster(400, 0, 110); //����һֻ��е����������Ϊԭ�Ͷ��������ڿ�¡Ŀ��
//	_nmsp2::Monster* pmyPropEleMonster = new _nmsp2::M_Element(200, 80, 100); //����һֻԪ������������Ϊԭ�Ͷ��������ڿ�¡Ŀ�ģ�
//	                  //�������ֱ��new��Ҳ����ͨ������ģʽ����ԭ�Ͷ���ȡ���ڳ���Ա�Լ���ϴ�á�
//	//.....
//	_nmsp2::Monster* p_CloneObj1 = myPropMecMonster.clone(); //ʹ��ԭ�Ͷ����¡���µĻ�е��������
//	_nmsp2::Monster* p_CloneObj2 = pmyPropEleMonster->clone(); //ʹ��ԭ�Ͷ����¡���µ�Ԫ����������
//
//	//���Զ�p_CloneObj1��p_CloneObj2��ָ��Ķ�����и��ֲ�����ʵ�־����ҵ���߼���
//	//......
//
//	//�ͷ���Դ
//	//�ͷſ�¡�����Ĺ������
//	delete p_CloneObj1;
//	delete p_CloneObj2;
//
//	//�ͷ�ԭ�Ͷ��󣨶��еģ�
//	delete pmyPropEleMonster;
	
	_nmsp2::Monster* pMonsterObj = new _nmsp2::M_Element(200, 80, 100);
	_nmsp2::Gbl_CreateMonster2(pMonsterObj);
	delete pMonsterObj;
	return 0;
} 
