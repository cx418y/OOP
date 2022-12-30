#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <cstring>
#include <cstdlib>
#include "head.h"
#ifndef FAMILYMART_H
#define FAMILYMART_H
using namespace std;
//TODO 
// you need to modify this file
// you need to finish this class, but don't change the definition of the existing functions below.



//Node tmp;

class FamilyMart {
    public:
        FamilyMart();  // no any commodity
    
    	// using file name to construct FamilyMart
    	// the format of file is the same as purchase.txt
        FamilyMart(const string& cmmodity_file_name); 
    
    	// using file name add new commodities in every morning, the format of file is the same as purchase.txt
        void purchase_file(const string& cmmodity_file_name);
    
    	//the same as above, this is sell process//default:there is no discount
        void sell_file(const string& sellFile);
    
    	//return a total sales, a turnover snice the start of new FamilyMart.
        double show_turnover();
    
    	// ... your other function

    private:
    	
    	struct Node *p=new Node,*head=new Node,*tail=new Node;
		struct Node *p1=new Node,*p2=new Node;
		//struct Node *tmp;
		
    	vector<string> sellProduct;
    	vector<string> sellProductName;
    	vector<string> sellProductDiscount;
    	
    	vector<string> storeProduct;
		vector<string> storeProductName;
    	vector<string> storeProductPrice;
    	vector<string> storeProductLife;
    	vector<string> storeProductProductDate;
    	
    	string temp;
    	int profit;
    	//int month=4;
    	//int day=25;
    	int month;
    	int day;
    	int turnover;//the product number that are removed because of over the valid day
    	
    	
    	int productDay;
    	int validDay;
    	int price;
    	string name;
    	// different attributes

};

class Commodity:public FamilyMart{
	public:
		//use this while there is discount
		void sell_file(const string& sellFile);
};


FamilyMart::FamilyMart(){
	
}

FamilyMart::FamilyMart(const string& cmmodity_file_name){
	
}

void FamilyMart::purchase_file(const string& cmmodity_file_name){//读取存入目前OK 
	char buffer[1000];
	int number;
	ifstream file(cmmodity_file_name.c_str());
	//Node *tmp=new Node;
	while((!file.eof())){
		vector<string> productTemp;
		file.getline(buffer,1000);
		stringstream input(buffer);
		while(input>>temp){
		 	productTemp.push_back(temp);
		}
		if((productTemp.size()==4)&&(number!=0)){
			Node *tmp=new Node;
			
			tmp->name=productTemp[0];
			
			stringstream s(productTemp[1]);
			s>>tmp->price;
			
			stringstream ss(productTemp[2]);
			ss>>tmp->life;

        	char arrDate[10];
        	strcpy(arrDate,productTemp[3].c_str());
        	char *tokenPtr=strtok(arrDate,"/");

        	tmp->year = atoi(tokenPtr);
        	tokenPtr=strtok(NULL,"/");
        	tmp->month = atoi(tokenPtr);
        	tokenPtr=strtok(NULL,"/");
        	tmp->day = atoi(tokenPtr);
        	
        	
        	tmp->next=NULL;
			
			
			if(number==1){
				head=CreateLinkedList(tmp) ;
			}			
			else{
				head=AddNode(head,  tmp);
			}
		}
		number++;
	}
	ShowList(head);
} 

void FamilyMart::sell_file(const string& sellFile){
	char buffer[1000];
	int sellNumber;
	ifstream file(sellFile.c_str());
	while(!file.eof()){
		vector<string> sellTemp;
		file.getline(buffer,1000);
		//cout<<buffer<<endl;
		stringstream input(buffer);
		while(input>>temp){
		 	sellProduct.push_back(temp);
		}
		if((sellProduct.size()==2)&&(sellNumber!=0)){
			Node *tmp=new Node;
			tmp->name=sellProduct[0];
			
			stringstream s(sellProduct[1]);
			s>>tmp->discount;
			
			cout<<getPositionByName(head,tmp->name)<<"asdf"<<endl; 
		}
		else if((sellProduct.size()==1)&&(sellNumber!=0)){
			Node *tmp=new Node;
			tmp->name=sellProduct[0];
			
			tmp->discount=1;
			
			cout<<getPositionByName(head,tmp->name)<<"asdf"<<endl; 
		}
		
		sellNumber++;
	}
} 

double FamilyMart::show_turnover(){
    /*for(int i=0;i<sellProductName.size();i++){
        cout<<sellProductName[i]<<endl;
    }
    
    for(int i=0;i<storeProductProductDate.size();i++){
        int realYear,realMonth,realDay;
        char arrDate[10];
        strcpy(arrDate,storeProductProductDate[i].c_str());
        char *tokenPtr=strtok(arrDate,"/");

        realYear = atoi(tokenPtr);
        tokenPtr=strtok(NULL,"/");
        realMonth = atoi(tokenPtr);
        tokenPtr=strtok(NULL,"/");
        realDay = atoi(tokenPtr);
        cout<<realYear<<"/"<<realMonth<<"/"<<realDay<<endl; 
    }   */
    
    cout<<"end of the day"<<month<<"月"<<day<<"日"<<endl;
    
    
    //for(int 0;i<) 
    
    if(month%2==0&&day<30){
    	day++;
	}
	else if(month%2==0&&day>=30){
		month++;
		day=1;
	}
	else if(month%2==1&&day<31){
		day++;
	}
	else{
		month++;
		day=1;
	}//add one day 
} 





#endif //FAMILYMART_H
