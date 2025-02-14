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

struct ethernetHeader{
    string preamble;
    string SFD;
    string DST;
    string SRC;
    string type;
    string data;
    string FCS;
};


string leggi_Messaggio();
void scrittura_Messaggio(string messaggio);
string char_to_bin(char lettera);
string string_to_bin(char lettera);
string crea_Datagram(IpHeader &header);
string crea_Frame(ethernetHeader header2,string risultato_ip);
unsigned short ipChecksum(string bits);
#endif	//serve a evitare inclusioni multiple
