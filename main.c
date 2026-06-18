#include <gtk/gtk.h>

static void apply_css(void) {
    GtkCssProvider *provider = gtk_css_provider_new();
    GdkDisplay *display = gdk_display_get_default();
    
    gtk_css_provider_load_from_path(provider, "styles/gtk.css");
    
    gtk_style_context_add_provider_for_display(
        display,
        GTK_STYLE_PROVIDER(provider),
        GTK_STYLE_PROVIDER_PRIORITY_APPLICATION
    );
    
    g_object_unref(provider);
}

// Debug test code
static void on_button_clicked(GtkWidget *widget, gpointer data) {
    g_print("Test button\n");
}

static void create_ui(GtkWidget *window) {
    GtkWidget *main_box;
    GtkWidget *label;
    GtkWidget *entry;
    GtkWidget *button;

    main_box = gtk_box_new(GTK_ORIENTATION_VERTICAL, 15);
    gtk_widget_set_margin_top(main_box, 20);
    gtk_widget_set_margin_bottom(main_box, 20);
    gtk_widget_set_margin_start(main_box, 20);
    gtk_widget_set_margin_end(main_box, 20);
    gtk_window_set_child(GTK_WINDOW(window), main_box);

    label = gtk_label_new("Test myDiscord ! 🔥");
    gtk_box_append(GTK_BOX(main_box), label);

    entry = gtk_entry_new();
    gtk_entry_set_placeholder_text(GTK_ENTRY(entry), "Test entry...");
    gtk_box_append(GTK_BOX(main_box), entry);

    button = gtk_button_new_with_label("Test button");
    g_signal_connect(button, "clicked", G_CALLBACK(on_button_clicked), NULL);
    gtk_box_append(GTK_BOX(main_box), button);
}
// Debug test code ends here

static void activate(GtkApplication *app, gpointer user_data) {
    GtkWidget *window;

    apply_css();

    window = gtk_application_window_new(app);
    gtk_window_set_title(GTK_WINDOW(window), "myDiscord");
    gtk_window_set_default_size(GTK_WINDOW(window), 800, 800);

    // Debug test UI
    create_ui(window);

    gtk_window_present(GTK_WINDOW(window));
}

int main(int argc, char **argv) {
    GtkApplication *app;
    int status;

    app = gtk_application_new("org.nah.mydiscord", G_APPLICATION_DEFAULT_FLAGS);
    g_signal_connect(app, "activate", G_CALLBACK(activate), NULL);
    status = g_application_run(G_APPLICATION(app), argc, argv);
    g_object_unref(app);

    return status;
}