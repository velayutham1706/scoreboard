#include <GL/glut.h>
#include <stdio.h>

int wide = 0, ones = 0, twos = 0, fours = 0, sixes = 0, noballs = 0;
int score = 0, wickets = 0, balls = 0;
int gameOver = 0;

float overs(int balls) {
  int completeOvers = balls / 6;
  int remainingBalls = balls % 6;
  return completeOvers + (remainingBalls / 10.0);
}

void renderText(float x, float y, void *font, const char *str) {
  glRasterPos2f(x, y);
  for (const char *c = str; *c; c++) {
    glutBitmapCharacter(font, *c);
  }
}

void drawBox(float x1, float y1, float x2, float y2, float r, float g,
             float b) {
  glColor3f(r, g, b);
  glBegin(GL_QUADS);
  glVertex2f(x1, y1);
  glVertex2f(x2, y1);
  glVertex2f(x2, y2);
  glVertex2f(x1, y2);
  glEnd();
  glColor3f(1.0f, 1.0f, 1.0f);
}

void drawBox(float x1, float y1, float x2, float y2, float r, float g, float b);

void display() {
  char buffer[128];
  glClear(GL_COLOR_BUFFER_BIT);

  if (gameOver) {
    renderText(-0.3f, 0.0f, GLUT_BITMAP_HELVETICA_18, "Game Over!");
    sprintf(buffer, "Final Score: %d - %d (%.1f)", score, wickets,
            overs(balls));
    renderText(-0.6f, -0.1f, GLUT_BITMAP_HELVETICA_18, buffer);
    glFlush();
    return;
  }

  // Score
  drawBox(-0.95f, 0.75f, 0.95f, 0.9f, 0.2f, 0.3f, 0.6f);
  sprintf(buffer, "Score: %d - %d (%.1f)", score, wickets, overs(balls));
  renderText(-0.8f, 0.8f, GLUT_BITMAP_HELVETICA_18, buffer);

  // Stats for nerds
  printf("\n");
  drawBox(-0.95f, 0.35f, 0.95f, 0.7f, 0.1f, 0.4f, 0.2f);
  sprintf(buffer, "Fours: %d   Sixes: %d", fours, sixes);
  renderText(-0.8f, 0.60f, GLUT_BITMAP_HELVETICA_18, buffer);
  sprintf(buffer, "Ones: %d   Twos: %d", ones, twos);
  renderText(-0.8f, 0.50f, GLUT_BITMAP_HELVETICA_18, buffer);
  sprintf(buffer, "Wides: %d   No balls: %d", wide, noballs);
  renderText(-0.8f, 0.40f, GLUT_BITMAP_HELVETICA_18, buffer);

  renderText(-0.9f, 0.25f, GLUT_BITMAP_HELVETICA_18, "Controls:");
  renderText(-0.9f, 0.15f, GLUT_BITMAP_HELVETICA_18,
             "1 = One   2 = Two   3 = Four   4 = Six");
  renderText(-0.9f, 0.05f, GLUT_BITMAP_HELVETICA_18,
             "5 = Wide  6 = No Ball  7 = Wicket");
  renderText(-0.9f, -0.05f, GLUT_BITMAP_HELVETICA_18, "8 = Exit");

  glFlush();
}

void keyboard(unsigned char key, int x, int y) {
  if (gameOver && key != '8')
    return;

  switch (key) {
  case '1':
    score += 1;
    ones++;
    balls++;
    break;
  case '2':
    score += 2;
    twos++;
    balls++;
    break;
  case '3':
    score += 4;
    fours++;
    balls++;
    break;
  case '4':
    score += 6;
    sixes++;
    balls++;
    break;
  case '5':
    score += 1;
    wide++;
    break;
  case '6':
    score += 1;
    noballs++;
    break;
  case '7':
    wickets++;
    balls++;
    break;
  case '8':
    printf("Final Score: %d - %d (%.1f)\n", score, wickets, overs(balls));
    exit(0);
  default:
    break;
  }

  if (wickets >= 10) {
    gameOver = 1;
  }

  glutPostRedisplay();
}

void init() {
  glClearColor(0.0, 0.0, 0.0, 1.0); // Black background
  glColor3f(1.0, 1.0, 1.0);         // White text
  glMatrixMode(GL_PROJECTION);
  gluOrtho2D(-1, 1, -1, 1);
}

int main(int argc, char **argv) {
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
  glutInitWindowSize(700, 500);
  glutCreateWindow("Cricket Scoreboard - OpenGL");
  init();
  glutDisplayFunc(display);
  glutKeyboardFunc(keyboard);
  glutMainLoop();
  return 0;
}
