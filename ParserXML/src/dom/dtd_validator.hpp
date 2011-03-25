/**
 * == Analyseur XML simplifié ==
 * @authors Hexanome 4314
 */

#ifndef XML_DTD_VALIDATOR_H
#define XML_DTD_VALIDATOR_H

#include "node.hpp"

namespace xml {
// TODO enum sur la cardinalité ?
/**
 * @brief Un validateur est un objet qui va tester la validité d'une séquence de
 * noeuds XML.
 */
class DtdValidator
{
  public:
    DtdValidator();

    // TODO vérifier si effectivement un destructeur virtuel est utile
    // nb : d'un autre côté, c'est pas très important la classe est vp
    virtual ~DtdValidator();

    /**
     * @brief valide le plus d'éléments possible dans la séquence dont le début
     * est pointé par cursor. Le curseur sera placé à la position du premier
     * noeud non validé.
     *
     * Notons que la séquence peut ne pas être intégralement validée sans
     * erreur (c'est d'ailleurs le cas le plus courant).
     *
     * @param cursor début de la séquence de noeuds
     * @param end fin de la séquence
     * @return vrai si aucune erreur n'a été détectée
     */
    virtual bool valid(NodeList::iterator* cursor, NodeList::iterator& end)
      const = 0;

    /**
     * @brief enregistre la cardinalité attendue, c'est à dire, l'intevalle de
     * fois où l'élément validé est attendu.
     * @param cardinality
     */
    void setCardinality(int cardinality);

  protected:
    /** cardinalité attendue, c'est à dire, intervalle de fois où l'élément
     * validé est attendu. */
    int _cardinality;
};

}

#endif

