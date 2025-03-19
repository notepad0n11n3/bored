#include <gtk/gtk.h>

static void mostrar_ventana(GtkWidget *window) {
    gtk_widget_show_all(window);
}

int main(int argc, char *argv[]) {
    GtkWidget *window;

    gtk_init(&argc, &argv);

    // Crear una nueva ventana
    window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(window), "Ventana Flotante");
    gtk_window_set_default_size(GTK_WINDOW(window), 200, 100);

    // Agregar un mensaje en la ventana
    GtkWidget *label = gtk_label_new("¡Mochi mango Ready... ewe!");
    gtk_container_add(GTK_CONTAINER(window), label);

    // Conectar la señal de cierre de la ventana
    g_signal_connect(window, "destroy", G_CALLBACK(gtk_main_quit), NULL);

    mostrar_ventana(window);

    gtk_main();  // Iniciar el bucle principal de GTK

    return 0;
}
