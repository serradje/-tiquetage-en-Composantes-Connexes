
/** \file pile.h
 */

#ifndef __PILE_H_
#define __PILE_H_

/** \class stack_s
 * stack_s = Pile non bornée dans laquelle chaque élément est une paire
 * de nombres naturels {x,y} contenant les coordonnées d'un pixel
 */


/** \struct pixel
 * contenant les coordonnées (x,y) d'un pixel
 */
 
typedef struct
{
	int x;   
	int y;
} pixel;


typedef struct stack stack_s;

/** \memberof stack_s
 * Constructeur : renvoie une nouvelle stack_s (vide)
 * \param -
 * \return stack_s vide
 * \pre
 * \post
 */
 
stack_s *stack_new (void);

/** \memberof stack_s
 * Constructeur : ajoute un élément à la stack_s
 * \param [inout] pp_stack stack_s, empiler de \a data
 * \param [in] data élément à empiler
 * \return -
 * \pre
 * \post la stack_s est non vide
 */
 
void stack_push (stack_s **, pixel *);

/** \memberof stack_s
 * Constructeur : supprime l'élément de la stack_s
 * \param [inout] pp_stack une stack_s
 * \return pixel
 * \pre la stack_s est non vide
 * \post
 */
 
pixel *stack_pop (stack_s **);

/** \memberof stack_s
 * Destructeur : libère la mémoire allouée pour une stack_s
 * \param [in] pp_stack une stack_s
 * \return -
 * \pre
 * \post \a pp_stack ne doit pas être utiisée après cet appel
 */
 
void stack_delete (stack_s **);


struct stack
{
   struct stack *prev;  /**< élément précédent dans la pile */
   struct stack *next; /**< élément suivant dans la pile */
   pixel *data;		  /**< ce qu'on stocke dans la pile*/
};


						
#endif /** #ifndef _PILE_H_ */
