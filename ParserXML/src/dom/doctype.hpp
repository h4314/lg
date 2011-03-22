/**
 * == Analyseur XML simplifié ==
 * @authors Hexanome 4314
 */

#ifndef XML_DOCTYPE_H
#define XML_DOCTYPE_H

#include <istream>
#include <string>

namespace xml {

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
    Doctype(std::string name = "");

    /**
     * @breif donne le nom du doctype
     */
    inline std::string& name() {
      return _name;
    }

  private:
    /** Nom du doctype */
    std::string _name;
};

}

#endif

