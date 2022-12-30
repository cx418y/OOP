#include <iostream>
#include <windows.h>
#include <ctime>
#include <iomanip>
#include <conio.h>
#include <string>
#include "lab.h"
#include "stack.cpp"

using namespace std;

int size = 4;

class Game{
	public:
		int score;	
		int **grid = new int*[size];
		int **empty = new int*[size*size];	
		int winNumber;
		bool gameWin;
		bool gameOver;
		string userName;
		int step = 0;
		
		Game();  //���캯�� 
		void Print();
		void CreateNum();
		int Input1(int input);
		int Input2(int input);
		bool CanMove(int direction);
		void move(int direction);
		bool GameContinue();
		
		
		void setWinNumber(int winNumber);
		void setUserName(string name); 
};

// ���췽��ʵ�� 
Game::Game(void){
	this -> score = 0;
	this -> winNumber = 2048;
	this -> gameWin = false;
	this -> gameOver = false;
	this -> userName = "";
	for(int i = 0;i < size; i++){
		grid[i] = new int[size];
		for(int j = 0 ; j < size ;j++){
			grid[i][j] = 0;
		}
	}
	for(int i = 0; i < size*size; i++){
		empty[i] = new int[2];
		for(int j = 0;j < 2; j++){
			empty[i][j] = 0; 
		}
	}
	srand(time(0));
    grid[rand()%size][rand()%size] = 2;	
} 
void Game::setUserName(string name){
	this -> userName = name;
} 

void Game::setWinNumber(int winNumber){
	this -> winNumber = winNumber;
}

//��ӡ���� 
void Game::Print(){
	
	for(int i = 0; i < size; i++){cout <<"+-----";}
	cout <<"+"<< endl; 
	
	for(int i = 0; i < size; i++){
		for(int j = 0; j < size; j++){
			if(grid[i][j] == 0){
				cout << "|     ";
			}
			else {
				cout <<"| "<<std::left<<setw(4) << grid[i][j];
			}
		}
		cout << "|" << endl;
		for(int k = 0 ; k < size; k++){cout <<"+-----";}
		cout <<"+"<< endl; 
		
	}
	cout<<" "<<endl;
}

// ����ڿյ�λ����������2 
void Game::CreateNum(){
	int emptyNum = 0;
	for(int i = 0; i < size; i++){
		for(int j = 0; j < size; j++){
			if(grid[i][j]== 0){
				empty[emptyNum][0] = i;
				empty[emptyNum][1] = j;
				
				emptyNum++;
			}
       }
    }
    //���������������� 
    if(emptyNum != 0){
	    //����ڿո���������
	    srand(time(NULL));
	    int n = rand()%emptyNum;
        int x = empty[n][0];
        int y = empty[n][1];
        grid[x][y] = 2;
    }
}

bool Game::GameContinue(){
	//��Ϸ��ʤ
	for(int i = 0; i < size; i++){
		for(int j = 0; j < size;j++){ 
			if(grid[i][j] == winNumber){
				gameWin = true;
				return false;
			}
		}
	}
	//������޿ո� 
	for(int i = 0; i < size; i++){
		for(int j = 0;j < size; j++){
			if(grid[i][j] == 0){
				return true;
			}
		} 
	}
	
	//���������޿ɺϲ��� 
	for(int i = 0; i < size;i++){
		for(int j = 0; j < size - 1; j++){
			if(grid[i][j] == grid[i][j+1]){
				return true;
			} 
		}
	}
	
	//���������޿ɺϲ���
	for(int i = 0;i < size - 1; i++){
		for(int j = 0; j < size;j++){
			if(grid[i][j] == grid[i+1][j]){
				return true;
			}
		}
	}
	
	gameOver = true;
	return false; 
} 

bool Game::CanMove(int direction){
	switch(direction){
		case 1:
			for(int i = 1;i < size; i++){
	           	for(int j = 0; j < size;j++){
			        if((grid[i][j]  != 0)&& (grid[i][j] == grid[i-1][j] || grid[i-1][j] == 0)){
				        return true;
			        }
		       }      
	       }
		   break; 
		case 2:
			for(int i = size-2;i >= 0; i--){
	           	for(int j = 0; j < size;j++){
			        if((grid[i][j]  != 0)&& (grid[i][j] == grid[i+1][j] || grid[i+1][j] == 0)){
				        return true;
			        }
		       }      
	       } 
		   break;
		case 3:
			for(int i = 0; i < size;i++){
		        for(int j = 1; j < size; j++){
			        if((grid[i][j]  != 0) && (grid[i][j] == grid[i][j-1] || grid[i][j-1] == 0)){
				        return true;
			        } 
		        }
	        } 
			break;
		case 4:
		    for(int i = 0; i < size;i++){
		        for(int j = size - 2 ; j >= 0; j--){
			        if((grid[i][j]  != 0) && (grid[i][j] == grid[i][j+1] || grid[i][j+1] == 0)){
				        return true;
			        }
		        }
	        } 
			break;
		default:
			return false;
			break;		
	}
	return false;
} 

