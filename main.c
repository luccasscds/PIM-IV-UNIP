#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

int login() {
    char user[100], password[20];

    while(1){
        printf("\n==============================\n");
        printf("\n      Faça seu login \n");
        printf("\n==============================\n");
        printf("Digite seu usuário: ");
        (void)!scanf("%s",user);

        printf("Digite sua senha: ");
        (void)!scanf("%s",password);

        if(strcmp(user,"admin") == 0 && strcmp(password, "admin") == 0){
            (void)!system("clear");
            printf("Login aprovado...\n");
            break;
        }

        printf("Seu usuário ou senha está incorreto. Por favor tente novamente.");
        getchar();
        (void)!system("clear");
    }

    return 0;
}

int storageFile(char idStr[100], char str[100], char nameFile[100]) {
    FILE *point;
    char path[100] = "pacientes/"; strcat(path,nameFile); strcat(path,".txt");
    point = fopen(path,"a");
    if(point == NULL){
        printf("\nError: Na abertura do arquivo\n");
        exit(1);
    }else {
        fprintf(point,idStr,str);
    }

    fclose(point);
    return 0;
}

int verifyLength(char str[100]){
    int length = 0; // Removendo o enter da string
    while(str[length] != '\0'){
        if(str[length] == '\n') {str[length] = '\0';}
        length ++;
    }
    length = 0; // Saber o length da string
    while(str[length] != '\0'){length ++;}

    return length;
}

int verifyNumber(char str[100]){
    int length = 0;
    int isNumber = 1;// true
    while(str[length]){
        if(isdigit(str[length]) == 0) {
            isNumber = 0; // false
        }
        length ++;
    }

    return isNumber;
}

int verifyStr(char str[100]){ // true:1 ; false:0
    int length = 0;
    int isString = 1;
    while(str[length]){
        if(isalpha(str[length]) == 0 && str[length] != ' ') {
            isString = 0;
        }
        length ++;
    }

    return isString;
}

int currentDate(char s[1]){
    time_t currentTime;
    currentTime = time(NULL);
    struct tm tm = *localtime(&currentTime);

    int day = tm.tm_mday;
    int month = tm.tm_mon + 1;
    int year = 1900 + tm.tm_year;

    if(strcmp(s,"d") == 0){
        return day;
    }
    if(strcmp(s,"m") == 0){
        return month;
    }
    if(strcmp(s,"y") == 0){
        return year;
    }
    return 0;
}

