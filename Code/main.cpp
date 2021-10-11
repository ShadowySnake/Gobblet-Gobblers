#include "Includes.h"
#include "Vars.h"
#include "Server.h"
void CreateText(SDL_Texture** texture,const char* c,int &h,int &w,int marime,SDL_Color culoare)
{
    TTF_Font* font=TTF_OpenFont("fonts/arial.ttf",marime);
    SDL_Surface* surf=TTF_RenderText_Blended(font,c,culoare);
    h=surf->h;
    w=surf->w;
    *texture=SDL_CreateTextureFromSurface(renderer,surf);
    SDL_FreeSurface(surf);
    TTF_CloseFont(font);
}
void Play_Effect(int i,int volum)
{
    Mix_FreeChunk(soundEffect);
    if(i == 0)
        {
            soundEffect = Mix_LoadWAV("Music/Bloop.wav"); // click sound
            Mix_VolumeChunk(soundEffect, volum);
        }
    else
    if(i == 1)
        {
            soundEffect = Mix_LoadWAV("Music/Win.wav"); // win sound
            Mix_VolumeChunk(soundEffect, volum);
        }
    else
    if(i == 2)
        {
            soundEffect = Mix_LoadWAV("Music/Loss.wav"); // loss sound
            Mix_VolumeChunk(soundEffect, volum);
        }
     if(i == 3)
        {
            soundEffect = Mix_LoadWAV("Music/winround.wav"); // win sound
            Mix_VolumeChunk(soundEffect, volum);
        }
    if(i == 4)
        {
            soundEffect = Mix_LoadWAV("Music/lostround.wav"); // win sound
            Mix_VolumeChunk(soundEffect, volum);
        }
    Mix_PlayChannel(-1, soundEffect, 0);
}
void InitWindow()
{
    SDL_Init(SDL_INIT_EVERYTHING);
    TTF_Init();
    IMG_Init(IMG_INIT_PNG);
    Mix_OpenAudio(44100,MIX_DEFAULT_FORMAT,2,2048);
    window=SDL_CreateWindow("Gobblet Gobblers",SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED,1000,600,0);
    renderer=SDL_CreateRenderer(window,-1,0);
    SDL_SetRenderDrawColor(renderer,255,255,255,0);
}
void Upload(SDL_Texture** textura,const char* c,int *h=NULL,int *w=NULL)
{
    SDL_Surface* surf=IMG_Load(c);
    if(h!=NULL)
        *h=surf->h;
    if(w!=NULL)
        *w=surf->w;
    *textura=SDL_CreateTextureFromSurface(renderer,surf);
    SDL_FreeSurface(surf);
}
void HoverOnButton(SDL_Rect* hover,SDL_Rect button)
{
    hover->x=button.x-10;
    hover->y=button.y-10;
    hover->h=button.h+20;
    hover->w=button.w+20;
}
void UploadTexturi()
{
    Upload(&BgTexture,"img/background.jpg");
    Upload(&MatrixTexture,"img/matrice.png");
    Upload(&PiesaTexture,"img/piesa_mare.png");
    Upload(&PiesaEnemyTexture,"img/piesa_mare_enemy.png");
    Upload(&TextureYourTurn,"img/YourTurn.png");
    Upload(&TextureEnemyTurn,"img/EnemyTurn.png");
    Upload(&avaible,"img/avaible.png");
    Upload(&notavaible,"img/notavaible.png");
    Upload(&foremenu,"img/foreground.png");
    Upload(&hover,"img/hover.png");
    Upload(&buton[0],"img/start.png",&butonRect[0].h,&butonRect[0].w);
    Upload(&buton[1],"img/lan.png",&butonRect[1].h,&butonRect[1].w);
    Upload(&buton[2],"img/options.png",&butonRect[2].h,&butonRect[2].w);
    Upload(&buton[3],"img/howto.png",&butonRect[3].h,&butonRect[3].w);
    Upload(&buton[4],"img/exit.png",&butonRect[4].h,&butonRect[4].w);
    Upload(&back2,"img/background2.png");
    Upload(&lantable,"img/LanTable.png",&lantableRect.h,&lantableRect.w);
    Upload(&lanbuton[0],"img/Directconnect.png",&lanbutonRect[0].h,&lanbutonRect[0].w);
    Upload(&lanbuton[1],"img/HostServer.png",&lanbutonRect[1].h,&lanbutonRect[1].w);
    Upload(&lanbuton[2],"img/Connect.png",&lanbutonRect[2].h,&lanbutonRect[2].w);
    Upload(&lanbuton[3],"img/refresh.png",&lanbutonRect[3].h,&lanbutonRect[3].w);
    Upload(&lanbuton[4],"img/Back.png",&lanbutonRect[4].h,&lanbutonRect[4].w);
    Upload(&waitingtexture,"img/Waiting.png",&waitingRect.h,&waitingRect.w);
    Upload(&textbox,"img/textbox.png",&textboxRect.h,&textboxRect.w);
    Upload(&conectlabel,"img/conectlabel.png",&conectlabelRect.h,&conectlabelRect.w);
    Upload(&labelhover,"img/hoverlabel.png",&labelhoverRect.h,&labelhoverRect.w);
    Upload(&hovertext,"img/hovertext.png",&hovertextRect.h,&hovertextRect.w);
    Upload(&starthosting,"img/starthosting.png",&starthostingRect.h,&starthostingRect.w);
    Upload(&backhosting,"img/backhosting.png",&backhostingRect.h,&backhostingRect.w);
    Upload(&clientText,"img/ClientText.png",&clientTextRect.h,&clientTextRect.w);
    Upload(&hostText,"img/HostText.png",&hostTextRect.h,&hostTextRect.w);
    Upload(&randomText,"img/RandomText.png",&randomTextRect.h,&randomTextRect.w);
    Upload(&firsthover,"img/FirstHover.png",&firsthoverRect.h,&firsthoverRect.w);
    Upload(&uparrow,"img/uparrow.png",&uparrowRect.h,&uparrowRect.w);
    Upload(&downarrow,"img/downarrow.png",&downarrowRect.h,&downarrowRect.w);
    Upload(&waitinghosting,"img/waitinghosting.png");
    Upload(&menu,"img/menu.png",&menuRect.h,&menuRect.w);
    Upload(&selectlang,"img/selectlang.png",&selectlangRect.h,&selectlangRect.w);
    Upload(&ro_lang,"img/ro.png",&ro_langRect.h,&ro_langRect.w);
    Upload(&ro_lang_tr,"img/ro_tr.png",NULL,NULL);
    Upload(&fr_lang,"img/fr.png",&fr_langRect.h,&fr_langRect.w);
    Upload(&fr_lang_tr,"img/fr_tr.png",NULL,NULL);
    Upload(&eng_lang,"img/eng.png",&eng_langRect.h,&eng_langRect.w);
    Upload(&eng_lang_tr,"img/eng_tr.png",NULL,NULL);
    Upload(&howlangro,"img/howlangro.png",&howlangRect.h,&howlangRect.w);
    Upload(&howlangeng,"img/howlangeng.png",NULL,NULL);
    Upload(&howlangfr,"img/howlangfr.png",NULL,NULL);
    Upload(&timeandscore,"img/timeandscore.png",&timeandscoreRect.h,&timeandscoreRect.w);
    Upload(&youwon,"img/youwon.png",&youwonRect.h,&youwonRect.w);
    Upload(&youlost,"img/youlost.png",&youlostRect.h,&youlostRect.w);
    Upload(&conTexture,"img/conlost.png",&conRect.h,&conRect.w);
    Upload(&ScreenOptions,"img/ScreenOptions.png",NULL,NULL);
    Upload(&soundicon,"img/soundicon.png",&soundiconRect.h,&soundiconRect.w);
    Upload(&muteicon,"img/muteicon.png",NULL,NULL);
    Upload(&volumeblank,"img/volumeblank.png",&volumeblankRect.h,&volumeblankRect.w);
    Upload(&volumeorange,"img/volumeorange.png",&volumeorangeRect.h,&volumeorangeRect.w);
    Upload(&normal,"img/normal.png",&normalRect.h,&normalRect.w);
    Upload(&hard,"img/hard.png",&hardRect.h,&hardRect.w);
    bgm=Mix_LoadMUS("Music/bgm.mp3");
    sunet=volumeorangeRect.w;
}
bool incadrare(SDL_Rect incadrat,SDL_Rect plan)
{
    if(incadrat.x>=plan.x && incadrat.x+incadrat.w <= plan.x + plan.w)
        if(incadrat.y>=plan.y && incadrat.y+incadrat.h <= plan.y + plan.h)
            return true;
    return false;
}
bool RightonCLick()
{
    if(e.type==SDL_MOUSEBUTTONDOWN)
        if(e.button.button==SDL_BUTTON_RIGHT)
            return true;
    return false;
}
void setDimensiuni(SDL_Rect* rect,int x,int y,int h,int w)
{
    if(x!=NULL)
        rect->x=x;
    if(y!=NULL)
        rect->y=y;
    if(w!=NULL)
        rect->w=w;
    if(h!=NULL)
        rect->h=h;
}
void setDimensiuniTextBox(SDL_Rect* boxRect,SDL_Rect* textRect,int x,int y,int h,int w)
{
    setDimensiuni(boxRect,x,y,h,w);
    textRect->x=x+3;
    textRect->y=y+5;
}

