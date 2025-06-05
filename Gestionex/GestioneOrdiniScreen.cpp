#include "GestioneOrdiniScreen.h"
#include <list>
#include <iostream>
#include <string>
#include <random>
#include "ThemeManager.h"

using namespace std;

void DrawGestioneOrdiniScreen(bool& gestioneOrdini, list<OrdineEntrata>& listOrdini, vector<Magazzino>& listMagazzini) 
{
    // Set tema
    ThemeManager& themeManager = ThemeManager::getInstance();
    int theme = themeManager.getCurrentThemeInt(); // Ottieni il tema corrente

    ImGui::SetNextWindowPos(ImVec2(0, 0), ImGuiCond_Always);
    ImGui::SetNextWindowSize(ImGui::GetIO().DisplaySize, ImGuiCond_Always);
    ImGui::Begin("Gestione degli ordini in Entrata ", nullptr, ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoMove |
        ImGuiWindowFlags_NoCollapse);

    // Applica i colori in base al tema
    if (theme == 0) { // Tema chiaro
		// Colori pulsanti, testo, checkbox per il tema chiaro
        ImGui::PushStyleColor(ImGuiCol_Text, ImVec4(0.0f, 0.0f, 0.0f, 1.0f)); // Testo nero
        ImGui::PushStyleColor(ImGuiCol_Button, ImVec4(0.0f, 0.6f, 0.2f, 1.0f));  // Verde
        ImGui::PushStyleColor(ImGuiCol_ButtonHovered, ImVec4(0.0f, 0.8f, 0.3f, 1.0f));  // Verde acceso
        ImGui::PushStyleColor(ImGuiCol_ButtonActive, ImVec4(0.0f, 0.4f, 0.1f, 1.0f));  // Verde scuro
        ImGui::PushStyleColor(ImGuiCol_CheckMark, ImVec4(0.0f, 0.8f, 0.2f, 1.0f));  // Verde per checkbox

        // Stili per la combo
        ImGui::PushStyleColor(ImGuiCol_FrameBg, ImVec4(0.9f, 0.9f, 0.9f, 1.0f)); // Sfondo combo
        ImGui::PushStyleColor(ImGuiCol_FrameBgHovered, ImVec4(0.8f, 0.8f, 0.8f, 1.0f)); // Hover combo
        ImGui::PushStyleColor(ImGuiCol_FrameBgActive, ImVec4(0.7f, 0.7f, 0.7f, 1.0f)); // Active combo
        ImGui::PushStyleColor(ImGuiCol_Header, ImVec4(0.7f, 0.7f, 0.7f, 1.0f)); // Header selectable
        ImGui::PushStyleColor(ImGuiCol_HeaderHovered, ImVec4(0.6f, 0.6f, 0.6f, 1.0f)); // Header hover
        ImGui::PushStyleColor(ImGuiCol_HeaderActive, ImVec4(0.5f, 0.5f, 0.5f, 1.0f)); // Header active

        // Stili per popup
        ImGui::PushStyleColor(ImGuiCol_PopupBg, ImVec4(0.95f, 0.95f, 0.95f, 1.0f)); // Sfondo popup
        ImGui::PushStyleColor(ImGuiCol_WindowBg, ImVec4(0.95f, 0.95f, 0.95f, 1.0f)); // Sfondo finestre
    }
    else { // Tema scuro
        // Colori pulsanti, testo, checkbox per il tema scuro
        ImGui::PushStyleColor(ImGuiCol_Text, ImVec4(0.9f, 0.9f, 0.9f, 1.0f)); // Testo bianco
        ImGui::PushStyleColor(ImGuiCol_Button, ImVec4(0.0f, 0.6f, 0.2f, 1.0f));  // Verde
        ImGui::PushStyleColor(ImGuiCol_ButtonHovered, ImVec4(0.0f, 0.8f, 0.3f, 1.0f));  // Verde acceso
        ImGui::PushStyleColor(ImGuiCol_ButtonActive, ImVec4(0.0f, 0.4f, 0.1f, 1.0f));  // Verde scuro
        ImGui::PushStyleColor(ImGuiCol_CheckMark, ImVec4(0.0f, 0.8f, 0.2f, 1.0f));  // Verde per checkbox

        // Stili per la combo
        ImGui::PushStyleColor(ImGuiCol_FrameBg, ImVec4(0.2f, 0.2f, 0.2f, 1.0f)); // Sfondo combo scuro
        ImGui::PushStyleColor(ImGuiCol_FrameBgHovered, ImVec4(0.3f, 0.3f, 0.3f, 1.0f)); // Hover combo
        ImGui::PushStyleColor(ImGuiCol_FrameBgActive, ImVec4(0.4f, 0.4f, 0.4f, 1.0f)); // Active combo
        ImGui::PushStyleColor(ImGuiCol_Header, ImVec4(0.2f, 0.4f, 0.8f, 0.8f)); // Header selectable
        ImGui::PushStyleColor(ImGuiCol_HeaderHovered, ImVec4(0.3f, 0.5f, 0.9f, 0.8f)); // Header hover
        ImGui::PushStyleColor(ImGuiCol_HeaderActive, ImVec4(0.1f, 0.3f, 0.7f, 0.8f)); // Header active

        // Stili per popup
        ImGui::PushStyleColor(ImGuiCol_PopupBg, ImVec4(0.15f, 0.15f, 0.15f, 1.0f)); // Sfondo popup scuro
        ImGui::PushStyleColor(ImGuiCol_WindowBg, ImVec4(0.15f, 0.15f, 0.15f, 1.0f)); // Sfondo finestre scuro
    }

    ImGui::PushStyleVar(ImGuiStyleVar_FrameRounding, 8.0f);

    ImGui::Text("Opzioni disponibili in questa sezione:");
    ImGui::Spacing();

    static bool showAddOrderWindow = false;
    static bool showModifyOrderWindow = false;
    static bool showArticlesWindow = false;
    static bool showTransferWindow = false;
    static int selectedOrderIndexForArticles = -1;
    static int selectedOrderIndexForTransfer = -1;

    int index = 0;
    for (auto it = listOrdini.begin(); it != listOrdini.end(); ++index) {
        auto& ordine = *it;

        ImGui::Separator();
        ImGui::Spacing();
        ImGui::Text("ID Tracking dell'ordine: %s", ordine.getID_track().c_str());
        ImGui::SameLine();
        ImGui::Text("| Stato ordine: %s", ordine.getStatoOrdineString().c_str());
        ImGui::Spacing();

        ImGui::Indent();
        if (ImGui::Button(("Annulla##" + to_string(index)).c_str(), ImVec2(120, 30))) {
            it = listOrdini.erase(it);
            --index;
        }
        else {
            ++it;
        }

        ImGui::SameLine();
        if (ImGui::Button(("Visualizza gli articoli##" + to_string(index)).c_str(), ImVec2(200, 30))) {
            selectedOrderIndexForArticles = index;
            showArticlesWindow = true;
        }

        ImGui::SameLine();
        ImGui::Checkbox(("Controllo danni effettuato##" + to_string(index)).c_str(), &ordine.getCheckDanno());
        ImGui::SameLine();
        ImGui::Checkbox(("Controllo documenti effettuato##" + to_string(index)).c_str(), &ordine.getCheckDocumento());
        ImGui::SameLine();
        if (ordine.getCheckDanno() && ordine.getCheckDocumento()) {
            if (ImGui::Button(("Trasferisci gli articoli nello stock##" + to_string(index)).c_str(), ImVec2(300, 30))) {
                selectedOrderIndexForTransfer = index;
                showTransferWindow = true;
            }
        }
    }

    ImGui::Separator();
    ImGui::Spacing();

    if (ImGui::Button("Aggiungi un nuovo ordine", ImVec2(250, 40))) showAddOrderWindow = true;
    ImGui::SameLine();
    if (ImGui::Button("Modifica un ordine esistente", ImVec2(270, 40))) showModifyOrderWindow = true;
    ImGui::SameLine();
    if (ImGui::Button("Torna alla Homepage", ImVec2(250, 40))) gestioneOrdini = false;

    DrawAddOrderWindow(showAddOrderWindow, listOrdini);
    DrawModifyOrderWindow(showModifyOrderWindow, listOrdini);
    DrawArticlesWindow(showArticlesWindow, selectedOrderIndexForArticles, listOrdini);
    DrawTransferArticlesWindow(showTransferWindow, selectedOrderIndexForTransfer, listOrdini, listMagazzini);

    ImGui::PopStyleVar(); // Ripristina FrameRounding
    ImGui::PopStyleColor(13); // Ripristina i colori del tema principale
    ImGui::End();
}

