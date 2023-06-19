#include "shapes.hpp"


//  Rotation angles
double xTh = 24;
double yTh = 12;


double xShift = -.06f;
double yShift = -6.4;
double zShift = -18.8;

bool moving_forward = false;
bool moving_backward = false;
bool moving_left = false;
bool moving_right = false;
bool moving_up = false;
bool moving_down = false;

bool rotating_right = false;
bool rotating_left = false;
bool rotating_up = false;
bool rotating_down = false;

int mode = 0;
#define FREE 0
#define PERSP 2
#define ORTHO 1

const float speed = 0.1f;
const int rot_speed = 1;


const float X_OVERHEAD_ORTHO = -3.0f;
const float Y_OVERHEAD_ORTHO = 0;
const float Z_OVERHEAD_ORTHO = -4.0f;
const float xTH_OVERHEAD_ORTHO = 90.0f;
const float yTH_OVERHEAD_ORTHO = 90.0f;

const float X_OVERHEAD_PRESP = -3.0f;
const float Y_OVERHEAD_PRESP = -15;
const float Z_OVERHEAD_PRESP = -3.0f;
const float xTH_OVERHEAD_PRESP = 90.0f;
const float yTH_OVERHEAD_PRESP = 90.0f;

int width_ = 600;
int height_ = 600;

const char *modeText(){
   if(mode == PERSP) return "Overhead Presp";
   else if(mode == ORTHO) return "Overhead Ortho";
   return "1st Person";
}



// --------------------------------------------------------------------------------------------

void drawAxis(int len){

   // Drawing axis
   glBegin(GL_LINES);
   glColor3f(1,1,1);


   glVertex3d(0, 0, 0);
   glVertex3d(len, 0, 0);

   
   glVertex3d(0, 0, 0);
   glVertex3d(0, len, 0);

   
   glVertex3d(0, 0, 0);
   glVertex3d(0, 0, len);


   glEnd();

   glWindowPos2i(5,5);
   // Label axis

   
   glRasterPos3d(len, 0, 0);
   Print("X");

   glRasterPos3d(0, len, 0);
   Print("Y");

   glRasterPos3d(0, 0, len);
   Print("Z");

}

void chair(){

   // Draw the legs
   float leg_offset = .4f;
   float leg_width = .03f;
   float leg_height = 0.35f;

   cube(-leg_offset, 0, -leg_offset, leg_width, leg_height, leg_width, 0, .5, .5, .5);
   cube(-leg_offset, 0, leg_offset, leg_width, leg_height, leg_width, 0, .5, .5, .5);
   cube(leg_offset, 0, -leg_offset, leg_width, leg_height, leg_width, 0, .5, .5, .5);
   cube(leg_offset, 0, leg_offset, leg_width, leg_height, leg_width, 0, .5, .5, .5);

   // Draw the seat
   float chair_width = 0.5f;
   float chair_depth = .01f;
   float chair_height = 0.35f;
   cube(0, chair_height, 0, chair_width, chair_depth, chair_width, 0, .4, .4, .4);

    // Draw the backrest
   cube(0, leg_height + chair_height, chair_width, chair_width, chair_height, chair_depth, 0, .6, .6, .6);
}


void table(){
   // Table top!
   cube(0, 0, 0, .5f, 0.05, .5f, 0, .4, .4, .4);

   // Drawing legs
   cube(-.4f, -.35f, 0.4f, .05f, 0.3, .05f, 0, .3, .3, .3);
   cube(.4f, -.35f, -0.4f, .05f, 0.3, .05f, 0, .3, .3, .3);
   cube(-.4f, -.35f, -0.4f, .05f, 0.3, .05f, 0, .3, .3, .3);
   cube(.4f, -.35f, 0.4f, .05f, 0.3, .05f, 0, .3, .3, .3);
}


void board(){
   cube(3, 2, -3, 3, 1.5, 0.05, 0, .8, .8, .8);
}