void Dimensionare()
{

    setDimensiuni(&bgrect,0,0,600,1000);

    setDimensiuni(&mt,120,120,420,420);
    setDimensiuni(&foremenuRect,0,0,600,1000);
    setDimensiuni(&avrect,-100,-100,140,140);

    setDimensiuni(&piesa_initiala[2],900,280,90,90);
    setDimensiuni(&piesa_initiala[1],908,400,75,75);
    setDimensiuni(&piesa_initiala[0],915,500,60,60);

    for(int i=0;i<=2;i++)
    {
        setDimensiuni(&pieseRect[i],-100,-100,60+i*15,60+i*15);
        setDimensiuni(&pieseRect[i+3],-100,-100,60+i*15,60+i*15);
    }

    setDimensiuni(&turn,670,170,40,320);

    for(int i=0;i<3;i++)
        setDimensiuni(&text[i],piesa_initiala[i].x-70,piesa_initiala[i].y+piesa_initiala[i].h/2-text[i].h/2,0,0);

    setDimensiuni(&TimerRect,600,30,30,127);

    for(int i=0;i<=3;i++)
    setDimensiuni(&butonRect[i],370,150+i*100,NULL,NULL);
    setDimensiuni(&butonRect[4],800,30,NULL,NULL);
    setDimensiuni(&back2RectDest,0,0,600,1000);
    setDimensiuni(&back2RectSrc,0,0,600,1000);
    setDimensiuni(&lantableRect,100,100,NULL,NULL);
    setDimensiuni(&lanbutonRect[0],200,150,NULL,NULL);
    setDimensiuni(&lanbutonRect[1],lanbutonRect[0].x+lanbutonRect[0].w+100,150,NULL,NULL);
    setDimensiuni(&lanbutonRect[2],150,450,NULL,NULL);
    setDimensiuni(&lanbutonRect[3],lanbutonRect[2].x+lanbutonRect[2].w+50,450,NULL,NULL);
    setDimensiuni(&lanbutonRect[4],lanbutonRect[3].x+lanbutonRect[3].w+50,450,NULL,NULL);
    setDimensiuni(&waitingRect,200,150,NULL,NULL);
    setDimensiuniTextBox(&textboxRect,&ipRect,300,350,NULL,NULL);
    setDimensiuni(&conectlabelRect,210,210,NULL,NULL);
    setDimensiuni(&labelhoverRect,290,345,NULL,NULL);
    setDimensiuni(&flashRect,303,353,NULL,NULL);
    setDimensiuni(&dirconectcon,570,290,lanbutonRect[2].h,lanbutonRect[2].w);
    setDimensiuni(&dirconectback,570,390,lanbutonRect[4].h,lanbutonRect[4].w);
    setDimensiuni(&hovertextRect,200,317,NULL,NULL);
    setDimensiuniTextBox(&servernameBox,&servernameRect,250,230,textboxRect.h,textboxRect.w);
    setDimensiuni(&starthostingRect,240,430,NULL,NULL);
    setDimensiuni(&backhostingRect,550,430,NULL,NULL);
    setDimensiuni(&clientTextRect,250,350,NULL,NULL);
    setDimensiuni(&hostTextRect,335,350,NULL,NULL);
    setDimensiuni(&randomTextRect,420,350,NULL,NULL);
    setDimensiuni(&uparrowRect,640,280,NULL,NULL);
    setDimensiuni(&downarrowRect,640,370,NULL,NULL);
    setDimensiuniTextBox(&roundsBox,&roundsRect,620,320,textboxRect.h,75);
    setDimensiuni(&backconection,420,420,backhostingRect.h,backhostingRect.w);
    setDimensiuni(&TextWaitingRect,260,300,NULL,NULL);
    setDimensiuni(&menuRect,30,20,NULL,NULL);
    setDimensiuni(&ScoreRect,600,100,NULL,NULL);
    setDimensiuni(&scoreplayerRect,725,103,NULL,NULL);
    setDimensiuni(&scoreenemyRect,785,103,NULL,NULL);
    setDimensiuni(&maximRect,270,30,NULL,NULL);
    setDimensiuni(&selectlangRect,0,0,NULL,NULL);
    setDimensiuni(&ro_langRect,190,250,NULL,NULL);
    setDimensiuni(&fr_langRect,640,250,NULL,NULL);
    setDimensiuni(&eng_langRect,410,250,NULL,NULL);
    setDimensiuni(&backlang,700,500,backhostingRect.h,backhostingRect.w);
    setDimensiuni(&howlangRect,97,10,NULL,NULL);
    setDimensiuni(&menubuttonwin,390,400,menuRect.h,menuRect.w);
    setDimensiuni(&timeandscoreRect,220,250,NULL,NULL);
    setDimensiuni(&youwonRect,330,170,NULL,NULL);
    setDimensiuni(&youlostRect,330,170,NULL,NULL);
    setDimensiuni(&conRect,330,170,NULL,NULL);
    setDimensiuni(&soundiconRect,150,200,NULL,NULL);
    setDimensiuni(&volumeblankRect,250,220,NULL,NULL);
    setDimensiuni(&volumeorangeRect,volumeblankRect.x+2,volumeblankRect.y,NULL,NULL);
    setDimensiuni(&normalRect,200,370,NULL,NULL);
    setDimensiuni(&hardRect,400,370,NULL,NULL);
    setDimensiuniTextBox(&singlepTextbox,&singlepTextRect,700,300,textboxRect.h,75);
    setDimensiuni(&uparrowsg,720,250,uparrowRect.h,uparrowRect.w);
    setDimensiuni(&downarrowsg,720,360,downarrowRect.h,downarrowRect.w);
    singlepTextRect.x=singlepTextRect.x+27;
    dim_patrat=mt.h/3;
}
void RenderPiese()
{
    SDL_Rect r;
    for(int i=0;i<3;i++)
            for(int j=0;j<3;j++)
                for(int k=0;k<=2;k++)
                   {
                       if(m[i][j].piesa[k])
                        {
                            r.y=i*dim_patrat+mt.y+ (dim_patrat-pieseRect[k].h)/2;
                            r.x=j*dim_patrat+mt.x+ (dim_patrat-pieseRect[k].w)/2;
                            r.h=pieseRect[k].h;
                            r.w=pieseRect[k].w;
                            SDL_RenderCopy(renderer,PiesaTexture,NULL,&r);
                        }
                        if(m[i][j].piesa[k+3])
                        {
                            r.y=i*dim_patrat+mt.y+ (dim_patrat-pieseRect[k+3].h)/2;
                            r.x=j*dim_patrat+mt.x+ (dim_patrat-pieseRect[k+3].w)/2;
                            r.h=pieseRect[k+3].h;
                            r.w=pieseRect[k+3].w;
                            SDL_RenderCopy(renderer,PiesaEnemyTexture,NULL,&r);
                        }
                   }
    if(showing)
    {
        SDL_Rect r;
        r.h=avrect.h;
        r.w=avrect.w;
        for(int i=0;i<3;i++)
        {
            r.x=mt.x+pozitii[i][1]*dim_patrat;
            r.y=mt.y+pozitii[i][0]*dim_patrat;
            SDL_RenderCopy(renderer,avaible,NULL,&r);
        }
    }
    else
    if(showingen)
    {
        SDL_Rect r;
        r.h=avrect.h;
        r.w=avrect.w;
        for(int i=0;i<3;i++)
        {
            r.x=mt.x+pozitii[i][1]*dim_patrat;
            r.y=mt.y+pozitii[i][0]*dim_patrat;
            SDL_RenderCopy(renderer,notavaible,NULL,&r);
        }
    }
}
void render()
{
        SDL_RenderClear(renderer);
        if(playing)
        {
            SDL_RenderCopy(renderer,BgTexture,NULL,&bgrect);
            SDL_RenderCopy(renderer,MatrixTexture,NULL,&mt);
            RenderPiese();
            if(isPlacing)
                SDL_RenderCopy(renderer,light,NULL,&avrect);
            for(int i=0;i<=2;i++)
                SDL_RenderCopy(renderer,PiesaTexture,NULL,&piesa_initiala[i]);

            for(int i=0;i<3;i++)
                SDL_RenderCopy(renderer,TexturaText[i],NULL,&text[i]);

            if(yourturn)
                SDL_RenderCopy(renderer,TextureYourTurn,NULL,&turn);
            else
                SDL_RenderCopy(renderer,TextureEnemyTurn,NULL,&turn);
            if(placing)
                SDL_RenderCopy(renderer,hover,NULL,&hoverRect);
            SDL_RenderCopy(renderer,menu,NULL,&menuRect);
            SDL_RenderCopy(renderer,timer,NULL,&TimerRect);
            SDL_RenderCopy(renderer,score,NULL,&ScoreRect);
            SDL_RenderCopy(renderer,scoreplayer,NULL,&scoreplayerRect);
            SDL_RenderCopy(renderer,scoreenemy,NULL,&scoreenemyRect);
            SDL_RenderCopy(renderer,maxim,NULL,&maximRect);
            if(used)
                SDL_RenderCopy(renderer,PiesaTexture,NULL,item_dragging);
            if(win || lose || conlost)
            {
                SDL_RenderCopy(renderer,waitinghosting,NULL,&waitingRect);
                if(win)
                    SDL_RenderCopy(renderer,youwon,NULL,&youwonRect);
                else
                if(lose)
                    SDL_RenderCopy(renderer,youlost,NULL,&youlostRect);
                else
                    SDL_RenderCopy(renderer,conTexture,NULL,&conRect);
                SDL_RenderCopy(renderer,timeandscore,NULL,&timeandscoreRect);
                SDL_RenderCopy(renderer,timer,&timesrc,&timedest);
                SDL_RenderCopy(renderer,scoreplayer,NULL,&scoretable);
                if(placing)
                    SDL_RenderCopy(renderer,hover,NULL,&hoverRect);
                SDL_RenderCopy(renderer,menu,NULL,&menubuttonwin);
            }

        }
        else
        {
            SDL_RenderCopy(renderer,back2,&back2RectSrc,&back2RectDest);
            SDL_RenderCopy(renderer,foremenu,NULL,&foremenuRect);
            if(isPlacing)
                SDL_RenderCopy(renderer,hover,NULL,&hoverRect);
            for(int i=0;i<=4;i++)
                SDL_RenderCopy(renderer,buton[i],NULL,&butonRect[i]);
            if(lanwindow)
                {
                    SDL_RenderCopy(renderer,lantable,NULL,&lantableRect);
                    if(isPlacing)
                        SDL_RenderCopy(renderer,hover,NULL,&hoverRect);
                    for(int i=0;i<=4;i++)
                        SDL_RenderCopy(renderer,lanbuton[i],NULL,&lanbutonRect[i]);
                    if(ipfocus)
                        SDL_RenderCopy(renderer,hovertext,NULL,&hovertextRect);
                    for(int i=0;i<lg;i++)
                        SDL_RenderCopy(renderer,gasite[i],NULL,&gasiteRect[i]);
                    if(waiting)
                        {
                            if(hosting)
                            {
                                SDL_RenderCopy(renderer,waitinghosting,NULL,&waitingRect);
                                if(isPlacing)
                                    SDL_RenderCopy(renderer,hover,NULL,&hoverRect);
                                SDL_RenderCopy(renderer,backhosting,NULL,&backconection);
                                SDL_RenderCopy(renderer,TextWaiting,NULL,&TextWaitingRect);
                            }
                            else
                            {
                                SDL_RenderCopy(renderer,waitingtexture,NULL,&waitingRect);
                                if(focus2)
                                    SDL_RenderCopy(renderer,labelhover,NULL,&labelhoverRect);
                                SDL_RenderCopy(renderer,textbox,NULL,&servernameBox);
                                if(servernameText[0]!=NULL)
                                    SDL_RenderCopy(renderer,servername,NULL,&servernameRect);
                                if(focus2 && flashing)
                                    SDL_RenderCopy(renderer,flash,NULL,&flashRect);
                                 if(isPlacing)
                                    SDL_RenderCopy(renderer,hover,NULL,&hoverRect);
                                SDL_RenderCopy(renderer,starthosting,NULL,&starthostingRect);
                                SDL_RenderCopy(renderer,backhosting,NULL,&backhostingRect);
                                SDL_RenderCopy(renderer,firsthover,NULL,&firsthoverRect);
                                SDL_RenderCopy(renderer,clientText,NULL,&clientTextRect);
                                SDL_RenderCopy(renderer,hostText,NULL,&hostTextRect);
                                SDL_RenderCopy(renderer,randomText,NULL,&randomTextRect);
                                SDL_RenderCopy(renderer,uparrow,NULL,&uparrowRect);
                                SDL_RenderCopy(renderer,downarrow,NULL,&downarrowRect);
                                SDL_RenderCopy(renderer,textbox,NULL,&roundsBox);
                                SDL_RenderCopy(renderer,rounds,NULL,&roundsRect);
                            }
                        }
                    if(directconect)
                        {
                            SDL_RenderCopy(renderer,conectlabel,NULL,&conectlabelRect);
                            if(focus)
                                SDL_RenderCopy(renderer,labelhover,NULL,&labelhoverRect);
                            SDL_RenderCopy(renderer,textbox,NULL,&textboxRect);
                            if(textip[0]!=NULL)
                                SDL_RenderCopy(renderer,ip,NULL,&ipRect);
                            if(focus && flashing)
                                SDL_RenderCopy(renderer,flash,NULL,&flashRect);
                            if(isPlacing)
                                SDL_RenderCopy(renderer,hover,NULL,&hoverRect);
                            SDL_RenderCopy(renderer,lanbuton[2],NULL,&dirconectcon);
                            SDL_RenderCopy(renderer,lanbuton[4],NULL,&dirconectback);
                        }
                }
                else
                if(showlang)
                {
                    SDL_RenderCopy(renderer,selectlang,NULL,&selectlangRect);
                    SDL_RenderCopy(renderer,*ro_lang_actual,NULL,&ro_langRect);
                    SDL_RenderCopy(renderer,*fr_lang_actual,NULL,&fr_langRect);
                    SDL_RenderCopy(renderer,*eng_lang_actual,NULL,&eng_langRect);
                    if(isPlacing)
                        SDL_RenderCopy(renderer,hover,NULL,&hoverRect);
                    SDL_RenderCopy(renderer,backhosting,NULL,&backlang);

                }
                else
                if(langing)
                {
                    SDL_RenderCopy(renderer,*howlang,NULL,&howlangRect);
                    if(isPlacing)
                        SDL_RenderCopy(renderer,hover,NULL,&hoverRect);
                    SDL_RenderCopy(renderer,backhosting,NULL,&backlang);
                }
                else
                if(options)
                {
                    SDL_RenderCopy(renderer,ScreenOptions,NULL,NULL);
                    if(isPlacing)
                        SDL_RenderCopy(renderer,hover,NULL,&hoverRect);
                    SDL_RenderCopy(renderer,backhosting,NULL,&backlang);
                    SDL_RenderCopy(renderer,soundicon,NULL,&soundiconRect);
                    if(mute)
                        SDL_RenderCopy(renderer,muteicon,NULL,&soundiconRect);
                    SDL_RenderCopy(renderer,volumeblank,NULL,&volumeblankRect);
                    SDL_RenderCopy(renderer,volumeorange,NULL,&volumeorangeRect);
                    SDL_RenderCopy(renderer,firsthover,NULL,&firsthoverRect);
                    SDL_RenderCopy(renderer,normal,NULL,&normalRect);
                    SDL_RenderCopy(renderer,hard,NULL,&hardRect);
                    SDL_RenderCopy(renderer,textbox,NULL,&singlepTextbox);
                    SDL_RenderCopy(renderer,uparrow,NULL,&uparrowsg);
                    SDL_RenderCopy(renderer,downarrow,NULL,&downarrowsg);
                    SDL_RenderCopy(renderer,singlepTextTexture,NULL,&singlepTextRect);
                }
        }
        SDL_RenderPresent(renderer);
}
void dragging(SDL_Rect &item)
{
    int x,y;
    SDL_GetMouseState(&x,&y);
    item.x=x- item.w/2;
    item.y=y- item.h/2;
}
bool valid(int linie,int coloana,int tip)
{
    tip=tip%3;
    for(int i=tip;i<=Mare;i++)
        if(m[linie][coloana].piesa[i] || m[linie][coloana].piesa[i+3])
            return false;
    return true;

}
void CtoP(SDL_Rect item,int &x,int &y)
{
        x=(item.y-mt.y)/dim_patrat;
        y=(item.x-mt.x)/dim_patrat;
}
void CtoP(int crdx,int crdy,int &x,int &y)
{
    x=(crdy-mt.y)/dim_patrat;
    y=(crdx-mt.x)/dim_patrat;
}
void ItemOnMatrix(int tip,int linie,int coloana)
{
   m[linie][coloana].piesa[tip]=true;
}
int getfirst(int linie,int coloana)
{
    for(int i=Mare;i>=Mica;i--)
        if(m[linie][coloana].piesa[i])
            return i;
        else
        if(m[linie][coloana].piesa[i+3])
            return i+3;
    return -1;
}
int testare(int linie,int coloana)
{
    int me=0,enemy=0;
    for(int i=0;i<3;i++)
    {
        int tip=getfirst(linie,i);
        pozitii[i][0]=linie;
        pozitii[i][1]=i;
        if(tip!=-1)
            if(tip<=2)
                me++;
            else
                enemy++;
    }
    if(me==3)
        return CASTIGAT;
    else
    if(enemy==3)
        return PIERDUT;
    me=enemy=0;

    for(int i=0;i<3;i++)
    {
        int tip=getfirst(i,coloana);
        pozitii[i][0]=i;
        pozitii[i][1]=coloana;
        if(tip!=-1)
            if(tip<=2)
                me++;
            else
                enemy++;
    }
    if(me==3)
        return CASTIGAT;
    else
    if(enemy==3)
        return PIERDUT;

    me=enemy=0;
    for(int i=0;i<3;i++)
    {
        int tip=getfirst(i,i);
        pozitii[i][0]=i;
        pozitii[i][1]=i;
        if(tip!=-1)
            if(tip<=2)
                me++;
            else
                enemy++;
    }
    if(me==3)
        return CASTIGAT;
    else
    if(enemy==3)
        return PIERDUT;

    me=enemy=0;
    for(int i=0;i<3;i++)
    {
        int tip=getfirst(i,2-i);
        pozitii[i][0]=i;
        pozitii[i][1]=2-i;
        if(tip!=-1)
            if(tip<=2)
                me++;
            else
                enemy++;
    }
    if(me==3)
        return CASTIGAT;
    else
    if(enemy==3)
        return PIERDUT;
    return 0;
}
bool onHover(SDL_Rect rect)
{
    int x,y;
    SDL_GetMouseState(&x,&y);
    if(x>=rect.x && x<=rect.x+rect.w && y>= rect.y && y<= rect.y+rect.h)
        return true;
    return false;
}
void setdragging(SDL_Rect **item_dragging,int tip)
{
   *item_dragging=&pieseRect[tip];
}
bool Ticks(Uint32 &time,unsigned int miliseconds)
{
    if(SDL_GetTicks()-time>=miliseconds)
    {
        time=SDL_GetTicks();
        return true;
    }
    return false;
}

