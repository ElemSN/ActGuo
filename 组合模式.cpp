#include<iostream>
#include<vector>
#include<string>
using namespace std;
class AbstractFile{
	protected:
		string name;
	public:
		AbstractFile(){
			name="XXX";
		}
		AbstractFile(string n){
			name=n;
		}
		virtual void Out ()=0;
		
};
class File:public AbstractFile{
	public:
		File(){
		}
		File(string n):AbstractFile(n){
		}
		void Out(){
		cout<<name<<endl;
		}
};
class Folder:public AbstractFile{
	private :
		vector <AbstractFile*> vec;
	public:
		Folder(){
		}
		Folder(string n):AbstractFile(n){
		}
		void Add(AbstractFile*t){
			vec.push_back(t);
		}
		void Out(){
		 cout<<name<<endl;
		}
};
int main(void){
	Folder *folder=new Folder("aa");
	File *f1=new File("a1");
	File *f2=new File("a2");
	File *f3=new File("a3");
	Folder *fc=new Folder("bb");
	File *f4=new File("b1");
	folder->Add(f1);
	folder->Add(f2);
	folder->Add(f3);
	fc->Add(f4);
	folder->Out();
	f1->Out();
	f2->Out();
	f3->Out();
	fc->Out();
	f4->Out();

	
}
