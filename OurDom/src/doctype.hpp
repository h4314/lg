/**
 * == Analyseur XML simplifié ==
 * @authors Hexanome 4314
 */

#ifndef XML_DOCTYPE_H
#define XML_DOCTYPE_H

#include <istream>

namespace xml {

/**
 * @brief La classe représente le doctype d'un DTD
 */
class Doctype
{
  public:
    /**
     * @brief Le constructeur par défaut 
     */
    Doctype();
    
    /**
     * @brief Le constructeur
     * @param name Le nom du doctype
     */
    Doctype(string name);

  protected:
  private:
    string _name;
};

}

#endif

