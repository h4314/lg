/**
 * == Analyseur XML simplifié ==
 * @authors Hexanome 4314
 */

#include "attribute.hpp"

using namespace std;

namespace xml {

Attribute::Attribute() {

	Attribute() {};

	Attribute(std::string name, std::string value)
	{
		_name = name;
		_value = value;
	}

}

}

