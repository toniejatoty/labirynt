#include <stdio.h>
#include <stdlib.h>
#include "structure.h"


void freeafterposition(structure position,structure special)
{
	return; // narazie return sprawdzam czy to nie rozwiazuje labirynta
        if(position==NULL) return;
if(position->up!=NULL)  if(position->up->s!=-1)freeafterposition(position->up,special);
if(position->down!=NULL)        if(position->down->s!=-1)freeafterposition(position->down, special);
if(position->right!=NULL)       if(position->right->s!=-1)freeafterposition(position->right, special);
if(position->left!=NULL)        if(position->left->s!=-1)freeafterposition(position->left, special);
if(position->prev->up!=NULL)if (position->prev->up==position) position->prev->up=special;
if(position->prev->down!=NULL)if (position->prev->down==position) position->prev->down=special;
if(position->prev->right!=NULL)if (position->prev->right==position) position->prev->right=special;
if(position->prev->left!=NULL)if (position->prev->left==position) position->prev->left=special;

printf("UWAGA ZWALNIAM POSITION x--> %d y --> %d s-->%d\n", position->x, position->y, position->s);
free(position);
position=NULL;
}
void backasfarasyoucan(structure finish, int * T)
{
      return; // narazie return sprawdzam czy to ma wplyw na rozwiazanie labirynta
structure tmp2;
        if(finish->prev==NULL) return;
structure tmp= finish -> prev;
do
{tmp2=tmp;
        if(tmp->prev!=NULL)
tmp=tmp->prev;
free(tmp2); // TU MOGA BYC BLEDY ZE FREE UZYLEM A POTEM W CORRIDORS>=3 sie cofam a tu position==NULL
}
while(tmp->prev!=NULL && tmp->down!=NULL && tmp -> up !=NULL && tmp->right!=NULL && tmp-> left!=NULL&& tmp->down->s==-1&& tmp->up->s==-1 && tmp->right->s==-1 && tmp->left->s==-1);
}
void delasmuch(structure finish, int *T)
{
return;
        if(finish->prev==NULL){printf("nie powinno byc bledu ale w razie czego to pathfindr backasfar"); return;}
structure tmp= finish;
do
{
        if(finish->prev!=NULL)
        tmp=finish;
                finish=finish->prev;
free(tmp); // TU MOGA BYC BLEDY ZE FREE UZYLEM A POTEM W CORRIDORS>=3 sie cofam a tu position==NULL
}
while(finish->prev!=NULL && finish->down!=NULL && finish -> up !=NULL && finish->right!=NULL && finish-> left!=NULL&& finish->down->s==-1&& finish->up->s==-1 && finish->right->s==-1 && finish->left->s==-1);
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
