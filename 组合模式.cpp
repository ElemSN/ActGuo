#include<iostream>
#include<typeinfo> 
#include<string>
#include<vector>
#include<stdio.h>
using namespace std;
class  AbstractFile{
	public:
		string name;
	public:
		AbstractFile(){}
		AbstractFile(string name){
			this->name=name;
		}
		virtual void Out()=0;
};
class File:public AbstractFile{
	public:
		File(){}
		File(string name):AbstractFile(name){}
		void Out(){
			cout<<"File:"<<name<<endl;
		}
};
class Folder:public AbstractFile{
	private:
		vector<AbstractFile*> vec;
	public:
		Folder(string name):AbstractFile(name){}
		void Add(AbstractFile* t){
			vec.push_back(t);
		}
		void Out(){			
			cout<<"Folder:"<<name<<endl;
		}
		void Show(AbstractFile* a){
//µÝ¹éÊµÏÖ 
//			vector<AbstractFile*>::iterator it;
//			it=vec.begin();
//            File *file;
//            it++;
//            cout<<*it<<endl;
//            cout<<(typeid(*a)==typeid(*file))<<endl;//²âÊÔ 
////			cout<<<<endl;
//			if(typeid(*it)==typeid(*file)){
//            cout<<"chehe"<<endl; 
//            }
//			else{
				(a)->Out();
//			}
			}
		
};
int main(){
	Folder *root=new Folder("F:\\");
	File *file1=new File("1.c");
	File *file2=new File("2.c");
	Folder *cf=new Folder("aa");
	File *file3=new File("3.c");
	root->Add(root);
	root->Add(file1);
	root->Add(file2);
	root->Add(cf);
	cf->Add(file3);	
	root->Show(root); 
    root->Show(file1);
	root->Show(file2);
	root->Show(cf);
	root->Show(file3);
}

