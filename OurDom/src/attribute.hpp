/**
 * == Analyseur XML simplifié ==
 * @authors Hexanome 4314
 */

#ifndef XML_ATTRIBUTE_H
#define XML_ATTRIBUTE_H

#include <vector>
#include <string>

namespace xml {

typedef AttributeList vector<Attribute&>;

/**
 * @brief La classe représente un attribut d'un élement xml dans un fichier xml ou dans un DTD
 */
class Attribute
{
	public:
	/**
	 * @brief Le constructeur par défaut de la classe Attribute
	 */
	Attribute();

	/**
	 * @brief Le constructeur de la classe Attribute
	 * @param name le nom de l'attribut
	 * @param value la valeur de l'attribut dans un xml ou la valeur par défaut dans un DTD
	 */
	Attribute(std::string name, std::string value);
	protected:

	private:
	std::string _name;
	std::string _value;
};

}
#endif

