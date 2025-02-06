#include<iostream>
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
    //apro lo stream col file
    ofstream fout("frame.txt");
    
    //se c'e' un errore nell'apertura lo comunico all'utente e torno al main
    if(!fout){
        cout<<"Errore nella scrittura del file\n";
    }    
    //scrivo il messaggio (conversione in binario del messaggio) all'interno del file
    fout<<messaggio;
}


void crea_Datagram(IpHeader &header){
    header.version= 4;
    header.HLEN= 10;
    
    //priorita'� 4, delay 1, trhoughput 0, reliability 1, monetary cost 0 (ultimo di completamento)
    header.TOS= 148;
    
    header.total_lenght= 38070;
    header.identification= 11569;

    //3 bit  (il primo e' inutilizzato; il secondo se = 1 indica che il pacchetto non puo' essere frammentato)
    header.flags= 2;
    header.fragment_offset= 150;
    header.time_to_live= 60;
    header.protocol= 1;
    header.header_checksum= 39843;
    header.S_IP_address= 45344;
    header.D_IP_address= 17817;
    header.option= 56801;
    header.padding= 12785;
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

