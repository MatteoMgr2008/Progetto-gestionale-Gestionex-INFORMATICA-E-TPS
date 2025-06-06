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
        // Colori pulsanti, testo, checkbox per il tema chiaro
        ImGui::PushStyleColor(ImGuiCol_Text, ImVec4(0.0f, 0.0f, 0.0f, 1.0f)); // Testo nero
        ImGui::PushStyleColor(ImGuiCol_Button, ImVec4(0.8f, 0.2f, 0.6f, 1.0f)); // Fucsia normale
        ImGui::PushStyleColor(ImGuiCol_ButtonHovered, ImVec4(0.9f, 0.3f, 0.7f, 1.0f)); // Fucsia più chiaro (hover)
        ImGui::PushStyleColor(ImGuiCol_ButtonActive, ImVec4(0.6f, 0.1f, 0.5f, 1.0f)); // Fucsia più scuro (clic)
        ImGui::PushStyleColor(ImGuiCol_CheckMark, ImVec4(0.8f, 0.2f, 0.6f, 1.0f));  // Fucsia per checkbox

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
        ImGui::PushStyleColor(ImGuiCol_Button, ImVec4(0.8f, 0.2f, 0.6f, 1.0f)); // Fucsia normale
        ImGui::PushStyleColor(ImGuiCol_ButtonHovered, ImVec4(0.9f, 0.3f, 0.7f, 1.0f)); // Fucsia più chiaro (hover)
        ImGui::PushStyleColor(ImGuiCol_ButtonActive, ImVec4(0.6f, 0.1f, 0.5f, 1.0f)); // Fucsia più scuro (clic)
        ImGui::PushStyleColor(ImGuiCol_CheckMark, ImVec4(0.8f, 0.2f, 0.6f, 1.0f));  // Fucsia per checkbox

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

    if (ImGui::Button("Aggiungi un nuovo ordine", ImVec2(250, 40))) showAddOrderWindow = true;
    ImGui::SameLine();
    if (ImGui::Button("Modifica un ordine esistente", ImVec2(270, 40))) showModifyOrderWindow = true;
    ImGui::SameLine();
    if (ImGui::Button("Torna alla Homepage", ImVec2(250, 40))) gestioneOrdini = false;

    // Inserire pop-up o altre pagine qua in futuro
    // TODO: Implementare le finestre popup per showAddOrderWindow, showModifyOrderWindow, showArticlesWindow e showTransferWindow

    ImGui::PopStyleVar(); // Ripristina FrameRounding
    ImGui::PopStyleColor(13); // Ripristina i colori del tema principale

    ImGui::End();
}