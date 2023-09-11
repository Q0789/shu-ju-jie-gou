#include<stdio.h>
#include<stdlib.h>
//单链表是由一个一个结点构成的，而每个结点都是一个结构体(结构体类型是struct LNode!!!)，结构体里面有一个数据和指向下一下结点的指针
//要明白：LNode就是一个结点  LNode*/LinkList（头指针）就是一个指向结点的指针。
//(int b=5;int* a=&b，int型指针存储int型数据的地址)函数传入参数为L，L是一个指针类型，
//所以传入的一定是地址，地址是LNode结点结构体类型，所以接受参数类型为结构体类型的指针，即为LinkList类型
//或者说就是LinkList到LinkLIst类型。
//malloc:指针=(指针类型)malloc(sizeof（所指向的那部分空间的数据类型*个数）)
//具体实现封装，比如实现找到第i-1个节点！！！！！！（非常重要）
//对于结点的定义
typedef struct LNode{
	int data;
	struct LNode* next;
}LNode,* LinkList;
/*
//不带头结点的单链表:
//初始化
bool InitList(LinkList L){
	L=NULL;
	return true;
}
//判断单链表是否为空
bool Empty (LinkList L){
	return (L==NULL);//只需要看头指针是否有指向即可，因为只要头指针没有指向，那么单链表是一个空表
}
//按位序插入
bool ListInsert(LinkList L,int i,int e){
	if(i<1){
		return false;
	}
	if(i==1){
		LNode* s=(LNode*)malloc(sizeof(LNode));
		s->data=e;
		s->next=L;
		L=s;
		return true;
	}
	LNode *s=L;
	int j=1;//1!!!!!
	while(s!=NULL && j<i-1){
		s=s->next;
		j++;
	}
	if(s==NULL){
		return false;
	}
	LNode* p=(LNode*)malloc(sizeof(LNode));
	//右边赋予左边，左边是准备指的箭头，右边是箭头所指向的东西
	p->data=e;
	p->next=p->next;
	p->next=p;
	return true;
}
//指定节点的后插操作
bool InsertNextNode(LNode* p,int e){
	if(p==NULL){
		return false;
	}
	LNode* s=(LNode*)malloc(sizeof(LNode));
	if(s==NULL){//一般来说在malloc分配内存之后，我们都需要判断是否内存分配成功与否
		return false;
	}
	s->data=e;
	s->next=p->next;
	p->data=e;
	return true;
}
//指定节点的前插操作(后插+交换两个结点的元素值)
bool InsertPriorNode(LNode* p,int e){
	if(p==NULL){
		return false;
	}
	LNode* s=(LNode*)malloc(sizeof(LNode));
	if(s==NULL){
		return false;
	}
	s->next=p->next;
	p->next=s;
	s->data=p->data;
	p->data=e;
	return true;
}
//按位序删除(先找到第i-1个结点，然后需要两个指针打配合)
bool ListDelete(LinkList L,int i,int e){
	if(i<1){
		return false;
	}
	
}
  
*/
//带头结点的单链表：
//初始化：
bool InitList(LinkList L){
	L=(LNode*)malloc(sizeof(LNode));
	if(L==NULL){
		return false;
	}
	L->next=NULL;
	return true;
}
//判断单链表是否为空
bool Empty (LinkList L){
	return (L->next==NULL);
}
//插入（位序+指定节点的前插和后插）
//按位序插入：
bool ListInsert(LinkList L,int i,int x){
	if(i<1){
		return false;
	}
	LNode* p=L;
	int j=0;
	while(p!=NULL && j<i-1){
		p=p->next;
		j++;
	}
	LNode* s=(LNode*)malloc(sizeof(LNode));
	s->data=x;
	s->next=p->next;
	p->next=s;
	return true;
}
//指定节点的插入：
//前插：
//后插：
//删除（位序+指定节点）
//按位序删除：(先找到第i-1个结点，然后需要两个指针打配合)
bool ListDelete(LinkList L,int i,int* e){
	if(i<1){
		return false;
	}
	LNode* p=L;
	int j=0;
	while(p!=NULL && j<i-1){
		p=p->next;
		j++;
	}
	//可能第i-1个结点是不存在的，甚至第i个结点（即p指向为NULL）是不存在的。
	if(p==NULL || p->next==NULL){
		return false;
	}
	//LNode* q=p->next;//让q指向第i个结点
	*e=p->next->data;
	p->next=p->next->next;//p->next=q->next;
	//free(q);
	return true;
	
}
//指定结点的删除:
int main(){
	LinkList L;//定义了一个头指针，即看作定义了一个单链表
	//InitList(L);//传入的是头指针，L本身就是一个指针，不用加取地址符。所以你就会发现，单链表这一块，参数传入单链表的一定是地址
	//ListInsert(L,5,123);
	//InsertNextNode(L,213);//传入的是结点
	//InsertPriorNode(L,123);//传入的是结点
}






/*
//带头结点的单链表
//对于结点的定义
typedef struct LNode{
	int data;
	struct LNode* next;
}LNode,* LinkList;
//初始化
bool InitList(LinkList L){
	L=(LNode*)malloc(sizeof(LNode));//产生一个头结点，并且让头指针指向这个头结点
	if(L==NULL){
		return false;//可能内存分配失败
	}
	L->next=NULL;//让头结点指向空NULL！！！
	return true;
}
//判断单链表是否为空
bool Empty (LinkList L){
	return (L->next==NULL);//只需要看头指针指向的头结点是否有指向即可，因为只要头指针指向的头结点没有指向，那么单链表是一个空表
}
//插入（位序+指定结点）
//1、按位序插入(找到第i-1个结点，然后将新结点插进去即可)
bool ListInsert(LinkList L,int i,int e){
	if(i<1){
		return false;
	}
	LNode* p=L;//定义指向头结点的指针（也就是指向结构体的指针，之后在使用这个指针时，就是"p->"!!!!!），且表达结点的意思，用LNode，并且我们不会动头指针，一般用另外一个变量存储头指针的地址
	int j=0;//表示从第0个结点，也就是头结点开始,让p指针依次向后指，知道第i-1个结点
	while(p!=NULL && j<i-1){
		p=p->next;
		j++;
	}
	if(p==NULL){
		return false;
	}
	LNode* s=(LNode*)malloc(sizeof(LNode));
	//右边赋予左边，左边是准备指的箭头，右边是箭头所指向的东西
	s->data=e;
    s->next=p->next;
	p->next=s;
	return true;
}
int main(){
	LinkList L;//定义了一个头指针，即看作定义了一个单链表
	InitList(L);//传入的是头指针，L本身就是一个指针，不用加取地址符。所以你就会发现，单链表这一块，参数传入单链表的一定是地址
	if(ListInsert(L,5,213)){
		printf("插入成功");
	}else{
		printf("插入失败");
	}
}
 */
