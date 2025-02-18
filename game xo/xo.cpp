#include <iostream>
#include <cctype>
#include <ctime>
#include <cstdlib>

using namespace std;

void greatboard(char *space);
void playermove(char player,char *space);
void computerplayer(char computer, char *space);
bool checkwin(char *space,char player ,char computer);
bool checktie(char *space);
int main(){
	char player='x';
	char space[]={' ',' ',' ',' ',' ',' ',' ',' ',' '};
	char computer='o';
	bool running =true;
	
	greatboard(space); 
	while(1){
		playermove(player,space);
		greatboard(space);
		if(checkwin(space,player ,computer)){
			running = false;
			break;
		}
		else if(checktie(space)){
			running=false;
			break;
		}
		
		computerplayer(computer,space);
		greatboard(space);
		if(checkwin(space,player ,computer)){
			running = true;
			break;
		}
		else if(checktie(space)){
			running=false;
			break;
		}		
	}
	return 0;
}
void greatboard(char *space){
	cout<<"     |     |     \n";
	cout<<"  "<<space[0]<<"  |"<<"  "<<space[1]<<"  |"<<"  "<<space[2]<<"  \n";
	cout<<"_____|_____|_____\n";
	cout<<"     |     |     \n";
	cout<<"  "<<space[3]<<"  |"<<"  "<<space[4]<<"  |"<<"  "<<space[5]<<"  \n";
		cout<<"_____|_____|_____\n";
	cout<<"     |     |     \n";
	cout<<"  "<<space[6]<<"  |"<<"  "<<space[7]<<"  |"<<"  "<<space[8]<<"  \n";
	cout<<"     |     |     \n";
	
}
void playermove(char player,char *space){
		int number;
		do{
			cout<<"enter number 1-9\n";
			cin>>number;
			number--;
			if(space[number]==' '){
				space[number]= player;
				break;
			}
		}while(!number>0 || !number<8);			
}
void computerplayer(char computer, char *space){
	srand(time(0));
	while(true){
		int move = rand()%9;
		if(space[move]==' '){
			space[move]= computer;
			break;
		}
	}
}
bool checkwin(char *space,char player ,char computer){
	if((space[0]!=' ') && (space[0]==space[1]) &&(space[1]==space[2])){
		space[0]==player? cout<<"you win\n" : cout<<"you lost\n";
	}
	else if((space[3]!=' ') && (space[3]==space[4])&&(space[4]==space[5])){
		space[3]==player? cout<<"you win\n" :cout<<"you lost\n";
	}
	else if((space[6]!=' ') && (space[6]==space[7])&&(space[7]==space[8])){
		space[6]==player?cout<<"you win\n":cout<<"you lost\n";
	}
	else if((space[0]!=' ') && (space[0]==space[4])&&(space[4]==space[8])){
		space[0]==player?cout<<"you win\n":cout<<"you lost\n";
	}
	else if((space[2]!=' ') && (space[2]==space[4])&&(space[4]==space[6])){
		space[2]==player?cout<<"you win\n":cout<<"you lost\n";
	}
	else if((space[0]!=' ') && (space[0]==space[3])&&(space[3]==space[6])){
		space[0]==player?cout<<"you win\n":cout<<"you lost\n";
	}
	else if((space[1]!=' ') && (space[1]==space[4])&&(space[4]==space[7])){
		space[1]==player?cout<<"you win\n":cout<<"you lost\n";
	}
	else if((space[2]!=' ') && (space[2]==space[5])&&(space[5]==space[8])){
		space[2]==player?cout<<"you win\n":cout<<"you lost\n";
	}
	else{
		return false;
	}
}
bool checktie(char *space){
	for(int i=0;i<9;i++){
		if(space[i]== ' '){
			return false;
		}	
	}
	cout<<"it's a tie!\n";
	return true;
}




