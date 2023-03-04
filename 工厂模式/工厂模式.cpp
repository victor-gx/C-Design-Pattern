#include <iostream>

using namespace std;

namespace _nmsp1
{
	//怪物父类
	class Monster
	{
	public:
		//构造函数
		Monster(int life, int magic, int attack) :m_life(life), m_magic(magic), m_attack(attack) {}
		virtual ~Monster() {} //做父类时析构函数应该为虚函数

	protected://可能被子类访问的成员，所以用protected修饰
		//怪物属性
		int m_life; //生命值
		int m_magic; //魔法值
		int m_attack; //攻击力
	};
	
	//亡灵类怪物
	class M_Undead :public Monster
	{
	public:
		//构造函数
		M_Undead(int life, int magic, int attack) :Monster(life, magic, attack)
		{
			cout << "一个亡灵类怪物来到了这个世界" << endl;
		}
		//其他代码略......
	};
	
	//元素类怪物
	class M_Element :public Monster
	{
	public:
		//构造函数
		M_Element(int life, int magic, int attack) :Monster(life, magic, attack)
		{
			cout << "一个元素类怪物来到了这个世界" << endl;
		}
		//其他代码略......
	};
	
	//机械类怪物
	class M_Mechanic :public Monster
	{
	public:
		//构造函数
		M_Mechanic(int life, int magic, int attack) :Monster(life, magic, attack)
		{
			cout << "一个机械类怪物来到了这个世界" << endl;
		}
		//其他代码略......
	};
	
	//-------------------------------
	//怪物工厂类
	class MonsterFactory
	{
	public:
		//Monster* createMonster(string strmontype) //简单工厂模式
		static Monster* createMonster(string strmontype) //静态工厂方法模式（Static Factory Method）
		{
			Monster* prtnobj = nullptr;
			if (strmontype == "udd") //udd代表要创建亡灵类怪物
			{
				prtnobj = new M_Undead(300, 50, 80);
			}
			else if (strmontype == "elm") //elm代表要创建元素类怪物
			{
				prtnobj = new M_Element(200, 80, 100);
			}
			else if (strmontype == "mec") //mec代表要创建机械类怪物
			{
				prtnobj = new M_Mechanic(400, 0, 110);
			}
			return prtnobj;
		}
	};	
}

int main() {
//	_nmsp1::Monster* pM1 = new _nmsp1::M_Undead(300, 50, 80); //产生一只亡灵类怪物
//	_nmsp1::Monster* pM2 = new _nmsp1::M_Element(200, 80, 100); //产生一只元素类怪物
//	_nmsp1::Monster* pM3 = new _nmsp1::M_Mechanic(400, 0, 110); //产生一只机械类怪物
//	
//	//释放资源
//	delete pM1;
//	delete pM2;
//	delete pM3;

//	_nmsp1::MonsterFactory facobj;
//	_nmsp1::Monster* pM1 = facobj.createMonster("udd"); //产生了一只亡灵类怪物，当然这里必须知道“udd”代表的是创建亡灵类怪物
//	_nmsp1::Monster* pM2 = facobj.createMonster("elm"); //创建一只元素类怪物
//	_nmsp1::Monster* pM3 = facobj.createMonster("mec"); //创建一只机械类怪物
//
//	//释放资源
//	delete pM1;
//	delete pM2;
//	delete pM3;

	//此时简单工厂模式又可以称为静态工厂方法模式（Static Factory Method）
	_nmsp1::Monster* pM1 = _nmsp1::MonsterFactory::createMonster("udd"); //产生了一只亡灵类怪物，当然这里必须知道“udd”代表的是创建亡灵类怪物
	_nmsp1::Monster* pM2 = _nmsp1::MonsterFactory::createMonster("elm"); //创建一只元素类怪物
	_nmsp1::Monster* pM3 = _nmsp1::MonsterFactory::createMonster("mec"); //创建一只机械类怪物

	//释放资源
	delete pM1;
	delete pM2;
	delete pM3;
	
	return 0;
} 
