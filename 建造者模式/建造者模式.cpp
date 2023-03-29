#include <iostream>

using namespace std;

namespace _nmsp1 {
	//���︸��
	class Monster
	{
	public:
		virtual ~Monster() {} //������ʱ��������Ӧ��Ϊ�麯��
//		void Assemble(string strmodelno) //����:ģ�ͱ�ţ����磺��1253679201245���ȡ�ÿЩλ����϶���һЩ�ر�ĺ��壬���ﲻ��Ҫ̽����
//		{
//			LoadTrunkModel(strmodelno.substr(4, 3)); //��������ģ�ͣ���ȡĳ�����ַ����Ա�ʾ����ģ�͵ı��
//			LoadHeadModel(strmodelno.substr(7, 3)); //����ͷ��ģ�Ͳ��ҽӵ�����ģ����
//			LoadLimbsModel(strmodelno.substr(10, 3)); //������֫ģ�Ͳ��ҽӵ�����ģ����
//		}
//
//		virtual void LoadTrunkModel(string strno) = 0; //����Ҳ����д��һ���պ�������������Ƿ�����ʵ��
//		virtual void LoadHeadModel(string strno) = 0;
//		virtual void LoadLimbsModel(string strno) = 0;
	};
	
	//���������
	class M_Undead :public Monster
	{
//	public:
//		virtual void LoadTrunkModel(string strno)
//		{
//			cout << "�����������������ɲ�λģ�ͣ���Ҫ����M_Undead����丸������������Ա�������߼�������......" << endl;
//		}
//		virtual void LoadHeadModel(string strno)
//		{
//			cout << "��������������ͷ��ģ�Ͳ��ҽӵ����ɲ�λ����Ҫ����M_Undead����丸������������Ա�������߼�������......" << endl;
//		}
//		virtual void LoadLimbsModel(string strno)
//		{
//			cout << "����������������֫ģ�Ͳ��ҽӵ����ɲ�λ����Ҫ����M_Undead����丸������������Ա�������߼�������......" << endl;
//		}
	};
	
	//Ԫ�������
	class M_Element :public Monster
	{
//	public:
//		virtual void LoadTrunkModel(string strno)
//		{
//			cout << "����Ԫ�����������ɲ�λģ�ͣ���Ҫ����M_Element����丸������������Ա�������߼�������......" << endl;
//		}
//		virtual void LoadHeadModel(string strno)
//		{
//			cout << "����Ԫ��������ͷ��ģ�Ͳ��ҽӵ����ɲ�λ����Ҫ����M_Element����丸������������Ա�������߼�������......" << endl;
//		}
//		virtual void LoadLimbsModel(string strno)
//		{
//			cout << "����Ԫ����������֫ģ�Ͳ��ҽӵ����ɲ�λ����Ҫ����M_Element����丸������������Ա�������߼�������......" << endl;
//		}
	};

	//��е�����
	class M_Mechanic :public Monster
	{
//	public:
//		virtual void LoadTrunkModel(string strno)
//		{
//			cout << "�����е���������ɲ�λģ�ͣ���Ҫ����M_Mechanic����丸������������Ա�������߼�������......" << endl;
//		}
//		virtual void LoadHeadModel(string strno)
//		{
//			cout << "�����е������ͷ��ģ�Ͳ��ҽӵ����ɲ�λ����Ҫ����M_Mechanic����丸������������Ա�������߼�������......" << endl;
//		}
//		virtual void LoadLimbsModel(string strno)
//		{
//			cout << "�����е��������֫ģ�Ͳ��ҽӵ����ɲ�λ����Ҫ����M_Mechanic����丸������������Ա�������߼�������......" << endl;
//		}
	};
	
	//----------------------------
	//���ﹹ��������
	class MonsterBuilder
	{
	public:
		virtual ~MonsterBuilder() {} //������ʱ��������Ӧ��Ϊ�麯��
		//void Assemble(string strmodelno) //����:ģ�ͱ�ţ����磺��1253679201245���ȡ�ÿЩλ����϶���һЩ�ر�ĺ��壬���ﲻ��Ҫ̽����
		//{
		//	LoadTrunkModel(strmodelno.substr(4, 3)); //��������ģ�ͣ���ȡĳ�����ַ����Ա�ʾ����ģ�͵ı��
		//	LoadHeadModel(strmodelno.substr(7, 3)); //����ͷ��ģ�Ͳ��ҽӵ�����ģ����
		//	LoadLimbsModel(strmodelno.substr(10, 3)); //������֫ģ�Ͳ��ҽӵ�����ģ����
		//}

		//����ָ��Monster��ĳ�Ա����ָ��m_pMonster����һ�����ӵĶ��󹹽���ɺ󣬿���ͨ���ó�Ա�����Ѷ��󷵻ء�
		Monster* GetResult()
		{
			return m_pMonster;
		}

		virtual void LoadTrunkModel(string strno) = 0; //����Ҳ����д��һ���պ�������������Ƿ�����ʵ��
		virtual void LoadHeadModel(string strno) = 0;
		virtual void LoadLimbsModel(string strno) = 0;

	protected:
		Monster* m_pMonster; //ָ��Monster��ĳ�Ա����ָ��
	};
	
	//----------
	//��������ﹹ������
	class M_UndeadBuilder :public MonsterBuilder
	{
	public:
		M_UndeadBuilder() //���캯��
		{
			m_pMonster = new M_Undead();
		}

