<?xml version="1.0" encoding="UTF-8"?>

<xsl:stylesheet version="1.0" xmlns:xsl="http://www.w3.org/1999/XSL/Transform">
	<xsl:output method="html"/>
  <xsl:template match="/rapport/titre">
    <h1>
      <xsl:apply-templates/>
    </h1>
  </xsl:template>
  <xsl:template match="/rapport/auteur">
    <em>
    <xsl:text> Auteur: </xsl:text>
    <xsl:apply-templates/>
  </em>
  </xsl:template>
  <xsl:template match="/rapport/resume">
    <h2>
      Résumé
    </h2>
    <xsl:apply-templates/>
  </xsl:template>
  <xsl:template match="chapitre">
    <h2>
      Chapitre <xsl:value-of select="titre"/>
    </h2>
    <xsl:apply-templates/>
  </xsl:template>

  <xsl:template match="section">
    <xsl:apply-templates/>
  </xsl:template>

  <xsl:template match="section/titre">
    <h3>
      Section : <xsl:apply-templates/>
    </h3>

  </xsl:template>

  <xsl:template match="p">
    <p>
      <xsl:apply-templates/>
    </p>
  </xsl:template>

	<xsl:template match="/">
		<html>
			<head>
				<title>
					<xsl:value-of select="//titre"/>
					<xsl:text>, de </xsl:text>
					<xsl:value-of select="//auteur"/>
				</title>
			</head>
			<body style="background-color: white;">
				<xsl:apply-templates/>
			</body>
		</html>
	</xsl:template>
</xsl:stylesheet>
