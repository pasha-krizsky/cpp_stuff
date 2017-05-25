#include <iostream>
#include <string>
#include <unordered_set>
#include <cstdlib>

using namespace std;

/**
    Time complexity of the algorithm: O(n)
*/
string find_unique(const string& s1, const string& s2) {
	string res("");
	unordered_set<char> unique_set1;
	unordered_set<char> unique_set2;

	const size_t SIZE_S1 = s1.size();
	const size_t SIZE_S2 = s2.size();
	size_t i = 0;

	for (i = 0; i < SIZE_S1; ++i)
		unique_set1.insert(s1[i]);

	for (i = 0; i < SIZE_S2; ++i)
		unique_set2.insert(s2[i]);

	for (auto it = unique_set1.begin(); it != unique_set1.end(); ++it)
		// Average case: constant.
		// Worst case: linear in container size.
		if (unique_set2.count(*it)) 
			res += *it;
	
	return res;
}

int main() {

	string s1;
	string s2;

	cin >> s1 >> s2;
	cout << find_unique(s1, s2) << endl;

	system("pause");
	return 0;
}