int registePatient(){
    char name[100], cpf[100], telephone[100], street[100], number[10], neighborhood[100], city[100], state[100], cep[100], birthDate[100], email[100], diagnosisDate[100], comorbidity[100], res[1];
    int age = 0;

    while(1){
        printf("\n============================================\n");
        printf("\n  Bem-vindo ao sistema de cadastramento:");
        printf("\n  Pacientes diagnosticados com COVID-19\n");
        printf("\n============================================\n");
        printf("1 - Cadastrar paciente.\n0 - Sair.\n> ");
        (void)!scanf("%s",res);

        if(strcmp(res,"0") == 0){
            (void)!system("clear");
            printf("Você saiu do cadastro.\n");
            break;
        }
        if(strcmp(res,"1") == 0){
            (void)!system("clear");
            printf("\n============================================\n");
            printf("    Cadastrar paciente");
            printf("\n============================================\n");

            while(1) {
                printf("Nome do paciente? \n");
                void * verifyInput = fgets(name,100,stdin);
                if(verifyInput != NULL){
                    int length = verifyLength(name);
                    int isString = verifyStr(name);

                    if(length > 2 && isString == 1){
                        break;
                    }
                }
                (void)!system("clear");
            }
            storageFile("Nome: %s\n",name, name);

            while(1){
                printf("\nCPF? [01730411178] \n");
                void * verifyInput = fgets(cpf,100,stdin);
                if(verifyInput != NULL) {
                    int length = verifyLength(cpf);
                    int isNumber = verifyNumber(cpf);

                    if(length == 11 && isNumber != 0){
                        break;
                    }
                }
                (void)!system("clear");
            }
            storageFile("Cpf: %s\n",cpf, name);

            while(1){
                printf("\nTelefone com DDD? [somente os números] \n");
                void * verifyInput = fgets(telephone,100,stdin);

                if(verifyInput != NULL) {
                    int length = verifyLength(telephone);
                    int isNumber = verifyNumber(telephone);

                    if(length == 11 && isNumber != 0){
                        break;
                    }
                }
                (void)!system("clear");
            }
            storageFile("Telefone: %s\n",telephone,name);

            while(1){
                printf("\nSua rua? \n");
                void * verifyInput = fgets(street,100,stdin);
                if(verifyInput != NULL) {
                    int length = verifyLength(street);
                    int isString = verifyStr(street);

                    if(length > 0 && isString == 1){
                        break;
                    }
                }
                (void)!system("clear");
            }
            storageFile("Rua: %s\n",street,name);

            while(1){
                printf("\nNúmero da casa? \n");
                void * verifyInput = fgets(number,100,stdin);
                if(verifyInput != NULL) {
                    int length = verifyLength(number);
                    int isNumber = verifyNumber(number);

                    if(length >= 1 && isNumber != 0){
                        break;
                    }
                }
                (void)!system("clear");
            }
            storageFile("Numero: %s\n",number,name);

            while(1){
                printf("\nBairro? \n");
                void * verifyInput = fgets(neighborhood,100,stdin);
                if(verifyInput != NULL) {
                    int length = verifyLength(neighborhood);
                    int isString = verifyStr(neighborhood);

                    if(length > 3 && isString == 1){
                        break;
                    }
                }
                (void)!system("clear");
            }
            storageFile("Bairro: %s\n",neighborhood,name);

            while(1){
                printf("\nCidade? [teresina] \n");
                void * verifyInput = fgets(city,100,stdin);
                if(verifyInput != NULL) {
                    int length = verifyLength(city);
                    int isString = verifyStr(city);

                    if(length > 4 && isString == 1){
                        break;
                    }
                }
                (void)!system("clear");
            }
            storageFile("Cidade: %s\n",city,name);

            while(1){
                printf("\nEstado? [PI] \n");
                void * verifyInput = fgets(state,100,stdin);
                if(verifyInput != NULL) {
                    int length = verifyLength(state);
                    int isString = verifyStr(state);

                    if(length == 2 && isString == 1){
                        break;
                    }
                }
                (void)!system("clear");
            }
            storageFile("Estado: %s\n",state,name);

            while(1){
                printf("\nCep? [somente os números] \n");
                void * verifyInput = fgets(cep,100,stdin);
                if(verifyInput != NULL) {
                    int length = verifyLength(cep);
                    int isNumber = verifyNumber(cep);

                    if(length == 8 && isNumber != 0){
                        break;
                    }
                }
                (void)!system("clear");
            }
            storageFile("Cep: %s\n",cep,name);

            while(1){
                printf("\nQual é a data de nascimento? [dd/mm/aaaa] \n");
                void * verifyInput = fgets(birthDate,100,stdin);
                if(verifyInput != NULL) {
                    int length = verifyLength(birthDate);

                    if(length == 10){ // dividir a string;
                        int i = 0, differenceDay = 0, differenceMonth = 0, differenceYear = 0;
                        char *pointChar;
                        pointChar = strtok(birthDate,"/");
                        while(pointChar){
                            if(i == 0){
                                differenceDay = atoi(pointChar) == currentDate("d");
                                strcpy(birthDate,pointChar);
                            }
                            if(i == 1){
                                differenceMonth = atoi(pointChar) == currentDate("m");
                                strcat(birthDate,pointChar);
                            }
                            if(i == 2){
                                differenceYear = currentDate("y") - atoi(pointChar);
                                strcat(birthDate,pointChar);
                            }
                            pointChar = strtok(NULL,"/");
                            i ++;
                        }
                        if(differenceDay == 1 && differenceMonth == 1){
                            age = differenceYear;
                        } else {
                            age = differenceYear - 1;
                        }
                        if(age > 65){
                            FILE *point;
                            char path[100] = "pacientes/grupo de risco.txt";
                            point = fopen(path, "a");

                            if(point == NULL) {
                                printf("Erro na abertura do arquivo!\n");
                                exit(1);
                            }else {
                                fputs("\nDados pessoais do paciente em grupo de risco", point);
                                fputs("\nData da criacao: ", point);
                                fprintf(point,"\n\nCEP: %s",cep);
                                fprintf(point,"\nIdade: %d",age);

                                fclose(point);
                            }
                        }
                        break;
                    }
                }
                (void)!system("clear");
            }
            storageFile("Data de nascimento: %s\n",birthDate,name);

            while(1){
                printf("\nEmail? \n");
                void * verifyInput = fgets(email,100,stdin);
                if(verifyInput != NULL) {
                    int length = verifyLength(email);

                    // verificar se email tem o @
                    char *findChar = strchr(email,'@');

                    if(length > 9 && findChar != NULL){
                        break;
                    }
                }
                (void)!system("clear");
            }
            storageFile("Email: %s\n",email,name);

            while(1){
                printf("\nData do diagnóstico? [somente os números] \n");
                void * verifyInput = fgets(diagnosisDate,100,stdin);
                if(verifyInput != NULL) {
                    int length = verifyLength(diagnosisDate);
                    int isNumber = verifyNumber(diagnosisDate);

                    if(length == 8 && isNumber != 0){
                        break;
                    }
                }
                (void)!system("clear");
            }
            storageFile("Data do diagnóstico: %s\n",diagnosisDate,name);

            while(1){
                char isComorbidity[100];
                printf("\nPaciente possui comorbidade?[S,N] \n");
                void * verifyInput = fgets(isComorbidity,100,stdin);
                if(verifyInput != NULL) {
                    int lengthIsComorbidity = verifyLength(isComorbidity);

                    if(strcmp(isComorbidity,"s") == 0 && lengthIsComorbidity == 1){
                        while(1){
                            printf("\nQual sua comorbidade?[diabetes, obesidade, hipertensão, tuberculose, ...] \n");
                            void * verifyInput = fgets(comorbidity,100,stdin);
                            if(verifyInput != NULL) {
                                int length = verifyLength(comorbidity);
                                int isString = verifyStr(comorbidity);

                                if(length > 5 && isString == 1){
                                    break;
                                }
                            }
                            (void)!system("clear");
                        }
                        if(strlen(comorbidity) > 5 ) {
                            break;
                        }
                    }else if(strcmp(isComorbidity,"n") == 0 && lengthIsComorbidity == 1){
                        strcpy(comorbidity, "nao possui");
                        break;
                    }
                }
                (void)!system("clear");
            }
            storageFile("Comorbidade: %s\n",comorbidity,name);

            (void)!system("clear");
            printf("\nPaciente cadastrado com sucesso.\n");
            break;
        }
        printf("\nOpção invalida!");
        getchar();
        (void)!system("clear");
    }

    return 0;
}

int main() {

    while(1){
        char resp[2];
        printf("\n===========================================================\n");
        printf("    Você entrou no sistema de cadastrado de paciente");
        printf("\n===========================================================\n");
        printf("1 - Fazer o login\n0 - Sair\n>");
        (void)!scanf("%s",resp);

        if(strcmp(resp,"1") == 0){
            (void)!system("clear");
            login();
            break;
        }
        if(strcmp(resp,"2") == 0){
            return 1;
        }
        printf("\nOpção invalida!");
        getchar();
        (void)!system("clear");
    }

    registePatient();

    printf("\nJUNTOS SOMOS MAIS FORTES!\n");
    return 0;
}
