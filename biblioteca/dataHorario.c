#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include "dataHorario.h"

struct horario{
    int hora;
    int minuto;
    int segundo;
};

struct data{
    int dia;
    int mes;
    int ano;
};

static int ehBissexto(int ano) {
    if((ano % 400 == 0) || ((ano % 4 == 0) && (ano % 100 != 0))) {
        return 1;
    }
        
    return 0;
    
}

static int quantidadeDiasAno(int ano) {
    if(ehBissexto(ano)) {
        return 366;
    }
    
    return 365;
}

static int quantidadeDiasMes(int mes) {
    int diasPorMes[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if(mes < 1 || mes > 12) {
        return -1;
    }
    return diasPorMes[mes - 1];
}

Horario* criaHorario() {
    Horario* h = NULL;
    long int segundos = 0;
    int minutos = 0;
    int horas = 0;
    
    h = (Horario*) malloc(sizeof(Horario));
    
    if(h == NULL) {
        printf("\nERRO: memoria insuficiente.\n");
        return NULL;
    }

    segundos = time(NULL);
    horas = (segundos % 86400) / 3600;
    minutos = ((segundos % 86400) % 3600) / 60;
    segundos = ((segundos % 86400) % 3600) % 60;
    
    if(horas < 0) {
        horas = 24 + horas;
    }

    h -> hora = 0;
    h -> minuto = 0;
    h -> segundo = 0;

    return h;
}

void horarioExato(Horario* hor, int fuso) {
    long int segundos = 0;
    int minutos = 0;
    int horas = 0;
    
    if(hor == NULL) {
        printf("\nERRO: variavel de horario nao inicializada.\n");
        return;
    }
    
    if(fuso < -11 || fuso > 12) {
        printf("\nERRO: valor incorreto de fuso.\n");
        return;
    }
    
    segundos = time(NULL) + (fuso * 3600);
    horas = (segundos % 86400) / 3600;
    minutos = ((segundos % 86400) % 3600) / 60;
    segundos = ((segundos % 86400) % 3600) % 60;
    
    if(horas < 0) {
        horas = 24 + horas;
    }
    
    hor -> hora = horas;
    hor -> minuto = minutos;
    hor -> segundo = segundos;
    
}

void alteraHorario(Horario* hr, int horas, int minutos, int segundos) {
    if(hr == NULL) {
        printf("\nERRO: variavel de horario nao inicializada.\n");
        return;
    }

    if(horas < 0 || horas > 23) {
        printf("\nERRO: valor incorreto de hora.\n");
        return;
    }
    
    if(minutos < 0 || minutos > 59) {
        printf("\nERRO: valor incorreto de minutos.\n");
        return;
    }
    
    if(segundos < 0 || segundos > 59) {
        printf("\nERRO: valor incorreto de segundos.\n");
        return;
    }

    hr -> hora = horas;
    hr -> minuto = minutos;
    hr -> segundo = segundos;

}

void imprimeHorario(Horario* hor) {
    if(hor == NULL) {
        printf("\nERRO: variavel de horario nao inicializada.\n");
        return;
    }
    printf("%i:%i:%i\n", hor -> hora, hor -> minuto, hor -> segundo);
}

Data* criaData() {
    Data* dta = NULL;
    int ano = 1970;
    int dias = 0;
    int mes = 1;
    int horas = 0;
    long int segundos = time(NULL);
    
    dta = (Data*) malloc(sizeof(Data));
    
    if(dta == NULL) {
        printf("\nERRO: memoria insuficiente.\n");
        return NULL;
    }

    dias = (segundos / 86400) + 1;
    horas = (segundos % 86400) / 3600;
    
    while(dias > quantidadeDiasAno(ano)) {
        dias -= quantidadeDiasAno(ano);
        ano++;
    }
    
    while((dias > quantidadeDiasMes(mes))) {
        if((ehBissexto(ano)) && (mes == 2)) {
            dias -= 29;
        }
        
        else {
            dias -= quantidadeDiasMes(mes);
        }
        
        mes++;
    }
    
    if(horas < 0) {
        horas = 24 + horas;
        if(dias == 1) {
            if(mes == 1) {
                ano -= 1;
                mes = 12;
                dias = quantidadeDiasMes(mes);
            }
            
            else if(ehBissexto(ano) && mes == 2) {
                dias = 29;
            }
            
            else {
                dias = quantidadeDiasMes(mes);
            }
        }
    }

    dta -> dia = dias;
    dta -> mes = mes;
    dta -> ano = ano;
    
    return dta;
}

void dataExata(Data* dat, int fuso) {
    int ano = 1970;
    int dias = 0;
    int mes = 1;
    int horas = 0;
    long int segundos = 0;
    
    if(dat == NULL) {
        printf("\nERRO: variavel de data nao inicializada.\n");
        return;
    }
    
    if(fuso < -11 || fuso > 12) {
        printf("\nERRO: valor invalido de fuso horario.\n");
        return;
    }

    segundos = time(NULL) + (fuso * 3600);

    dias = (segundos / 86400) + 1;
    horas = (segundos % 86400) / 3600;
    
    while(dias > quantidadeDiasAno(ano)) {
        dias -= quantidadeDiasAno(ano);
        ano++;
    }
    
    while((dias > quantidadeDiasMes(mes))) {
        if((ehBissexto(ano)) && (mes == 2)) {
            dias -= 29;
        }
        
        else {
            dias -= quantidadeDiasMes(mes);
        }
        
        mes++;
    }
    
    if(horas < 0) {
        horas = 24 + horas;
        if(dias == 1) {
            if(mes == 1) {
                ano -= 1;
                mes = 12;
                dias = quantidadeDiasMes(mes);
            }
            
            else if(ehBissexto(ano) && mes == 2) {
                dias = 29;
            }
            
            else {
                dias = quantidadeDiasMes(mes);
            }
        }
    }
    
    dat -> dia = dias;
    dat -> mes = mes;
    dat -> ano = ano;
}

void alteraData(Data* dta, int dia, int mes, int ano) {
    if(dta == NULL) {
        printf("\nERRO: variavel de data nao inicializada.\n");
        return;
    }
    if(ano < 1) {
        printf("\nERRO: valor invalido de ano.\n");
        return;
    }
    
    if(mes < 1 || mes > 12) {
        printf("\nERRO: valor invalido de mes.\n");
        return;
    }
    
    if(mes == 2) {
        if(ehBissexto(ano)) {
            if(dia < 1 || dia > 29) {
                printf("\nERRO: valor invalido de dia.\n");
                return;
            }
        }
        
        else{
            if(dia < 1 || dia > 28) {
                printf("\nERRO: valor invalido de dia.\n");
                return;
            }
        }
    }
    
    else if(dia < 1 || dia > quantidadeDiasMes(mes)) {
        printf("\nERRO: valor invalido de dia.\n");
        return;
    }

    dta -> dia = dia;
    dta -> mes = mes;
    dta -> ano = ano;

}

void imprimeData(Data* dat) {
    if(dat == NULL) {
        printf("\nERRO: variavel de data nao inicializada.\n");
        return;
    }
    
    printf("%i/%i/%i\n", dat -> dia, dat -> mes, dat -> ano);
}

void imprimeDataHorarioExatos(Data* dat, Horario* hor, int fuso) {
    if(dat == NULL || hor == NULL) {
        return;
    }
    
    dataExata(dat, fuso);
    horarioExato(hor, fuso);
    
    imprimeHorario(hor);
    imprimeData(dat);
}

void relogioCalendario(Data* dat, Horario* hor, int fuso) {
    int i = 0;
    
    for(i = 0; i < 65; i++) {
        imprimeDataHorarioExatos(dat, hor, fuso);
        sleep(1);
        printf("\e[1;1H\e[2J");
    }
}

long int diferencaDeDiasEntreDatas(Data* data1, Data* data2) {
    int i = 0;
    int j = 0;
    int dias = 0;

    if(data1 == NULL || data2 == NULL) {
        printf("\nERRO: variavel de Data nao inicializada.\n");
        return -1;
    }

    j = data1 -> ano;

    for(i = 1; i <= data1 -> mes; i++) {
        if(ehBissexto(j) && (i == 2)) {
            dias += 29;
        }
        else{
            dias += quantidadeDiasMes(i);
        }
    }

    j = data2 -> ano;

    for(i = 1; i <= data2 -> mes; i++) {
        if(ehBissexto(j) && (i == 2)) {
            dias -= 29;
        }
        else{
            dias -= quantidadeDiasMes(i);
        }
    }

    for(i = data2 -> ano; i < data1 -> ano; i++) {
        dias += quantidadeDiasAno(i);
    }

    dias += data1 -> dia - data2 -> dia;

    if(dias < 0) {
        return -2;
    }

    return dias;

}


/*calcula a diferenca de tempo entre duas datas em anos, meses e dias*/
void diferencaDatas(Data* data1, Data* data2) {
    int ano = 0;
    int mes = 0;
    int i = 0;
    int j = 0;
    int mesInicial = 0;
    long int dias = diferencaDeDiasEntreDatas(data1, data2);

    /*testa se as datas sao iguais*/
    if(dias == 0) {
        printf("\nAs datas sao iguais.\n");
        return;
    }

    /*testa se a segunda data acontece depois que a primeira*/
    if(dias == -2) {
        printf("\nA segunda data acontece depois que a primeira.\n");
        return;
    }

    /*testa se uma datas aponta para null*/
    if(dias == -1) {
        printf("\nERRO: variavel de data nao inicializada.\n");
        return;
    }


    printf("\nA diferenca entre as duas datas eh de %i dia(s).\n", dias);

    i = data2 -> mes;
    j = data2 -> ano;
    mesInicial = data2 -> mes;
    mes = 0;

    while(dias >= quantidadeDiasMes(i)) {
        if(ehBissexto(j) && (i == 2)) {
            dias -= 29;
        }

        else{
            dias -= quantidadeDiasMes(i);
        }
        
        mes++;
        i = (i % 12) + 1;

        if(i == mesInicial) {
            ano++;
            mes = 0;
        }

        if(i == 1) {
            j++;
        }
    }

    printf("\nA diferenca entre as datas eh de %i ano(s), %i mes(es) e %i dia(s).\n", ano, mes, dias);

}