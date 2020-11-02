/*
	James Pope
	10/31/20
	Leaf Shinobi Interactive Fiction
	This program is a quick interactive fiction game. Enjoy!
*/

#include <iostream>

using namespace std;

//enum for story branching
enum class playerStory { Uchiha, Hyuga, Senju };

//function declarations
void intro();
char askYesOrNo(string question);
void giveInstructions(char answer);
string askText(string question);
void showMissionDetails(string name, string clan);
void tellStory(string clan, playerStory story, string name);
int tellUchihaStory(string name, string clan);
int tellHyugaStory(string name, string clan);
int tellSenjuStory(string name, string clan);
void describeSmallVillage();
void describeBattle(string name, string clan, string command);

int main() 
{
	// create enum class variable and initialize it with a default value
	playerStory story = playerStory::Uchiha;
	// display intro for player
	intro();
	// ask if they want to read the instructions
	char answer = askYesOrNo("Would you like to hear the instructions? y/n: ");
	// give instructions, this code only runs if answer == 'y'
	giveInstructions(answer);
	// get player name
	string name = askText("\nWhat is your name? ");
	// get player clan
	string clan = askText("\nWhich clan do you belong to? You have three clans to choose from; Uchiha, Hyuga, or Senju.\n");
	// show the mission details
	showMissionDetails(name, clan);
	// tell the story they chose
	tellStory(clan, story, name);

	return 0;
}

// introduce player to game
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
	cout << "But first, I have some questions to ask you:\n";
}
// give player instructions on how to play
void giveInstructions(char answer) 
{
	if (answer == 'y') 
	{
		cout << "\nDuring this game you will be presented with choices you must answer via your keyboard.\n";
		cout << "Most answers should be given in all lowercase, ";
		cout << "with the exclusion of your name and clan.\n";
		cout << "When ever you find yourself in a combat situation ";
		cout << "you can type attack, defend, ninjutsu, Byakugan (Hyuga only), and genjutsu (Uchiha only).\n";
		cout << "Any game overs, successful or not, will result in you being asked to play again.\n";
		cout << "Enjoy the game!\n";
	}
}
// generic askText function
string askText(string question) 
{
	string text;
	cout << question;
	cin >> text;
	return text;
}
// generic ask yes or no function
char askYesOrNo(string question) 
{
	// decalre answer variable
	char answer;
	// ask the question passed through parameter
	cout << question;
	// store input in answer
	cin >> answer;
	// return answer
	return answer;
}
// shows the player the mission details when called
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

// picks and plays the story appropriate for player chosen clan
void tellStory(string clan, playerStory story, string name)
{
	// if clan is equal to Uchiha
	if (clan == "Uchiha") 
	{
		// set story enum to Uchiha
		story = playerStory::Uchiha;
	}
	// otherwise if it is equal to "Hyuga"
	else if (clan == "Hyuga") 
	{
		// set story enum to Hyuga
		story = playerStory::Hyuga;
	}
	// otherwise
	else 
	{
		//set story enum to Senju
		story = playerStory::Senju;
	}
	// switch statement for deciding player story
	switch (story)
	{
	case playerStory::Uchiha: // if story is equal to playerStory::Uchiha
		tellUchihaStory(name, clan); // tell Uchiha Story
		break;
	case playerStory::Hyuga: // if story is equal to playerStory::Hyuga
		tellHyugaStory(name, clan); // tell Hyuga Story
		break;
	case playerStory::Senju: // if story is equal to playerStory::Senju
		tellSenjuStory(name, clan); // tell Senju Story
		break;
	default:
		cout << "\nInvalid choice, ending program.\n"; // if somehow it is not equal to any of these end the program
		break;
	}
}

