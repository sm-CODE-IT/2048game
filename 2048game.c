#include <stdio.h>
#include <Windows.h>
#include <time.h>
#include <conio.h>

#define LEFT_WARD 75
#define RIGHT_WARD 77
#define UP_WARD 72
#define DOWN_WARD 80

int board[4][4] = { {0,0,0,0},
			{0,0,0,0},
			{0,0,0,0},
			{0,0,0,0}
};

int score = 0;

void gotoxy(int x, int y) {
	COORD pos = { x,y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

void color(int num) {
	if (num == 2) {
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 8);
	}
	else if (num == 4) {
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 8);
	}
	else if (num == 8) {
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 8);
	}
	else if (num == 16) {
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
	}
	else if (num == 32) {
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
	}
	else if (num == 64) {
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 5);
	}
	else if (num == 128) {
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 3);
	}
	else if (num == 256) {
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 1);
	}
	else if (num == 512) {
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);
	}
	else if (num == 1028) {
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
	}
	else if (num >= 2048) {
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
	}
}

int press_key() {
	int a, b, c;
	int press_chck = 0;

	switch (_getch()) {
	case LEFT_WARD:
		for (a = 0; a < 4; a++) {
			for (b = 1; b < 4; b++) {
				for (c = b; c > 0; c--) {
					if (board[a][c] % 2 == 1) break;
					// 0 0 => 0 0, 2 0 => 2 0
					if (board[a][c] == 0) break;
					// 2 4 => 2 4
					if (board[a][c - 1] != 0 && board[a][c] != board[a][c - 1]) break;
					//0 2 => 2 0
					if (board[a][c - 1] == 0) {
						board[a][c - 1] = board[a][c];
						board[a][c] = 0;
					}
					//2 2=> 4 0
					else if (board[a][c] == board[a][c - 1]) {
						board[a][c - 1] *= 2;
						score += board[a][c - 1];
						board[a][c] = 0;
						board[a][c - 1]++;
					}
					press_chck++;
				}
			}
		}
		break;

	case RIGHT_WARD:
		for (a = 0; a < 4; a++) {
			for (b = 2; b > -1; b--) {
				for (c = b; c < 3; c++) {
					if (board[a][c] % 2 == 1) break;
					// 0 0 => 0 0, 0 2 => 0 2
					if (board[a][c] == 0) break;
					// 2 4 => 2 4
					if (board[a][c + 1] != 0 && board[a][c] != board[a][c + 1]) break;
					//2 0 => 0 2
					if (board[a][c + 1] == 0) {
						board[a][c + 1] = board[a][c];
						board[a][c] = 0;
					}
					//2 2=> 0 4
					else if (board[a][c] == board[a][c + 1]) {
						board[a][c + 1] *= 2;
						score += board[a][c + 1];
						board[a][c] = 0;
						board[a][c + 1]++;
					}
					press_chck++;
				}
			}
		}
		break;


	case UP_WARD:
		for (a = 0; a < 4; a++) {
			for (b = 1; b < 4; b++) {
				for (c = b; c > 0; c--) {
					if (board[c][a] % 2 == 1) break;
					/*0 => 0  2 => 0
					  0 => 0, 0 => 0*/
					if (board[c][a] == 0) break;
					/*4 => 4
					  2 => 2*/
					if (board[c - 1][a] != 0 && board[c][a] != board[c - 1][a]) break;
					/*0 => 2
					  2 => 0*/
					if (board[c - 1][a] == 0) {
						board[c - 1][a] = board[c][a];
						board[c][a] = 0;
					}
					/*2 => 4
					  2 => 0*/
					else if (board[c][a] == board[c - 1][a]) {
						board[c - 1][a] *= 2;
						score += board[c - 1][a];
						board[c][a] = 0;
						board[c - 1][a]++;
					}
					press_chck++;
				}
			}
		}
		break;

	case DOWN_WARD:
		for (a = 0; a < 4; a++) {
			for (b = 2; b > -1; b--) {
				for (c = b; c < 3; c++) {
					if (board[c][a] % 2 == 1) break;
					/*0 => 0  0 => 0
					  0 => 0, 2 => 2*/
					if (board[c][a] == 0) break;
					/*2 => 2
					  4 => 4*/
					if (board[c + 1][a] != 0 && board[c][a] != board[c + 1][a]) break;
					/*2 => 0
					  0 => 2*/
					if (board[c + 1][a] == 0) {
						board[c + 1][a] = board[c][a];
						board[c][a] = 0;
					}
					/*2 => 0
					  2 => 4*/
					else if (board[c][a] == board[c + 1][a]) {
						board[c + 1][a] *= 2;
						score += board[c + 1][a];
						board[c][a] = 0;
						board[c + 1][a]++;
					}
					press_chck++;
				}
			}
		}
		break;
	}

	for (a = 0; a < 4; a++) {
		for (b = 0; b < 4; b++) {
			if (board[a][b] % 2 == 1) {
				board[a][b]--;
			}
		}
	}
	return press_chck;
}

