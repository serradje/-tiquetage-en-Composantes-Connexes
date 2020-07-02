#include <stdio.h>
#include <stdlib.h>
#include "StrEcc.h"

/**
 * \file main.c
 *\author Serradj Elhadi 
 */



int main(int argc, char** argv)
{
	//system("clear");

	if (argc != 3) /** test nombre d'arguments */
	{
		fprintf(stderr,"Usage : %s <lignes> <colones>\n",argv[0]);
		exit(1);
	}
	
	 
	int ligne = atoi(argv[1]);
	int colone = atoi(argv[2]);

	StrEcc m1;
	
	m1 = Str_Alloc(ligne,colone);
			
			etiquetage(m1,15);
			
			 printf("\n");

			 printf("===========MatBool==========\n");
			 
			 affiche_Str_Bool(m1);
			 
			 printf("\n");
			 
			 printf("===========MatEcc===========\n");
			 
			 affiche_Str_Ecc(m1);
			 
			 printf("\n");
      
   free_Str_Bool_Ecc(m1);
	
	
return 0;

}

