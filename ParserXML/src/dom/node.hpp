/**
 * == Analyseur XML simplifié ==
 * @authors Hexanome 4314
 */

#ifndef XML_NODE_H
#define XML_NODE_H

#include <vector>

namespace xml {

class Node;
class Element;
/**
 * @brief Représente une liste de pointeurs sur des noeuds
 */
typedef std::vector<Node*> NodeList ;

/**
 * @brief Représente un noeud dans le modèle objet du document XML.
 * Un noeud est un type abstrait.
 */
class Node
{
  public:
    Node(Element* parent);
		Element* parent();
    virtual void display();
	protected:
		Element* parent_;
};

}

#endif

