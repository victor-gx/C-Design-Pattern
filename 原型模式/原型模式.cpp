#include <iostream>

using namespace std;

namespace _nmsp1
{
	//工厂方法模式(代码放到这里，方便比较)----------------------------------------
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
		
	//所有工厂类的父类
	class M_ParFactory
	{
	public:
		virtual Monster* createMonster() = 0; //具体的实现在子类中进行
		virtual ~M_ParFactory() {} //做父类时析构函数应该为虚函数
	};
	//M_Undead怪物类型的工厂，生产M_Undead类型怪物
	class M_UndeadFactory : public M_ParFactory
	{
	public:
		virtual Monster* createMonster()
		{
			//return  new M_Undead(300, 50, 80); //创建亡灵类怪物
			Monster* ptmp = new M_Undead(300, 50, 80); //创建亡灵类怪物
			//这里可以增加一些其他业务代码
			//......
			return ptmp;
		}
	};

	//M_Element怪物类型的工厂，生产M_Element类型怪物
	class M_ElementFactory : public M_ParFactory
	{
	public:
		virtual Monster* createMonster()
		{
			return  new M_Element(200, 80, 100); //创建元素类怪物
		}
	};

	//M_Mechanic怪物类型的工厂，生产M_Mechanic类型怪物
	class M_MechanicFactory : public M_ParFactory
	{
	public:
		virtual Monster* createMonster()
		{
			return  new M_Mechanic(400, 0, 110); //创建机械类怪物
		}
	};
}

namespace _nmsp2 {
	//怪物父类
	class Monster
	{
	public:
		//构造函数
		Monster(int life, int magic, int attack) :m_life(life), m_magic(magic), m_attack(attack) {}
		virtual ~Monster() {} //做父类时虚构函数应该为虚函数

	public:
		virtual Monster* clone() = 0; //具体的实现在子类中进行

//	public:
//		void setlife(int tmplife)
//		{
//			m_life = tmplife;
//		}
	protected: //可能被子类访问的成员，所以用protected修饰
//	public:
		//怪物属性
		int m_life;  //生命值
		int m_magic; //魔法值
		int m_attack;  //攻击力
	};
	
	//亡灵类怪物
	class M_Undead :public Monster
	{
	public:
		//构造函数
		M_Undead(int life, int magic, int attack) :Monster(life, magic, attack)
		{
			cout << "一只亡灵类怪物来到了这个世界" << endl;
		}
		
		//拷贝构造函数
		//..........留给大家自己写

		virtual Monster* clone()
		{
			//return new M_Undead(300, 50, 80); //创建亡灵类怪物
			return new M_Undead(*this); //触发拷贝构造函数的调用来创建亡灵类怪物
			
			
//			Monster * pmonster = new M_Undead(300, 50, 80); //创建亡灵类怪物
//			//pmonster->m_life = m_life;
//			pmonster->setlife(m_life);
//			pmonster->m_magic = m_magic;
//			pmonster->m_attack = m_attack;
//			return pmonster;
		}
		//...其他代码略
	};
	
	//元素类怪物
	class M_Element :public Monster
	{
	public:
		//构造函数
		M_Element(int life, int magic, int attack) :Monster(life, magic, attack)
		{
			cout << "一只元素类怪物来到了这个世界" << endl;
		}
		
		//拷贝构造函数
		M_Element(const M_Element& tmpobj) :Monster(tmpobj) //初始化列表中注意对父类子对象的初始化
		{
			cout << "调用了M_Element::M_Element(const M_Element& tmpobj)拷贝构造函数创建了一只元素类怪物" << endl;
		}

		virtual Monster* clone()
		{
			//return new M_Element(200, 80, 100); //创建元素类怪物
			return new M_Element(*this);
		}
		//...其他代码略
	};
	
	//机械类怪物
	class M_Mechanic :public Monster
	{
	public:
		//构造函数
		M_Mechanic(int life, int magic, int attack) :Monster(life, magic, attack)
		{
			cout << "一只机械类怪物来到了这个世界" << endl;
		}
		
		//拷贝构造函数
		M_Mechanic(const M_Mechanic& tmpobj) :Monster(tmpobj) //初始化列表中注意对父类子对象的初始化
		{
			cout << "调用了M_Mechanic::M_Mechanic(const M_Mechanic& tmpobj)拷贝构造函数创建了一只机械类怪物" << endl;
		}

		virtual Monster* clone()
		{
			//return new M_Mechanic(400, 0, 110); //创建机械类怪物
			return new M_Mechanic(*this);
		}
		//...其他代码略
	};
	
//	//全局的用于创建怪物对象的函数
//	void Gbl_CreateMonster2(Monster* pMonster)
//	{
//		Monster* ptmpobj = nullptr;
//		if (dynamic_cast<M_Undead*>(pMonster) != nullptr)
//		{
//			ptmpobj = new M_Undead(300, 50, 80); //创建亡灵类怪物
//		}
//		else if (dynamic_cast<M_Element*>(pMonster) != nullptr)
//		{
//			ptmpobj = new M_Element(200,80, 100); //创建元素类怪物
//		}
//		else if (dynamic_cast<M_Mechanic*>(pMonster) != nullptr)
//		{
//			ptmpobj = new M_Mechanic(400, 0, 110); //创建机械类怪物
//		}
//		if (ptmpobj != nullptr)
//		{
//			//这里就可以针对ptmpobj对象实现各种业务逻辑
//			//......
//			//不要忘记释放资源
//			delete ptmpobj;
//		}
//	}

	void Gbl_CreateMonster2(Monster* pMonster)
	{
		Monster* ptmpobj = pMonster->clone(); //根据已有对象直接创建新对象，不需要知道已有对象所属的类型
		//这里就可以针对ptmpobj对象实现各种业务逻辑
			//......
			//不要忘记释放资源
		delete ptmpobj;
	}

}

int main() {
	
//	_nmsp2::M_Mechanic myPropMecMonster(400, 0, 110); //创建一只机械类怪物对象作为原型对象以用于克隆目的
//	_nmsp2::Monster* pmyPropEleMonster = new _nmsp2::M_Element(200, 80, 100); //创建一只元素类怪物对象作为原型对象以用于克隆目的，
//	                  //这里可以直接new，也可以通过工厂模式创建原型对象，取决于程序员自己的洗好。
//	//.....
//	_nmsp2::Monster* p_CloneObj1 = myPropMecMonster.clone(); //使用原型对象克隆出新的机械类怪物对象
//	_nmsp2::Monster* p_CloneObj2 = pmyPropEleMonster->clone(); //使用原型对象克隆出新的元素类怪物对象
//
//	//可以对p_CloneObj1、p_CloneObj2所指向的对象进行各种操作（实现具体的业务逻辑）
//	//......
//
//	//释放资源
//	//释放克隆出来的怪物对象
//	delete p_CloneObj1;
//	delete p_CloneObj2;
//
//	//释放原型对象（堆中的）
//	delete pmyPropEleMonster;
	
	_nmsp2::Monster* pMonsterObj = new _nmsp2::M_Element(200, 80, 100);
	_nmsp2::Gbl_CreateMonster2(pMonsterObj);
	delete pMonsterObj;
	return 0;
} 
