#include <iostream>

using namespace std;

namespace _nmsp1 {
	//怪物父类
	class Monster
	{
	public:
		virtual ~Monster() {} //做父类时析构函数应该为虚函数
//		void Assemble(string strmodelno) //参数:模型编号，形如：“1253679201245”等。每些位的组合都有一些特别的含义，这里不需要探究。
//		{
//			LoadTrunkModel(strmodelno.substr(4, 3)); //载入躯干模型，截取某部分字符串以表示躯干模型的编号
//			LoadHeadModel(strmodelno.substr(7, 3)); //载入头部模型并挂接到躯干模型上
//			LoadLimbsModel(strmodelno.substr(10, 3)); //载入四肢模型并挂接到躯干模型上
//		}
//
//		virtual void LoadTrunkModel(string strno) = 0; //这里也可以写成一个空函数，子类决定是否重新实现
//		virtual void LoadHeadModel(string strno) = 0;
//		virtual void LoadLimbsModel(string strno) = 0;
	};
	
	//亡灵类怪物
	class M_Undead :public Monster
	{
//	public:
//		virtual void LoadTrunkModel(string strno)
//		{
//			cout << "载入亡灵类怪物的躯干部位模型，需要调用M_Undead类或其父类中其他诸多成员函数，逻辑代码略......" << endl;
//		}
//		virtual void LoadHeadModel(string strno)
//		{
//			cout << "载入亡灵类怪物的头部模型并挂接到躯干部位，需要调用M_Undead类或其父类中其他诸多成员函数，逻辑代码略......" << endl;
//		}
//		virtual void LoadLimbsModel(string strno)
//		{
//			cout << "载入亡灵类怪物的四肢模型并挂接到躯干部位，需要调用M_Undead类或其父类中其他诸多成员函数，逻辑代码略......" << endl;
//		}
	};
	
	//元素类怪物
	class M_Element :public Monster
	{
//	public:
//		virtual void LoadTrunkModel(string strno)
//		{
//			cout << "载入元素类怪物的躯干部位模型，需要调用M_Element类或其父类中其他诸多成员函数，逻辑代码略......" << endl;
//		}
//		virtual void LoadHeadModel(string strno)
//		{
//			cout << "载入元素类怪物的头部模型并挂接到躯干部位，需要调用M_Element类或其父类中其他诸多成员函数，逻辑代码略......" << endl;
//		}
//		virtual void LoadLimbsModel(string strno)
//		{
//			cout << "载入元素类怪物的四肢模型并挂接到躯干部位，需要调用M_Element类或其父类中其他诸多成员函数，逻辑代码略......" << endl;
//		}
	};

	//机械类怪物
	class M_Mechanic :public Monster
	{
//	public:
//		virtual void LoadTrunkModel(string strno)
//		{
//			cout << "载入机械类怪物的躯干部位模型，需要调用M_Mechanic类或其父类中其他诸多成员函数，逻辑代码略......" << endl;
//		}
//		virtual void LoadHeadModel(string strno)
//		{
//			cout << "载入机械类怪物的头部模型并挂接到躯干部位，需要调用M_Mechanic类或其父类中其他诸多成员函数，逻辑代码略......" << endl;
//		}
//		virtual void LoadLimbsModel(string strno)
//		{
//			cout << "载入机械类怪物的四肢模型并挂接到躯干部位，需要调用M_Mechanic类或其父类中其他诸多成员函数，逻辑代码略......" << endl;
//		}
	};
	
	//----------------------------
	//怪物构建器父类
	class MonsterBuilder
	{
	public:
		virtual ~MonsterBuilder() {} //做父类时析构函数应该为虚函数
		//void Assemble(string strmodelno) //参数:模型编号，形如：“1253679201245”等。每些位的组合都有一些特别的含义，这里不需要探究。
		//{
		//	LoadTrunkModel(strmodelno.substr(4, 3)); //载入躯干模型，截取某部分字符串以表示躯干模型的编号
		//	LoadHeadModel(strmodelno.substr(7, 3)); //载入头部模型并挂接到躯干模型上
		//	LoadLimbsModel(strmodelno.substr(10, 3)); //载入四肢模型并挂接到躯干模型上
		//}

		//返回指向Monster类的成员变量指针m_pMonster，当一个复杂的对象构建完成后，可以通过该成员函数把对象返回。
		Monster* GetResult()
		{
			return m_pMonster;
		}

		virtual void LoadTrunkModel(string strno) = 0; //这里也可以写成一个空函数，子类决定是否重新实现
		virtual void LoadHeadModel(string strno) = 0;
		virtual void LoadLimbsModel(string strno) = 0;

	protected:
		Monster* m_pMonster; //指向Monster类的成员变量指针
	};
	
	//----------
	//亡灵类怪物构建器类
	class M_UndeadBuilder :public MonsterBuilder
	{
	public:
		M_UndeadBuilder() //构造函数
		{
			m_pMonster = new M_Undead();
		}