static char* GenerateRandomIDTrack(static char idTrack[], const char hex_digits[]) {
   std::random_device rd;
   std::mt19937 gen(rd());
   std::uniform_int_distribution<> dist(0, 15);

   // Initialize the idTrack array with the desired pattern
   strcpy_s(idTrack, 13, "yxyxyxyxyxyx");

   for (int i = 0; i < 12; ++i) { // 12 characters, leaving space for '\0'
       if (idTrack[i] == 'x') {
           idTrack[i] = hex_digits[dist(gen)];
       } else if (idTrack[i] == 'y') {
           idTrack[i] = hex_digits[(dist(gen) & 0x3) | 0x8];
       }
   }
   return idTrack; // Return the generated Tracking ID
}

static char* GenerateRandomArticoloID(static char articoloID[],const char hex_digits[]) {
   std::random_device rd;
   std::mt19937 gen(rd());
   std::uniform_int_distribution<> dist(0, 15);

   // Initialize the articoloID array with the desired pattern
   strcpy_s(articoloID, 9, "xxyyxxyy");

   for (int i = 0; i < 8; ++i) { // 8 caratteri, poi '\0'
       if (articoloID[i] == 'x') {
           articoloID[i] = hex_digits[dist(gen)];
       }
       else if (articoloID[i] == 'y') {
           articoloID[i] = hex_digits[(dist(gen) & 0x3) | 0x8];
       }
   }
   return articoloID; // Restituisce l'ID articolo generato
}

