#include<iostream>
#include<ctime>
#include<cstdlib>
void draw(char* Game) {
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 6; j++) {
			if (j % 2 == 0) std::cout << " | " << Game[i * 3 + j / 2];
			if (j == 5) std::cout << " |" << std::endl;
		}
		if (i != 2) std::cout << " -------------" << std::endl;
	}
}
void player(char* Game, const char* player_, const char* computer_) {
	int choose;
	do {
		std::cout << "Choose 1-9: ";
		std::cin >> choose;
	} while (choose > 9 || choose < 1 || Game[choose - 1] == *player_|| Game[choose - 1] == *computer_);
	Game[choose - 1] = *player_;
}
int _computer(char* Game, const char* computer_, const char* player_) {
	srand((time(0)));
	int computer_choose = rand() % 9 + 1;
	if (Game[computer_choose - 1] != *player_ && Game[computer_choose - 1] != *computer_) { Game[computer_choose - 1] = *computer_; return 0; }
	while (Game[computer_choose - 1] == *player_ || Game[computer_choose - 1] == *computer_) {
		computer_choose = rand() % 9 + 1;
	}
	Game[computer_choose - 1] = *computer_;
	return 0;

}
int check(char* Game, const  char* player_, const char* computer_, char hehe) {
	if (Game[0] == Game[1] && Game[0] == Game[2] && Game[0] == *player_) return 1;
	if (Game[3] == Game[4] && Game[3] == Game[5] && Game[3] == *player_) return 1;
	if (Game[6] == Game[7] && Game[6] == Game[8] && Game[6] == *player_) return 1;
	if (Game[0] == Game[4] && Game[4] == Game[8] && Game[4] == *player_) return 1;
	if (Game[2] == Game[4] && Game[2] == Game[6] && Game[2] == *player_) return 1;
	if (Game[1] == Game[4] && Game[1] == Game[7] && Game[1] == *player_) return 1;
	if (Game[0] == Game[3] && Game[0] == Game[6] && Game[3] == *player_) return 1;
	if (Game[2] == Game[5] && Game[2] == Game[8] && Game[2] == *player_) return 1;


	if (Game[0] == Game[1] && Game[0] == Game[2] && Game[0] == *computer_) return 2;
	if (Game[3] == Game[4] && Game[3] == Game[5] && Game[3] == *computer_) return 2;
	if (Game[6] == Game[7] && Game[6] == Game[8] && Game[6] == *computer_) return 2;
	if (Game[0] == Game[4] && Game[4] == Game[8] && Game[4] == *computer_) return 2;
	if (Game[2] == Game[4] && Game[2] == Game[6] && Game[2] == *computer_) return 2;
	if (Game[0] == Game[3] && Game[4] == Game[6] && Game[3] == *computer_) return 2;
	if (Game[2] == Game[5] && Game[2] == Game[8] && Game[2] == *computer_) return 2;

	return 0;
}

int main() {
	bool running = true;
	char player_ = 'X';
	char computer_ = 'O';
	char hehe = ' ';
	char Game[9]; 

		std::fill(Game, Game + 9, hehe);
	draw(Game);
	int count = 0;
	while (running == true && count < 9) {
		player(Game, &player_,&computer_);
		_computer(Game, &computer_, &player_);
		draw(Game);
		count++;

		if ((check(Game, &player_, &computer_, hehe))) running = false;
	}
	if (count <= 9 && (check(Game, &player_, &computer_, hehe)) == 1) { std::cout << "Player Win!" << std::endl; return 0; }
	if (count <= 9 && (check(Game, &player_, &computer_, hehe)) == 2) { std::cout << "Computer Win!" << std::endl; return 0; }
	else std::cout << "End in a draw!" << std::endl;

}