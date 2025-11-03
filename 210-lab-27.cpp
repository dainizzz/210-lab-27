// COMSC-210 | Lab 27 | Dainiz Almazan
// IDE used: CLion

#include <iostream>
#include <limits>
#include <map>
#include <tuple>
using namespace std;

// displayMenu() outputs a menu and reads and returns the user's selection from the menu
// arguments: none
// returns: an int value representing the user's menu selection
int displayMenu();

// addVillager() prompts the user for villager data, then adds that villager to the map of villagers
// arguments: a map containing villager data
// returns: nothing
void addVillager(map<string, tuple<int, string, string> > &);

// deleteVillager() prompts the user for a villager's name, then deletes that villager from the map of villagers
// arguments: a map containing villager data
// returns: nothing
void deleteVillager(map<string, tuple<int, string, string> > &);

// decreaseFriendship() prompts the user for a villager's name, then decrements the villager's friendship score by 1.
// arguments: a map containing villager data
// returns: nothing
void decreaseFriendship(map<string, tuple<int, string, string> > &);

// increaseFriendship() prompts the user for a villager's name, then increments the villager's friendship score by 1.
// arguments: a map containing villagers data
// returns: nothing
void increaseFriendship(map<string, tuple<int, string, string> > &);

// searchForVillager() prompts the user for a villager's name, then searches the map for that villager. It outputs the
// villager's data if the villager is found, or a statement saying the villager was not found if they weren't found.
// arguments: a map containing villagers data
// returns: nothing
void searchForVillager(const map<string, tuple<int, string, string> > &);

// displayVillagerData() outputs the data for each of the villagers in the map
// arguments: a map with villager data
// returns: nothing
void displayVillagerData(const map<string, tuple<int, string, string> > &);

int main() {
	// declarations
	map<string, tuple<int, string, string> > villagers;
	int choice;
	string villager;

	// Adding starting villagers
	villagers["Audie"] = {5, "Wolf", "Foxtrot"};
	villagers["Raymond"] = {3, "Cat", "Crisp"};
	villagers.insert({"Marshal", {0, "Squirrel", "Sulky"}});

	bool again = true;
	while (again) {
		choice = displayMenu();
		switch (choice) {
			case 1:
				addVillager(villagers);
				displayVillagerData(villagers);
				break;
			case 2:
				deleteVillager(villagers);
				displayVillagerData(villagers);
				break;
			case 3:
				increaseFriendship(villagers);
				displayVillagerData(villagers);
				break;
			case 4:
				decreaseFriendship(villagers);
				displayVillagerData(villagers);
				break;
			case 5:
				searchForVillager(villagers);
				displayVillagerData(villagers);
				break;
			case 6:
				again = false;
				break;
			default:
				break; // Invalid choices should already be caught in displayMenu();
		}
	}

	return 0;
}

int displayMenu() {
	int choice;
	cout << "1. Add Villager" << endl;
	cout << "2. Delete Villager" << endl;
	cout << "3. Increase Friendship" << endl;
	cout << "4. Decrease Friendship" << endl;
	cout << "5. Search for Villager" << endl;
	cout << "6. Exit" << endl;
	cout << "Enter choice: ";
	while (!(cin >> choice) || choice < 1 || choice > 6) {
		cout << "Invalid choice. Please enter a number 1-6 as your choice:" << endl;
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
	}
	return choice;
}

void addVillager(map<string, tuple<int, string, string>> &villagers) {
	string name, species, catchphrase;
	int friendship;
	cout << "Villager name: ";
	cin >> name;
	cout << "Friendship level: ";
	cin >> friendship;
	cout << "Species: ";
	cin >> species;
	cout << "Catchphrase: ";
	cin.ignore();
	getline(cin,catchphrase);

	villagers.insert({name, {friendship, species, catchphrase}});

	cout << name << " added.";
}

void deleteVillager(map<string, tuple<int, string, string>> & villagers) {
	string villager;
	cout << "Which villager do you want to delete?" << endl;
	cin >> villager;
	auto it = villagers.find(villager);
	if (it != villagers.end()) {
		villagers.erase(it);
	}
}

void decreaseFriendship(map<string, tuple<int, string, string> > &villagers) {
	string villager;
	cout << "Who do you want to decrease friendship with?" << endl;
	cin >> villager;
	auto it = villagers.find(villager);
	if (it != villagers.end() && get<0>(it->second) > 0)
		get<0>(it->second)--;
}

void increaseFriendship(map<string, tuple<int, string, string> > &villagers) {
	string villager;
	cout << "Who do you want to increase friendship with?" << endl;
	cin >> villager;
	auto it = villagers.find(villager);
	if (it != villagers.end() && get<0>(it->second) < 10)
		get<0>(it->second)++;
}

void searchForVillager(const map<string, tuple<int, string, string> > &villagers) {
	string villager;
	cout << "Which villager are you searching for?" << endl;
	cin >> villager;
	auto it = villagers.find(villager);
	if (it != villagers.end()) {
		cout << "\nFound " << villager << "'s friendship score, species, and catchphrase: ";
		cout << get<0>(it->second) << ", " << get<1>(it->second) << ", " << get<2>(it->second);
		cout << endl;
	} else
		cout << endl << villager << " not found." << endl;
}

void displayVillagerData(const map<string, tuple<int, string, string> > &villagers) {
	cout << "Villager details:" << endl;
	for (auto pair: villagers) {
		cout << pair.first << " [" << get<0>(pair.second) << ", " << get<1>(pair.second) << ", " << get<2>(pair.second)
				<< "]" << endl;
	}
}
