#include <GL/glut.h>

GLfloat angle, fAspect;

void Desenha(void){

	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(0.0f, 0.0f, 1.0f);
	glutWireTeapot(50.0f);
	glutSwapBuffers();
}

void Inicializa (void){ 
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
	angle=45;
}

void EspecificaParametrosVisualizacao(void){

	glMatrixMode(GL_PROJECTION);
	glMatrixMode(GL_PROJECTION);
	gluPerspective(angle,fAspect,0.1,500);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(0,80,200, 0,0,0, 0,1,0);
}

void AlteraTamanhoJanela(GLsizei w, GLsizei h){

	if ( h == 0 ) h = 1;
	glViewport(0, 0, w, h);
	fAspect = (GLfloat)w/(GLfloat)h;
	EspecificaParametrosVisualizacao();

}

void GerenciaMouse(int button, int state, int x, int y){
	if (button == GLUT_LEFT_BUTTON)
		if (state == GLUT_DOWN) {  // Zoom-in
			if (angle >= 10) angle -= 5;
		}
	if (button == GLUT_RIGHT_BUTTON)
		if (state == GLUT_DOWN) {  // Zoom-out
			if (angle <= 130) angle += 5;
		}
	EspecificaParametrosVisualizacao();
	glutPostRedisplay();
}

int main(int argc, char** argv){
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(350,300);
	glutCreateWindow("Visualizacao 3D");
	glutDisplayFunc(Desenha);
	glutReshapeFunc(AlteraTamanhoJanela);
	glutMouseFunc(GerenciaMouse);
	Inicializa();
	glutMainLoop();

}
