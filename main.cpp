#include <windows.h>
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#include <string>

using namespace std;

int screenWidth = 600;
int screenHeight = 600;
bool elegirPersonaje = false;
bool instrucciones = false;
bool menu = true;
bool elegirNivel = false;
bool jugar = false;
bool juegoMaria = false;
bool juegoJuan = false;
int personaje = -1;
int nivel = -1;

void reshape(int width, int height){
    screenHeight = height;
    screenWidth = width;
    glViewport(0.0, 0.0, width, height);
    glLoadIdentity();
}

void drawString(GLfloat x, GLfloat y, string text, GLfloat sizex, GLfloat sizey)
{
    glPushMatrix();
    glTranslatef(x, y, 0);
    glScalef(1/sizex, 1/sizey, 1/152.38);

//imprime caracteres
    for( int i = 0; i<text.length(); i++)
    {
        glutStrokeCharacter(GLUT_STROKE_ROMAN, text[i]);
    }
    glPopMatrix();
}


void display(){
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    if (menu){
        glColor3f (0.5,1.0,0.5);
        glBegin(GL_QUADS);

        glVertex2d(-100, 0);
        glVertex2d(-100, -25);
        glVertex2d(100, -25);
        glVertex2d(100, 0);

        glColor3f (1.0,1,0.5);

        glVertex2d(-100, -30);
        glVertex2d(-100, -55);
        glVertex2d(100, -55);
        glVertex2d(100, -30);

        glColor3f (1.0,0.5,0.5);

        glVertex2d(-100, -60);
        glVertex2d(-100, -85);
        glVertex2d(100, -85);
        glVertex2d(100, -60);

        glEnd();

        glColor3f (0.0,0.0,0.0);

        drawString(-80,55,"Correct", 3, 3);
        drawString(-75,20,"Choice", 3, 3);

        drawString(-15,-15,"Jugar", 12, 12);
        drawString(-20,-45,"Instrucciones", 12, 12);
        drawString(-15,-75,"Salir", 12, 12);
    }
    else if(elegirPersonaje) {
        glColor3f (1.0,0.5,0.5);
        glBegin(GL_QUADS);

        glVertex2d(-100, -80);
        glVertex2d(-100, -95);
        glVertex2d(100, -95);
        glVertex2d(100, -80);

        glColor3f (1.0,0.56,0.74);

        glVertex2d(-80, 60);
        glVertex2d(-80, -30);
        glVertex2d(-10, -30);
        glVertex2d(-10, 60);

        glColor3f (0.0,0.0,1.0);

        glVertex2d(80, 60);
        glVertex2d(80, -30);
        glVertex2d(10, -30);
        glVertex2d(10, 60);

        glEnd();

        glColor3f (0.0,0.0,0.0);
        drawString(-70,75,"Elige Personaje", 6, 6);
        drawString(-65,-45,"Maria", 10, 10);
        drawString(35,-45,"Juan", 10, 10);
        drawString(-20,-93,"Atras", 10, 10);

        if (juegoMaria){
            drawString(-79,-15,"Seleccionada", 10, 10);
        }
        else if (juegoJuan){
            drawString(20,-15,"Seleccionado", 10, 10);
        }

        if(juegoJuan || juegoMaria){
            glColor3f (0.5,1.0,0.5);
            glBegin(GL_QUADS);

            glVertex2d(-100, -60);
            glVertex2d(-100, -75);
            glVertex2d(100, -75);
            glVertex2d(100, -60);

            glEnd();

            glColor3f (0.0,0.0,0.0);
            drawString(-20,-73,"Seguir", 10, 10);
        }
    }
    else if (instrucciones) {
        glColor3f (1.0,0.5,0.5);
        glBegin(GL_QUADS);

        glVertex2d(-100, -80);
        glVertex2d(-100, -95);
        glVertex2d(100, -95);
        glVertex2d(100, -80);

        glEnd();

        glColor3f (0.0,0.0,0.0);
        drawString(-70,75,"Instrucciones", 6, 6);
        drawString(-20,-93,"Atras", 10, 10);
    }
    else if (elegirNivel){
        glColor3f (1.0,0.5,0.5);

        glBegin(GL_QUADS);

        glVertex2d(-100, -80);
        glVertex2d(-100, -95);
        glVertex2d(100, -95);
        glVertex2d(100, -80);

        glColor3f (1.0,1,0.5);

        glVertex2d(-100, 50);
        glVertex2d(-100, 25);
        glVertex2d(100, 25);
        glVertex2d(100, 50);

        glVertex2d(-100, 20);
        glVertex2d(-100, -5);
        glVertex2d(100, -5);
        glVertex2d(100, 20);

        glVertex2d(-100, -10);
        glVertex2d(-100, -35);
        glVertex2d(100, -35);
        glVertex2d(100, -10);

        glEnd();

        glColor3f (0.0,0.0,0.0);

        drawString(-70,75,"Elegir Nivel", 6, 6);
        drawString(-97,51,"Numero Nivel", 15, 15);
        drawString(50,51,"Porcentaje", 15, 15);
        drawString(-95,33,"1er Nivel", 10, 10);
        drawString(50,33,"Incompleto", 15, 15);
        drawString(-95,3,"2ndo Nivel", 10, 10);
        drawString(50,3,"Incompleto", 15, 15);
        drawString(-95,-27,"3er Nivel", 10, 10);
        drawString(50,-27,"Incompleto", 15, 15);
        drawString(-20,-93,"Atras", 10, 10);

        drawString(-30,-53,"Nivel: ", 10, 10);


        if (nivel > 0){
            glColor3f (0.5,1.0,0.5);
            glBegin(GL_QUADS);

            glVertex2d(-100, -60);
            glVertex2d(-100, -75);
            glVertex2d(100, -75);
            glVertex2d(100, -60);

            glEnd();

            glColor3f (0.0,0.0,0.0);
            drawString(-20,-73,"Seguir", 10, 10);
        }
    } else if(jugar) {
        drawString(-70,75,"Jugar", 6, 6);
    }

    glutSwapBuffers();

}

