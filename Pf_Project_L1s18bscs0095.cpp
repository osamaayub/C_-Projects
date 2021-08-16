#include<iostream>
#include<fstream>
using namespace std;
void Loadmaze(ifstream &fin, int **arr, int r, int c);
void Pause(int **arr, int r, int c);
void Resume(int **arr, int r, int c);
void check_move(ifstream &fin, int **arr, int r, int c, char n[25]);
void showmaze(int **arr, int row, int col);
void swaparr(char arr[25], char arr1[25]);
void showHighscoreTable();
void save_user_score(int **arr, int r, int c);
int main()
{
	char name[25] = { '\0' };
	ifstream fin;
	int **ptr = nullptr, row = 0, col = 0;
	char choice = 0, choice1 = 0, choice2 = 0;
	cout << "Enter Player Name=";
	cin >> name;
	cout << "Menu" << endl;
	cout << "Press S for Start New Game" << endl;
	cin >> choice;
	if (choice == 'S')
	{
		cout << "Press L For Level Selection" << endl;
		cin >> choice1;
		if (choice1 == 'L')
		{	
			cout << "Press E For Easy Level" << endl;
			cout << "Press M For Medium Level" << endl;
			cout << "Press H For Hard Level" << endl;
			cout << "Input=";
			cin >> choice2;
			if (choice2 == 'E')
			{
				fin.open("Easy.txt");
				row = 4, col = 4;
				ptr = new int*[row];
				for (int i = 0; i < row; i++)
				{
					ptr[i] = new int[col];
				}
				check_move(fin, ptr, row, col, name);
			}
			else if (choice2 == 'M')
			{
				fin.open("Medium.txt");
				row = 5, col = 5;
				ptr = new int*[row];
				for (int i = 0; i < row; i++)
				{
					ptr[i] = new int[col];
				}
				check_move(fin, ptr, row, col, name);
			}
			else if (choice2 == 'H')
			{
				fin.open("Hard.txt");
				row = 6, col = 6;
				ptr = new int*[row];
				for (int i = 0; i < row; i++)
				{
					ptr[i] = new int[col];
				}
				check_move(fin, ptr, row, col, name);
			}
			else
			{
				cout << "Wrong Input" << endl;
			}
		}
		else
		{
			cout << "Wrong Input" << endl;
		}
	}
	else
	{
		cout << "Wrong Input" << endl;
	}
	cout << "Highest Score Table Stored In Scores.txt File" << endl;
	showHighscoreTable();
	delete[]ptr;
	ptr = NULL;
	return 0;
}
void LoadMaze(ifstream &fin, int **arr, int r, int c)
{
	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			fin >> arr[i][j];
		}
	}
}
void check_move(ifstream &fin, int **arr, int r, int c, char n[25])
{
	ofstream fout;
	fout.open("Scores.txt", ios::app);
	int *dest = nullptr, *source = nullptr, *pl = nullptr, ply = 7, x = 0, y = 0, lives = 3, score = 0;
	char ch = 0;
	LoadMaze(fin, arr, r, c);
	fin.close();
	dest = &arr[r - 1][c - 1];
	source = &arr[0][0];
	pl = &arr[0][0];
	arr[0][0] = ply;
	save_user_score(arr, r, c);
	cout << "Input Moves in I,J Cordinates " << endl;
	while (lives > 0 && pl != dest)
	{
		cout << "Input Value of I=";
		cin >> x;
		cout << "Input Value Of J=";
		cin >> y;
		if (x >= 0 && x < r && y >= 0 && y < c)
		{
			if (arr[x][y] == 1)
			{
				score += 5;
				cout << "Score=" << score << endl;
				cout << "Lives=" << lives << endl;
				pl = &arr[x][y];
				arr[x][y] = ply;
			}
			else if (arr[x][y] == 0)
			{
				score -= 1;
				cout << "Score=" << score << endl;
			}
			else if (arr[x][y] == -2)
			{
				lives--;
				score -= 5;
				cout << "Score=" << score << endl;
				cout << "Lives=" << lives << endl;
			}
			if (lives > 0 && pl != dest)
			{
				cout << "Press P For Pause Game If Not Press Any Key To Continue" << endl;
				cout << "Input=";
				cin >> ch;
				if (ch == 'P')
				{
					Pause(arr, r, c);
					cout << "Press R For Resume Game" << endl;
					cout << "Press Any Key For Exit" << endl;
					cout << "Input=";
					cin >> ch;
					if (ch == 'R')
					{
						Resume(arr, r, c);
						//print(arr, r, c);
					}
					else
					{
						break;
					}
				}
			}
		}
		else
		{
			cout << "Wrong Input" << endl;
		}
	}
	if (pl == dest)
	{
		cout << endl;
		showmaze(arr, r, c);
		cout << "\nSuccessFully Reached" << endl;
		cout << "Name" << n<< " " << "Score" <<" "<<score << endl;
		fout << n << " " << score << endl;
	}
	else if (lives == 0 && pl != dest)
	{
		cout << "\nGame Lose" << endl;
	}
	fout.close();
}
void save_user_score(int **arr, int r, int c)
{
	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			cout << arr[i][j] << " ";
		}
		cout << endl;
	}
}
void Pause(int **arr, int r, int c)
{
	ofstream fout;
	fout.open("Pause.txt");
	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			fout << arr[i][j] << " ";
		}
		fout << endl;
	}
	fout.close();
}
void Resume(int **arr, int r, int c)
{
	ifstream fin;
	fin.open("Pause.txt");
	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			fin >> arr[i][j];
		}
	}
	fin.close();
}
void showHighscoreTable()
{
	char arr[25] = { '\0' }, **arr1 = nullptr;
	int score = 0, record = 0, *scores = nullptr;
	ifstream fin;
	fin.open("Scores.txt");
	while (fin >> arr && fin >> score)
	{
		record++;
	}
	fin.close();
	arr1 = new char*[record];
	scores = new int[record];
	for (int i = 0; i < record; i++)
	{
		arr1[i] = new char[25]{'\0'};
	}
	fin.open("Scores.txt");
	for (int i = 0; i < record; i++)
	{
		fin >> arr1[i];
		fin >> scores[i];
	}
	fin.close();
	ofstream fout;
	fout.open("Scores.txt");
	for (int i = 0; i < record; i++)
	{
		for (int j = i + 1; j < record; j++)
		{
			if (scores[i] > scores[j])
			{
				swaparr(arr1[i], arr1[j]);
				swap(scores[i], scores[j]);
			}
		}
	}
	for (int i = 0; i < record; i++)
	{
		fout << arr1[i] << " ";
		fout << scores[i] << endl;
	}
	delete[]arr1;
	arr1 = NULL;
	fout.close();
}
void swaparr(char arr[25], char arr1[25])
{
	char arr2[25] = { '\0' };
	int i = 0;
	for (i = 0; arr[i] != '\0'; i++)
	{
		arr2[i] = arr[i];
	}
	arr2[i] = '\0';
	for (i = 0; arr1[i] != '\0'; i++)
	{
		arr[i] = arr1[i];
	}
	arr[i] = '\0';
	for (i = 0; arr2[i] != '\0'; i++)
	{
		arr1[i] = arr2[i];
	}
	arr1[i] = '\0';
}
void showmaze(int **arr, int row, int col)
{
	int x = 0;
	cout << char(218) << char(196) << char(196) << char(194);
	for (int i = 0; i < row - 2; i++)
	{
		cout << char(196) << char(196) << char(194);
	}
	cout << char(196) << char(196) << char(191) << endl;
	for (int i = 0; i < col; i++)
	{
		if (arr[x][i] == 7)
		{
			cout << char(179) << '1' << char(255);
		}
		else
		{
			cout << char(179) << '0' << char(255);
		}
	}
	cout << char(179) << endl;
	x++;
	for (int j = 0; j < row - 1; j++)
	{
		cout << char(195) << char(196) << char(196) << char(197);
		for (int i = 0; i < row - 2; i++)
		{
			cout << char(196) << char(196) << char(197);
		}
		cout << char(196) << char(196) << char(180) << endl;
		for (int i = 0; i < col; i++)
		{
			if (arr[x][i] == 7)
			{
				cout << char(179) << '1' << char(255);
			}
			else
			{
				cout << char(179) << '0' << char(255);
			}
		}
		x++;
		cout << char(179) << endl;
	}
	cout << char(192);
	for (int i = 0; i < row - 1; i++)
	{
		cout << char(196) << char(196) << char(193);
	}
	cout << char(196) << char(196) << char(217);
}