void Count(int &counter,int limit,int reset)
{
    counter++;
    if(counter>=limit)
        counter=reset;
}
void typing(char* text,SDL_Texture** TexturaText,SDL_Rect* RectText,SDL_Rect textboxRect,int fontsize)
{
    if(e.type==SDL_TEXTINPUT)
    {
        if(flashRect.x+flashRect.w<textboxRect.x+textboxRect.w-10)
        {
            strcat(text,e.text.text);
            CreateText(TexturaText,text,RectText->h,RectText->w,fontsize,black);
            flashRect.x=RectText->x+RectText->w;
            flashing=true;
            timepast=SDL_GetTicks();
        }
    }
    if(e.type==SDL_KEYDOWN && e.key.keysym.sym==SDLK_BACKSPACE)
    {
         if(text[1]!=NULL)
         {
            text[strlen(text)-1]=NULL;
            CreateText(TexturaText,text,RectText->h,RectText->w,fontsize,black);
            flashRect.x=RectText->x+RectText->w;
            flashing=true;
            timepast=SDL_GetTicks();
         }
        else
        {
            text[0]=NULL;
            flashRect.x=RectText->x;
        }
    }
}
void reset()
{
    isPlacing=false;
    for(int i=0;i<=2;i++)
        {
            CreateText(&TexturaText[i],"2x",text[i].h,text[i].w,40,white);
            setDimensiuni(&text[i],piesa_initiala[i].x-70,piesa_initiala[i].y+piesa_initiala[i].h/2-text[i].h/2,text[i].h,text[i].w);
        }

    for(int i=0;i<=2;i++)
        placed_me[i]=placed_enemy[i]=0;

    a=0;

    for(int i=0;i<3;i++)
        for(int j=0;j<3;j++)
        {
            for(int k=0;k<=5;k++)
                m[i][j].piesa[k]=false;
        }
}
void ClosingSockets()
{
    closesocket(server);
    closesocket(client);
    closesocket(serverstabil);
    closesocket(clientstabil);
    closesocket(request);
}
void MuteMusic()
{
    if(mute)
    {
        sunet=volumeorangeRect.w;
        Mix_VolumeMusic(sunet/4);
        Mix_VolumeChunk(soundEffect,sunet);
        mute=false;
    }
    else
    {
        sunet=0;
        Mix_VolumeMusic(sunet);
        mute=true;
    }
}
void init()
{
    if(online)
    {
        if(gazda)
        {
            char msg[3];
            msg[0]=(incepe-1)*(-1);
            msg[1]=numarmaxim;
            send(client,msg,2,0);
        }
        else
        {
            u_long ul=0;
            do
            {
                ioctlsocket(server,FIONREAD,&ul);
            }while(ul<=0);
            char msg[2];
            recv(server,msg,2,0);
            incepe=msg[0];
            numarmaxim=msg[1];
        }
        if(incepe==1)
            yourturn=true;
        else
            yourturn=false;
    }
    else
    {
        srand(SDL_GetTicks());
        numarmaxim=numarmaximsg;
        yourturn=rand()%2;
    }
    win=false;
    used=false;
    lose=false;
    conlost=false;
    hosting=false;
    ro_lang_actual=&ro_lang;
    fr_lang_actual=&fr_lang;
    eng_lang_actual=&eng_lang;
    std::stringstream s;
    s<<"First to ";
    s<<numarmaxim;
    s<<" win";
    CreateText(&maxim,s.str().c_str(),maximRect.h,maximRect.w,30,white);
    timeback=SDL_GetTicks();
    timeresponse=SDL_GetTicks();
    timeout=SDL_GetTicks();
    Dimensionare();
    player=enemy=0;
    char a[2];
    a[0]=numarmaximsg+48;
    a[1]=NULL;
    CreateText(&singlepTextTexture,a,singlepTextRect.h,singlepTextRect.w,20,black);
    CreateText(&rounds,"1",roundsRect.h,roundsRect.w,20,black);
    roundsRect.x=roundsRect.x+27;
    CreateText(&score,"Score:    -",ScoreRect.h,ScoreRect.w,40,white);
    CreateText(&scoreplayer,"0",scoreplayerRect.h,scoreplayerRect.w,40,green);
    setDimensiuni(&scoretable,500,320,scoreplayerRect.h,scoreplayerRect.w);
    CreateText(&scoreenemy,"0",scoreenemyRect.h,scoreenemyRect.w,40,red);
    CreateText(&timer,"Time: 00:00",TimerRect.h,TimerRect.w,40,white);
    setDimensiuni(&timesrc,95,0,TimerRect.h,1000);
    setDimensiuni(&timedest,360,245,TimerRect.h,TimerRect.w/2+10);
    CreateText(&flash,"|",flashRect.h,flashRect.w,20,black);
    timepast=SDL_GetTicks();
    minutes=0;
    seconds=0;
    reset();
}
bool onclick(SDL_Rect rect, bool sound=true)
{
    int x,y;
    if(e.type==SDL_MOUSEBUTTONDOWN && prev!=SDL_MOUSEBUTTONDOWN)
        if(e.button.button==SDL_BUTTON_LEFT)
        {
            SDL_GetMouseState(&x,&y);
            if(x>=rect.x && x<=rect.x+rect.w && y>= rect.y && y<= rect.y+rect.h)
                {
                    if(sound)
                        Play_Effect(0,sunet);
                    return true;
                }
        }
    return false;
}
bool onclick(int,bool sound=true)
{
    if(e.type==SDL_MOUSEBUTTONDOWN && prev!=SDL_MOUSEBUTTONDOWN)
        if(e.button.button==SDL_BUTTON_LEFT)
            {
                if(sound)
                    Play_Effect(0,sunet);
                return true;
            }
    return false;
}
int wheretowin(bool enemy)
{
    int var=0;
    int castigare=CASTIGAT;
    int pierdere=PIERDUT;
    if(enemy)
        {
            var=3;
            castigare=PIERDUT;
            pierdere=CASTIGAT;
        }
    for(int i=0;i<3;i++)
        for(int j=0;j<3;j++)
            {
                bool ok=false;
                for(int tip=Mica+var;tip<=Mare+var;tip++)
                {

                    if(valid(i,j,tip))
                    {
                        ItemOnMatrix(tip,i,j);
                        if(testare(i,j)==castigare)
                        {
                            ok=true;
                            m[i][j].piesa[tip]=false;
                            if(placed_enemy[tip-var]<2)
                            {
                                if(enemy)
                                    placed_enemy[tip-var]++;
                                return i*100+j*10+tip;
                            }
                        }
                        m[i][j].piesa[tip]=false;
                    }
                }
                if(ok)
                {
                    for(int linie=0;linie<3;linie++)
                        for(int coloana=0;coloana<3;coloana++)
                            {
                                int first=getfirst(linie,coloana);
                                if(first>=Mica+var && first<=Mare+var)
                                {
                                    m[linie][coloana].piesa[first]=false;
                                    if(testare(linie,coloana)!=pierdere)
                                    {
                                        if(valid(i,j,first))
                                        {
                                            ItemOnMatrix(first,i,j);
                                            if(testare(i,j)==castigare)
                                            {
                                                if(!enemy)
                                                    ItemOnMatrix(first,linie,coloana);
                                                m[i][j].piesa[first]=false;
                                                return i*100+j*10+first;
                                            }
                                            m[i][j].piesa[first]=false;
                                        }
                                    }
                                    ItemOnMatrix(first,linie,coloana);
                                }
                            }
                }
            }
        return -1;
}
int wheretoput(bool enemy)
{
     int rezultat=wheretowin(false);
     if(rezultat!=-1)
     {
         for(int i=0;i<3;i++)
            for(int j=0;j<3;j++)
                for(int tip=MicaInamic;tip<=MareInamic;tip++)
                     if(valid(i,j,tip))
                     {
                         if(placed_enemy[tip-3]<2)
                         {
                             ItemOnMatrix(tip,i,j);
                             if(wheretowin(false)==-1)
                             {
                                 placed_enemy[tip-3]++;
                                 m[i][j].piesa[tip]=false;
                                 return i*100+j*10+tip;
                             }
                             m[i][j].piesa[tip]=false;
                         }
                         else
                         {
                             for(int linie=0;linie<3;linie++)
                                for(int coloana=0;coloana<3;coloana++)
                                    {
                                        int first=getfirst(linie,coloana);
                                        if(first>=MicaInamic && first<=MareInamic)
                                        {
                                            m[linie][coloana].piesa[first]=false;
                                            if(testare(linie,coloana)!=CASTIGAT)
                                            {
                                                if(valid(i,j,first))
                                                {
                                                    ItemOnMatrix(first,i,j);
                                                    if(wheretowin(false)==-1)
                                                    {
                                                        m[i][j].piesa[first]=false;
                                                        return i*100+j*10+first;
                                                    }
                                                    m[i][j].piesa[first]=false;
                                                }
                                            }
                                            ItemOnMatrix(first,linie,coloana);
                                        }
                                    }
                         }
                     }
     }
     return -1;

}
void algoritm()
{
    bool consumate=false;
    int x,y,tip;
    do
    {
        srand(SDL_GetTicks());
        tip=rand()%3+3;
        x=rand()%3;
        y=rand()%3;
        if(placed_enemy[0]>=2 && placed_enemy[1]>=2 && placed_enemy[2]>=2)
        {
            consumate=true;
            break;
        }

    }while(!valid(x,y,tip) || placed_enemy[tip-3]>=2);
    if(consumate)
    {
        int i=0,j=0;
        bool ver=false;
        do
        {

            while(i<3)
            {
                if((tip=getfirst(i,j))>Mare)
                   break;
                j++;
                if(j==4)
                {
                    j=0;
                    i++;
                }
            }
            x=0;
            y=0;
            while(x<3)
            {
                if(x!=i || y!=j)
                    if(valid(x,y,tip))
                       {
                           m[i][j].piesa[tip]=false;
                           ver=true;
                           break;
                       }
                y++;
                if(y==4)
                {
                    y=0;
                    x++;
                }
            }
        }while(ver==false);
    }
    ItemOnMatrix(tip,x,y);
    placed_enemy[tip-3]++;
    if(testare(x,y)==PIERDUT)
        {
            std::stringstream s;
            enemy++;
            s<<enemy;
            CreateText(&scoreenemy,s.str().c_str(),scoreenemyRect.h,scoreenemyRect.w,40,red);
            showingen=true;
            Play_Effect(4,sunet);
            timeshowing=SDL_GetTicks();
        }
    else
        yourturn=true;
}
void algoritmhard()
{
    int tip,linie,coloana;
    int rezultat=wheretowin(true);
    if(rezultat==-1)
    {
        int rez=wheretoput(true);
        if(rez!=-1)
        {
            tip=rez%10,rez/=10;
            coloana=rez%10,rez/=10;
            linie=rez%10;
            ItemOnMatrix(tip,linie,coloana);
        }
        else
        {
            if(m[1][1].piesa[Mare]==false && m[1][1].piesa[MareInamic]==false && placed_enemy[Mare]<2)
            {
                placed_enemy[Mare]++;
                linie=1;
                coloana=1;
                ItemOnMatrix(MareInamic,linie,coloana);
            }
            else
            {
                bool ver=false;
                for(int tipul=MareInamic;tipul>=MicaInamic;tipul--)
                    for(int i=0;i<=1;i++)
                        for(int j=0;j<=1;j++)
                        {
                            if(valid(i*2,j*2,tipul) && placed_enemy[tipul-3]<2 && getfirst(2-(i*2),2-(j*2))<tipul-3)
                            {
                                placed_enemy[tipul-3]++;
                                linie=i*2;
                                coloana=j*2;
                                ItemOnMatrix(tipul,linie,coloana);
                                ver=true;
                                j=2;
                                i=2;
                                tipul=-1;
                            }

                        }
                    if(ver==false)
                        algoritm();
            }
        }
    }
    else
    {
            tip=rezultat%10,rezultat/=10;
            coloana=rezultat%10,rezultat/=10;
            linie=rezultat%10;
            ItemOnMatrix(tip,linie,coloana);
            yourturn=true;
    }
    if(testare(linie,coloana)==PIERDUT)
    {
        std::stringstream s;
        enemy++;
        s<<enemy;
        CreateText(&scoreenemy,s.str().c_str(),scoreenemyRect.h,scoreenemyRect.w,40,red);
        showingen=true;
        Play_Effect(4,sunet);
        timeshowing=SDL_GetTicks();
    }
    else
        yourturn=true;
}

