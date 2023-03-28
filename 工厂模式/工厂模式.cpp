#include <iostream>

using namespace std;

namespace _nmsp1
{
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
	//Ұ����
	//class M_Beast :public Monster { .... };
	
	//-------------------------------
	//���﹤����
//	class MonsterFactory
//	{
//	public:
//		//Monster* createMonster(string strmontype) //�򵥹���ģʽ
//		static Monster* createMonster(string strmontype) //��̬��������ģʽ��Static Factory Method��
//		{
//			Monster* prtnobj = nullptr;
//			if (strmontype == "udd") //udd����Ҫ�������������
//			{
//				prtnobj = new M_Undead(300, 50, 80);
//			}
//			else if (strmontype == "elm") //elm����Ҫ����Ԫ�������
//			{
//				prtnobj = new M_Element(200, 80, 100);
//			}
//			else if (strmontype == "mec") //mec����Ҫ������е�����
//			{
//				prtnobj = new M_Mechanic(400, 0, 110);
//			}
//			return prtnobj;
//		}
//	};	

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
			Monster *ptmp = new M_Undead(300, 50, 80); //�������������
			//�����������һЩ����ҵ�����
			//......
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
	//class M_BeastFactory:public M_ParFactory{......};
	
	//ȫ�ֵ����ڴ����������ĺ���,ע���βε������ǹ����������͵�ָ�룬���������ǹ��︸�����͵�ָ��
	Monster* Gbl_CreateMonster(M_ParFactory* factory)
	{
		return  factory->createMonster(); //createMonster�麯�������˶�̬new����Ϊ��factoryָ��ľ�����﹤���಻ͬ�������Ĺ������Ҳ��ͬ��
	}
	
	//--------------------------------- 
	//���봴��̫�๤���࣬�����װ�仯
	//�������﹤������ģ��
	template <typename T>
	class M_ChildFactory :public M_ParFactory
	{
	public:
		virtual Monster* createMonster()
		{
			return new T(300, 50, 80); //�����Ҫ��ͬ��ֵ�����ͨ��createMonster���βν�ֵ���ݽ���
		}
	};
}

namespace _nmsp2
{
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

	//�������������
	class M_Undead_Swamp :public Monster
	{
	public:
		M_Undead_Swamp(int life, int magic, int attack) :Monster(life, magic, attack)
		{
			cout << "һ�����������������������������" << endl;
		}
	};
	
	//����Ԫ�������
	class M_Element_Swamp :public Monster
	{
	public:
		M_Element_Swamp(int life, int magic, int attack) :Monster(life, magic, attack)
		{
			cout << "һ�������Ԫ��������������������" << endl;
		}
	};
	
	//�����е�����
	class M_Mechanic_Swamp :public Monster
	{
	public:
		M_Mechanic_Swamp(int life, int magic, int attack) :Monster(life, magic, attack)
		{
			cout << "һ������Ļ�е������������������" << endl;
		}
	};
	
	//--------------------------
	//ɽ�����������
	class M_Undead_Mountain :public Monster
	{
	public:
		M_Undead_Mountain(int life, int magic, int attack) :Monster(life, magic, attack)
		{
			cout << "һ��ɽ��������������������������" << endl;
		}
	};
	//ɽ��Ԫ�������
	class M_Element_Mountain :public Monster
	{
	public:
		M_Element_Mountain(int life, int magic, int attack) :Monster(life, magic, attack)
		{
			cout << "һ��ɽ����Ԫ��������������������" << endl;
		}
	};
	//ɽ����е�����
	class M_Mechanic_Mountain :public Monster
	{
	public:
		M_Mechanic_Mountain(int life, int magic, int attack) :Monster(life, magic, attack)
		{
			cout << "һ��ɽ���Ļ�е������������������" << endl;
		}
	};
	//--------------------------
	//�������������
	class M_Undead_Town :public Monster
	{
	public:
		M_Undead_Town(int life, int magic, int attack) :Monster(life, magic, attack)
		{
			cout << "һ�����������������������������" << endl;
		}
	};
	//����Ԫ�������
	class M_Element_Town :public Monster
	{
	public:
		M_Element_Town(int life, int magic, int attack) :Monster(life, magic, attack)
		{
			cout << "һ�������Ԫ��������������������" << endl;
		}
	};
	//�����е�����
	class M_Mechanic_Town :public Monster
	{
	public:
		M_Mechanic_Town(int life, int magic, int attack) :Monster(life, magic, attack)
		{
			cout << "һ������Ļ�е������������������" << endl;
		}
	};

