#ifndef SERVER_H_INCLUDED
#define SERVER_H_INCLUDED
#include "Includes.h"
void stergere(char* c,int l);
void verificare_adrese(char *c,char names[10][20],char vec[10][20],SOCKET sock,int &lg);
void refresh(char c[10][20],int &lg,char names[10][20]);
void getname(char*c, char* name,int l);
bool Conection(char* host,u_short port,SOCKET &server,SOCKET &serverstabil);
void CreateServer(const char* port,SOCKET &server,SOCKET& serverstabil,SOCKET &request);
bool WaitToConnect(SOCKET server,SOCKET serverstabil,SOCKET& client,SOCKET &clientstabil,SOCKET &request,char* servernameText);
void SendPackage(SOCKET destinatie);
bool RecvPackage(bool gazda,SOCKET& delacine);

#endif // SERVER_H_INCLUDED