void update()
{
    if(Ticks(timeback,25))
    {
        Count(contor,2000,-1);
        back2RectSrc.x=contor;
    }
    if(SDL_PollEvent(&e))
    {
        if(e.type==SDL_QUIT)
            running=false;
        else
        if(focus)
        {
            typing(textip,&ip,&ipRect,textboxRect,20);
            if(e.type==SDL_KEYDOWN && e.key.keysym.sym==SDLK_RETURN)
            {
                if(Conection(textip,444,server,serverstabil))
                {
                    yourturn=false;
                    playing=true;
                    online=true;
                    init();
                    gazda=false;
                }
            }
        }
        else
        if(focus2)
        {
            typing(servernameText,&servername,&servernameRect,servernameBox,20);
        }

    }
    if(playing)
    {

        if(lose || win || conlost)
        {
            if(onHover(menubuttonwin))
            {
                HoverOnButton(&hoverRect,menubuttonwin);
                placing=true;
            }
            else
            if(placing)
                placing=false;
            if(onclick(menubuttonwin))
            {
                playing=false;
                online=false;
                init();
            }
        }
        else
        {
            if(onHover(menuRect))
            {
                placing=true;
                HoverOnButton(&hoverRect,menuRect);
            }
            else
            if(placing)
                placing=false;
            if(onclick(menuRect))
            {
                playing=false;
                online=false;
                ClosingSockets();
                init();
            }
            if(Ticks(timepast,1000))
            {
                seconds++;
                if(seconds==60)
                {
                    seconds=0;
                    minutes++;
                }
                std::stringstream ss;
                ss<<"Time: "<<minutes/10<<minutes%10<<":"<<seconds/10<<seconds%10;
                CreateText(&timer,ss.str().c_str(),TimerRect.h,TimerRect.w,40,white);

            }
                if(yourturn==false)
            {
                if(online)
                    {
                        char inp[20];
                        int recc;
                        unsigned long ul=0;
                        if(gazda)
                            {

                                ioctlsocket(client,FIONREAD,(unsigned long*)&ul);
                                if(ul>0)
                                    recc=recv(client,inp,20,0);
                            }
                        else
                            {
                                ioctlsocket(server,FIONREAD,(unsigned long*)&ul);
                                if(ul>0)
                                    recc=recv(server,inp,20,0);
                            }
                        if(ul>0)
                        {
                            if((int)inp[0]==100)
                            {
                                m[inp[1]][inp[2]].piesa[inp[3]+3]=false;
                                if(testare(inp[1],inp[2])==CASTIGAT)
                                {
                                    std::stringstream s;
                                    player++;
                                    s<<player;
                                    CreateText(&scoreplayer,s.str().c_str(),scoreplayerRect.h,scoreplayerRect.w,40,green);
                                    timeshowing=SDL_GetTicks();
                                    Play_Effect(3,sunet);
                                    showing=true;
                                }
                            }
                            else
                            if((int)inp[0]==101)
                                m[inp[1]][inp[2]].piesa[inp[3]+3]=true;
                            else
                            {
                                inp[recc]=NULL;
                                int x=0,y=0,tip=0;
                                x=inp[0]-48;
                                y=inp[1]-48;
                                tip=inp[2]-48+3;
                                if(inp[3]-48!=4)
                                    m[inp[3]-48][inp[4]-48].piesa[tip]=false;
                                ItemOnMatrix(tip,x,y);
                                if(testare(x,y)==PIERDUT)
                                    {
                                        std::stringstream s;
                                        enemy++;
                                        s<<enemy;
                                        CreateText(&scoreenemy,s.str().c_str(),scoreenemyRect.h,scoreenemyRect.w,40,red);
                                        showingen=true;
                                        Play_Effect(4,sunet);
                                        timeshowing=SDL_GetTicks();
                                    }
                                if(showingen==false)
                                    yourturn=true;
                            }
                        }

                    }
                    else
                        if(showingen==false)
                            {
                                if(dif==1)
                                    algoritm();
                                else
                                if(dif=2)
                                    algoritmhard();
                            }
                    if(showing)
                    {
                        if(Ticks(timeshowing,1000))
                        {
                            showing=false;
                            if(player>=numarmaxim)
                            {
                                win=true;
                                Play_Effect(1,sunet);
                                if(online)
                                {
                                    online=false;
                                    ClosingSockets();
                                }
                            }
                            else
                            {
                                yourturn=false;
                                reset();
                            }
                        }
                    }
                    if(showingen)
                        if(Ticks(timeshowing,1000))
                        {
                            showingen=false;
                            if(enemy>=numarmaxim)
                            {
                                lose=true;
                                Play_Effect(2,sunet);
                                if(online)
                                {
                                    online=false;
                                    ClosingSockets();
                                }
                            }
                            else
                            {
                                yourturn=true;
                                reset();
                            }
                        }
            }
            else
            {
                if(used==false)
                {
                    if(showing==false && showingen==false)
                    {
                        if(onclick(piesa_initiala[2]))
                            used=true,setdragging(&item_dragging,2),dragtype=Mare,itemonmatrice=false;
                        else
                        if(onclick(piesa_initiala[1]))
                            used=true,setdragging(&item_dragging,1),dragtype=Mediu,itemonmatrice=false;
                        else
                        if(onclick(piesa_initiala[0]))
                            used=true,setdragging(&item_dragging,0),dragtype=Mica,itemonmatrice=false;
                        else
                        if(onclick(mt))
                        {
                            int x,y;
                            SDL_GetMouseState(&x,&y);
                            CtoP(x,y,x,y);
                            int tip=getfirst(x,y);
                            if(tip!=-1 && tip<=2)
                            {
                                m[x][y].piesa[tip]=false;
                                dragtype=tip;
                                setdragging(&item_dragging,dragtype);
                                used=true;
                                if(testare(x,y)==PIERDUT)
                                {
                                    std::stringstream s;
                                    enemy++;
                                    s<<enemy;
                                    CreateText(&scoreenemy,s.str().c_str(),scoreenemyRect.h,scoreenemyRect.w,40,red);
                                    showingen=true;
                                    Play_Effect(4,sunet);
                                    timeshowing=SDL_GetTicks();
                                    used=false;
                                }
                                if(online)
                                {
                                    char msg[5];
                                    msg[0]=100;
                                    msg[1]=x;
                                    msg[2]=y;
                                    msg[3]=tip;
                                    if(gazda)
                                        send(client,msg,4,0);
                                    else
                                        send(server,msg,4,0);
                                }
                                placed_me[dragtype]--;

                                itemonmatrice=true;
                                linieonmatrice=x;
                                coloanaonmatrice=y;
                            }

                        }
                        if(used && placed_me[dragtype]>=2)
                            used=false;
                    }
                }
                else
                if(used)
                {
                    dragging(*item_dragging);
                    if(onclick(ANYWHERE))
                    {
                        if(incadrare(*item_dragging,mt))
                            {
                                int x,y;
                                CtoP(*item_dragging,x,y);
                                if(valid(x,y,dragtype))
                                {
                                    if(placed_me[dragtype]<2)
                                    {
                                        ItemOnMatrix(dragtype,x,y);
                                        placed_me[dragtype]++;
                                        light=avaible;
                                        if(testare(x,y)== CASTIGAT)
                                            {
                                                player++;
                                                std::stringstream s;
                                                s<<player;
                                                CreateText(&scoreplayer,s.str().c_str(),scoreplayerRect.h,scoreplayerRect.w,40,green);
                                                showing=true;
                                                timeshowing=SDL_GetTicks();
                                                Play_Effect(3,sunet);
                                            }
                                        std::stringstream Strr;
                                        Strr<<2-placed_me[dragtype]<<"x";
                                        CreateText(&TexturaText[dragtype],Strr.str().c_str(),text[dragtype].h,text[dragtype].w,40,white);
                                        Strr.str("");
                                        Strr<<x<<y<<dragtype;
                                        char inp[10];
                                        if(itemonmatrice)
                                        {
                                            Strr<<linieonmatrice<<coloanaonmatrice;
                                        }
                                        else
                                        {
                                            Strr<<4<<4;
                                        }
                                        strcpy(inp,Strr.str().c_str());
                                        if(online)
                                            {
                                                if(gazda)
                                                    send(client,inp,strlen(inp),0);
                                                else
                                                    send(server,inp,strlen(inp),0);send(serverstabil,inp,strlen(inp),0);
                                            }
                                        if(showing==false)
                                            yourturn=false;
                                    }
                                }
                                else
                                if(itemonmatrice)
                                {
                                    ItemOnMatrix(dragtype,linieonmatrice,coloanaonmatrice);
                                    placed_me[dragtype]++;
                                    if(online)
                                    {
                                        char msg[5];
                                        msg[0]=101;
                                        msg[1]=linieonmatrice;
                                        msg[2]=coloanaonmatrice;
                                        msg[3]=dragtype;
                                        if(gazda)
                                        {
                                            send(client,msg,4,0);
                                        }
                                        else
                                            send(server,msg,4,0);
                                    }
                                }
                                isPlacing=false;
                            }
                            else
                            if(itemonmatrice)
                                {
                                    ItemOnMatrix(dragtype,linieonmatrice,coloanaonmatrice);
                                    placed_me[dragtype]++;
                                    if(online)
                                    {
                                        char msg[5];
                                        msg[0]=101;
                                        msg[1]=linieonmatrice;
                                        msg[2]=coloanaonmatrice;
                                        msg[3]=dragtype;
                                        if(gazda)
                                            send(client,msg,4,0);
                                        else
                                            send(server,msg,4,0);
                                    }
                                }
                        for(int i=0;i<=2;i++)
                            pieseRect[i]=piesa_initiala[i];

                        used=false;

                        itemonmatrice=false;
                    }
                    else
                    if(RightonCLick())
                    {
                        if(itemonmatrice)
                            {
                                ItemOnMatrix(dragtype,linieonmatrice,coloanaonmatrice);
                                placed_me[dragtype]++;
                                if(online)
                                {
                                    char msg[5];
                                    msg[0]=101;
                                    msg[1]=linieonmatrice;
                                    msg[2]=coloanaonmatrice;
                                    msg[3]=dragtype;
                                    if(gazda)
                                    {
                                        send(client,msg,4,0);
                                    }
                                    else
                                        send(server,msg,4,0);
                                }
                            }
                        for(int i=0;i<=2;i++)
                            pieseRect[i]=piesa_initiala[i];
                        used=false;
                        isPlacing=false;
                        itemonmatrice=false;
                    }
                    else
                    if(incadrare(*item_dragging,mt))
                    {
                        int x,y;
                        CtoP(*item_dragging,x,y);
                        avrect.x=mt.x+dim_patrat*y;
                        avrect.y=mt.y+dim_patrat*x;
                        isPlacing=true;
                        if(valid(x,y,dragtype))
                            light=avaible;
                        else
                            light=notavaible;
                    }
                    else
                        isPlacing=false;
                }
                if(showing)
                    if(Ticks(timeshowing,1000))
                    {
                        showing=false;
                        if(player>=numarmaxim)
                        {
                            win=true;
                            Play_Effect(1,sunet);
                            if(online)
                            {
                                online=false;
                                ClosingSockets();
                            }
                        }
                        else
                            {
                                reset();
                                yourturn=false;
                            }
                    }
                    if(showingen)
                        if(Ticks(timeshowing,1000))
                        {

                            showingen=false;
                            if(enemy>=numarmaxim)
                            {
                                if(online)
                                {
                                    online=false;
                                    ClosingSockets();
                                }
                                Play_Effect(2,sunet);
                                lose=true;
                            }
                            else
                            {
                                yourturn=true;
                                reset();
                            }
                        }
            }
            if(online)
            {
                if( gazda==false && Ticks(timeout,100))
                        SendPackage(serverstabil);
                if(!(Ticks(timeresponse,2000)))
                {
                    if(gazda)
                    {
                        if(RecvPackage(gazda,clientstabil))
                            timeresponse=SDL_GetTicks();
                    }
                    else
                    {
                        if(RecvPackage(gazda,serverstabil))
                            timeresponse=SDL_GetTicks();
                    }
                }
                else
                    {
                        conlost=true;
                        ClosingSockets();
                    }
            }
        }
    }
    else
    if(!lanwindow)
    {
         if(showlang)
        {
            if(onHover(ro_langRect))
                ro_lang_actual=&ro_lang_tr;
            else
                ro_lang_actual=&ro_lang;

            if(onHover(fr_langRect))
                fr_lang_actual=&fr_lang_tr;
            else
                fr_lang_actual=&fr_lang;

            if(onHover(eng_langRect))
                eng_lang_actual=&eng_lang_tr;
            else
                eng_lang_actual=&eng_lang;
            if(onHover(backlang))
            {
                HoverOnButton(&hoverRect,backlang);
                isPlacing=true;
            }
            else
            if(isPlacing)
                isPlacing=false;
            if(onclick(backlang))
                showlang=false;
            else
            if(onclick(ro_langRect))
            {
                langing=true;
                showlang=false;
                howlang=&howlangro;
            }
            else
            if(onclick(fr_langRect))
            {
                langing=true;
                showlang=false;
                howlang=&howlangfr;
            }
            else
            if(onclick(eng_langRect))
            {
                langing=true;
                showlang=false;
                howlang=&howlangeng;
            }

        }
        else
        if(options)
        {
            if(onHover(backlang))
            {
                HoverOnButton(&hoverRect,backlang);
                isPlacing=true;
            }
            else
            if(isPlacing)
                isPlacing=false;

            if(onclick(backlang))
                options=false;
            else
            if(onclick(soundiconRect))
            {
                MuteMusic();
            }
            else
            if(onclick(volumeblankRect))
            {
                pressing=true;
            }
            else
            if(onclick(normalRect))
                {
                    dif=1;
                    HoverOnButton(&firsthoverRect,normalRect);
                }
            else
            if(onclick(hardRect))
                {
                    dif=2;
                    HoverOnButton(&firsthoverRect,hardRect);
                }
            else
            if(onclick(uparrowsg))
            {
                if(numarmaximsg<9)
                {
                    numarmaximsg++;
                    std::stringstream s;
                    s<<numarmaximsg;
                    CreateText(&singlepTextTexture,s.str().c_str(),singlepTextRect.h,singlepTextRect.w,20,black);
                }
            }
            else
            if(onclick(downarrowsg))
            {
                if(numarmaximsg>1)
                {
                    numarmaximsg--;
                    std::stringstream s;
                    s<<numarmaximsg;
                    CreateText(&singlepTextTexture,s.str().c_str(),singlepTextRect.h,singlepTextRect.w,20,black);
                }
            }

            if(pressing)
            {

                if(e.type!=SDL_MOUSEBUTTONUP && onHover(volumeblankRect) && mute==false)
                {
                    int x=0;
                    SDL_GetMouseState(&x,NULL);
                    if(x<=(volumeblankRect.x+volumeblankRect.w)-2)
                        {
                            volumeorangeRect.w=x-volumeorangeRect.x;
                            if(volumeorangeRect.w>=5)
                            {
                                sunet=volumeorangeRect.w;
                                Mix_VolumeChunk(soundEffect,sunet);
                                Mix_VolumeMusic(sunet/4);
                            }
                            else
                            {
                                sunet=0;
                                Mix_VolumeChunk(soundEffect,sunet);
                                Mix_VolumeMusic(sunet/4);
                            }
                        }
                }
                else
                    pressing=false;
            }
        }
        else
        if(langing)
        {
            if(onHover(backlang))
            {
                HoverOnButton(&hoverRect,backlang);
                isPlacing=true;
            }
            else
            if(isPlacing)
                isPlacing=false;
            if(onclick(backlang))
            {
                showlang=true;
                langing=false;
            }
        }
        else
        {
            bool ver=false;
            for(int i=0;i<=4;i++)
            {
                if(onHover(butonRect[i]))
                {
                    isPlacing=true;
                    HoverOnButton(&hoverRect,butonRect[i]);
                    ver=true;
                }
            }
            if(ver==false)
                isPlacing=false;
            if(onclick(butonRect[0]))
                {
                    playing=true;
                    init();
                }
            else
            if(onclick(butonRect[1]))
                {
                    lanwindow=true;
                    HoverOnButton(&firsthoverRect,hostTextRect);
                }
            else
            if(onclick(butonRect[2]))
            {
                options=true;
                if(dif==1)
                    HoverOnButton(&firsthoverRect,normalRect);
                else
                if(dif==2)
                    HoverOnButton(&firsthoverRect,hardRect);
            }
            else
            if(onclick(butonRect[3]))
            {
                showlang=true;
            }
            else
            if(onclick(butonRect[4]))
                running=false;
        }

    }
    else
    {
        if(focus || focus2)
        {
            if(Ticks(timepast,1000))
                flashing=!flashing;
        }
        if(directconect)
        {
            if(onclick(textboxRect))
            {
                if(focus2)
                    focus2=false;
                if(focus==false)
                {
                    HoverOnButton(&labelhoverRect,textboxRect);
                    focus=true;
                    SDL_StartTextInput();
                    if(textip[0]==NULL)
                        setDimensiuni(&flashRect,ipRect.x,ipRect.y,NULL,NULL);
                    flashing=true;
                    timepast=SDL_GetTicks();
                }
            }
            else
            if(onclick(ANYWHERE,false))
            {
                focus=false;
                SDL_StopTextInput();

            }
            if(onHover(dirconectcon))
            {
                HoverOnButton(&hoverRect,dirconectcon);
                isPlacing=true;
            }
            else
            if(onHover(dirconectback))
            {
                HoverOnButton(&hoverRect,dirconectback);
                isPlacing=true;
            }
            else
                isPlacing=false;
            if(onclick(dirconectcon))
            {
                if(textip[0]!=NULL)
                    if(Conection(textip,444,server,serverstabil))
                    {
                        yourturn=false;
                        playing=true;
                        online=true;
                        init();
                        gazda=false;
                    }
            }
            else
            if(onclick(dirconectback))
            {
                searching=false;
                closesocket(server);
                directconect=false;
                strcpy(textip,"");
                flashRect.x=ipRect.x;
                searching=false;
                ClosingSockets();
            }
        }
        else
        if(waiting)
        {
            if(hosting)
            {
                std::stringstream s;
                s<<"Waiting for other player to join";
                if(Ticks(timepast,1000))
                {
                    cont++;
                    if(cont==4)
                        cont=0;
                    for(int i=0;i<cont;i++)
                        s<<'.';
                    CreateText(&TextWaiting,s.str().c_str(),TextWaitingRect.h,TextWaitingRect.w,30,black);
                }
                if(onHover(backconection))
                {
                    HoverOnButton(&hoverRect,backconection);
                    isPlacing=true;
                }
                else
                if(isPlacing)
                    isPlacing=false;
                if(onclick(backconection))
                {
                    searching=false;
                    hosting=false;
                    numarmaxim=3;
                    ClosingSockets();

                }
            }
            else
            {
                if(onHover(starthostingRect))
                {
                    HoverOnButton(&hoverRect,starthostingRect);
                    isPlacing=true;
                }
                else
                if(onHover(backhostingRect))
                {
                    HoverOnButton(&hoverRect,backhostingRect);
                    isPlacing=true;
                }
                else
                if(isPlacing==true)
                    isPlacing=false;
                if(onclick(servernameBox))
                {
                    if(focus)
                        focus=false;
                    if(focus2==false)
                    {
                        focus2=true;
                        SDL_StartTextInput();
                        HoverOnButton(&labelhoverRect,servernameBox);
                        if(servernameText[0]==NULL)
                            setDimensiuni(&flashRect,servernameRect.x,servernameRect.y,NULL,NULL);
                        flashing=true;
                        timepast=SDL_GetTicks();
                    }
                }
                else
                if(onclick(backhostingRect))
                {
                    waiting=false;
                    if(focus2)
                        focus2=false;
                }
                else
                if(onclick(starthostingRect))
                {
                    CreateServer("444",server,serverstabil,request);
                    searching=true;
                    hosting=true;
                    listen(server,1);
                    listen(serverstabil,1);
                    isPlacing=false;
                    focus2=false;
                    CreateText(&TextWaiting,"Waiting for other player to join",TextWaitingRect.h,TextWaitingRect.w,30,black);
                    timepast=SDL_GetTicks();
                    numarmaxim=runde;
                }
                else
                if(onclick(hostTextRect))
                {
                    HoverOnButton(&firsthoverRect,hostTextRect);
                    incepe=1;
                }
                else
                if(onclick(clientTextRect))
                {
                    HoverOnButton(&firsthoverRect,clientTextRect);
                    incepe=0;
                }
                else
                if(onclick(randomTextRect))
                {
                    HoverOnButton(&firsthoverRect,randomTextRect);
                    srand(SDL_GetTicks());
                    incepe=rand()%2;
                }
                else
                if(onclick(uparrowRect))
                {
                    std::stringstream s;
                    if(runde<9)
                        runde++;
                    s<<runde;
                    CreateText(&rounds,s.str().c_str(),roundsRect.h,roundsRect.w,20,black);
                }
                else
                if(onclick(downarrowRect))
                {
                    if(runde>1)
                        runde--;
                    std::stringstream s;
                    s<<runde;
                    CreateText(&rounds,s.str().c_str(),roundsRect.h,roundsRect.w,20,black);
                }
                else
                if(onclick(ANYWHERE,false))
                    if(focus2)
                        focus2=false;
            }
        }
        else
        {
            bool ver=false;
            for(int i=0;i<=4;i++)
            {
                if(onHover(lanbutonRect[i]))
                {
                    HoverOnButton(&hoverRect,lanbutonRect[i]);
                    isPlacing=true;
                    ver=true;
                }
            }
            if(ver==false)
                isPlacing=false;
            if(onclick(lanbutonRect[4]))
                {
                    lanwindow=false;
                }
            else
            if(onclick(lanbutonRect[1]))
            {
                waiting=true;
            }
            else
            {
                if(onclick(lanbutonRect[0]))
                    directconect=true;
                else
                if(onclick(lanbutonRect[3]))
                {
                    refresh(c,lg,names);
                    for(int i=0;i<lg;i++)
                    {
                        CreateText(&gasite[i],names[i],gasiteRect[i].h,gasiteRect[i].w,20,black);
                        setDimensiuni(&gasiteRect[i],300,i*(gasiteRect[0].h+4)+320,NULL,NULL);
                    }
                }
                else
                if(onclick(lanbutonRect[2]))
                {
                    if(ipfocus)
                        if(Conection(c[ipready],444,server,serverstabil))
                        {
                            yourturn=false;
                            playing=true;
                            online=true;
                            init();
                            gazda=false;
                        }
                }

            }
        }

        if(searching)
        {
            if(WaitToConnect(server,serverstabil,client,clientstabil,request,servernameText))
                {
                    online=true;
                    searching=false;
                    playing=true;
                    gazda=true;
                    init();
                    waiting=false;
                }
        }

        bool ver=false;
        for(int i=0;i<lg;i++)
        {
            if(onclick(gasiteRect[i]))
                setDimensiuni(&hovertextRect,200,i*(gasiteRect[0].h+4)+317,NULL,NULL),ver=true,ipfocus=true,ipready=i;

        }
        if(ver==false)
            if(onclick(ANYWHERE,false))
                ipfocus=false;
    }
    prev=e.type;
}
int main(int argc, char* argv[])
{
    InitWindow();
    UploadTexturi();
    init();
    if(!Mix_PlayingMusic())
    {
        Mix_PlayMusic(bgm,-1);
        Mix_VolumeMusic(MIX_MAX_VOLUME/8);
    }
    while(running)
    {
        update();
        render();
    }
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    return 0;
}
