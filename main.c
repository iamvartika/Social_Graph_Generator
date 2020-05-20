#include<stdio.h>

#include<stdlib.h>

#include<string.h>

#include <GL/glut.h>

#include<math.h>

int px[100], qy[100], pk, vertex = 0;
char str[100];
int ar[100][100];
int i, j, k;
int m = 0;
int buttoncount;
int person;
int rows;
int closefriend[100];
int rightcount=0;
int mouse3butt;
int mouse3butt_m;
int graph[100][100];
struct weigh {
  int weight;
  int weight2;

};
struct weigh wei[100][100];
void Line() {
  glColor3f(0.0, 1.0, 0.0);
  glBegin(GL_LINES);
  glVertex2f(px[i], qy[i]);
  glVertex2f(px[j], qy[j]);
  glEnd();
  glFlush();

}
void onExit() {}
void plot1(int xcen, int ycen, int xcor, int ycor) {
  glColor3f(0.0, 1.0, 0.0);
  glBegin(GL_POINTS);
  glVertex2f(xcen + xcor, ycen + ycor);
  glVertex2f(xcen - xcor, ycen + ycor);
  glVertex2f(xcen + xcor, ycen - ycor);
  glVertex2f(xcen - xcor, ycen - ycor);
  glVertex2f(xcen + ycor, ycen + xcor);
  glVertex2f(xcen - ycor, ycen + xcor);
  glVertex2f(xcen + ycor, ycen - xcor);
  glVertex2f(xcen - ycor, ycen - xcor);
  glEnd();
  glFlush();
}

void circle(int x, int y, int r1) {

  int a = 0;
  int x1 = 0;
  int y1 = r1;
  pk = 1 - r1;
  glColor3f(0.0, 1.0, 0.0);

  while (x1 < y1) {

    if (pk < 0) {

      pk += 2 * x1 + 3;
      ++x1;
    } else {

      pk += 2 * (x1 - y1) + 5;
      ++x1;
      --y1;

    }
    plot1(x, y, x1, y1);
  }

}

void mouse(int button, int state, int mousex, int mousey) {
  if (button == GLUT_LEFT_BUTTON && state == GLUT_UP) {
    vertex = vertex + 1;
    px[vertex] = mousex;
    qy[vertex] = 480 - mousey;
    circle(px[vertex], qy[vertex], 30);

    sprintf(str, "%d", vertex);
    glRasterPos2i(mousex, 480 - mousey);
    for (int i = 0; i < strlen(str); ++i) {
      glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, str[i]);
    }
    glFlush();
    printf("%d\n", vertex);
    if (vertex == 10) {
      for (i = 1; i <= 10; ++i) {
        for (j = 1; j <= 10; ++j) {
          if (graph[i][j] != 0) {
            Line();
          }
        }
      }
    }

  }

  //printf("%d\n",vertex);

}
/*if(button==GLUT_LEFT_BUTTON && state==GLUT_UP)
{
exit();
}*/

