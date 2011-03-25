========================================================================
Projet 4IF: Traitement de langage, Développement d'un processeur XML
========================================================================

:Author: H4314

Ce document présente les différents plans de tests correspondant à ce projet, et indique les fichier fournis pour réaliser ces tests.

Rappels des restrictions au traitement
######################################

#. On ne traite pas les références, les instructions et les sections `CDATA`
#. Dans la DTD, les attributs seront toujours déclarés avec le type `CDATA` et le défaut `#implied`.

Tests
#####

Tests par rapport aux fichier 'rap1.xml' et 'rap1.dtd' fournis
===============================================================

Ci-dessous sont décrits les tests que doit satisfaire l'application. Ils ont été spécifiés à partir des fichiers donnés sur la machine `iftpserv2.insa-lyon.fr` dans le répertoire `/public/tp/ProcesseurXML/`.

Comment lire ces tests?

Les tests sont décrits de la manière suivante:

- x. objet test
	- y. cas test
		- z. sous cas du test

Pour chaque test, un fichier xml de test est fourni. Il est intitulé `Testx-y-z.xml`.

La technique et le plan de test qui a été développé ci-dessous est loin d'être parfait. En effet, les tests ont été basés sur les fichiers DTD `rap1.dtd`, `rap2.dtd` et `rap3.dtd`, qu'on a considéré. L'idéal aurait été de faire des tests "génériques" par rapport à la norme XML et de la DTD, mais nous avons pris ce qui était le plus simple et le plus efficace pour nous.


#. Fichier non-xml 
	#. du texte avec n'importe quoi sans balise
#. Fichier xml mal structuré
	- Les tests ci-dessous représentent des cas de mal-structuration du fichier xml à différents "niveaux de profondeur" dans l'arbre des noeuds liés aux éléments xml.

	#. balises non fermées

		#. balise `</rapport>` absente alors que balise `<rapport>` présente -> Erreur
		#. balise `</chapitre>` absente alors que balise `<chapitre>` présente -> Erreur
		#. balise `</p>` absente alors que balise `<p>` présente -> Erreur

	#. balises fermées mais non ouvertes

		#. balise `</rapport>` présente mais `<rapport>` absente -> Erreur
		#. balise `</chapitre>` présente mais  `<chapitre>` absente -> Erreur
		#. balise `</p>` présente mais `<p>` absente -> Erreur