		virtual void LoadTrunkModel(string strno)
		{
			cout << "�����������������ɲ�λģ�ͣ���Ҫm_pMonsterָ�����M_Undead����丸������������Ա�������߼�������......" << endl;
			//����Ҫ����������ʵ��ί�и�����������ɣ�ί��ָ�ѱ����Լ�ʵ�ֵĹ���ת��������ʵ��
			//m_pMonster->......��
		}
		virtual void LoadHeadModel(string strno)
		{
			cout << "��������������ͷ��ģ�Ͳ��ҽӵ����ɲ�λ����Ҫm_pMonsterָ�����M_Undead����丸������������Ա�������߼�������......" << endl;
			//m_pMonster->......��
		}
		virtual void LoadLimbsModel(string strno)
		{
			cout << "����������������֫ģ�Ͳ��ҽӵ����ɲ�λ����Ҫm_pMonsterָ�����M_Undead����丸������������Ա�������߼�������......" << endl;
			//m_pMonster->......��
		}
	};

	//Ԫ������ﹹ������
	class M_ElementBuilder :public MonsterBuilder
	{
	public:
		M_ElementBuilder() //���캯��
		{
			m_pMonster = new M_Element();
		}

		virtual void LoadTrunkModel(string strno)
		{
			cout << "����Ԫ�����������ɲ�λģ�ͣ���Ҫm_pMonsterָ�����M_Element����丸������������Ա�������߼�������......" << endl;			
			//m_pMonster->......��
		}
		virtual void LoadHeadModel(string strno)
		{
			cout << "����Ԫ��������ͷ��ģ�Ͳ��ҽӵ����ɲ�λ����Ҫm_pMonsterָ�����M_Element����丸������������Ա�������߼�������......" << endl;
			//m_pMonster->......��
		}
		virtual void LoadLimbsModel(string strno)
		{
			cout << "����Ԫ����������֫ģ�Ͳ��ҽӵ����ɲ�λ����Ҫm_pMonsterָ�����M_Element����丸������������Ա�������߼�������......" << endl;
			//m_pMonster->......��
		}
	};

	//��е����ﹹ������
	class M_MechanicBuilder :public MonsterBuilder
	{
	public:
		M_MechanicBuilder() //���캯��
		{
			m_pMonster = new M_Mechanic();
		}

		virtual void LoadTrunkModel(string strno)
		{
			cout << "�����е���������ɲ�λģ�ͣ���Ҫm_pMonsterָ�����M_Mechanic����丸������������Ա�������߼�������......" << endl;
			//m_pMonster->......��
		}
		virtual void LoadHeadModel(string strno)
		{
			cout << "�����е������ͷ��ģ�Ͳ��ҽӵ����ɲ�λ����Ҫm_pMonsterָ�����M_Mechanic����丸������������Ա�������߼�������......" << endl;
			//m_pMonster->......��
		}
		virtual void LoadLimbsModel(string strno)
		{
			cout << "�����е��������֫ģ�Ͳ��ҽӵ����ɲ�λ����Ҫm_pMonsterָ�����M_Mechanic����丸������������Ա�������߼�������......" << endl;
			//m_pMonster->......��
		}
	};
	
	//------------------
	//ָ������
	class MonsterDirector
	{
	public:
		MonsterDirector(MonsterBuilder* ptmpBuilder) //���캯��
		{
			m_pMonsterBuilder = ptmpBuilder;
		}

		//ָ���µĹ�����
		void SetBuilder(MonsterBuilder* ptmpBuilder)
		{
			m_pMonsterBuilder = ptmpBuilder;
		}

		//ԭMonsterBuilder���е�Assemble��Ա����
		Monster *Construct(string strmodelno) //����:ģ�ͱ�ţ����磺��1253679201245���ȡ�ÿЩλ����϶���һЩ�ر�ĺ��壬���ﲻ��Ҫ̽����
		{
			m_pMonsterBuilder->LoadTrunkModel(strmodelno.substr(4, 3)); //��������ģ�ͣ���ȡĳ�����ַ����Ա�ʾ����ģ�͵ı��
			m_pMonsterBuilder->LoadHeadModel(strmodelno.substr(7, 3)); //����ͷ��ģ�Ͳ��ҽӵ�����ģ����
			m_pMonsterBuilder->LoadLimbsModel(strmodelno.substr(10, 3)); //������֫ģ�Ͳ��ҽӵ�����ģ����
			return m_pMonsterBuilder->GetResult(); //���ع�����Ķ���
		}
	private:
		MonsterBuilder* m_pMonsterBuilder; //ָ�����й�������ĸ���
	};
}

int main() {
//	_nmsp1::Monster* pmonster = new _nmsp1::M_Element(); //����һֻԪ�������
//	pmonster->Assemble("1253679201254");
//
//	//�ͷ���Դ
//	delete pmonster;
	
	_nmsp1::MonsterBuilder* pMonsterBuilder = new _nmsp1::M_UndeadBuilder(); //������������ﹹ��������
	_nmsp1::MonsterDirector* pDirector = new _nmsp1::MonsterDirector(pMonsterBuilder); 
	_nmsp1::Monster* pMonster = pDirector->Construct("1253679201254"); //����͹�������һ�������Ĺ������

	//�ͷ���Դ
	delete pMonster;
	delete pDirector;
	delete pMonsterBuilder;
	
	return 0;
}

