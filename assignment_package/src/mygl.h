#ifndef MYGL_H
#define MYGL_H

#include <glwidget277.h>
#include <utils.h>
#include <shaderprogram.h>
#include <scene/grid.h>
#include <scene/polygon.h>

#include <QOpenGLVertexArrayObject>
#include <QOpenGLShaderProgram>


class MyGL
    : public GLWidget277
{
private:
    ShaderProgram prog_flat;// A shader program that uses "flat" reflection (no shadowing at all)

    Grid m_geomGrid; // The instance of the object used to render the 5x5 grid
    Polygon2D m_geomSquare; // The singular instance of our square object that can be re-drawn with different colors
                         // to create the appearance of there being multiple squares

    bool m_showGrid; // Read in paintGL to determine whether or not to draw the grid.

    GLuint vao; // A handle for our vertex array object. This will store the VBOs created in our geometry classes.


public:
    explicit MyGL(QWidget *parent = 0);
    ~MyGL();

    void initializeGL();
    void resizeGL(int w, int h);
    void paintGL();

protected:
    void keyPressEvent(QKeyEvent *e);
};


#endif // MYGL_H
