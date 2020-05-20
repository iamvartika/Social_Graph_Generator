#include<stdio.h>
int main() 
{ 
    FILE *fp; 
    int count = 0;
    fp=fopen("minor1dataset.csv","r"); 
    char c;  

    
  
    if (fp==NULL) 
    { 
        printf("Could not open file "); 
        return 0; 
    } 
	c = getc(fp);
  
   while(c!=EOF)
    { 
        if (c =='\n')
            count = count + 1; 
  
     
    
      c = getc(fp);
      }
fclose(fp);
    printf("%d",count); 
  
    return 0; 
} 
