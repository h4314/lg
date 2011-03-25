#!/bin/sh -x

PROC=../ParserXML/bin/parser

FILES=$(cat test.csv |tr -s ' ' | cut -d ' ' -f1)

rm out.csv

for i in $FILES
do
  $PROC $i
  echo "$i $?" >> out.csv
done

diff test.csv out.csv
