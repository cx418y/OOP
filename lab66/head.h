#include <iostream>
using namespace std;

 
struct Node
{
	string name;
	int life;
	int year;
	int month;
	int day;
	float price;
	int data;
	float discount;
	struct Node *next;  //该指针指向下一个结构体，next为一个结点的指针，和header效果一样
};
 
Node *CreateLinkedList(Node *templt);
int LengthOfList(Node *header_node);
void ShowList(Node *header_node);
Node *DeleteNode(Node *header_node, int pos);
Node *AddNode(Node *header_node, int pos, Node *new_node);
 
Node *CreateLinkedList(Node *templt)   //相当于将Node当成一个新的数据类型，因为要返回的是一个指针，所以定义为Node *
{
	Node *header_node;  
	header_node=templt;
	return header_node;
};

int getPositionByName(Node *header_node,string name){
	Node *cur = header_node;
	int pos=0;
	int number=0;
	int year,month,day;
	year=cur->year;
	month-cur->month;
	day=cur->day;
	while(cur!=NULL){
		cur=cur->next;
		number++;
		if(cur->month<month){
			pos=number;
			month=cur->month;
		}
		else if(cur->day<day){
			pos=number;
			day=cur->day;
		}
	}//寻找最早生产的商品 
	return pos;
}
 
int LengthOfList(Node *header_node)
{
	Node *cur = header_node;
	if(header_node == NULL)
	{
		cout << "该表无数据" << endl;
		return 0;
	}
	else
	{
		int length = 1;
		while(cur->next != NULL)
		{
			length++;
			cur = cur->next;
		}
		return length;
	}
}
 
void ShowList(Node *header_node)
{
	Node *cur = header_node;
	//for(int i = 0; i < LengthOfList(header_node); i++)
	cout <<cur->name<<cur->year<<"/"<<cur->month<<"/"<<cur->day<< endl;
	while(cur->next!=NULL)
	{
		cout <<cur->next->name<<cur->next->year<<"/"<<cur->next->month<<"/"<<cur->next->day<< endl;
		cur = cur->next;
	}
}
 
Node *DeleteNode(Node *header_node, int pos)  //删除头结点后第pos个结点，pos大于0
{
	int length = LengthOfList(header_node);
	if(pos <= 0 || length == 0)
	{
		cout << "删除错误" << endl;
	}
	else
	{
		cout << "删除头结点后第" << pos << "个结点：" << endl;
		Node *cur = header_node;  //定义当前指针
		Node *pre = cur;  //定义上一个位置的指针
		for(int i = 0; i < pos; i++)  //移动当前指针到要删除的位置
		{
			pre = cur;
			cur = cur->next;
		}
		if(pos == length)
			pre->next = NULL;
		else
			pre->next = cur->next;
	}
	return header_node;
}
 
Node *AddNode(Node *header_node, Node *new_node)  //在头结点后第pos个结点后面插入新结点，pos>=0
{
	int pos = LengthOfList(header_node);
	if(pos < 0 || pos== 0)
	{
		cout << "插入错误" << endl;
	}	
	else
	{
		//cout << "在头结点后第" << pos << "个结点的后面插入元素：" << endl;
		Node *cur = header_node;  //定义当前指针
		//Node *new_node = new Node;  //为新加入的结点开辟空间
		//new_node->data = add_number;
		//for(int i = 0; i < pos; i++)
		while(cur->next!=NULL)
		{
			cur = cur->next;
		}		
		//if(pos == length)
		//{
			cur->next = new_node;
			new_node->next = NULL;
		//}
		//else
		//{
			//new_node->next = cur->next;
			//cur->next = new_node;
		//}
	}
	return header_node;
}

 

