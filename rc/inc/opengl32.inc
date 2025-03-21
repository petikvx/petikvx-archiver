; ..\LIB\OPENGL32.LIB PROTOTYPES
; ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

DllInitialize PROTO :DWORD,:DWORD,:DWORD
GlmfBeginGlsBlock PROTO :DWORD
GlmfCloseMetaFile PROTO :DWORD
GlmfEndGlsBlock PROTO :DWORD
GlmfEndPlayback PROTO :DWORD
GlmfInitPlayback PROTO :DWORD,:DWORD,:DWORD
GlmfPlayGlsRecord PROTO :DWORD,:DWORD,:DWORD,:DWORD
glAccum PROTO :DWORD,:DWORD
glAlphaFunc PROTO :DWORD,:DWORD
glAreTexturesResident PROTO :DWORD,:DWORD,:DWORD
glArrayElement PROTO :DWORD
glBegin PROTO :DWORD
glBindTexture PROTO :DWORD,:DWORD
glBitmap PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
glBlendFunc PROTO :DWORD,:DWORD
glCallList PROTO :DWORD
glCallLists PROTO :DWORD,:DWORD,:DWORD
glClear PROTO :DWORD
glClearAccum PROTO :DWORD,:DWORD,:DWORD,:DWORD
glClearColor PROTO :DWORD,:DWORD,:DWORD,:DWORD
glClearDepth PROTO :DWORD,:DWORD
glClearIndex PROTO :DWORD
glClearStencil PROTO :DWORD
glClipPlane PROTO :DWORD,:DWORD
glColor3b PROTO :DWORD,:DWORD,:DWORD
glColor3bv PROTO :DWORD
glColor3d PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
glColor3dv PROTO :DWORD
glColor3f PROTO :DWORD,:DWORD,:DWORD
glColor3fv PROTO :DWORD
glColor3i PROTO :DWORD,:DWORD,:DWORD
glColor3iv PROTO :DWORD
glColor3s PROTO :DWORD,:DWORD,:DWORD
glColor3sv PROTO :DWORD
glColor3ub PROTO :DWORD,:DWORD,:DWORD
glColor3ubv PROTO :DWORD
glColor3ui PROTO :DWORD,:DWORD,:DWORD
glColor3uiv PROTO :DWORD
glColor3us PROTO :DWORD,:DWORD,:DWORD
glColor3usv PROTO :DWORD
glColor4b PROTO :DWORD,:DWORD,:DWORD,:DWORD
glColor4bv PROTO :DWORD
glColor4d PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
glColor4dv PROTO :DWORD
glColor4f PROTO :DWORD,:DWORD,:DWORD,:DWORD
glColor4fv PROTO :DWORD
glColor4i PROTO :DWORD,:DWORD,:DWORD,:DWORD
glColor4iv PROTO :DWORD
glColor4s PROTO :DWORD,:DWORD,:DWORD,:DWORD
glColor4sv PROTO :DWORD
glColor4ub PROTO :DWORD,:DWORD,:DWORD,:DWORD
glColor4ubv PROTO :DWORD
glColor4ui PROTO :DWORD,:DWORD,:DWORD,:DWORD
glColor4uiv PROTO :DWORD
glColor4us PROTO :DWORD,:DWORD,:DWORD,:DWORD
glColor4usv PROTO :DWORD
glColorMask PROTO :DWORD,:DWORD,:DWORD,:DWORD
glColorMaterial PROTO :DWORD,:DWORD
glColorPointer PROTO :DWORD,:DWORD,:DWORD,:DWORD
glCopyPixels PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
glCopyTexImage1D PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
glCopyTexImage2D PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
glCopyTexSubImage1D PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
glCopyTexSubImage2D PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
glCullFace PROTO :DWORD
glDebugEntry PROTO :DWORD,:DWORD
glDeleteLists PROTO :DWORD,:DWORD
glDeleteTextures PROTO :DWORD,:DWORD
glDepthFunc PROTO :DWORD
glDepthMask PROTO :DWORD
glDepthRange PROTO :DWORD,:DWORD,:DWORD,:DWORD
glDisable PROTO :DWORD
glDisableClientState PROTO :DWORD
glDrawArrays PROTO :DWORD,:DWORD,:DWORD
glDrawBuffer PROTO :DWORD
glDrawElements PROTO :DWORD,:DWORD,:DWORD,:DWORD
glDrawPixels PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
glEdgeFlag PROTO :DWORD
glEdgeFlagPointer PROTO :DWORD,:DWORD
glEdgeFlagv PROTO :DWORD
glEnable PROTO :DWORD
glEnableClientState PROTO :DWORD
glEnd PROTO
glEndList PROTO
glEvalCoord1d PROTO :DWORD,:DWORD
glEvalCoord1dv PROTO :DWORD
glEvalCoord1f PROTO :DWORD
glEvalCoord1fv PROTO :DWORD
glEvalCoord2d PROTO :DWORD,:DWORD,:DWORD,:DWORD
glEvalCoord2dv PROTO :DWORD
glEvalCoord2f PROTO :DWORD,:DWORD
glEvalCoord2fv PROTO :DWORD
glEvalMesh1 PROTO :DWORD,:DWORD,:DWORD
glEvalMesh2 PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
glEvalPoint1 PROTO :DWORD
glEvalPoint2 PROTO :DWORD,:DWORD
glFeedbackBuffer PROTO :DWORD,:DWORD,:DWORD
glFinish PROTO
glFlush PROTO
glFogf PROTO :DWORD,:DWORD
glFogfv PROTO :DWORD,:DWORD
glFogi PROTO :DWORD,:DWORD
glFogiv PROTO :DWORD,:DWORD
glFrontFace PROTO :DWORD
glFrustum PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
glGenLists PROTO :DWORD
glGenTextures PROTO :DWORD,:DWORD
glGetBooleanv PROTO :DWORD,:DWORD
glGetClipPlane PROTO :DWORD,:DWORD
glGetDoublev PROTO :DWORD,:DWORD
glGetError PROTO
glGetFloatv PROTO :DWORD,:DWORD
glGetIntegerv PROTO :DWORD,:DWORD
glGetLightfv PROTO :DWORD,:DWORD,:DWORD
glGetLightiv PROTO :DWORD,:DWORD,:DWORD
glGetMapdv PROTO :DWORD,:DWORD,:DWORD
glGetMapfv PROTO :DWORD,:DWORD,:DWORD
glGetMapiv PROTO :DWORD,:DWORD,:DWORD
glGetMaterialfv PROTO :DWORD,:DWORD,:DWORD
glGetMaterialiv PROTO :DWORD,:DWORD,:DWORD
glGetPixelMapfv PROTO :DWORD,:DWORD
glGetPixelMapuiv PROTO :DWORD,:DWORD
glGetPixelMapusv PROTO :DWORD,:DWORD
glGetPointerv PROTO :DWORD,:DWORD
glGetPolygonStipple PROTO :DWORD
glGetString PROTO :DWORD
glGetTexEnvfv PROTO :DWORD,:DWORD,:DWORD
glGetTexEnviv PROTO :DWORD,:DWORD,:DWORD
glGetTexGendv PROTO :DWORD,:DWORD,:DWORD
glGetTexGenfv PROTO :DWORD,:DWORD,:DWORD
glGetTexGeniv PROTO :DWORD,:DWORD,:DWORD
glGetTexImage PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
glGetTexLevelParameterfv PROTO :DWORD,:DWORD,:DWORD,:DWORD
glGetTexLevelParameteriv PROTO :DWORD,:DWORD,:DWORD,:DWORD
glGetTexParameterfv PROTO :DWORD,:DWORD,:DWORD
glGetTexParameteriv PROTO :DWORD,:DWORD,:DWORD
glHint PROTO :DWORD,:DWORD
glIndexMask PROTO :DWORD
glIndexPointer PROTO :DWORD,:DWORD,:DWORD
glIndexd PROTO :DWORD,:DWORD
glIndexdv PROTO :DWORD
glIndexf PROTO :DWORD
glIndexfv PROTO :DWORD
glIndexi PROTO :DWORD
glIndexiv PROTO :DWORD
glIndexs PROTO :DWORD
glIndexsv PROTO :DWORD
glIndexub PROTO :DWORD
glIndexubv PROTO :DWORD
glInitNames PROTO
glInterleavedArrays PROTO :DWORD,:DWORD,:DWORD
glIsEnabled PROTO :DWORD
glIsList PROTO :DWORD
glIsTexture PROTO :DWORD
glLightModelf PROTO :DWORD,:DWORD
glLightModelfv PROTO :DWORD,:DWORD
glLightModeli PROTO :DWORD,:DWORD
glLightModeliv PROTO :DWORD,:DWORD
glLightf PROTO :DWORD,:DWORD,:DWORD
glLightfv PROTO :DWORD,:DWORD,:DWORD
glLighti PROTO :DWORD,:DWORD,:DWORD
glLightiv PROTO :DWORD,:DWORD,:DWORD
glLineStipple PROTO :DWORD,:DWORD
glLineWidth PROTO :DWORD
glListBase PROTO :DWORD
glLoadIdentity PROTO
glLoadMatrixd PROTO :DWORD
glLoadMatrixf PROTO :DWORD
glLoadName PROTO :DWORD
glLogicOp PROTO :DWORD
glMap1d PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
glMap1f PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
glMap2d PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
glMap2f PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
glMapGrid1d PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
glMapGrid1f PROTO :DWORD,:DWORD,:DWORD
glMapGrid2d PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
glMapGrid2f PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
glMaterialf PROTO :DWORD,:DWORD,:DWORD
glMaterialfv PROTO :DWORD,:DWORD,:DWORD
glMateriali PROTO :DWORD,:DWORD,:DWORD
glMaterialiv PROTO :DWORD,:DWORD,:DWORD
glMatrixMode PROTO :DWORD
glMultMatrixd PROTO :DWORD
glMultMatrixf PROTO :DWORD
glNewList PROTO :DWORD,:DWORD
glNormal3b PROTO :DWORD,:DWORD,:DWORD
glNormal3bv PROTO :DWORD
glNormal3d PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
glNormal3dv PROTO :DWORD
glNormal3f PROTO :DWORD,:DWORD,:DWORD
glNormal3fv PROTO :DWORD
glNormal3i PROTO :DWORD,:DWORD,:DWORD
glNormal3iv PROTO :DWORD
glNormal3s PROTO :DWORD,:DWORD,:DWORD
glNormal3sv PROTO :DWORD
glNormalPointer PROTO :DWORD,:DWORD,:DWORD
glOrtho PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
glPassThrough PROTO :DWORD
glPixelMapfv PROTO :DWORD,:DWORD,:DWORD
glPixelMapuiv PROTO :DWORD,:DWORD,:DWORD
glPixelMapusv PROTO :DWORD,:DWORD,:DWORD
glPixelStoref PROTO :DWORD,:DWORD
glPixelStorei PROTO :DWORD,:DWORD
glPixelTransferf PROTO :DWORD,:DWORD
glPixelTransferi PROTO :DWORD,:DWORD
glPixelZoom PROTO :DWORD,:DWORD
glPointSize PROTO :DWORD
glPolygonMode PROTO :DWORD,:DWORD
glPolygonOffset PROTO :DWORD,:DWORD
glPolygonStipple PROTO :DWORD
glPopAttrib PROTO
glPopClientAttrib PROTO
glPopMatrix PROTO
glPopName PROTO
glPrioritizeTextures PROTO :DWORD,:DWORD,:DWORD
glPushAttrib PROTO :DWORD
glPushClientAttrib PROTO :DWORD
glPushMatrix PROTO
glPushName PROTO :DWORD
glRasterPos2d PROTO :DWORD,:DWORD,:DWORD,:DWORD
glRasterPos2dv PROTO :DWORD
glRasterPos2f PROTO :DWORD,:DWORD
glRasterPos2fv PROTO :DWORD
glRasterPos2i PROTO :DWORD,:DWORD
glRasterPos2iv PROTO :DWORD
glRasterPos2s PROTO :DWORD,:DWORD
glRasterPos2sv PROTO :DWORD
glRasterPos3d PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
glRasterPos3dv PROTO :DWORD
glRasterPos3f PROTO :DWORD,:DWORD,:DWORD
glRasterPos3fv PROTO :DWORD
glRasterPos3i PROTO :DWORD,:DWORD,:DWORD
glRasterPos3iv PROTO :DWORD
glRasterPos3s PROTO :DWORD,:DWORD,:DWORD
glRasterPos3sv PROTO :DWORD
glRasterPos4d PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
glRasterPos4dv PROTO :DWORD
glRasterPos4f PROTO :DWORD,:DWORD,:DWORD,:DWORD
glRasterPos4fv PROTO :DWORD
glRasterPos4i PROTO :DWORD,:DWORD,:DWORD,:DWORD
glRasterPos4iv PROTO :DWORD
glRasterPos4s PROTO :DWORD,:DWORD,:DWORD,:DWORD
glRasterPos4sv PROTO :DWORD
glReadBuffer PROTO :DWORD
glReadPixels PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
glRectd PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
glRectdv PROTO :DWORD,:DWORD
glRectf PROTO :DWORD,:DWORD,:DWORD,:DWORD
glRectfv PROTO :DWORD,:DWORD
glRecti PROTO :DWORD,:DWORD,:DWORD,:DWORD
glRectiv PROTO :DWORD,:DWORD
glRects PROTO :DWORD,:DWORD,:DWORD,:DWORD
glRectsv PROTO :DWORD,:DWORD
glRenderMode PROTO :DWORD
glRotated PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
glRotatef PROTO :DWORD,:DWORD,:DWORD,:DWORD
glScaled PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
glScalef PROTO :DWORD,:DWORD,:DWORD
glScissor PROTO :DWORD,:DWORD,:DWORD,:DWORD
glSelectBuffer PROTO :DWORD,:DWORD
glShadeModel PROTO :DWORD
glStencilFunc PROTO :DWORD,:DWORD,:DWORD
glStencilMask PROTO :DWORD
glStencilOp PROTO :DWORD,:DWORD,:DWORD
glTexCoord1d PROTO :DWORD,:DWORD
glTexCoord1dv PROTO :DWORD
glTexCoord1f PROTO :DWORD
glTexCoord1fv PROTO :DWORD
glTexCoord1i PROTO :DWORD
glTexCoord1iv PROTO :DWORD
glTexCoord1s PROTO :DWORD
glTexCoord1sv PROTO :DWORD
glTexCoord2d PROTO :DWORD,:DWORD,:DWORD,:DWORD
glTexCoord2dv PROTO :DWORD
glTexCoord2f PROTO :DWORD,:DWORD
glTexCoord2fv PROTO :DWORD
glTexCoord2i PROTO :DWORD,:DWORD
glTexCoord2iv PROTO :DWORD
glTexCoord2s PROTO :DWORD,:DWORD
glTexCoord2sv PROTO :DWORD
glTexCoord3d PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
glTexCoord3dv PROTO :DWORD
glTexCoord3f PROTO :DWORD,:DWORD,:DWORD
glTexCoord3fv PROTO :DWORD
glTexCoord3i PROTO :DWORD,:DWORD,:DWORD
glTexCoord3iv PROTO :DWORD
glTexCoord3s PROTO :DWORD,:DWORD,:DWORD
glTexCoord3sv PROTO :DWORD
glTexCoord4d PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
glTexCoord4dv PROTO :DWORD
glTexCoord4f PROTO :DWORD,:DWORD,:DWORD,:DWORD
glTexCoord4fv PROTO :DWORD
glTexCoord4i PROTO :DWORD,:DWORD,:DWORD,:DWORD
glTexCoord4iv PROTO :DWORD
glTexCoord4s PROTO :DWORD,:DWORD,:DWORD,:DWORD
glTexCoord4sv PROTO :DWORD
glTexCoordPointer PROTO :DWORD,:DWORD,:DWORD,:DWORD
glTexEnvf PROTO :DWORD,:DWORD,:DWORD
glTexEnvfv PROTO :DWORD,:DWORD,:DWORD
glTexEnvi PROTO :DWORD,:DWORD,:DWORD
glTexEnviv PROTO :DWORD,:DWORD,:DWORD
glTexGend PROTO :DWORD,:DWORD,:DWORD,:DWORD
glTexGendv PROTO :DWORD,:DWORD,:DWORD
glTexGenf PROTO :DWORD,:DWORD,:DWORD
glTexGenfv PROTO :DWORD,:DWORD,:DWORD
glTexGeni PROTO :DWORD,:DWORD,:DWORD
glTexGeniv PROTO :DWORD,:DWORD,:DWORD
glTexImage1D PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
glTexImage2D PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
glTexParameterf PROTO :DWORD,:DWORD,:DWORD
glTexParameterfv PROTO :DWORD,:DWORD,:DWORD
glTexParameteri PROTO :DWORD,:DWORD,:DWORD
glTexParameteriv PROTO :DWORD,:DWORD,:DWORD
glTexSubImage1D PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
glTexSubImage2D PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
glTranslated PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
glTranslatef PROTO :DWORD,:DWORD,:DWORD
glVertex2d PROTO :DWORD,:DWORD,:DWORD,:DWORD
glVertex2dv PROTO :DWORD
glVertex2f PROTO :DWORD,:DWORD
glVertex2fv PROTO :DWORD
glVertex2i PROTO :DWORD,:DWORD
glVertex2iv PROTO :DWORD
glVertex2s PROTO :DWORD,:DWORD
glVertex2sv PROTO :DWORD
glVertex3d PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
glVertex3dv PROTO :DWORD
glVertex3f PROTO :DWORD,:DWORD,:DWORD
glVertex3fv PROTO :DWORD
glVertex3i PROTO :DWORD,:DWORD,:DWORD
glVertex3iv PROTO :DWORD
glVertex3s PROTO :DWORD,:DWORD,:DWORD
glVertex3sv PROTO :DWORD
glVertex4d PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
glVertex4dv PROTO :DWORD
glVertex4f PROTO :DWORD,:DWORD,:DWORD,:DWORD
glVertex4fv PROTO :DWORD
glVertex4i PROTO :DWORD,:DWORD,:DWORD,:DWORD
glVertex4iv PROTO :DWORD
glVertex4s PROTO :DWORD,:DWORD,:DWORD,:DWORD
glVertex4sv PROTO :DWORD
glVertexPointer PROTO :DWORD,:DWORD,:DWORD,:DWORD
glViewport PROTO :DWORD,:DWORD,:DWORD,:DWORD
wglChoosePixelFormat PROTO :DWORD,:DWORD
wglCopyContext PROTO :DWORD,:DWORD,:DWORD
wglCreateContext PROTO :DWORD
wglCreateLayerContext PROTO :DWORD,:DWORD
wglDeleteContext PROTO :DWORD
wglDescribeLayerPlane PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
wglDescribePixelFormat PROTO :DWORD,:DWORD,:DWORD,:DWORD
wglGetCurrentContext PROTO
wglGetCurrentDC PROTO
wglGetDefaultProcAddress PROTO :DWORD
wglGetLayerPaletteEntries PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
wglGetPixelFormat PROTO :DWORD
wglGetProcAddress PROTO :DWORD
wglMakeCurrent PROTO :DWORD,:DWORD
wglRealizeLayerPalette PROTO :DWORD,:DWORD,:DWORD
wglSetLayerPaletteEntries PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
wglSetPixelFormat PROTO :DWORD,:DWORD,:DWORD
wglShareLists PROTO :DWORD,:DWORD
wglSwapBuffers PROTO :DWORD
wglSwapLayerBuffers PROTO :DWORD,:DWORD
wglSwapMultipleBuffers PROTO :DWORD,:DWORD
wglUseFontBitmapsA PROTO :DWORD,:DWORD,:DWORD,:DWORD
wglUseFontBitmaps equ <wglUseFontBitmapsA>

wglUseFontOutlinesA PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
wglUseFontOutlines equ <wglUseFontOutlinesA>