int Game::Input1(int input){
	int direction = 0;
	switch(input){
		//up
		case 72:
		    direction = 1;
		    break; 
		    
	   //down
	   case 80:
	   	    direction = 2;
		    break; 
		    
	   //left
	   case 75:  
	  	    direction = 3;
		    break; 
		    
	   //right
	   case 77:
	   	    direction = 4;
		    break; 
    }
	return direction;
} 

int Game::Input2(int input){
	int direction = 0;
	switch(input){
		//up
		case 119:  //w 
		    direction = 1;
		    break; 
		    
	   //down
	   case 115:  //s
		    direction = 2;
		    break; 
		    
	   //left
	   case 97:  //a
		    direction = 3;
		    break; 
		    
	   //right
	   case 100:  //d
	   	    direction = 4;
		    break; 
		
    }
	return direction;
} 

//�ƶ� 
void Game::move(int direction){
	switch(direction){
		case 1:
			//�����ƶ����ϲ� 
			for(int i = 1; i < size; ++i){
				for(int j = 0; j < size;++j){
					//��һ������Ϊ�� 
					if(grid[i][j] != 0){
					    for(int k = i;k>0;--k){
					        if(grid[k-1][j] == 0){ 
					     	    grid[k-1][j] = grid[k][j];
						        grid[k][j] = 0;
					        }
				        }
			        }
				}
			}
			//�ϲ� 
			for(int i = 1; i < size; ++i){
				for(int j = 0; j < size;++j){
					//��һ����������������ͬ��ϲ� 
					if(grid[i][j] != 0){
					    if(grid[i-1][j] == grid[i][j]){
						    grid[i-1][j] = (grid[i][j])*2;
						    score += grid[i-1][j];  //��¼�÷� 
						    grid[i][j] = 0;
					    }
					}
				}
			}
			//���ƶ�һ�� 
			for(int i = 1; i < size; ++i){
				for(int j = 0; j < size;++j){
					//��һ������Ϊ�� 
					if(grid[i][j] != 0){
					    for(int k = i;k>0;--k){
					        if(grid[k-1][j] == 0){ 
					     	    grid[k-1][j] = grid[k][j];
						        grid[k][j] = 0;
					        }
				        }
			        }
				}
			}
			break;
			
		case 2:
			//�����ƶ����ϲ� 
			for(int i = size-2; i >= 0; i--){
				for(int j = 0; j < size;j++){
					//��һ������Ϊ�� 
					for(int k = i;k<size-1;k++){
					    if(grid[k+1][j] == 0){ 
					    	grid[k+1][j] = grid[k][j];
				    		grid[k][j] = 0;
				    	}
			     	}
				}
			}
			//�ϲ� 
			for(int i = size - 2; i >= 0; i--){
				for(int j = 0; j < size;j++){
					//��һ����������������ͬ��ϲ� 
					if(grid[i][j] != 0){
					    if(grid[i+1][j] == grid[i][j]){
						    grid[i+1][j] = grid[i][j]*2;
						    score += grid[i+1][j];
						    grid[i][j] = 0;
					    }
					}
				}
			}
			//���ƶ�һ�� 
			for(int i = size-2; i >= 0; i--){
				for(int j = 0; j < size;j++){
					//��һ������Ϊ�� 
					for(int k = i;k<size-1;k++){
					    if(grid[k+1][j] == 0){ 
					    	grid[k+1][j] = grid[k][j];
				    		grid[k][j] = 0;
				    	}
			     	}
				}
			}
			break;
			
		case 3:
			//�����ƶ����ϲ� 
			for(int j = 1; j < size; j++){
				for(int i = 0; i < size;i++){
					for(int k = j;k>0;k--){
					    //��һ������Ϊ��
			    		if(grid[i][k-1] == 0){ 
				    		grid[i][k-1] = grid[i][k];
					    	grid[i][k] = 0;
					}
				}
				}
			}
			//�ϲ� 
			for(int j = 1; j < size; j++){
				for(int i = 0; i < size;i++){
					//��һ����������������ͬ��ϲ� 
					if(grid[i][j] != 0){
					    if(grid[i][j-1] == grid[i][j]){
						    grid[i][j-1] = grid[i][j]*2;
						    score += grid[i][j-1];
						    grid[i][j] = 0;
					    }
					}
				}
			}
			//���ƶ�һ�� 
			for(int j = 1; j < size; j++){
				for(int i = 0; i < size;i++){
					for(int k = j;k>0;k--){
					    //��һ������Ϊ��
			    		if(grid[i][k-1] == 0){ 
				    		grid[i][k-1] = grid[i][k];
					    	grid[i][k] = 0;
					}
				}
				}
			}
			break;
			
		case 4:
			//�����ƶ����ϲ� 
			for(int j = size-2; j >= 0 ; j--){
				for(int i = 0; i < size;i++){
					for(int k = j; k<size-1;k++){
				
				    	//��һ������Ϊ��
	    				if(grid[i][k+1] == 0){ 
		    				grid[i][k+1] = grid[i][k];
			    			grid[i][k] = 0;
					}
				}
				}
			}
			//�ϲ� 
			for(int j = size-2; j >= 0 ; j--){
				for(int i = 0; i < size;i++){
					//��һ����������������ͬ��ϲ� 
					if(grid[i][j] != 0){
					    if(grid[i][j+1] == grid[i][j]){
						    grid[i][j+1] = grid[i][j]*2;
						    score += grid[i][j+1];
						    grid[i][j] = 0;
					    }
					}
				}
			}
			//���ƶ�һ�� 
			for(int j = size-2; j >= 0 ; j--){
				for(int i = 0; i < size;i++){
					for(int k = j; k<size-1;k++){
				
				    	//��һ������Ϊ��
	    				if(grid[i][k+1] == 0){ 
		    				grid[i][k+1] = grid[i][k];
			    			grid[i][k] = 0;
					}
				}
				}
			}
			break;
			
		
	}
}

 
//����ģʽ 
void SingleUser(){
	Game game;
	Stack stack;
	cout << "�������'64'ģʽ������'-t'����������������";
	string a;
	cin >>  a;
	if(a == "-t"){
		game.setWinNumber(64);
	}
	system("cls");
	game.Print();
	cout << "��ǰ�÷�Ϊ��" << game.score << endl;
	cout << "����Լ��롮q��������һ������" << endl; 
	while(true){
		if(_kbhit()&&game.GameContinue()){
			int ch1 = _getch();
			//���壺 
			while(ch1 == 113){
				if(stack.top == -1){
					cout << "��ǰ���ܳ��أ��������Ϸ��"<< endl;
				}else{
					game.grid = stack.grid_pop();
					game.score = stack.score_pop();
					system("cls");
					game.Print();
	   		        cout << "��ǰ�÷�Ϊ��" << game.score <<endl;
				} 
				ch1 = _getch();
			} 
			int input = getch();
			int direction = game.Input1(input);
			if(game.GameContinue()&&(!game.CanMove(direction))){
				cout << "Try other arrow" << endl;
			}
			if(game.CanMove(direction)){
				stack.push(game.grid,game.score); 
		        game.move(direction);
				game.CreateNum(); 
     	        system("cls");
	   		    game.Print();
	   		    cout << "��ǰ�÷�Ϊ��" << game.score << endl;
				cout << "����Լ��롮q��������һ������" << endl; 
	   	    }
		}
		if(!game.GameContinue()){
		    if(game.gameWin){
			    cout << "You win!" << "�÷�Ϊ��" << game.score << endl;
			    break;
		    }
		    else if(game.gameOver){
			    cout << "Game Over!" << "�÷�Ϊ��" << game.score << endl;
			    break;
		}
	 }
	}
}