/*
	The following 3 functions consist mainly of couts and handle the main bulk of story telling
	all do loops are just to make sure the player enters correct input
	while all 3 contain a boolean that is used to tell if the player knows of a trap at a certain point in the story
	Also, all 3 contain a string variable declared as command that I use to store the player's commands and do operations with.
	There are 3 separate functions though most of them are the same besides minor details.
	There probably is a more efficient way to do this but as of this writing I have yet to think of it.
	I will only comment out the Uchiha story, as the other tellStory functions are the same
*/
int tellUchihaStory(string name, string clan) 
{
	string command;
	cout << "\nYou have trained hard for this moment.\n";
	cout << "You will prove the " + clan + " Clan is an honorable part of this village!\n";
	command = askText("\nWhat would you like to do? Start your mission now, or buy ninja tools? (start or tools): "); // ask the player to visit a shop, just to get them to practice inputting choices
	do
	{
		// if they just want to start
		if (command == "start")
		{
			// inform them of their mission beginning
			cout << "\nIn true Uchiha fashion, you rush off to start your mission right away.\n";
		}
		//otherwise if they want to buy ninja tools
		else if (command == "tools")
		{
			// inform them how the shopping goes
			cout << "\nYou decide to stop and buy some ninja tools before you head out.\n";
			cout << "Why, if it isn't " + name + " of the Sharingan!";
			cout << "How can I help you today? The usual?";
			cout << "exclaims the shopkeep.\n";
			cout << "You restock on your usual ninja tools; smoke bombs, paper bombs, and some kunai.\n";
			cout << "You bid farewell to the shopkeep as you leave for your mission.\n";
		}
		// otherwise
		else
		{
			// inform them they entered invalid input
			cout << "\nPlease enter a valid command.\n";
		}

	} while (command != "start" && command != "tools"); // this process will loop so long as the player does not enter start or tools to continue

	describeSmallVillage(); // describe the small village they arrive at
	command = askText("\nWhat will you do? (type: interrogate, to interrogate village head. type: cave, to go to the cave.) "); // ask the player what they will do, also provide some prompt on what commands they can enter
	bool knowsTrap = false; // declare a boolean for if the player knows about the upcoming trap initialized to false
	do
	{
		// if they choose to interrogate
		if (command == "interrogate")
		{
			// show them how that goes
			cout << "\nYou decide to interrogate the village leader on the whereabouts of the rogue Anbu.\n";
			cout << "She informs you of the Anbu who she saw enter the cave last night, but never came out.\n";
			cout << "She also mentions that the entrance to the cave may have been rigged with a trap.\n";
			cout << "You thank her and head out for the cave.\n";
			knowsTrap = true; // and now they know about the trap so set the boolean to true
		}
		// otherwise if they just want to go straight to the cave they saw
		else if (command == "cave")
		{
			// prompt the player on their choice
			cout << "\nYou decide to head straight for the cave.\n";
		}
		//otherwise if they enter neither of those
		else
		{
			// tell them they entered an invalid command
			cout << "\nPlease enter a valid command\n";
		}
		// the do loop will repeat unbtil they enter a valid command
	} while (command != "interrogate" && command != "cave");
	
	//if they know about the trap
	if (knowsTrap) 
	{
		//prompt them on their safe entry of the cave
		cout << "\nYou stand at the entrance to the cave.\n";
		cout << "Luckily, you spot the trap that the villagers told you about ";
		cout << "and safely make it inside.\n";
		describeBattle(name, clan, command); // describe battle with Akio
		cout << "\nThe End.\n";
		return 0; // return 0 to end the story
	}
	//otherwise
	else if (knowsTrap == false)
	{
		//they die from the trap
		cout << "\nAs soon as you step into the cave you hear a snapping sound!\n";
		cout << "Kunai spring out from infront of you, piercing into your chest!\n";
		cout << "You struggle to stay standing. ";
		cout << "But, the entry of the cave collapses in on you.\n";
		cout << "You died, game over.\n";
		return 0; //return 0 to end the story
	}
}

