/*
	James Pope
	10/31/20
	Leaf Shinobi Interactive Fiction
	This program is a quick interactive fiction game. Enjoy!
*/

#include <iostream>

using namespace std;

enum class playerStory { Uchiha, Hyuga, Senju };

void intro();
void showMissionDetails(string name, string clan);
string getPlayerName();
string getClan();
void tellStory(string clan, playerStory story);

int main() 
{
	// create enum class variable and initialize it with a default value
	playerStory story = playerStory::Uchiha;

	intro();
	string name = getPlayerName();
	string clan = getClan();
	showMissionDetails(name, clan);
	tellStory(clan, story);

	return 0;
}

void intro() 
{
	cout << "------------------------------------------------------------------\n";
	cout << "Welcome to Ninja Adventures, Shinobi.\n";
	cout << "This is a short text adventure game.\n";
	cout << "Please be sure to pay attention to how you type your commands.\n";
	cout << "Aside from the upcoming information you will enter in the intro, ";
	cout << "everything should be typed in all lowercase.\n";
	cout << "------------------------------------------------------------------\n";
	cout << "\nToday, the Hokage has assigned you a special mission.\n";
	cout << "But first, please fill out some personfal information below:\n";
}

string getPlayerName() 
{
	//var to hold player name
	string name;
	//prompt the player to enter their name and store it
	cout << "What is your name? ";
	cin >> name;
	//add "Sensei" to the end of their name.
	name = name + " Sensei";
	//address them properly so the player can see how they will be referred to.
	cout << "\nWelcome, " + name + ".\n";
	
	return name;
}

string getClan() 
{
	string clan;
	do
	{
		cout << "\nYou have three clans to choose from; Uchiha, Hyuga, or Senju.\n";
		cout << "Which clan do you belong to?\n";
		cin >> clan;
	} while (clan != "Uchiha" && clan != "Hyuga" && clan != "Senju");

	if (clan == "Uchiha") 
	{
		cout << "\nSuch visual prowess, but it comes at a price.\n";
		cout << "Though, this mission might just be the perfect fit for you.\n";
	}
	else if (clan == "Hyuga") 
	{
		cout << "\nAh, so I see you hold the Byakugon in your eyes.\n";
		cout << "Use them wisely.\n";
	}
	else 
	{
		cout << "\nThe proud lineage from which The Leaf began.\n";
		cout << "I expect much from you.\n";
	}

	return clan;
}

void showMissionDetails(string name, string clan) 
{
	cout << "\nMission Details:\n";
	cout << "A former Anbu Black Ops has turned rogue.\n";
	cout << "They have taken extremely sensative information pertaining to the Hidden Leaf.\n";
	cout << "We can assume they mean to sell this information to an enemy village.\n";
	cout << "His name is Akio Amamiya, he is a very talented ninja and posses a powerful kekkai genkai.\n";
	cout << "the Inuzuka clan has tracked his scent "; 
	cout << "to a small village on the border of the Land of Fire.\n";
	cout << "You are permitted to use any force ";
	cout <<	"you deem necessary to succeed in your mission.\n";
	cout << "The " + clan + " Clan, and The Leaf put their faith in you, " + name << endl;
}

void tellStory(string clan, playerStory story)
{
	if (clan == "Uchiha") 
	{
		story = playerStory::Uchiha;
	}
	else if (clan == "Hyuga") 
	{
		story = playerStory::Hyuga;
	}
	else 
	{
		story = playerStory::Senju;
	}

	switch (story)
	{
	case playerStory::Uchiha:
		cout << "\nThis is the Uchiha Story.\n";
		break;
	case playerStory::Hyuga:
		cout << "\nThis is the Hyuga Story.\n";
		break;
	case playerStory::Senju:
		cout << "\nThis is the Senju Story.\n";
		break;
	default:
		cout << "\nInvalid choice, ending program.\n";
		break;
	}
}