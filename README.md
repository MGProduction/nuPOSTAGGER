# nuPOSTAGGER

A very minimal single .h file (English) PosTagger with no external data to load, less than 10KB of static memory used as engine core data and a single call for parsing / postagging of (ANSI) english text

Emitted output uses standard Penn Treebank POS Tagset (as described for instance here: https://www.sketchengine.eu/penn-treebank-tagset/)

Functions to handle dynamic token array are also provided

*note*: quality of this postagger is "poor" (a little less than 90%). This library is meant to be used when memory (and in part, speed) are the most important issues

## Usage

use #define NUPOSTAG_IMPLEMENT when you include this .h in your main source file

## Sample calling code

#define NUPOSTAG_IMPLEMENT

#include "nuPOSTAGGER.h"

nuTokenbag tokens;

nuTokenbag_new(&tokens);

while( -- program need postagging)

 {
 
  char line[MAX_SIZE];
  
  -- get text input and put in line
  
  nuTokenbag_reset(&tokens);
  
  nuPosTag(line,&tokens,nu_doparse,NULL);
  
  -- use szPos for each of tokens.nTokens tokens in tokens.Token array for your own need
  
 }
 
nuTokenbag_delete(&tokens);

