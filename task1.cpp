#include <iostream>
#include <string>
#include <unordered_set>
#include <cstdlib>
#include <ctime>

using namespace std;

/**
    This function accepts two references to "std::string" objects and returns 
    new "std::string" object, which contains the unique characters from first
    and second strings. To implement an algorithm "unordered_set" 
    data structure was used. This data structure uses "hash table" to store elements.

    Time complexity of the algorithm: O(n) - where "n" is common length of "s1" and "s2" objects.

    ---------------------------------------------------------------
    Time complexity of the algorithm: O(n)
 */
string intersection_strings_by_set(string const& s1, string const& s2) {

    // This object will store the result string
    string res_str("");
    
    // This object will store the unique characters
    unordered_set<char> set_str = {};

    // Get sizes of strings
    const size_t SIZE_S1 = s1.size();
    const size_t SIZE_S2 = s2.size();

    // Add all the characters from "s1" to the set
    for (size_t i = 0; i < SIZE_S1; i++)
        set_str.insert(s1[i]);

    // Add all the characters from "s2" to the set
    for (size_t i = 0; i < SIZE_S2; i++)
        set_str.insert(s2[i]);

    // Reserve size to store result string
    res_str.reserve(set_str.size());

    // Copy all elements from "set" to "string" object 
    for (auto it = set_str.begin(); it != set_str.end(); ++it)
        res_str += *it;
    
    // Return result string
    return res_str;
}

/**
    This function accepts two references to "std::string" objects and returns
    new "std::string" object, which contains the unique characters from first
    and second strings. Each character is compared with the ones that already added
    
    Time complexity of the algorithm: O(n^2) - where "n" is common length of "s1" and "s2" objects.
    Despite the quadratic time complexity, this algorithm can be more effective in a number of cases.
    Moreover, this algorithm does not require additional memory for storing the set.
    
    ---------------------------------------------------------------
    Time complexity of the algorithm: O(n^2)
*/
string intersection_strings_by_loops(string const& s1, string const& s2) {
    
    // This object will store the result string
    string res_str("");
    
    // Get sizes of strings
    const size_t SIZE_S1 = s1.size();
    const size_t SIZE_S2 = s2.size();

    // Reserve size to store result string
    res_str.reserve(SIZE_S1 + SIZE_S2);

    // Add characters from first string to result string
    for (size_t i = 0; i < SIZE_S1; i++) {
        bool haveChar = false;
        for (size_t j = 0; j < res_str.size(); j++) {
            if (s1[i] == res_str[j]) {
                haveChar = true;
                break;
            }
        }

        if (!haveChar) {
            res_str += s1[i];
        }
    }

    // Add characters from second string to result string
    for (size_t i = 0; i < SIZE_S2; i++) {
        bool haveChar = false;
        for (size_t j = 0; j < res_str.size(); j++) {
            if (s2[i] == res_str[j]) {
                haveChar = true;
                break;
            }
        }

        if (!haveChar) {
            res_str += s2[i];
        }
    }

    // Return result string
    return res_str;
}

/**
    This function generates tests
*/
string test1(size_t n) {
    const size_t ALPHABET_SIZE = 14;
    string s("");
    s.reserve(n);
    for (size_t i = 0; i < n; i++) {
        s += (rand() % ALPHABET_SIZE + 10);
    }

    return s;
}

/**
    Entry point
*/
int main() {
    const size_t N = 10000;

    srand(clock());

    string s1 = test1(N);
    string s2 = test1(N);

    // Test 1
    int cloc = clock();
    string s3 = intersection_strings_by_set(s1, s2);
    cout << "Set: " << (clock() - cloc) << endl;

    // Test 2
    cloc = clock();
    string s4 = intersection_strings_by_loops(s1, s2);
    cout << "Loops: " << (clock() - cloc) << endl;

    system("pause");
    return 0;
}