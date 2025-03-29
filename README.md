# 📅 Gerenciador de Data e Horário em C

Este projeto implementa um **gerenciador de data e horário** em **C**, permitindo manipulação e exibição de datas e horários com suporte a fusos horários e cálculo de diferença entre datas.

## 📌 Funcionalidades
- 📆 **Manipulação de datas** (criação, alteração e exibição).
- ⏰ **Manipulação de horários** (criação, alteração e exibição).
- 🌍 **Suporte a fusos horários**.
- 📅 **Cálculo de anos bissextos**.
- 🕰️ **Relógio e calendário em tempo real**.
- 🔄 **Cálculo da diferença entre duas datas**.

## 🛠 Tecnologias Utilizadas
- **C** (linguagem de programação)
- **GNU Compiler Collection - GCC** (usado como compilador da linguagem de programação)
- **Bibliotecas:**
  - `time.h` (para manipulação de tempo)
  - `stdlib.h` e `stdio.h` (para entrada/saída e alocação de memória)
  - `unistd.h` (para funções de atraso e pausa)

## 🚀 Como Executar o Programa
### 1️⃣ Compilar o código (exemplo)
```bash
gcc -o main main.c dataHorario.c dataHorario.h
```

### 2️⃣ Executar o programa (exemplo)
```bash
./main
```

## 📖 Como Usar
- **Cria horário (criando uma estrutura com horário exato em UTC+0):** `criaHorario();`
- **Cria data (criando uma estrutura com data exata em UTC+0):** `criaData();`
- **Altera a estrutura para o horário exato:** `horarioExato(Horario* hor, int fuso);`
- **Altera a estrutura para a data exata:** `dataExata(Data* dat, int fuso);`
- **Alterar horário manualmente:** `alteraHorario(Horario* hr, int horas, int minutos, int segundos);`
- **Alterar data manualmente:** `alteraData(Data* dta, int dia, int mes, int ano);`
- **Calcular diferença entre datas:** `diferencaDatas(Data* data1, Data* data2);`

## 📊 Exemplo de Uso
```c
Horario* horario = criaHorario();
Data* data = criaData();
imprimeDataHorarioExatos(data, horario, -3);
```

## 👨‍💻 Contribuição
1. Faça um **fork** do repositório.
2. Crie um **branch** com sua melhoria:
   ```bash
   git checkout -b minha-nova-feature
   ```
3. Commit suas mudanças:
   ```bash
   git commit -m "Adiciona nova funcionalidade"
   ```
4. Envie para o GitHub:
   ```bash
   git push origin minha-nova-feature
   ```
5. Abra um **Pull Request**.

## 📄 Licença
Este projeto está sob a licença MIT.

---


