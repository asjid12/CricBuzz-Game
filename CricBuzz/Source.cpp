#pragma once

#include<iostream>
#include<fstream>
#include<string>
#include<conio.h>  // To detect key press
using namespace std;


class Player
{
	//private attributes
protected:
	string name;
	int shirt_no;
	float average;
	int ranking;
	int total_runs;
	int total_matches;
	int total_wickets;
public:
	//methods of PLAYER
	void add_Player();
	void remove_Player();
	void search_Player();
	void update_Player();
};
//class: TEAM
class Team :public Player
{
	//private attributes
	string team_name;
	int team_ranking;
	int no_players;
	int matches_won;
	int matches_lost;
	string captain;
	string coach;
	string admin_username;
	string admin_password;
	int currentNumberOfPlayers;
	//extras
	int addition_choice;
public:
	//methods and functioning of TEAM class
	Team()
	{
		currentNumberOfPlayers = 0;
	}

	//player addition
	void add_Player(string teamName)
	{
		this->team_name = teamName;
		string fileName2 = teamName + "_data.txt";

		ofstream pakistan_data(fileName2, ios::app);

		if (!pakistan_data.is_open())
		{
			cout << "\n\n\t\t\t\t\t    An error occured opening '" << fileName2 << "' file\n";
			return;
		}
		
		if (team_name == "pakistan")
		{
			if (currentNumberOfPlayers >= 11)
			{
				cout << "\n\t\t\t\t\t\t   The team already has 11 players\n";
				return;
			}

			this->currentNumberOfPlayers++;
			cout << "\n\t\t\t\t\t\t   Enter PLAYER NAME: ";
			cin >> name;
			pakistan_data << name << endl;
			cout << "\n\t\t\t\t\t\t   Enter PLAYER SHIRT NO: ";
			cin >> shirt_no;
			pakistan_data << shirt_no << endl;
			cout << "\n\t\t\t\t\t\t   Enter average: ";
			cin >> average;
			pakistan_data << average << endl;
			cout << "\n\t\t\t\t\t\t   Enter PLAYER RANKING: ";
			cin >> ranking;
			pakistan_data << ranking << endl;
			cout << "\n\t\t\t\t\t\t   Enter TOTAL RUNS: ";
			cin >> total_runs;
			pakistan_data << total_runs << endl;
			cout << "\n\t\t\t\t\t\t   Enter TOTAL MATCHES: ";
			cin >> total_matches;
			pakistan_data << total_matches << endl;
			cout << "\n\t\t\t\t\t\t   Enter TOTAL WICKETS: ";
			cin >> total_wickets;
			pakistan_data << total_wickets << endl;
			cout << "\n\t\t\t\t\t\t   PLAYER DATA ADDED SUCCESSFULLY!" << "\n\n";
			pakistan_data << name << "end" << endl;
		}
		else
		{
			cout << "\n\t\t\t\t\t\t   NO SUCH TEAM EXISTS!\n" << endl;
		}

		pakistan_data.close();
	}

	void remove_Player(string playerName, string teamName)
	{
		teamName += "_data.txt";
		string playersData[11];  // At max 11 players
		string line;
		int playersCounter = 0;
		ifstream readFile(teamName);
		if (!readFile.is_open())
		{
			cout << "\n\n\t\t\t\t\t    An error occured opening '" << teamName << "' file\n";
			return;
		}

		
		while (getline(readFile, line))
		{
			bool skip = false;
			if (line != playerName)
			{
				playersData[playersCounter] += line;
				playersData[playersCounter] += "\n";
			}
			else
				skip = true;

			for (int i = 0;i < 7;i++)
			{
				getline(readFile, line);
				if (!skip)
				{
					playersData[playersCounter] += line;
					playersData[playersCounter] += "\n";
				}
			}
			if (!skip)
			{
				playersCounter++;
			}
		}

		ofstream writeFile(teamName);
		for (int i = 0;i < playersCounter;i++)
		{
			writeFile << playersData[i];
		}

		cout << "\n\n\t\t\t\t\t\tPLAYER REMOVED SUCCESSFULLY\n: ";
		this->currentNumberOfPlayers--;
	}