void DrawAddOrderWindow(bool& showAddOrderWindow, list<OrdineEntrata>& listOrdini) {
    static list<ArticoliDellOrdine> listaArticoli;
    static string errorMessage = "";
    static const char hex_digits[] = "0123456789ABCDEF";
    static char idTrack[] = "yxyxyxyxyxyx";
    static char articoloID[] = "xxyyxxyy";
	static bool primoCiclo = true;

    // Valore iniziale della variabili di input nella finestra
    static int statoOrdine = 0;
    static int statoOrdineIndex = 0;
    static int articoloQuantita = 1;
    static char nomeArticolo[128] = "";
    static float articoloSpazioOccupato = 0.0f;
    static float articoloPeso = 0.0f;
    static float articoloPrezzo = 0.0f;

    static const char* listaStatoOrdine[] = {
		"In attesa",                    // 0
        "Arrivato",                     // 1
        "Annullato",                    // 2
        "In attesa di controllo",       // 3
        "Articoli in stoccaggio",       // 4
        "Completato"                    // 5
    };

    if (showAddOrderWindow) {
        ImGui::Begin("Compilazione del DDT per l'inserimento di un nuovo ordine in entrata", &showAddOrderWindow);
        
        // Colori verdi per i pulsanti (indipendenti dal tema)
        ImGui::PushStyleColor(ImGuiCol_Button, ImVec4(0.0f, 0.6f, 0.2f, 1.0f));  // Verde
        ImGui::PushStyleColor(ImGuiCol_ButtonHovered, ImVec4(0.0f, 0.8f, 0.3f, 1.0f));  // Verde acceso
        ImGui::PushStyleColor(ImGuiCol_ButtonActive, ImVec4(0.0f, 0.4f, 0.1f, 1.0f));  // Verde scuro

        if (primoCiclo) {
            GenerateRandomIDTrack(idTrack, hex_digits); // Genera un ID Tracking casuale
            GenerateRandomArticoloID(articoloID, hex_digits); // Genera un ID articolo casuale
			primoCiclo = false; // Imposta a false per non rigenerare l'ID Tracking e l'ID articolo ad ogni apertura della finestra
        }

		ImGui::Text("Compila i seguenti campi del DDT (Documento Di Trasporto) per aggiungere un nuovo ordine in entrata:");
        ImGui::Spacing();
        ImGui::InputText("ID Tracking (generato automaticamente)", idTrack, sizeof(idTrack), ImGuiInputTextFlags_ReadOnly);
        ImGui::Combo("Stato ordine", &statoOrdineIndex, listaStatoOrdine, IM_ARRAYSIZE(listaStatoOrdine));
        ImGui::InputText("ID articolo (generato automaticamente)", articoloID, sizeof(articoloID), ImGuiInputTextFlags_ReadOnly);
        ImGui::InputText("Nome articolo", nomeArticolo, sizeof(nomeArticolo));
        if (ImGui::InputInt("Quantita' articolo", &articoloQuantita)) {
            if (articoloQuantita < 1)
				articoloQuantita = 1; // Limita la quantita' dell'articolo a non essere inferiore a 1
        }
        ImGui::InputFloat("Spazio occupato dall'articolo (in mq)", &articoloSpazioOccupato);
        ImGui::InputFloat("Peso articolo (in kg)", &articoloPeso);
        ImGui::InputFloat("Prezzo articolo (in euro)", &articoloPrezzo);
        ImGui::Spacing();

        if (ImGui::Button("Aggiungi un nuovo articolo")) {
            errorMessage.clear();

            if (strlen(articoloID) == 0)
                errorMessage = "ERRORE: l'ID Articolo non puo' essere vuoto.";
            else if (articoloQuantita <= 0)
                errorMessage = "ERRORE: la quantita' deve essere maggiore di zero.";
            else if (articoloSpazioOccupato <= 0.0f)
                errorMessage = "ERRORE: lo spazio occupato non puo' essere negativo o nullo.";
            else if (articoloPeso <= 0.0f)
                errorMessage = "ERRORE: il peso non puo' essere negativo o nullo.";
            else if (articoloPrezzo <= 0.0f)
                errorMessage = "ERRORE: il prezzo non puo' essere negativo o nullo.";  

            if (errorMessage.empty()) {
                Articolo articolo(nomeArticolo, articoloID, idTrack, articoloSpazioOccupato, articoloPeso, articoloPrezzo);
                listaArticoli.push_back(ArticoliDellOrdine(articolo, articoloQuantita));
                GenerateRandomArticoloID(articoloID, hex_digits);
                strcpy_s(nomeArticolo, sizeof(nomeArticolo), "");
                articoloQuantita = 1;
                articoloSpazioOccupato = 0.0f;
                articoloPeso = 0.0f;
                articoloPrezzo = 0.0f;
            }
        }

        for (auto& articolo : listaArticoli) {
            ImGui::Text("%s | Quantita' articolo: %d | Spazio articolo: %.2f mq | Peso articolo: %.2f kg | Prezzo articolo: %.2f euro",
                articolo.getArticolo().getInfoArticoli().c_str(),
                articolo.getQuantita(),
                articolo.getArticolo().getSpazioOccupato(),
                articolo.getArticolo().getPeso(),
                articolo.getArticolo().getPrezzo());
        }

        ImGui::Dummy(ImVec2(0, 10)); // interlinea più grande (10 pixel)

        if (!errorMessage.empty()) {
            ImGui::PushTextWrapPos(); // forza il testo ad andare a capo se è lungo
            ImGui::TextColored(ImVec4(1.0f, 0.4f, 0.4f, 1.0f), "%s", errorMessage.c_str());
            ImGui::PopTextWrapPos();
        }

		ImGui::Dummy(ImVec2(0, 10)); // interlinea più grande (10 pixel)

        if (ImGui::Button("Aggiungi un nuovo ordine")) {
            errorMessage.clear();
            if (strlen(idTrack) == 0)
                errorMessage = "ERRORE: l'ID Tracking dell'ordine non puo' essere vuoto.";
            else if (listaArticoli.empty())
                errorMessage = "ERRORE: Aggiungi almeno un articolo per quest'ordine.";

            if (errorMessage.empty()) {
                listOrdini.push_back(OrdineEntrata(idTrack, statoOrdineIndex, listaArticoli, "", false, false));
                listaArticoli.clear();
                statoOrdine = 0;
                statoOrdineIndex = 0;
                showAddOrderWindow = false;
                primoCiclo = true;
            }
        }

        ImGui::SameLine();
        if (ImGui::Button("Annulla")) {
            showAddOrderWindow = false;
        }

        ImGui::PopStyleColor(3); // Ripristina i colori dei pulsanti verdi

        ImGui::End();
    }
}

