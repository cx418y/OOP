#include <iostream>
#include <windows.h>
#include <ctime>
#include <iomanip>
#include <conio.h>
#include <string>
#include "lab.h"

int maxsize = 20;

class Stack{
	public:
		int top;
		int ***game = new int**[maxsize];
	    int *scores = new int[maxsize]; 
		Stack();
		void push(int** grid ,int score);
		int** grid_pop();
		int score_pop();
};

//��ʼ��ջ 
Stack::Stack(void){
	this -> top = -1;
	for(int i = 0 ;i < maxsize; i++){
	//	game[i] = (int**)malloc(sizeof(int*)*size);
	    game[i] = new int*[size];
	}
	for(int i = 0; i < maxsize; i++){
		for(int j = 0; j < size; j++){
			//game[i][j] = (int*)malloc(sizeof(int)*size);
			game[i][j] = new int [size];
		}
	}
	for(int i = 0; i < maxsize; i++){
		for(int j = 0; j < size; j++){
			for(int k = 0; k < size; k++){
				game[i][j][k] = 0;
			}
		}
	}
	for(int i = 0; i < maxsize; i++){
		scores[i] = 0;
	}
	
}

//����µ����̺͵÷� 
void Stack::push(int** grid, int score){
	//ջδ�� 
	if(top < maxsize - 1){
		top ++;
		for(int i = 0; i < size; i++){
			for (int j = 0; j < size; j++){
				game[top][i][j] = grid[i][j];
			}
		}
		scores[top] = score; 
	}
    //ջ�����Ƴ�������ջԪ�� 
	else{
		//�Ƴ����� 
		for(int k = 1; k < maxsize; k++){
			for(int i = 0;i < size; i++){
				for (int j = 0; j < size; j++){
		    		game[k-1][i][j] = game[k][i][j];
		    	}
			}
		}
		for(int i = 0;i < size; i++){
			for (int j = 0; j < size; j++){
	    		game[top][i][j] = grid[i][j];
	    	}
		}
		//�Ƴ��÷� 
		for(int i = 1; i < maxsize; i++){
			scores[i-1] = scores[i];
		} 
		scores[top] = score; 
	}
}

int** Stack::grid_pop(){
	int** current_grid = new int* [size];
	for(int i = 0;i < size; i++){
		current_grid[i] = new int[size];
		for(int j = 0; j < size; j++){
			current_grid[i][j] = game[top][i][j];
		}
	}
	for(int i = 0;i < size; i++){
		for(int j = 0; j < size; j++){
			game[top][i][j] = 0;
		}
	} 
	return current_grid;
}

int Stack::score_pop(){
	int current_score = scores[top];
	scores[top] = 0;
	top --;
	return current_score;
}

