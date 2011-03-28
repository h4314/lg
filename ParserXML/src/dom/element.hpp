/**
 * == Analyseur XML simplifié ==
 * @authors Hexanome 4314
 */

#ifndef XML_ELEMENT_H
#define XML_ELEMENT_H

#include "node.hpp"
#include "attribute.hpp"

#include <utility>
#include <string>

namespace xml
{

/**
 * @brief La classe représente un élément dans un xml ou dans un DTD
 */
class Element: public Node
{
  public:
    /**
     * @brief Le constructeur
     * @param Le nom de l'élément
     */
    Element(Element* parent, const std::string& name);

    /**
     * @brief La fonction pour ajouter un noeud fils à l'élément
     * @param newChild Le noeud fils à ajouter
     * @return le nombre de noeud fils dans l'élement
     */
    int appendChild(Node* newChild);

    /**
     * @brief La fonction pour ajouter un nouvel attribut à l'élement
     * @param newAttribute L'attribut à ajouter
     * @return Le nombre d'attributs dans l'élement
     */
    int addAttribute(Attribute* newAttribute);

    inline const std::string& name() const
    {
      return _name;
    }

    /**
     * @brief Retourne la liste des noeuds fils
     * @return liste des noeuds fils
     */
    inline const NodeList& children() const {
      return _children;
    }

    /**
     * @brief Retourne la liste des attributs de l'élément
     * @return liste des attributs de l'élément
     */
    inline const AttributeList& attributes() const {
      return _attributes;
    }

    virtual void display();

  private:
    /** le nom de l'élement */
    std::string _name;

    /** Les noeuds fils de l'élement */
    NodeList _children;

    /** Les attributs de l'élement */
    AttributeList _attributes;
};

}

#endif

