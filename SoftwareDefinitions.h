#pragma once
#include <regex>


#define Reading   1
#define Writing   2
#define Show      20
#define OnExitSoftware  3
#define Adding  4
#define Filling   5
#define Lname   6
#define Fname   7
#define Sname   8
#define Country   9
#define Phone   10
#define Mail   11
#define SLname   12
#define SFname   13
#define SCoun   14
#define CCoun   15
#define CPhone   16
#define CMail   17
#define FLname   18
#define FFname  19
#define OnClearFields   21
#define OnReadFields    22
#define OnClearEnter    23
#define ReadDB          24
#define SaveDB          25


#define TextBufferSize  500
#define TextBuff 50
#define TextBuffLname  50
#define TextBuffFname  50
#define TextBuffSname  50
#define TextBuffCoun  10
#define TextBuffPhone  50
#define TextBuffMail  50

char Buffer[TextBufferSize];
char Buff[TextBuff];
char BuffL[TextBuffLname];
char BuffF[TextBuffFname];
char BuffS[TextBuffSname];
char BuffC[TextBuffCoun];
char BuffP[TextBuffPhone];
char BuffM[TextBuffMail];

int CharsRead;
int CharsLname;
int CharsFname;
int CharsSname;
int Length;
char* temp1;
bool job;
std::regex tx("([0-9]{2})(\\-[0-9]{3})(\\-[0-9]{2})(\\-[0-9]{2})");//регулярное выражение для телефона
int k;
int k1;
int k2;

HWND hStaticControl;
HWND hEnterControl;
HWND hEditControl;
HWND hLname;
HWND hFname;
HWND hSname;
HWND hCoun;
HWND hPhone;
HWND hMail;
HWND temp;

char filename[260];
OPENFILENAMEA ofn;

LRESULT CALLBACK SoftwareMainProcedure(HWND hWnd, UINT msg, WPARAM wp, LPARAM lp);
WNDCLASS NewWindowClass(HBRUSH BGColor, HCURSOR Cursor, HINSTANCE hInst, HICON Icon, LPCWSTR Name, WNDPROC Procedure);

void MainWndAddWidgets(HWND hWnd);
void MainWndAddMenus(HWND hWnd);
void SetOpenFileParams(HWND hWnd);
void SaveData(LPCSTR(path));
void LoadData(LPCSTR(path));

LRESULT CALLBACK SoftwareEditProcedure(HWND hWnd1, UINT msg1, WPARAM wp1, LPARAM lp1);
WNDCLASS NewEditClass(HBRUSH BGColor, HCURSOR Cursor, HINSTANCE hInst1, HICON Icon1, LPCWSTR Name1, WNDPROC Procedure1);

void EditWndAddWidgets(HWND hWnd1);
void EditWndAddMenus(HWND hWnd1);
