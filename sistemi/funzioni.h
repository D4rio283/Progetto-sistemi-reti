#ifndef FUNZIONI_H
#define FUNZIONI_H
#include<string>
using namespace std;

struct IpHeader{
    string version;
    string HLEN;
    string TOS;
    string total_lenght;
    string identification;
    string flags;
    string fragment_offset;
    string time_to_live;
    string protocol;
    string header_checksum;
    string S_IP_address;
    string D_IP_address;
    string option;
    string padding;
};

string leggi_Messaggio();
void scrittura_Messaggio(string messaggio);
string char_to_bin(char lettera);
string string_to_bin(char lettera);
void crea_Datagram(IpHeader &header);

#endif	//serve a evitare inclusioni multiple
