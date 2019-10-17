#include <GL/glut.h>

GLfloat xf, yf, win;
GLint view_w, view_h;

void Desenha(void){
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
                   
	glClear(GL_COLOR_BUFFER_BIT);

	glBegin(GL_POLYGON);
		glVertex2f(0.0f, 0.0f);
		glVertex2f(xf, 0.0f);
		glVertex2f(xf, yf);
		glVertex2f(0.0f, yf);               
	glEnd();
	glFlush();

}



void Inicializa (void){   

	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
	xf=50.0f;
	yf=50.0f;
	win=250.0f;
}

void AlteraTamanhoJanela(GLsizei w, GLsizei h){

	glViewport(0, 0, w, h);
	view_w = w;
	view_h = h;                   

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D (-win, win, -win, win);
}

void GerenciaTeclado(unsigned char key, int x, int y){
	switch (key) {
		case 'R': 
		case 'r':// muda a cor corrente para vermelho
			glColor3f(1.0f, 0.0f, 0.0f);
			break;
		case 'G':
		case 'g':// muda a cor corrente para verde
			glColor3f(0.0f, 1.0f, 0.0f);
			break;
		case 'B':
		case 'b':// muda a cor corrente para azul
			glColor3f(0.0f, 0.0f, 1.0f);
			break;
	}
	glutPostRedisplay();
}
    

void GerenciaMouse(int button, int state, int x, int y){
	if (button == GLUT_LEFT_BUTTON)
		if (state == GLUT_DOWN) {
			xf = ( (2 * win * x) / view_w) - win;
			yf = ( ( (2 * win) * (y-view_h) ) / -view_h) - win;
		}
	glutPostRedisplay();
}

void TeclasEspeciais(int key, int x, int y){
	if(key == GLUT_KEY_UP) {
		win -= 20;
		glMatrixMode(GL_PROJECTION);
		glLoadIdentity();
		gluOrtho2D (-win, win, -win, win);
	}
	if(key == GLUT_KEY_DOWN) {
		win += 20;
		glMatrixMode(GL_PROJECTION);
		glLoadIdentity();
		gluOrtho2D (-win, win, -win, win);
	}
	glutPostRedisplay();
}

int main(int argc, char** argv){
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(350,300);
	glutInitWindowPosition(10,10);
	glutCreateWindow("Exemplo de Interacao");
	glutDisplayFunc(Desenha);
	glutReshapeFunc(AlteraTamanhoJanela);
	glutKeyboardFunc(GerenciaTeclado);
	glutMouseFunc(GerenciaMouse);
	glutSpecialFunc(TeclasEspeciais);     
	Inicializa();
	glutMainLoop();

}
