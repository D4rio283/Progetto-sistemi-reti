//includo le librerie
#include<iostream>
#include<string>
#include<fstream>
#include<algorithm>
#include"funzioni.h"
using namespace std;

//manca funzione e prototipo di checksum e CRC

int main(){
    //dichiaro due variabili di tipo string e a parola gli assegno cio' che e' scritto in msg.txt
    string parola= leggi_Messaggio();
    string bin= "";
    string risultato_ip="";
    string risultato_finale="";
    
    //ogni lettera del messaggio viene passata alla funzione che restituisce la sua conversione in binario
    for(int i= 0; i<parola.size(); i++){
        //ogni conversione in binario di ogni lettera viene concatenata alla variabile bin, che conterra'� l'intera conversine del messaggio
        bin+=char_to_bin(parola[i]);
    }
    
    
    //IN BIN � PRESENTE LA CONVERSIONE IN BINARIO DEL MESSAGGIO
    //creo una variabile di tipo struct
    IpHeader header;
    ethernetHeader header2;
    
    //in risultato_ip ci va il datagramma (pacchetto)
    risultato_ip= crea_Datagram(header, bin);
	
	//in risultato_finale ci va il frame (che comprende sia il datagram sia il frame; TUTTO)
    risultato_finale=crea_Frame(header2,risultato_ip);

    //chiamo la procedura scrittura passando la variabile risultato_finale
    scrittura_Messaggio(risultato_finale);

    return 0;
}