void DrawModifyOrderWindow(bool& modificaOrdine, list<OrdineEntrata>& listOrdini) {
    // Funzione per modificare un ordine
    if (modificaOrdine) {
        ImGui::Begin("Modifica dei dettagli di un ordine aggiunto in entrata", &modificaOrdine);

        // Colori verdi per i pulsanti (indipendenti dal tema)
        ImGui::PushStyleColor(ImGuiCol_Button, ImVec4(0.0f, 0.6f, 0.2f, 1.0f));  // Verde
        ImGui::PushStyleColor(ImGuiCol_ButtonHovered, ImVec4(0.0f, 0.8f, 0.3f, 1.0f));  // Verde acceso
        ImGui::PushStyleColor(ImGuiCol_ButtonActive, ImVec4(0.0f, 0.4f, 0.1f, 1.0f));  // Verde scuro

        static int selectedOrderIndex = -1;           // Indice dell'ordine selezionato
        static char newIDTrack[128] = "";             // Buffer per il nuovo ID Track
        static int newStatoOrdineIndex = 0;                // Stato dell'ordine (0: In Attesa, 1: Completato, ecc.)
        static int selectedStatoOrdineIndex = -1;

        vector<string> orderIDStrings;
        vector<const char*> orderIDs;

        // Mostra i dettagli dell'ordine selezionato
        static const char* listaStatoOrdine[] = {
            "In attesa",                    // 0
            "Arrivato",                     // 1
            "Annullato",                    // 2
            "In attesa di controllo",       // 3
            "Articoli in stoccaggio",       // 4
            "Completato"                    // 5
        };

        // Popola la lista con gli ID degli ordini
        for (auto& ordine : listOrdini) {
            orderIDStrings.push_back(ordine.getID_track()); // Salva la stringa
            orderIDs.push_back(orderIDStrings.back().c_str()); // Usa il puntatore alla stringa salvata
            cout << "ID Tracking dell'ordine: " << ordine.getID_track().c_str() << endl; // Debug: Stampa gli ID degli ordini
        }
        // Mostra un messaggio se la lista è vuota
        if (orderIDs.empty()) {
            ImGui::Text("Nessun ordine in entrata esistente in questo momento. E' necessario, quindi, creare uno o piu' nuovi ordini in entrata.");
        }
        else {
            ImGui::Text("Compila i seguenti campi per modficare un ordine in entrata esistente:");
            ImGui::Spacing();
            // Dropdown per selezionare un ordine
            if (ImGui::Combo("Seleziona l'ID Tracking di un ordine dall'elenco", &selectedOrderIndex, &orderIDs[0], orderIDs.size())) {
                // Se un ordine è selezionato, carica i suoi dettagli per la modifica
                if (selectedOrderIndex >= 0 && selectedOrderIndex < listOrdini.size()) {
                    auto it = listOrdini.begin();
                    advance(it, selectedOrderIndex); // Trova l'ordine selezionato
                    strcpy_s(newIDTrack, it->getID_track().c_str()); // Copia l'ID Track
                    newStatoOrdineIndex = it->getStatoOrdine();  // Recupera lo stato dell'ordine
                }
            }

            if (selectedOrderIndex >= 0 && selectedOrderIndex < listOrdini.size()) {
                ImGui::Combo("Stato ordine", &newStatoOrdineIndex, listaStatoOrdine, IM_ARRAYSIZE(listaStatoOrdine));

                ImGui::Spacing();

                // Bottone per confermare la modifica
                if (ImGui::Button("Salva le modifiche")) {
                    if (selectedOrderIndex >= 0 && selectedOrderIndex < listOrdini.size()) {
                        auto it = listOrdini.begin();
                        advance(it, selectedOrderIndex);
                        it->setID_track(newIDTrack);  // Imposta il nuovo ID Track
                        it->setStatoOrdine(newStatoOrdineIndex); // Imposta il nuovo stato dell'ordine
						modificaOrdine = false; // Chiudi la finestra di modifica
                    }
                }

                ImGui::SameLine();
				if (ImGui::Button("Annulla")) {
					modificaOrdine = false; // Chiudi la finestra di modifica
				}
            }
        }

        ImGui::PopStyleColor(3); // Ripristina i colori dei pulsanti verdi

        ImGui::End();
    }
}

