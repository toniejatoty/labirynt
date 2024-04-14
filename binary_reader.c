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
	int sum_c=0;
	int sum_l=0;
	char was_P_or_K=0;
	do {
		count=0;
		fread(&dummy,1,1,in);		
		fread(&value,1,1,in);		//wartość słowa kodowego
		fread(&count,1,1,in);		//licznik
		if(sum_c==T[4] && sum_l==T[5]) {
			sum_c++;
			fprintf(fout, "P");
			was_P_or_K=1;
		}
		if(sum_c==header.exity && sum_l==header.exitx) {
			sum_c++;
			fprintf(fout,"K");
			was_P_or_K=1;
	}
		for (int i = 0; i <= count; i++) {
			if(was_P_or_K!=0) {
				i++;
				was_P_or_K=0;
			}
			if(sum_c == T[1]-1) {
				fprintf(fout,"\n");
				sum_l++;
				if (i!=count-1) {
					sum_c=0;
					for (int j = 0; j <= count-i;j++) {
						fprintf(fout,"%c",value);
						sum_c++;
					}
				}
				else
					sum_c=0;
				continue;
			}
			sum_c++;
			fprintf(fout, "%c", value);
		}
	}while (sum_l!=(T[0]-1));
	fclose(in);
	fclose(fout);
	return T;
}
