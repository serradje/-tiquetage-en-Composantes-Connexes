
/** \file StrEcc.c
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "color.h"
#include "StrEcc.h"
#include "pile.h"


/** \memberof StrEcc
 * Constructeur : renvoie une StrEcc
 * \author Serradj Elhadi
 * \param [in] m ligne
 * \param [in] n colone
 * \return (m1.matBool,m1.matEcc) StrEcc
 * \pre 
 * \post
 */
						
StrEcc Str_Alloc(int m,int n)
{
	
	StrEcc m1;
	int i,j;
	
	m1.m=m;
	
	m1.n=n;
	
	m1.matBool = (Bool **) malloc (m*(sizeof(Bool*)));
	
	m1.matEcc = (int **) malloc (m*(sizeof(int*)));
	
		for(i = 0; i < m1.m ; i++)
			{
				m1.matBool[i]=(Bool *) malloc(n*sizeof(Bool));
				
				m1.matEcc[i]=(int *) malloc(n*sizeof(int));
			}
			
	   for(i = 0 ; i < m1.m ; i++)
			{
				for (j = 0 ; j < m1.n ; j++)
					{
						m1.matBool[i][j]=0;
						
						m1.matEcc[i][j]=0;
					}
			}
		
    return m1;
}
 
/** \memberof StrEcc
 * Destructeur : libère la mémoire allouée pour une StrEcc
 * \author Serradj Elhadi
 * \param[in] Ecc une StrEcc
 * \return -
 * \pre
 * \post \a Ecc ne doit pas être utiisée après cet appel
 */
  
void free_Str_Bool_Ecc(StrEcc Ecc)
{
	int i;
	
	for(i=0; i< Ecc.m; i++)
		{
			free(Ecc.matBool[i]);
			
			free(Ecc.matEcc[i]);
			
			Ecc.matBool[i] =NULL;
			
			Ecc.matEcc[i] =NULL;
		}
		
	free(Ecc.matBool);
	free(Ecc.matEcc);
	Ecc.matBool = NULL;
	Ecc.matEcc = NULL;
}

/** \memberof StrEcc
 * Constructeur: affiche matBool
 * \author Serradj Elhadi
 * \param[in] m une StrEcc
 * \return -
 * \pre
 * \post
 */
 
void affiche_Str_Bool(StrEcc m)
{
	int i,j,k;
	
	 for (k = 0 ; k<m.n*2.5; k++)
		{	
			printf(" _");		 
		}
		
	 printf("\n");
	
	 for (i = 0 ; i<m.m; i++)
		{	
			printf("|");
		 
			for (j = 0 ; j<m.n; j++)
				{
					printf("_");
					
					if (m.matBool[i][j] == 1)
					{
						printf(FG_LTGREEN "%2d" NOCOLOR ,m.matBool[i][j]) ;
					}
					
					else
					{
						printf("%2d",m.matBool[i][j]) ;
					}
					
					printf("_");
					printf("|");
            
				}
			printf("\n");
		}
	return;
}
			
         


/** \memberof StrEcc
 * Constructeur: affiche matEcc
 * \author Tourki Oussema
 * \param[in] m une StrEcc
 * \return -
 * \pre
 * \post
 */
 
