#ifndef DATA_HORARIO_H
#define DATA_HORARIO_H

typedef struct horario Horario;
typedef struct data Data;

static int ehBissexto(int ano);

static int quantidadeDiasAno(int ano);

static int quantidadeDiasMes(int mes);

Horario* criaHorario();

void horarioExato(Horario* hor, int fuso);

void alteraHorario(Horario* hr, int horas, int minutos, int segundos);

void imprimeHorario(Horario *hor);

Data* criaData();

void dataExata(Data* dat, int fuso);

void alteraData(Data* dta, int dia, int mes, int ano);

void imprimeData(Data* dat);

void imprimeDataHorarioExatos(Data *dat, Horario* hor, int fuso);

void relogioCalendario(Data* dat, Horario* hor, int fuso);

long int diferencaDeDiasEntreDatas(Data* data1, Data* data2);

void diferencaDatas(Data* data1, Data* data2);


#endif