#. Fichier xml-conforme avec la DTD `rap1.dtd`

	#. test par rapport à `<!ELEMENT titre (#PCDATA)>` de la DTD

		#. absence de texte entre deux balises `<titre>` et `</titre>` -> Ok
		#. présence de texte entre deux balises `<titre>` et `</titre>` -> Ok
		#. combinaison des deux test précédents -> Ok

	#. test par rapport à `<!ELEMENT p (#PCDATA)>` de la DTD

		Tests similaires à ceux présentés en section 3.1.x
		#. absence de texte entre deux balises `<p>` et `</p>` -> Ok
		#. présence de texte entre deux balises `<p>` et `</p>` -> Ok
		#. combinaison des deux test précédents -> Ok
	
  #. test par rapport à `<!ELEMENT section (titre, p+)>` de la DTD

		#. absence d'un élément `<titre>...</titre>` dans un noeud `<section>` -> Erreur
		#. absence d'un élémént `<p>..</p>` à la suite d'un élément `<titre>...</titre>` dans un noeud `<section>` -> Erreur
		#. présence d'un élémént `<p>..</p>` à la suite d'un élément `<titre>...</titre>` dans un noeud `<section>` -> Ok
		#. présence de plusieurs éléments `<p>..</p>` à la suite d'un élément `<titre>...</titre>` dans un noeud `<section>` -> Ok
		#. présence d'un élément `<p>..</p>` avant un élément `<titre>..</titre>` dans un noeud `<section>` -> Erreur
		#. présence de plusieurs éléments `<p>..</p>` avant un élément `<titre>..</titre>` dans un noeud `<section>` -> Erreur
		#. présence d'un élément `<p>..</p>` avant un élément `<titre>..</titre>` et présence d'un élément `<p>..</p>` après cet élément `<titre>..</titre>` dans un noeud `<section>` -> Erreur
		#. présence d'un élément `<p>..</p>` avant un élément `<titre>..</titre>` et présence de plusieurs éléments `<p>..</p>` après cet élément `<titre>..</titre>` dans un noeud `<section>` -> Erreur
		#. présence de plrs élmts `<p>..</p>` avant un élmt `<titre>..</titre>` et présence d'un élmt `<p>..</p>` après cet élmt `<titre>..</titre>` dans un noeud `<section>` -> Erreur
		#. présence de plrs élmts `<p>..</p>` avant un élmt `<titre>..</titre>` et présence de plsrs élmts `<p>..</p>` après cet élmt `<titre>..</titre>` dans un noeud `<section>` -> Erreur
		#. présence uniquement d'un élément `<titre>..</titre>` dans un noeud `<section>` -> Erreur
		#. présence uniquement d'un élément `<p>..</p>` dans un noeud `<section>` -> Erreur
		#. présence uniquement de plusieurs éléments `<titre>..</titre>` dans un noeud `<section>` -> Erreur
		#. présence uniquement de plusieurs éléments `<p>..</p>` dans un noeud `<section>` -> Erreur
		#. présence de plusieurs éléments `<titre>..</titre>` puis d'un élément `<p>..</p>` dans un noeud `<section>` -> Erreur
		#. présence de plusieurs éléments `<titre>..</titre>` puis de plusieurs éléments `<p>..</p>` dans un noeud `<section>` -> Erreur

	#. test par rapport à `<!ELEMENT chapitre (titre, (p | section)+)>` de la DTD

		#. absence d'un élément `<titre>..</titre>` dans un noeud `<chapitre>` -> Erreur 
		#. présence uniquement d'un élément `<titre>..</titre>` dans un noeud `<chapitre>` -> Erreur 
		#. présence d'un élément `<titre>..</titre>` suivi d'un élément `<p>..</p>` dans un noeud `<chapitre>`  -> Ok
		#. présence d'un élément `<titre>..</titre>` suivi d'un élément `</section>` dans un noeud `<chapitre>`  -> Ok
		#. présence d'un élément `<titre>..</titre>` suivi de plusieurs éléments `<p>..</p>` dans un noeud `<chapitre>` -> Ok
		#. présence d'un élément `<titre>..</titre>` suivi de plusieurs éléments `</section>` dans un noeud `<chapitre>` -> Ok
		#. présence d'un élément `<p>..<p>` suivi d'un élément `<titre>..</titre>` suivi d'un élément `<p>..</p>` dans un noeud `<chapitre>` -> Erreur 
		#. présence de plusieurs éléments `<p>..<p>` suivi d'un élément `<titre>..</titre>` suivi d'un élément `<p>..</p>` dans un noeud `<chapitre>`  -> Erreur
		#. présence d'un élément `<p>..<p>` suivi d'un élément `<titre>..</titre>` suivi de plusieurs éléments `<p>..</p>` dans un noeud `<chapitre>`  -> Erreur
		#. présence de plusieurs éléments `<p>..<p>` suivi d'un élément `<titre>..</titre>` suivi de plusieurs éléments `<p>..</p>` dans un noeud `<chapitre>`  -> Erreur
		#. présence d'un élément `<section>..<section>` suivi d'un élément `<titre>..</titre>` suivi d'un élément `<section>..</section>` dans un noeud `<chapitre>`  -> Erreur
		#. présence de plusieurs éléments `<section>..<section>` suivi d'un élément `<titre>..</titre>` suivi d'un élément `<section>..</sectino>` dans un noeud `<chapitre>`  -> Erreur
		#. présence d'un élément `<section>..<section>` suivi d'un élément `<titre>..</titre>` suivi de plusieurs éléments `<section>..</section>` dans un noeud `<chapitre>`  -> Erreur
		#. présence de plusieurs éléments `<section>..<section>` suivi d'un élément `<titre>..</titre>` suivi de plusieurs éléments `<section>..</section>` dans un noeud `<chapitre>`  -> Erreur
		#. présence d'un élément `<titre>..</titre>` suivi d'une combinaison dans un ordre quelconque d'éléments `<p>..</p>` et `<section>..</section>` dans un noeud `<chapitre>`  -> Ok
		
		- Les tests 3.4.11 à 3.4.14 n'ont pas les fichiers xml générés, donc ne peuvent être testés pour le moment.

	#. test par rapport à `<!ELEMENT resume (#PCDATA)>` de la DTD

		- Tests similaires à ceux présentés en section 3.1.x
		- Pas de test 3.5.3, car normalement la balise `<resume>` n'apparait qu'une seule fois dans le fichier xml.

		#. absence de texte entre deux balises `<resume>` et `</resume>` -> Ok
		#. présence de texte entre deux balises `<resume>` et `</resume>` -> Ok

	#. test par rapport à `<!ELEMENT p (#PCDATA)>` de la DTD

		- Tests similaires à ceux présentés en section 3.1.x
		- Pas de test 3.7.3, car normalement la balise `<prenom>` n'apparait qu'une seule fois dans le fichier xml.

		#. absence de texte entre deux balises `<p>` et `</p>` -> Ok
		#. présence de texte entre deux balises `<p>` et `</p>` -> Ok
		#. combinaison des deux test précédents -> Ok

	#. test par rapport à `<!ELEMENT prenom (#PCDATA)>` de la DTD

		- Tests similaires à ceux présentés en section 3.1.x

		#. absence de texte entre deux balises `<prenom>` et `</prenom>` -> Ok
		#. présence de texte entre deux balises `<prenom>` et `</prenom>` -> Ok
	#. test par rapport à `<!ELEMENT nom (#PCDATA)>` de la DTD

		- Tests similaires à ceux présentés en section 3.1.x
		- Pas de test 3.8.3, car normalement la balise `<nom>` n'apparait qu'une seule fois dans le fichier xml.

		#. absence de texte entre deux balises `<nom>` et `</nom>` -> Ok
		#. présence de texte entre deux balises `<nom>` et `</nom>` -> Ok

	#. test par rapport à `<!ELEMENT auteur (prenom, nom)>` de la DTD

		#. présence uniquement d'un élément `<prenom>..</prenom>` dans un noeud `<auteur>` -> Erreur
		#. présence uniquement d'un élément `<nom>..</nom>` dans un noeud `<auteur>` -> Erreur
		#. présence d'un élémént `<nom>..</nom>` à la suite d'un élément `<prenom>...</prenom>` dans un noeud `<auteur>` -> Ok
		#. présence uniquement de plusieurs éléments `<prenom>..</prenom>` dans un noeud `<auteur>` -> Erreur
		#. présence uniquement de plusieurs éléments `<nom>..</nom>` dans un noeud `<auteur>` -> Erreur
		#. présence d'un élément `<prénom>..</prénom>` suivi de plusieurs éléments `<nom>..</nom>` -> Erreur
		#. présence de plusieurs éléments `<prenom>..</prenom>` puis de plusieurs éléments `<nom>..</nom>` dans un noeud `<auteur>` -> Erreur
		#. présence de plusieurs éléments `<prenom>..</prenom>` et `<nom>..</nom>` dans un ordre quelconque dans un noeud `<auteur>` -> Erreur

		- En clair, le noeud `<auteur>` ne peut pas avoir plus de 2 éléments, et ceux-ci doivent être précisément, dans l'ordre, les éléments `<prenom>..</prenom>` et `<nom>..</nom>`

	#. test par rapport à `<!ELEMENT rapport (titre, auteur+, resume, chapitre+)>` de la DTD

		#. absence d'un élément `<titre>..</titre>` dans le noeud `<rapport>` -> Erreur
		#. absence d'un élément `<auteur>..</auteur>` dans le noeud `<rapport>` -> Erreur
		#. absence d'un élément `<resume>..</resume>` dans le noeud `<rapport>` -> Erreur
		#. absence d'un élément `<chapitre>` dans le noeud `<rapport>` -> Erreur
		#. présence, dans l'ordre, d'un élément `<titre>..</titre>`, d'un élément `<auteur>..</auteur>`, d'un élément `<resume>..</resume>` et d'un élément `<chapitre>..</chapitre>` dans le noeud `<rapport>` -> Ok
		#. présence, dans l'ordre, d'un élément `<titre>..</titre>`, de plusieurs éléments à la suite `<auteur>..</auteur>`, d'un élément `<resume>..</resume>` et de plusieurs éléments à la suite `<chapitre>..</chapitre>` dans le noeud `<rapport>` -> Ok
		#. présence au bon endroit de plusieurs éléments `<titre>..</titre>` à la suite dans le noeud `<rapport>` -> Erreur
		#. présence au bon endroit de plusieurs éléments `<resume>..</resume>` à la suite dans le noeud `<rapport>` -> Erreur
		#. présence de plusieurs éléments `<titre>..</titre>` dans le désordre dans le noeud `<rapport>` -> Erreur
		#. présence de plusieurs éléments `<auteur>..</auteur>` dans le désordre dans le noeud `<rapport>` -> Erreur
		#. présence de plusieurs éléments `<resume>..</resume>` dans le désordre dans le noeud `<rapport>` -> Erreur
		#. présence de plusieurs éléments `<chapitre>..</chapitre>` dans le désordre dans le noeud `<rapport>` -> Erreur	
		#. placement au mauvais emplacement d'un élément `<titre>..</titre>` dans le noeud `<rapport>` -> Erreur
		#.  placement au mauvais emplacement d'un élément `<auteur>..</auteur>` dans le noeud `<rapport>` -> Erreur
		#.  placement au mauvais emplacement d'un élément `<resume>..</resume>` dans le noeud `<rapport>` -> Erreur
		#.  placement au mauvais emplacement d'un élément `<chapitre>` dans le noeud `<rapport>` -> Erreur

