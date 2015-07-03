/* 
 * File:   main.c
 * Author: Mercedes
 *
 * Created on 25 de mayo de 2015, 18:04
 */
  #include <allegro5/allegro.h>   
#include <allegro5/allegro_font.h>   
int main()   
{   
    al_init();   
            al_init_font_addon();   
            al_install_keyboard();   
            ALLEGRO_DISPLAY* d = al_create_display(800, 600);  
            ALLEGRO_FONT* font = al_create_builtin_font();  
            ALLEGRO_EVENT_QUEUE* q = al_create_event_queue();  
            al_register_event_source(q, al_get_keyboard_event_source());  
            al_register_event_source(q, al_get_display_event_source(d));  
            ALLEGRO_USTR* str = al_ustr_new("Type something...");  
            int pos = (int)al_ustr_size(str);  
            char* mistring;
            
            int quit = 0;  
            while(quit==0)  
            {  
                al_clear_to_color(al_map_rgb_f(0, 0, 0));  
                al_draw_ustr(font, al_map_rgb_f(1, 1, 1), 400, 300, ALLEGRO_ALIGN_CENTRE, str);  
                al_flip_display();  
                
                ALLEGRO_EVENT e;  
                al_wait_for_event(q, &e);  
                switch(e.type)  
                {  
                    case ALLEGRO_EVENT_DISPLAY_CLOSE:  
                        quit = true;  
                        break;  
                    case ALLEGRO_EVENT_KEY_CHAR:  
                        if(e.keyboard.unichar >= 32)  
                        {  
                            pos += al_ustr_append_chr(str, e.keyboard.unichar);  
                        }  
                        else if(e.keyboard.keycode == ALLEGRO_KEY_BACKSPACE)  
                        {  
                            if(al_ustr_prev(str, &pos))  
                                al_ustr_truncate(str, pos);  
                        }
                        
                        if(e.keyboard.unichar == 13){
                            quit=1;
                        }
                        
                        break;  
                }  
            }  
            while(quit==1){
                mistring=al_cstr(str);
                al_clear_to_color(al_map_rgb_f(0, 0, 0));  
                al_draw_text(font, al_map_rgb_f(1,1,1),100,100,ALLEGRO_ALIGN_LEFT,mistring);
                al_draw_ustr(font, al_map_rgb_f(1, 1, 1), 400, 300, ALLEGRO_ALIGN_CENTRE, str);      
                al_flip_display();
            }
}