/**
 * == Analyseur XML simplifié ==
 * @authors Hexanome 4314
 */

#ifndef XML_ATTRIBUTE_H
#define XML_ATTRIBUTE_H

#include <vector>
#include <string>

namespace xml {

class Attribute;

typedef std::vector<Attribute*> AttributeList;

/**
 * @brief La classe représente un attribut d'un élement xml dans un fichier xml
 * ou dans un DTD
 */
class Attribute
{
	public:
	/**
	 * @brief Le constructeur de la classe Attribute
	 * @param name le nom de l'attribut
   * @param value la valeur de l'attribut dans un xml ou la valeur par défaut
   * dans un DTD
	 */
	Attribute(std::string name = "", std::string value = "");

  /**
   * @brief donne le nom de l'attrbut
   */
  inline const std::string& name() const {
    return _name;
  }

  /**
   * @brief identifie le nom de l'attrbut
   */
  void setName(std::string name);

  /**
   * @brief donne la valeur de l'attrbut
   */
  inline const std::string& value() const {
    return _value;
  }

  /**
   * @brief identifie la valeur de l'attribut
   */
  void setValue(std::string name);

  void display();

	private:
  /** Nom de l'attribut */
	std::string _name;
  /** Valuer de l'attrbut */
	std::string _value;
};

}
#endif

