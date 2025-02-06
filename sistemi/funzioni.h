#ifndef FUNZIONI_H
#define FUNZIONI_H
#include<string>
using namespace std;

struct IpHeader{
    int version;
    int HLEN;
    int TOS;
    int total_lenght;
    int identification;
    int flags;
    int fragment_offset;
    int time_to_live;
    int protocol;
    int header_checksum;
    int S_IP_address;
    int D_IP_address;
    int option;
    int padding;
};

string leggi_Messaggio();
void scrittura_Messaggio(string messaggio);
string char_to_bin(char lettera);
string string_to_bin(char lettera);
void crea_Datagram(IpHeader &header);

#endif	//serve a evitare inclusioni multiple
