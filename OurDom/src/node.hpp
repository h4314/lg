/**
 * == Analyseur XML simplifié ==
 * @authors Hexanome 4314
 */

#ifndef XML_NODE_H
#define XML_NODE_H

#include <vector>

namespace xml {

/**
 * @brief Représente une liste de pointeurs sur des noeuds
 */
typedef NodeList std::vector<Node*>;

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

