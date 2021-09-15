// GameSnake v0.0000000000001
#include<iostream>
#include<conio.h>
#include<Windows.h>
enum eDiraction { STOP = 0, LEFT, RIGHT, UP, DOWN };
eDiraction dir;
int cw = 0;
using namespace std;
bool GameOver;
const int width = 50;
const int height = 25 - 2; // 25 -2 потому что две отдельные линии сверху и снизу рисуются отдельно
int x, y;
void Setup() {
	GameOver = false;
	dir = STOP;
	x = width / 2 - 1;
	y = height / 2 - 1;
}
void Draw() {
	system("cls");
	Sleep(16);
	for (int i = 0; i < width + 1; i++)
		cout << "#";
	cout << " w a s d x r escape";
	cout << endl; // рисует верх
	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			if (j == 0 or j == width - 1) {
				cout << "#";
			}
			if (i == y and j == x) {
				cout << "0";
			}
			else {
				cout << " ";
			} // Тут рисовка поля

		}
		cout << endl;
	}// Рисует по бокам
	for (int i = 0; i < width + 1; i++)
		cout << "#";// рисует низ
	cout << endl;

	cout << "x = " << x / 2 << " y = " << y << endl;// тут координаты для удобства
}
void Input() {
	if (_kbhit()) {
		switch (_getch()) {
		case 27:
			cout << "You pressed escape and quit the game";
			exit(0);
		case 'r':
			dir = STOP;
			break;
		case 'a':
			dir = LEFT;
			break;
		case 's':
			dir = DOWN;
			break;
		case 'w':
			dir = UP;
			break;
		case 'd':
			dir = RIGHT;
			break;
		case 'x':
			GameOver = true;
			Sleep(500);
			break;
		} // тут обработка нажатий клавиш
	}
}
void Logic() {
	switch (dir)
	{
	case LEFT:
		x--;
		x--;
		break;
	case RIGHT:
		x++;
		x++;
		break;
	case UP:
		y--;
		break;
	case DOWN:
		y++;
		break;
	case STOP:
		y = height / 2 - 1;
		x = width / 2 - 1;
		break;
	}		// Тут логика действий при нажатой клавише
	if (y >= height) {
		GameOver = true;
	}
	else if (y < 0) {
		GameOver = true;
	}
	else if (x < 0) {
		GameOver = true;
	}
	else if (x >= width) {
		GameOver = true;
	} // Если уходишь за поля игры то ты проиграл

}
void LogicForGameOver() {
	if (_kbhit()) {
		switch (_getch()) {
		case 27:
			cout << "\nYou pressed escape and quit the game";
			exit(0);
		case 'x':
			GameOver = false;
			Sleep(500);
			break;
		case 'g':
			cout << endl << "You get pressent: https://www.youtube.com/watch?v=dQw4w9WgXcQ"; // Подарок
			if (cw > 0) {}
			else {
				system("start https://www.youtube.com/watch?v=dQw4w9WgXcQ");
			}
			cw++;
		}
	}
}
void DrawForGameOver() {
	system("cls");
	cout << "GAME OVER";
	for (int i = 0; i < width - 8; i++) {
		cout << "R";
	}
	cout << endl << "Press x for restart";
}
int main() {
A: ///////////// СCЫЛКА ЗДЕСЬ 141 СТРОКА
	Setup();
	while (!GameOver) {
		Draw();
		Input();
		Logic();
	}
	while (GameOver) {
		LogicForGameOver();
		DrawForGameOver();
		if (!GameOver) {
			goto A;
		}
	}
	return 0;
}
