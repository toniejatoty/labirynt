#include "binary_reader.h"

struct h {
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
} pragma pack typedef head_struct;

void binary_read(int *T) {
	
	FILE *in = fopen(input, "rb");
	if (int == NULL)
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
	do {
		count = 0;
		fread(&dummy,1,1,in);		
		fread(&value,1,1,in);		//wartość słowa kodowego
		fread(&count,1,1,in);		//licznik
		for (int i = 0; i < count; i) {
			sum_c++;
			if(sum_c == T[1]) {
				fprintf(fout,"\n");
				if (i!=count-1)
				sum_c=0;
					for (int j = 0; j < count-i) {
						sum++;
						fprintf(fout,"%c",value);
					}
				else
					sum_c=0;
				continue;
			}
			fprintf(fout, "%c", value);
	}while (sum_l==(T[0]+1));

	
}
