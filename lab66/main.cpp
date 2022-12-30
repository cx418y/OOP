#include <iostream>
#include "FamilyMart.h"
#include <sstream>
#include <vector>
using namespace std;
// modify this file to test your logics
// TODO 

int main() {
    
    FamilyMart *test_mart = new FamilyMart();
    string filename1,filename2;
    int date=502;
    for (int i= 0; i<1; i++){
    	std::cout << "2021 0"<< date << std::endl;
        std::cout << "Today is beginning" << std::endl;
    	std::cout << "please input purchase list file name" << std::endl;
		//std::cin>>filename1;
        //test_mart->purchase_file(filename1);
        test_mart->purchase_file("purchase.txt");
        //std::cout << "please input sell list file name" << std::endl;
		//std::cin>>filename2;
        test_mart->sell_file("sell.txt");
        std::cout << "This day is over" << std::endl;
        std::cout << "turnover:" << test_mart->show_turnover() << std::endl;
        date++;
    }
    
    delete test_mart;
    
    return 0;
}