	void search_Player(string playerName, string teamName)
	{
		teamName += "_data.txt";
		ifstream readFile(teamName);
		if (!readFile.is_open())
		{
			cout << "\n\n\t\t\t\t\t    An error occured opening '" << teamName << "' file\n";
			return;
		}
		string line;

		bool found = false;
		while (getline(readFile, line))
		{
			if (line == playerName)
			{
				found = true;
				cout << "\n\t\t\t\t\t\t   Player Name: " << line << endl;

				getline(readFile, line);
				cout << "\n\t\t\t\t\t\t   Shirt Number: " << line << endl;

				getline(readFile, line);
				cout << "\n\t\t\t\t\t\t   Average: " << line << endl;

				getline(readFile, line);
				cout << "\n\t\t\t\t\t\t   Ranking: " << line << endl;

				getline(readFile, line);
				cout << "\n\t\t\t\t\t\t   Total Runs: " << line << endl;

				getline(readFile, line);
				cout << "\n\t\t\t\t\t\t   Total Matches: " << line << endl;

				getline(readFile, line);
				cout << "\n\t\t\t\t\t\t   Total Wickets: " << line << endl;
				
				getline(readFile, line);
			}
		}

		if (!found)
		{
			cout << "\n\t\t\t\t\t\t   | No such player exists |\n";
		}
	}

	void update_Player(string playerName, string teamName)
	{
		teamName += "_data.txt";
		string playersData[11];  // At max 11 players
		string line;
		string temp;
		int playersCounter = 0;
		ifstream readFile(teamName);
		if (!readFile.is_open())
		{
			cout << "\n\n\t\t\t\t\t    An error occured opening '" << teamName << "' file\n";
			return;
		}

		while (getline(readFile, line))
		{
			playersData[playersCounter] += line;
			playersData[playersCounter] += "\n";

			bool found = false;
			if (line == playerName)
			{
				found = true;
			}

			if (found)
			{
				getline(readFile, line);
				cout << "\n\t\t\t\t\t\t   Enter PLAYER SHIRT NO: ";
				cin >> temp;
				playersData[playersCounter] += temp;
				playersData[playersCounter] += "\n";

				getline(readFile, line);
				cout << "\n\t\t\t\t\t\t   Enter average: ";
				cin >> temp;
				playersData[playersCounter] += temp;
				playersData[playersCounter] += "\n";

				getline(readFile, line);
				cout << "\n\t\t\t\t\t\t   Enter PLAYER RANKING: ";
				cin >> temp;
				playersData[playersCounter] += temp;
				playersData[playersCounter] += "\n";

				getline(readFile, line);
				cout << "\n\t\t\t\t\t\t   Enter TOTAL RUNS: ";
				cin >> temp;
				playersData[playersCounter] += temp;
				playersData[playersCounter] += "\n";

				getline(readFile, line);
				cout << "\n\t\t\t\t\t\t   Enter TOTAL MATCHES: ";
				cin >> temp;
				playersData[playersCounter] += temp;
				playersData[playersCounter] += "\n";

				getline(readFile, line);
				cout << "\n\t\t\t\t\t\t   Enter TOTAL WICKETS: ";
				cin >> temp;
				playersData[playersCounter] += temp;
				playersData[playersCounter] += "\n";

				getline(readFile, line);
				playersData[playersCounter] += line;
				playersData[playersCounter] += "\n";
				
			}

			else if (!found)
			{
				for (int i = 0;i < 7;i++)
				{
					getline(readFile, line);
					playersData[playersCounter] += line;
					playersData[playersCounter] += "\n";
				}
			}
			playersCounter++;
		}

		ofstream writeFile(teamName);
		for (int i = 0;i < playersCounter;i++)
		{
			writeFile << playersData[i];
		}

		cout << "\n\t\t\t\t\t\t   PLAYER DATA UPDATED SUCCESSFULLY!" << "\n\n";
	}

	void update_Captain(string teamName)
	{
		ifstream readFile("captains.txt");
		string data[20];
		int dataCounter = 0;
		if (!readFile.is_open())
		{
			cout << "\n\n\t\t\t\t\t    An error occured opening 'captains.txt' file\n";
			return;
		}
		string line;
		string newName;

		cout << "\n\t\t\t\t\t\t   Enter new captain's name: ";
		cin >> newName;

		while (getline(readFile, line))
		{
			data[dataCounter] += line;
			data[dataCounter] += "\n";

			if (line == teamName)
			{
				getline(readFile, line);
				data[dataCounter] += newName;
				data[dataCounter] += "\n";
			}
			else
			{
				getline(readFile, line);
				data[dataCounter] += line;
				data[dataCounter] += "\n";
			}
			dataCounter++;
		}

		ofstream writeFile("captains.txt");
		for (int i = 0;i < dataCounter;i++)
		{
			writeFile << data[i];
		}

		cout << "\n\n\t\t\t\t\t\tCAPTAIN UPDATED SUCCESSFULLY\n: ";
		
	}

