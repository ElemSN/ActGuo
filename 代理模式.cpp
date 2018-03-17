#include<iostream>
using namespace std;
class Base{
	public:
	Base(){
	}
	virtual void method()=0;
	virtual ~ Base(){
	}
};
class Sourse:public Base{
	public:
		void method(){
			cout<<"Sourse"<<endl;
		}
		~ Sourse(){
		}
};
class Proxy:public Base{
	private:
		Base*pb;
	public:
		Proxy(Base*t){
			pb=t;
		}
		void method(){
			pb->method();
		}
		~ Proxy(){
		}
};
int main(void){
	Proxy *py=new Proxy(new Sourse());
	py->method(); 
	delete py;
}