Tests par rapport aux fichier 'rap2.xml' et 'rap3.dtd' fournis
==============================================================

Tous les tests présentés dans la section précédente doivent aussi être satisfaits, en remplaçant  le fichier `rap1.dtd`, pris en entrée de l'application, par `rap3.dtd`. Sauf mention contraire (voir ci-dessous) Les fichiers de tests à prendre sont les mêmes (`Testx-y-z.xml`).


Changement dans le plan de test par rapport à ceux présentés dans la section précédente:

- Les tests 3.1.1, 3.1.2, 3.1.3, 3.3.1, 3.3.5, 3.3.6, 3.3.7, 3.3.8, 3.3.9, 3.3.10, 3.3.12, 3.3.13, 3.3.14, 3.3.15, 3.3.16, 3.4.1, 3.4.2, 3.4.7,3.4.8, 3.4.9, 3.4.10 sont supprimés.

Modification de tests:

- Pour les tests 3.3.x et 3.4.y, il faut les faire avec les fichiers xml `Test-Rap3-dtd-3.3.x.xml` et `Test-Rap3-dtd-3.4.y.xml`
- Pour les testss 3.3.x et 3.4.y, il faut remplacer dans les énoncés des tests la mention "présence d'un élément `<titre>..</titre>`" par la mention "présence de l'attribut `titre`".

