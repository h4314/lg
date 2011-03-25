/**
 * == Analyseur XML simplifié ==
 * @authors Hexanome 4314
 */

#ifndef XML_DOCTYPE_H
#define XML_DOCTYPE_H

#include <map>
#include <string>

#include "dtd_element.hpp"

namespace xml {

typedef std::map<std::string, DtdElement*> DtdElementList;
/**
 * @brief La classe représente le doctype d'un DTD
 */
class Doctype
{
  public:
    /**
     * @brief Le constructeur
     * @param name Le nom du doctype
     */
    Doctype(const std::string& name);
    /**
     * @brief Destructeur
     */
    ~Doctype();

    /**
     * @brief donne le nom du doctype
     */
    inline std::string& name() {
      return _name;
    }

    /**
     * @brief Retourne l'élément correspondant dans la DTD, le créé si il
     * n'existe pas.
     * @param eltname Nom de l'élément
     */
    DtdElement* element(std::string eltname);
    DtdElement* element(const char* eltname);

  private:
    /** Nom du doctype */
    std::string _name;

    /** Liste des éléments définis dans la DTD */
    DtdElementList _elements;
};

}

#endif

