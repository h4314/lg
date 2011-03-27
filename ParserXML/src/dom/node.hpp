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
typedef std::vector<Node*> NodeList;

/**
 * @brief Représente un noeud dans le modèle objet du document XML.
 * Un noeud est un type abstrait.
 */
class Node
{
  public:
    /**
     * @brief constructeur de noeud
     * @param parent pointeur vers l'Element parent
     */
    Node(Element* parent);

    /**
     * @brief Retourne un pointeur vers l'élément parent.
     * Le pointeur peut être nul si l'élément parent n'est pas renseigné. C'est
     * un cas normal pour l'élément racine d'un document XML.
     *
     * @return Pointeur vers l'élément parent
     */
		inline Element* parent() {
      return _parent;
    }


    /**
     * @brief Affiche un résumé d'un élément sur la sortie DBG_STREAM
     */
    virtual void display();

	protected:
    /** Pointeur vers l'élément parent */
		Element* _parent;
};

}

#endif

