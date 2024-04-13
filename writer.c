#include "writer.h"
#include "switch_writer.h"
#include "structure.h"
void writewheretogo(int fromorg, int director, FILE *out)
{if(director==1){
	if(fromorg==2) fprintf(out,"TURN RIGHT\n" );
	else if(fromorg==4) fprintf(out,"TURN LEFT\n" );
	return;
		}
if(director==3)
{	if(fromorg==2) fprintf(out,"TURN LEFT\n" );
	else if(fromorg==4) fprintf(out,"TURN RIGHT\n" );
return;
}
if(director==2)
{
	if(fromorg==1) fprintf(out,"TURN LEFT\n" );
	else if(fromorg==3) fprintf(out,"TURN RIGHT\n" );
	return;
}
if(director==4)
{if(fromorg==1) fprintf(out,"TURN RIGHT\n" );
	else if(fromorg==3) fprintf(out,"TURN LEFT\n" );
return;
}

}
int wheretogo(structure start, int fromorg,FILE * out, int *T)
{
	if(start->up!=NULL && start->up->s!=-1)
	{
	return 1;
	}
	else if(start->down!=NULL && start->down->s!=-1)
	{
	return 3;
	}
	else if(start->right!=NULL && start->right->s!=-1)
	{
	return 2;
	}
	else if(start->left!=NULL && start->left->s!=-1)
	{
	return 4;
	}


}
void gofromvertextovertex(char ** maze, FILE * out, char * in, int *T,int fromorg,structure start, int count )
{int corridors = 0,director =0,up=0,down=0,right=0,left=0, from=0;//from 1- up 2- right 3- down 4-left
	from = fromorg;
	int Kon=-1;
	do
		{
		while (T[2] / T[7] != T[6])
                {
                        if (T[2] / T[7] < T[6])
                        {
                                T[6]--;
                               maze= load2(maze, in, T);
                        }
                        else if (T[2] / T[7] > T[6])
                        {
                                T[6]++;
                                maze = load2(maze, in, T);
                        }
                }       
			corridors=0;
			up=0; down=0; right=0; left=0;
			
			//up	
			if(T[2]%T[7]==0)
			{
			T[6]--;
			maze=load2(maze,in,T);
			}
						
			if(maze[(T[2]-1)%T[7]][T[3]]=='P'||maze[(T[2]-1)%T[7]][T[3]]==' '||maze[(T[2]-1)%T[7]][T[3]]=='K' ){
			corridors ++;
			up=1;
			if(maze[(T[2]-1)%T[7]][T[3]]=='K')Kon=1;
			}
			if(T[2]%T[7]==0)
			{
			T[6]++;
			maze=load2(maze,in, T);
			}
			//up

			
			//down
			if(T[2]%T[7]==T[7]-1)
			{
				T[6]++;
				maze=load2(maze,in, T);
			}
			if( maze[(T[2]+1)%T[7]][T[3]]=='P'||maze[(T[2]+1)%T[7]][T[3]]==' ' || maze[(T[2]+1)%T[7]][T[3]]=='K'){
			corridors ++;
			down=1;
			if(maze[(T[2]+1)%T[7]][T[3]]=='K')Kon=3;
			}
if(T[2]%T[7]==T[7]-1)
{
T[6]--;
maze=load2(maze,in, T);
}

			//down
			if( maze[(T[2])%T[7]][T[3]+1]=='P'||maze[T[2]%T[7]][T[3]+1]==' '|| maze[T[2]%T[7]][T[3]+1]=='K'){
			corridors ++;
			right=1;
		       if(maze[T[2]%T[7]][T[3]+1]=='K')Kon=2;
			}
			if(maze[T[2]%T[7]][T[3]-1]=='P'|| maze[T[2]%T[7]][T[3]-1]==' '||maze[T[2]%T[7]][T[3]-1]=='K'){
			corridors ++;
			left=1;
			if(maze[T[2]%T[7]][T[3]-1]=='K')
			Kon=4;
			}

		if(corridors ==2&&Kon==-1 ){
			if(from ==1)
			from= down==1? 1: right==1? 4:2;
			else if(from ==2)
			from= down==1? 1:up==1 ?3:2;
			else if(from ==3)
			from= up==1? 3:right==1?4:2;
			else if(from ==4)
			from= up==1? 3:down==1?1:4;
			
			if(fromorg==from)
			{count++;
			if(from ==1)T[2]++;
			if(from ==2)T[3]--;
			if(from ==3)T[2]--;
			if(from ==4)T[3]++;
		}
		else if(from !=fromorg)
		{
			count++;
		fprintf(out,"FORWARD %d\n", count-1);
		changedirector(from , fromorg, out,T);
		fromorg=from;
		count =1;
		}
		}}
	while(corridors==2&& Kon==-1);
		if(corridors >=3 && Kon==-1)
		{
			//fprintf(out, "FORWARD %d\n", count);
	director=wheretogo(start,fromorg,out, T);//where i head 1 up 2 right 3 down 4 left
		if(director%2 != from%2){
			fprintf(out, "FORWARD %d\n", count);

		writewheretogo(fromorg,director,out);
		count=1;
		}
		else {count ++;}
		}
		else if(corridors ==1&& Kon==-1) 
		{
		fprintf(out,"FORWARD %d\n", count);	
		return;
		}
	if(Kon!=-1)
	{
	switch(Kon){
		case 1: 
	if(from ==3 ){fprintf(out, "FORWARD %d\n", count+1);}
	else if(from==2){ fprintf(out, "FORWARD %d\nTURN RIGHT\nFORWARD 1\n",count );}
	else if(from==4){fprintf(out, "FORWARD %d\nTURN LEFT\nFORWARD 1\n", count);}
	break;
		case 2: 
	if(from ==4 ){fprintf(out, "FORWARD %d\n", count+1);}
	else if(from==3){ fprintf(out, "FORWARD %d\nTURN RIGHT\nFORWARD 1\n",count );}
	else if(from==1){fprintf(out, "FORWARD %d\nTURN LEFT\nFORWARD 1\n", count);}
	break;

		case 3: 
	if(from ==1 ){fprintf(out, "FORWARD %d\n", count+1);}
	else if(from==4){ fprintf(out, "FORWARD %d\nTURN RIGHT \nFORWARD 1\n",count );}
	else if(from==2){fprintf(out, "FORWARD %d\nTURN LEFT \nFORWARD 1\n", count);}
	break;

		case 4 : 
	if(from ==2 ){fprintf(out, "FORWARD %d\n", count+1);}
	else if(from==3){ fprintf(out, "FORWARD %d\nTURN RIGHT \nFORWARD 1\n",count );}
	else if(from==1){fprintf(out, "FORWARD %d\nTURN LEFT \nFORWARD 1\n", count);}
	break;
		default: return;}
return;	
	}
save(out, in , T, start, maze,count);
	/*if(director==1)
save(out, in,T,start->up, maze);

	else if(director==2)
save(out, in,T,start->right, maze);

	else if(director==3)
save(out, in,T,start->down, maze);

	else if(director==4)
save(out, in,T,start->left,maze);
*/

}
void changedirector(int from, int fromorg, FILE * out,int *T)
{
		if(from ==4&& fromorg==1 ){ fprintf(out, "TURN LEFT\n");T[3]++; }
		else if(from ==4 && fromorg ==3){fprintf(out, "TURN RIGHT\n");T[3]++;}
		else if(from ==3 && fromorg ==2){fprintf(out, "TURN RIGHT\n");T[2]--;}
		else if(from ==3 && fromorg ==4){fprintf(out, "TURN LEFT\n");T[2]--;}
		else if(from ==2 && fromorg ==1){fprintf(out, "TURN RIGHT\n");T[3]--;}
		else if(from ==2 && fromorg ==3){fprintf(out, "TURN LEFT\n");T[3]--;}
		else if(from ==1 && fromorg ==2){fprintf(out, "TURN LEFT\n");T[2]++;}
		else if(from ==1 && fromorg ==4){fprintf(out, "TURN RIGHT\n");T[2]++;}
		
}
//T 0 1 - size 2,3 actual posiiton 4,5 P position
void save(FILE *out,char * in, int *T, structure start, char ** maze, int count) {
	int corridors = 0,fromorg=0, from=0;//from 1- up 2- right 3- down 4-left
	if(start->up!=NULL && start->up->s!=-1)
	{
		from = 3, fromorg=3;
		T[2]--; 
	gofromvertextovertex(maze,out,in,T,fromorg,start->up, count);	
	}
	else if(start->down!=NULL && start->down->s!=-1)
	{
		T[2] ++;
	from = 1, fromorg=1;
	gofromvertextovertex(maze,out,in,T,fromorg,start->down, count);	
	}
	else if(start->right!=NULL && start->right->s!=-1)
	{
		T[3]++;
	from = 4, fromorg=4;
	gofromvertextovertex(maze,out,in,T,fromorg,start->right, count);	
	}
	else if(start->left!=NULL && start->left->s!=-1)
	{
		T[3]--;
	from = 2, fromorg=2;
	gofromvertextovertex(maze,out,in,T,fromorg, start->left, count);	
	}
}
void go_start_first_vertex(FILE *out, char * in, int *T, structure start, char **maze)
{
	int fromorg =0;
	T[2] = T[4];
	T[3]=T[5];
	if(T[2]==0){ fromorg=1; T[2]++; }
	else if(T[3]==0){fromorg=4; T[3]++;}
	else if(T[3]==T[1]-1){fromorg=2; T[3]--;}//tu nie jestem pewny czy T[1] czy T[1]-1
	else {fromorg=3; T[2]--;}
	int count =1;
gofromvertextovertex(maze, out, in,T,fromorg,start,count );
//save(out, in, T, start, maze, 1);
}