	void update_Coach(string teamName)
	{
		ifstream readFile("coaches.txt");
		string data[20];
		int dataCounter = 0;
		if (!readFile.is_open())
		{
			cout << "\n\n\t\t\t\t\t    An error occured opening 'captains.txt' file\n";
			return;
		}
		string line;
		string newName;

		cout << "\n\t\t\t\t\t\t   Enter new captain's name: ";
		cin >> newName;

		while (getline(readFile, line))
		{
			data[dataCounter] += line;
			data[dataCounter] += "\n";

			if (line == teamName)
			{
				getline(readFile, line);
				data[dataCounter] += newName;
				data[dataCounter] += "\n";
			}
			else
			{
				getline(readFile, line);
				data[dataCounter] += line;
				data[dataCounter] += "\n";
			}
			dataCounter++;
		}

		ofstream writeFile("coaches.txt");
		for (int i = 0;i < dataCounter;i++)
		{
			writeFile << data[i];
		}

		cout << "\n\n\t\t\t\t\t\tCOACH UPDATED SUCCESSFULLY\n: ";

	}

	void display_Team(string teamName)
	{
		teamName += "_data.txt";
		string line;
		ifstream readFile(teamName);
		if (!readFile.is_open())
		{
			cout << "\n\n\t\t\t\t\t    An error occured opening '"<< teamName <<"' file\n";
			return;
		}

		while (getline(readFile, line))
		{
			cout << "\n\n\t\t\t\t\t\t    " << line << endl << endl;
			for (int i = 0;i < 7;i++)
			{
				getline(readFile, line);
			}
		}
	}
};

