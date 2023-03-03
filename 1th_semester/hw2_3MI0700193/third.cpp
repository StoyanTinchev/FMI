#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<string> fillVector(string names) {
	vector<string> vector;
	string name;
	for (int I = 0; I <= names.size(); ++I) {
		if (names[I] == ' ' || names[I] == '\n' || I == names.size()) {
			vector.push_back(name);
		} else {
			name = name + names[I];
		}
	}
	return vector;
}

int main() {

	string inputProperName;
	cin >> inputProperName;

	string inputSurnames;
	cin >> inputSurnames;

	vector<string> properNames = fillVector(inputProperName);
	vector<string> surnames = fillVector(inputSurnames);

	vector<string> result;
	for (int I = 0; I < properNames.capacity(); ++I) {
		result.push_back(properNames.at(I));
		result.push_back(surnames.at(I));
	}

	for (const auto &Item : result) {
		cout << Item << " ";
	}
	cout << endl;
	return 0;
}