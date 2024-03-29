#include "writer.h"
#include "structure.h"
int wheretogo(structure start, int fromorg,FILE * out, int *T)
{
	if(start->up!=NULL && start->up->s!=-1)
	{
	if(fromorg==2) fprintf(out,"TURN RIGHT\n" );
	else if(fromorg==4) fprintf(out,"TURN LEFT\n" );
	T[2]--;
	return 1;
	}
	else if(start->down!=NULL && start->down->s!=-1)
	{
	if(fromorg==2) fprintf(out,"TURN LEFT\n" );
	else if(fromorg==4) fprintf(out,"TURN RIGHT\n" );
	T[2]++;
	return 3;
	}
	else if(start->right!=NULL && start->right->s!=-1)
	{
	if(fromorg==1) fprintf(out,"TURN LEFT\n" );
	else if(fromorg==3) fprintf(out,"TURN RIGHT\n" );
	T[3]++;
	return 2;
	}
	else if(start->left!=NULL && start->left->s!=-1)
	{
	if(fromorg==1) fprintf(out,"TURN RIGHT\n" );
	else if(fromorg==3) fprintf(out,"TURN LEFT\n" );
	T[3]--;
	return 4;
	}


}
void gofromvertextovertex(char ** maze, FILE * out, char * in, int *T,int fromorg )
{int corridors = 0, count = 1, from=0;//from 1- up 2- right 3- down 4-left
	from = fromorg;
	while(corridors ==2)
		{
			if(maze[T[2]-1][T[3]]==" "){
			corridors ++;

				from = 3;
			}
			if(maze[T[2]+1][T[3]]==" "){
			corridors ++;
			from = 1;
			}
			if(maze[T[2]][T[3]+1]==" "){
			corridors ++;
			from = 4;
			}
			if(maze[T[2]][T[3]-1]==" "){
			corridors ++;
			from = 2;
			}

		if(corridors ==2 && from = fromorg)
		{count++;
			if(from =1)T[2]++;
			if(from =2)T[3]--;
			if(from =3)T[2]--;
			if(from =4)T[3]++;
		}
		else if(from !=fromorg&&corridors==2)
		{
		fprintf(out,"FORWARD %d\n", count);
		changedirector();
		fromorg=from;
		count =1;
		}
		}
		if(corridors >=3)
		{
			fprintf(out, "FORWARD %d\n", count);
		int director=wheretogo(start->up,fromorg,out, T);//where i head 1 up 2 right 3 down 4 left
		}
if(director==1)
save(out, in,T,start->up, maze);

	else if(director==2)
save(out, in,T,start->right, maze);

if(director==3)
save(out, in,T,start->down, maze);

if(director==4)
save(out, in,T,start->left,maze);


}
void changedirector(int from, int fromorg)
{
		if(from ==4&& fromorg==1 ) fprintf(out, "TURN LEFT\n");
		else if(from ==4 && fromorg ==3)fprintf(out, "TURN RIGHT\n");
		else if(from ==3 && fromorg ==2)fprintf(out, "TURN RIGHT\n");
		else if(from ==3 && fromorg ==4)fprintf(out, "TURN LEFT\n");
		else if(from ==2 && fromorg ==1)fprintf(out, "TURN RIGHT\n");
		else if(from ==2 && fromorg ==3)fprintf(out, "TURN LEFT\n");
		else if(from ==1 && fromorg ==2)fprintf(out, "TURN LEFT\n");
		else if(from ==1 && fromorg ==4)fprintf(out, "TURN RIGHT\n");
		
}
//T 0 1 - size 2,3 actual posiiton 4,5 P position
void save(FILE *out,char * in, int *T, structure start, char ** maze) {
	int corridors = 0, count = 1,fromorg=0; from=0;//from 1- up 2- right 3- down 4-left
	if(start->up!=NULL && start->up->s!=-1)
	{	from = 3, fromorg=3;

	gofromvertextovertex(maze,out,in,*T,fromorg);
		while(corridors ==2)
		{
			if(maze[T[2]-1][T[3]]==" "){
			corridors ++;

				from = 3;
			}
			if(maze[T[2]+1][T[3]]==" "){
			corridors ++;
			from = 1;
			}
			if(maze[T[2]][T[3]+1]==" "){
			corridors ++;
			from = 4;
			}
			if(maze[T[2]][T[3]-1]==" "){
			corridors ++;
			from = 2;
			}

		if(corridors ==2 && from = fromorg)
		{count++;
			if(from =1)T[2]++;
			if(from =2)T[3]--;
			if(from =3)T[2]--;
			if(from =4)T[3]++;
		}
		else if(from !=fromorg&&corridors==2)
		{
		fprintf(out,"FORWARD %d\n", count);
		changedirector();
		fromorg=from;
		count =0;
		}
		}
		if(corridors >=3)
		{
		int director=wheretogo(start->up,fromorg,out, T);//where i head 1 up 2 right 3 down 4 left
		}
	
	}
	else if(start->down!=NULL && start->down->s!=-1)
	else if(start->right!=NULL && start->right->s!=-1)
	else if(start->left!=NULL && start->left->s!=-1)
if(director==1)
save(FILE *out, in,T,start->up, char ** maze);

	else if(director==2)
save(FILE *out, in,T,start->right, char ** maze);

if(director==3)
save(FILE *out, in,T,start->down, char ** maze);

if(director==4)
save(FILE *out, in,T,start->left, char ** maze);
}
