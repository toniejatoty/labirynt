#include "binary_reader.h"

typedef struct h {
	int File_Id;
	char ESC;
	short columns;
	short lines;
	short entryx;
	short entryy;
	short exitx;
	short exity;
	char reserved[12];
	int counter;
	int solution_offset;
	char separator;
	char wall;
	char path;
} __attribute__((packed)) head_struct;

int *binary_read(char *input) {
	int *T = calloc(10,sizeof(*T));
	FILE *in = fopen(input, "rb");
	if (in == NULL)
	{
		T[1] = -2;
		return T;
	}
	head_struct header;
	fread(&header,40,1,in);

	T[0]=header.lines;
	T[1]=header.columns;
	T[4]=header.entryy;
	T[5]=header.entryx;
	char *out = "binary_to_text";
	FILE *fout = fopen(out,"w");
	char dummy;
	char value;
	int count;
	int sum_c=1;
	int sum_l=0;
	do {
		count=0;
		fread(&dummy,1,1,in);		
		fread(&value,1,1,in);		//wartość słowa kodowego
		fread(&count,1,1,in);		//licznik
		for (int i = 0; i <= count; i++) {
			if(sum_c==T[5] && (sum_l+1)==T[4]) {
				sum_c++;
				i++;
				fprintf(fout,"P");	//miejsce na p
			}
			if(sum_c == T[1]) {
				if(sum_c==header.exitx && (sum_l+1)==header.exity)
					fprintf(fout,"K\n");				//miejsce na K
				else
					fprintf(fout,"X\n");
				sum_l++;
				if (i!=count) {
					for (int j = 0; j <= count-i;j++) {
						fprintf(fout,"%c",value);
						sum_c++;
					}
				}
				else
					sum_c=1;
				continue;
			}
			sum_c++;
			fprintf(fout, "%c", value);
		}
	}while (sum_l!=(T[0]));
	fclose(in);
	fclose(fout);
	return T;
}
