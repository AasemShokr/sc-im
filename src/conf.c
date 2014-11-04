#include "conf.h"
#include "utils/dictionary.h"
#include <stdlib.h>
#include <stdio.h>


void store_default_config_values() {
    put(user_conf_d, "half_page_scroll", "0");
    put(user_conf_d, "autocalc", "1");
    put(user_conf_d, "numeric", "0");
    put(user_conf_d, "newline_action", "0");
}

char * get_conf_values(char * salida) {

   if (user_conf_d == NULL) return;
   struct nlist * nl;
   struct nlist * n_next;

   nl = user_conf_d->list;
   salida[0]='\0';
   while (nl != NULL) {
       sprintf(salida, "%s%s=%s\n", salida, nl->key, nl->val);
       nl = nl->next;
   }
   return salida;
}


char * get_conf_value(char * key) {

   char * val = get(user_conf_d, key);
    
   if ( val != '\0' )
       return val;
   else
       return get(predefined_conf_d, key);
}