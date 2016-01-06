#include <string>
#include <cstring>
#include <cstdlib>
#include <iostream>

std::string caesarCipher (std::string str, const int& shift);

int main (int argc, char * argv[])
{
  /* g fmnc wms bgblr rpylqjyrc gr zw fylb. 
  rfyrq ufyr amknsrcpq ypc dmp. 
  bmgle gr gl zw fylb gq glcddgagclr ylb rfyr'q ufw rfgq rcvr gq qm jmle. 
  sqgle qrpgle.kyicrpylq() gq pcamkkclbcb. 
  lmu ynnjw ml rfc spj.*/
    
  argc > 2 
  ?
    std::cout << caesarCipher (argv[1], atoi(argv[2])) << std::endl
  :
    std::cout << 
      "Usage is <prog> \"<phrase>\" <shifts>.\n"
      "If <shifts> is positive, <prog> encodes.\n"
      "If <shifts> is negative, <prog> decodes."
    << std::endl;

  return 0;
}

std::string caesarCipher (std::string str, const int& shift) {
  std::string dcode = "";
  char temp;

  for (int i = 0; i < str.length(); i++) {
    if ((int)str[i] >= 97 && (int)str[i] <= 122) {
      temp = tolower(str[i]) - 97;
      temp = (temp+shift)%26;
      temp += 97;
      dcode += temp;
    }
    else
      dcode += (char)str[i];      
  }

  return dcode;
}