#include<stdio.h>
#include<iostream>
using namespace std;
class Base{
	protected:
		Base *next;
	public:
		Base(){}
		Base(Base *t){//t指向new ProductA() 
			next=t;
		}
		virtual void fun()=0;//声明虚接口实现多态
		virtual ~Base(){
			cout<<"实现虚接口"<<endl;
		}
//		void Do(){
//			next->fun();//调用功能A的fun（） 
//		}
};
class ProductA:public Base{
	public:
		ProductA(Base *t){
			next=t;
		}
		void fun(){
			cout<<"ProoductA"<<endl;
			if(next)
			next->fun();//调用附加功能A的fun（） 
		}
}; 
class Decorator:public Base{
	public:
        virtual void fun()=0;//保证Decorator是虚函数，不用创建对象，同时也保持继承体系的完整性 
//        virtual ~Decorator(){
//        	cout<<"执行附加功能虚接口"<<endl; 
//		}
//		void fun(){
//			cout<<"DecoratorA"<<endl;
////			next->fun(); //调用附加功能A的fun（） 
//		}
};
class DecoratorA:public Decorator{
	public:
	DecratorA(){}
	DecoratorA(Base *t){   //t指向new DecoratorB（） 
		next=t;
	}
	void fun(){
		cout<<"DecoratorA"<<endl;
		if(next)
		next->fun();//调用附加功能B的fun（） 
	}
//	~DecoratorA(){
//		cout<<"调用DecoratorA的析构函数"<<endl;	 
//	}
};
class DecoratorB:public Decorator{
	public:
	DecoratorB(){}
	DecoratorB(Base* t){
		next=t;
	} 
	void fun(){
		cout<<"DecoratorB"<<endl;
		if(next)
		next->fun();
	}
};
int main(){
    DecoratorB* pdb=new DecoratorB(NULL);
	DecoratorA* pda=new DecoratorA(pdb);
	Base *base=new ProductA(pda);
	base->fun(); 
}


