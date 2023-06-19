#include "includes.hpp"


/*
 * Icosahedron defined as triangles
 */
const int Ni=60;
//  Vertex coordinates and colors
const float xyzrgb[] =
{
    0.276,  0.851,  0.447,  0.0, 0.0, 1.0,
    0.894,  0.000,  0.447,  0.0, 0.0, 1.0,
    0.000,  0.000,  1.000,  0.0, 0.0, 1.0,
   -0.724,  0.526,  0.447,  0.0, 1.0, 0.0,
    0.276,  0.851,  0.447,  0.0, 1.0, 0.0,
    0.000,  0.000,  1.000,  0.0, 1.0, 0.0,
   -0.724, -0.526,  0.447,  0.0, 1.0, 1.0,
   -0.724,  0.526,  0.447,  0.0, 1.0, 1.0,
    0.000,  0.000,  1.000,  0.0, 1.0, 1.0,
    0.276, -0.851,  0.447,  1.0, 0.0, 1.0,
   -0.724, -0.526,  0.447,  1.0, 0.0, 1.0,
    0.000,  0.000,  1.000,  1.0, 0.0, 1.0,
    0.894,  0.000,  0.447,  1.0, 1.0, 0.0,
    0.276, -0.851,  0.447,  1.0, 1.0, 0.0,
    0.000,  0.000,  1.000,  1.0, 1.0, 0.0,
    0.000,  0.000, -1.000,  0.0, 0.0, 1.0,
    0.724,  0.526, -0.447,  0.0, 0.0, 1.0,
   -0.276,  0.851, -0.447,  0.0, 0.0, 1.0,
    0.000,  0.000, -1.000,  0.0, 1.0, 0.0,
   -0.276,  0.851, -0.447,  0.0, 1.0, 0.0,
   -0.894,  0.000, -0.447,  0.0, 1.0, 0.0,
    0.000,  0.000, -1.000,  0.0, 1.0, 1.0,
   -0.894,  0.000, -0.447,  0.0, 1.0, 1.0,
   -0.276, -0.851, -0.447,  0.0, 1.0, 1.0,
    0.000,  0.000, -1.000,  1.0, 0.0, 0.0,
   -0.276, -0.851, -0.447,  1.0, 0.0, 0.0,
    0.724, -0.526, -0.447,  1.0, 0.0, 0.0,
    0.000,  0.000, -1.000,  1.0, 0.0, 1.0,
    0.724, -0.526, -0.447,  1.0, 0.0, 1.0,
    0.724,  0.526, -0.447,  1.0, 0.0, 1.0,
    0.894,  0.000,  0.447,  1.0, 1.0, 0.0,
    0.276,  0.851,  0.447,  1.0, 1.0, 0.0,
    0.724,  0.526, -0.447,  1.0, 1.0, 0.0,
    0.276,  0.851,  0.447,  0.0, 0.0, 1.0,
   -0.724,  0.526,  0.447,  0.0, 0.0, 1.0,
   -0.276,  0.851, -0.447,  0.0, 0.0, 1.0,
   -0.724,  0.526,  0.447,  0.0, 1.0, 0.0,
   -0.724, -0.526,  0.447,  0.0, 1.0, 0.0,
   -0.894,  0.000, -0.447,  0.0, 1.0, 0.0,
   -0.724, -0.526,  0.447,  0.0, 1.0, 1.0,
    0.276, -0.851,  0.447,  0.0, 1.0, 1.0,
   -0.276, -0.851, -0.447,  0.0, 1.0, 1.0,
    0.276, -0.851,  0.447,  1.0, 0.0, 0.0,
    0.894,  0.000,  0.447,  1.0, 0.0, 0.0,
    0.724, -0.526, -0.447,  1.0, 0.0, 0.0,
    0.276,  0.851,  0.447,  1.0, 0.0, 1.0,
   -0.276,  0.851, -0.447,  1.0, 0.0, 1.0,
    0.724,  0.526, -0.447,  1.0, 0.0, 1.0,
   -0.724,  0.526,  0.447,  1.0, 1.0, 0.0,
   -0.894,  0.000, -0.447,  1.0, 1.0, 0.0,
   -0.276,  0.851, -0.447,  1.0, 1.0, 0.0,
   -0.724, -0.526,  0.447,  0.0, 0.0, 1.0,
   -0.276, -0.851, -0.447,  0.0, 0.0, 1.0,
   -0.894,  0.000, -0.447,  0.0, 0.0, 1.0,
    0.276, -0.851,  0.447,  0.0, 1.0, 0.0,
    0.724, -0.526, -0.447,  0.0, 1.0, 0.0,
   -0.276, -0.851, -0.447,  0.0, 1.0, 0.0,
    0.894,  0.000,  0.447,  0.0, 1.0, 1.0,
    0.724,  0.526, -0.447,  0.0, 1.0, 1.0,
    0.724, -0.526, -0.447,  0.0, 1.0, 1.0,
};


