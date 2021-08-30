// ************************************************************
//
//                      nuPOSTAGGER Console
//                             by
//                        Marco Giorgini 
//
//  Licensed under the Apache License, Version 2.0 (the "License");
//  you may not use this file except in compliance with the License.
//  You may obtain a copy of the License at
//
//      http://www.apache.org/licenses/LICENSE-2.0
//
//  Unless required by applicable law or agreed to in writing, software
//  distributed under the License is distributed on an "AS IS" BASIS,
//  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
//  See the License for the specific language governing permissions and
//  limitations under the License.
//
// ************************************************************
//
//  A console sample program that uses nuPOSTAGGER (a minimal English
//  PosTagger)
//
//  Enter your text (max two lines), press enter, wait few seconds
//  and read the postagged information
//
// ************************************************************


#include <stdio.h>

#define NUPOSTAG_IMPLEMENT

#include "nuPOSTAGGER.h"

char       text[256];
nuTokenbag tokens;

void nuDump(const char*text,nuTokenbag*tokens)
{
 int i;
 for(i=0;i<tokens->nTokens;i++)
  {
   char wrd[MAXLEXLEN];
   int  len=tokens->Tokens[i].wLen;
   if(len>sizeof(wrd)-1) len=sizeof(wrd)-1;
   nuMemCpy(wrd,text+tokens->Tokens[i].dwPos,len);wrd[len]=0;
   if(i) printf(" ");
   
   if(tokens->Tokens[i].bPos!=nuTAGUNK)
    if(0&&(tokens->Tokens[i]._info&NUUNKWORD))
     printf("%s/%s[?]",wrd,nuTagSZ(tokens->Tokens[i].bPos));
    else
     printf("%s/%s",wrd,nuTagSZ(tokens->Tokens[i].bPos));
   
   else 
    printf("%s/UNK",wrd);
  }
 printf("\n"); 
}

int main()
{
 nuTokenbag_new(&tokens);
 printf("               nuPOSTAGGER\n");
 printf("        a minimal English PosTagger\n");
 printf("           by Marco Giorgini\n\n");
 while(1)
  {
   printf(">");
   gets(text);
   
   if(*text==0)
    break;      
    
   nuTokenbag_reset(&tokens);
   nuPosTag(text,&tokens,nu_doparse|nu_usemonograms);
   printf(" ");
   nuDump(text,&tokens);      
  }
 nuTokenbag_delete(&tokens); 
 return 0;
}