void affiche_Str_Ecc(StrEcc m)
{
	;
	int i,j,k;
	
	 for (k = 0 ; k<m.n*2.5; k++)
		{	
		 printf(" _");		 
		}
		
	 printf("\n");
	
	 for (i = 0 ; i<m.m; i++)
		{	
			printf("|");
		 
			for (j = 0 ; j<m.n; j++)
			{
				printf("_");
				         
				if (m.matEcc[i][j] == 1)
					printf(BG_RED"%2d" NOCOLOR ,m.matEcc[i][j]) ;
				if (m.matEcc[i][j] == 2)
					printf(BG_GREEN"%2d" NOCOLOR ,m.matEcc[i][j]) ;
				if (m.matEcc[i][j] == 3)
					printf(BG_BLUE"%2d" NOCOLOR ,m.matEcc[i][j]) ;
				if (m.matEcc[i][j] == 4)
					printf(BG_YELLOW"%2d" NOCOLOR ,m.matEcc[i][j]) ;
				if (m.matEcc[i][j] == 5)
					printf(BG_MAGENTA"%2d" NOCOLOR ,m.matEcc[i][j]) ;
				if (m.matEcc[i][j] == 6)
					printf(BG_CYAN"%2d" NOCOLOR ,m.matEcc[i][j]) ;
				if (m.matEcc[i][j] == 7)
					printf(FG_LTRED"%2d" NOCOLOR ,m.matEcc[i][j]) ;
				if (m.matEcc[i][j] == 8)
					printf(FG_LTGREEN"%2d" NOCOLOR ,m.matEcc[i][j]) ;
				if (m.matEcc[i][j] == 9)
					printf(FG_LTBLUE"%2d" NOCOLOR ,m.matEcc[i][j]) ;
				if (m.matEcc[i][j] == 10)
					printf(FG_LTYELLOW"%2d" NOCOLOR ,m.matEcc[i][j]) ;
				if (m.matEcc[i][j] == 11)
					printf(FG_LTMAGENTA"%2d" NOCOLOR ,m.matEcc[i][j]) ;
				if (m.matEcc[i][j] == 12)
					printf(FG_LTCYAN"%2d" NOCOLOR ,m.matEcc[i][j]) ;
				if (m.matEcc[i][j] == 13)
					printf(FG_MAGENTA"%2d" NOCOLOR ,m.matEcc[i][j]) ;
				if (m.matEcc[i][j] == 14)
					printf(FG_BLUE"%2d" NOCOLOR ,m.matEcc[i][j]) ;
				if (m.matEcc[i][j] == 15)
					printf(FG_YELLOW"%2d" NOCOLOR ,m.matEcc[i][j]) ;
				if(m.matEcc[i][j]==0 || m.matEcc[i][j]>15)
					printf("%2d",m.matEcc[i][j]) ;
				
			
				printf("_");
				printf("|");
			}
        printf("\n");
	}
	return;
}

/** \memberof int
 * Constructeur : retourne k entiers aléatoires entre 0 et h-1
 * \author Serradj Elhadi
 * \param [in] k entier
 * \param [in] h entier
 * \return [k]
 * \pre 
 * \post
 */

int* EntierAleatoire(int k, int h)
{
	
	srand(time(NULL));
	if( k >= h)
	{
		printf(" k ne doit pas depasser m*n\n");
		exit(1);
	}
    int i;
    
    int * tab = (int *)malloc(k*sizeof(int));
    
    for (i = 0 ; i<k; i++)
    {
       tab[i] = rand()%h;        
	}
	
  return tab;
}

/** \memberof pixel
 * Constructeur : transforme k à l'indice (i,j) correspondante
 * \author Tourki Oussema
 * \param [in] k entier
 * \param [in] m ligne
 * \param [in] n colone
 * \return (i,j) un pixel
 * \pre k >= m*n
 * \post
 */	

pixel Transforme_en_Indice ( int k, int m, int n)
{
	
	int i,j;
	
	pixel c;
	
	int compt=0;
	
	for(i=0; i<m; i++)
	{
		for(j=0; j<n; j++)
			{
				if (compt == k)
					{
						c.x = i;
						c.y = j;			
					}
					
				compt++;
			}
	}
		 
	return c;
}


/** \memberof int
 * Constructeur : renvoie la taille d'un tableau
 * \author Tourki Oussema
 * \param [in] tab un tableau d'entier
 * \return i la taille de tableau
 * \pre 
 * \post
 */	

int longueur(int*tab){
	int i;
	for(i=0;tab[i]!='\0';i++);
	return i;
}

/** \memberof StrEcc
 * Constructeur : fonction permettant d'assigner les valeurs 1 pour k éléments aléatoires dans matbool à l'aide de q3 et q4
 * \author Serradj Elhadi
 * \param [in] m1 StrEcc
 * \param [in] k entier
 * \return (i,j) m1 une StrEcc
 * \pre 
 * \post
 */	