// /*
//  *  Draw vertex in polar coordinates
//  */
// static void Vertex(double th,double ph)
// {
//    glColor3f(Cos(th)*Cos(th) , Sin(ph)*Sin(ph) , Sin(th)*Sin(th));
//    glVertex3d(Sin(th)*Cos(ph) , Sin(ph) , Cos(th)*Cos(ph));
// }


// /*
//  *  Draw a sphere (version 2)
//  *     at (x,y,z)
//  *     radius (r)
//  */
// static void sphere2(double x, double y, double z, double r)
// {
//    const int d=15;

//    //  Save transformation
//    glPushMatrix();
//    //  Offset and scale
//    glTranslated(x, y, z);
//    glScaled(r, r, r);

//    //  Latitude bands
//    for (int ph=-90;ph<90;ph+=d)
//    {
//       glBegin(GL_QUAD_STRIP);
//       for (int th=0;th<=360;th+=d)
//       {
//          Vertex(th,ph);
//          Vertex(th,ph+d);
//       }
//       glEnd();
//    }

//    //  Undo transformations
//    glPopMatrix();
// }



/*
 *  Draw a cube
 *     at (x,y,z)
 *     dimensions (dx,dy,dz)
 *     rotated th about the y axis
 */
static void cube(double x,double y,double z, double dx,double dy,double dz, double th, double r, double g, double b)
{
   //  Save transformation
   glPushMatrix();
   //  Offset
   glTranslated(x, y, z);
   glRotated(th,0,1,0);
   glScaled(dx,dy,dz);
   //  Cube
   glBegin(GL_QUADS);
   //  Front
   glColor3f(r, g, b);
   glVertex3f(-1,-1, 1);
   glVertex3f(+1,-1, 1);
   glVertex3f(+1,+1, 1);
   glVertex3f(-1,+1, 1);
   //  Back
   glColor3f(r, g, b);
   glVertex3f(+1,-1,-1);
   glVertex3f(-1,-1,-1);
   glVertex3f(-1,+1,-1);
   glVertex3f(+1,+1,-1);
   //  Right
   glColor3f(r, g, b);
   glVertex3f(+1,-1,+1);
   glVertex3f(+1,-1,-1);
   glVertex3f(+1,+1,-1);
   glVertex3f(+1,+1,+1);
   //  Left
   glColor3f(r, g, b);
   glVertex3f(-1,-1,-1);
   glVertex3f(-1,-1,+1);
   glVertex3f(-1,+1,+1);
   glVertex3f(-1,+1,-1);
   //  Top
   glColor3f(r, g, b);
   glVertex3f(-1,+1,+1);
   glVertex3f(+1,+1,+1);
   glVertex3f(+1,+1,-1);
   glVertex3f(-1,+1,-1);
   //  Bottom
   glColor3f(r, g, b);
   glVertex3f(-1,-1,-1);
   glVertex3f(+1,-1,-1);
   glVertex3f(+1,-1,+1);
   glVertex3f(-1,-1,+1);
   //  End
   glEnd();
   //  Undo transformations
   glPopMatrix();
}


// /*
//  *  Draw icosahedron using VBO
//  *     at (x,y,z)
//  *     size  s
//  *     rotated th about the x axis
//  */
// static unsigned int vbo3=0; //  Icosahedron VBO
// static void icosahedron3(float x,float y,float z,float s,float th)
// {
//    //  Bind VBO
//    if (vbo3)
//       glBindBuffer(GL_ARRAY_BUFFER,vbo3);
//    //  Initialize VBO on first call
//    else
//    {
//       //  Get buffer name
//       glGenBuffers(1, &vbo3);
//       //  Bind VBO
//       glBindBuffer(GL_ARRAY_BUFFER, vbo3);
//       //  Copy icosahedron to VBO
//       glBufferData(GL_ARRAY_BUFFER,sizeof(xyzrgb),xyzrgb,GL_STATIC_DRAW);
//    }

//    //  Define vertexes
//    glVertexPointer(3,GL_FLOAT,6*sizeof(float),(void*)0);
//    glEnableClientState(GL_VERTEX_ARRAY);
//    //  Define colors for each vertex
//    glColorPointer(3,GL_FLOAT,6*sizeof(float),(void*)12);
//    glEnableClientState(GL_COLOR_ARRAY);
//    //  Draw icosahedron
//    glPushMatrix();
//    glTranslatef(x,y,z);
//    glRotatef(th,1,0,0);
//    glScalef(s,s,s);
//    glDrawArrays(GL_TRIANGLES,0,Ni);
//    glPopMatrix();
//    //  Disable vertex array
//    glDisableClientState(GL_VERTEX_ARRAY);
//    //  Disable color array
//    glDisableClientState(GL_COLOR_ARRAY);
//    //  Release VBO
//    glBindBuffer(GL_ARRAY_BUFFER,0);
// }