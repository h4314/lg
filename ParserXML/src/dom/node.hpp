/**
 * == Analyseur XML simplifié ==
 * @authors Hexanome 4314
 */

#ifndef XML_NODE_H
#define XML_NODE_H

#include <vector>

namespace xml {

class Node;
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
    Node();
};

}

#endif

