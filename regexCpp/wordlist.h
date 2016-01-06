#include <string>
#include <vector>
#include <regex>
#include <unordered_map>

typedef std::string word;
typedef std::vector<word> words;
typedef word category;

class wordlist
{
  words list;

  public:
  int size() const;
  bool empty() const;
  void push_back();
  void erase();
  void clear();

  wordslist& operator= (const wordlist& rhs);
};

class wordlists
{
  std::unordered_map <category, wordlist> map;
  
  public:
  int size() const;
  bool empty() const;
  word add (const category*, const word*);
  word remove (const category*, const word*);
  wordlist get (const category*);

  wordlist& operator[] (const category*);
};

ostream& wordlist::operator<< (const wordlist&) const;
