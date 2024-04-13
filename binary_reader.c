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
	fread(&header,40,1,f);

	T[0]=header.lines;
	T[1]=header.columns;
	T[4]=header.entryy;
	T[5]=header.entryx;
	
}
