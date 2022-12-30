#ifndef FAMILYMART_H
#define FAMILYMART_H
#include<iostream>
#include <vector>
#include <string.h>
#include <stdio.h>
#include <string>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <cstring>
//#include "tool.h"
#include "CommodityList.h"
//#include "Commodity.h"

using namespace std;
using std::string;  //使用string对象
using std::vector;


//TODO 
// you need to modify this file
// you need to finish this class, but don't change the definition of the existing functions below.


class FamilyMart {
    public:
        FamilyMart();  // no any commodity
    
    	// using file name to construct FamilyMart
    	// the format of file is the same as purchase.txt
        FamilyMart(const string& cmmodity_file_name); 
    
    	// using file name add new commodities in every morning, the format of file is the same as purchase.txt
        void purchase_file(const string& cmmodity_file_name);
    
    	//the same as above, this is sell process
        void sell_file(const string& sellFile);
        
    
    	//return a total sales, a turnover snice the start of new FamilyMart.
        double show_turnover();
    
    	// ... your other function
    	CommodityList*  disposal(CommodityList* temp);   //处理过期商品
    	
    	//CommodityList get_commodities();  
    	
    	string get_date();
    	
    	void set_date(string date);

		double discount_method(double price, double discount = 1);

		void print(CommodityList* temp);
    	
    	//int get_days();
    	
    	//void set_days();
    	
    private:
    	// some attributes
    	double turnover = 0;  //销售额
    	
    	 
    	//int days;    //开店天数
    	
    	string date;  //当前日期
    	
        CommodityList *head = new CommodityList;    // 商品链表头
    	
    	//CommodityList *sold_out_head;        // 售完商品链表

};

FamilyMart::FamilyMart(){
	this -> turnover = 0;
	this -> head = init();
	this -> date = "2021/5/2";
}

double FamilyMart::show_turnover(){
	return this -> turnover;
}

string FamilyMart::get_date(){
	return this -> date;
}

void FamilyMart::set_date(string date){
	this -> date = date;
}

CommodityList* FamilyMart::disposal(CommodityList* temp){
	CommodityList *head1 = temp;
	while(temp -> next != NULL){
		CommodityList *p = temp -> next;
		//商品的过期日先于今天则删除
		if(compare_date(p->expire_date,this->date)<0){
			delete_node(head,p->name);
			cout << p->name << ": "<<p-> expire_date << " expierd!" <<endl;
			temp = temp;
		}else{
			temp = temp ->next;
		}
		
	}
	return head1;
}

double FamilyMart::discount_method(double price,double discount){
	return price * discount;
}

void FamilyMart:: purchase_file(const string& cmmodity_file_name){
	ifstream input_file(cmmodity_file_name);
	string line;

    vector<string> list;  

    //文件不存在
    if(!input_file)
    {
        cout<<"file can not open"<<endl;   
        abort();
    }

	while(getline(input_file,line)){
		list.push_back(line);
	}

    for(int i = 1; i < list.size(); i++){
         vector<string> res;
        //暂存从word中读取的字符串 
        string result;
        //将字符串读到input中 
        stringstream input(list[i]);
    //依次输出到result中，并存入res中 
        while(input>>result){
            res.push_back(result);
		}

    	if(res.size()==4){
			string name = res[0];   //商品名字
			double price = atof(res[1].c_str());   //价格
			int life = atoi(res[2].c_str());     
			string product_date = res[3];
			Commodity commodity = Commodity(name,price,life,product_date);
			this -> head = add_node(head,commodity);   //将商品插入链表
		}

    }
//	print(head);

    //处理过期产品
	this -> head = disposal(head);
//	print(head);
	

}

void FamilyMart::sell_file(const string& sellFile){
	ifstream input_file(sellFile);
	string line;

    vector<string> list;  

    //文件不存在
    if(!input_file)
    {
        cout<<"file can not open"<<endl;   
        abort();
    }

	while(getline(input_file,line)){
		list.push_back(line);
	}

    for(int i = 1; i < list.size(); i++){
         vector<string> res;
        //暂存从word中读取的字符串 
        string result;

        //将字符串读到input中 
        stringstream input(list[i]);
    //依次输出到result中，并存入res中 
        while(input>>result){
            res.push_back(result);
		}

        //有折扣
    	if(res.size()==2){
			string name = res[0];   //商品名字
			double discount = atof(res[1].c_str());   //折扣
			CommodityList* temp = find_node(this -> head,name);
			if(temp == NULL){
				cout << name <<" had sold out!" <<endl;
			}else{
				double sell_price = discount_method(temp->price,discount);   //传入折扣，得到商品售价
				turnover += sell_price;    //销售额增加
				this -> head = delete_node(this -> head,name);  //删除商品
			}
		}
		
		//没有折扣
		if(res.size()==1){
			string name = res[0];   //商品名字
			//double discount = atof(res[1].c_str());   //折扣
			CommodityList* temp = find_node(this -> head,name);
			if(temp == NULL){
				cout << name <<" had sold out!" <<endl;
			}else{
				double sell_price = discount_method(temp->price);   //得到商品售价
				turnover += sell_price;    //销售额增加
				this -> head = delete_node(this -> head,name);  //删除商品
			}
		}

    }

	this -> date = date_add(this -> date,1);  //商店当前日期加一天
	//print(head);

}

void FamilyMart::print(CommodityList* temp){ 
    CommodityList* a = temp;
	while(a->next!=NULL){
		cout<< a->next->name << a->next->expire_date << "---->";
		a =a->next;
	}
	cout <<endl;
}














	


#endif //FAMILYMART_H
