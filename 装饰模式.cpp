#include<iostream>
#include<string>
using namespace std;
class Base{
	private:
		Base*next;
	public:
		Base(Base*t){
			next=t;
		}
		virtual void fun(){
			if(next)
			next->fun();
			}
		virtual ~ Base(){
		}
		
};
class produceA:public Base{
	public:
	produceA(Base*t):Base(t){
	}
	void fun(){
		cout<<"ProduceA"<<endl;
		Base::fun();
	}
	~ produceA (){
	}
};
class Decorator:public Base{
	public:
	Decorator(Base*t):Base(t){
	}
	virtual void fun()=0;
	virtual ~ Decorator(){
	}
};
class DecoratorA:public Decorator{
	public:
		DecoratorA(Base*t):Decorator(t){
		}
		void fun(){
			cout<<"DecoratorA"<<endl;
			Base::fun();
		}
		~ DecoratorA(){
		}
};
class DecoratorB:public Decorator{
	public:
		DecoratorB(Base*t):Decorator(t){
		}
		void fun(){
			cout<<"DecoratorB"<<endl;
			Base::fun();
		}
		~ DecoratorB(){
			
		}
};
int main(){
	DecoratorB *deb=new DecoratorB(NULL);
	DecoratorA*dea=new DecoratorA(deb);
	Base*head=new produceA(dea);
	head->fun();
	delete deb;
	delete dea;
	delete head;
}
