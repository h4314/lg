#!/bin/sh

# Sort sur la sortie standard les tests qui ne passent pas.
# Se référer au document Test.html pour voir la description du test

PROC=../ParserXML/bin/parser

FILES=$(cat test.csv |tr -s ' ' | cut -d ' ' -f1)

rm out.csv

for i in $FILES
do
  $PROC $i > /dev/null 2> /dev/null
  echo "$i $?" >> out.csv
done

diff -y --left-column --suppress-common-line test.csv out.csv | tr -s ' ' | cut -d ' ' -f1
