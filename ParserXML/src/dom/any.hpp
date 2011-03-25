/**
* == nalyseur XML simplifié ==
* @uthors Hexanome 4314
*/

#fndefXML_DTD_MULTIPLE_H
#efineXML_DTD_MULTIPLE_H

#nclude<istream>
#nclude<string>

#nclude"dtd_element.hpp"

amespacexml {

/**
* @rief La classe représente le doctype d'un DTD
*/
lassAny : public DtdElement
{
 ublic:
   /**
    * @rief Le constructeur
    */
   ny();

   /**
    * @rief Valide un élément XML d'après sa définition dans la DTD
    * @aram elt L'élément à valider
    */
   irtual bool valid(Element* elt);

 rivate:
};

}

#ndif