int main()
{
	int choice, choice1;  //for access team
	Team obj1;

mainMenu:   // label specifying main menu

	system("cls");
	cout << "\n\n\n\n\n\t\t\t\t--------------------| WELCOME TO CRICBUZZ APP |--------------------\n" << endl;
	cout << "\t\t\t\t\t\t1)     ACCESS TEAM\n" << endl;
	cout << "\t\t\t\t\t\t2)     Exit\n\n" << endl;
	cout << "\t\t\t\t\t\t       CHOICE: ";
	cin >> choice;
	

	//greater(for team class)
	if (choice == 1)
	{
	playerMenu:  // label specifying access team menu

		system("cls");
		cout << "\n\n\n\n\n\t\t\t\t--------------------|   ACCESS TEAM   |--------------------\n" << endl;
		cout << "\t\t\t\t\t\t1)      ADD PLAYER\n" << endl;
		cout << "\t\t\t\t\t\t2)      REMOVE PLAYER\n" << endl;
		cout << "\t\t\t\t\t\t3)      SEARCH PLAYER\n" << endl;
		cout << "\t\t\t\t\t\t4)      UPDATE PLAYER\n" << endl;
		cout << "\t\t\t\t\t\t5)      DISPLAY MATCHES\n" << endl;
		cout << "\t\t\t\t\t\t6)      UPDATE CAPATAIN\n" << endl;
		cout << "\t\t\t\t\t\t7)      UPDATE COACH\n" << endl;
		cout << "\t\t\t\t\t\t8)      MAIN MENU\n\n" << endl;
		cout << "\t\t\t\t\t\t        CHOICE: ";
		cin >> choice1;


		if (choice1 == 1)
		{
			system("cls");
			cout << "\n\n\n\n\n\t\t\t\t--------------------|   ADD PLAYER   |--------------------\n" << endl;
			cout << "\n\t\t\t\t\t\t   Enter team name: ";
			string teamName;
			cin >> teamName;
			obj1.add_Player(teamName);
			
			cout << "\n\n\t\t(Press 'R' to return to ACCESS TEAM menu)\n\n";

			while (1)  // Wait until the user presses Enter key
			{
				int ch = _getch();
				if (ch == 98 || ch == 114)
				{
					break;
				}
			}
			system("cls");
			goto playerMenu;
		}
		else if (choice1 == 2)
		{
			system("cls");
			cout << "\n\n\n\n\n\t\t\t\t--------------------|   REMOVE PLAYER   |--------------------\n" << endl;
			
			string playerName, teamName;
			cout << "\t\t\t\t\t\tName of player to be removed: ";
			cin >> playerName;
			cout << "\n\t\t\t\t\t\tTeam of the player: ";
			cin >> teamName;

			obj1.remove_Player(playerName, teamName);
			
			cout << "\n\n\t\t(Press 'R' to return to ACCESS TEAM menu)\n\n";

			while (1)  // Wait until the user presses Enter key
			{
				int ch = _getch();
				if (ch == 98 || ch == 114)
				{
					break;
				}
			}
			system("cls");
			goto playerMenu;

		}
		else if (choice1 == 3)
		{
			system("cls");
			cout << "\n\n\n\n\n\t\t\t\t--------------------|   SEARCH PLAYER   |--------------------\n" << endl;

			string playerName, teamName;
			cout << "\n\t\t\t\t\t\tName of player to be searched: ";
			cin >> playerName;
			cout << "\n\t\t\t\t\t\tTeam of the player: ";
			cin >> teamName;

			obj1.search_Player(playerName, teamName);
			
			cout << "\n\n\t\t(Press 'R' to return to ACCESS TEAM menu)\n\n";

			while (1)  // Wait until the user presses Enter key
			{
				int ch = _getch();
				if (ch == 98 || ch == 114)
				{
					break;
				}
			}
			system("cls");
			goto playerMenu;
		}

		else if (choice1 == 4)
		{
			system("cls");
			cout << "\n\n\n\n\n\t\t\t\t--------------------|   UPDATE PLAYER   |--------------------\n" << endl;
			
			string playerName, teamName;
			cout << "\n\t\t\t\t\t\tName of player to be updated: ";
			cin >> playerName;
			cout << "\n\t\t\t\t\t\tTeam of the player: ";
			cin >> teamName;

			obj1.update_Player(playerName, teamName);

			cout << "\n\n\t\t(Press 'R' to return to ACCESS TEAM menu)\n\n";

			while (1)  // Wait until the user presses Enter key
			{
				int ch = _getch();
				if (ch == 98 || ch == 114)
				{
					break;
				}
			}
			system("cls");
			goto playerMenu;
		}


		else if (choice1 == 5)
		{
			system("cls");
			cout << "\n\n\n\n\n\t\t\t\t--------------------|   DISPLAY TEAM   |--------------------\n" << endl;

			string teamName;
			cout << "\n\t\t\t\t\t\tEnter team's name to display its players: ";
			cin >> teamName;

			obj1.display_Team(teamName);

			cout << "\n\n\t\t(Press 'R' to return to ACCESS TEAM menu)\n\n";

			while (1)  // Wait until the user presses Enter key
			{
				int ch = _getch();
				if (ch == 98 || ch == 114)
				{
					break;
				}
			}
			system("cls");
			goto playerMenu;
		}

		else if (choice1 == 6)
		{
			system("cls");
			cout << "\n\n\n\n\n\t\t\t\t--------------------|   UPDATE CAPTAIN   |--------------------\n" << endl;
		
			string teamName;
			cout << "\n\t\t\t\t\t\tEnter team's name to update its captain: ";
			cin >> teamName;

			obj1.update_Captain(teamName);

			cout << "\n\n\t\t(Press 'R' to return to ACCESS TEAM menu)\n\n";

			while (1)  // Wait until the user presses Enter key
			{
				int ch = _getch();
				if (ch == 98 || ch == 114)
				{
					break;
				}
			}
			system("cls");
			goto playerMenu;

		}

		else if (choice1 == 7)
		{

			system("cls");
			cout << "\n\n\n\n\n\t\t\t\t--------------------|   UPDATE COACH   |--------------------\n" << endl;
		
			string teamName;
			cout << "\n\t\t\t\t\t\tEnter team's name to update its coach: ";
			cin >> teamName;

			obj1.update_Coach(teamName);

			cout << "\n\n\t\t(Press 'R' to return to ACCESS TEAM menu)\n\n";

			while (1)  // Wait until the user presses Enter key
			{
				int ch = _getch();
				if (ch == 98 || ch == 114)
				{
					break;
				}
			}
			system("cls");
			goto playerMenu;
		}

		else if (choice1 == 8)
		{
			system("cls");
			goto mainMenu;
		}


	}
	return 0;
}