void setupProjection()
{
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    if (mode == ORTHO)
    {
      //  Orthogonal projection
      const double dim = 5;
      double asp = (height_>0) ? (double)width_/height_ : 1;
      glOrtho(-asp*dim,+asp*dim, -dim, +dim, -dim, +dim);
    }
    else
    {
      // Apply perspective projection
      double aspectRatio = (double)width_ / height_;
      gluPerspective(45, aspectRatio, 0.1, 100);
    }

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

void display(){

   //  Erase the window and the depth buffer
   glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
   setupProjection();
   //  Enable Z-buffering in OpenGL
   glEnable(GL_DEPTH_TEST);
   //  Undo previous transformations
   glLoadIdentity();

   glRotatef(xTh, 1, 0, 0);
   glRotatef(yTh, 0, 1, 0);

   // -----------------------


   glTranslatef(xShift, yShift, zShift);

   
   switch (mode){
      case PERSP:
         xShift = X_OVERHEAD_PRESP;
         yShift = Y_OVERHEAD_PRESP;
         zShift = Z_OVERHEAD_PRESP;
         xTh = xTH_OVERHEAD_PRESP;
         yTh = yTH_OVERHEAD_PRESP;

         break;

      case ORTHO:
         xShift = X_OVERHEAD_ORTHO;
         yShift = Y_OVERHEAD_ORTHO;
         zShift = Z_OVERHEAD_ORTHO;
         xTh = xTH_OVERHEAD_ORTHO;
         yTh = yTH_OVERHEAD_ORTHO;

         break;
   }


   for(int i = 0; i < 4; i++){
      for(int j = 0; j < 5; j++){
         glPushMatrix();
         glTranslatef(i*2, 0.5, j*2.5);
         
         glPushMatrix();
         glScalef(1.3, 1.3, 1.3);
         table();
         glPopMatrix();

         glPushMatrix();
         glScalef(.8, .8, .8);
         glTranslatef(0, -0.8f, 1);
         chair();
         glPopMatrix();

         glPopMatrix();
      }
   }

   board();



   // drawAxis(1);


   glRotatef(xTh, 1, 0, 0);
   glRotatef(yTh, 0, 1, 0);


   // -----------------------
   //  Five pixels from the lower left corner of the window
   glWindowPos2i(5,5);
   Print("X: %g, Y: %g, Z: %g, xTh: %g, yTh: %g, MODE: %s (%d)", xShift, yShift, zShift, xTh, yTh, modeText(), mode);


   //  Render the scene
   ErrCheck("display");
   glFlush();
   glutSwapBuffers();
}


/*
 * This function is called by GLUT when the window is resized
 */
void reshape(int width,int height)
{

   width_ = width;
   height_ = height;

   //  Set viewport as entire window
   glViewport(0, 0, RES*width, RES*height);
   //  Select projection matrix
   glMatrixMode(GL_PROJECTION);
   //  Set projection to identity
   glLoadIdentity();


   if(mode == ORTHO){
      //  Orthogonal projection
      const double dim = 5;
      double asp = (height_>0) ? (double)width_/height_ : 1;
      glOrtho(-asp*dim,+asp*dim, -dim, +dim, -dim, +dim);
   }
   else{
      // Apply perspective projection
      double aspectRatio = (double)width_ / height_;
      gluPerspective(45, aspectRatio, 0.1, 100);
   }


   //  Select model view matrix
   glMatrixMode(GL_MODELVIEW);
   //  Set model view to identity
   glLoadIdentity();
}

/*
 * This function is called by GLUT when special keys are pressed
 */
void special(int key,int x,int y){

   switch (key){
      case GLUT_KEY_RIGHT: // Right arrow - increase rotation by 5 degree
         rotating_right = true;
         break;
   
      case GLUT_KEY_LEFT: // Left arrow - decrease rotation by 5 degree
         rotating_left = true;
         break;
   
      case GLUT_KEY_UP: // Up arrow - decrease rotation by 5 degree
         rotating_up = true;
         xTh -= rot_speed;
         break;
   
      case GLUT_KEY_DOWN: // Down arrow - increases rotation by 5 degree
         rotating_down = true;
         xTh += rot_speed;
         break;
   }


   //  Request display update
   glutPostRedisplay();
}


void specialUp(int key,int x,int y){

   switch (key){
      case GLUT_KEY_RIGHT: // Right arrow - increase rotation by 5 degree
         rotating_right = false;
         break;
   
      case GLUT_KEY_LEFT: // Left arrow - decrease rotation by 5 degree
         rotating_left = false;
         break;
   
      case GLUT_KEY_UP: // Up arrow - decrease rotation by 5 degree
         rotating_up = false;
         xTh -= rot_speed;
         break;
   
      case GLUT_KEY_DOWN: // Down arrow - increases rotation by 5 degree
         rotating_down = false;
         xTh += rot_speed;
         break;
   }


   //  Request display update
   glutPostRedisplay();
}


void keyboard(unsigned char ch,int x,int y){
   if(mode == FREE){
      switch (ch){
         case 27:   // Exit on ESC
            exit(0);
            break;
         
         case 'w':
            moving_forward = true;
            break;
         
         case 's':
            moving_backward = true;
            break;

         case 'a':
            moving_left = true;
            break;

         case 'd':
            moving_right = true;
            break;

         case ' ':
            moving_up = true;
            break;

         case '`':
            moving_down = true;
            break;

         case 'm':
            mode = (mode + 1) % 3;
            break;

         case '0':  // Reset the view angle
            xTh = yTh = xShift = yShift = zShift = 0;
            break;
      }
   }
   else{
      switch (ch){
         case 27:
            exit(0);
            break;

         case 'm':
            mode = (mode + 1) % 3;
            if(mode == FREE){
               xShift = X_OVERHEAD_PRESP;
               yShift = Y_OVERHEAD_PRESP;
               zShift = Z_OVERHEAD_PRESP;
               xTh = xTH_OVERHEAD_PRESP;
               yTh = yTH_OVERHEAD_PRESP;
            }
            break;
      }
   }

   //  Request display update
   glutPostRedisplay();
}


void keyboardUp(unsigned char ch,int x,int y){

   switch (ch){
      
      case 'w':
         moving_forward = false;
         break;
      
      case 's':
         moving_backward = false;
         break;

      case 'a':
         moving_left = false;
         break;

      case 'd':
         moving_right = false;
         break;

      case ' ':
         moving_up = false;
         break;

      case '`':
         moving_down = false;
         break;
   }

   //  Request display update
   glutPostRedisplay();
}


/*
 *  GLUT calls this routine when there is nothing else to do
 */
void idle(){
   // double t = glutGet(GLUT_ELAPSED_TIME)/1000.0;
   // zh = fmod(90*t,360);
   float delta_x = speed * Sin(yTh);
   float delta_z = speed * Cos(yTh);

   if(moving_forward){

      xShift += -delta_x;
      zShift += delta_z;
   }
   
   if(moving_backward){
      xShift -= -delta_x;
      zShift -= delta_z;
   }

   if(moving_left){
      xShift += delta_z;
      zShift += delta_x;
   }

   if(moving_right){
      xShift -= delta_z;
      zShift -= delta_x;
   }

   if(moving_up){
      yShift -= speed;
   }

   if(moving_down){
      yShift += speed;
   }

   if(rotating_right){
      yTh += rot_speed;
   }

   if(rotating_left){
      yTh -= rot_speed;
   }

   if(rotating_up){
      xTh -= rot_speed;
   }

   if(rotating_down){
      xTh += rot_speed;
   }


   glutPostRedisplay();
}


/*
 *  Main
 */
int main(int argc, char *argv[])
{
   
   //  Initialize GLUT
   glutInit(&argc,argv);
   glutInitWindowSize(1080, 720);
   //  Request double buffered true color window with Z-buffer
   glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
   //  Create window
   glutCreateWindow("Assignment 2: Ali Almutawa Jr. - A 3D Scene");

#ifdef USEGLEW
   //  Initialize GLEW
   if (glewInit()!=GLEW_OK) Fatal("Error initializing GLEW\n");
#endif

   //  Register display, reshape and key callbacks
   glutDisplayFunc(display);
   glutReshapeFunc(reshape);
   glutSpecialFunc(special);
   glutSpecialUpFunc(specialUp);
   glutKeyboardFunc(keyboard);
   glutKeyboardUpFunc(keyboardUp);
   glutIdleFunc(idle);

   //  Enable Z-buffer depth test
   glEnable(GL_DEPTH_TEST);

   //  Pass control to GLUT for events
   glutMainLoop();

   return 0;
}