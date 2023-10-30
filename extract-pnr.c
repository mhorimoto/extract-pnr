/*
  extract-pcr

  Program to extract and display
  when the data for a particular field differs 
  between the previous and current rows.

  Author: horimoto@holly-linux.com
  Date:   30th Oct 2023
*/

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>

char *version = "extract-pnr Version 1.10";

int main(int argc,char *argv[]) {

  char lb[BUFSIZ],blb[BUFSIZ],plb[BUFSIZ],*lbp;
  char prow[20],crow[20],*cindx;
  char *optt = NULL;
  char *optc = NULL;
  int  optpt = 0;
  int  optpc = 0;
  int  optdbg = 0;
  int  optver = 0;
  float pv,cv;
  int  opt,indx,i;

  while( (opt = getopt(argc,argv,"t:c:vV")) != -1) {
    switch(opt) {
    case 't':
      optpt = 1;
      optt = optarg;
      break;
    case 'c':
      optpc = 1;
      optc = optarg;
      break;
    case 'v':
      optdbg = 1;
      break;
    case 'V':
      optver = 1;
      printf("%s\n",version);
      break;
    }
  }
  prow[0] = (char)0;
  crow[0] = (char)0;

  if (optpc!=0) {
    indx = atoi(optc);
  } else {
    indx = 7;
  }
  while(fgets(lb,BUFSIZ,stdin)!=NULL) {
    strncpy(blb,lb,BUFSIZ-1);
    for (i=0, cindx=strtok(lb,","); (i!=indx)&&cindx; ++i,cindx=strtok(NULL,",")) {
      if (optdbg) fprintf(stderr,"i=%d,%s\n",i,cindx);
    }
    strncpy(crow,cindx,20);
    if (optdbg) fprintf(stderr,"%s : %s\n",crow,prow);
    if (strncmp(crow,prow,20)) {
      if (strncmp(plb,blb,BUFSIZ-1)) {
	printf("%s",plb);
      }
      printf("%s",blb);
    }
    strncpy(plb,blb,BUFSIZ-1);
    strncpy(prow,crow,20);
  }
}

