#include <vector>
#include <string>
#include <regex>
#include <iostream>

typedef std::vector<std::string> words;

int main (int argc, char * argv [])
{
  words interesting;
  interesting.push_back ("Serendipity");
  interesting.push_back ("Defenestrate");
  interesting.push_back ("Pneumonoultramicroscopicsilicovolcanoconiosis");
  interesting.push_back ("Serendipitously Defenestrated");

  auto const regexFlags = std::regex::icase | std::regex::ECMAScript;

  std::smatch matched;

  if (argc > 1) {
    std::regex expr (argv[1], regexFlags);

    for (const auto& word : interesting) {
      std::cout << word << " : " 
        << std::boolalpha << std::regex_match(word, matched, expr) 
        << std::endl;
    }

    std::cout << std::endl;

    for (uint i = 0; i < interesting.size(); i++) {
      auto listBegins = 
        std::sregex_iterator (
          interesting[i].begin(), 
          interesting[i].end(), 
          expr
        );
      auto listEnds = 
        std::sregex_iterator ();

      for (auto word = listBegins; word != listEnds; word++) {
        std::cout << (*word).str() << std::endl;
      } // End of "word"
    } // End of "interesting"

  } // End of "if argc > 1"

  return 0;
}