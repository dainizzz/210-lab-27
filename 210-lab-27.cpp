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

// decreaseFriendship() decrements the specified villager's friendship score by 1.
// arguments: a string value representing the specified villager's name, a map containing the villager's data
// returns: nothing
void decreaseFriendship(string, map<string, tuple<int, string, string> >);

// increaseFriendship() increments the specified villager's friendship score by 1.
// arguments: a string value representing the specified villager's name, a map containing the villager's data
// returns: nothing
void increaseFriendship(string, map<string, tuple<int, string, string> >);

// searchForVillager() searches the map for the specified villager. It outputs the villager's data if the villager is
//		found, or a statement saying the villager was not found if they weren't found.
// arguments: a string value representing the specified villager's name, a map containing the villager's data
// returns: nothing
void searchForVillager(string, map<string, tuple<int, string, string> >);

// displayVillagerData() outputs the data for each of the villagers in the map
// arguments: a map with villager data
// returns: nothing
void displayVillagerData(map<string,const tuple<int, string, string> >);

int main() {
	// declarations
	map<string, tuple<int, string, string> > villagers;

	// insert elements into the map
	// note how the right-hand side of the assignment are the vector elements
	villagers["Audie"] = {0, "Wolf", "Foxtrot"};
	villagers["Raymond"] = {0, "Cat", "Crisp"};
	villagers.insert({"Marshal", {0, "Squirrel", "Sulky"}});

	// access the map using a range-based for loop
	cout << "Villagers, their friendship scores, their species, and their catchphrases (range-based for loop):" << endl;
	for (auto pair: villagers) {
		cout << pair.first << ": ";
		cout << get<0>(pair.second) << '\t' << get<1>(pair.second) << '\t' << get<2>(pair.second);
		cout << endl;
	}

	// access the map using iterators
	cout << "\nVillagers, their friendship scores, their species, and their catchphrases (iterators):" << endl;
	for (map<string, tuple<int, string, string> >::iterator it = villagers.begin();
	     it != villagers.end(); ++it) {
		cout << it->first << ": ";
		cout << get<0>(it->second) << '\t' << get<1>(it->second) << '\t' << get<2>(it->second);
		cout << endl;
	}

	// delete an element
	villagers.erase("Raymond");

	// report size, clear, report size again to confirm map operations
	cout << "\nSize before clear: " << villagers.size() << endl;
	villagers.clear();
	cout << "Size after clear: " << villagers.size() << endl;

	return 0;
}

int displayMenu() {
	int choice;
	cout << "1. Increase Friendship" << endl;
	cout << "2. Decrease Friendship" << endl;
	cout << "3. Search for Villager" << endl;
	cout << "4. Exit" << endl;
	while (!(cin >> choice) || choice < 1 || choice > 4) {
		cout << "Invalid choice. Please enter a number 1-4 as your choice:" << endl;
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
	}
	return choice;
}

void decreaseFriendship(string villager, map<string, tuple<int, string, string>> villagers) {
	auto it = villagers.find(villager);
	if (it != villagers.end())
		get<0>(it->second)--;
}

void increaseFriendship(string villager, map<string, tuple<int, string, string>> villagers) {
		auto it = villagers.find(villager);
		if (it != villagers.end())
			get<0>(it->second)++;
}

void searchForVillager(string villager, const map<string, tuple<int, string, string>> villagers){
	auto it = villagers.find(villager);
	if (it != villagers.end()) {
		// the iterator points to beyond the end of the map
		// if searchKey is not found
		cout << "\nFound " << villager << "'s friendship score, species, and catchphrase: ";
		cout << get<0>(it->second) << '\t' << get<1>(it->second) << '\t' << get<2>(it->second);
		cout << endl;
	} else
		cout << endl << villager << " not found." << endl;
}

void displayVillagerData(map<string, tuple<int, string, string>> villagers) {

}
