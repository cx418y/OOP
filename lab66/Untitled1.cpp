#include<iostream>
#include<string>
#include<sstream>
#include<vector>
#include <fstream>

#include <cstdlib>
using namespace std;

int compare_date(string date1,string date2){
	//分割字符串，得到年、月、天
	int pos1 = 0;
	int pos2 = 0;
	int year1 = 0;
	int month1 = 0;
	int day1 = 0;
	pos1 = date1.find("/", 0);
	pos2 = date1.find("/",pos1+1);
	//year1 = atoi(date1.substr(0,4).c_str())
	year1 = std::stoi(date1.substr(0,4));
	month1 = std::stoi(date1.substr(5,pos2-pos1-1));
	day1 = std::stoi(date1.substr(pos2+1,date1.length()-pos2-1));

	int pos3 = 0;
	int pos4 = 0;
	int year2 = 0;
	int month2 = 0;
	int day2 = 0;
	pos3 = date2.find("/", 0);
	pos4 = date2.find("/",pos3+1);
	year2 = std::stoi(date2.substr(0,4));
	month2 = std::stoi(date2.substr(5,pos4-pos3-1));
	day2 = std::stoi(date2.substr(pos4+1,date2.length()-pos4-1));

	if(year1 == year2){
		if(month1 == month2){
			return day1 - day2;
		}else{
			return month1 - month2;
		}
	}else{
		return year1 - year2;
	}
	
	return 1;
}

string date_add(string date, int days){
	//分割date
	int pos1 = 0;
	int pos2 = 0;
	int year = 0;
	int month = 0;
	int day = 0;
	pos1 = date.find("/", 0);
	pos2 = date.find("/",pos1+1);
	year = std::stoi(date.substr(0,4));
	month = std::stoi(date.substr(5,pos2-pos1-1));
	day = std::stoi(date.substr(pos2+1,date.length()-pos2-1));

    //二月:
	if(month == 2){
		if(day + days <= 28){
			day = day +days;
		}else{
			month++;
			day = day + days - 28;
		}
	}
	else if(month == 12){//12月
		if(day + days <= 30){
			day = day +days;
		}else{
			month = 1;
			day = day + days - 28;
			year++;
		}   
	}else if((month <= 6 && month % 2 ==0)||(month >= 9 && month % 2 == 1)){   //小月
	    if(day + days <= 30){
			day = day +days;
		}else{
			month++;
			day = day + days - 30;
		}
	}else{  //大月
		 if(day + days <= 31){
			day = day +days;
		}else{
			month++;
			day = day + days - 28;
		}
	}
	date = std::to_string(year)+"/" +std::to_string(month)+"/"+std::to_string(day);
	return date;
} 

int main(){
    

    string date1="2021/5/4";
	int pos1 = 0;
	int pos2 = 0;
	int year1 = 0;
	int month1 = 0;
	int day1 = 0;
	pos1 = date1.find("/", 0);
	pos2 = date1.find("/",pos1+1);
	year1 = std::stoi(date1.substr(0,4));
	month1 = std::stoi(date1.substr(5,pos2-pos1-1));
	day1 = std::stoi(date1.substr(pos2+1,date1.length()-pos2-1));
	

	int a = compare_date("2021/12/3","2021/6/3");
	//cout << a <<endl; 

	string add = date_add("2021/4/26",6);
	cout << add <<endl;

    string s ="7.5";
	double n = atof(s.c_str());
	string s1 = "5.5";
	double n2 = atof(s1.c_str());
	//cout << n2 <<endl;
	//cout <<n+n2 <<endl;
}
