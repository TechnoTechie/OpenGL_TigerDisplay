#include <stdlib.h>
#include <stdio.h>
#include "./Tiger.h"
#include <GL/glut.h>

static const char FILENAME[] = "Tiger.obj";

void display(void)
{
	glClear(GL_COLOR_BUFFER_BIT);	// �ㅼ젙��諛곌꼍�됱쑝濡��붾㈃ 珥덇린��
	float scale_factor = 1.0;	// 臾쇱껜 �ш린 議곗젅���꾪븳 �뺣� 鍮꾩쑉
	glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(0.0, 0.0, 0.0, 0.0, 0.0, -1.0, 0.0, 1.0, 0.0);	// �쒖젏 �ㅼ젙
    glPushMatrix();
    glScalef(scale_factor, scale_factor, scale_factor); //*/
	
    // Fill this area to render your objects��	//enable vertex coordinate array when glDrawArrays is called
	glEnableClientState(GL_VERTEX_ARRAY);
	//enable normal array when glDrawArrays is called
	glEnableClientState(GL_NORMAL_ARRAY);
	//enable texture coordinate array when glDrawArrays is called
	glEnableClientState(GL_TEXTURE_COORD_ARRAY);
	
	// set input data to arrays
	glVertexPointer(3, GL_FLOAT, 0, TigerVerts);
	glNormalPointer(GL_FLOAT, 0, TigerNormals);
	glTexCoordPointer(2, GL_FLOAT, 0, TigerTexCoords);

	// draw data
	glDrawArrays(GL_TRIANGLES, 0, TigerNumVerts);
	
    glPopMatrix();
    glutSwapBuffers();
}

void reshape(int width, int height)
{
	
	glViewport(0, 0, width, height);
    /*
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0, width, 0, height);
    glMatrixMode(GL_MODELVIEW);
	//*/
	/*
	glViewport(0, 0, width, height);
    glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
    glFrustum(-5.0, 5.0, -5.0, 5.0, 0.5, 20.0); //*/
}

void idle(void)
{
    glutPostRedisplay();
}

void processObj(FILE *file){

}
FILE openFile(char *filename){
	FILE *file;
	char *selection;

	file = fopen(FILENAME, "r");

	if (file == NULL){
		selection = (char*) malloc(sizeof(char));
		printf("File \"%s\" could not be opened.", FILENAME);
		fclose(file);
		printf("Select new file or type 'quit' to exit");
		gets(selection);
		if(!strcmp(selection, "quit"))
			file = openFile(selection); //recursive call to get file name
		free(selection);
	}
	return FILE;
}

int main(int argc, char** argv)
{
	FILE *file;
	char *stringBuffer;

    glutInit(&argc, argv);
    stringBuffer = (char*) malloc(sizeof(char));
    file = openFile(FILENAME);
    if (file == NULL) return 1; //user typed 'quit'
    
    processObj(file);

    glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE | GLUT_DEPTH);
    glutInitWindowSize(640, 480);
    
    glutCreateWindow("ID_Assign1");
    //glClearColor(1.0, 1.0, 1.0, 1.0);
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutIdleFunc(idle);
    
    glutMainLoop();
    return 0;
}