	//--------------------------
	//���й�����ĸ���
	class M_ParFactory
	{
	public:
		virtual Monster* createMonster_Undead() = 0; //�������������
		virtual Monster* createMonster_Element() = 0; //����Ԫ�������
		virtual Monster* createMonster_Mechanic() = 0; //������е�����
		virtual ~M_ParFactory() {} //������ʱ��������Ӧ��Ϊ�麯��
	};

	//��������Ĺ���
	class M_Factory_Swamp :public M_ParFactory
	{
	public:
		virtual Monster* createMonster_Undead()
		{
			return new M_Undead_Swamp(300, 50, 120); //�����������������
		}
		virtual Monster* createMonster_Element()
		{
			return new M_Element_Swamp(200, 80, 110); //��������Ԫ�������
		}
		virtual Monster* createMonster_Mechanic()
		{
			return new M_Mechanic_Swamp(400, 0, 90); //���������е�����
		}		
	};
	//--------------------------
	//ɽ�������Ĺ���
	class M_Factory_Mountain :public M_ParFactory
	{
	public:
		virtual Monster* createMonster_Undead()
		{
			return new M_Undead_Mountain(300, 50, 80); //����ɽ�����������
		}
		virtual Monster* createMonster_Element()
		{
			return new M_Element_Mountain(200, 80, 100); //����ɽ��Ԫ�������
		}
		virtual Monster* createMonster_Mechanic()
		{
			return new M_Mechanic_Mountain(600, 0, 110); //����ɽ����е�����
		}
	};
	//--------------------------
	//����Ĺ���
	class M_Factory_Town :public M_ParFactory
	{
	public:
		virtual Monster* createMonster_Undead()
		{
			return new M_Undead_Town(300, 50, 80); //�����������������
		}
		virtual Monster* createMonster_Element()
		{
			return new M_Element_Town(200, 80, 100); //��������Ԫ�������
		}
		virtual Monster* createMonster_Mechanic()
		{
			return new M_Mechanic_Town(400, 0, 110); //���������е�����
		}
	};
}

namespace _nmsp3 
{
	//���������
	class Body
	{
	public:
		virtual void getName() = 0;
		virtual ~Body() {}
	};

	//�·�������
	class Clothes
	{
	public:
		virtual void getName() = 0;
		virtual ~Clothes() {}
	};

	//Ь�ӳ�����
	class Shoes
	{
	public:
		virtual void getName() = 0;
		virtual ~Shoes() {}
	};
	
	//---------------------------
	//���󹤳���
	class AbstractFactory
	{
	public:
		//�������Ĳ���Ӧ���ȶ��ı������������������ʺϳ��󹤳�ģʽ
		virtual Body* createBody() = 0; //��������
		virtual Clothes* createClothes() = 0; //�����·�
		virtual Shoes* createShoes() = 0; //����Ь��
		virtual ~AbstractFactory() {}
	};
	
	//---------------------------
	//�ű�������
	class BarbieDoll
	{
	public:
		//���캯��
		BarbieDoll(Body* tmpbody, Clothes* tmpclothes, Shoes* tmpshoes)
		{
			body = tmpbody;
			clothes = tmpclothes;
			shoes = tmpshoes;
		}

		void Assemble() //��װ�ű�����
		{
			cout << "�ɹ���װ��һ���ű����ޣ�" << endl;
			body->getName();
			clothes->getName();
			shoes->getName();
		}

	private:
		Body* body;
		Clothes* clothes;
		Shoes* shoes;
	};
	
