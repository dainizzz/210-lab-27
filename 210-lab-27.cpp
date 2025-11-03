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
        cout << '\t' <<  get<0>(pair.second) << endl;
        cout << '\t' << get<1>(pair.second) << endl;
        cout << '\t' << get<2>(pair.second) << endl;
        cout << endl;
    }

    // access the map using iterators
    cout << "\nVillagers and their favorite colors (iterators):" << endl;
    for (map<string, tuple<int, string, string>>::iterator it = villagers.begin();
                                               it != villagers.end(); ++it) {
        cout << it->first << ": ";
        for (auto color : it->second) {
            cout << color << " ";
        }
        cout << endl;
    }

    // delete an element
    villagers.erase("Raymond");

    // search for an element using .find() to avoid errors
    string searchKey = "Audie";
    auto it = villagers.find(searchKey);
    if (it != villagers.end()) {  // the iterator points to beyond the end of the map
                                       // if searchKey is not found
        cout << "\nFound " << searchKey << "'s favorite colors: ";
        for (auto color : it->second)  // range loop to traverse the value/vector
            cout << color << " ";
        cout << endl;
    } else
        cout << endl << searchKey << " not found." << endl;

    // report size, clear, report size again to confirm map operations
    cout << "\nSize before clear: " << villagers.size() << endl;
    villagers.clear();
    cout << "Size after clear: " << villagers.size() << endl;

    return 0;
}