#include "../OurDom/src/dom.hpp"

int main(int argc, char **argv)
{	
  Document doc(std::cin);
  doc.parse();



  return 0;
}
