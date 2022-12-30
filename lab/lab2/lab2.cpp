#include <iostream>
#include <windows.h>
#include <ctime>
#include <iomanip>
#include <conio.h>
using namespace std;

int const COL = 4;
int const ROW = 4;
bool gameWin = false;
bool gameOver = false;


class Game{
	public:
		int val;
};


Game game[ROW][COL];

//��ӡ 
void Print(){
	cout <<"+-----+-----+-----+-----+"<< endl; 
	for(int i = 0; i < ROW; i++){
		for(int j = 0; j < COL; j++){
			if(game[i][j].val == 0){
				cout << "|     ";
			}
			else {
				cout <<"| "<<std::left<<setw(4)<<game[i][j].val;
			}
		}
		cout << "|" << endl;
			cout <<"+-----+-----+-----+-----+"<< endl;
	}
	cout<<" "<<endl;
}

//�����µ����� 
bool CreateNum(){
	int emptyNum = 0; 
	for(int i = 0; i < ROW; i++){
		for(int j = 0; j < COL; j++){
			if(game[ROW][COL].val == 0){
				emptyNum++;
			}
       }
    }
    //���������������� 
    if(emptyNum == 0){
	   	return false;
	}
	//�������2��4,0.1����Ϊ4��0.9����Ϊ2
	srand(time(NULL));
	int p = rand() % 9;
	int generateNum;
	if(p == 0){
		generateNum = 4;
	}else{
		generateNum = 2;
	}
	
	//����ڿո���������
	srand(time(NULL));
    int x = rand()%COL;
    int y = rand()%ROW;
    while(game[x][y].val != 0){
        x = rand()%COL;
        y = rand()%ROW;
    }
    game[x][y].val = generateNum;
    return true;
}

//�������������������������,�ֱ��Ӧ1,2,3,4 
int Input(int input){
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
	    	    
		default:
			cout <<"Please enter arrow" << endl;
			break;
		
    }
	return direction;
} 


