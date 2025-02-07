\#include<iostream>
#include<string>
#include<algorithm>
#include"funzioni.h"
#include<fstream>
using namespace std;

string leggi_Messaggio(){
    //dichiaro la variabile riga
    string riga;
    
    //apro lo stream col file
    ifstream fin("msg.txt");
    
    //se c'e' un errore nell'apertura lo comunico all'utente e torno al main
    if(!fin){
        cout<<"Errore nell'apertura del file\n";
    }
    
    //l'intera riga in cui e' contenuto il messaggio viene memorizzata nella variabile riga
    getline(fin, riga);
    
    //chiudo lo stream col file
    fin.close();
    
    //restituisco al main l'intero messaggio
    return riga;
}


void scrittura_Messaggio(string messaggio){
    //apro lo stream con il file
    ofstream fout("frame.txt");
    
    //se c'e' un errore nell'apertura lo comunico all'utente e torno al main
    if(!fout){
        cout<<"Errore nella scrittura del file\n";
    }    
    //scrivo il messaggio (conversione in binario del messaggio) all'interno del file
    fout<<messaggio;
}


string crea_Datagram(IpHeader &header,string bin){
    string risultato= "";
    string checksum="000000000000000";
    string risultato_parziale="";
    
    header.version= "0100";
    header.HLEN= "0101";
    
    //priorita'� 4, delay 1, trhoughput 0, reliability 1, monetary cost 0 (ultimo di completamento)
    header.TOS= "01100110";
    
    header.total_lenght= "0000000000111100";
    header.identification= "1101010011110001";

    //3 bit  (il primo e' inutilizzato; il secondo se = 1 indica che il pacchetto non puo' essere frammentato)
    header.flags= "010";
    header.fragment_offset= "0000000000000";
    header.time_to_live= "01000000";
    header.protocol= "00000110";
    header.S_IP_address= "11000000101010000000000100001010";
    header.D_IP_address= "00001000000010000000000000001000";
    risultato_parziale= header.version+header.HLEN+header.TOS+header.total_lenght+header.identification+header.flags+header.fragment_offset+header.time_to_live+header.protocol+header.S_IP_address+header.D_IP_address;
    header.header_checksum= ipChecksum(risultato_parziale);
    
    risultato= header.version+header.HLEN+header.TOS+header.total_lenght+header.identification+header.flags+header.fragment_offset+header.time_to_live+header.protocol+header.header_checksum+header.S_IP_address+header.D_IP_address+bin;
    return risultato;
}


string char_to_bin(char lettera){
    //dichiaro un array e due variabili
    int cont= 7;
    string risultato= "";
    
  	if(lettera>=128){
        risultato= "1";
    }else{
        risultato= "0";
    }
    
    //faccio compiere all'algoritmo 8 iterazioni (8 sono i bit nel numero binario)
    while(cont!=1){
        //se il numero è divisibile per 2 allora aggiungo metto 0 nella cella dell'array in posizione cont; altrimenti metto 1
        if(lettera%2==0){
            risultato+="0";
        }else{
            risultato+="1";
        }
        
        //decremento cont e dimezzo il numero
        cont--;
        lettera= lettera/2;
    }
    
    reverse(risultato.begin(), risultato.end()); // Inverte la stringa
    
    //restituisco il risultato
    return risultato;
}

string string_to_bin(char lettera){
    //dichiaro un array e due variabili
    int cont= 7;
    string risultato= "";
    
  	if(lettera>=128){
        risultato= "1";
    }else{
        risultato= "0";
    }
    
    //faccio compiere all'algoritmo 8 iterazioni (8 sono i bit nel numero binario)
    while(cont!=1){
        //se il numero è divisibile per 2 allora aggiungo metto 0 nella cella dell'array in posizione cont; altrimenti metto 1
        if(lettera%2==0){
            risultato+="0";
        }else{
            risultato+="1";
        }
        
        //decremento cont e dimezzo il numero
        cont--;
        lettera= lettera/2;
    }
    
    reverse(risultato.begin(), risultato.end()); // Inverte la stringa
    
    //restituisco il risultato
    return risultato;
}

void crea_Frame(ethernetHeader &header2,string risultato_ip){
    string risultato_totale="";
    header2.preamble="1010101010101010101010101010101010101010101010101010101010101010";
    header2.SFD="11010101";
    header2.DST="101011111010111110101111101011111010111110101111";
    header2.SRC="101011001010111110101101101011001010011010101110";
    header2.type="10000000000000000";
    header2.FCS="";
    risultato_totale=header2.preamble+header2.SFD+header2.DST+header2.SRC+header2.type+risultato_ip+header2.FCS;
    return risultato_totale;
   
}
