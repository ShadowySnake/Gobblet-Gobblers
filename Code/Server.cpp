#include "Server.h"
void getname(char*c, char* name,int l)
{
    int i=l-1;
    if(c[i]=='/')
        c[i]=NULL,strcpy(name,c);
    else
    {
        while(c[i]!='/' && i>=0)
            i--;
        if(i>-1)
            strcpy(name,c+i+1);
    }
    c[i]=NULL;
}
void stergere(char* c,int l)
{
    for(int i=l-1;c[i]!='.';i--)
        c[i]=NULL;
}
void verificare_adrese(char *c,char names[10][20],char vec[10][20],SOCKET sock,int &lg)
{

    sockaddr_in hint;

    for(int i=1;i<=254;i++)
    {
        stergere(c,strlen(c));
        std::stringstream ss;
        ss.str("");
        ss<<i;
        strcat(c,ss.str().c_str());
        hint.sin_family=AF_INET;
        hint.sin_port=htons(444);
        hint.sin_addr.S_un.S_addr=inet_addr(c);
        u_long ul=0;
        ioctlsocket(sock,FIONREAD,&ul);
        sendto(sock,c,strlen(c),NULL,(sockaddr*)&hint,sizeof(hint));
        char msg[30];
        for(int j=0;j<=20;j++)
            if(ul>0)
            {
                int recc=recvfrom(sock,msg,30,0,NULL,NULL);
                if(recc>0)
                {
                    msg[recc]=NULL;
                    getname(msg,names[lg],strlen(msg));
                    strcpy(vec[lg],msg);
                    std::cout<<vec[lg]<<std::endl;
                    lg++;
                    if(lg>1 && strcmp(vec[lg-1],vec[lg-2])==0)
                        lg--;
                }
                ioctlsocket(sock,FIONREAD,&ul);
            }
    }
}
void refresh(char c[10][20],int &lg,char names[10][20])
{
    WSADATA data;

    WSAStartup(MAKEWORD(2,2),&data);

    lg=0;
    char mesaj[20];
    gethostname(mesaj,20);
    hostent *host;
    host=gethostbyname(mesaj);
    SOCKET sv=socket(AF_INET,SOCK_DGRAM,IPPROTO_UDP);
    char a[20][20];
    int l=0;
    for(int i=0;host->h_addr_list[i]!=0;i++)
    {
        in_addr adr;
        memcpy(&adr,host->h_addr_list[i],sizeof(adr));
        strcpy(a[i],inet_ntoa(adr));
        l++;
    }
    for(int i=0;i<l;i++)
        verificare_adrese(a[i],names,c,sv,lg);
    closesocket(sv);
}
void CreateServer(const char* port,SOCKET &server,SOCKET &serverstabil,SOCKET &request)
{
    WSADATA data;

    WSAStartup(MAKEWORD(2,2),&data);

    sockaddr_in hint;
    ZeroMemory(&hint,sizeof(hint));

    hint.sin_family=AF_INET;
    hint.sin_port=htons(444);
    hint.sin_addr.S_un.S_addr=INADDR_ANY;

    server=socket(AF_INET,SOCK_STREAM,IPPROTO_TCP);

    bind(server,(sockaddr*)&hint,sizeof(hint));

    sockaddr_in hint2;
    ZeroMemory(&hint2,sizeof(hint2));
    hint2.sin_family=AF_INET;
    hint2.sin_port=htons(20000);
    hint2.sin_addr.S_un.S_addr=INADDR_ANY;

    serverstabil=socket(AF_INET,SOCK_STREAM,IPPROTO_TCP);
    if(bind(serverstabil,(sockaddr*)&hint2,sizeof(hint2))==0)
        std::cout<<"Succes bind";

    sockaddr_in hint3;
    ZeroMemory(&hint3,sizeof(hint3));

    hint3.sin_family=AF_INET;
    hint3.sin_port=htons(444);
    hint3.sin_addr.S_un.S_addr=INADDR_ANY;

    request=socket(AF_INET,SOCK_DGRAM,IPPROTO_UDP);

    if(bind(request,(sockaddr*)&hint3,sizeof(hint3))==0)
       std::cout<<"Succes request";

}
bool WaitToConnect(SOCKET server,SOCKET serverstabil,SOCKET &client,SOCKET &clientstabil,SOCKET &requestt,char* servernameText)
{
    fd_set asteptare;
    FD_ZERO(&asteptare);
    FD_SET(server,&asteptare);
    FD_SET(serverstabil,&asteptare);
    TIMEVAL time;
    time.tv_sec=0;
    time.tv_usec=10;

    sockaddr_in dest;
    int ul=sizeof(dest);
    u_long z=0;
    char msg[30];
    ioctlsocket(requestt,FIONREAD,&z);
    if(z>0)
        {
            int recc=recvfrom(requestt,msg,30,NULL,(sockaddr*)&dest,&ul);
            if(recc>0)
                {
                    msg[recc]=NULL;
                    strcat(msg,"/");
                    strcat(msg,servernameText);
                    sendto(requestt,msg,strlen(msg),0,(sockaddr*)&dest,ul);
                }
            std::cout<<"Trimis inapoi"<<std::endl;
        }

    if(select(0,&asteptare,NULL,NULL,&time)>1)
    {
        client=accept(server,NULL,NULL);
        clientstabil=accept(serverstabil,NULL,NULL);
        std::cout<<"Client acceptat"<<std::endl;
        return true;
    }
    return false;
}
void SendPackage(SOCKET destinatie)
{
    send(destinatie,"zzzz",4,0);
}
bool RecvPackage(bool gazda,SOCKET &delacine)
{
    u_long ul=0;
    ioctlsocket(delacine,FIONREAD,&ul);
    if(gazda)
    {
        if(ul>0)
        {
            char msg[20];
            recv(delacine,msg,20,0);
            send(delacine,"zzzz",4,0);
            return true;
        }
    }
    else
        if(ul>0)
            {
                char msg[20];
                recv(delacine,msg,20,0);
                return true;
            }
    return false;
}
bool Conection(char* host,u_short port,SOCKET &server,SOCKET &serverstabil)
{
    WSADATA data;
    WSAStartup(MAKEWORD(2,2),&data);

    sockaddr_in hint;

    ZeroMemory(&hint,sizeof(hint));

    hint.sin_family=AF_INET;
    hint.sin_port=htons(port);
    hint.sin_addr.S_un.S_addr=inet_addr(host);

    int ver=0;

    server=socket(AF_INET,SOCK_STREAM,IPPROTO_TCP);
    if(connect(server,(struct sockaddr*)&hint,sizeof(hint))!=SOCKET_ERROR)
        std::cout<<"succes",ver=1;

    sockaddr_in hint2;
    ZeroMemory(&hint2,sizeof(hint2));

    hint2.sin_family=AF_INET;
    hint2.sin_port=htons(20000);
    hint2.sin_addr.S_un.S_addr=inet_addr(host);

    serverstabil=socket(AF_INET,SOCK_STREAM,IPPROTO_TCP);
    if(ver==1)
        if(connect(serverstabil,(struct sockaddr*)&hint2,sizeof(hint2))!=SOCKET_ERROR)
            {
                std::cout<<"Succes stabil";
                return true;
            }

    /*fd_set asteptare;
    FD_ZERO(&asteptare);
    FD_SET(server,&asteptare);
    FD_SET(serverstabil,&asteptare);
    TIMEVAL time;
    time.tv_sec=0;
    time.tv_usec=200;
    //if(select(0,NULL,&asteptare,NULL,&time)>1)
    //{
       // connect(server,(struct sockaddr*)&hint,sizeof(hint));
      //  connect(serverstabil,(struct sockaddr*)&hint2,sizeof(hint2));

      //  std::cout<<"a";

   // }*/
    return false;
}
