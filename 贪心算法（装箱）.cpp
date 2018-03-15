#include<stdio.h>
#include<stdlib.h>
#define n 9
#define v 40
typedef struct{
	int gno;//物品编号 
	int gv;//物品体积 
}ElemG;
typedef struct node{
	int gno;
	struct node *link;
}GoodsLink;
typedef struct box{
	int Remainder;
	GoodsLink *hg;
	struct box *next;
}BoxLink; 
ElemG*Sort(ElemG*g){
	int i,j;
	ElemG t; 
	for(i=0;i<n;i++){
		for(j=i+1;j<n;j++){
			if(g[i].gv<g[j].gv){
				t=g[i];
				g[i]=g[j];
				g[j]=t;	
			}
		}
	}
		return g;
}
BoxLink *PutBox(ElemG *h){
	int i;
	BoxLink *tail,*hbox=NULL,*p,*hg;
	GoodsLink *q,*ne;
	for(i=0;i<n;i++){		
		for(p=hbox;p&&p->Remainder<h[i].gv;p=p->next);
		if(!p){
			p=(BoxLink*)malloc(sizeof(BoxLink));
			p->Remainder=v;
			p->hg=NULL;
			p->next=NULL;
			if(!hbox)
		    hbox=tail=p;
		    else
		    tail=tail->next=p;
		}
		p->Remainder-=h[i].gv;
		ne=(GoodsLink*)malloc(sizeof(GoodsLink));
		ne->gno=h[i].gno;
		ne->link=NULL;
		if(!p->hg)
		p->hg=ne;
		else{
			for(q=p->hg;q->link;q=q->link);
				q->link=ne;
			}
		}
	return hbox;
	}
void print(BoxLink*hbox){
	BoxLink*p;
	GoodsLink*q;
	int cut=0;
	for(p=hbox;p;p=p->next){
		printf("这是第%d个箱子；里面放的物品编号",++cut);
		for(q=p->hg;q;q=q->link)
			printf("%d，",q->gno);
		printf("\n");
	}
}
int main(void){
	ElemG *g,*h;
	BoxLink*hbox;
	int vol,c=0;
	g=(ElemG*)malloc(n*sizeof(ElemG));
	
	for(int i=0;i<n;i++){
	printf("请输入第%d物品的体积:",++c);
		g[i].gno=i+1;	
		scanf("%d",&vol);
		g[i].gv=vol;
	}
	h=Sort(g);
	hbox=PutBox(h);
	print(hbox);
}
