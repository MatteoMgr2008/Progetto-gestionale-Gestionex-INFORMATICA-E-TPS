#define GLFW_EXPOSE_NATIVE_WIN32

// Librerie necessarie per il progetto
#include <Windows.h>
#include "imgui.h"
#include "imgui_impl_glfw.h"
#include "imgui_impl_opengl3.h"
#include <GLFW/glfw3.h>
#include <vector>
#include <string>
#include <list>
#include "OrdineEntrata.h"
#include "Magazzino.h"
#include <GLFW/glfw3native.h>

// Schermate
#include "HomeScreen.h"
#include "GestioneStockScreen.h"
#include "GestioneOrdiniScreen.h"
#include "GestioneOrdiniUscitaScreen.h"

// Fonts
#include "font.h"

// Icone
#include "resource.h" // Per IDI_ICON1 (gestito da Gestionex.rc)

using namespace std;

// Funzione principale per le applicazioni Windows (sostituisce il main)
int APIENTRY WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {

    // Inizializza GLFW (necessario prima di usarlo)
    glfwInit();
    // Ottiene la risoluzione del monitor primario
    const GLFWvidmode* mode = glfwGetVideoMode(glfwGetPrimaryMonitor());

    // Crea una finestra GLFW con dimensione dello schermo e titolo
    GLFWwindow* window = glfwCreateWindow(mode->width, mode->height, "Gestionex", NULL, NULL);
    glfwMakeContextCurrent(window); // Imposta il contesto OpenGL su questa finestra
    glfwSwapInterval(1); // Attiva V-Sync (sincronizzazione verticale)

	// Aggiunge icona alla finestra
    HWND hwnd = glfwGetWin32Window(window);
    HICON hIcon = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_ICONA_GESTIONEX));
    if (hIcon) {
        SendMessageA(hwnd, WM_SETICON, ICON_SMALL, (LPARAM)hIcon);
        SendMessageA(hwnd, WM_SETICON, ICON_BIG, (LPARAM)hIcon);
    }

    // Massimizza la finestra
    glfwMaximizeWindow(window);

    // Inizializza il contesto ImGui
    IMGUI_CHECKVERSION();
    ImGui::CreateContext();
    ImGuiIO& io = ImGui::GetIO(); (void)io; // Ottiene l'oggetto IO (può essere usato per input, configurazioni, ecc.)

    // Variabile da mettere sopra, tra le altre globali o prima del ciclo
    bool darkMode = true; // Tema scuro di default

    // Inizializza i backend per GLFW e OpenGL
    ImGui_ImplGlfw_InitForOpenGL(window, true);
    ImGui_ImplOpenGL3_Init("#version 130"); // Specifica la versione di GLSL da usare

    // Variabili per controllare quale schermata mostrare al momento opportuno
    bool gestioneOrdiniEntrata = false;
    bool gestioneStock = false;
    bool gestioneOrdiniUscita = false;

    // Caricamento dei font di tutto il programma
    ImFontConfig font_base_cfg;
    font_base_cfg.FontDataOwnedByAtlas = false;
    ImFont* Font_base = io.Fonts->AddFontFromMemoryTTF(font_poppins, grandezza_font_poppins, 25.0f, &font_base_cfg);
    io.FontDefault = Font_base;
    
    // Lista iniziale di ordini
	list<OrdineEntrata> ordiniEntrataList;
	list<OrdineUscita> ordiniUscitaList; 
	vector<Magazzino> magazziniList;

	// Aggiunge due magazzini di esempio (md e lidl)
	Magazzino magazzino1(2,"md");
	magazziniList.push_back(magazzino1);
    Magazzino magazzino2(3, "lidl");
    magazziniList.push_back(magazzino2);

    // Ciclo principale dell'applicazione (finché la finestra non viene chiusa dall'utente)
    while (!glfwWindowShouldClose(window)) {
        glfwPollEvents(); // Gestisce gli eventi in input (mouse, tastiera, ecc...)

        // Inizio di un nuovo frame per ImGui
        ImGui_ImplOpenGL3_NewFrame();
        ImGui_ImplGlfw_NewFrame();
        ImGui::NewFrame();

        // Mostra una schermata diversa in base allo stato della variabile
        if (gestioneOrdiniEntrata) {
            DrawGestioneOrdiniScreen(gestioneOrdiniEntrata, ordiniEntrataList, magazziniList); // Schermata di gestione ordini
        }
        else if (gestioneStock) {
            DrawGestioneStockScreen(gestioneStock, magazziniList); // Schermata di gestione stock
        }
        else if (gestioneOrdiniUscita) {
            DrawGestioneOrdiniUscitaScreen(gestioneOrdiniUscita, ordiniUscitaList); // Schermata di gestione ordini in uscita
        }
        else {
            DrawHomeScreen(gestioneOrdiniEntrata, gestioneStock, gestioneOrdiniUscita); // Schermata iniziale (home)
        }

        // Rendering ImGui
        ImGui::Render();
        int display_w, display_h;
        glfwGetFramebufferSize(window, &display_w, &display_h); // Ottiene la dimensione della finestra
        glViewport(0, 0, display_w, display_h); // Imposta l'area di disegno OpenGL
        glClearColor(0.1f, 0.1f, 0.1f, 1.0f); // Imposta il colore di sfondo (grigio scuro)
        glClear(GL_COLOR_BUFFER_BIT); // Pulisce lo schermo
        ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData()); // Disegna tutto con ImGui

        glfwSwapBuffers(window); // Mostra il risultato a schermo
    }

    // Pulizia e chiusura delle librerie
    ImGui_ImplOpenGL3_Shutdown();
    ImGui_ImplGlfw_Shutdown();
    ImGui::DestroyContext();
    glfwDestroyWindow(window); // Chiude la finestra
    glfwTerminate(); // Termina GLFW

    return 0; // Uscita normale
}