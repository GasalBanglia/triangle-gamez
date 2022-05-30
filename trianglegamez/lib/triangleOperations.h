/*
 * @file
 * 	triangleOperations.h
 * @description
 * 	Functions implementing behavior of the
 * 	trianglegamez project.  'tgl' stands for 
 * 	Triangle Graphics Library.
 * @date
 * 	8/2/2016
 * @version
 * 	1.0 -> detail window procedure, transforms, projectile launch,
 * 		and status display.
 */
#ifndef TGL_H
#define TGL_H

#pragma once 

#include <windows.h>
#include <stdlib.h>
#include "..\res\resource.h"

#define TGL_POLYGON 0
#define TGL_POLYLINE 1

#define TGL_PROJECTILE1 0
#define TGL_PROJECTILE2 1

#define TGL_PLAYER1 0
#define TGL_PLAYER2 1

#define MAX_VERTEX_ATTRIBS 128
#define IDT_FRAMERATE_CONTROL 201
#define IDT_PROJECTILETIMER1 202
#define IDT_PROJECTILETIMER2 203	
#define IDT_GAMEOVER 204

#define GAMEOVER_ANIMATION_INTERVAL 1000
#define FRAMERATE_INTERVAL 17

/* here, an attribute (or 'attrib' for short) is the 
 * information required to specify a vertex: an x and y 
 * coordinate. */
POINT vertexAttribs[MAX_VERTEX_ATTRIBS];
BITMAP bmp;
HBITMAP hbmOld;
HBITMAP hBmp;
HDC htdc;
HDC windowDC;
HINSTANCE hInstance;
HWND htDrawWnd; //'handle to triangle drawing window' --> I know, it's contrived.
HBRUSH oldBrush;
RECT rc;
POINT player1[4];
POINT player2[4];
POINT projectile1[6];
POINT projectile2[6];
POINT healthBarOutline1[5];
POINT healthBarOutline2[5];
POINT healthBarFill1[5];
POINT healthBarFill2[5];
POINT *gameObjects[9]; 
int vertexCounts[8];
HBRUSH *brushes[8];
int winner;
char player1WinText[40]; 
char player2WinText[40];
char *player1WinCountString;
char *player2WinCountString;
int player1WinCount;
int player2WinCount;
BOOL gameWon;
HFONT hf;

/*
 * Generic function.  Takes a single array of point data
 * and draws a Polygon with 'count' points starting at 
 * vertex 'start' and ending with vertex 'end'.
 *
 * The vertices are set by assigning the desired POINT values into 
 * the vertexAttribs global variable declared in this file.
 * That is, DrawVertexArrays draws a subset of the vertexAttribs
 * array.
 *
 * This model allows all of your vertex data for every object
 * to be specified in a single array of POINT structs.  
 * OpenGL, as far as I'm concerned, has functions that operate 
 * in a similar way.
 */
void tglDrawVertexArrays(int count, int start, int end, int mode);

/*
 * Simple function draws a user-provided array of POINTs
 * as a polygon to the current context.
 */
void tglDrawPolygon(POINT* points, int count);

/*
 * Iterates drawing over all objects in the objects array.
 */
void tglDrawScene(POINT **objects, int *counts);

/*
 * The parameter points should be the game object transformed,
 * defined in the above header.
 */
void tglTranslateObject(POINT* points, int dx, int dy);

/*
 * Figure out whether a positive degree corresponds to 
 * a clockwise or counterclockwise rotation, and vice versa.
 */
void tglRotateObject(POINT* points, POINT origin, int degree);

/*
 * Implement this for me, will ya?
 */
void tglScaleObject(POINT* points, int delta);

/*
 * This function must be called before any drawing calls will work.
 * Using operations without creating a context will result in
 * undefined behavior.  Try it; I can't say what will happen.
 */
void tglCreateContext(HWND hWnd, HINSTANCE hInst);

/*
 * Shifts the coordinates of the POINT array describing the
 * given projectile at the tip of its associated triangle.
 */
void tglResetProjectile(int projectileID);

/*
 * Give all of the game objects their initial values.
 */
void tglInitObjects();

/*
 * Update health bar and animate a projectile hit.
 */
void tglInflictDamage(int player);

/*
 * Initiate match end sequence.
 */
void tglGameOver(int player);

char *itoa(int i, char *str, int base);

/*		Various Procedures		*/
LRESULT CALLBACK WndProc(HWND hWnd, unsigned int msg, WPARAM wParam, LPARAM lParam);
VOID CALLBACK ProjectileTimerProc1(HWND hWnd, UINT uMsg, UINT_PTR idEvent, DWORD dwTime);
VOID CALLBACK ProjectileTimerProc2(HWND hWnd, UINT uMsg, UINT_PTR idEvent, DWORD dwTime);
VOID CALLBACK RotationTimerProc(HWND hWnd, UINT uMsg, UINT_PTR idEvent, DWORD dwTime);
VOID CALLBACK TimerProc(HWND hWnd, UINT uMsg, UINT_PTR idEvent, DWORD dwTime);
VOID CALLBACK GameOverProc(HWND hWnd, UINT uMsg, UINT_PTR idEvent, DWORD dwTime);
#endif
