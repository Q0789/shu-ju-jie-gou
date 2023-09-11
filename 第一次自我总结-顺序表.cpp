#include<stdio.h>
#include<stdlib.h>
//创销，增删改查(创销增删都是需要对原线性表进行改变，必须传入的是地址)
//对于线性表的基本操作(线性表变量一般使用L表示的)：
//初始化：InitList(传入的是地址)；对于顺序表,是创建一个结构体L，然后把结构体的指针传进去，而对于链表，是创建一个头指针L，再把L传进去
//销毁：DestroyList(传入的是地址);
//插入：ListInsert(传入的是地址,i,e);
//删除:ListDelete(传入的是地址,i,&e);&e表示我们要把删除的那部分地址返回来
//按位查找:GetElem(L,i);获得L线性表中第i个位置元素的值
//按值查找：LocateElem(L,e);查找线性表L中是否有e元素。注意：当值为结构体类型时，就不可以用==了，可以自己创建一个比较函数，比较结构体中的每一项属性，都相同时，才是“等值”
//其他的常用操作：Length(L); PrintList(L);Empty(L);
//传入的是结构体地址时，用的是“->”，传入的是结构体变量时，用的是“.”


/*
//对于静态分配存储结构的顺序表的创建和初始化
#define MaxSize 10
typedef struct{//结构体的定义
	int data[MaxSize];
	int length;
}SqList;
//初始化
void InitList(SqList* L){
	L->length=0;
}
//插入元素(将第i个以及后面的所有数据元素后移)
bool ListInsert(SqList* L,int i,int e){
	if(i<1 ||i>L->length+1){
		return false;
	}
	if(L->length>=MaxSize){
		return false;
	}
	for(int j=L->length;j>=i;j--){
		L->data[j]=L->data[j-1];//比如长度为4，i为2，我们要知道我们现在第一步是要把下标为3放到下标为4的位置上，而长度已经为4了，不妨就是L->data[j]=L->data[j-1]，而结束的j条件看下面的注释
	}
	L->data[i-1]=e;//因为for循环的最后一步是将目标位置的值放到比目标位置大一的位置上，而最后一步是将j-1放到j中，而for循环最后一次进行的时候j等于i，所以最后一步是把i-1放到i中，即目标位置的下标是i-1
	L->length++;//容易忘记
	return true;
}
//删除元素（将第i+1以及后面的所有元素前移）
bool ListDelete(SqList* L,int i,int *e){
	if(i<1 ||i>L->length){
		return false;
	}
	*e=L->data[i-1];
	for(int j=i;j<L->length;j++){
		L->data[j-1]=L->data[j];//比如i为2，对应的下标为1，我们要知道，第一步是将下标为2放到下标为1的位置上，而i已经为2，且j等于i，所以L->data[j-1]=L->data[j]
	}
	L->length--;
	return true;
}
//按位查找
int GetElem(SqList L,int i){
	return L.data[i-1];
}
int main()
{
	SqList  L;//首先创建一个顺序表（即创建了一个结构体）
	InitList(&L);
	if(ListInsert(&L,5,24)){
		printf("添加成功");
	}else{
		printf("添加失败");
	}
	int e;//用变量e将删除的元素“带回来”
	if(ListDelete(&L,5,&e)){
		printf("已经删除第3个元素，删除元素的值为%d\n",e);
	}else{
		printf("位序i不合法，删除失败\n");
	}
	int x=GetElem(L,3);
	int weixu=LocateElem(L,123);
	return 0;
}
 */





//对于动态分配存储结构的顺序表的创建和初始化
#define InitSize 10
typedef struct{
	int* data;
	int length;
	int MaxSize;
}SeqList;
//初始化
void InitList(SeqList* L){
	L->data=(int*)malloc(sizeof(int)*InitSize);
	L->length=0;
	L->MaxSize=InitSize;
}
//插入元素
void IncreaseSize(SeqList* L,int len){
	int* q=L->data;//！！！！！结构体指针L指向了结构体，然后结构体里面有一个data指针，指向了malloc开辟的连续的int型数据空间
	L->data=(int*)malloc(sizeof(int)*(L->MaxSize+len));
	for(int i=0;i<L->length;i++){
		L->data[i]=q[i];//L->data[i]的写法是非常重要的，这是访问“L指向的结构体，结构体指针又指向的malloc创建的连续int型数据”的内存空间
	}
	L->MaxSize=L->MaxSize+len;//容易忘记
	free(q);//容易忘记
}
//按位查找
int GetElem(SeqList L,int i){
	return L.data[i-1];//！！！！！L.data会拿到地址，而地址[偏移量]就是地址所指的位置加偏移量后的数据
}
//按值查找（若是结构体类型时，则自己创建一个函数，结构体中每个属性都相同时，即为“相同”）
int LocateElem(SeqList L,int e){
	for(int i=0;i<L.length;i++){
		if(L.data[i]==e){
			return i+1;
		}
	}
	return 0;
}
int main(){
	SeqList L;
	InitList(&L);
	IncreaseSize(&L,10);
	printf("%d\n",L.MaxSize);
	int x=GetElem(L,5);
	int weixu=LocateElem(L,123);
	return 0;
}
 





