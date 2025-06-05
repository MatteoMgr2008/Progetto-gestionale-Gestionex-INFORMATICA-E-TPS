#include "GestioneOrdiniUscitaScreen.h"
#include "ThemeManager.h"

void DrawGestioneOrdiniUscitaScreen(bool& gestioneOrdini, list<OrdineUscita>& listOrdini)
{
    // Set del tema
    ThemeManager& themeManager = ThemeManager::getInstance();
    int theme = themeManager.getCurrentThemeInt(); // Ottieni il tema corrente

    ImGui::SetNextWindowPos(ImVec2(0, 0), ImGuiCond_Always);
    ImGui::SetNextWindowSize(ImGui::GetIO().DisplaySize, ImGuiCond_Always);
    ImGui::Begin("Gestione degli ordini in uscita", nullptr, ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoMove |
        ImGuiWindowFlags_NoCollapse);

    // Applica i colori in base al tema
    if (theme == 0) { // Tema chiaro
        ImGui::PushStyleColor(ImGuiCol_Text, ImVec4(0.0f, 0.0f, 0.0f, 1.0f)); // Testo nero
        ImGui::PushStyleColor(ImGuiCol_Button, ImVec4(0.8f, 0.8f, 0.8f, 1.0f)); // Bottone grigio chiaro
        ImGui::PushStyleColor(ImGuiCol_ButtonHovered, ImVec4(0.7f, 0.7f, 0.7f, 1.0f)); // Hover grigio medio
        ImGui::PushStyleColor(ImGuiCol_ButtonActive, ImVec4(0.6f, 0.6f, 0.6f, 1.0f)); // Active grigio scuro
    }
    else { // Tema scuro
        ImGui::PushStyleColor(ImGuiCol_Text, ImVec4(0.9f, 0.9f, 0.9f, 1.0f)); // Testo bianco
        ImGui::PushStyleColor(ImGuiCol_Button, ImVec4(0.2f, 0.4f, 0.8f, 1.0f)); // Bottone blu
        ImGui::PushStyleColor(ImGuiCol_ButtonHovered, ImVec4(0.3f, 0.5f, 0.9f, 1.0f)); // Hover blu chiaro
        ImGui::PushStyleColor(ImGuiCol_ButtonActive, ImVec4(0.1f, 0.3f, 0.7f, 1.0f)); // Active blu scuro
    }

    ImGui::PushStyleVar(ImGuiStyleVar_FrameRounding, 8.0f);

    ImGui::Text("Opzioni disponibili in questa sezione:");
    ImGui::Spacing();

    static bool showAddOrderWindow = false;
    static bool showModifyOrderWindow = false;
    static bool showArticlesWindow = false;
    static bool showTransferWindow = false;
    static int selectedOrderIndexForArticles = -1;

    int index = 0;
    for (auto it = listOrdini.begin(); it != listOrdini.end(); ++index) {
        auto& ordine = *it;

        ImGui::Separator();
        ImGui::Text("Tracciamento: %s", ordine.getID_track().c_str());
        ImGui::SameLine();
        ImGui::Text("| Stato: %s", ordine.getStatoOrdineString().c_str());

        ImGui::Indent();
        if (ImGui::Button(("Cancella##" + to_string(index)).c_str(), ImVec2(120, 30))) {
            it = listOrdini.erase(it);
            --index; // Decrementa l'indice per compensare l'elemento rimosso
            continue; // Salta l'incremento dell'iteratore
        }

        ImGui::SameLine();
        if (ImGui::Button(("Visualizza Articoli##" + to_string(index)).c_str(), ImVec2(180, 30))) {
            selectedOrderIndexForArticles = index;
            showArticlesWindow = true;
        }

        ImGui::SameLine();
        ImGui::Checkbox(("Controllo Danno##" + to_string(index)).c_str(), &ordine.getCheckDanno());
        ImGui::SameLine();
        ImGui::Checkbox(("Controllo Documenti##" + to_string(index)).c_str(), &ordine.getCheckDocumento());
        ImGui::SameLine();
        if (ordine.getCheckDanno() && ordine.getCheckDocumento()) {
            if (ImGui::Button(("Trasferisci Articoli in Stock##" + to_string(index)).c_str(), ImVec2(200, 30))) {
                showTransferWindow = true;
            }
        }

        ImGui::Unindent();
        ++it; // Incrementa l'iteratore solo se non è stato cancellato l'elemento
    }

    ImGui::Separator();
    ImGui::Spacing();

    if (ImGui::Button("Aggiungi Ordine", ImVec2(180, 40))) showAddOrderWindow = true;
    ImGui::SameLine();
    if (ImGui::Button("Modifica Ordine", ImVec2(180, 40))) showModifyOrderWindow = true;

    ImGui::Spacing();
    if (ImGui::Button("Torna alla Home", ImVec2(180, 40))) gestioneOrdini = false;

    // Inserisci pop-up o altre pagine
    // TODO: Implementare le finestre popup per showAddOrderWindow, showModifyOrderWindow, 
    // showArticlesWindow e showTransferWindow

    // Bilanciamento dello stack di stili
    ImGui::PopStyleVar(1);     // Per FrameRounding
    ImGui::PopStyleColor(4);   // Per i 4 colori pushati

    ImGui::End();
}