Nouveaux tests à réaliser:

4. tests de conformité avec `rap3.dtd`
<<<<<<< HEAD

	#. Tests avec l'ajout des éléments `<!ATTLIST chapitre titre CDATA #IMPLIED>` 

=======
	#. Tests avec l'ajout des éléments `<!ATTLIST chapitre titre CDATA #IMPLIED>` 
>>>>>>> bbe1e82f076658b67075ab835cb6d5201456acc5
		#. absence de l'attribut `titre` pour l'élément `<chapitre>..</chapitre>` dans un noeud `<chapitre>` -> Erreur
		#. présence de l'attribut `titre` pour l'élément `<chapitre>..</chapitre>` dans un noeud `<chapitre>`-> Ok
		#. absence de l'attribut `titre` mais présence de l'élément `<titre>..</titre>` pour l'élément `<chapitre>..</chapitre>` dans un noeud `<chapitre>` -> Erreur
		#. présence de l'attribut `titre` et  présence de l'élément `<titre>..</titre>` pour l'élément `<chapitre>..</chapitre>` dans un noeud `<chapitre>` -> Erreur
	#. Tests avec l'ajout de l'élément `<!ATTLIST section titre CDATA #IMPLIED>`
<<<<<<< HEAD

=======
>>>>>>> bbe1e82f076658b67075ab835cb6d5201456acc5
		#. Même test que 4.1.1 avec `chapitre` remplacé par `section`
		#. Même test que 4.1.2 avec `chapitre` remplacé par `section`
		#. Même test que 4.1.3 avec `chapitre` remplacé par `section`
		#. Même test que 4.1.4 avec `chapitre` remplacé par `section`
	
