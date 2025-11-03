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

// decreaseFriendship() decrements the specified villager's friendship score by
// arguments: a string value representing the specified villager's name, a map containing the villager's data
// returns: nothing
void decreaseFriendship(string, map<string, tuple<int, string, string> >);

// increaseFriendship() increments the specified villager's friendship score by one
// arguments: a string value representing the specified villager's name, a map containing the villager's data
// returns: nothing
void increaseFriendship(string, map<string, tuple<int, string, string> >);

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

	// search for an element using .find() to avoid errors
	string searchKey = "Audie";
	auto it = villagers.find(searchKey);
	if (it != villagers.end()) {
		// the iterator points to beyond the end of the map
		// if searchKey is not found
		cout << "\nFound " << searchKey << "'s friendship score, species, and catchphrase: ";
		cout << get<0>(it->second) << '\t' << get<1>(it->second) << '\t' << get<2>(it->second);
		cout << endl;
	} else
		cout << endl << searchKey << " not found." << endl;

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
