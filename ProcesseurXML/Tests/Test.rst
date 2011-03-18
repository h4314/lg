========================================================================
Projet 4IF: Traitement de langage, Développement d'un processeur XML
========================================================================

:Author: H4314

Ce document présente les différents plans de tests correspondant à ce projet, et indique les fichier fournis pour réaliser ces tests.

Rappels des restrictions au traitement
######################################

#. On ne traite pas les références, les instructions et les sections `CDATA`
#. Dans la DTD, les attributs seront toujours déclarés avec le type `CDATA` et le défaut `#implied`.

Tests par rapport aux fichier 'rap1.xml' et 'rap1.dtd' fournis
##############################################################

Tests:

#. Fichier non-xml 
	#. du texte avec n'importe quoi sans balise
#. Fichier xml mal structuré
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

	#. test par rapport à `<!ELEMENT chapitre (titre, (p | section)+)>` de la DTD
	#. test par rapport à `<!ELEMENT resume (#PCDATA)>` de la DTD
	#. test par rapport à `<!ELEMENT resume (#PCDATA)>` de la DTD
	#. test par rapport à `<!ELEMENT prenom (#PCDATA)>` de la DTD
	#. test par rapport à `<!ELEMENT nom (#PCDATA)>` de la DTD
	#. test par rapport à `<!ELEMENT auteur (prenom, nom)>` de la DTD
	#. test par rapport à `<!ELEMENT rapport (titre, auteur+, resume, chapitre+)>` de la DTD
