#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;
using namespace std::placeholders;

string make_plural(size_t ctr, const string &word, 
                               const string &ending)
{
	return (ctr > 1) ? word + ending : word;
}

inline void output_words(const vector<string> & words)
{
    for (auto it = words.begin(); it != words.end(); ++it)
        cout << *it << " ";
    cout << endl;
}

void elimDups(vector<string> &words)
{
    sort(words.begin(), words.end());
    auto end_unique = unique(words.begin(), words.end());
    words.erase(end_unique, words.end());
}

bool check_size(const string &s, string::size_type sz)
{
    return s.size() >= sz;
}

void biggies(vector<string> &words, vector<string>::size_type sz)
{
    elimDups(words);

    for_each(words.begin(), words.end(),
        [](const string &a)
        {cout << a << " ";});
    cout << endl;
    auto wc = partition(words.begin(), words.end(),
        bind(check_size, _1, sz));
    auto count = wc - words.begin() ;
    cout << count << " " << make_plural(count, "word", "s") << " of length "
        << sz << " or longer" << endl;
    
    for_each(words.begin(), wc,
        [](const string &a)
        {cout << a << " ";});
    cout << endl;
}

int main(int argc, char const *argv[])
{
    vector<string> words = {"the", "quick", "red", "fox", "jumps", "over", "the", "slow", "red", "turtle"};
    biggies(words, 4);
    return 0;
}