		virtual void LoadTrunkModel(string strno)
		{
			cout << "载入亡灵类怪物的躯干部位模型，需要m_pMonster指针调用M_Undead类或其父类中其他诸多成员函数，逻辑代码略......" << endl;
			//具体要做的事情其实是委托给怪物子类完成，委托指把本该自己实现的功能转给其他类实现
			//m_pMonster->......略
		}
		virtual void LoadHeadModel(string strno)
		{
			cout << "载入亡灵类怪物的头部模型并挂接到躯干部位，需要m_pMonster指针调用M_Undead类或其父类中其他诸多成员函数，逻辑代码略......" << endl;
			//m_pMonster->......略
		}
		virtual void LoadLimbsModel(string strno)
		{
			cout << "载入亡灵类怪物的四肢模型并挂接到躯干部位，需要m_pMonster指针调用M_Undead类或其父类中其他诸多成员函数，逻辑代码略......" << endl;
			//m_pMonster->......略
		}
	};

	//元素类怪物构建器类
	class M_ElementBuilder :public MonsterBuilder
	{
	public:
		M_ElementBuilder() //构造函数
		{
			m_pMonster = new M_Element();
		}

		virtual void LoadTrunkModel(string strno)
		{
			cout << "载入元素类怪物的躯干部位模型，需要m_pMonster指针调用M_Element类或其父类中其他诸多成员函数，逻辑代码略......" << endl;			
			//m_pMonster->......略
		}
		virtual void LoadHeadModel(string strno)
		{
			cout << "载入元素类怪物的头部模型并挂接到躯干部位，需要m_pMonster指针调用M_Element类或其父类中其他诸多成员函数，逻辑代码略......" << endl;
			//m_pMonster->......略
		}
		virtual void LoadLimbsModel(string strno)
		{
			cout << "载入元素类怪物的四肢模型并挂接到躯干部位，需要m_pMonster指针调用M_Element类或其父类中其他诸多成员函数，逻辑代码略......" << endl;
			//m_pMonster->......略
		}
	};

	//机械类怪物构建器类
	class M_MechanicBuilder :public MonsterBuilder
	{
	public:
		M_MechanicBuilder() //构造函数
		{
			m_pMonster = new M_Mechanic();
		}

		virtual void LoadTrunkModel(string strno)
		{
			cout << "载入机械类怪物的躯干部位模型，需要m_pMonster指针调用M_Mechanic类或其父类中其他诸多成员函数，逻辑代码略......" << endl;
			//m_pMonster->......略
		}
		virtual void LoadHeadModel(string strno)
		{
			cout << "载入机械类怪物的头部模型并挂接到躯干部位，需要m_pMonster指针调用M_Mechanic类或其父类中其他诸多成员函数，逻辑代码略......" << endl;
			//m_pMonster->......略
		}
		virtual void LoadLimbsModel(string strno)
		{
			cout << "载入机械类怪物的四肢模型并挂接到躯干部位，需要m_pMonster指针调用M_Mechanic类或其父类中其他诸多成员函数，逻辑代码略......" << endl;
			//m_pMonster->......略
		}
	};
	
	//------------------
	//指挥者类
	class MonsterDirector
	{
	public:
		MonsterDirector(MonsterBuilder* ptmpBuilder) //构造函数
		{
			m_pMonsterBuilder = ptmpBuilder;
		}

		//指定新的构建器
		void SetBuilder(MonsterBuilder* ptmpBuilder)
		{
			m_pMonsterBuilder = ptmpBuilder;
		}

		//原MonsterBuilder类中的Assemble成员函数
		Monster *Construct(string strmodelno) //参数:模型编号，形如：“1253679201245”等。每些位的组合都有一些特别的含义，这里不需要探究。
		{
			m_pMonsterBuilder->LoadTrunkModel(strmodelno.substr(4, 3)); //载入躯干模型，截取某部分字符串以表示躯干模型的编号
			m_pMonsterBuilder->LoadHeadModel(strmodelno.substr(7, 3)); //载入头部模型并挂接到躯干模型上
			m_pMonsterBuilder->LoadLimbsModel(strmodelno.substr(10, 3)); //载入四肢模型并挂接到躯干模型上
			return m_pMonsterBuilder->GetResult(); //返回构建后的对象
		}
	private:
		MonsterBuilder* m_pMonsterBuilder; //指向所有构建器类的父类
	};
}

int main() {
//	_nmsp1::Monster* pmonster = new _nmsp1::M_Element(); //创建一只元素类怪物
//	pmonster->Assemble("1253679201254");
//
//	//释放资源
//	delete pmonster;
	
	_nmsp1::MonsterBuilder* pMonsterBuilder = new _nmsp1::M_UndeadBuilder(); //创建亡灵类怪物构建器对象
	_nmsp1::MonsterDirector* pDirector = new _nmsp1::MonsterDirector(pMonsterBuilder); 
	_nmsp1::Monster* pMonster = pDirector->Construct("1253679201254"); //这里就构建出了一个完整的怪物对象

	//释放资源
	delete pMonster;
	delete pDirector;
	delete pMonsterBuilder;
	
	return 0;
}