StrEcc assigner_1_matBool (StrEcc m1,int k)
{
	int* tab = EntierAleatoire(k,m1.m*m1.n);
	
	int i;
	
	pixel c;
	
	for(i=0;i<longueur(tab);i++)
		{
			c=Transforme_en_Indice(tab[i],m1.m,m1.n);
			m1.matBool[c.x][c.y]=1;
		}
	
	return m1;

}

/** \memberof StrEcc
 * Constructeur : fonction permettant d'étiqueter les composantes connexes
 * \author Serradj Elhadi & Tourki Oussema
 * \param [in] m1 StrEcc
 * \param [in] k entier
 * \return (i,j) m1 (matEcc) une StrEcc
 * \pre 
 * \post
 */	

StrEcc etiquetage(StrEcc m1, int k)
{
	
     assigner_1_matBool(m1, k);
     
	 int etqc =1;
	 
	pixel c,d;
	
	pixel* v;
	
	stack_s * p = stack_new();
	
	int i,j;
	
	printf("nombre de ligne m: %d\n",m1.m);
	printf("nombre de cologne n: %d\n",m1.n);
	printf("\n");

	for ( i=0; i< m1.m; i++)
		{
			 for ( j = 0; j<m1.n;j++)
				{
				  c.x = i ;
				  c.y = j;
			   
				  if(m1.matBool[i][j] == 1 &&  m1.matEcc[i][j] < 1 )
					{
					   printf(" pixel: (%d,%d) etqc: %d\n",i+1,j+1,etqc);
					
					stack_push(&p,&c);

					  while (p != NULL)
					   {                   
							  v =(pixel*) stack_pop(&p);           

							   d.x = (*v).x;
							   d.y = (*v).y;
							   m1.matEcc[d.x][d.y] = etqc;               							  
							   printf("pixel dépilé: (%d,%d)\n",d.x+1,d.y+1);
                    
             
					if( d.y-1>=0)
					{                        
						if( m1.matBool[d.x][d.y-1] == 1 && m1.matEcc[d.x][d.y-1] < 1)
							{

								m1.matEcc[d.x][d.y-1] = etqc;
								c.x =d.x;
								c.y=d.y-1;
								printf(" voisin: (%d,%d) etqc: %d\n",c.x+1,c.y+1,etqc);
								stack_push(&p,&c);
							}
					}

					if( d.y+1<=m1.n)
					{
						if(m1.matBool[d.x][d.y+1] == 1 && m1.matEcc[d.x][d.y+1] < 1)
							{
								m1.matEcc[c.x][c.y+1] = etqc;
								c.x =d.x;
								c.y=d.y+1;
								printf(" voisin: (%d,%d) etqc: %d\n",c.x+1,c.y+1,etqc);									 
								stack_push(&p,&c);
							}
					}
					
				   if( d.x-1>=0)
					{ 
						if( m1.matBool[d.x-1][d.y] == 1 && m1.matEcc[d.x-1][d.y] < 1)
							{
								m1.matEcc[d.x-1][d.y] = etqc;
								c.x =d.x-1;
								c.y=d.y;
								printf(" voisin: (%d,%d) etqc: %d\n",c.x+1,c.y+1,etqc); 
							   stack_push(&p,&c);
							}
					}
					
                  if( d.x+1<m1.m)
					{					  
						if(m1.matBool[d.x+1][d.y] == 1 && m1.matEcc[d.x+1][d.y] < 1)
							{
								m1.matEcc[d.x+1][d.y] = etqc;
								c.x =d.x+1;
								c.y=d.y;
								printf(" voisin: (%d,%d) etqc: %d\n",c.x+1,d.y+1,etqc);
								printf("\n");  
								stack_push(&p,&c);
							}
					}
               
				}
				
				etqc ++;
			}
		}    
	}  
				//free(v);
				stack_delete(&p);

return m1;
}