	//---------------------------
	//�й�����ʵ�ֵ���������
	class China_Body :public Body
	{
	public:
		virtual void getName()
		{
			cout << "�й����̲���_���岿��" << endl;
		}
	};
	class China_Clothes :public Clothes
	{
	public:
		virtual void getName()
		{
			cout << "�й����̲���_�·�����" << endl;
		}
	};
	class China_Shoes :public Shoes
	{
	public:
		virtual void getName()
		{
			cout << "�й����̲���_Ь�Ӳ���" << endl;
		}
	};
	//����һ���й�����
	class ChinaFactory : public AbstractFactory
	{
	public:
		virtual Body* createBody()
		{
			return new China_Body;
		}
		virtual Clothes* createClothes()
		{
			return new China_Clothes;
		}
		virtual Shoes* createShoes()
		{
			return new China_Shoes;
		}		
	};
	
	//---------------------------
	//�ձ�����ʵ�ֵ���������
	class Japan_Body :public Body
	{
	public:
		virtual void getName()
		{
			cout << "�ձ����̲���_���岿��" << endl;
		}
	};
	class Japan_Clothes :public Clothes
	{
	public:
		virtual void getName()
		{
			cout << "�ձ����̲���_�·�����" << endl;
		}
	};
	class Japan_Shoes :public Shoes
	{
	public:
		virtual void getName()
		{
			cout << "�ձ����̲���_Ь�Ӳ���" << endl;
		}
	};
	//����һ���ձ�����
	class JapanFactory : public AbstractFactory
	{
	public:
		virtual Body* createBody()
		{
			return new Japan_Body;
		}
		virtual Clothes* createClothes()
		{
			return new Japan_Clothes;
		}
		virtual Shoes* createShoes()
		{
			return new Japan_Shoes;
		}
	};
	
	//---------------------------
	//��������ʵ�ֵ���������
	class America_Body :public Body
	{
	public:
		virtual void getName()
		{
			cout << "�������̲���_���岿��" << endl;
		}
	};
	class America_Clothes :public Clothes
	{
	public:
		virtual void getName()
		{
			cout << "�������̲���_�·�����" << endl;
		}
	};
	class America_Shoes :public Shoes
	{
	public:
		virtual void getName()
		{
			cout << "�������̲���_Ь�Ӳ���" << endl;
		}
	};
	//����һ����������
	class AmericaFactory : public AbstractFactory
	{
	public:
		virtual Body* createBody()
		{
			return new America_Body;
		}
		virtual Clothes* createClothes()
		{
			return new America_Clothes;
		}
		virtual Shoes* createShoes()
		{
			return new America_Shoes;
		}
	};
} 

