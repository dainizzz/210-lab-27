// COMSC-210 | Lab 27 | Dainiz Almazan
// IDE used: CLion

#include <iostream>
#include <map>
#include <tuple>
using namespace std;

int main() {
    // declarations
    map<string, tuple<int, string, string>> villagers;

    // insert elements into the map
    // note how the right-hand side of the assignment are the vector elements
    villagers["Audie"] = {0, "Wolf", "Foxtrot"};
    villagers["Raymond"] = {0, "Cat", "Crisp"};
    villagers.insert({"Marshal", {0, "Squirrel", "Sulky"}});

    // access the map using a range-based for loop
    cout << "Villagers, their friendship scores, their species, and their catchphrases (range-based for loop):" << endl;
    for (auto pair : villagers) {
        cout << pair.first << ": ";
        cout << get<0>(pair.second) <<'\t' << get<1>(pair.second) << '\t' << get<2>(pair.second);
        cout << endl;
    }

    // access the map using iterators
    cout << "\nVillagers, their friendship scores, their species, and their catchphrases (iterators):" << endl;
    for (map<string, tuple<int, string, string>>::iterator it = villagers.begin();
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
    if (it != villagers.end()) {  // the iterator points to beyond the end of the map
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