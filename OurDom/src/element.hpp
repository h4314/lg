/**
 * == Analyseur XML simplifié ==
 * @authors Hexanome 4314
 */

#ifndef XML_ELEMENT_H
#define XML_ELEMENT_H

#include "node.hpp"
#include "attribute.hpp"

#include <vector>
#include <utility>
#include <string>

namespace xml {

/** La cardinalité d'un noeud fils est défini par une paire d'entiers 
 *  contenant le nombre min et max possible dans l'élement
 */
typedef Cardinality pair<int, int>;

/** La liste pour stocker le nom d'un noeud fils et sa cardinalité */ 
typedef CardinalityList map<string, Cardinality>;

/**
 * @brief La classe représente un élément dans un xml ou dans un DTD
 */
class Element: public Node
{
  public:
	/**
	 * @brief Le constructeur par défaut
	 */
    Element();
    
    /**
     * @brief Le constructeur
     * @param Le nom de l'élément
     */
    Element(string name);
    
    /**
     * @brief La fonction pour ajouter un noeud fils à l'élément
     * @param newChild Le noeud fils à ajouter
     * @return le nombre de noeud fils dans l'élement
     */
    int AppendChild(Node& newChild);
    
    /**
     * @brief La fonction pour ajouter un nouvel attribut à l'élement
     * @param newAttribute L'attribut à ajouter
     * @return Le nombre d'attributs dans l'élement
     */
    int AddAttribute(Attribute& newAttribute);

  protected:
    
  private:
    /** le nom de l'élement */
    std::string _name;
    
    /** Les noeuds fils de l'élement */
    NodeList _children;
    
    /** Les attributs de l'élement */
    AttributeList _attributes;
    
    /** Les cardinalités des éléments fils dans un DTD
     *  Cet attribut n'est pas utile dans un fichier xml et sera mis à null
     */
    CardinalityList _cardinalityChildren;
};

}

#endif