int tellHyugaStory(string name, string clan)
{
	string command;
	cout << "\nYou have trained hard for this moment.\n";
	cout << "You will prove the " + clan + " Clan is an honorable part of this village!\n";
	command = askText("\nWhat would you like to do? Start your mission now, or buy ninja tools? (start or tools): ");
	do
	{
		if (command == "start")
		{
			cout << "\nYou rush off to start your mission right away.\n";
		}
		else if (command == "tools")
		{
			cout << "\nYou decide to stop and buy some ninja tools before you head out.\n";
			cout << "Why, if it isn't " + name + " of the Byakugan!";
			cout << "How can I help you today? The usual?";
			cout << "exclaims the shopkeep.\n";
			cout << "You restock on your usual ninja tools; smoke bombs, paper bombs, and some kunai.\n";
			cout << "You bid farewell to the shopkeep as you leave for your mission.\n";
		}
		else
		{
			cout << "\nPlease enter a valid command.\n";
		}

	} while (command != "start" && command != "tools");

	describeSmallVillage();
	command = askText("\nWhat will you do? (type: interrogate, to interrogate village head. type: cave, to go to the cave.) ");
	bool knowsTrap = false;
	do
	{
		if (command == "interrogate")
		{
			cout << "\nYou decide to interrogate the village leader on the whereabouts of the rogue Anbu.\n";
			cout << "She informs you of the Anbu who she saw enter the cave last night, but never came out.\n";
			cout << "She also mentions that the entrance to the cave may have been rigged with a trap.\n";
			cout << "You thank her and head out for the cave.\n";
			knowsTrap = true;
		}
		else if (command == "cave")
		{
			cout << "\nYou decide to head straight for the cave.\n";
		}
		else if (command == "Byakugan") 
		{
			cout << "\nYou activate your Byakugan and sense someone's chakra alone in the cave.\n";
		}
		else
		{
			cout << "\nPlease enter a valid command\n";
		}

	} while (command != "interrogate" && command != "cave");

	if (knowsTrap)
	{
		cout << "\nYou stand at the entrance to the cave.\n";
		cout << "Luckily, you spot the trap that the villagers told you about ";
		cout << "and safely make it inside.\n";
		describeBattle(name, clan, command);
		cout << "\nThe End.\n";
		return 0;
	}
	else if (knowsTrap == false)
	{
		cout << "\nAs soon as you step into the cave you hear a snapping sound!\n";
		cout << "Kunai spring out from infront of you, piercing into your chest!\n";
		cout << "You struggle to stay standing. ";
		cout << "But, the entry of the cave collapses in on you.\n";
		cout << "You died, game over.\n";
		return 0;
	}
}

int tellSenjuStory(string name, string clan)
{
	string command;
	cout << "\nYou have trained hard for this moment.\n";
	cout << "You will protect the legacy of the " + clan + " Clan!\n";
	command = askText("\nWhat would you like to do? Start your mission now, or buy ninja tools? (start or tools): ");
	do
	{
		if (command == "start")
		{
			cout << "\nYou rush off to start your mission right away.\n";
		}
		else if (command == "tools")
		{
			cout << "\nYou decide to stop and buy some ninja tools before you head out.\n";
			cout << "Why, if it isn't " + name + " of the " + clan + " Clan!";
			cout << "How can I help you today? The usual?";
			cout << "exclaims the shopkeep.\n";
			cout << "You restock on your usual ninja tools; smoke bombs, paper bombs, and some kunai.\n";
			cout << "You bid farewell to the shopkeep as you leave for your mission.\n";
		}
		else
		{
			cout << "\nPlease enter a valid command.\n";
		}

	} while (command != "start" && command != "tools");

	describeSmallVillage();
	command = askText("\nWhat will you do? (type: interrogate, to interrogate village head. type: cave, to go to the cave.) ");
	bool knowsTrap = false;
	do
	{
		if (command == "interrogate")
		{
			knowsTrap = true;
			cout << "\nYou decide to interrogate the village leader on the whereabouts of the rogue Anbu.\n";
			cout << "She informs you of the Anbu who she saw enter the cave last night, but never came out.\n";
			cout << "She also mentions that the entrance to the cave may have been rigged with a trap.\n";
			cout << "You thank her and head out for the cave.\n";
		}
		else if (command == "cave")
		{
			cout << "\nYou decide to head straight for the cave.\n";
		}
		else
		{
			cout << "\nPlease enter a valid command\n";
		}

	} while (command != "interrogate" && command != "cave");

	if (knowsTrap)
	{
		cout << "\nYou stand at the entrance to the cave.\n";
		cout << "Luckily, you spot the trap that the villagers told you about ";
		cout << "and safely make it inside.\n";
		describeBattle(name, clan, command);
		cout << "\nThe End.\n";
		return 0;
	}
	else if (knowsTrap == false)
	{
		cout << "\nAs soon as you step into the cave you hear a snapping sound!\n";
		cout << "Kunai spring out from infront of you, piercing into your chest!\n";
		cout << "You struggle to stay standing. ";
		cout << "But, the entry of the cave collapses in on you.\n";
		cout << "You died, game over.\n";
		return 0;
	}
}

