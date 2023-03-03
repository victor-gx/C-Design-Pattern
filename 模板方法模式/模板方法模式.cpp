#include <iostream>

using namespace std;

namespace _nmsp1
{
	// 定义一个“战士”类
	class Warrior
	{
	public:
		// 构造函数
		Warrior(int life, int magic, int attack) : m_life(life), m_magic(magic), m_attack(attack)
		{
		}
		//...一些其他成员函数,不重要，不深究

	public:
		void JN_Burn() // 技能“燃烧”
		{
			cout << "让所有敌人每人失去500点生命，相关逻辑代码这里略......" << endl;
			cout << "主角自身失去300点生命值" << endl;
			m_life -= 300;
			cout << "播放技能\"燃烧\"的技能特效给玩家看" << endl;
		}

	private:
		// 角色属性
		int m_life;	  // 生命值
		int m_magic;  // 魔法值
		int m_attack; // 攻击力
	};

}

namespace _nmsp2
{
	// 战斗者父类
	class Fighter
	{
		public: 
		Fighter(int life, int magic, int attack) : m_life(life), m_magic(magic), m_attack(attack) {}
		virtual ~Fighter() {} // 做父类时析构函数应该为虚函数

		// 对主角自身会产生影响，对敌人会产生影响。
		// 分析：对敌人产生影响，有函数effect_enemy。对主角自身产生影响，有函数effect_self。播放技能play_effect函数。
		void JN_Burn() // 技能“燃烧”
		{
			if (canUseJN() == false) //如果不能使用该技能，则直接返回
				return; 
			effect_enemy(); // 对敌人产生的影响
			effect_self();	// 对主角自身产生的影响
			play_effect();	// 播放技能“燃烧”的技能特效
		}

	private:
		virtual void effect_enemy() {} // 函数体为空，表示啥也不做，如果要求必须在子类中重新实现该虚函数，则可以将该函数写成纯虚函数。
		virtual void effect_self() {}
		void play_effect()
		{
			cout << "播放技能\"燃烧\"的技能特效给玩家看" << endl; // 所有主角播放的技能特效都相同，因此不用写成一个虚函数并在子类中实现技能特效的播放。
		}
		virtual bool canUseJN() = 0; //判断是否能使用技能“燃烧”，这是个纯虚函数声明，子类中必须重新实现canUseJN。

	protected: // 可能被子类访问，所以用protected修饰
		// 角色属性
		int m_life;	  // 生命值
		int m_magic;  // 魔法值
		int m_attack; // 攻击力
	};

	//-------------------------
	// “战士”类，父类为Fighter
	class F_Warrior : public Fighter
	{
	public:
		F_Warrior(int life, int magic, int attack) : Fighter(life, magic, attack) {}

	private:
		// 对敌人产生的影响
		virtual void effect_enemy()
		{
			cout << "战士主角_让所有敌人每人失去500点生命，相关逻辑代码这里略......" << endl;
		}
		// 对主角自身产生的影响
		virtual void effect_self()
		{
			cout << "战士主角_自身失去300点生命值" << endl;
			m_life -= 300;
		}
		virtual bool canUseJN()
		{
			if (m_life < 300) //生命值不够300点，不能使用技能“燃烧”
				return false;
			return true;
		}
	};
	//-------------------------
	// “法师”类，父类为Fighter
	class F_Mage : public Fighter
	{
	public:
		F_Mage(int life, int magic, int attack) : Fighter(life, magic, attack) {}

	private:
		// 对敌人产生的影响
		virtual void effect_enemy()
		{
			cout << "法师主角_让所有敌人每人失去650点生命，相关逻辑代码这里略......" << endl;
		}
		// 对主角自身产生的影响
		virtual void effect_self()
		{
			cout << "法师主角_自身失去100点魔法值" << endl;
			m_magic -= 100;
		}
		virtual bool canUseJN()
		{
			if (m_magic < 100) //魔法值不够100点，不能使用技能“燃烧”
				return false;
			return true;
		}
	};
}

int main()
{
	// _nmsp1::Warrior mroleobj(1000, 0, 200); //创建主角
	// mroleobj.JN_Burn(); //主角释放“燃烧”技能

//	_nmsp2::Fighter *prole_war = new _nmsp2::F_Warrior(1000, 0, 200); // 创建战士主角，注意这里是父类指针指向子类对象以利用多态特性。
//	prole_war->JN_Burn();	// 战士主角释放“燃烧”技能，调用的是F_Warrior类的effect_enemy和effect_self。
//
//	cout << "---------------------------" << endl;					// 分割线，以便更醒目的显示信息
//	_nmsp2::Fighter *prole_mag = new _nmsp2::F_Mage(800, 200, 300); // 创建法师主角，注意这里是父类指针指向子类对象以利用多态特性。
//	prole_mag->JN_Burn();											// 法师主角释放“燃烧”技能
//
//	// 释放资源
//	delete prole_war;
//	delete prole_mag;
	
//	//早绑定
//	_nmsp2::F_Warrior role_war(1000, 0, 200);
//	role_war.JN_Burn(); //早绑定
	
	_nmsp2::Fighter* prole_war2 = new _nmsp2::F_Warrior(50, 0, 200);//创建生命值只有50的战士主角
	prole_war2->JN_Burn(); //该战士无法成功释放“燃烧”技能，不输出任何结果。
	                       //钩子方法

	delete prole_war2;

	return 0;
}