void init(){
    glClearColor(0.5,0.7,1.0,0.0);
    menu = true;
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-100,100, -100,100);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}


void keyboard(unsigned char key, int x, int y){
    switch(key)
    {
        case 'p':
        case 'P':
            display();
            break;

        case 'o':
        case 'O':
            display();
            break;

        case 27:   // escape
            exit(0);
            break;
    }
}

void myMouse(int button, int state, int x, int y)
{
    x = screenWidth-x;
    y = screenHeight-y;

    if(menu){
        if (state == GLUT_DOWN && button == GLUT_LEFT_BUTTON)//boton izquierdo presionado
        {
            if(y <= screenHeight/2 && y >= screenHeight/2 - screenHeight/2*.25) //click dentro del rango de 1/5 de la pantalla
            {
                elegirPersonaje = true;
                instrucciones = false;
                menu = false;
            }
            else if (y <= screenHeight/2 - screenHeight/2*.3 && y >= screenHeight/2 - screenHeight/2*.55){
                elegirPersonaje = false;
                instrucciones = true;
                menu = false;
            }
            else if (y <= screenHeight/2 - screenHeight/2*.6 && y >= screenHeight/2 - screenHeight/2*.85){
                exit(-1);
            }
        }
    }
    else if (elegirPersonaje){
        if (state == GLUT_DOWN && button == GLUT_LEFT_BUTTON)//boton izquierdo presionado
        {
            if(y <= screenHeight/2 - screenHeight/2*.8   && y >= screenHeight/2 - screenHeight/2*.95)
            {
                elegirPersonaje = false;
                instrucciones = false;
                menu = true;
                juegoMaria = false;
                juegoJuan = false;
                personaje = -1;
            }
            else if (y <= screenHeight-screenHeight*.2 && y >= screenHeight - screenHeight*.65){
                if (x >= screenWidth - screenWidth*.45 && x <= screenWidth - screenWidth*.1){
                    juegoMaria = true;
                    juegoJuan = false;
                    personaje = 1; //personaje es MUJEr
                }
                else if (x >= screenWidth - screenWidth*.9 && x <= screenWidth - screenWidth*.55){
                    juegoMaria = false;
                    juegoJuan = true;
                    personaje = 0; //personaje es HOMBRE
                } else {
                    juegoJuan = false;
                    juegoMaria = false;
                }
            }
            if(juegoJuan || juegoMaria){
                if(y <= screenHeight/2 - screenHeight/2*.6   && y >= screenHeight/2 - screenHeight/2*.75) { //SEGUIR
                        elegirNivel = true;
                        elegirPersonaje = false;
                }
            }
        }
    }else if(instrucciones){
        if (state == GLUT_DOWN && button == GLUT_LEFT_BUTTON)//boton izquierdo presionado
        {
            if(y <= screenHeight/2 - screenHeight/2*.8   && y >= screenHeight/2 - screenHeight/2*.95) //click dentro del rango de 1/5 de la pantalla
            {
                elegirPersonaje = false;
                instrucciones = false;
                menu = true;
            }
        }

    } else if (elegirNivel) {
        if (state == GLUT_DOWN && button == GLUT_LEFT_BUTTON)//boton izquierdo presionado
        {
            if(y <= screenHeight-screenHeight*.25 && y >= screenHeight - screenHeight*.375){
                nivel=1;
            }else if(y <= screenHeight-screenHeight*.4 && y >= screenHeight - screenHeight*.525){
                nivel=2;
            }else if(y <= screenHeight-screenHeight*.55 && y >= screenHeight - screenHeight*.675){
                nivel=2;
            }else if(y <= screenHeight/2 - screenHeight/2*.8   && y >= screenHeight/2 - screenHeight/2*.95) {
                elegirNivel = false;
                elegirPersonaje = true;
                nivel = -1;
            }else if(nivel > 0 && y <= screenHeight/2 - screenHeight/2*.6   && y >= screenHeight/2 - screenHeight/2*.75){ //SEGUIR
                    elegirNivel = false;
                    jugar = true;
            }else{
                nivel = -1;
            }
        }
    }

    display();
}


int main(int argc, char **argv){
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowPosition(50, 50);
    glutInitWindowSize(screenWidth, screenHeight);
    glutCreateWindow("CorrectChoice");
    init();
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutKeyboardFunc(keyboard);
    glutKeyboardUpFunc(keyboard);
    glutMouseFunc(myMouse);
    glutMainLoop();
    return 0;
}