//����Ƿ�����ƶ�
bool CanMove(int direction){
	switch(direction){
		case 1:
			for(int i = 1;i < ROW; i++){
	           	for(int j = 0; j < COL;j++){
			        if((game[i][j].val  != 0)&& (game[i][j].val == game[i-1][j].val || game[i-1][j].val == 0)){
				        return true;
			        }
		       }      
	       }
		   break; 
		case 2:
			for(int i = ROW-2;i >= 0; i--){
	           	for(int j = 0; j < COL;j++){
			        if((game[i][j].val  != 0)&& (game[i][j].val == game[i+1][j].val || game[i+1][j].val == 0)){
				        return true;
			        }
		       }      
	       } 
		   break;
		case 3:
			for(int i = 0; i < ROW;i++){
		        for(int j = 1; j < COL; j++){
			        if((game[i][j].val  != 0) && (game[i][j].val == game[i][j-1].val || game[i][j-1].val == 0)){
				        return true;
			        } 
		        }
	        } 
			break;
		case 4:
		    for(int i = 0; i < ROW;i++){
		        for(int j = COL - 2 ; j >= 0; j--){
			        if((game[i][j].val  != 0) && (game[i][j].val == game[i][j+1].val || game[i][j+1].val == 0)){
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
 
//�ƶ� 
void move(int direction){
	switch(direction){
		case 1:
			//�����ƶ����ϲ� 
			for(int i = 1; i < ROW; ++i){
				for(int j = 0; j < COL;++j){
					//��һ������Ϊ�� 
					if(game[i][j].val != 0){
					    for(int k = i;k>0;--k){
					        if(game[k-1][j].val == 0){ 
					     	    game[k-1][j].val = game[k][j].val;
						        game[k][j].val = 0;
					        }
				        }
			        }
				}
			}
			//�ϲ� 
			for(int i = 1; i < ROW; ++i){
				for(int j = 0; j < COL;++j){
					//��һ����������������ͬ��ϲ� 
					if(game[i][j].val != 0){
					    if(game[i-1][j].val == game[i][j].val){
						    game[i-1][j].val = (game[i][j].val)*2;
						    game[i][j].val = 0;
					    }
					}
				}
			}
			//���ƶ�һ�� 
			for(int i = 1; i < ROW; ++i){
				for(int j = 0; j < COL;++j){
					//��һ������Ϊ�� 
					if(game[i][j].val != 0){
					    for(int k = i;k>0;--k){
					        if(game[k-1][j].val == 0){ 
					     	    game[k-1][j].val = game[k][j].val;
						        game[k][j].val = 0;
					        }
				        }
			        }
				}
			}
			break;
			
		case 2:
			//�����ƶ����ϲ� 
			for(int i = ROW-2; i >= 0; i--){
				for(int j = 0; j < COL;j++){
					//��һ������Ϊ�� 
					for(int k = i;k<ROW-1;k++){
					    if(game[k+1][j].val == 0){ 
					    	game[k+1][j].val = game[k][j].val;
				    		game[k][j].val = 0;
				    	}
			     	}
				}
			}
			//�ϲ� 
			for(int i = ROW - 2; i >= 0; i--){
				for(int j = 0; j < COL;j++){
					//��һ����������������ͬ��ϲ� 
					if(game[i][j].val != 0){
					    if(game[i+1][j].val == game[i][j].val){
						    game[i+1][j].val = game[i][j].val*2;
						    game[i][j].val = 0;
					    }
					}
				}
			}
			//���ƶ�һ�� 
			for(int i = ROW-2; i >= 0; i--){
				for(int j = 0; j < COL;j++){
					//��һ������Ϊ�� 
					for(int k = i;k<ROW-1;k++){
					    if(game[k+1][j].val == 0){ 
					    	game[k+1][j].val = game[k][j].val;
				    		game[k][j].val = 0;
				    	}
			     	}
				}
			}
			break;
			
		case 3:
			//�����ƶ����ϲ� 
			for(int j = 1; j < COL; j++){
				for(int i = 0; i < ROW;i++){
					for(int k = j;k>0;k--){
					    //��һ������Ϊ��
			    		if(game[i][k-1].val == 0){ 
				    		game[i][k-1].val = game[i][k].val;
					    	game[i][k].val = 0;
					}
				}
				}
			}
			//�ϲ� 
			for(int j = 1; j < COL; j++){
				for(int i = 0; i < ROW;i++){
					//��һ����������������ͬ��ϲ� 
					if(game[i][j].val != 0){
					    if(game[i][j-1].val == game[i][j].val){
						    game[i][j-1].val = game[i][j].val*2;
						    game[i][j].val = 0;
					    }
					}
				}
			}
			//���ƶ�һ�� 
			for(int j = 1; j < COL; j++){
				for(int i = 0; i < ROW;i++){
					for(int k = j;k>0;k--){
					    //��һ������Ϊ��
			    		if(game[i][k-1].val == 0){ 
				    		game[i][k-1].val = game[i][k].val;
					    	game[i][k].val = 0;
					}
				}
				}
			}
			break;
			
		case 4:
			//�����ƶ����ϲ� 
			for(int j = COL-2; j >= 0 ; j--){
				for(int i = 0; i < ROW;i++){
					for(int k = j; k<COL-1;k++){
				
				    	//��һ������Ϊ��
	    				if(game[i][k+1].val == 0){ 
		    				game[i][k+1].val = game[i][k].val;
			    			game[i][k].val = 0;
					}
				}
				}
			}
			//�ϲ� 
			for(int j = COL-2; j >= 0 ; j--){
				for(int i = 0; i < ROW;i++){
					//��һ����������������ͬ��ϲ� 
					if(game[i][j].val != 0){
					    if(game[i][j+1].val == game[i][j].val){
						    game[i][j+1].val = game[i][j].val*2;
						    game[i][j].val = 0;
					    }
					}
				}
			}
			//���ƶ�һ�� 
			for(int j = COL-2; j >= 0 ; j--){
				for(int i = 0; i < ROW;i++){
					for(int k = j; k<COL-1;k++){
				
				    	//��һ������Ϊ��
	    				if(game[i][k+1].val == 0){ 
		    				game[i][k+1].val = game[i][k].val;
			    			game[i][k].val = 0;
					}
				}
				}
			}
			break;
			
		
	}
}

bool GameContinue(){
	//��Ϸ��ʤ
	for(int i = 0; i < ROW; i++){
		for(int j = 0; j < COL;j++){ 
			if(game[i][j].val == 16){
				gameWin = true;
				return false;
			}
		}
	}
	//������޿ո� 
	for(int i = 0; i < ROW; i++){
		for(int j = 0;j < COL; j++){
			if(game[i][j].val == 0){
				return true;
			}
		} 
	}
	
	//���������޿ɺϲ��� 
	for(int i = 0; i < ROW;i++){
		for(int j = 0; j < COL - 1; j++){
			if(game[i][j].val == game[i][j+1].val){
				return true;
			} 
		}
	}
	
	//���������޿ɺϲ���
	for(int i = 0;i < ROW - 1; i++){
		for(int j = 0; j < COL;j++){
			if(game[i][j].val == game[i+1][j].val){
				return true;
			}
		}
	}
	
	gameOver = true;
	return false; 
}

int main(){
	for(int i = 0; i < ROW; i++){
	    for(int j = 0; j < COL; j++){
		    game[i][j].val = 0;
	    }
    }
    srand(time(0));
    game[rand()%4][rand()%4].val = 2;
	Print();
	
	while(true){
		if(_kbhit()&&GameContinue()){
			int ch1 = _getch();
			int input = getch();
			int direction = Input(input);
			if(GameContinue()&&(!CanMove(direction))){
				cout << "Try other arrow" << endl;
			}
			if(CanMove(direction)){
		        move(direction);
     	        CreateNum();
     	       // system("cls");
	   		    Print();
	   	    }
		}
		if(!GameContinue()){
		    if(gameWin){
			    //Print();
			    cout << "You win!" << endl;
			    break;
		    }
		    else if(gameOver){
			    //Print();
			    cout << "Game Over!" << endl;
			    break;
		}
	 }
	}
	return 0;
}
    



