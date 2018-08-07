#include <stdint.h>
#include <inttypes.h>
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <unistd.h>
#include <dirent.h>
#include <string.h>
#include <unistd.h>
#include <stdio.h>
#include <dirent.h>
#include <string.h>
#include <sys/stat.h>
#include <stdlib.h>


void dirwalk(char *,int);
     int hcounter =0; numfiles=0;ROOT(char[][100], int);
    char hashes[][100];thash[][100];char * readFile(char *);
void hash(char *);
int main()
{
  int userInput;
    char *Fs[500];
    while(1)
{
        printf(" Enter a to Add leaf{file)");
        printf(" Enter b to Root hash");
        scanf("%d", &userInput);
        if(userInput==0)
        {
            printf("Enter txt pathFile");

            fflush(stdin);

            char buffer[1000];  char *point;

            scanf("%s",&buffer);

            point=strtok(buffer, ",");
            char len=0;
            while(point)
            {
                Fs[len]= point;
                len++;
                point=strtok(NULL, ",");
            }
            for(int i=0; i<len; i++)
            {
                char *filedata = readFile(Fs[i]);

                if(strcmp(filedata,",") != 0)
                {
                    hash(filedata);
                }
            }
        }
        if(userInput==1)
        {
            ROOT(hashes,numfiles);

            hcounter++;
        }

    }
{
    if(userInput=5){
printf("Directory scan of C:/Users/ghon/Desktop/f:\n");
dirwalk("C:/Users/ghon/Desktop/f",0);
printf("done.\n");
return(0);
}

void dirwalk(char *dir,int depth)
{
DIR *dp;
char str[30];
char name[30];
struct dirent *entry;
struct stat statbuf;

if((dp = opendir(dir)) == NULL)
{
fprintf(stderr,"Cannot open directory: %s\n",dir);
return;
}

chdir(dir);

while((entry = readdir(dp)) != NULL)
{
lstat(entry->d_name,&statbuf);
if(S_ISDIR(statbuf.st_mode))
{
/* Found a directory ,but ignore . and .. */
if(strcmp(".",entry->d_name) ==0 || strcmp("..",entry->d_name) == 0)
continue;
printf("%*s %s/\n",depth,"",entry->d_name);

/*funtion is called recursively at a new indent level */
dirwalk(entry->d_name,depth + 4);
}
else
if(S_ISREG(statbuf.st_mode))
printf("%*s %s \n",depth,"",entry->d_name); /*Here you need to add u'r code*/
strcpy(str,entry->d_name);
strcpy(name,str);

printf("\nFile name is %s\n",name);
}

chdir("..");
closedir(dp);
}
}

    return 0;
}
char *readFile(char *filename)
{
    fflush(stdin);
    if( access( filename, F_OK ) )
    {

        return filename;
    }

    char *source = NULL;
    FILE *fp = fopen(filename, "rt");

    /* Go to the end of the file. */
    if (fseek(fp, 0L, SEEK_END) == 0)
    {
        long bufsize = ftell(fp);



        if (bufsize == -1) {  }
        source = malloc(sizeof(char) * (bufsize + 1));


if (fseek(fp, 0L, SEEK_SET) != 0) {  }


        size_t newLen = fread(source, sizeof(char), bufsize, fp);

        if ( ferror( fp ) != 0 )
        {
            fputs("Error reading file", stderr);
        }
        else
        {
            source[newLen++] = '\0';
        }
    }
    fclose(fp);
    return source;
}
void hash(char *filedata)
{
            char hashedfile[50];char filehash[50];

    SHA1(hashedfile,filedata,strlen(filedata));
                int i;

            printf("   ");
    for(i=0; i<20; i++)

    {
                printf("%02x", (int) hashedfile[i]&0xff);
        sprintf(filehash + (2*i),"%02x", hashedfile[i]&0xff);
    }
    printf("\n");
        numfiles++;
            strcpy(hashes[numfiles-1],filehash);
}

int ROOT(char hashes_param[][100], int numnodes)
{
                char Hsum[100][100];
        int SUM = 0;
    /*
    printf("\n");
    printf("                              COMPUTING THE ROOT HASH \n");
    */

    if(numnodes==1)

    {
        printf("  \n");
            printf("*******************************\n");
            printf("\n");
            printf("Root is: %s\n", hashes[0]);
                    strcpy(thash[hcounter], hashes[0]);
                    printf(" \n");
            printf("*********************************\n");

        return 1;
    }

            int i = 0;
    while(i<numnodes)
    {
        if(i == numnodes -1)
        {

            strcpy(Hsum[SUM],hashes[numnodes-1]);
                SUM++;

            char node[100];
        char result[100];
    SHA1(node,hashes[numnodes-1],strlen(hashes[numnodes-1]));
                fflush(stdin);

            printf("\n");
            return 1 + ROOT(Hsum,SUM);
        }
        else
        {
            char *output = malloc(strlen(hashes[i]) + strlen(hashes[i+1]) + 1);
            strcpy(output, hashes[i]);
                                strcat(output, hashes[i+1]);

                        printf("\n");
             printf("\n");
            printf("                              COMPUTING THE ROOT HASH \n");
            printf("\n");

             printf("      LEFT HASH SHA1                                  RIGHT HASH SHA1  \n");
             printf("%s + %s ",hashes[i],hashes[i+1]);

 printf("\n");
                    char node[50];
            char HAS[50];
                    SHA1(node,output,strlen(output));
                fflush(stdin);
            for(int i=0; i<20; i++)
            {
                sprintf(HAS + (2*i),"%02x", node[i]&0xff);
            }

                                printf("NEW HASH: %s\n",HAS);
                        strcpy(Hsum[SUM],HAS);
                    SUM++;
            i+=2;
        }
    }
    return
    1 + ROOT(Hsum,SUM);












}
