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
	struct Node *next;  //��ָ��ָ����һ���ṹ�壬nextΪһ������ָ�룬��headerЧ��һ��
};
 
Node *CreateLinkedList(Node *templt);
int LengthOfList(Node *header_node);
void ShowList(Node *header_node);
Node *DeleteNode(Node *header_node, int pos);
Node *AddNode(Node *header_node, int pos, Node *new_node);
 
Node *CreateLinkedList(Node *templt)   //�൱�ڽ�Node����һ���µ��������ͣ���ΪҪ���ص���һ��ָ�룬���Զ���ΪNode *
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
	}//Ѱ��������������Ʒ 
	return pos;
}
 
int LengthOfList(Node *header_node)
{
	Node *cur = header_node;
	if(header_node == NULL)
	{
		cout << "�ñ�������" << endl;
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
 
Node *DeleteNode(Node *header_node, int pos)  //ɾ��ͷ�����pos����㣬pos����0
{
	int length = LengthOfList(header_node);
	if(pos <= 0 || length == 0)
	{
		cout << "ɾ������" << endl;
	}
	else
	{
		cout << "ɾ��ͷ�����" << pos << "����㣺" << endl;
		Node *cur = header_node;  //���嵱ǰָ��
		Node *pre = cur;  //������һ��λ�õ�ָ��
		for(int i = 0; i < pos; i++)  //�ƶ���ǰָ�뵽Ҫɾ����λ��
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
 
Node *AddNode(Node *header_node, Node *new_node)  //��ͷ�����pos������������½�㣬pos>=0
{
	int pos = LengthOfList(header_node);
	if(pos < 0 || pos== 0)
	{
		cout << "�������" << endl;
	}	
	else
	{
		//cout << "��ͷ�����" << pos << "�����ĺ������Ԫ�أ�" << endl;
		Node *cur = header_node;  //���嵱ǰָ��
		//Node *new_node = new Node;  //Ϊ�¼���Ľ�㿪�ٿռ�
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

 

