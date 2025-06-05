#include "HomeScreen.h"
#include <string>
#include "ThemeManager.h"
using namespace std;

void DrawHomeScreen(bool& gestioneOrdiniEntrata, bool& gestioneStock, bool& gestioneOrdiniUscita) {
    ImGui::SetNextWindowPos(ImVec2(0, 0), ImGuiCond_Always);
    ImGui::SetNextWindowSize(ImGui::GetIO().DisplaySize, ImGuiCond_Always);

	// Inizio della schermata home (Homepage)
    ImGui::Begin("Homepage", nullptr, ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoMove |
        ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoScrollbar | ImGuiWindowFlags_NoScrollWithMouse);

    // Spaziatura verticale iniziale
    ImGui::Dummy(ImVec2(0.0f, 100.0f));

    // Ottieni il theme manager
    ThemeManager& themeManager = ThemeManager::getInstance();
    int theme = themeManager.getCurrentThemeInt();

    // Titolo
	string titoloGestionex = "GESTIONEX";
	ImGui::PushFont(ImGui::GetIO().Fonts->Fonts[0]); // Usa il font predefinito (impostato)
	ImGui::PushStyleColor(ImGuiCol_Text, ImVec4(1.0f, 0.0f, 0.0f, 1.0f)); // Colore rosso per il titolo
    ImGui::SetCursorPosX((ImGui::GetWindowSize().x - ImGui::CalcTextSize(titoloGestionex.c_str()).x) * 0.5f);
    ImGui::Text("%s", titoloGestionex.c_str());
    ImGui::PopStyleColor();
    ImGui::PopFont();

    // Sottotitolo o slogan (descrizione del programma Gestionex)
	string sloganGestionex = "Il gestionale definitivo per gestire con facilita' ordini in entrata, ordini in uscita e lo stock di tutti i propri magazzini.";
    ImGui::Spacing();
    ImGui::SetCursorPosX((ImGui::GetWindowSize().x - ImGui::CalcTextSize(sloganGestionex.c_str()).x) * 0.5f);
    ImGui::TextWrapped("%s", sloganGestionex.c_str());
    ImGui::Spacing();

    ImGui::Spacing();
    ImGui::Spacing();
    ImGui::Spacing();

    // Setup per i pulsanti centrati
    float buttonWidth = 300.0f;
    float buttonHeight = 50.0f;
    float spacingY = 20.0f;
    float centerX = (ImGui::GetWindowSize().x - buttonWidth) * 0.5f;

    ImGui::PushStyleColor(ImGuiCol_Button, ImVec4(0.2f, 0.4f, 0.8f, 1.0f));
    ImGui::PushStyleColor(ImGuiCol_ButtonHovered, ImVec4(0.3f, 0.5f, 0.9f, 1.0f));
    ImGui::PushStyleColor(ImGuiCol_ButtonActive, ImVec4(0.1f, 0.3f, 0.7f, 1.0f));
    ImGui::PushStyleVar(ImGuiStyleVar_FrameRounding, 10.0f);

    // Setup per combo box
    ImGui::PushStyleColor(ImGuiCol_FrameBg, theme == 0 ? ImVec4(0.9f, 0.9f, 0.9f, 1.0f) : ImVec4(0.2f, 0.2f, 0.2f, 1.0f));
    ImGui::PushStyleColor(ImGuiCol_FrameBgHovered, theme == 0 ? ImVec4(0.8f, 0.8f, 0.8f, 1.0f) : ImVec4(0.3f, 0.3f, 0.3f, 1.0f));
    ImGui::PushStyleColor(ImGuiCol_FrameBgActive, theme == 0 ? ImVec4(0.7f, 0.7f, 0.7f, 1.0f) : ImVec4(0.4f, 0.4f, 0.4f, 1.0f));
    ImGui::PushStyleColor(ImGuiCol_PopupBg, theme == 0 ? ImVec4(1.0f, 1.0f, 1.0f, 1.0f) : ImVec4(0.15f, 0.15f, 0.15f, 1.0f));
    ImGui::PushStyleColor(ImGuiCol_Border, theme == 0 ? ImVec4(0.7f, 0.7f, 0.7f, 1.0f) : ImVec4(0.4f, 0.4f, 0.4f, 1.0f));

    // Pulsante degli ordini in entrata - Verde
    ImGui::PushStyleColor(ImGuiCol_Button, ImVec4(0.0f, 0.6f, 0.2f, 1.0f));  // Verde
    ImGui::PushStyleColor(ImGuiCol_ButtonHovered, ImVec4(0.0f, 0.8f, 0.3f, 1.0f));  // Verde acceso
    ImGui::PushStyleColor(ImGuiCol_ButtonActive, ImVec4(0.0f, 0.4f, 0.1f, 1.0f));  // Verde scuro
    ImGui::SetCursorPosX(centerX);
    if (ImGui::Button("Gestione degli ordini in entrata", ImVec2(buttonWidth, buttonHeight))) {
        gestioneOrdiniEntrata = true;
    }
    ImGui::PopStyleColor(3); // Ripristina i colori originali (importante!)

    // Spaziatura tra i pulsanti
    ImGui::Dummy(ImVec2(0.0f, spacingY));

    // Pulsante degli ordini nello stock - Arancione chiaro
    ImGui::PushStyleColor(ImGuiCol_Button, ImVec4(0.949f, 0.514f, 0.133f, 1.0f)); // Arancione normale
    ImGui::PushStyleColor(ImGuiCol_ButtonHovered, ImVec4(1.0f, 0.6f, 0.2f, 1.0f)); // Arancione chiaro (hover)
    ImGui::PushStyleColor(ImGuiCol_ButtonActive, ImVec4(0.8f, 0.4f, 0.1f, 1.0f)); // Arancio scuro (clic)
    ImGui::SetCursorPosX(centerX);
    if (ImGui::Button("Gestione degli ordini nello stock", ImVec2(buttonWidth, buttonHeight))) {
        gestioneStock = true;
    }
    ImGui::PopStyleColor(3); // Ripristina i colori originali (importante!)

    ImGui::Dummy(ImVec2(0.0f, spacingY));

    // Pulsante degli ordini in uscita - Fucsia
    ImGui::PushStyleColor(ImGuiCol_Button, ImVec4(0.8f, 0.2f, 0.6f, 1.0f)); // Fucsia normale
    ImGui::PushStyleColor(ImGuiCol_ButtonHovered, ImVec4(0.9f, 0.3f, 0.7f, 1.0f)); // Fucsia più chiaro (hover)
    ImGui::PushStyleColor(ImGuiCol_ButtonActive, ImVec4(0.6f, 0.1f, 0.5f, 1.0f)); // Fucsia più scuro (clic)
    ImGui::SetCursorPosX(centerX);
    if (ImGui::Button("Gestione degli ordini in uscita", ImVec2(buttonWidth, buttonHeight))) {
        gestioneOrdiniUscita = true;
    }
    ImGui::PopStyleColor(3); // Ripristina i colori originali (importante!)

    // Combo in alto a destra visibile correttamente per la scelta del tema
    float comboWidth = 120.0f;
    float comboHeight = ImGui::GetFrameHeight(); // Altezza del widget
    float paddingX = 135.0f;
    float paddingY = 10.0f;

    ImVec2 windowSize = ImGui::GetWindowSize();

    // Posizionamento corretto
    ImGui::SetCursorPos(ImVec2(windowSize.x - comboWidth - paddingX, paddingY));

    // Push di larghezza fissa per evitare un layout brutto
    ImGui::PushItemWidth(comboWidth);

	// Cambio del tema nel programma
    if (ImGui::Combo("Tema dell'app", &theme, "Chiaro\0Scuro\0")) {
        themeManager.setThemeFromInt(theme);
    }

    ImGui::PopStyleVar();
    ImGui::PopStyleColor(3);
    ImGui::PopStyleColor(5);

	// Footer fisso con margine dal fondo per i credit di Gestionex
    float altezzaFooterCredit = 30.0f;
    float distanzaMargineFinestra = 2.0f;

	// Imposta la posizione della barra footer sulla parte inferiore della finestra
    ImGui::SetCursorPos(ImVec2(0, windowSize.y - altezzaFooterCredit - distanzaMargineFinestra));

    // Applica i colori in base al tema
    bool footerStyled = false;
    if (theme == 0) { // Tema chiaro
        // Colore sfondo della barra footer
        ImGui::PushStyleColor(ImGuiCol_ChildBg, ImVec4(0.8f, 0.8f, 0.8f, 1.0f)); // Grigio chiaro che si differenzia con il tema chiaro
		// Colore del testo della barra footer
        ImGui::PushStyleColor(ImGuiCol_Text, ImVec4(0.0f, 0.0f, 0.0f, 1.0f)); // Testo nero
        footerStyled = true;
    }
    else if (theme == 1) { // Tema scuro
        // Colore sfondo della barra footer
        ImGui::PushStyleColor(ImGuiCol_ChildBg, ImVec4(0.18f, 0.18f, 0.18f, 1.0f)); // Grigio antracite che si differenzia con il tema scuro
        // Colore del testo della barra footer
        ImGui::PushStyleColor(ImGuiCol_Text, ImVec4(0.85f, 0.85f, 0.85f, 1.0f)); // Testo grigio chiaro diverso dallo sfondo del tema scuro
        footerStyled = true;
    }

	// Inizio della barra footer
    ImGui::BeginChild("FooterBar", ImVec2(windowSize.x, altezzaFooterCredit), false, ImGuiWindowFlags_NoScrollbar | ImGuiWindowFlags_NoScrollWithMouse);

	// Calcola la posizione Y centrata per il testo nella barra footer
    float Ycentrata = (altezzaFooterCredit - ImGui::GetFontSize()) * 0.5f;
    ImGui::SetCursorPosY(Ycentrata);

    // Testo iniziale
    string TestoCreditInizio = "Gestionex e' un software libero (open source). Il codice sorgente e' disponibile su ";
    string TestoCreditMezzo = " | Sviluppato e ideato da Matteo Magrino (";
    string TestoCreditFine = ")";

    // Calcola la larghezza totale per centrare tutto
    float larghezzaTestoCreditInizio = ImGui::CalcTextSize(TestoCreditInizio.c_str()).x;
    float larghezzaTestoCreditGitHub = ImGui::CalcTextSize("GitHub").x;
    float larghezzaTestoCreditMezzo = ImGui::CalcTextSize(TestoCreditMezzo.c_str()).x;
    float larghezzaTestoCreditNome = ImGui::CalcTextSize("MatteoMgr2008").x;
    float larghezzaTestoCreditFine = ImGui::CalcTextSize(TestoCreditFine.c_str()).x;
    float larghezzaTestoCreditTotale = larghezzaTestoCreditInizio + larghezzaTestoCreditGitHub + larghezzaTestoCreditMezzo + larghezzaTestoCreditNome;

    // Posiziona il cursore per centrare tutto
    float startX = (windowSize.x - larghezzaTestoCreditTotale) * 0.5f;
    ImGui::SetCursorPosX(startX);

    // Stile per i link normale
    ImVec4 coloreLinkNormale = theme == 0 
        ? ImVec4(0.0f, 0.4f, 0.8f, 1.0f)
        : ImVec4(0.4f, 0.7f, 1.0f, 1.0f); // Blu
    // Stile per i link quando l'utente passa sopra il cursore
    ImVec4 coloreLinkHover = theme == 0 
        ? ImVec4(0.0f, 0.6f, 1.0f, 1.0f)
        : ImVec4(0.6f, 0.8f, 1.0f, 1.0f); // Blu più chiaro

    // Testo iniziale
    ImGui::Text("%s", TestoCreditInizio.c_str());
    // Link della repository di GitHub (stessa riga)
    ImGui::SameLine(0, 0); // Senza spaziatura

    ImGui::PushStyleColor(ImGuiCol_Button, ImVec4(0, 0, 0, 0)); // Trasparente
    ImGui::PushStyleColor(ImGuiCol_ButtonHovered, ImVec4(0, 0, 0, 0)); // Trasparente
    ImGui::PushStyleColor(ImGuiCol_ButtonActive, ImVec4(0, 0, 0, 0)); // Trasparente
    ImGui::PushStyleColor(ImGuiCol_Text, coloreLinkNormale);
    ImGui::PushStyleVar(ImGuiStyleVar_FramePadding, ImVec2(0, 0)); // Rimuove il padding
    ImGui::PushStyleVar(ImGuiStyleVar_FrameBorderSize, 0.0f); // Nessun bordo

	string linkRepositoryGitHub = "https://github.com/MatteoMgr2008/Progetto-gestionale-Gestionex-INFORMATICA-E-TPS"; // Testo del link della repository di GitHub
    if (ImGui::Button("GitHub")) {
        // Permette l'apertura del link al repository GitHub indicato nel link
        #ifdef _WIN32
            string comando = "start " + linkRepositoryGitHub;
            system(comando.c_str());
        #elif __linux__
            string comando = "xdg-open " + linkRepositoryGitHub;
            system(comando.c_str());
        #elif __APPLE__
            string comando = "open " + linkRepositoryGitHub;
            system(comando.c_str());
        #endif
    }

    // Cambia colore se il mouse è sopra il link di GitHub
    if (ImGui::IsItemHovered()) {
        ImGui::PushStyleColor(ImGuiCol_Text, coloreLinkHover);
        ImGui::SetMouseCursor(ImGuiMouseCursor_Hand);
        ImVec2 min = ImGui::GetItemRectMin();
        ImVec2 max = ImGui::GetItemRectMax();
        ImGui::GetWindowDrawList()->AddLine(
            ImVec2(min.x, max.y),
            ImVec2(max.x, max.y),
            ImColor(0.0f, 0.6f, 1.0f, 1.0f),
            1.0f
        );
        ImGui::PopStyleColor();
    }

    ImGui::PopStyleVar(2);
    ImGui::PopStyleColor(4);

    // Testo di mezzo
    ImGui::SameLine(0, 0);
    ImGui::Text("%s", TestoCreditMezzo.c_str());
    // Link nome utente
    ImGui::SameLine(0, 0);

    ImGui::PushStyleColor(ImGuiCol_Button, ImVec4(0, 0, 0, 0)); // Trasparente
    ImGui::PushStyleColor(ImGuiCol_ButtonHovered, ImVec4(0, 0, 0, 0)); // Trasparente
    ImGui::PushStyleColor(ImGuiCol_ButtonActive, ImVec4(0, 0, 0, 0)); // Trasparente
    ImGui::PushStyleColor(ImGuiCol_Text, coloreLinkNormale);
    ImGui::PushStyleVar(ImGuiStyleVar_FramePadding, ImVec2(0, 0)); // Rimuove il padding
    ImGui::PushStyleVar(ImGuiStyleVar_FrameBorderSize, 0.0f); // Nessun bordo

    string linkProfiloGitHub = "https://github.com/MatteoMgr2008"; // Testo del link del profilo di GitHub
    if (ImGui::Button("MatteoMgr2008")) {
        // Permette l'apertura del link riguardante il profilo GitHub "MatteoMgr2008" (quello dello sviluppatore)
        #ifdef _WIN32
            string comando = "start " + linkProfiloGitHub;
            system(comando.c_str());
        #elif __linux__
            string comando = "xdg-open " + linkProfiloGitHub;
            system(comando.c_str());
        #elif __APPLE__
            string comando = "open " + linkProfiloGitHub;
            system(comando.c_str());
        #endif
    }

    // Cambia colore se il mouse è sopra il link del nome
    if (ImGui::IsItemHovered()) {
        ImGui::PushStyleColor(ImGuiCol_Text, coloreLinkHover);
        ImGui::SetMouseCursor(ImGuiMouseCursor_Hand);
        ImVec2 min = ImGui::GetItemRectMin();
        ImVec2 max = ImGui::GetItemRectMax();
        ImGui::GetWindowDrawList()->AddLine(
            ImVec2(min.x, max.y),
            ImVec2(max.x, max.y),
            ImColor(0.0f, 0.6f, 1.0f, 1.0f),
            1.0f
        );
        ImGui::PopStyleColor();
    }

    ImGui::PopStyleVar(2);
	ImGui::PopStyleColor(4); // Ripristina i colori originali

    // Testo finale
    ImGui::SameLine(0, 0);
    ImGui::Text("%s", TestoCreditFine.c_str());

	// Fine della barra footer
    ImGui::EndChild();
    ImGui::PopStyleColor(2); // Ripristina i colori del footer (sfondo e testo)

	// Fine della schermata home (Homepage)
    ImGui::End();
}