void myinit() {
  glClear(GL_COLOR_BUFFER_BIT);
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  glClearColor(0.0, 0.0, 0.0, 0.0);
  gluOrtho2D(0.0, 640, 0.0, 480.0);

}
void display() {
  glPointSize(2.0);

}
void display2() {
  glPointSize(2.0);

}
void myinit2() {
  glClear(GL_COLOR_BUFFER_BIT);
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  glClearColor(0.0, 0.0, 0.0, 0.0);
  gluOrtho2D(0.0, 640, 0.0, 480.0);
  glColor3f(0.0, 1.0, 0.0);

}
void mouse2(int button, int state, int x, int y)
 {
  if (button == GLUT_LEFT_BUTTON && state == GLUT_UP) {
    if (buttoncount == 0) {
      char str[100] = "enter the number you want to enter";
      //str="enter the no u want to enter";
      //sprintf(str,"%s",vertex); 
      glRasterPos2i(x, 480 - y);
      for (int i = 0; i < strlen(str); ++i) {
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, str[i]);
      }
      glFlush();
    }

    if (buttoncount == 1) {
      char str2[100];
      sprintf(str2, "%d", person);
      glRasterPos2i(x, 480 - y);
      for (int i = 0; i < strlen(str2); ++i) {
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, str2[i]);
      }
      glFlush();
    }

    ++buttoncount;
  }
  if (button == GLUT_RIGHT_BUTTON && state == GLUT_UP)
 {
    if(rightcount==0)
 {
char per[100]="person";
char suggest[100]="suggestions";
char close[100]="closefriends";
char all[100]="allfriends";
glRasterPos2i(x, 480 - y);
      for (int i = 0; i < strlen(per); ++i) {
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, per[i]);
      }
      glFlush();
glRasterPos2i(x+150, 480 - y);
      for (int i = 0; i < strlen(suggest); ++i) {
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, suggest[i]);
      }
      glFlush();
glRasterPos2i(x+300, 480 - y);
for (int i = 0; i < strlen(close); ++i) {
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, close[i]);
      }
      glFlush();
glRasterPos2i(x+450, 480 - y);
for (int i = 0; i < strlen(all); ++i) {
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, all[i]);
      }
      glFlush();
    

}
if(rightcount==1){
    for (j = 1; j <= rows; ++j) {
      if (wei[person][j].weight != 0) {
        char str3[100];
        sprintf(str3, "%d[weight=%d\n]", j, wei[person][j].weight);
        glRasterPos2i(x, 480 - y - m);
        for (int i = 0; i < strlen(str3); ++i) {
          glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, str3[i]);
        }
        glFlush();
        m = m + 50;
      }
}
m=0;

      //printf("%d[weight=%d]\n",j,wei[person][j].weight);
}
if(rightcount==2)
{
char str4[100];
       
  for(j=1;j<=rows;++j)
  {
  if(closefriend[person]==wei[person][j].weight2)
  {
  sprintf(str4,"%d",j);
glRasterPos2i(x, 480 - y - m);
       for (int i = 0; i < strlen(str4); ++i) {
          glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, str4[i]);
        }
        glFlush();
        m = m + 50;
  }
  
  

}
m=0;
  }
if(rightcount==3)
{
char str5[100];
for(j=1;j<=rows;++j)
{
if(ar[person][j]==1)
{
 sprintf(str5,"%d",j);
glRasterPos2i(x, 480 - y - m);
       for (int i = 0; i < strlen(str5); ++i) {
          glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, str5[i]);
        }
        glFlush();
        m = m + 50;


}
}
m=0;
}
++rightcount;
}
}
void display3() {
  glPointSize(2.0);

}