void DoublePrint(Game player1,Game player2, Game currentPlayer){
	cout << "tips:���" << player1.userName <<"ʹ�÷���������� ";
	    cout << "���" << player2.userName << "ʹ��'wasd������" << endl;
        cout << endl;
	    cout << "���" << player1.userName << "  �÷�Ϊ��" << player1.score  << endl; 
        player1.Print();
        cout << endl;
        cout << "���" << player2.userName << "   �÷�Ϊ��" << player2.score << endl; 
	    player2.Print(); 
	    cout << endl; 
	    cout << "��ǰ�ִ�Ϊ��" << "���" << currentPlayer.userName << ", ʣ�ಽ��Ϊ: "<<currentPlayer.step<< endl;
	    cout << "���Լ��롮q��������һ��"<< endl; 
}

//˫��ģʽ 
void DoubleUser(){
	Game player1;
	Game player2;
	Stack stack1;
	Stack stack2;
	cout << "���������һ�����֣�";
	string name1;
	cin >> name1;
	cout << "��������Ҷ������֣�";
	string name2;
	cin >> name2;
	player1.setUserName(name1);
	player2.setUserName(name2);
	player1.step ++;
	
	cout << "�������'64'ģʽ������'-t'����������������";
	string a;
	cin >>  a;
	system("cls");
	
	if(a == "-t"){
		player1.setWinNumber(64);
		player2.setWinNumber(64);
	}
	
	bool user1 = true;

    DoublePrint(player1,player2,player1);
	
	while(true){
		if(_kbhit()&&player1.GameContinue()&&player2.GameContinue()){
			if(user1){
	        	int ch1 = _getch();
	        	//���� 
	        	while(ch1 == 113){
				if(stack1.top == -1){
					cout << "��ǰ���ܳ��أ��������Ϸ��"<< endl;
				}else{
					player1.grid = stack1.grid_pop();
					player1.score = stack1.score_pop();
					player1.step ++ ;
					system("cls");
					DoublePrint(player1,player2,player1);	
				} 
				ch1 = _getch();
			    } 
	        	if(ch1 == 224){
	        		int input = getch();
	        		int direction = player1.Input1(input);
        			if(player1.GameContinue()&&(player1.CanMove(direction))){
        				stack1.push(player1.grid,player1.score);
	        	        player1.move(direction);
	        			player1.CreateNum(); 
	        			player1.step --;
             	        system("cls");
             	        if(player1.step == 0){
             	        	player2.step++;
             	        	DoublePrint(player1,player2,player2);	
             	        	user1 = !user1;
						}else{
							
							DoublePrint(player1,player2,player1);
						}
	   	            }
	   	        }
	   	        	       
	   	    }
	   	    else{
	   	    	int input = getch();
	   	    	while(input == 113){
				if(stack1.top == -1){
					cout << "��ǰ���ܳ��أ��������Ϸ��"<< endl;
				}else{
					player2.grid = stack2.grid_pop();
					player2.score = stack2.score_pop();
					player2.step ++ ;
					system("cls");
					DoublePrint(player1,player2,player2);	
				} 
				input = _getch();
			    }
	    		int direction = player2.Input2(input);
    			if(player2.GameContinue()&&(player2.CanMove(direction))){
    				stack2.push(player2.grid,player2.score);
	    	        player2.move(direction);
	    			player2.CreateNum(); 
         	        system("cls");
         	        player2.step--;
         	        if(player2.step == 0){
             	        	player1.step++;
             	        	DoublePrint(player1,player2,player1);	
             	        	user1 = !user1;
					}else{		
						DoublePrint(player1,player2,player2);
					}
	   	        }
	   	        
			}
		}
		if(!(player1.GameContinue()&&player2.GameContinue())){
		    if(player1.score == player2.score){
		    	cout << "��Ϸ������Ϊƽ��" << endl; 
			}else if(player1.score > player2.score){
				cout << "��Ϸ������Ӯ��Ϊ��" << "���" << player1.userName << "���÷�Ϊ��" << player1.score <<endl;
			}
			else{
				cout << "��Ϸ������Ӯ��Ϊ��" << "���" << player2.userName << "���÷�Ϊ��" << player2.score <<endl;
			} 
			
			break;
	    }
	}
}

int main(){
	cout << "--------------��Ϸ��ʼ--------------" << endl;
	cout <<endl;
	//���̴�С 
	cout <<"���������̴�С(3��4��5):" << endl;
	string a;
	cin >> a;
	while(true){
		if(a == "3"){
		    size = 3;
		    break;
		}else if(a == "4"){
			size = 4;
			break;
		}else if(a == "5"){
			size = 5;
			break;
		} else{
			cout <<"���̴�Сֻ��Ϊ3��4��5�����������룺"<< endl;
			cin >> a;
		}
	}
	cout <<"�����ģʽѡ��" << endl;
	cout <<"1������ģʽ" << endl; 
	cout <<"2��˫��ģʽ" << endl; 
	cout <<"�������Ӧģʽ�����1��2:" ;
	
	
	while(true){
		string a;
	    cin >>  a; 
	    int b = atoi(a.c_str());
	    if(b == 1){
			SingleUser();
		}
		else if(b == 2){
			DoubleUser();
		}
		else cout << "�������Ӧģʽ�����1��2��"; 
}	
	return 0;
} 
