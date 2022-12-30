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

//打印 
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

//产生新的数字 
bool CreateNum(){
	int emptyNum = 0; 
	for(int i = 0; i < ROW; i++){
		for(int j = 0; j < COL; j++){
			if(game[ROW][COL].val == 0){
				emptyNum++;
			}
       }
    }
    //格子已满则不能生成 
    if(emptyNum == 0){
	   	return false;
	}
	//随机生成2或4,0.1概率为4，0.9概率为2
	srand(time(NULL));
	int p = rand() % 9;
	int generateNum;
	if(p == 0){
		generateNum = 4;
	}else{
		generateNum = 2;
	}
	
	//随机在空格处生成数字
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

//处理输入输出，返回上下左右,分别对应1,2,3,4 
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


//检查是否可以移动
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
 
//移动 
void move(int direction){
	switch(direction){
		case 1:
			//向上移动不合并 
			for(int i = 1; i < ROW; ++i){
				for(int j = 0; j < COL;++j){
					//上一个格子为空 
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
			//合并 
			for(int i = 1; i < ROW; ++i){
				for(int j = 0; j < COL;++j){
					//上一个格子与其数字相同则合并 
					if(game[i][j].val != 0){
					    if(game[i-1][j].val == game[i][j].val){
						    game[i-1][j].val = (game[i][j].val)*2;
						    game[i][j].val = 0;
					    }
					}
				}
			}
			//再移动一次 
			for(int i = 1; i < ROW; ++i){
				for(int j = 0; j < COL;++j){
					//上一个格子为空 
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
			//向下移动不合并 
			for(int i = ROW-2; i >= 0; i--){
				for(int j = 0; j < COL;j++){
					//下一个格子为空 
					for(int k = i;k<ROW-1;k++){
					    if(game[k+1][j].val == 0){ 
					    	game[k+1][j].val = game[k][j].val;
				    		game[k][j].val = 0;
				    	}
			     	}
				}
			}
			//合并 
			for(int i = ROW - 2; i >= 0; i--){
				for(int j = 0; j < COL;j++){
					//下一个格子与其数字相同则合并 
					if(game[i][j].val != 0){
					    if(game[i+1][j].val == game[i][j].val){
						    game[i+1][j].val = game[i][j].val*2;
						    game[i][j].val = 0;
					    }
					}
				}
			}
			//再移动一次 
			for(int i = ROW-2; i >= 0; i--){
				for(int j = 0; j < COL;j++){
					//下一个格子为空 
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
			//向左移动不合并 
			for(int j = 1; j < COL; j++){
				for(int i = 0; i < ROW;i++){
					for(int k = j;k>0;k--){
					    //左一个格子为空
			    		if(game[i][k-1].val == 0){ 
				    		game[i][k-1].val = game[i][k].val;
					    	game[i][k].val = 0;
					}
				}
				}
			}
			//合并 
			for(int j = 1; j < COL; j++){
				for(int i = 0; i < ROW;i++){
					//左一个格子与其数字相同则合并 
					if(game[i][j].val != 0){
					    if(game[i][j-1].val == game[i][j].val){
						    game[i][j-1].val = game[i][j].val*2;
						    game[i][j].val = 0;
					    }
					}
				}
			}
			//再移动一次 
			for(int j = 1; j < COL; j++){
				for(int i = 0; i < ROW;i++){
					for(int k = j;k>0;k--){
					    //左一个格子为空
			    		if(game[i][k-1].val == 0){ 
				    		game[i][k-1].val = game[i][k].val;
					    	game[i][k].val = 0;
					}
				}
				}
			}
			break;
			
		case 4:
			//向右移动不合并 
			for(int j = COL-2; j >= 0 ; j--){
				for(int i = 0; i < ROW;i++){
					for(int k = j; k<COL-1;k++){
				
				    	//右一个格子为空
	    				if(game[i][k+1].val == 0){ 
		    				game[i][k+1].val = game[i][k].val;
			    			game[i][k].val = 0;
					}
				}
				}
			}
			//合并 
			for(int j = COL-2; j >= 0 ; j--){
				for(int i = 0; i < ROW;i++){
					//右一个格子与其数字相同则合并 
					if(game[i][j].val != 0){
					    if(game[i][j+1].val == game[i][j].val){
						    game[i][j+1].val = game[i][j].val*2;
						    game[i][j].val = 0;
					    }
					}
				}
			}
			//再移动一次 
			for(int j = COL-2; j >= 0 ; j--){
				for(int i = 0; i < ROW;i++){
					for(int k = j; k<COL-1;k++){
				
				    	//右一个格子为空
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
	//游戏获胜
	for(int i = 0; i < ROW; i++){
		for(int j = 0; j < COL;j++){ 
			if(game[i][j].val == 16){
				gameWin = true;
				return false;
			}
		}
	}
	//检查有无空格 
	for(int i = 0; i < ROW; i++){
		for(int j = 0;j < COL; j++){
			if(game[i][j].val == 0){
				return true;
			}
		} 
	}
	
	//横向检查有无可合并的 
	for(int i = 0; i < ROW;i++){
		for(int j = 0; j < COL - 1; j++){
			if(game[i][j].val == game[i][j+1].val){
				return true;
			} 
		}
	}
	
	//纵向检查有无可合并的
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
    



