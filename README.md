# Progetto gestionale Gestionex - Software per la gestione della logistica di un magazzino

https://github.com/user-attachments/assets/1bcbd611-9cbc-46d4-8c0c-3dcf159d16c6

Gestionex è un software gestionale progettato per ottimizzare l’intera filiera logistica di un magazzino generico. Il sistema è stato sviluppato con un'architettura desktop-based in linguaggio C++ e supportato da un database SQL (ancora in fase di sviluppo) per la tracciabilità e l’organizzazione delle merci, degli ordini e delle spedizioni.

L’obiettivo principale di Gestionex è quello di automatizzare e semplificare i tre processi fondamentali della logistica di magazzino:

- **Gestione delle entrate:** controllo documentale e fisico delle merci in ingresso, con verifica della corrispondenza tra l’ordine e le merci effettivamente ricevute.

- **Gestione dello stoccaggio:** allocazione efficiente dei prodotti negli spazi disponibili, monitoraggio delle scorte e notifica automatica in caso di esaurimento.

- **Gestione delle uscite:** gestione degli ordini in uscita, includendo le fasi di picking, packing e spedizione, con preparazione dei documenti di trasporto (DDT) e coordinamento con i corrieri.

Il progetto ha previsto un’approfondita analisi dei requisiti, suddivisi in:

- **Requisiti tecnici:** architettura software, gestione sicura degli accessi e integrazione con database SQL.

- **Requisiti utente:** definizione dei ruoli e delle interazioni previste per amministratori, responsabili logistici e operatori di magazzino.

- **Requisiti normativi:** conformità alle normative fiscali italiane, alla gestione dei documenti digitali e al GDPR per la protezione dei dati.

L’intero sviluppo ha seguito una metodologia di progettazione TOP-DOWN, partendo da una visione generale del sistema e suddividendo progressivamente le funzionalità in moduli specifici, garantendo così una struttura solida, modulare e facilmente espandibile al software Gestionex.

-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

⚠️ **❗** `ATTENZIONE N.B.:` **❗** Per scaricare il software Gestionex e provarlo gratuitamente sul proprio dispositivo Windows è necessiaro seguire i seguenti passaggi:
1) Per prima cosa, scaricare il repository cliccando su Code → Download ZIP
2) Estrarre il contenuto dello ZIP attraverso programmi come WinRAR e 7Zip
3) Aprire la cartella estratta ed aprire a sua volta la cartella "Versione compilata"
4) Avviare Gestionex.exe senza spostare nessun file presente nella cartella (compreso l’eseguibile stesso)

⚠️ ❗ `PER LA RISOLUZIONE DEI PROBLEMI:` ❗
Se appare un messaggio di errore come “mancano DLL” quando si avvia il software Gestionex.exe, provare a installare o reinstallare i Microsoft Visual C++ Redistributable:

Scaricare e installare le versioni più recenti (aggiornate al 28 maggio 2025) da i link sottostanti:

Per sistemi 64-bit (x64):
[Visual C++ Redistributable per Visual Studio 2015–2022 (x64)](https://aka.ms/vs/17/release/vc_redist.x64.exe)

Per sistemi 32-bit (x86):
[Visual C++ Redistributable per Visual Studio 2015–2022 (x86)](https://aka.ms/vs/17/release/vc_redist.x86.exe)

Questi pacchetti contengono le runtime più recenti (versione 14.44.35208.0) e coprono le versioni Visual Studio 2015, 2017, 2019 e 2022.

-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

### PER ULTERIORI INFORMAZIONI RIGUARDO LO SVILUPPO DEL SOFTWARE CONSULTARE:

- La relazione tecnica del software è disponibile al seguente link: https://github.com/MatteoMgr2008/Progetto-gestionale-Gestionex-INFORMATICA-E-TPS/blob/main/Relazione%20tecnica/Es.%20di%20scrittura%20di%20una%20relazione%20tecnica%20riguardo%20lo%20sviluppo%20del%20software%20Gestionex.pdf
- Il diagramma UML delle classi è disponibile al seguente link: https://github.com/MatteoMgr2008/Progetto-gestionale-Gestionex-INFORMATICA-E-TPS/blob/main/Diagrammi%20e%20grafici/Diagramma%20UML%20delle%20classi%20del%20codice%20in%20C%2B%2B.pdf
- Il diagramma TOP-DOWN raffigurante la logica del software è disponibile al seguente link: https://github.com/MatteoMgr2008/Progetto-gestionale-Gestionex-INFORMATICA-E-TPS/blob/main/Diagrammi%20e%20grafici/Es.%20di%20realizzazione%20dell'approccio%20TOP-DOWN%20per%20il%20progetto.pdf
