#include <iostream>

using namespace std;

namespace _nmsp1
{
	// ����һ����սʿ����
	class Warrior
	{
	public:
		// ���캯��
		Warrior(int life, int magic, int attack) : m_life(life), m_magic(magic), m_attack(attack)
		{
		}
		//...һЩ������Ա����,����Ҫ�����

	public:
		void JN_Burn() // ���ܡ�ȼ�ա�
		{
			cout << "�����е���ÿ��ʧȥ500������������߼�����������......" << endl;
			cout << "��������ʧȥ300������ֵ" << endl;
			m_life -= 300;
			cout << "���ż���\"ȼ��\"�ļ�����Ч����ҿ�" << endl;
		}

	private:
		// ��ɫ����
		int m_life;	  // ����ֵ
		int m_magic;  // ħ��ֵ
		int m_attack; // ������
	};

}

namespace _nmsp2
{
	// ս���߸���
	class Fighter
	{
		public: 
		Fighter(int life, int magic, int attack) : m_life(life), m_magic(magic), m_attack(attack) {}
		virtual ~Fighter() {} // ������ʱ��������Ӧ��Ϊ�麯��

		// ��������������Ӱ�죬�Ե��˻����Ӱ�졣
		// �������Ե��˲���Ӱ�죬�к���effect_enemy���������������Ӱ�죬�к���effect_self�����ż���play_effect������
		void JN_Burn() // ���ܡ�ȼ�ա�
		{
			if (canUseJN() == false) //�������ʹ�øü��ܣ���ֱ�ӷ���
				return; 
			effect_enemy(); // �Ե��˲�����Ӱ��
			effect_self();	// ���������������Ӱ��
			play_effect();	// ���ż��ܡ�ȼ�ա��ļ�����Ч
		}

	private:
		virtual void effect_enemy() {} // ������Ϊ�գ���ʾɶҲ���������Ҫ�����������������ʵ�ָ��麯��������Խ��ú���д�ɴ��麯����
		virtual void effect_self() {}
		void play_effect()
		{
			cout << "���ż���\"ȼ��\"�ļ�����Ч����ҿ�" << endl; // �������ǲ��ŵļ�����Ч����ͬ����˲���д��һ���麯������������ʵ�ּ�����Ч�Ĳ��š�
		}
		virtual bool canUseJN() = 0; //�ж��Ƿ���ʹ�ü��ܡ�ȼ�ա������Ǹ����麯�������������б�������ʵ��canUseJN��

	protected: // ���ܱ�������ʣ�������protected����
		// ��ɫ����
		int m_life;	  // ����ֵ
		int m_magic;  // ħ��ֵ
		int m_attack; // ������
	};

	//-------------------------
	// ��սʿ���࣬����ΪFighter
	class F_Warrior : public Fighter
	{
	public:
		F_Warrior(int life, int magic, int attack) : Fighter(life, magic, attack) {}

	private:
		// �Ե��˲�����Ӱ��
		virtual void effect_enemy()
		{
			cout << "սʿ����_�����е���ÿ��ʧȥ500������������߼�����������......" << endl;
		}
		// ���������������Ӱ��
		virtual void effect_self()
		{
			cout << "սʿ����_����ʧȥ300������ֵ" << endl;
			m_life -= 300;
		}
		virtual bool canUseJN()
		{
			if (m_life < 300) //����ֵ����300�㣬����ʹ�ü��ܡ�ȼ�ա�
				return false;
			return true;
		}
	};
	//-------------------------
	// ����ʦ���࣬����ΪFighter
	class F_Mage : public Fighter
	{
	public:
		F_Mage(int life, int magic, int attack) : Fighter(life, magic, attack) {}

	private:
		// �Ե��˲�����Ӱ��
		virtual void effect_enemy()
		{
			cout << "��ʦ����_�����е���ÿ��ʧȥ650������������߼�����������......" << endl;
		}
		// ���������������Ӱ��
		virtual void effect_self()
		{
			cout << "��ʦ����_����ʧȥ100��ħ��ֵ" << endl;
			m_magic -= 100;
		}
		virtual bool canUseJN()
		{
			if (m_magic < 100) //ħ��ֵ����100�㣬����ʹ�ü��ܡ�ȼ�ա�
				return false;
			return true;
		}
	};
}

int main()
{
	// _nmsp1::Warrior mroleobj(1000, 0, 200); //��������
	// mroleobj.JN_Burn(); //�����ͷš�ȼ�ա�����

//	_nmsp2::Fighter *prole_war = new _nmsp2::F_Warrior(1000, 0, 200); // ����սʿ���ǣ�ע�������Ǹ���ָ��ָ��������������ö�̬���ԡ�
//	prole_war->JN_Burn();	// սʿ�����ͷš�ȼ�ա����ܣ����õ���F_Warrior���effect_enemy��effect_self��
//
//	cout << "---------------------------" << endl;					// �ָ��ߣ��Ա����Ŀ����ʾ��Ϣ
//	_nmsp2::Fighter *prole_mag = new _nmsp2::F_Mage(800, 200, 300); // ������ʦ���ǣ�ע�������Ǹ���ָ��ָ��������������ö�̬���ԡ�
//	prole_mag->JN_Burn();											// ��ʦ�����ͷš�ȼ�ա�����
//
//	// �ͷ���Դ
//	delete prole_war;
//	delete prole_mag;
	
//	//���
//	_nmsp2::F_Warrior role_war(1000, 0, 200);
//	role_war.JN_Burn(); //���
	
	_nmsp2::Fighter* prole_war2 = new _nmsp2::F_Warrior(50, 0, 200);//��������ֵֻ��50��սʿ����
	prole_war2->JN_Burn(); //��սʿ�޷��ɹ��ͷš�ȼ�ա����ܣ�������κν����
	                       //���ӷ���

	delete prole_war2;

	return 0;
}