void DrawArticlesWindow(bool& showArticlesWindow, int selectedOrderIndex, list<OrdineEntrata>& listOrdini) {
    if (showArticlesWindow && selectedOrderIndex >= 0 && selectedOrderIndex < listOrdini.size()) {

        // Colori verdi per i pulsanti (indipendenti dal tema)
        ImGui::PushStyleColor(ImGuiCol_Button, ImVec4(0.0f, 0.6f, 0.2f, 1.0f));  // Verde
        ImGui::PushStyleColor(ImGuiCol_ButtonHovered, ImVec4(0.0f, 0.8f, 0.3f, 1.0f));  // Verde acceso
        ImGui::PushStyleColor(ImGuiCol_ButtonActive, ImVec4(0.0f, 0.4f, 0.1f, 1.0f));  // Verde scuro

		// Trova l'ordine selezionato dall'utente
        auto it = listOrdini.begin();
        advance(it, selectedOrderIndex);
        auto& ordine = *it;

		// Imposta il titolo della finestra con l'ID Tracking dell'ordine selezionato
        string titoloFinestra = "Articoli dell'ordine con l'ID Tracking " + ordine.getID_track();
        ImGui::Begin(titoloFinestra.c_str(), &showArticlesWindow);
        string descrizioneFinestra = "Nell'ordine con l'ID Tracking " + ordine.getID_track() + " sono presenti i seguenti articoli:";
        ImGui::Text("%s", descrizioneFinestra.c_str());

        if (ordine.getID_track().empty()) {
            titoloFinestra = "Articoli dell'ordine (ID Tracking non disponibile al momento)";
        }

        for (auto& articolo : ordine.getListaArticoli()) {
            ShowArticoliDellOrdine(articolo);
        }

        if (ImGui::Button("Chiudi")) {
            showArticlesWindow = false;
        }

        ImGui::PopStyleColor(3); // Ripristina i colori dei pulsanti verdi

        ImGui::End();
    }
}

