#include <windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <math.h>

static int SearchDirection[8][2] = {{0,1},{1,1},{1,0},{1,-1},{0,-1},{-1,-1},{-1,0},{-1,1}};
static unsigned char **bitmap;
static int **labelmap;
static int **contourmap;

int read_pbm(char *fn, int *pwidth, int *pheight, char *option);
int write_rlt(char *fn, int cccnt, int width, int height, char *option);
void Tracer(int *cy, int *cx, int *tracingdirection);
void ContourTracing(int cy, int cx, int labelindex, int tracingdirection, char *option);
int ConnectedComponentLabeling(char *fn, char *option);
int iI = 0;
double dbTimeSum = 0.0f;
int iStepCount = 0;

int read_pbm(char *fn, int *pwidth, int *pheight, char *option)
{
	FILE *f = fopen(fn, "r");
	int i, x, y;
	char buf[256];

	if(f == NULL) return -1;

	do
	{
		fgets(buf, 256, f);
	} while(buf[0] == '#');

	if(buf[0] != 'P' || buf[1] != '1')
	{
		fclose(f);
		return -1;
	}

	do
	{
		fgets(buf, 256, f);
	} while(buf[0] == '#');

	sscanf(buf, "%d %d", pwidth, pheight);
	*pwidth += 2;
	*pheight += 2;
	bitmap = (unsigned char**)malloc(*pheight * sizeof(unsigned char*));
	labelmap = (int**)malloc(*pheight * sizeof(int*));

	if(option == "1")
	{
		contourmap = (int**)malloc(*pheight * sizeof(int*));

		if(bitmap == NULL|| labelmap == NULL || contourmap == NULL)
		{
			fclose(f);
			return -2;
		}
	}
	else
	{
		if(bitmap == NULL|| labelmap == NULL)
		{
			fclose(f);
			return -2;
		}
	}

	for(y = 0; y < *pheight; y++)
	{
		bitmap[y] = (unsigned char*)malloc(*pwidth * sizeof(unsigned char));
		labelmap[y] = (int*)malloc(*pwidth * sizeof(int));

		if(option == "1")
		{
			contourmap[y] = (int*)malloc(*pwidth * sizeof(int));

			if(bitmap[y] == NULL || labelmap[y] == NULL || contourmap[y] == NULL)
			{
				fclose(f);
				return -2;
			}
		}
		else
		{
			if(bitmap[y] == NULL || labelmap[y] == NULL)
			{
				fclose(f);
				return -2;
			}
		}

		memset(bitmap[y], 0, *pwidth);
		memset(labelmap[y], 0, *pwidth * sizeof(int));
		if(option == "1") memset(contourmap[y], 0, *pwidth * sizeof(int));
	}

	for(y = 1; y <= *pheight - 2; y++)
	{
		for(x = 1; x <= *pwidth - 2; x++)
		{
			fscanf(f, "%d", &i);
			bitmap[y][x] = (unsigned char)i;
		}
	}

	fclose(f);
	return 1;
}

int write_rlt(char *fn, int cccnt, int width, int height, char *option)
{
	int cnt, i, x, y;
	char buf[256];
	FILE *f;

	width -= 2;
	height -= 2;
	strcpy(buf, fn);
	strcat(buf, ".lab");

	if(f = fopen(buf, "wt"))
	{
		cnt = (int)log10((double)cccnt) + 2;
		sprintf(buf, "%%%dd", cnt);
		fprintf(f, "CC# %d\n", cccnt);
		fprintf(f,  "%d %d\n", width, height);

		for(y = 1; y <= height; y++)
		{
			for(x = 1; x <= width; x++)
			{
				if(labelmap[y][x] > 0)
				{
					fprintf(f, buf, labelmap[y][x]);
				}
				else
				{
					fprintf(f, buf, 0);
				}
			}

			fprintf(f, "\n");
		}

		fclose(f);
	}

	if(option == "1")
	{
		strcpy(buf, fn);
		strcat(buf, ".ctr");

		if(f = fopen(buf, "wt"))
		{
			cnt = (int)log10((double)cccnt) + 2;
			sprintf(buf, "%%%dd", cnt);
			fprintf(f, "CC# %d\n", cccnt);
			fprintf(f,  "%d %d\n", width, height);

			for(y = 1; y <= height; y++)
			{
				for(x = 1; x <= width; x++)
				{
					if(contourmap[y][x] > 0)
					{
						fprintf(f, buf, contourmap[y][x]);
					}
					else
					{
						fprintf(f, buf, 0);
					}
				}

				fprintf(f, "\n");
			}

			fclose(f);
		}
	}

	return 1;
}

void Tracer(int *cy, int *cx, int *tracingdirection)
{
	int i, y, x;

	for(i = 0; i < 7; i++)
	{
		y = *cy + SearchDirection[*tracingdirection][0];
		x = *cx + SearchDirection[*tracingdirection][1];

		if(bitmap[y][x] == 0)
		{
			labelmap[y][x] = -1;
			*tracingdirection = (*tracingdirection + 1) % 8;
			//iStepCount++;
		}
		else
		{
			*cy = y;
			*cx = x;
			break;
		}
	}
}

