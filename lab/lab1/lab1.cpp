#include <iostream>
#include <windows.h>
#include <ctime>
using namespace std;

int const COL = 4;
int const ROW = 4;
int game[16] = {0};

void print(){
	cout <<"+-----+-----+-----+-----+"<< endl; 
	for(int i = 0; i < ROW; i++){
		for(int j = 0; j < COL; j++){
			if(game[i*4+j]==0){
				cout << "|     ";
			}
			else{
				cout << "|  2  ";
			}
		}
		cout << "|" << endl;
			cout <<"+-----+-----+-----+-----+"<< endl;
	}
}

int main(){
	print();
	int times = 0;
	while(times != ROW*COL){
		string a;
		cin >>  a;
		cout << ch1; 
		if(a=="n"){
		srand(time(NULL));
        int n =rand()%16;
		while(game[n]==2){
			srand(time(NULL));
            n =rand()%16;
		}
		game[n] = 2;
		print();
		times++;
	}
	else{
		cout <<"Please enter 'n'"<< endl;
	}
}
    cout <<"game over"<< endl;
	return 0;
}
    



