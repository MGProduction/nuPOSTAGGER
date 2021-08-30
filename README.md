# nuPOSTAGGER

A very minimal single .h file (English) PosTagger with no external data to load, less than 10KB of static memory used as engine core data and a single call for postagging of (ANSI) english text - working even on a **C64** (80's 1 Mhz 8bit machine).

Parsing is also provided but being at the moment out of the scope of this project is just a space-based word split. Being anyway internal parsing possible, functions to handle dynamic token array are also provided

Emitted output uses standard Penn Treebank POS Tagset (as described for instance here: https://www.sketchengine.eu/penn-treebank-tagset/)

**note**: quality of this postagger is "poor" (around 91%). This library is meant to be used when memory (and in part, speed) are the most important issues

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
  
  nuPosTag(line,&tokens,nu_doparse);
  
  -- use bPos value for each of tokens.nTokens tokens in tokens.Token array for your own need
     (you can show tag label string from its binary id using nuTagSZ(id) )
  
 }
 
nuTokenbag_delete(&tokens);

## Sample projects

In this repository there are also two console sample projects that uses this little library to let you test its quality.

One is a generic single file console app that should compile under win / linux / mac (**sampleapp_Generic.c**) and one is slightly different source code meant to be used with **CC65 compiler** [https://cc65.github.io/] to create a **C64** program file (**sampleapp_C64.c**)