int main() {
	
//	_nmsp1::Monster* pM1 = new _nmsp1::M_Undead(300, 50, 80); //����һֻ���������
//	_nmsp1::Monster* pM2 = new _nmsp1::M_Element(200, 80, 100); //����һֻԪ�������
//	_nmsp1::Monster* pM3 = new _nmsp1::M_Mechanic(400, 0, 110); //����һֻ��е�����
//	
//	//�ͷ���Դ
//	delete pM1;
//	delete pM2;
//	delete pM3;

//	_nmsp1::MonsterFactory facobj;
//	_nmsp1::Monster* pM1 = facobj.createMonster("udd"); //������һֻ����������Ȼ�������֪����udd��������Ǵ������������
//	_nmsp1::Monster* pM2 = facobj.createMonster("elm"); //����һֻԪ�������
//	_nmsp1::Monster* pM3 = facobj.createMonster("mec"); //����һֻ��е�����
//
//	//�ͷ���Դ
//	delete pM1;
//	delete pM2;
//	delete pM3;

	//��ʱ�򵥹���ģʽ�ֿ��Գ�Ϊ��̬��������ģʽ��Static Factory Method��
//	_nmsp1::Monster* pM1 = _nmsp1::MonsterFactory::createMonster("udd"); //������һֻ����������Ȼ�������֪����udd��������Ǵ������������
//	_nmsp1::Monster* pM2 = _nmsp1::MonsterFactory::createMonster("elm"); //����һֻԪ�������
//	_nmsp1::Monster* pM3 = _nmsp1::MonsterFactory::createMonster("mec"); //����һֻ��е�����
//
//	//�ͷ���Դ
//	delete pM1;
//	delete pM2;
//	delete pM3;

//	_nmsp1::M_ParFactory* p_ud_fy = new _nmsp1::M_UndeadFactory(); //��̬������ע��ָ������
//	_nmsp1::Monster* pM1 = _nmsp1::Gbl_CreateMonster(p_ud_fy); //������һֻ��������Ҳ�Ƕ�̬��ע�ⷵ������
//	                                                         //��Ȼ������Ҳ����ֱ��д�� Monster *pM1 = p_ud_fy->createMonster();
//
//	_nmsp1::M_ParFactory* p_elm_fy = new _nmsp1::M_ElementFactory();
//	_nmsp1::Monster *pM2 = _nmsp1::Gbl_CreateMonster(p_elm_fy); //������һֻԪ�������
//
//	_nmsp1::M_ParFactory* p_mec_fy = new _nmsp1::M_MechanicFactory();
//	_nmsp1::Monster* pM3 = _nmsp1::Gbl_CreateMonster(p_mec_fy); //������һֻ��е�����
//
//	//�ͷ���Դ
//	//�ͷŹ���
//	delete p_ud_fy;
//	delete p_elm_fy;
//	delete p_mec_fy;
//
//	//�ͷŹ���
//	delete pM1;
//	delete pM2;
//	delete pM3;
	
//	_nmsp1::M_ChildFactory<_nmsp1::M_Undead> myFactory;
//	_nmsp1::Monster* pM10 = myFactory.createMonster();

//	_nmsp2::M_ParFactory* p_mou_fy = new _nmsp2::M_Factory_Mountain(); //��̬������ɽ�������Ĺ���
//	_nmsp2::Monster* pM1 = p_mou_fy->createMonster_Element(); //����ɽ��������Ԫ�������
//
//	_nmsp2::M_ParFactory* p_twn_fy = new _nmsp2::M_Factory_Town(); //��̬����������Ĺ���
//	_nmsp2::Monster* pM2 = p_twn_fy->createMonster_Undead(); //����������������������
//	_nmsp2::Monster* pM3 = p_twn_fy->createMonster_Mechanic(); //������������Ļ�е�����
//
//	//�ͷ���Դ
//	//�ͷŹ���
//	delete p_mou_fy;
//	delete p_twn_fy;
//
//	delete pM1;
//	delete pM2;
//	delete pM3;

	//������һ���ű�����------------
	//(1)����һ���й�����
	_nmsp3::AbstractFactory* pChinaFactory = new _nmsp3::ChinaFactory();
	//(2)�����й����ĸ��ֲ���
	_nmsp3::Body* pChinaBody = pChinaFactory->createBody();
	_nmsp3::Clothes* pChinaClothes = pChinaFactory->createClothes();
	_nmsp3::Shoes* pChinaShoes = pChinaFactory->createShoes();
	//(3)�����ű�����
	_nmsp3::BarbieDoll* pbd1obj = new _nmsp3::BarbieDoll(pChinaBody, pChinaClothes, pChinaShoes);
	pbd1obj->Assemble(); //��װ�ű�����
	
	cout << "-------------------------------------" << endl;
	//�����ڶ����ű�����------------
	//(1)�������������������ձ���������������
	_nmsp3::AbstractFactory* pJapanFactory = new _nmsp3::JapanFactory();
	_nmsp3::AbstractFactory* pAmericaFactory = new _nmsp3::AmericaFactory();
	//(2)�����й��������岿�����ձ������·���������������Ь�Ӳ���
	_nmsp3::Body* pChinaBody2 = pChinaFactory->createBody();
	_nmsp3::Clothes* pJapanClothes = pJapanFactory->createClothes();
	_nmsp3::Shoes* pAmericaShoes = pAmericaFactory->createShoes();
	//(3)�����ű�����
	_nmsp3::BarbieDoll* pbd2obj = new _nmsp3::BarbieDoll(pChinaBody2, pJapanClothes, pAmericaShoes);
	pbd2obj->Assemble(); //��װ�ű�����
	
	//���ǵ��ͷ��ڴ�----------------
	delete pbd1obj;
	delete pChinaShoes;
	delete pChinaClothes;
	delete pChinaBody;
	delete pChinaFactory;
	//------------
	delete pbd2obj;
	delete pAmericaShoes;
	delete pJapanClothes;
	delete pChinaBody2;
	delete pAmericaFactory;
	delete pJapanFactory;
	
	return 0;
} 
