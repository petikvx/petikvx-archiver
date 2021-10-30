#define	VBS_WORM	101
#define HTML_VIRUS	102
#define IDM_ABOUT	103
#define IDM_CLOSE	104
#define WEL		105

// VBS Generator
#define ID_NAME		201
#define IDM_NAME	202
#define ID_AUTHOR	203
#define IDM_AUTHOR	204
#define ID_COPY		205
#define IDM_COPY	206
#define ID_REG		207
#define IDM_REG		208
#define ID_SUBJECT	209
#define IDM_SUBJECT	210
#define ID_BODY		211
#define IDM_BODY	212
#define IDM_GENWORM	401

// HTML Generator
#define ID_NAMEV	301
#define IDM_NAMEV	302
#define ID_AUTHORV	303
#define IDM_AUTHORV	304
#define ID_FOLDER1	305
#define IDM_FOLDER1	306
#define ID_FOLDER2	307
#define IDM_FOLDER2	308
#define ID_FOLDER3	309
#define IDM_FOLDER3	310
#define ID_TITLE	311
#define IDM_TITLE	312
#define ID_OWNER	313
#define IDM_OWNER	314
#define ID_ORG		315
#define IDM_ORG		316

#define IDM_GENVIRUS	402

BOOL CALLBACK MainProc(HWND, UINT, WPARAM, LPARAM);
LRESULT CALLBACK MainWorm(HWND, UINT, WPARAM, LPARAM);
LRESULT CALLBACK MainVirus(HWND, UINT, WPARAM, LPARAM);