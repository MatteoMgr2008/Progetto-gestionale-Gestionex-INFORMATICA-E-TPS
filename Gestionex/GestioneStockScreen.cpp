#include "GestioneStockScreen.h"
#include <vector>
#include <string>
#include <cmath>
#include "ThemeManager.h"

using namespace std;

void DrawGestioneStockScreen(bool& gestioneStock, vector<Magazzino>& listMagazzini)
{
    // Set tema
    ThemeManager& themeManager = ThemeManager::getInstance();
    int theme = themeManager.getCurrentThemeInt(); // Ottieni il tema corrente

    ImGui::SetNextWindowPos(ImVec2(0, 0), ImGuiCond_Always);
    ImGui::SetNextWindowSize(ImGui::GetIO().DisplaySize, ImGuiCond_Always);
    ImGui::Begin("Gestione Stock", nullptr, ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoMove |
        ImGuiWindowFlags_NoCollapse);

    // Applica i colori in base al tema
    if (theme == 0) { // Tema chiaro
        ImGui::PushStyleColor(ImGuiCol_Text, ImVec4(0.0f, 0.0f, 0.0f, 1.0f)); // Testo nero
        ImGui::PushStyleColor(ImGuiCol_Button, ImVec4(0.949f, 0.514f, 0.133f, 1.0f)); // Arancione normale
        ImGui::PushStyleColor(ImGuiCol_ButtonHovered, ImVec4(1.0f, 0.6f, 0.2f, 1.0f)); // Arancione chiaro (hover)
        ImGui::PushStyleColor(ImGuiCol_ButtonActive, ImVec4(0.8f, 0.4f, 0.1f, 1.0f)); // Arancio scuro (clic)

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
        ImGui::PushStyleColor(ImGuiCol_Text, ImVec4(0.9f, 0.9f, 0.9f, 1.0f)); // Testo bianco
        ImGui::PushStyleColor(ImGuiCol_Button, ImVec4(0.949f, 0.514f, 0.133f, 1.0f)); // Arancione normale
        ImGui::PushStyleColor(ImGuiCol_ButtonHovered, ImVec4(1.0f, 0.6f, 0.2f, 1.0f)); // Arancione chiaro (hover)
        ImGui::PushStyleColor(ImGuiCol_ButtonActive, ImVec4(0.8f, 0.4f, 0.1f, 1.0f)); // Arancio scuro (clic)

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

    static int selectedMagazzinoIndex = 0;
    static bool popUpAddStock = false;
    static bool errorPopup = false;
    static bool showStockPopup = false;
    static int selectedStockIndex = -1;
    static Stock selectedStock;

    ImGui::Text("Seleziona il magazzino per il quale desideri gestire lo stock:");
    ImGui::Spacing();
    
    vector<string> nomiMagazzini;
    for (const auto& m : listMagazzini) {
        nomiMagazzini.push_back(m.getNome());
    }

	// Verifica se ci sono magazzini disponibili
    if (!nomiMagazzini.empty()) {
        const char* currentNome = nomiMagazzini[selectedMagazzinoIndex].c_str();
		// Combo box (menù a tendina) per selezionare il magazzino per il quale si desidera gestire lo stock
        if (ImGui::BeginCombo("##magazzini", currentNome)) {
            for (int i = 0; i < nomiMagazzini.size(); ++i) {
                bool selected = (selectedMagazzinoIndex == i);
                if (ImGui::Selectable(nomiMagazzini[i].c_str(), selected)) {
                    selectedMagazzinoIndex = i;
                }
                if (selected) ImGui::SetItemDefaultFocus();
            }
            ImGui::EndCombo();
        }

        ImGui::Spacing();
        ImGui::Separator();
        ImGui::Spacing();
        ImGui::Spacing();

		// Verifica se l'indice selezionato è valido
        Magazzino& magazzino = listMagazzini[selectedMagazzinoIndex];

        if (ImGui::Button("Aggiungi un nuovo stock", ImVec2(240, 35))) {
            popUpAddStock = true;
        }

        ImDrawList* draw_list = ImGui::GetWindowDrawList();

        float startX = 60.0f;
        float startY = 150.0f;
        float magazzinoWidth = 800.0f;
        float magazzinoHeight = 400.0f;
        float padding = 0.0f;

        ImVec2 topLeft(startX, startY);
        ImVec2 bottomRight(startX + magazzinoWidth, startY + magazzinoHeight);
        draw_list->AddRectFilled(topLeft, bottomRight, IM_COL32(70, 70, 70, 255), padding);
        draw_list->AddRect(topLeft, bottomRight, IM_COL32(255, 255, 255, 255), padding);

        float spazioTotaleMagazzino = magazzino.getSpazioTotale();
        vector<Stock> stockList = magazzino.getStockList();

        // Calcola lo spazio occupato da magazzino
        float areaWidth = magazzinoWidth - 2 * padding;
        float areaHeight = magazzinoHeight - 2 * padding;
        float totalArea = areaWidth * areaHeight;

        float currentX = startX + padding;
        float currentY = startY + padding;
        float rowHeight = 0.0f;
        
		int index = 0; // Contatore per gli stock

		// Disegna gli stock in proporzione allo spazio occupato
        for (Stock stock : stockList) {
		    float spazioOccupato = stock.getSpazioOccupato();
		    float spazioTotale = stock.getSpazioTotale();
		    float areaStock = (totalArea * spazioTotale) / spazioTotaleMagazzino;
            float areaHeightStock = areaHeight;
            float areaWidthStock = (areaStock / areaHeight);

		    // Ensure the stock fits within the magazzino rectangle
		    if (currentX + areaWidthStock > bottomRight.x) {
		    	currentX = startX + padding;
		    	currentY += rowHeight + padding;
		    	rowHeight = 0.0f;
		    }

            ImVec2 stockTopLeft(currentX, currentY);
            ImVec2 stockBottomRight(currentX + areaWidthStock, currentY + areaHeightStock);

            // Converti coordinate schermo in coordinate finestra per InvisibleButton
            ImVec2 windowPos = ImGui::GetWindowPos();
            ImVec2 buttonPos = ImVec2(stockTopLeft.x - windowPos.x, stockTopLeft.y - windowPos.y);
            ImVec2 buttonSize = ImVec2(areaWidthStock, areaHeightStock);

            // Posiziona il cursore per l'InvisibleButton
            ImGui::SetCursorPos(buttonPos);

            string pulsanteSelezionato = "##Stock" + to_string(index); // index è un contatore univoco per ogni stock

			// Calcola la dimensione del pulsante invisibile
            if (ImGui::InvisibleButton(pulsanteSelezionato.c_str(), buttonSize)){
                selectedStockIndex = index;
                selectedStock = stock;
                showStockPopup = true;
			}

            // Ottieni le coordinate del pulsante appena creato
            ImVec2 min = ImGui::GetItemRectMin();
            ImVec2 max = ImGui::GetItemRectMax();

			// Controlla gli stati dei pulsanti invisibili
            bool pulsanteHover = ImGui::IsItemHovered();
            bool pulsantePremuto = ImGui::IsItemActive();

            // Cambia colore il pulsante invisibile in base allo stato
            ImU32 coloreStatoPulsanteSelezionato;
            if (pulsanteHover) {
                coloreStatoPulsanteSelezionato = IM_COL32(120, 120, 120, 255); // Colore stato pulsante premuto
            } else if (pulsantePremuto) {
                coloreStatoPulsanteSelezionato = IM_COL32(100, 100, 100, 255); // Colore stato pulsante hover
            } else {
				coloreStatoPulsanteSelezionato = IM_COL32(50, 50, 50, 255); // Colore stato pulsante normale (cioè non premuto e non hover)
            }

            // Disegna il rettangolo con il colore appropriato
			ImGui::GetWindowDrawList()->AddRectFilled(min, max, coloreStatoPulsanteSelezionato);
			// Disegna solo il bordo del rettangolo
            ImGui::GetWindowDrawList()->AddRect(min, max, IM_COL32(255, 255, 255, 255));

		    rowHeight = std::max(rowHeight, areaHeightStock);
		    currentX += areaWidthStock + padding;
            index++; // Incrementa il contatore per il prossimo stock
		}

        ImGui::SetCursorPosY(bottomRight.y + 30);
        float center = ImGui::GetWindowSize().x / 2.0f;

        ImGui::SetCursorPosX(center - 200);
        if (ImGui::Button("Aggiungi un nuovo magazzino", ImVec2(290, 40))) {}

        ImGui::SameLine();
        ImGui::SetCursorPosX(center + 98);

        if (ImGui::Button("Torna alla Homepage", ImVec2(210, 40))) {
            gestioneStock = false;
        }

		// Popup per aggiungere un nuovo stock
        DrawPopUpAddStock(popUpAddStock, magazzino, errorPopup);
		// Popup per visualizzare le informazioni dello stock selezionato (cliccando sul pulsante invisibile)
        DrawInfoStockPopUp(showStockPopup, selectedStock, selectedStockIndex, magazzino);
    }
    else {
        ImGui::Text("Nessun magazzino disponibile in questo momento. E' necessario creare almeno uno o più nuovi magazzini.");
    }

    ImGui::PopStyleVar();
    ImGui::PopStyleColor(12);
    ImGui::End();
}

void DrawPopUpAddStock(bool& popUpAddStock, Magazzino& magazzino, bool& errorPopup) {
    if (popUpAddStock) {
        ImGui::Begin("Aggiunta di un nuovo stock", &popUpAddStock);
        static char categoria[128] = "";
        static float spazioTotale = 0.0f;
        static float spazioOccupato = 0.0f;

        ImGui::Text("Compila i seguenti campi per aggiungere un nuovo stock nel magazzino selezionato:");
        ImGui::Spacing();
        ImGui::InputText("Categoria dell'articolo", categoria, sizeof(categoria));
        ImGui::InputFloat("Spazio totale dello stock", &spazioTotale);
        ImGui::InputFloat("Spazio occupato dello stock", &spazioOccupato);
		ImGui::Spacing();

        if (ImGui::Button("Aggiungi")) {
            if (spazioTotale <= 0.0f || spazioOccupato < 0.0f) {
                errorPopup = true;
            }
            else {
                Stock nuovoStock(categoria, 0, spazioTotale, spazioOccupato);
                if (magazzino.getSpazioTotale() - magazzino.getSpazioOccupato() >= spazioTotale) {
                    magazzino.aggiungiStock(nuovoStock);
                    strcpy_s(categoria, "");
                    spazioTotale = 0.0f;
                    spazioOccupato = 0.0f;
                    popUpAddStock = false;
                }
                else {
                    errorPopup = true;
                }
            }
        }

        if (errorPopup) {
            ImGui::OpenPopup("ERRORE: Lo spazio rimanente nel magazzino e' esaurito");
        }

        if (ImGui::BeginPopupModal("ERRORE: Lo spazio rimanente nel magazzino e' esaurito", nullptr, ImGuiWindowFlags_AlwaysAutoResize)) {
            ImGui::Text("Lo spazio occupato per lo stock di questa categoria e' maggiore dello spazio libero rimanente nel magazzino.");
            ImGui::Spacing();
            ImGui::Spacing();
            if (ImGui::Button("Chiudi", ImVec2(120, 0))) {
                errorPopup = false;
                ImGui::CloseCurrentPopup();
            }
            ImGui::EndPopup();
        }

        ImGui::SameLine();

        if (ImGui::Button("Annulla")) {
            popUpAddStock = false;
        }

        ImGui::End();
    }
}

// Funzione per disegnare il popup di informazioni dello stock quando si clicca su uno stock specifico (il pulsante invisibile)
void DrawInfoStockPopUp(bool& showPopup, Stock& stock, int stockIndex, Magazzino& magazzino) {
    if (showPopup) {
        ImGui::Begin("Informazioni stock:", &showPopup);
        ImGui::Text("Nome stock: %s", stock.getInfoStock().c_str());
        ImGui::Text("Spazio Totale: %.2f", stock.getSpazioTotale());
        ImGui::Text("Spazio Occupato: %.2f", stock.getSpazioOccupato());
        if (ImGui::Button("Modifica")) {
            // Logica per modificare lo stock
            // Per esempio, si potrebbe aprire un altro popup per modificare i dettagli dello stock
        }
        if (ImGui::Button("Rimuovi")) {
            magazzino.rimuoviStock(stock);
            showPopup = false; // Chiude il popup dopo la rimozione
        }
        if (ImGui::Button("Chiudi")) {
            showPopup = false;
        }
        ImGui::End();
	}
}