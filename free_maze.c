#include <stdio.h>
#include <stdlib.h>
#include "free_maze.h"
void deletenotused(structure finish, structure special)
{
if(finish!=NULL&&finish->prev!=NULL && finish->prev->s!=-1)
{
if(finish->prev->up!=NULL && finish->prev->up->s!=-1 && finish->prev->up!=finish)
	freeafterposition(finish->prev->up, special);

if(finish->prev->right!=NULL && finish->prev->right->s!=-1 && finish->prev->right!=finish)
	freeafterposition(finish->prev->right, special);
if(finish->prev->down!=NULL && finish->prev->down->s!=-1 && finish->prev->down!=finish)
	freeafterposition(finish->prev->down, special);
if(finish->prev->left!=NULL && finish->prev->left->s!=-1 && finish->prev->left!=finish)
	freeafterposition(finish->prev->left, special);
deletenotused(finish->prev, special);
}
}

void freeasmuchasyoucan(structure finish)
{
char corridors = 60;//char needs 1B int needs 4B, when i declare char corridors=0; and corridors ++; corridors have value like 1 '001' and this '001' dont influence well on program
if(finish->prev->up->s!=-1)corridors++;
if(finish->prev->down->s!=-1)corridors++;
if(finish->prev->right->s!=-1)corridors++;
if(finish->prev->left->s!=-1)corridors++;
if(corridors ==60)
{
freeasmuchasyoucan(finish->prev);
free(finish);
}
}


void freeafterposition(structure position, structure special)
{
        //return; // narazie return sprawdzam czy to nie rozwiazuje labirynta
        if (position == NULL)
                return;
        if (position->up != NULL)
                if (position->up->s != -1)
                        freeafterposition(position->up, special);
        if (position->down != NULL)
                if (position->down->s != -1)
                        freeafterposition(position->down, special);
        if (position->right != NULL)
                if (position->right->s != -1)
                        freeafterposition(position->right, special);
        if (position->left != NULL)
                if (position->left->s != -1)
                        freeafterposition(position->left, special);
        if (position->prev->up != NULL)
                if (position->prev->up == position)
                        position->prev->up = special;
        if (position->prev->down != NULL)
                if (position->prev->down == position)
                        position->prev->down = special;
        if (position->prev->right != NULL)
                if (position->prev->right == position)
                        position->prev->right = special;
        if (position->prev->left != NULL)
                if (position->prev->left == position)
                        position->prev->left = special;

//        printf("UWAGA ZWALNIAM POSITION x--> %d y --> %d s-->%d\n", position->x, position->y, position->s);
        free(position);
        position = NULL;
}
/*
void findwspolne(structure oldfinish, structure newfinish)
{
        structure old=finish;
        structure new=newfinish;
while(old->prev!=NULL)
{ old=old->prev;

while(new->prev!=NULL)
}
}*/

