/**
 * == Analyseur XML simplifié ==
 * @authors Hexanome 4314
 */

#ifndef XML_DTD_ELEMENT_H
#define XML_DTD_ELEMENT_H

#include <set>
#include <string>

#include "element.hpp"
#include "attribute.hpp"

namespace xml {

class DtdValidator;

typedef std::set<std::string> DtdAttributeList;
/**
 * @brief DtdElement représente la déclaration d'un élément XML dans une DTD.
 */
class DtdElement
{
  public:
    /**
     * @brief Le constructeur
     * @param name Nom de l'élément
     */
    DtdElement(std::string& name);

    /**
     * @brief Définit l'objet permettant de valider le noeud Xml.
     * @param validateur l'objet validateur
     */
    void setValidator(DtdValidator* validator);

    /**
     * @brief Ajoute un attribut autorisé pour l'élément XML.
     * @param attrname Nom de l'attribut
     */
    void addAttribute(std::string& attrname);

    /**
     * @brief Valide un élément XML d'après sa définition dans la DTD
     * @param elt L'élément à valider dans l'arbre XML
     */
    bool valid(Element* elt);

  private:
    /** Nom de l'élément */
    std::string _name;
    /** Validateur de noeud */
    DtdValidator* _validator;

    /** Liste d'attributs autorisés pour l'élément */
    DtdAttributeList _attributes;
};

}

#endif

