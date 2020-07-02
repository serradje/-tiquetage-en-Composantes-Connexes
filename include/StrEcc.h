/** \file StrEcc.h */

#ifndef __STRECC_H_
#define __STRECC_H_

#include "pile.h"

/** \class StrEcc
 * StrEcc = StrEcc contenant:
 *  une matrice booléenne matBool
 *  une matrice d'entiers matEcc
 *  deux entiers m et n qui spécifie la taille de deux matrices
 */

typedef int Bool;

typedef struct
{
		Bool ** matBool;
		int ** matEcc;
		int m;
		int n;
} StrEcc;

/** \memberof StrEcc
 * Constructeur : renvoie une StrEcc
 * \param [in] m ligne
 * \param [in] n colone
 * \return (m1.matBool,m1.matEcc) StrEcc
 * \pre 
 * \post
 */

StrEcc Str_Alloc(int l,int n);
 
/** \memberof StrEcc
 * Constructeur: affiche matBool
 * \param[in] m une StrEcc
 * \return -
 * \pre
 * \post
 */
   
void affiche_Str_Bool(StrEcc m);


/** \memberof StrEcc
 * Constructeur: affiche matEcc
 * \param[in] m une StrEcc
 * \return -
 * \pre
 * \post
 */
 
void affiche_Str_Ecc(StrEcc m);

/** \memberof int
 * Constructeur : retourne k entiers aléatoires entre 0 et h-1
 * \param [in] k entier
 * \param [in] h entier
 * \return [k]
 * \pre 
 * \post
 */
 
int* EntierAleatoire(int k, int h);

/** \memberof pixel
 * Constructeur : transforme k à l'indice (i,j) correspondante
 * \param [in] k entier
 * \param [in] m ligne
 * \param [in] n colone
 * \return (i,j) un pixel
 * \pre k >= m*n
 * \post
 */	

pixel Transforme_en_Indice ( int k, int m, int n);


/** \memberof int
 * Constructeur : renvoie la taille d'un tableau
 * \param [in] tab un tableau d'entier
 * \return (i,j) i la taille de tableau
 * \pre 
 * \post
 */	

int longueur(int* tab);


/** \memberof StrEcc
 * Constructeur : fonction permettant d'assigner les valeurs 1 pour k éléments aléatoires dans matbool à l'aide de q3 et q4
 * \param [in] m1 StrEcc
 * \param [in] k entier
 * \return (i,j) m1 une StrEcc
 * \pre 
 * \post
 */	

StrEcc assigner_1_matBool (StrEcc m1,int k);

/** \memberof StrEcc
 * Constructeur : fonction permettant d'étiqueter les composantes connexes
 * \param [in] m1 StrEcc
 * \param [in] k entier
 * \return (i,j) m1 (matEcc) une StrEcc
 * \pre 
 * \post
 */	


StrEcc etiquetage(StrEcc m1, int k);

/** \memberof StrEcc
 * Destructeur : libère la mémoire allouée pour une StrEcc
 * \param[in] Ecc une StrEcc
 * \return -
 * \pre
 * \post \a Ecc ne doit pas être utiisée après cet appel
 */

void free_Str_Bool_Ecc (StrEcc m);

#endif /** #ifndef _STRECC_H_ */


