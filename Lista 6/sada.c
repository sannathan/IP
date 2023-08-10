#include <gtk/gtk.h>

// Função para lidar com o clique no botão
void on_button_clicked(GtkWidget *widget, gpointer data) {
    g_print("Botão clicado!\n");
}

int main(int argc, char *argv[]) {
    GtkWidget *window;
    GtkWidget *button;
    
    gtk_init(&argc, &argv);
    
    // Cria uma janela
    window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(window), "Exemplo de Interface");
    gtk_container_set_border_width(GTK_CONTAINER(window), 10);
    g_signal_connect(window, "destroy", G_CALLBACK(gtk_main_quit), NULL);

    // Cria um botão
    button = gtk_button_new_with_label("Clique Aqui!");
    g_signal_connect(button, "clicked", G_CALLBACK(on_button_clicked), NULL);
    gtk_container_add(GTK_CONTAINER(window), button);

    gtk_widget_show_all(window);
    gtk_main();

    return 0;
}