// this function just describes the small village the players encounter
// it is a function because I did not want to type this for each story function
void describeSmallVillage() 
{
	cout << "\nStarting in the direction that the Inuzuka clan pointed you in, you rush off into the woods.\n";
	cout << "After a long journey you end up in a tiny village on the border of the Land of Fire.\n";
	cout << "This village has 4 buildings; ";
	cout << "an inn, a forge, another non - descript small building, and what looks to be the village official's headquaters.\n";
	cout << "You also see what seems to be a cave nestled in the mountains that is clearly visible from the village.\n";
}

// this function describes the battle and truly offers the multiple endings for each story
void describeBattle(string name, string clan, string command) 
{
	// prompt them that they finally spotted their target
	cout << "Finally, you see him.\n";
	cout << "Akio Amamiya is crouched over a small fire.";
	cout << "You notice that he is tending to some wounds on the side of his ribs.\n";
	// do loop to keep looping until proper input is recieved
	do
	{
		command = askText("What will you do? (talk, attack, Byakugan (Hyuga only), genjutsu(Uchiha Only)) "); // ask them how they wish to proceed
		if (command == "talk") // if they want to talk
		{
			// display the talk-no-jutsu ending
			cout << "\nYou approach Akio silently.\n";
			cout << "\nAkio says: So, " + name + " they sent you after me.";
			cout << "How heartless of them, to pit master against student.\n";
			cout << "Here I am, free of the Shinobi world, and yet it pulls me back in\n";
			cout << "\nYou ask: Why are you doing this?\n";
			cout << "We had a good life back in the Hidden Leaf.\n";
			cout << "You were a highly respected member of the Anbu Black Ops.\n";
			cout << "Why would you betray us?\n";
			cout << "\nAkio replies: Betray you?\n";
			cout << "I merely left the village to live a solitary life.\n";
			cout << "If anyone is being betrayed here it is me.\n";
			cout << "You ask: You don't plan to sell secrets to our enemies?\n";
			cout << "Akio answers: Why would I ever do that? I still care for the Leaf.\n";
			cout << "I am no longer able to bear the burden of a Shinobi.";
			cout << "The deaths, the losses, it has all become too much.\n";
			cout << name + ", if you could please spare me one last kindness? make it painless.\n";
			cout << "You stare at Akio for an entire minute.";
			cout << "Unsure of what to do, you sit next to him.\n";
			cout << "You say: Leave the Land of Fire, and never return.\n";
			cout << "I will tell the Leaf you are dead. Be free, Akio.\n";
			cout << "You leave the cave and return to the Leaf.\n";
			cout << "Sometimes, when staring into the firelight";
			cout << "you think of a young student you once had.\n";

		}
		else if (command == "attack") // if they want to attack
		{
			// display the attack ending
			cout << "\nQuickly and fiercely, you fling a kunai at Akio's head.\n";
			cout << "He deflects it with his tanto, and retaliates almost as fast as your eyes can see.\n";
			cout << "He makes a quick horizontal slash, that just barely misses your jonin vest.\n";
			cout << "as his blade is passing by your body, you pull out a paper bomb.\n";
			cout << "The blade is still just close enough to attach your paper bomb to it without him noticing.\n";
			cout << "You jump back in preparation for the explosion.\n";
			cout << "Akio smiles and says: Have you forgotten, Sensei?\n";
			cout << "He quickly weaves hand signs and in an instant his body is made of stone harder than bedrock.\n";
			cout << "Right before the paper bomb explodes he advances next to you.\n";
			cout << "The bomb explodes right on top of him and you.\n";
			cout << "The smoke clears, Aiko is protected by his kekkai genkai.\n";
			cout << "He kneels over your incinerated corpse, lamenting that it came to this.\n";
		}
		else if (command == "genjutsu") // if they want to use genjutsu
		{
			if (clan == "Uchiha") // and if they are an Uchiha
			{
				// give them the genjutsu ending (for Uchihas only)
				cout << "\nYou approach Akio silently.\n";
				cout << "Akio, you say, and he looks up at you in disbelief that you are here.\n";
				cout << "He makes the unfortunate mistake of making eye contact with you.\n";
				cout << "Akio becomes motionless, stuck with a look of disbelief upon his face.\n";
				cout << "You sit next to him, his body still frozen as he is trapped inside your genjutsu.\n";
				cout << "You hesitate, a master should not have to kill their former student.\n";
				cout << "Yet, you have no choice, you must protect The Leaf.\n";
				cout << "Kunai in hand, you whisper your farewells to your former student.\n";
				cout << "You close your eyes as you slice his throat.\n";
				cout << "Akio slumps to the ground.";
				cout << " You scream as you open your eyes.\n";
				cout << "The pattern inside your eyes change and, from the trauma of this conflict, your Mangekyo Sharingan awakens.\n";
			}
			else // otherwise
			{
				// tell them they are not an Uchiha and cannot use genjutsu
				cout << "\nYou cannot use genjutsu.\n";
				// they die, a ninja must know their abilities
				cout << "Akio takes this opprotunity to stab you through the ehart with his Tanto.\n";
			}
		}
		else if (command == "Byakugon") // otherwise if they want to use their Byakugon
		{
			if (clan == "Hyuga") // and if they are a Hyuga
			{
				// display the Byakugon ending
				cout << "Byakugan! You yell as you activate your clan's dojutsu.\n";
				cout << "You can see Akio's chakra through the dark of the cave clearly.\n";
				cout << "His chakra is slightly weaker than usual.";
				cout << "Probably a result from the wound on his ribs.\n";
				cout << "Silently you approach him.\n";
				cout << "Without making a sound you strike his chakra points faster than a normal human eye can see.\n";
				cout << "Akio falls over, completely disconnected from his chakra network.\n";
				cout << "Before he can say anything he loses conciousness.\n";
				cout << "You decide to take him back to The Leaf so that the Hokage can decide his fate.\n";
			}
			else // otherwise
			{
				// inform them they do not have a Byakugon
				cout << "\nYou do not have a Byakugon.\n";
				// they die, a ninja must know their abilities
				cout << "Akio takes this opprotunity to stab you through the ehart with his Tanto.\n";
			}
		}
		else if (command == "ninjutsu") // otherwise if they want to use ninjutsu
		{
			// display the ninjutsu ending
			cout << "From the entrance of the cave you cast your ninjutsu.\n";
			cout << "Lightning envelopes your hand, you leap forward, and in an instant you are on top of Akio.\n";
			cout << "Your hand, wrapped in lightning chakra, pierces his chest and subsequently, his heart.\n";
			cout << "You sit there in silence, pondering the cruel Shinobi world that brought a master to kill their former student.\n";
		}
		else //otherwise
		{
			// prompt them to give valid input
			cout << "\nPlease enter a valid command.\n";
		}
		// the do loop will continue to loop until a valid command is given
	} while (command != "talk" && command != "attack" && command != "genjutsu" && command != "Byakugan" && command != "ninjutsu");
}