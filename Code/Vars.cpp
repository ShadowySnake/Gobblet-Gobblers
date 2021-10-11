#include "includes.h"
#define Mare 2
#define MareInamic 5
#define Mediu 1
#define MediuInamic 4
#define Mica 0
#define MicaInamic 3
#define ANYWHERE 1
#define CASTIGAT 1
#define PIERDUT 2
bool online;
int dim_patrat;
int dragtype;
int seconds;
int minutes;
bool verificat=false;
SDL_Window* window;
SDL_Renderer* renderer;
SDL_Texture* timer;
SDL_Texture* BgTexture;
SDL_Texture* MatrixTexture;
SDL_Texture* foremenu;
SOCKET clientstabil;
SOCKET serverstabil;
SDL_Texture* PiesaTexture;
SDL_Texture* PiesaEnemyTexture;
SDL_Texture* starthosting;
SDL_Rect starthostingRect;
SDL_Texture* backhosting;
SDL_Rect backhostingRect;
SDL_Texture* TextureYourTurn;
SDL_Texture* TextureEnemyTurn;
SDL_Texture* selectlang;
SDL_Rect selectlangRect;

bool showlang=false;

SDL_Texture* ro_lang;
SDL_Texture* ro_lang_tr;
SDL_Rect ro_langRect;

SDL_Texture* fr_lang;
SDL_Texture* fr_lang_tr;
SDL_Rect fr_langRect;

SDL_Texture** ro_lang_actual;
SDL_Texture** fr_lang_actual;
SDL_Texture** eng_lang_actual;
SDL_Texture* howlangro;
SDL_Texture* howlangeng;
SDL_Texture* howlangfr;
SDL_Texture** howlang;
SDL_Rect howlangRect;
bool langing=false;
SDL_Rect backlang;
SDL_Rect menubuttonwin;

bool win=false;
bool lose=false;

SDL_Texture* eng_lang;
SDL_Texture* eng_lang_tr;
SDL_Rect eng_langRect;

SDL_Texture* hostText;
SDL_Rect hostTextRect;

SDL_Texture* clientText;
SDL_Rect clientTextRect;

SDL_Texture* firsthover;
SDL_Rect firsthoverRect;

SDL_Texture* randomText;
SDL_Rect randomTextRect;

SDL_Texture* avaible;
SDL_Texture* notavaible;
SDL_Texture* light;
SDL_Rect avrect;
bool showingen=false;
bool conout=false;
SDL_Texture* back2;
SDL_Rect back2RectDest;
SDL_Rect back2RectSrc;

SDL_Event e;
SDL_Rect bgrect;
SDL_Rect mt;

SDL_Texture* lantable;
SDL_Rect lantableRect;
SDL_Texture* waitingtexture;
SDL_Rect waitingRect;
SDL_Texture* conectlabel;
SDL_Rect conectlabelRect;
SDL_Texture* labelhover;
SDL_Rect labelhoverRect;
SDL_Texture* lanbuton[5];
SDL_Texture* flash;
SDL_Rect dirconectcon;
SDL_Rect dirconectback;
SDL_Rect roundsBox;
SDL_Texture* rounds;
SDL_Rect roundsRect;

SDL_Texture* uparrow;
SDL_Texture* downarrow;
SDL_Rect uparrowRect;
SDL_Rect downarrowRect;

int runde=1;
SDL_Rect flashRect;
SDL_Rect lanbutonRect[5];
bool searching=false;
bool flashing=false;
SDL_Rect foremenuRect;
SDL_Rect pieseRect[6];
SDL_Rect *item_dragging;
SDL_Rect piesa_initiala[3];
SOCKET client;
int prevstate=SDL_KEYDOWN;
Uint32 timeout;
SDL_Rect TimerRect;
SDL_Rect text[3];
char inp[511];
char textip[20];
SDL_Rect turn;
SDL_Texture* TexturaText[3];
Uint32 timepast;
bool gazda=false;
short cont;
short incepe=1;
UINT32 prev=0;
SOCKET server;
SOCKET request;
bool used=false;
bool ipfocus=false;
SDL_Rect backconection;
SDL_Texture* TextWaiting;
SDL_Rect TextWaitingRect;
SDL_Texture* waitinghosting;
int ipready=-1;
int linieonmatrice;
char c[10][20];
char names[10][20];
int lg;
int coloanaonmatrice;
bool running=true;
SDL_Texture* gasite[10];
SDL_Rect gasiteRect[10];
SDL_Texture* hovertext;
SDL_Rect hovertextRect;
bool placing=false;
SDL_Texture* menu;
SDL_Rect menuRect;
bool itemonmatrice;
int a=0;
int placed_me[3]={0};
int placed_enemy[3]={0};
bool yourturn=true;
bool playing=false;
bool lanwindow=false;
bool isPlacing=false;
bool waiting=false;
bool focus=false;
bool directconect=false;
bool waitrespinse=false;
SDL_Texture* textbox;
SDL_Rect textboxRect;
SDL_Color white={255,255,255};
SDL_Color black={0,0,0};
SDL_Color green={0,255,0};
SDL_Color red={255,0,0};
short player=0;
short enemy=0;
SDL_Texture* maxim;
SDL_Rect maximRect;
short numarmaxim=3;
SDL_Texture* hover;
SDL_Texture* ip;
SDL_Texture* score;
SDL_Rect ScoreRect;
SDL_Rect ipRect;
SDL_Rect hoverRect;
SDL_Texture* buton[5];
SDL_Rect butonRect[5];
SDL_Texture* scoreplayer;
SDL_Texture* scoreenemy;
SDL_Rect scoreplayerRect;
SDL_Rect scoreenemyRect;
int pozitii[3][2];
bool showing=false;
Uint32 timeshowing;
Uint32 timeback;
Uint32 timeresponse;
SDL_Texture* servername;
SDL_Rect servernameBox;
SDL_Rect servernameRect;
char servernameText[60];
bool hosting=false;
bool focus2=false;
SDL_Rect timesrc;
SDL_Rect timedest;
SDL_Rect scoretable;
bool conlost=false;
SDL_Texture* conTexture;
SDL_Rect conRect;
int contor=-1;
SDL_Texture* timeandscore;
SDL_Rect timeandscoreRect;
SDL_Texture* youwon;
SDL_Rect youwonRect;
SDL_Texture* youlost;
SDL_Rect youlostRect;
struct joc
{
    bool piesa[6]={false};

}m[3][3];