void ContourTracing(int cy, int cx, int labelindex, int tracingdirection, char *option)
{
	char tracingstopflag = 0, SearchAgain = 1;
	int fx, fy, sx = cx, sy = cy;

	Tracer(&cy, &cx, &tracingdirection);
	if(option == "1") contourmap[cy][cx] = labelindex;

    if (cx != sx || cy != sy)
    {
		fx = cx;
		fy = cy;

		while(SearchAgain)
		{
			tracingdirection = (tracingdirection + 6) % 8;
			labelmap[cy][cx] = labelindex;
			Tracer(&cy, &cx, &tracingdirection);
			if(option == "1") contourmap[cy][cx] = labelindex;

			if(cx == sx && cy == sy)
			{
				tracingstopflag = 1;
			}
			else if(tracingstopflag)
			{
				if(cx == fx && cy == fy)
				{
					SearchAgain = 0;
				}
				else
				{
					tracingstopflag = 0;
				}
			}
		}
	}
}

int ConnectedComponentLabeling(char *fn, char *option)
{
	int height, width, cx, cy, tracingdirection, ConnectedComponentsCount = 0, labelindex = 0;
	char buf[256];
    LARGE_INTEGER litmp; 
    LONGLONG QPart1,QPart2;
    double dfMinus, dfFreq, dfTim; 

	if(read_pbm(fn, &width, &height, option) != 1)
	{
		printf("File not found");
		return -1;
	}


    QueryPerformanceFrequency ( &litmp );
    dfFreq = (double) litmp.QuadPart;
    QueryPerformanceCounter ( &litmp );
    QPart1 = litmp.QuadPart;

	for(cy = 1; cy < height - 1; cy++)
	{
		for(cx = 1, labelindex = 0; cx < width - 1; cx++)
		{
			if(bitmap[cy][cx] == 1)// black pixel
			{
				if(labelindex != 0)// use pre-pixel label
				{
					labelmap[cy][cx] = labelindex;
				}
				else
				{
					labelindex = labelmap[cy][cx];

					if(labelindex == 0)
					{
						labelindex = ++ConnectedComponentsCount;
						tracingdirection = 0;
						ContourTracing(cy, cx, labelindex, tracingdirection, option);// external contour
						labelmap[cy][cx] = labelindex;
					}
				}
			}
			else if(labelindex != 0)// white pixel & pre-pixel has been labeled
			{
				if(labelmap[cy][cx] == 0)
				{
					tracingdirection = 1;
					ContourTracing(cy, cx - 1, labelindex, tracingdirection, option);// internal contour
				}

				labelindex = 0;
			}
		}
	}

    QueryPerformanceCounter(&litmp);
    QPart2 = litmp.QuadPart;
    dfMinus = (double)(QPart2-QPart1);
    dfTim = dfMinus / dfFreq;
    dfTim = dfTim * 1000.0f;
    printf("Processing Time: %f milliseconds\n", dfTim);
    dbTimeSum += dfTim;

    printf("CC# %d.\n", ConnectedComponentsCount);
    cx = strlen(fn);
	memcpy(buf, fn, cx - 4);
	buf[cx - 4] = '\0';
	strcat(buf, "_");
	strcat(buf, option);
	write_rlt(buf, ConnectedComponentsCount, width, height, option);

	//printf("Step Count: %d\n", iStepCount);

	for(cy = 0; cy < height; cy++)
	{
		free(bitmap[cy]);
		free(labelmap[cy]);

		if(option == "1")
		{
			free(contourmap[cy]);
		}
	}

	free(bitmap);
	free(labelmap);

	if(option == "1")
	{
		free(contourmap);
	}
    
	return 1;
}

void main(int argc, char **argv)
{
    if (argc == 1)
    {
        printf("**************************************************************************************\n");
        printf("* F. Chang, C. J. Chen, and C. J. Lu                                                 *\n");
        printf("*====================================================================================*\n");
        printf("* A Linear-Time Component-Labeling Algorithm Using Contour Tracing Technique.        *\n");
        printf("* Computer Vision and Image Understanding, vol. 93, no. 2, Feb. 2004, pp. 206 - 220. *\n");
        printf("**************************************************************************************\n");
        printf("* Please set parameter. The parameter 1 is a PBM format file.                        *\n");
        printf("* Example: CCL sample.pbm                                                            *\n");
        printf("**************************************************************************************\n");
    }
    else if (argc > 1)
    {
        if (argv[1] != NULL)
        {
            printf("**************************************************************************************\n");
            printf("* F. Chang, C. J. Chen, and C. J. Lu                                                 *\n");
            printf("*====================================================================================*\n");
            printf("* A Linear-Time Component-Labeling Algorithm Using Contour Tracing Technique.        *\n");
            printf("* Computer Vision and Image Understanding, vol. 93, no. 2, Feb. 2004, pp. 206 - 220. *\n");
            printf("**************************************************************************************\n");
			dbTimeSum = 0.0f;
			for (iI = 0; iI < 10; iI++)
            {
				iStepCount = 0;
                printf("No. %d\n", iI+1);
                ConnectedComponentLabeling(argv[1], "1");
                printf("\n");
            }
			printf("Total of The Processing Time: %f milliseconds\n", dbTimeSum);
			printf("Average Processing Time: %f milliseconds\n", (dbTimeSum / 10.0f));
        }
    }
    system("pause");
}
