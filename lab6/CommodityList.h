
#include <vector>
#include <string.h>
#include <stdio.h>
#include <string>
//#include "tool.h"
#include "Commodity.h"


struct CommodityList
{
    string name;   // 名称
		
	double price;    //价格
		
	string expire_date;     //过期日期

    CommodityList* next;
};


CommodityList* init(){
    CommodityList *temp = new CommodityList;
    temp->name=" ";
    temp->price = 0;
    temp -> expire_date = "2021/5/1";
    temp->next = NULL;
    return temp;
}

//向链表添加商品
CommodityList* add_node(CommodityList *commodityList,Commodity commodity){
    CommodityList* head = commodityList;
        //按照过期时间先后链接链表
    while(commodityList->next!=NULL){
        if(compare_date(commodityList->next->expire_date,commodity.get_expire_date())>0){
            CommodityList* temp = new CommodityList;
            temp->name = commodity.get_name();
            temp->price = commodity.get_price();
            temp->expire_date = commodity.get_expire_date();
            temp->next = commodityList->next;
            commodityList->next = temp;
            return head;
        }
        commodityList = commodityList->next;
    }

    CommodityList* temp = new CommodityList;
    temp->name = commodity.get_name();
    temp->price = commodity.get_price();
    temp->expire_date = commodity.get_expire_date();
    temp->next = NULL;
    commodityList->next = temp;
    return head;
}


 CommodityList* find_node(CommodityList *commodityList,string name){
    while(commodityList->next!=NULL){
        CommodityList* temp = commodityList->next;
        if(name.compare(temp->name)==0){  //找到商品返回true；
            return temp;
        }
        commodityList = commodityList->next;
    }
    return NULL;
}

CommodityList* delete_node(CommodityList *commodityList,string name){
    CommodityList* head = commodityList;
    while(commodityList->next!=NULL){
        CommodityList* temp = commodityList->next;
        if(name.compare(temp->name)==0){
            commodityList->next = temp->next; //删除节点
            return head;
        }
        commodityList = commodityList->next;
    }
    return head;
}
