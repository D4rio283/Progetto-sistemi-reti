//includo le librerie
#include<iostream>
#include<string>
#include<fstream>
#include<algorithm>
#include"funzioni.h"
using namespace std;



int main(){
    //dichiaro due variabili di tipo string e a parola gli assegno cio' che e' scritto in msg.txt
    string parola= leggi_Messaggio();
    string bin= "";
    string risultato_ip="";
    
    //ogni lettera del messaggio viene passata alla funzione che restituisce la sua conversione in binario
    for(int i= 0; i<parola.size(); i++){
        //ogni conversione in binario di ogni lettera viene concatenata alla variabile bin, che conterra'� l'intera conversine del messaggio
        bin+=char_to_bin(parola[i]);
    }
    
    //chiamo la procedura scrittura passando la variabile bin
    scrittura_Messaggio(bin);
    
    //creo una variabile di tipo struct
    IpHeader header;
    ethernetHeader header2;
    
    
    risultato_ip= crea_Datagram(header,bin);
    cout<<bin;

    crea_Frame(header,risultato_ip);

    
    return 0;
}


