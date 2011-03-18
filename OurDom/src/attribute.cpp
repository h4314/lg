/**
 * == Analyseur XML simplifié ==
 * @authors Hexanome 4314
 */

#include "attribute.hpp"

using namespace std;

namespace xml {

Attribute::Attribute() {
  public:

	Attribute() {};

	Attribute(string name, string value)
	{
		_name = name;
		_value = value;
	}
  protected:

  private:

}

}