void initial_prnt_board() {
	system("mode con cols=32 lines=22");
	printf("\n          式忖 忙忖 弛弛 忙忖\n");
	printf("          忙戎 弛弛 戌扣 戍扣\n");
	printf("          戌式 戌戎  弛 戌戎\n\n");
	printf("   score:                   \n\n");
	printf(" 忙式式式式式式式式式式式式式式式式式式式式式式式式式式式忖\n");
	printf(" 弛                           弛\n");
	printf(" 弛                           弛\n");
	printf(" 弛                           弛\n");
	printf(" 弛                           弛\n");
	printf(" 弛                           弛\n");
	printf(" 弛                           弛\n");
	printf(" 弛                           弛\n");
	printf(" 弛                           弛\n");
	printf(" 弛                           弛\n");
	printf(" 弛                           弛\n");
	printf(" 弛                           弛\n");
	printf(" 弛                           弛\n");
	printf(" 戌式式式式式式式式式式式式式式式式式式式式式式式式式式式戎");
}

void prnt_board() {
	for (int a = 0; a < 4; a++) {
		gotoxy(2, 9 + 3 * a);
		for (int b = 0; b < 4; b++) {
			color(board[a][b]);
			if (board[a][b] == 0) printf("      ");
			else printf("%6d", board[a][b]);
		}
		printf("\n\n\n");
	}
	gotoxy(10, 5);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
	printf("%d", score);
}

void make_num() {
	int a, b, cnt = 0;
	int* num[16] = { 0 };

	for (a = 0; a < 4; a++) {
		for (b = 0; b < 4; b++) {
			if (board[a][b] == 0) {
				num[cnt] = &board[a][b];
				cnt++;
			}
		}
	}
	*num[rand() % cnt] = rand() % 100 < 70 ? 2 : 4;
}

void check_rpdly() {
	int a, b;

	for (a = 0; a < 4; a++) {
		for (b = 0; b < 4; b++) {
			if (board[a][b] == 0) return;
		}
	}
	for (a = 0; a < 3; a++) {
		for (b = 0; b < 3; b++) {
			if (board[a][b] == board[a + 1][b] || board[a][b] == board[a][b + 1]) return;
		}
	}
	for (a = 0; a < 3; a++) {
		for (b = 0; b < 3; b++) {
			if (board[b][a] == board[b + 1][a] || board[b][a] == board[b][a + 1]) return;
		}
	}
	system("cls");
	printf("\n\n\n\n\n           Game Over\n");
	printf("           score: %d\n\n\n\n\n", score);
	exit(0);
}

void CursorView(char show){
	HANDLE hConsole;
	CONSOLE_CURSOR_INFO ConsoleCursor;

	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

	ConsoleCursor.bVisible = show;
	ConsoleCursor.dwSize = 1;

	SetConsoleCursorInfo(hConsole, &ConsoleCursor);
}

void main() {
	CursorView(0);
	make_num();
	make_num();
	initial_prnt_board();
	prnt_board();
	while (1) {
		if (press_key() > 0) {
			make_num();
			prnt_board();
			check_rpdly();
		}
	}
}