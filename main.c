#include <stdio.h>
#include <string.h>
int gera(int posicao_letra, int exec, char *array, char palavra[4]){	
	char aux[4]= ""; // Guarda palavra
	strcat(aux, palavra);
	if(exec<4){
		int i;
		for (i=0; i<26; i++){
			strncat(aux,array+i,1);
			printf("%s\n", aux);			
			
			gera(posicao_letra+1,exec+1,array,aux);
			
			strcpy(aux, palavra);
		}
	}else{
		FILE *txt;
		txt= fopen("dicionario.txt", "a");
		fprintf(txt, "%s", aux);
		if(strcmp(aux, "zzzz")!=0){
			fprintf(txt, "\n");
		}
		fclose(txt);
	}
	return 1;
}
main(){
	char alfabeto[26] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
	char teste[4]= "";
	gera(0,0,&alfabeto,teste);

}
