#include<stdio.h>
#include<iostream>
using namespace std;
class Base{
	protected:
		Base *next;
	public:
		Base(){}
		Base(Base *t){//tָ��new ProductA() 
			next=t;
		}
		virtual void fun()=0;//������ӿ�ʵ�ֶ�̬
		virtual ~Base(){
			cout<<"ʵ����ӿ�"<<endl;
		}
//		void Do(){
//			next->fun();//���ù���A��fun���� 
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
			next->fun();//���ø��ӹ���A��fun���� 
		}
}; 
class Decorator:public Base{
	public:
        virtual void fun()=0;//��֤Decorator���麯�������ô�������ͬʱҲ���ּ̳���ϵ�������� 
//        virtual ~Decorator(){
//        	cout<<"ִ�и��ӹ�����ӿ�"<<endl; 
//		}
//		void fun(){
//			cout<<"DecoratorA"<<endl;
////			next->fun(); //���ø��ӹ���A��fun���� 
//		}
};
class DecoratorA:public Decorator{
	public:
	DecratorA(){}
	DecoratorA(Base *t){   //tָ��new DecoratorB���� 
		next=t;
	}
	void fun(){
		cout<<"DecoratorA"<<endl;
		if(next)
		next->fun();//���ø��ӹ���B��fun���� 
	}
//	~DecoratorA(){
//		cout<<"����DecoratorA����������"<<endl;	 
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


