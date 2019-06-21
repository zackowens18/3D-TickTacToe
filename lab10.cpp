/*
Name: Zack Owens 
Lab #9
Date: 3/27/2019
Description: 3D tic tac toe allows user to play against computer.
*/
#include <iostream>
#include <string>
#include <stdlib.h>
#include <time.h>

using namespace std;

//class from lab 9
class game { // initializes game functions and varaibles
	public:
		game();
		void play(int selection);
		int slots[9];
		char xando[9];
		void print();
		bool check();
		bool finish;
		int turn;
		
};

game::game(){ // creates new board and numbers for user to pick 
	turn=0;
	finish = false;
	xando[0] ='1';
	xando[1] = '2';
	xando[2] = '3';
	xando[3] = '4';
	xando[4] = '5';
	xando[5] = '6';
	xando[6] = '7';
	xando[7] = '8';
	xando[8] = '9';
	for(int i = 0; i<9;i++){ // sets board to 0
		slots[i] = 0;
	}
	print();
}
void game::play(int select){ // checks if person wins and computer makes move if game is not over
	select--;
	
	if(slots[select]==0){
		slots[select]=1;
		turn++;
		if(check()==true){
			print();
		}else{
			turn++;
			if(slots[0]==1&&slots[4]==1&&slots[8]==0){
				slots[8]=2;
			}else if(slots[2]==1&&slots[4]==1&&slots[6]==0){
				slots[6]=2;
			}else if(slots[0]==1&&slots[4]==1&&slots[8]==0){
				slots[8]=2;
			}else if(slots[6]==1&&slots[4]==1&&slots[2]==0){
				slots[2]=2;
			}else if(slots[8]==1&&slots[4]==1&&slots[0]==0){
				slots[0]=2;
			}else if(slots[2]==1&&slots[6]==1&&slots[4]==0){
				slots[4]=2;
			}else if(slots[0]==1&&slots[8]==1&&slots[4]==0){
				slots[4]=2;
			}else if(slots[3]==1&&slots[5]==1&&slots[4]==0){
				slots[4]=2;
			}else if(slots[7]==1&&slots[1]==1&&slots[4]==0){
				slots[4]=2;
			}else if(slots[0]==1&&slots[6]==1&&slots[3]==0){
				slots[3]=2;
			}else if(slots[0]==1&&slots[3]==1&&slots[6]==0){
				slots[6]=2;
			}else if(slots[0]==1&&slots[3]==1&&slots[6]==0){
				slots[6]=2;
			}else if(slots[0]==1&&slots[1]==1&&slots[2]==0){
				slots[2]=2;
			}else if(slots[1]==1&&slots[2]==1&&slots[0]==0){
				slots[0]=2;
			}else if(slots[0]==1&&slots[2]==1&&slots[1]==0){
				slots[1]=2;
			}else if(slots[1]==1&&slots[4]==1&&slots[7]==0){
				slots[7]=2;
			}else if(slots[4]==1&&slots[7]==1&&slots[1]==0){
				slots[1]=2;
			}else if(slots[2]==1&&slots[5]==1&&slots[8]==0){
				slots[8]=2;
			}else if(slots[2]==1&&slots[8]==1&&slots[5]==0){
				slots[5]=2;
			}else if(slots[8]==1&&slots[5]==1&&slots[2]==0){
				slots[2]=2;
			}else if(slots[6]==1&&slots[7]==1&&slots[8]==0){
				slots[8]=2;
			}else if(slots[7]==1&&slots[8]==1&&slots[6]==0){
				slots[6]=2;
			}else if(slots[8]==1&&slots[6]==1&&slots[7]==0){
				slots[7]=2;
			}else if(slots[4]==1&&slots[5]==1&&slots[6]==0){
				slots[6]=2;
			}else if(slots[0]==0){
				slots[0]=2;
			}else if(slots[8]==0){
				slots[8]=2;
			}else if(slots[4]==0){
				slots[4]=2;
			}else if(slots[0]==0){
				slots[0]=2;
			}else if(slots[2]==0){
				slots[2]=2;
			}else if(slots[6]==0){
				slots[6]=2;
			}else if(slots[1]==0){
				slots[1]=2;
			}else if(slots[3]==0){
				slots[3]=2;
			}else if(slots[5]==0){
				slots[5]=2;
			}else if(slots[7]==0){
				slots[7]=2;
			}
		print();
		}
			

	}
	else{
		cout<<"space already occupied\n"; // in case user places value x on square already used 
		print();
	}
	
}
bool game::check(){ // the game checks if 3 in a row or if the board is filled it is a tie 
	if((slots[0]==1&&slots[4]==1&&slots[8]==1)||(slots[2]==1&&slots[4]==1&&slots[6]==1)||(slots[0]==1&&slots[3]==1&&slots[6]==1)||(slots[1]==1&&slots[4]==1&&slots[7]==1)||(slots[2]==1&&slots[5]==1&&slots[8]==1)||(slots[0]==1&&slots[1]==1&&slots[2]==1)||(slots[3]==1&&slots[4]==1&&slots[5]==1)||(slots[6]==1&&slots[7]==1&&slots[8]==1))
	{	
	cout<<"You Win!!\n";
	finish = true;
	return true;
	}else if((slots[0]==2 && slots[4]==2 && slots[8]==2)||(slots[2]==2 && slots[4]==2 && slots[6]==2)||(slots[0]==2&&slots[3]==2&&slots[6]==2)||(slots[1]==2&&slots[4]==2&&slots[7]==2)||(slots[2]==2&&slots[5]==2&&slots[8]==2)||(slots[0]==2&&slots[1]==2&&slots[2]==2)||(slots[3]==2&&slots[4]==2&&slots[5]==2)||(slots[6]==2&&slots[7]==2&&slots[8]==2)){
	cout<<"The computer won better luck next time\n";
	finish = true;
	
	}
	if(turn>8){
		cout<<"Tie Game\n";
		finish = true;
	}
	
	return false;
}
void game::print(){ // formats the board on the screen
	for(int i=0;i<9;i++){
		if(slots[i]==1){
			xando[i]='X';
		}else if(slots[i]==2){
			xando[i]='O';
			
		}
	}
	
	
}
class Game2: public game{
	int slots2[9];
	int slots3[9];
	string xando2[9];
	string xando3[9];
	bool first;
	int playerwins = 0;
	int compwins = 0;
	public:
		Game2();
		int play(int sel,int board);	
		void print2();
		int check();
		void comp();
		void aiplay();
};
Game2::Game2(){
	for(int i = 0; i<9;i++){
		slots[i]=0;
		slots2[i]=0;
		slots3[i]=0;
	}
	turn=0;
	int computer = 0;
	int human = 0;
	finish = false;
	xando[0] = '1';
	xando[1] = '2';
	xando[2] = '3';
	xando[3] = '4';
	xando[4] = '5';
	xando[5] = '6';
	xando[6] = '7';
	xando[7] = '8';
	xando[8] = '9';
	xando2[0] = "1";
	xando2[1] = "2";
	xando2[2] = "3";
	xando2[3] = "4";
	xando2[4] = "5";
	xando2[5] = "6";
	xando2[6] = "7";
	xando2[7] = "8";
	xando2[8] = "9";
	xando3[0] = "1";
	xando3[1] = "2";
	xando3[2] = "3";
	xando3[3] = "4";
	xando3[4] = "5";
	xando3[5] = "6";
	xando3[6] = "7";
	xando3[7] = "8";
	xando3[8] = "9";
}
void Game2::comp(){
	slots2[4]=2;
	turn++;
}
int Game2::play(int sel,int board){
	sel--;
	if(board ==1 && slots[sel]==0){
		slots[sel]=1;
		turn++;
		aiplay();
	}else if(board ==2 &&slots2[sel]==0){
		slots2[sel]=1;
		turn++;
		aiplay();
	}else if(board ==3 && slots3[sel]==0){
		slots3[sel]=1;
		turn++;
		aiplay();
	}else{
		cout<<"Invavlid number try again";
	}
	print2();
	return check();
	

}
void Game2::aiplay(){
	while(true){
		srand(time(NULL));
		int b = rand()%3;
		srand(time(NULL));
		int sq = rand()%9;
			if(b ==1 && slots[sq]==0){
				slots[sq]=2;
				turn++;
				break;
			}else if(b ==2 &&slots2[sq]==0){
				slots2[sq]=2;
				turn++;
				break;
			}else if(b ==3 && slots3[sq]==0){
				slots3[sq]=2;
				turn++;
				break;
			}
	}
}
int Game2::check(){
	if((slots[0]==1&&slots[4]==1&&slots[8]==1)||(slots[2]==1&&slots[4]==1&&slots[6]==1)||(slots[0]==1&&slots[3]==1&&slots[6]==1)||(slots[1]==1&&slots[4]==1&&slots[7]==1)||(slots[2]==1&&slots[5]==1&&slots[8]==1)||(slots[0]==1&&slots[1]==1&&slots[2]==1)||(slots[3]==1&&slots[4]==1&&slots[5]==1)||(slots[6]==1&&slots[7]==1&&slots[8]==1)||(slots2[0]==1&&slots2[4]==1&&slots2[8]==1)||(slots2[2]==1&&slots2[4]==1&&slots2[6]==1)||(slots2[0]==1&&slots2[3]==1&&slots2[6]==1)||(slots2[1]==1&&slots2[4]==1&&slots2[7]==1)||(slots2[2]==1&&slots2[5]==1&&slots2[8]==1)||(slots2[0]==1&&slots2[1]==1&&slots2[2]==1)||(slots2[3]==1&&slots2[4]==1&&slots2[5]==1)||(slots2[6]==1&&slots2[7]==1&&slots2[8]==1)||(slots3[0]==1&&slots3[4]==1&&slots3[8]==1)||(slots3[2]==1&&slots3[4]==1&&slots3[6]==1)||(slots3[0]==1&&slots3[3]==1&&slots3[6]==1)||(slots3[1]==1&&slots3[4]==1&&slots3[7]==1)||(slots3[2]==1&&slots3[5]==1&&slots3[8]==1)||(slots3[0]==1&&slots3[1]==1&&slots3[2]==1)||(slots3[3]==1&&slots3[4]==1&&slots3[5]==1)||(slots3[6]==1&&slots3[7]==1&&slots3[8]==1)||(slots[0]==1&&slots2[1]==1&&slots3[3]==1)||(slots[2]==1&&slots2[1]==1&&slots3[0]==1)||(slots[0]==1&&slots2[3]==1&&slots3[6]==1)||(slots[0]==1&&slots2[4]==1&&slots3[8]==1)||(slots[3]==1&&slots2[4]==1&&slots3[5]==1)||(slots[6]==1&&slots2[4]==1&&slots3[2]==1)||(slots[6]==1&&slots2[7]==1&&slots3[8]==1)||(slots[1]==1&&slots2[4]==1&&slots3[7]==1)||(slots[2]==1&&slots2[5]==1&&slots3[8]==1)||(slots[7]==1&&slots2[4]==1&&slots3[1]==1)||(slots[0]==1&&slots2[0]==1&&slots3[0]==1)||(slots[1]==1&&slots2[1]==1&&slots3[1]==1)||(slots[2]==1&&slots2[2]==1&&slots3[2]==1)||(slots[3]==1&&slots2[3]==1&&slots3[3]==1)||(slots[4]==1&&slots2[4]==1&&slots3[4]==1)||(slots[5]==1&&slots2[5]==1&&slots3[5]==1)||(slots[6]==1&&slots2[6]==1&&slots3[6]==1)||(slots[7]==1&&slots2[7]==1&&slots3[7]==1)||(slots[8]==1&&slots2[8]==1&&slots3[8]==1))
	{	
	cout<<"You Win!!\n";
	finish = true;
	return 1;
	}else if((slots[0]==2&&slots[4]==2&&slots[8]==2)||(slots[2]==2&&slots[4]==2&&slots[6]==2)||(slots[0]==2&&slots[3]==2&&slots[6]==2)||(slots[1]==2&&slots[4]==2&&slots[7]==2)||(slots[2]==2&&slots[5]==2&&slots[8]==2)||(slots[0]==2&&slots[1]==2&&slots[2]==2)||(slots[3]==2&&slots[4]==2&&slots[5]==2)||(slots[6]==2&&slots[7]==2&&slots[8]==2)||(slots2[0]==2&&slots2[4]==2&&slots2[8]==2)||(slots2[2]==2&&slots2[4]==2&&slots2[6]==2)||(slots2[0]==2&&slots2[3]==2&&slots2[6]==2)||(slots2[1]==2&&slots2[4]==2&&slots2[7]==2)||(slots2[2]==2&&slots2[5]==2&&slots2[8]==2)||(slots2[0]==2&&slots2[1]==2&&slots2[2]==2)||(slots2[3]==2&&slots2[4]==2&&slots2[5]==2)||(slots2[6]==2&&slots2[7]==2&&slots2[8]==2)||(slots3[0]==2&&slots3[4]==2&&slots3[8]==2)||(slots3[2]==2&&slots3[4]==2&&slots3[6]==2)||(slots3[0]==2&&slots3[3]==2&&slots3[6]==2)||(slots3[1]==2&&slots3[4]==2&&slots3[7]==2)||(slots3[2]==2&&slots3[5]==2&&slots3[8]==2)||(slots3[0]==2&&slots3[1]==2&&slots3[2]==2)||(slots3[3]==2&&slots3[4]==2&&slots3[5]==2)||(slots3[6]==2&&slots3[7]==2&&slots3[8]==2)||(slots[0]==2&&slots2[1]==2&&slots3[3]==2)||(slots[2]==2&&slots2[1]==2&&slots3[0]==2)||(slots[0]==2&&slots2[3]==2&&slots3[6]==2)||(slots[0]==2&&slots2[4]==2&&slots3[8]==2)||(slots[3]==2&&slots2[4]==2&&slots3[5]==2)||(slots[6]==2&&slots2[4]==2&&slots3[2]==2)||(slots[6]==2&&slots2[7]==2&&slots3[8]==2)||(slots[1]==2&&slots2[4]==2&&slots3[7]==2)||(slots[2]==2&&slots2[5]==2&&slots3[8]==2)||(slots[7]==2&&slots2[4]==2&&slots3[1]==2)||(slots[0]==2&&slots2[0]==2&&slots3[0]==2)||(slots[1]==2&&slots2[1]==2&&slots3[1]==2)||(slots[2]==2&&slots2[2]==2&&slots3[2]==2)||(slots[3]==2&&slots2[3]==2&&slots3[3]==2)||(slots[4]==2&&slots2[4]==2&&slots3[4]==2)||(slots[5]==2&&slots2[5]==2&&slots3[5]==2)||(slots[6]==2&&slots2[6]==2&&slots3[6]==2)||(slots[7]==2&&slots2[7]==2&&slots3[7]==2)||(slots[8]==2&&slots2[8]==2&&slots3[8]==2))
	{
	cout<<"The computer won better luck next time\n";
	finish = true;
	return 2;
	}
	if(turn>27){
		cout<<"Tie Game\n";
		return 0;
	}
	
}
void Game2::print2(){
	for(int i= 0;i<9;i++){
		if(slots[i]==1){
			xando[i]='X';
		}else if(slots[i]==2){
			xando[i]='O';
		}
		if(slots2[i]==1){
			xando2[i]="X";
		}else if(slots2[i]==2){
			xando2[i]="O ";
		}
		if(slots3[i]==1){
			xando3[i]="X";
		}else if(slots3[i]==2){
			xando3[i]="O";
		}
	}
	cout<<" "<<xando[0]<<"|"<<xando[1]<<"|"<<xando[2]<<"\n";
	cout<<"--------------\n";
	cout<<" "<<xando[3]<<"|"<<xando[4]<<"|"<<xando[5]<<"\n";
	cout<<"--------------\n";
	cout<<" "<<xando[6]<<"|"<<xando[7]<<"|"<<xando[8]<<"\n\n";
	cout<<"\t "<<xando2[0]<<"|"<<xando2[1]<<"|"<<xando2[2]<<"\n";
	cout<<"\t------------\n";
	cout<<"\t "<<xando2[3]<<"|"<<xando2[4]<<"|"<<xando2[5]<<"\n";
	cout<<"\t------------\n";
	cout<<"\t "<<xando2[6]<<"|"<<xando2[7]<<"|"<<xando2[8]<<"\n\n";
	cout<<"\t\t "<<xando3[0]<<"|"<<xando3[1]<<"|"<<xando3[2]<<"\n";
	cout<<"\t\t------------\n";
	cout<<"\t\t "<<xando3[3]<<"|"<<xando3[4]<<"|"<<xando3[5]<<"\n";
	cout<<"\t\t------------\n";
	cout<<"\t\t "<<xando3[6]<<"|"<<xando3[7]<<"|"<<xando3[8]<<"\n";
	
}

int main(void){
	int win1=0;
	int win2=0;
		while(true){
		char answer;
		int play,board;
		srand(time(NULL));
		cout<<"would you like to play a game?(y/n)";
		cin>>answer;
		if(answer=='y'){
			Game2 g1=Game2();
			if(int random=rand() % 2 == 0){
				g1.comp();
			}
			g1.print2();
			cout<<"Player has won: " <<win1<< "  Computer has won: "<<win2<<"\n";
			while(g1.finish == false){
				cout<<"select a square to play and board (square board)\n";
				cin>>play>>board;
				int w = g1.play(play,board);
				if(w == 1){
					win1++;
				} else if(w==2){
					win2++;
				}
			}
		}
		if(answer == 'n'){
			break;
		} 
	}
	return 0;


}

