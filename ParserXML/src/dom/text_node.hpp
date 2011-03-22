/**
 * == Analyseur XML simplifié ==
 * @authors Hexanome 4314
 */

#ifndef XML_TEXT_NODE_H
#define XML_TEXT_NODE_H

#include "node.hpp"

#include <string>

namespace xml {

/**
 * @brief Représente un noeud texte
 */
class TextNode : public Node
{
  public:
    /**
     * @brief Constructeur d'un noeud texte
     * @param content valeur textuelle du noeud
     */
    TextNode(std::string content);

    /**
     * @brief identifie le contenu du noeud
     */
    void setContent(std::string content);

    /**
     * @brief donne le contenu du noeud
     */
    inline const std::string& content() const {
      return _content;
    }

  private:
    /** valeur textuelle du noeud */
    std::string _content;
};

}

#endif

