#include <iostream>
#include <vector>
#include <fstream>
#include "lab7.h"
using namespace std;


void readFile(const string &input_firename) {
	ifstream input_file(input_firename);

    ofstream output_file("output.txt");

    string line;

    vector<string> list;

    //文件不存在
    if (!input_file)
    {
        cout << "file can not open" << endl;
        abort();
    }
    if (!output_file.is_open()) 
    { 
        cout << "fail to create file" << endl;
        abort();
    }

    while (getline(input_file, line)) {
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

    	if(res.size()==1 && res[0]==">>"){
            BigInt a = BigInt("");
			cout << "please enter number: " <<endl;
            cin >> a;
            output_file << a.output()<< endl;
		}else if(res.size()==2 && res[0]=="<<"){
            if(res[1].size()>100){
                cout << "the length mun must be under 100!";
                output_file << "the length of number must be under 100!"<< endl;
            }else{
                BigInt a = BigInt(res[1]);
                output_file << a.output() << endl;
            }
        }else if(res.size()==3){
			if(res[0].length()>100||res[2].length()>100){
				//cout <<"length: " <<res[0].length() << endl;
				cout << "the length mun must be under 100!";
                output_file << "the length of number must be under 100!"<< endl;
			}else{
				BigInt num1 = BigInt(res[0]);
				BigInt num2 = BigInt(res[2]);
				BigInt result = BigInt("");
				if(res[1] == "+"){
					result = num1 + num2;
					output_file << result.output() << endl;
				}else if(res[1] == "-"){
					result = num1 - num2;
					output_file << result.output() << endl;
				}else{
					cout << "input format error!" <<endl;
					//output_file << "the length of number must be under 100!" << endl;
				}
			}

        }else{
            cout << "input format error!" <<endl;
           // output_file << "input format error!" << endl;
        }
    }

    input_file.close();
    output_file.close();

}

int main()
{
    readFile("test.in");
	return 0;
}