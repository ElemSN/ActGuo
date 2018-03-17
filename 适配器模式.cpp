#include<iostream>
using namespace std;
class Adaptee{
	public:
		void method(){
			cout<<"Adaptee"<<endl;
		}
};
class AdaptorBase{
	public:
		virtual void method()=0;
		virtual ~ AdaptorBase(){
		}
};
class AdaptorA:public AdaptorBase{
	public:
		void method(){
			cout<<"Adaptor"<<endl;
		}
		~ AdaptorA(){
		}
};
class AdaptorB:public AdaptorBase{
	private:
		Adaptee*pe;
	public:
		AdpatorB(){
			pe=new Adaptee();
		}
		void method(){
			pe->method();
		}
		~ AdaptorB(){
			delete pe;
		}
};
int main(void){
	AdaptorB * pb=new AdaptorB();
	pb->method();
	delete pb;
}
