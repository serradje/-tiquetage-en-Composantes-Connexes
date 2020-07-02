
/** \file pile.c
 * Pile non bornée dans laquelle chaque élément est une paire 
 * de nombres naturels {x,y} contenant les coordonnées d'un pixel
 */

#include <stdio.h>
#include <stdlib.h>
#include "pile.h"

/** \memberof stack_s
 * Constructeur : renvoie une nouvelle stack_s (vide)
 * \author Serradj Elhadi & Tourki Oussema
 * \param -
 * \return stack_s vide
 * \pre
 * \post
 */
 
stack_s *stack_new (void)
{
   return (NULL);
}

/** \memberof stack_s
 * Constructeur : ajoute un élément à la stack_s
 * \author Serradj Elhadi & Tourki Oussema
 * \param [inout] pp_stack stack_s, empiler de \a data
 * \param [in] data élément à empiler
 * \return -
 * \pre
 * \post la stack_s est non vide
 */

void stack_push (stack_s ** pp_stack, pixel*data)
{
   if (pp_stack != NULL)
   {
      stack_s *p_p = *pp_stack;
      
      stack_s *p_l = NULL;

      p_l = malloc (sizeof (*p_l));
      
      if (p_l != NULL)
      {
         pixel* clone=malloc (sizeof (data));
         
         (*clone).x =(*data).x ;
         
         (*clone).y=(*data).y ;
         
         p_l->data = clone;
         
         p_l->next = NULL;
         
         p_l->prev = p_p;
         
         if (p_p != NULL)
         
            p_p->next = p_l;
            
         *pp_stack = p_l;
      }
      else
      {
         fprintf (stderr, "Memoire insuffisante\n");
         exit (EXIT_FAILURE);
      }
   }
   return;
}

/** \memberof stack_s
 * Constructeur : supprime l'élément de la stack_s
 * \author Serradj Elhadi & Tourki Oussema
 * \param [inout] pp_stack une stack_s
 * \return pixel
 * \pre  la stack_s est non vide
 * \post
 */

pixel* stack_pop (stack_s ** pp_stack)
{
   pixel *ret = NULL;

   if (pp_stack != NULL && *pp_stack != NULL)
   {
      stack_s *p_l = *pp_stack;
      
      stack_s *p_p = p_l->prev;

      if (p_p != NULL)
      
         p_p->next = NULL;
         
      ret = p_l->data;
      
      free (p_l);
      
      p_l = NULL;
      
      *pp_stack = p_p;
   }
   return (ret);
}

/** \memberof stack_s
 * Destructeur : libère la mémoire allouée pour une stack_s
 * \author Serradj Elhadi & Tourki Oussema
 * \param [in] pp_stack une stack_s
 * \return -
 * \pre
 * \post \a pp_stack ne doit pas être utiisée après cet appel
 */
 
void stack_delete (stack_s ** pp_stack)
{
   if (pp_stack != NULL && *pp_stack != NULL)
   {
      while (*pp_stack != NULL)
      
         stack_pop (pp_stack);
   }
   return;
}
