//incluindo de biblioteca
#include <stdio.h>
#include <time.h>
// declarar Variaveis

int numero , cep , telefone , anoNasc , mesNasc , diaNasc;
char nome[49];
char cpf[12];
char email[49];
char estado[49];
char cidade[49];
char bairro[49];
char rua[49];
char login[49] = "admin";
char senha[15] = "123456";
char login1[50]; 
char senha1[15];
int comorb;


void main(){

 //Tela de login

    printf("........................................Tela de Login.......................................");
    do{
        printf("\n\nUsuario: ");
        scanf("%s", login1); 
        if(strcmp(login, login1) == 0){        

            printf("SENHA: ");
            scanf("%s", senha1);
            fflush(stdin);

            if(strcmp(senha, senha1)== 0){
                printf("logado...\n");

                cadastro();

            }else{
                printf("senha incorreta\n");
            }
        
        }else{
            printf("Login não Existe\n");
        }
    }while (login != login1 && senha != senha1);
  
    
 return (0);
 
}

//Criando fun~so cadastro

void cadastro(){
 // buscando Data atual para o calculo de idade
 time_t mytime;
     mytime = time(NULL);
     struct tm tm = *localtime(&mytime);
     int diaAtual = tm.tm_mday;
     int mesAtual = tm.tm_mon + 1;
     int anoAtual = tm.tm_year + 1900;
    //declarando Variaveis necessarias para a função
    int op = 0;
    int anoIdad, mesIdad, diaIdad = 0;
    static int contador = 0;

    do{
        //Informações para cadastro de pacientes
        printf("....................................Cadastro de Pacientes....................................");
    
        printf("\n\nNome completo do paciente: ");
        fgets(nome, 50, stdin);

        printf("\nemail do paciente: ");
        fgets(email, 49, stdin);
        
        printf("\nCpf do paciente: ");
        scanf("%s", &cpf);

        printf("\ntelefone do paciente: ");
        scanf("%d", &telefone);
        fflush(stdin);

        printf("\nRua do paciente: ");
        fgets(rua, 49, stdin);

        printf("\nN: ");
        scanf("%d", &numero);
        fflush(stdin);

        printf("\nBairro do paciente: ");
        fgets(bairro, 50, stdin);

        printf("\ncidade do paciente: ");
        fgets(cidade, 50, stdin);

        printf("\nestado do paciente: ");
        fgets(estado, 50, stdin);

        printf("\nCEP: ");
        scanf("%d", &cep);

        printf("\nData de nacimento: Dia ");
        scanf("%d", &diaNasc);

        printf("Mes ");
        scanf("%d", &mesNasc);

        printf("Ano ");
        scanf("%d", &anoNasc);
        fflush(stdin);
        
        // descobrindo a idade exata do pasciente
        anoIdad = anoAtual - anoNasc;
        mesIdad = mesNasc - mesAtual;
        diaIdad = diaNasc - diaAtual;

        if (mesAtual <= mesNasc){
           if (diaAtual <= diaNasc){
                anoIdad--;  
            }
                
        }
        //criar a variavel ponteiro para arquivo
        FILE *pont_arq1 ,*pont_arq2; 
        //criar arquivo com o tipo de abertura "a"
        pont_arq1 = fopen("arqPacRisco.txt", "a");
        pont_arq2 = fopen("arqPacForadeRisco.txt", "a");

        // O pasciente pertence ao grupo de risco?

        printf("\npaciente possui o comorbidade:\n Digite (1) se Sim ou (2) se Não.: ");
        scanf("%d", &comorb);
        
        if(comorb == 1 || anoIdad > 64){
    
            //armazenar os dados do paciente em risco no arquivo
            fprintf(pont_arq2,"\n................................................................................");
            fprintf(pont_arq2,"\n\nPaciente.:%s",nome);
            fprintf(pont_arq1,"\nCPF.:%s", cpf);
            fprintf(pont_arq1,"\nTelefone.:%ld" ,telefone);
            fprintf(pont_arq1,"\ne_mail.:%s",email);
            fprintf(pont_arq1,"\nEndereço.:%s%d %s%s%s%d",rua, numero, bairro, cidade, estado, cep);
            fprintf(pont_arq1,"\nIdade.: %d",anoIdad);
            fprintf(pont_arq1,"\nData de entrada:.%d/%d/%d",diaAtual, mesAtual, anoAtual);
            
            //fecha arquivo
            fclose(pont_arq1);
            printf("\nDados do paciente salvos");
            printf("\nPaciente em grupo de risco");
        }
        else{
            //armazena os dados do paciente Fora de risco no arquivo
            fprintf(pont_arq2,"\n................................................................................");
            fprintf(pont_arq2,"\n\nPaciente.:%s",nome);
            fprintf(pont_arq2,"\nCPF.:%s", cpf);
            fprintf(pont_arq2,"\nTelefone.:%ld",telefone);
            fprintf(pont_arq2,"\ne_mail.:%s",email);
            fprintf(pont_arq2,"\nEndereço.:%s%d %s%s%s%d",rua, numero, bairro, cidade, estado, cep);
            fprintf(pont_arq2,"\nIdade.: %d",anoIdad);
            fprintf(pont_arq2,"\nData de entrada:.%d/%d/%d",diaAtual, mesAtual, anoAtual);
            //fecha arquivo
            fclose(pont_arq2);
            printf("\nDados do paciente salvos.");
            printf("\nPaciente fora do grupo de risco.");
        }

        printf("\n\nDigite '1' para Finalizar os cadastros ou qualquer outra tecla para o cadastro de outro paciente.");
        scanf("%d", &op);
        fflush(stdin);
    


    }while(op != 1);


}