void ShowArticoliDellOrdine(ArticoliDellOrdine& articolo) {
    ImGui::Spacing();
    ImGui::Text("ID Tracking: %s", articolo.getArticolo().getIDOrdine().c_str());
    ImGui::Separator();
    ImGui::Text("ID articolo: %s", articolo.getArticolo().getIDArticolo().c_str());
    ImGui::Separator();
    ImGui::Text("Nome articolo: %s", articolo.getArticolo().getNomeArticolo().c_str());
    ImGui::Separator();
    ImGui::Text("Quantita' articolo: %d", articolo.getQuantita());
    ImGui::Separator();
    ImGui::Text("Spazio occupato dall'articolo: %.2f mq", articolo.getArticolo().getSpazioOccupato());
    ImGui::Separator();
    ImGui::Text("Peso articolo: %.2f kg", articolo.getArticolo().getPeso());
    ImGui::Separator();
    ImGui::Text("Prezzo articolo: %.2f euro", articolo.getArticolo().getPrezzo());
    ImGui::Spacing();
}

void DrawTransferArticlesWindow(bool& showTransferWindow, int selectedOrderIndex,
    std::list<OrdineEntrata>& listOrdini,
    std::vector<Magazzino>& listMagazzini) {
    // Controlli di validità in anticipo
    if (!showTransferWindow || selectedOrderIndex < 0 ||
        selectedOrderIndex >= static_cast<int>(listOrdini.size())) {
        return;
    }

    ImGui::Begin("Articoli da trasferire nello stock", &showTransferWindow);

    // Colori verdi per i pulsanti (indipendenti dal tema)
    ImGui::PushStyleColor(ImGuiCol_Button, ImVec4(0.0f, 0.6f, 0.2f, 1.0f));
    ImGui::PushStyleColor(ImGuiCol_ButtonHovered, ImVec4(0.0f, 0.8f, 0.3f, 1.0f));
    ImGui::PushStyleColor(ImGuiCol_ButtonActive, ImVec4(0.0f, 0.4f, 0.1f, 1.0f));

    // Ottieni riferimento all'ordine selezionato
    auto it = listOrdini.begin();
    std::advance(it, selectedOrderIndex);
    auto& ordine = *it;

    // Variabili static per mantenere lo stato tra le chiamate
    static int selectedMagazzinoIndex = 0;
    static int selectedStockIndex = 0;

    // Reset degli indici se fuori range
    if (selectedMagazzinoIndex >= static_cast<int>(listMagazzini.size())) {
        selectedMagazzinoIndex = 0;
    }

    // Mostra informazioni ordine
    ImGui::Text("I seguenti articoli dell'ordine con ID Tracking %s verranno trasferiti in uno stock di un magazzino:",
        ordine.getID_track().c_str());

    for (auto& articolo : ordine.getListaArticoli()) {
        ShowArticoliDellOrdine(articolo);
    }

    ImGui::Separator();
    ImGui::Text("Seleziona il magazzino di destinazione:");

    // Gestione selezione magazzino
    if (listMagazzini.empty()) {
        ImGui::Text("Nessun magazzino esistente in questo momento per il trasferimento degli articoli nello stock.");
    }
    else {
        // Crea lista nomi magazzini
        std::vector<std::string> nomiMagazzini;
        nomiMagazzini.reserve(listMagazzini.size());
        for (const auto& magazzino : listMagazzini) {
            nomiMagazzini.push_back(magazzino.getNome());
        }

        // Combo box per magazzini
        const char* currentNome = nomiMagazzini[selectedMagazzinoIndex].c_str();
        if (ImGui::BeginCombo("##magazzini", currentNome)) {
            for (int i = 0; i < static_cast<int>(nomiMagazzini.size()); ++i) {
                bool selected = (selectedMagazzinoIndex == i);
                if (ImGui::Selectable(nomiMagazzini[i].c_str(), selected)) {
                    selectedMagazzinoIndex = i;
                    selectedStockIndex = 0; // Reset stock index quando cambia magazzino
                }
                if (selected) {
                    ImGui::SetItemDefaultFocus();
                }
            }
            ImGui::EndCombo();
        }

        // Gestione selezione stock
        Magazzino& selectedMagazzino = listMagazzini[selectedMagazzinoIndex];
        auto& stockList = selectedMagazzino.getStockList();

        if (stockList.empty()) {
            ImGui::Text("Nessuno stock disponibile in questo magazzino.");
        }
        else {
            // Reset dell'indice stock se fuori range
            if (selectedStockIndex >= static_cast<int>(stockList.size())) {
                selectedStockIndex = 0;
            }

            // Crea lista nomi stock
            std::vector<std::string> nomiStocks;
            nomiStocks.reserve(stockList.size());
            for (auto& stock : stockList) {
                nomiStocks.push_back(stock.getInfoStock());
            }

            // Combo box per stock
            const char* currentStockName = nomiStocks[selectedStockIndex].c_str();
            if (ImGui::BeginCombo("##stocks", currentStockName)) {
                for (int i = 0; i < static_cast<int>(nomiStocks.size()); ++i) {
                    bool selected = (selectedStockIndex == i);
                    if (ImGui::Selectable(nomiStocks[i].c_str(), selected)) {
                        selectedStockIndex = i;
                    }
                    if (selected) {
                        ImGui::SetItemDefaultFocus();
                    }
                }
                ImGui::EndCombo();
            }

            // Pulsante trasferici articoli dell'ordine nello stock
            if (ImGui::Button("Trasferisci articoli nello stock selezionato")) {
                auto& selectedStock = stockList[selectedStockIndex];

                // Controlla se lo stock ha spazio sufficiente
                float spazioOccupato = 0.0f;
                for (auto& articolo : ordine.getListaArticoli()) {
                    spazioOccupato += articolo.getArticolo().getSpazioOccupato() * articolo.getQuantita();
                }

                if (selectedStock.getSpazioOccupato() + spazioOccupato > selectedStock.getSpazioTotale()) {
                    ImGui::OpenPopup("Errore di spazio insufficiente");
                    auto& stockList = selectedMagazzino.getStockList();
                }
                else {
                    // Aggiungi articoli allo stock (assumendo che setArticoliDelloStock li aggiunga)
                    selectedStock.setArticoliDelloStock(ordine.getListaArticoli());

                    // Rimuovi l'ordine dalla lista dopo il trasferimento
                    listOrdini.erase(it);
                    showTransferWindow = false; // Chiudi la finestra di trasferimento

                    ImGui::OpenPopup("Trasferimento completato");
                }
            }

            // Gestione popup di errore
            if (ImGui::BeginPopupModal("Errore di spazio insufficiente", NULL, ImGuiWindowFlags_AlwaysAutoResize)) {
                ImGui::Text("Spazio insufficiente nello stock selezionato!");
                ImGui::Separator();
                if (ImGui::Button("OK", ImVec2(120, 0))) {
                    ImGui::CloseCurrentPopup();
                }
                ImGui::EndPopup();
            }

            // Gestione popup di successo
            if (ImGui::BeginPopupModal("Trasferimento completato", NULL, ImGuiWindowFlags_AlwaysAutoResize)) {
                ImGui::Text("Articoli trasferiti con successo!");
                ImGui::Separator();
                if (ImGui::Button("OK", ImVec2(120, 0))) {
                    ImGui::CloseCurrentPopup();
                }
                ImGui::EndPopup();
            }
        }
    }

    ImGui::Spacing();

    // Ripristina i colori dei pulsanti
    ImGui::PopStyleColor(3);
    ImGui::End();
}