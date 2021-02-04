#include <iostream>
#include <gtk-3.0/gtk/gtk.h>
#include <gdk/gdk.h>


using namespace std;

int main( int   argc,char *argv[] )
{

    GtkWidget *window;

    GtkWidget *button;
    GtkWidget *textinput;
    GtkWidget *textarea;

    GtkWidget *verticalBoxWrapper;
    GtkWidget *horizontalBoxForTextInput;
    GtkWidget *horizontalBoxForTextarea;
    GtkWidget *horizontalBoxForButton;

    GtkTextBuffer *buff;

    gtk_init (&argc, &argv);

    window = gtk_window_new (GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(window), "Test v 0.20.001");         // название в окне
    gtk_window_set_position(GTK_WINDOW(window), GTK_WIN_POS_CENTER);  // по центру экрана
    gtk_window_set_default_size(GTK_WINDOW(window), 400, 400);   // размеры окна при запуске
    gtk_container_set_border_width(GTK_CONTAINER (window), 20);   // отступ от края окна до контейнера

    textinput = gtk_entry_new();    // однострочное текстовое поле
    textarea = gtk_text_view_new(); // многострочное тестовое поле

    verticalBoxWrapper = gtk_box_new(GTK_ORIENTATION_VERTICAL, 10);             // делаю обертку для содержимого, внутрь которой буду помещать дрочерние контейнеры
    horizontalBoxForTextInput = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 5);     // для однострочного ввода
    horizontalBoxForTextarea  = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 5);     // для многострочного ввода
    gtk_text_view_set_editable(GTK_TEXT_VIEW(horizontalBoxForTextarea), true);            // возможность редактировать многострочный ввод

//    gtk_text_view_set_border_window_size(GTK_TEXT_VIEW(horizontalBoxForTextarea), GTK_TEXT_WINDOW_LEFT,200);
//    gtk_text_view_set_border_window_size(GTK_TEXT_VIEW(horizontalBoxForTextarea), GTK_TEXT_WINDOW_RIGHT,200);
//    gtk_text_view_set_border_window_size(GTK_TEXT_VIEW(horizontalBoxForTextarea), GTK_TEXT_WINDOW_TOP,200);
//    gtk_text_view_set_border_window_size(GTK_TEXT_VIEW(horizontalBoxForTextarea), GTK_TEXT_WINDOW_BOTTOM,200);

    buff = gtk_text_view_get_buffer (GTK_TEXT_VIEW (textarea));                                  // буфер текстового поля
    gtk_text_buffer_set_text (buff, "{\"id\":\"\1234\"}", -1);

    button = gtk_button_new_with_label ("Нажать");

    horizontalBoxForButton  = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 5); // для кнопки

    gtk_box_pack_start(GTK_BOX(horizontalBoxForTextInput), textinput, TRUE, FALSE, 5);          // в обертку однострочного тесктового ввода ждобавляем этот самый ввод
    gtk_box_pack_start(GTK_BOX(verticalBoxWrapper), horizontalBoxForTextInput, TRUE, FALSE, 5); // в обертку verticalBoxWrapper добавляем обертку для однострочного текстового поля horizontalBoxForTextInput

    // то же самое с многострочным полем, упаковать его в горизонтальный блок, который, в свою очередь, упаковать в общую обертку
    gtk_box_pack_start(GTK_BOX(horizontalBoxForTextarea), textarea, TRUE, FALSE, 5);
    gtk_box_pack_start(GTK_BOX(verticalBoxWrapper), horizontalBoxForTextarea, TRUE, FALSE, 5);

    // то же самое с кнопкой
    gtk_box_pack_start(GTK_BOX(horizontalBoxForButton), button, TRUE, FALSE, 5);
    gtk_box_pack_start(GTK_BOX(verticalBoxWrapper), horizontalBoxForButton, TRUE, FALSE, 5);

    g_signal_connect(window, "destroy",G_CALLBACK(gtk_main_quit), NULL); // закрытие приложения по нажатию на крестик

    gtk_container_add (GTK_CONTAINER (window), verticalBoxWrapper);

    gtk_widget_show_all(window);

    gtk_main ();

    return 0;

}