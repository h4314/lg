#!/bin/sh

PROC=../ParserXML/bin/parser

FILES=$(cat test.csv |tr -s ' ' | cut -d ' ' -f1)

rm out.csv

for i in $FILES
do
  $PROC $i > /dev/null 2> /dev/null
  echo "$i $?" >> out.csv
done

diff -y --left-column --suppress-common-line test.csv out.csv | tr -s ' ' | cut -d ' ' -f1