void myinit3() {
  glClear(GL_COLOR_BUFFER_BIT);
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  glClearColor(0.0, 0.0, 0.0, 0.0);
  gluOrtho2D(0.0, 640, 0.0, 480.0);
  glColor3f(0.0, 1.0, 0.0);

}
void mouse3(int button, int state, int x, int y) 
{
if(button==GLUT_LEFT_BUTTON && state==GLUT_LEFT)
{
char person2[100];
char allfriend[100];
char closefriend[100];
if(mouse3butt==0){
circle(x,480-y,30);
sprintf(person2,"%d",person);
glRasterPos2i(x, 480 - y);
       for (int i = 0; i < strlen(person2); ++i) {
          glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, person2[i]);
        }
        glFlush();
}
if(mouse3butt==1)
{
for(i=1;i<=rows;++i)
{
if(graph[person][i]!=0)
{
circle(x,480-y-mouse3butt_m,30);
sprintf(allfriend,"%d",i);
glRasterPos2i(x, 480 - y-mouse3butt_m);
       for (int i = 0; i < strlen(allfriend); ++i) {
          glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, allfriend[i]);
        }
        glFlush();
}
mouse3butt_m=mouse3butt_m+50;
}
mouse3butt_m=0;
}
/*if(mouse3butt==2)
{
for(i=1;i<=rows;++i)
{
if(closefriend[person]==wei[person][i].weight2)
{
printf("closefriend");
circle(x,480-y-mouse3butt_m,30);
sprintf(closefriend,"%d",i);
glRasterPos2i(x, 480 - y-mouse3butt_m);
       for (int i = 0; i < strlen(closefriend); ++i)
 {
          glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,closefriend[i]);
        }
        glFlush();
}
mouse3butt_m=mouse3butt_m+50;
}
mouse3butt_m=0;
}*/
mouse3butt=mouse3butt+1;
}
}
struct info {
  int id;
  char name[100];
  int age;
  char city[100];
  char profession[100];
  char food[100];
  char sports[100];
  char movie[100];
  char travelling[100];
  char music[100];
  char fashion[100];
};
/*struct weigh
{
int weight;
};*/
int main(int argc, char ** argv)
 {
  glutInit( & argc, argv);
  glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
  
  /*GLint WindowID1, WindowID2;                  // window ID numbers

  glutInitWindowSize(250.0, 250.0);           // set a window size
  glutInitWindowPosition(50,50);              // set a window position
  WindowID1 = glutCreateWindow("Window One"); // Create window 1

  glutInitWindowSize(500.0, 250.0);           // set a window size
  glutInitWindowPosition(500,50);             // set a window position
  WindowID2 = glutCreateWindow("Window Two"); // Create window 2

  	/*glutCreateWindow("TRANSLATION");
  	glutDisplayFunc(display);
          glutMouseFunc(mouse);
         
  	myinit();
          glutMainLoop();

  */

  FILE * fp;

  fp = fopen("minor1dataset.csv", "r");

  char c;
  char ch;

  if (fp == NULL) {
    printf("Could not open file ");
    return 0;
  }
  c = fgetc(fp);
  //counting the no of rows

  while (c != EOF) {
    if (c == '\n')
      rows = rows + 1;
    c = fgetc(fp);
  }
  printf("%d\n", rows);
  fclose(fp);
  int coloums = 1;
  fp = fopen("minor1dataset.csv", "r");
  c = fgetc(fp);
  while (c != '\n') {
    if (c == ',') {
      coloums = coloums + 1;
      c = fgetc(fp);
    }
    c = fgetc(fp);
  }
  printf("%d\n", coloums);

  fclose(fp);
  fp = fopen("minor2dataset.csv", "r");

  for (i = 1; i <= rows; ++i) {
    for (j = 1; j <= rows; ++j) {
      if (j >= 1 && j <= 9)
        fscanf(fp, "%d,", & ar[i][j]);
      else if (j == 10)
        fscanf(fp, "%d", & ar[i][j]);

    }

  }
for(i=1;i<=rows;++i)
{
for(j=1;j<=rows;++j)
{
graph[i][j]=ar[i][j];
}
}
  for (i = 1; i <= rows; ++i) {
    for (j = 1; j <= rows; ++j) {

      printf("%d", graph[i][j]);

    }
    printf("\n");
  }

  i = 1;

  while (i <= 10) {
    j = 1;
    while (j <= 10) {
      if (ar[i][j] != 1) {
        ++j;
      } else {
        k = 1;
        while (k <= 10) {
          if (ar[j][k] != 1 || k == i || ar[i][k] == 1) {
            ++k;
          } else {
            if (ar[j][k] == 1) {
              if (ar[i][k] == 0) {
                ar[i][k] = ar[i][j] + ar[j][k];

              }

            }
            ++k;
          }
        }
        ++j;

      }

    }
    ++i;

  }
  printf("\n");
  for (int i = 1; i <= rows; ++i) {
    for (int j = 1; j <= rows; ++j) {
      printf("%d", ar[i][j]);
    }
    printf("\n");

  }

  struct info inf[100];
  fp = fopen("minor1dataset.csv", "r");

  for (i = 1; i <= rows; ++i) {
    fscanf(fp, "%d,%[^,],%d,%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%s", & inf[i].id, inf[i].name, & inf[i].age, inf[i].city, inf[i].profession, inf[i].food, inf[i].sports, inf[i].movie, inf[i].travelling, inf[i].music, inf[i].fashion);

  }
  for (int i = 1; i <= rows; ++i) {
    printf("%d %s %d %s %s %s %s %s %s %s %s", inf[i].id, inf[i].name, inf[i].age, inf[i].city, inf[i].profession, inf[i].food, inf[i].sports, inf[i].movie, inf[i].travelling, inf[i].music, inf[i].fashion);
    printf("\n");
  }
  fclose(fp);
  //struct weigh wei[100][100];
  for (i = 1; i <= rows; ++i) {
    for (j = 1; j <= rows; ++j) {
      wei[i][j].weight = 0;

      if (ar[i][j] == 2) {
        wei[i][j].weight = 0;
        if ((inf[i].age >= 16 && inf[i].age <= 19) && (inf[j].age >= 16 && inf[j].age <= 19)) {
          wei[i][j].weight = wei[i][j].weight + 1;

        }
        if ((inf[i].age >= 20 && inf[i].age <= 24) && (inf[j].age >= 20 && inf[j].age <= 24)) {
          wei[i][j].weight = wei[i][j].weight + 1;

        }
        if ((inf[i].age >= 25 && inf[i].age <= 28) && (inf[j].age >= 25 && inf[j].age <= 28)) {
          wei[i][j].weight = wei[i][j].weight + 1;

        }
        if (strcmp(inf[i].city, inf[j].city) == 0) {

          wei[i][j].weight = wei[i][j].weight + 1;

        }
        if (strcmp(inf[i].profession, inf[j].profession) == 0) {
          wei[i][j].weight = wei[i][j].weight + 1;

        }
        if (strcmp(inf[i].food, inf[j].food) == 0) {
          wei[i][j].weight = wei[i][j].weight + 1;

        }
        if (strcmp(inf[i].sports, inf[j].sports) == 0) {
          wei[i][j].weight = wei[i][j].weight + 1;

        }
        if (strcmp(inf[i].movie, inf[j].movie) == 0) {
          wei[i][j].weight = wei[i][j].weight + 1;

        }
        if (strcmp(inf[i].travelling, inf[j].travelling) == 0) {
          wei[i][j].weight = wei[i][j].weight + 1;

        }
        if (strcmp(inf[i].music, inf[j].music) == 0) {
          wei[i][j].weight = wei[i][j].weight + 1;

        }
        if (strcmp(inf[i].fashion, inf[j].fashion) == 0) {
          wei[i][j].weight = wei[i][j].weight + 1;
        }
        printf("the weight of wei[%d][%d].weight is %d\n", i, j, wei[i][j].weight);
      }

    }

  }
  for (int i = 1; i <= rows; ++i) {
    for (int j = 1; j <= rows; ++j) {
      printf("weight[%d][%d] %d\n", i, j, wei[i][j].weight);
    }
  }

  int n;
  printf("enter the person id and we will display the suggestion");
  scanf("%d", & person);
  for (j = 1; j <= rows; ++j) {
    if (wei[person][j].weight != 0) {
      printf("%d[weight=%d]\n", j, wei[person][j].weight);
    }
  }
  for (i = 1; i <= rows; ++i) {
    for (j = 1; j <= rows; ++j) {
      wei[i][j].weight2 = 0;

      if (ar[i][j] == 1) {
        wei[i][j].weight2 = 0;
        if ((inf[i].age >= 16 && inf[i].age <= 19) && (inf[j].age >= 16 && inf[j].age <= 19)) {
          wei[i][j].weight2 = wei[i][j].weight2 + 1;

        }
        if ((inf[i].age >= 20 && inf[i].age <= 24) && (inf[j].age >= 20 && inf[j].age <= 24)) {
          wei[i][j].weight2 = wei[i][j].weight2 + 1;

        }
        if ((inf[i].age >= 25 && inf[i].age <= 28) && (inf[j].age >= 25 && inf[j].age <= 28)) {
          wei[i][j].weight2 = wei[i][j].weight2 + 1;

        }
        if (strcmp(inf[i].city, inf[j].city) == 0) {

          wei[i][j].weight2 = wei[i][j].weight2 + 1;

        }
        if (strcmp(inf[i].profession, inf[j].profession) == 0) {
          wei[i][j].weight2 = wei[i][j].weight2 + 1;

        }
        if (strcmp(inf[i].food, inf[j].food) == 0) {
          wei[i][j].weight2 = wei[i][j].weight2 + 1;

        }
        if (strcmp(inf[i].sports, inf[j].sports) == 0) {
          wei[i][j].weight2 = wei[i][j].weight2 + 1;

        }
        if (strcmp(inf[i].movie, inf[j].movie) == 0) {
          wei[i][j].weight2 = wei[i][j].weight2 + 1;

        }
        if (strcmp(inf[i].travelling, inf[j].travelling) == 0) {
          wei[i][j].weight2 = wei[i][j].weight2 + 1;

        }
        if (strcmp(inf[i].music, inf[j].music) == 0) {
          wei[i][j].weight2 = wei[i][j].weight2 + 1;

        }
        if (strcmp(inf[i].fashion, inf[j].fashion) == 0) {
          wei[i][j].weight2 = wei[i][j].weight2 + 1;
        }
        printf("the weight of wei[%d][%d].weight is %d\n", i, j, wei[i][j].weight2);
      }

    }

  }
  for (int i = 1; i <= rows; ++i) {
    for (int j = 1; j <= rows; ++j) {
      printf("weight[%d][%d] %d\n", i, j, wei[i][j].weight2);
    }
  }
  printf("enter the person primary key.we will display the closest friend");
  int max;
  for (i=1; i<=rows;++i) {
    max = 0;
    for (j =1;j <= rows;++j) {
      if (wei[i][j].weight2 != 0) {
        if (max <= wei[i][j].weight2) {
          max = wei[i][j].weight2;
        }
      }
    }
    printf("max%d\n", max);
    closefriend[i] = max;
    printf("closefriend[%d]=%d\n", i, closefriend[i]);
    printf("rows = %d\n",rows);
  }
  printf("ytf");
  for(i=1;i<=rows;++i)
  {
  for(j=1;j<=rows;++j)
  {
  if(closefriend[i]==wei[i][j].weight2)
  {
  printf("closefriend[%d][%d]=%d\n",i,j,closefriend[i]);
  }
  }
  }
  GLint WindowID1, WindowID2,WindowID3; // window ID numbers

  glutInitWindowSize(640.0, 480.0); // set a window size
  glutInitWindowPosition(50, 50); // set a window position
  WindowID1 = glutCreateWindow("Input");
  glutDisplayFunc(display);
  glutMouseFunc(mouse);
  myinit();
  // Create window 1

  glutInitWindowSize(640.0, 480.0); // set a window size
  glutInitWindowPosition(500, 50); // set a window position
  WindowID2 = glutCreateWindow("output");
 glutDisplayFunc(display2);
 glutMouseFunc(mouse2);
  myinit2();
 // glutDisplayFunc(display);
  // glutMouseFunc(mouse); // Create window 2

  /*glutCreateWindow("Input");
  glutCreateWindow("Output");
  glutDisplayFunc(display);
          glutMouseFunc(mouse);
    */
 // myinit();
WindowID3=glutCreateWindow("input and output");
glutDisplayFunc(display3);
glutMouseFunc(mouse3);
myinit3();
  glutMainLoop();

  //glutMainLoop();
  return 0;

}
