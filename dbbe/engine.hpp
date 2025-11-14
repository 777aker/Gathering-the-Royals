#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>

// different headers depending on what machine you're on
#ifdef USEGLEW
#include <GL/glew.h>
#endif
#define GL_GLEXT_PROTOTYPES
#include <GLFW/glfw3.h>
#ifdef __APPLE__
#include <OpenGL/glu.h>
#include <OpenGL/gl.h>
#else
#include <GL/glu.h>
#include <GL/gl.h>
#endif

extern double dim; // size of the world
extern double asp; // aspect ratio

void Print(const char *format, ...);
void Fatal(const char *format, ...);
void ErrCheck(const char *where);

unsigned int LoadTexBMP(const char *file);
int CreateShaderProg(const char *vert, const char *frag);

class Window
{
public:
	Window(const char *title, int sync, int width, int height,
		   void (*key)(GLFWwindow *, int, int, int, int),
		   void (*mouse)(GLFWwindow *, int, int, int));
	int FramesPerSecond();
	~Window();
	// void startDisplayLoop(void (*display)(Window*)); // this program isn't going to use this
	GLFWwindow *glwindow;

private:
	int fps = 0;
	int sec0 = 0, fpscount = 0;
};