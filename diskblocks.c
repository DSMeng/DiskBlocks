/* David Mengele */
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <math.h>
#include <ctype.h>

#define SIBLOCKS 2048L
#define DIBLOCKS (2048L*2048L)
#define TIBLOCKS (2048L*2048L*2048L)

long computeOverheadBlocks(long diskblocks) {
       long dpb = ceil((diskblocks - 12)/(float)SIBLOCKS);
        long direct = ceil((dpb - 1)/(float)SIBLOCKS);
        
	
        long indir;
	if (direct > 1)
             indir = 1;
	else
	    indir;
        
	long overblocks = direct+dpb+indir;
	  
  	return overblocks;
}

int main(int argc, char *argv[]) {
        if (argc != 2) {
                printf("Usage: diskblocks <file size in KBs>\n");
                return -1;
        }
	
	float num = 8;
        long filesize = atol(argv[1]);
        long diskblocks = filesize / 8;
	if(filesize % 8)
		diskblocks++;

	if (diskblocks > 12 + SIBLOCKS + DIBLOCKS + TIBLOCKS){
		printf("-1\n");
		return -1;
	}
	
	
        printf("%ld %d\n", diskblocks, computeOverheadBlocks(diskblocks));
}
