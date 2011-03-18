/**
 * == Analyseur XML simplifié ==
 * @authors Hexanome 4314
 */

#include "element.hpp"

using namespace std;

namespace xml {

Element::Element() : Node() {
public:

    Element() {};
    
    Element(string name) 
    {
    	_name = name;
    }
    
    int AppendChild(Node& newChild) 
    {
    	_children.push_back(newChild);
    }

    int AddAttribute(Attribute& newAttribute)
    {
    	_attributes.push_back(newAttribute);
    }

  protected:
    
  private:
}

}

