#include <string>
#include <cstring>
#include <vector>
#include <iostream>
#include <sstream>
#include <algorithm>
#include <unordered_map>
#include <utility>

using namespace std;

void print_pairs(vector <pair<int, string>> v)
{
    for (const auto& pair : v)
        cout << pair.first << " " << pair.second << endl;
}

vector <pair<int, string>> sort_by_frequency(vector <pair<int, string>> v)
{
    sort(begin(v), end(v), [](pair<int, string> p1, pair<int, string> p2){ return p1.first > p2.first; });
    
    return v;
}

vector <pair<int, string>> reverse_pairs(unordered_map<string, int> pairs)
{
    vector <pair<int, string>> r;
    
    for (auto& pair : pairs)
    {
        std::pair<int, string> p(pair.second, pair.first);
        r.push_back(p);
    }
    
    return r;
}

unordered_map<string, int> count_occurences(vector<string> names)
{
    unordered_map<string, int> m;
    
    for (const auto& word : names)
    {
        m[word]++;
    }
    
    return m;
}

// Use transform and a for-loop
vector<string> words(string text)
{
    vector<string> sv;
    
    transform(cbegin(text), cend(text), begin(text), [](char c){
        if (isalnum(c)) { return c;  }
        else { return ' '; }
    });
    
    istringstream iss(text);
    
    for (string word; iss >> word; )
        sv.push_back(word);
    
    return sv;
}


void print_common_words(string text)
{
    vector<string> w = words(text);
    unordered_map<string, int> m = count_occurences(w);
    vector<pair<int, string>> r = reverse_pairs(m);
    vector<pair<int, string>> s = sort_by_frequency(r);
    print_pairs(s);
}

int main()
{
    print_common_words("The The The CS30 class is awesome!a.a.");
                       
    return 0;
}
